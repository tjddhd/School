%Emerson Lentz
%Thomas Dolan

clear all; clc; close all;
left = rgb2gray(imread('conesLeft.ppm'));
right = rgb2gray(imread('conesRight.ppm'));

[leftnr,leftnc,leftnb] = size(left);
[rightnr,rightnc,rightnb] = size(right);
figure(1); imshow(left,[]); title('left');
figure(2); imshow(right,[]); title('right');

left = imread('conesLeft', 'ppm');
right = imread('conesRight', 'ppm');
left = imresize(left, .25);
right = imresize(right, .25);
leftGray = rgb2gray(left);
rightGray = rgb2gray(right);

L = double(im2col(leftGray, [3 3]));
R = double(im2col(rightGray, [3 3]));

[m, n] = size(L);

for i=1:n
    y = L(:, i);
    yMean = mean(y);
    yStd = std(y);
    for j=1:9
        y(j)=(y(j)-yMean)/yStd;
    end
    y = y/norm(y);
    L(:, i) = y;
    
end

[j, k] = size(R);

for i=1:k
    y = R(:, i);
    yMean = mean(y);
    yStd = std(y);
    for f=1:9
        y(f)=(y(f)-yMean)/yStd;
    end
    y = y/norm(y);
    R(:, i) = y;
end

DSI = 1-L'*R;




new = DSI;
occlusion = 2;
cost = 10;
for x=1:leftnr
    new(x,1) = x * occlusion;
end

for y=1:rightnc
    new(1,y) = y*occlusion;
end

M =[1:leftnr,1:rightnc];
for x=2:leftnr
    for y=2:rightnc
        min1 = new(x-1,y-1) + cost;
        min2 = new(x-1,y) + occlusion;
        min3 = new(x,y-1) + occlusion;
        cmin = min(min1,min(min2,min3));
        new(x,y) = cmin;
        if(min1==cmin) 
            M(x,y)=1;
        end
        if(min2==cmin)
            M(x,y)=2;
        end
        if(min3==cmin)
            M(x,y)=3;
        end
    end
end

bestpath = [1:leftnr,1:rightnc];
p = leftnr;
q = rightnc;
bestpath(p,q) = 1;
while(p~=0 && q~=0)
    if(M(p,q) == 1)
        bestpath(p-1,q-1) = 1;
        p = p-1;
        q = q-1;
    end
    if(M(p,q) == 2)
        bestpath(p-1,q) = 1;
        p = p-1;
    end
    if(M(p,q) == 3)
        bestpath(p,q-1) = 1;
        q = q-1;
    end
    if(q == 1)
        q = rightnc;
        p = p - 1;
        if(p == 1)
            p = 0;
        end
    end
end

figure(3); imshow(bestpath);









