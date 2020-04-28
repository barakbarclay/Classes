done=0;
L=2;
while (~done)
L=L+1;
n=0:(L-1);
f=2/L.*cos(0.44*pi*n);
w=-pi:pi/500:pi;
H=freqz(f,1,w);
jkl=[1:150 350:650 850:1001];
done=max(abs(H(jkl)))<max(abs(H)*0.1);
end
L-1
  