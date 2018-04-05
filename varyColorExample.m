x=sin(1:.01:20);

ColorSet=varycolor(300);
figure;
hold on
for i=1:300
    plot(x.*2*i,'Color',ColorSet(i,:))
end
hold off