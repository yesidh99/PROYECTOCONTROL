clc

s=tf('s');
z=tf('z');
Tau=66.93;
Ts=Tau/10;%Criterio1
Ts2=Tau/100;%Crioterio2
G=(56.77)/((66.93*s)+1);%Seba
%G=0.8482/(s+0.01494);
%G=(50.7813)/((86.45*s)+1);%Camilo
H=1/100;
GGhoHz=c2d(G*H,Ts);%dis-crit-1
GGhoHz2=c2d(G*H,Ts2);%dis-crit-2
GGhoz=c2d(G,Ts);
