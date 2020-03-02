first=0;

last=149;

nn=first:last;

xx=5*cos(0.3*pi.*nn)+22*cos(0.44*pi.*nn-pi/3)+22*cos(0.7*pi.*nn-pi/4);

subplot(4,1,1);

stem(nn,xx(nn+1))

xlabel('Time Index(n)')

ylabel('xx')

bb=[1 -2*cos(0.44*pi) 1];  % Filter 1

ww=firfilt(bb,xx);

subplot(4,1,2);

stem(nn,ww(nn+1),'filled')

xlabel('Time Index(n)')

ylabel('ww Output')

 

w=-pi:(pi/500):pi;

HH=freqz(bb,1,w);          % the frequency response of Filter 1

subplot(4,1,3);

plot(w,abs(HH))

subplot(4,1,4);

plot(w,angle(HH))

 

 

ww=firfilt(bb,xx);

subplot(4,1,1);

stem(nn,ww(nn+1),'filled')

xlabel('Time Index(n)')

ylabel('ww Output')

 

bb2=[1 -2*cos(0.7*pi) 1];  % Filter 2

yy=firfilt(bb2,ww);

subplot(4,1,2);

stem(nn,yy(nn+1),'filled')

xlabel('Time Index(n)')

ylabel('yy Output')

 

w=-pi:(pi/500):pi;

HH=freqz(bb2,1,w);         % the frequency response of Filter 2

subplot(4,1,3);

plot(w,abs(HH))

subplot(4,1,4);

plot(w,angle(HH))