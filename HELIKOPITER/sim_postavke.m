%postavljanje svih vrijednosti za simulaciju
parametri;
ABCD;
%max naponi
max_u = 3.5;

%pocetni kut theta
theta_0 = -60*pi/180;

%rezolucija enkodera
K_EC_P = 2 * pi / 2400;
K_EC_Y = 2 * pi / 2400;

%anti_windup: integrator reset time
Tr_p = 1;
Tr_y = 1;

%pojacanje regulatora
K_i = lrq_i(A,B,Qi,Ri)

% Specifications of a second-order low-pass filter
wcf = 2 * pi * 20; % filter cutting frequency
zetaf = 0.85;        % filter damping ratio