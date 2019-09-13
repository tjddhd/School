sigma = 1;
boxN = 7;

im= imread('objectsForActiveContours.png');
im = double(im(:,:,1))/255; %grayscale image with range [0,1]

%smooth with Gaussian kernel
%for efficiency, we'll take advantage of separability
halfwid = round(3*sigma);
xx = -halfwid:halfwid;
smookernel = exp(- xx.^2  / (2 * sigma^2));
%normalize to sum to one
smookernel = smookernel / sum(smookernel);
%convolve along x and y to do the 2D smoothing
smooim = imfilter(imfilter(im,smookernel,'replicate'),smookernel','replicate');

%compute gradients (x and y derivatives)
gradkernel = [-1 0 1]/2.0;
Gx = imfilter(smooim, gradkernel, 'replicate');
Gy = imfilter(smooim, gradkernel', 'replicate');

%form products of gradients at each pixel
Gxx = Gx .* Gx;
Gxy = Gx .* Gy;
Gyy = Gy .* Gy;
%sum up over NxN image regions
%will convolve using box filter;
box = ones(boxN);
Sxx = imfilter(Gxx,box,'replicate');
Sxy = imfilter(Gxy,box,'replicate');
Syy = imfilter(Gyy,box,'replicate');

%now compute Harris R value score
det = Sxx .* Syy - Sxy .* Sxy;
tra = Sxx + Syy;
k = .05;
R = det - k * tra.^2;

figure; imshow(im,[]); title('input image');
figure; imshow(R,[]); title('R scores on cornerness');

highCurvatureRegions = R>0.3;
figure; imshow(highCurvatureRegions); title('highCurvatureRegions for the active contour algorithm');




