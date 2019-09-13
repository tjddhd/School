clc; %clear the command window
close all; %close all figure windows
clear all; %clear all variables in the workspace

%read the image
im = double(imread('example.png'))/255;
im = im(:,:,1);
[nrows,ncols] = size(im);

%your code to compute the gradient
[dx dy] = gradient(im);
figure; imshow(im);%imshow(sqrt(dx.^2+dy.^2),[]); title('Magnitude of gradient');

%parameters
f = .5; %the minimum fraction of points to change
a = 1; %continuity
b = 1; %sqrt(gradient(dx).^2+gradient(dy).^2);%curvature
c = 1; %[dx dy]; %gradient
%and some other parameters you will use

%initialization, save the points into mat files without manually choosing
%points everytime when you develop/debug your codes
%figure(2); imshow(im);
%figure(3); imshow(b);
if 1
    [x, y] = ginput; %hit enter to finishing mouse click
    x = round(x); y = round(y);
    save('initPts2.mat','x','y');
else
    %    load('initPts2.mat','x','y');
end
N = numel(x);



%visualize the initial points
hold on;
plot([x; x(1)], [y; y(1)], 'r-*');
hold off; drawnow;
disp('Hit your keyboard to continue...');
pause

cntPt = inf; %infinity,change cntPt in loop to amount of points that moved
while cntPt>f*N
    %your codes for iterative active contour
    
    %SNAKE
    %
    
    %computing d
    avg_dist = 0;
    i = 1;
    while i <= N
        %if i == N
        %    x_prime = [[x(i),y(i)], [x(1),y(1)]];
        %else
        %    x_prime = [[x(i),y(i)], [x(i+1),y(i+1)]];
        %end
        
        if i ==N
            new_dist = sqrt(((x(1)-x(i)).^2)+((y(1)-y(i)).^2));
        else
            new_dist = sqrt(((x(i+1)-x(i)).^2)+((y(i+1)-y(i)).^2));
        end
        
        avg_dist = avg_dist + new_dist;
        i = i+1;
    end
    d = avg_dist / N;
    
    %computing energy of moved points
    movedPoints = 0;
    i = 1;
    
    while i <= N
        %initial best point setup
        if i ==1
            %edge point
            
            bestValue = (a*gradient(x(i),y(i)) + (b*(d-((x(i)-x(N)).^2 + (y(i)-y(N)).^2))) + (c*((x(i+1)+x(N)-2*x(i)).^2+((y(i+1)+y(N)-2*y(i)).^2))));
            bestPoint = i;
            %
            %
            if x(i) > 1
                if (a*gradient(x(N),y(i)) + (b*(d-((x(N)-x(N-1)).^2 + (y(i)-y(N)).^2))) + (c*((x(i)+x(N-1)-2*x(N)).^2+((y(i+1)+y(N)-2*y(i)).^2)))) <bestValue
                    movedPoints = movedPoints +1;
                    bestValue = (a*gradient(x(N),y(i)) + (b*(d-((x(N)-x(N-1)).^2 + (y(i)-y(N)).^2))) + (c*((x(i)+x(N-1)-2*x(N)).^2+((y(i+1)+y(N)-2*y(i)).^2))));
                    x(i) = x(i)-1;
                end
            end
            if y(i) > 1
                if (a*gradient(x(i),y(N)) + (b*(d-((x(i)-x(N)).^2 + (y(N)-y(N-1)).^2))) + (c*((x(i+1)+x(N)-2*x(i)).^2+((y(i)+y(N-1)-2*y(N)).^2)))) <bestValue
                    movedPoints = movedPoints +1;
                    bestValue = (a*gradient(x(i),y(N)) + (b*(d-((x(i)-x(N)).^2 + (y(N)-y(N-1)).^2))) + (c*((x(i+1)+x(N)-2*x(i)).^2+((y(i)+y(N-1)-2*y(N)).^2))));
                    y(i) = y(i)-1;
                end
            end
            if x(i) < ncols
                if (a*gradient(x(i+1),y(i)) + (b*(d-((x(i+1)-x(1)).^2 + (y(i)-y(N)).^2))) + (c*((x(i+2)+x(1)-2*x(i+1)).^2+((y(i+1)+y(N)-2*y(i)).^2)))) <bestValue
                    movedPoints = movedPoints +1;
                    bestValue = (a*gradient(x(i+1),y(i)) + (b*(d-((x(i+1)-x(1)).^2 + (y(i)-y(N)).^2))) + (c*((x(i+2)+x(1)-2*x(i+1)).^2+((y(i+1)+y(N)-2*y(i)).^2))));
                    x(i) = x(i)+1;
                end
            end
            if y(i) < nrows
                if (a*gradient(x(i),y(i+1)) + (b*(d-((x(i)-x(N)).^2 + (y(i+1)-y(1)).^2))) + (c*((x(i+1)+x(N)-2*x(i)).^2+((y(i+2)+y(1)-2*y(i+1)).^2)))) <bestValue
                    movedPoints = movedPoints +1;
                    bestValue = (a*gradient(x(i),y(i+1)) + (b*(d-((x(i)-x(N)).^2 + (y(i+1)-y(1)).^2))) + (c*((x(i+1)+x(N)-2*x(i)).^2+((y(i+2)+y(1)-2*y(i+1)).^2))));
                    y(i) = y(i)+1;
                end
            end
            %
            %
        else if i == N
                %other edge point
                
                bestValue = (a*gradient(x(i),y(i)) + (b*(d-((x(i)-x(i-1)).^2 + (y(i)-y(i-1)).^2))) + (c*((x(1)+x(i-1)-2*x(i)).^2+((y(1)+y(i-1)-2*y(i)).^2))));
                bestPoint = i;
                %
                %
                if x(i) > 1
                    if (a*gradient(x(i-1),y(i)) + (b*(d-((x(i)-x(i-1)).^2 + (y(i)-y(i-1)).^2))) + (c*((x(i)+x(i-1)-2*x(i-1)).^2+((y(1)+y(i)-2*y(i)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(i-1),y(i)) + (b*(d-((x(i-1)-x(i-1)).^2 + (y(i)-y(i)).^2))) + (c*((x(i)+x(i-1)-2*x(i-1)).^2+((y(1)+y(i)-2*y(i)).^2))));
                        x(i) = x(i)-1;
                    end
                end
                if y(i) > 1
                    if (a*gradient(x(i),y(i-1)) + (b*(d-((x(i)-x(i-1)).^2 + (y(i-1)-y(i)).^2))) + (c*((x(1)+x(i-2)-2*x(i)).^2+((y(1)+y(i-1)-2*y(i)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(i),y(i-1)) + (b*(d-((x(i)-x(i-1)).^2 + (y(i-1)-y(i)).^2))) + (c*((x(1)+x(i-1)-2*x(i)).^2+((y(1)+y(i-1)-2*y(i)).^2))));
                        y(i) = y(i)-1;
                    end
                end
                if x(i) < ncols
                    if (a*gradient(x(1),y(i)) + (b*(d-((x(1)-x(i)).^2 + (y(i)-y(i-1)).^2))) + (c*((x(1)+x(i-1)-2*x(i)).^2+((y(1)+y(i-1)-2*y(i)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(1),y(i)) + (b*(d-((x(1)-x(i)).^2 + (y(i)-y(i-1)).^2))) + (c*((x(1)+x(i-1)-2*x(i)).^2+((y(1)+y(i-1)-2*y(i)).^2))));
                        x(i) = x(i)+1;
                    end
                end
                if y(i) < nrows
                    if (a*gradient(x(i),y(1)) + (b*(d-((x(i)-x(i-1)).^2 + (y(1)-y(i)).^2))) + (c*((x(1)+x(i-1)-2*x(i)).^2+((y(1)+y(i-1)-2*y(i)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(i),y(1)) + (b*(d-((x(i)-x(i-1)).^2 + (y(1)-y(i)).^2))) + (c*((x(1)+x(i-1)-2*x(i)).^2+((y(1)+y(i-1)-2*y(i)).^2))));
                        y(i) = y(i)+1;
                    end
                end
                %
                %
            else
                %general point
                
                bestValue = (a*gradient(x(i),y(i)) + (b*(d-((x(i)-x(i-1)).^2 + (y(i)-y(i-1)).^2))) + (c*((x(i+1)+x(i-1)-2*x(i)).^2+((y(i+1)+y(i-1)-2*y(i)).^2))));
                bestPoint = i;
                %
                %
                if x(i) > 1
                    if (a*gradient(x(N),y(i)) + (b*(d-((x(i)-x(N)).^2 + (y(i)-y(N)).^2))) + (c*((x(i)+x(N-1)-2*x(N)).^2+((y(i+1)+y(N)-2*y(i)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(N),y(i)) + (b*(d-((x(i)-x(N)).^2 + (y(i)-y(N)).^2))) + (c*((x(i)+x(N-1)-2*x(N)).^2+((y(i+1)+y(N)-2*y(i)).^2))));
                        x(i) = x(i)-1;
                    end
                end
                if y(i) > 1
                    if (a*gradient(x(i),y(N)) + (b*(d-((x(i)-x(N)).^2 + (y(N)-y(i)).^2))) + (c*((x(i+1)+x(N-1)-2*x(N)).^2+((y(i+1)+y(N)-2*y(i)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(i),y(N)) + (b*(d-((x(i)-x(N)).^2 + (y(N)-y(i)).^2))) + (c*((x(i+1)+x(N-1)-2*x(N)).^2+((y(i+1)+y(N)-2*y(i)).^2))));
                        y(i) = y(i)-1;
                    end
                end
                if x(i) < nrows
                    if (a*gradient(x(i+1),y(i)) + (b*(d-((x(i)-x(i+1)).^2 + (y(i)-y(i-1)).^2))) + (c*((x(i)+x(1)-2*x(i+1)).^2+((y(i+1)+y(i-1)-2*y(i)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(i+1),y(i)) + (b*(d-((x(i)-x(i+1)).^2 + (y(i)-y(i-1)).^2))) + (c*((x(i)+x(1)-2*x(i+1)).^2+((y(i+1)+y(i-1)-2*y(i)).^2))));
                        x(i) = x(i)-1;
                    end
                end
                if y(i) < ncols
                    if (a*gradient(x(i),y(i+1)) + (b*(d-((x(i)-x(N)).^2 + (y(i+1)-y(i)).^2))) + (c*((x(i+1)+x(N-1)-2*x(N)).^2+((y(1)+y(i)-2*y(i+1)).^2)))) <bestValue
                        movedPoints = movedPoints +1;
                        bestValue = (a*gradient(x(i),y(i+1)) + (b*(d-((x(i)-x(N)).^2 + (y(i+1)-y(i)).^2))) + (c*((x(i+1)+x(N-1)-2*x(N)).^2+((y(1)+y(i)-2*y(i+1)).^2))));
                        y(i) = y(i)-1;
                    end
                end
                %
                %
            end
        end
        
        %increment counter
        i = i+1;
    end
    
    %setting moved points
    cntPt = movedPoints;
    %
    %END SNAKE
    
    %visualize the shrink process
    figure(2); clf; imshow(im); hold on;
    plot([x; x(1)], [y; y(1)], 'r-*');
    hold off; drawnow;
end