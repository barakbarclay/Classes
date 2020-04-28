%SYN_SIN Function to synthesize a sum of cosine waves
% usage:
% [xx,tt] = syn_sin(fk, Xk, fs, dur, tstart)
% fk = vector of frequencies
% (these could be negative or positive)
% Xk = vector of complex amplitudes: Amp*eˆ(j*phase)
% fs = the number of samples per second for the time axis
% dur = total time duration of the signal
% tstart = starting time (default is zero, if you make this input optional)
% xx = vector of sinusoidal values
% tt = vector of times, for the time axis
%
% Note: fk and Xk must be the same length.
% Xk(1) corresponds to frequency fk(1),
% Xk(2) corresponds to frequency fk(2), etc.
function [xx,tt]=syn_sin(fk,Xk,fs,dur,tstart)
 
if nargin < 3 %Nargin in the amount of varibles entered for the function
 
    error('Error - Input fk, Xk, and fs.');
 
 end
 
if nargin < 4
 
    dur = 1.0;
 
end
 
if nargin < 5
 
    tstart = 0;
 
end
 
L1 = length(fk); %both L1 and L2 will be the # of sineusoids
 
L2 = length(Xk);
 
if(L1~=L2)
 
    error('ERROR - fk and Xk must be the same size');
 
end
 
tt=tstart:1/fs:dur;
 
x1=zeros(1,length(tt)); %Fills a array with zeros. Array will go
%from # of sinusids to amount of samples
 
xx=zeros(1,length(tt));
 
for k=1:L2
 
    A = abs(Xk(k));
 
    x1(k,:)= A*cos(2*pi*fk(k)*tt+angle(Xk(k)));
 
    xx = xx+x1(k,:);
 
    period(k)= 1/fk(k);
 
    subplot(L1+1,1,k);plot(tt,x1(k,:));grid on;
 
end
 
xx = sum(x1);
 
period
 
subplot(L1+1,1,k+1);plot(tt,xx);grid on;
