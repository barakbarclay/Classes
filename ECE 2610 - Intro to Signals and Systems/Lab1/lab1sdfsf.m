tt = -.00025:.0000025:.00025;
T = .00025;
D = 1;
M = 9;
tm1 = (37.2/M)*T;
tm2 = -(41.3/D)*T;
A1 = 21;
A2 = 1.2*A1;
t = tt;
x1 = A1*cos(2*pi*4000*(t-tm1));
x2 = A2*cos(2*pi*4000*(t-tm2));
%{
figure()
subplot(3,1,1), plot(t,x1)
subplot(3,1,2), plot(t,x2)
x3 = abs(x1+x2);
subplot(3,1,3), plot(t,x3)
%}
%e = 2.718281828;
x1a = real(21*(exp(j*8000*pi))*exp(j*8000*pi*(t-tm1)));
figure()
subplot(3,1,1), plot(t,real(x1))
subplot(3,1,2), plot(t,(x1a))
