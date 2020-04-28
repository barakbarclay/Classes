function ss=L2S6Pe(xv)
dur=0.00000002;
c=3*10^8;
t1= sqrt(xv.^2+1500.^2);
t2=sqrt((1500-900).^2+100.^2)-sqrt((100-xv).^2+900.^2);
phi1=-2*pi*(t1/(dur/3));
phi2=-2*pi*(t2/(dur/3));
  if xv>100
    X=exp(j*phi1)+exp(j*phi2);
  else
    X=exp(j*phi1)-exp(j*phi2);
  end
ss=abs(X);
plot(xv,ss),grid on
C=ss<0.000001
M=max(ss)
m=min(ss)
end
