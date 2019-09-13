cla
set(gca,'xlim', [0,1], 'xtick', [], 'ytick', [], 'box', 'on', 'Position', [0.1,0.15,0.8,0.8])

text(.5,.72,'Assignment 3, Plane, cube and its Projection on the Plane', 'Fontsize', 12, 'Fontweight', 'bold', 'FontName', 'Times', 'HorizontalAlignment', 'center', 'Color', 'm')

x=0;y=10;w=80;h=30;xinc=80;
uicontrol('String', 'Axes', 'Callback', 'axes', 'Position', [x,y,w,h]);x=x+xinc;
uicontrol('String', 'Plane', 'Callback', 'plane', 'Position', [x,y,w,h]);x=x+xinc;
uicontrol('String', 'Cube', 'Callback', 'cube', 'Position', [x,y,w,h]);x=x+xinc;
uicontrol('String', 'ParallelProCube', 'Callback', 'parallel', 'Position', [x,y,w,h]);x=x+xinc;
uicontrol('String', 'Perspective', 'Callback', 'perspective', 'Position', [x,y,w,h]);x=x+xinc;
uicontrol('String', 'Reset', 'Callback', 'Assignment3_main', 'Position', [x,y,w,h]);x=x+xinc;
uicontrol('String', 'About', 'Callback', 'about', 'Position', [x,y,w,h]);x=x+xinc;