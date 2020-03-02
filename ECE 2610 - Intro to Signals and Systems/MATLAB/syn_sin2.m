function [xx,tt]=syn_sin2(fk,xk,fs,dur,tstart)

if nargin <5, tstart=0, end

if length (xk)~=length (fk)

    error ('error', ' fk~=xk');

end

t= tstart: 1/(fs):dur;

x=xk(1)* exp(2*j*pi*fk(1)*t);

for k=2: length(fk);

    x=xk(k) *exp(2*j*pi*fk(k)*t)+x;

end

plot(t,x),grid on