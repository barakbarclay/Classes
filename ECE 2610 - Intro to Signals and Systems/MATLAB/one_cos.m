function  [xx,tt] = one_cos(w,A,dur,phi)

tt=-dur:(1/(w/(2*pi)))/20:dur;

xx=A * cos (w*tt+phi);

plot(tt,xx),grid on

end 
