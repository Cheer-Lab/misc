%% Strain gauge
% Reads data from puTTY stream collected using voltagPrint sketch on arduino,
% then plots values to view which side of the box the animal is in.
% Authors: Tori Ayvazian and Brian Carson

box1=[]; % preallocate/clear old data
box2=[];
t=[];
filename=uigetfile('*.txt'); % open file selection dialog box
%% Get data for each box
t=readtable(filename); % read puTTY file into table 
box1=t{:,1}; % box1 from A2 in column 1 - {} braces extract double from table
box2=t{:,2}; % box2 from A5 in column 2

% smooth signals with filter
box1=sgolayfilt(box1,1,19); 
box2=sgolayfilt(box2,1,19);

% plot centered around 0 using mode subtraction from beginning of file
figure
subplot(2,1,1)
plot(box1-mode(box1(1:100)))
title('Box 1')
subplot(2,1,2)
plot(box2-mode(box2(1:100))) 
title('Box 2')
