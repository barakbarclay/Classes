function xx=dis(xv)
f=150000000;
dur=0.00000002;
t=0:1/(1000000*f):dur;
c=3*10^8;
dt=1500;
dyr=900;
dxr=100;
t1(xv)= sqrt(xv^2+dt^2);
  if xv>100
    t2(xv)=[ sqrt((dt-dyr)^2+dxr^2)+sqrt((dxr-xv)^2+dyr^2)]/c; 
  else
    t2(xv)=[ sqrt((dt-dyr)^2+dxr^2)-sqrt((dxr-xv)^2+dyr^2)]/c;
  end
r=cos( 2*pi*f*t-2*pi*t1(xv))- cos ( 2*pi*f*t-2*pi*t2(xv));
plot(t,r),grid on
end