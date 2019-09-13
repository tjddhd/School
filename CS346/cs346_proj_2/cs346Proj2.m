%plane warp demo using homographies
%Zhaozheng Yin, Computer Science, MST
%Spring 2014

clear all; clc; close all;

% read source and dest images
% source = imread('img1.tif');
% dest = imread('img2.tif');

source = imread('cameraman.tif');
dest = imread('cameraman.tif');

[destnr,destnc,destnb] = size(dest);
[srcnr,srcnc,srcnb] = size(source);
figure(1); imshow(source,[]); title('source');
figure(2); imshow(dest,[]); title('destination');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Step 1: manually select correpsonding points
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
fLoad = false;
if ~fLoad    
    %click points in source
    figure(1);
    [xpts,ypts] = ginput;
    hold on; plot(xpts, ypts, 'rs','Markersize',12);
    text(xpts, ypts, num2str((1:length(xpts))'),'Color','r')
    hold off;

    %click points in destination
    figure(2);
    [xprimes,yprimes] = ginput;
    hold on; plot(xprimes, yprimes, 'gs','Markersize',12);    
    text(xprimes,yprimes,num2str((1:length(xpts))'),'Color','g');  
    hold off;

    %save the points
    save('CorrespondingPoints.mat','xpts','ypts','xprimes','yprimes');
else
    %load the point correspondece
    load('CorrespondingPoints.mat','xpts','ypts','xprimes','yprimes');
    
    %show points in source
    figure(1);
    hold on; plot(xpts, ypts, 'rs','Markersize',12);
    text(xpts, ypts, num2str((1:length(xpts))'),'Color','r')
    hold off;
    
    %show points in destination
    figure(2);
    hold on; plot(xprimes, yprimes, 'gs','Markersize',12);
    text(xprimes,yprimes,num2str((1:length(xpts))'),'Color','g');    
    hold off;
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Step 2: compute homography (from source to dest coord system)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Method 1. compute h assuming h_33 = 1

homoA =  [xpts(1) ypts(1) 1 0 0 0 -xpts(1)*xprimes(1) -ypts(1)*xprimes(1);...
         0 0 0 xpts(1) ypts(1) 1 -xpts(1)*yprimes(1) -ypts(1)*yprimes(1);...
         xpts(2) ypts(2) 1 0 0 0 -xpts(2)*xprimes(2) -ypts(2)*xprimes(2);...
         0 0 0 xpts(2) ypts(2) 1 -xpts(2)*yprimes(2) -ypts(2)*yprimes(2);...
         xpts(3) ypts(3) 1 0 0 0 -xpts(3)*xprimes(3) -ypts(3)*xprimes(3);...
         0 0 0 xpts(3) ypts(3) 1 -xpts(3)*yprimes(3) -ypts(3)*yprimes(3);...
         xpts(4) ypts(4) 1 0 0 0 -xpts(4)*xprimes(4) -ypts(4)*xprimes(4);...
         0 0 0 xpts(4) ypts(4) 1 -xpts(4)*yprimes(4) -ypts(4)*yprimes(4)];

homoB = [xprimes(1); yprimes(1); xprimes(2); yprimes(2); xprimes(3);...
         yprimes(3); xprimes(4); yprimes(4)];
    
homo = homoA\homoB;

homography = [homo(1) homo(2) homo(3); homo(4) homo(5) homo(6);...
              homo(7) homo(8) 1];

%Method 2. compute h with constraint ||h|| = 1
A = [ xpts(1) ypts(1) 1 0 0 0 -xpts(1)*xprimes(1) -ypts(1)*xprimes(1) -xpts(1); ...
    0 0 0 xpts(1) ypts(1) 1 -xpts(1)*yprimes(1) -ypts(1)*yprimes(1) -yprimes(1); ...
    xpts(2) ypts(2) 1 0 0 0 -xpts(2)*xprimes(2) -ypts(2)*xprimes(2) -xpts(2); ...
    0 0 0 xpts(2) ypts(2) 1 -xpts(2)*yprimes(2) -ypts(2)*yprimes(2) -yprimes(2); ...
    xpts(3) ypts(3) 1 0 0 0 -xpts(3)*xprimes(3) -ypts(3)*xprimes(3) -xpts(3); ...
    0 0 0 xpts(3) ypts(3) 1 -xpts(3)*yprimes(3) -ypts(3)*yprimes(3) -yprimes(3); ...
    xpts(4) ypts(4) 1 0 0 0 -xpts(4)*xprimes(4) -ypts(4)*xprimes(4) -xpts(4); ...
    0 0 0 xpts(4) ypts(4) 1 -xpts(4)*yprimes(4) -ypts(4)*yprimes(4) -yprimes(4)];
zeroes = [0; 0; 0; 0; 0; 0; 0; 0];

[U, D, V] = svd(A'*A);

homoSVD = [V(1,1) V(2,1) V(3,1); V(4,1) V(5,1) V(6,1); V(7,1) V(8,1) V(9,1)];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Step 3: warp source image onto dest coord system
% try forward and backward warping (nearest neighbor and bilinear
% interpolation)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%Method 1: Forward Warping%%%
[srcnrows, srcncols] = size(source);
[destnrows, destncols] = size(dest);
warpedSrc = zeros(destnrows, destncols);
for x = 1:srcncols
    for y = 1:srcnrows
        p = [x; y; 1];
        pprime=homography*p;
        xprime = round(pprime(1)/pprime(3));
        yprime = round(pprime(2)/pprime(3));
        if (xprime<1 || xprime>destncols || yprime<1 || yprime>destnrows)
            continue;
        end
        warpedSrc(yprime,xprime)=source(y,x);
    end
end
figure(3); imshow(warpedSrc,[]);

%%%Method 2: Backward Warping%%%
warpedDest = zeros(destnrows, destncols);
for xprime = 1:destncols
    for yprime = 1:destnrows
        xdest = xprime;
        ydest = yprime;
        pprime = [xprime; yprime; 1];
        p=homography\pprime;
        x = (p(1)/p(3));
        y = (p(2)/p(3));
        if (x<1 || x>srcncols || y<1 || y>srcnrows)
            continue;
        end
        if(x ~= round(x) || y ~= round(y))
            if(dist(floor(x),x) < dist(ceil(x),x))
                xdest = floor(x);
            else
                xdest = ceil(x);
            end
            if(abs(floor(y)-y) < abs(ceil(y)-y))
                ydest = floor(y);
            else
                ydest = ceil(y);
            end
        end
        x = round(x);
        y = round(y);
        xdest = round(xdest);
        ydest = round(ydest);
        warpedDest(y,x)=dest(ydest,xdest);
    end
end
figure(4); imshow(warpedDest,[]);

%%%Method 3: Interp2 function%%%
[xi, yi] = meshgrid(1:srcnrows, 1:srcncols);
invhomography = inv(homography);
xx = (invhomography(1,1)*xi+invhomography(1,2)*yi+invhomography(1,3))./(invhomography(3,1)*xi+invhomography(3,2)*yi+invhomography(3,3));
yy = (invhomography(2,1)*xi+invhomography(2,2)*yi+invhomography(2,3))./(invhomography(3,1)*xi+invhomography(3,2)*yi+invhomography(3,3));
foo = uint8(interp2(source,xx,yy));
figure(5); imshow(foo);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Step 4: stitch two images together
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%






































