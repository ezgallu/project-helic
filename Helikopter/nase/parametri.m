g = 9.81;

%mase
m_propeler = 0.007;
m_motor_drzac = 0.01;
m_motor = 0.185;
m_enkoder = 0.3;
m_sipka = 0.04;

d_sipka = 0.35; %duzina osovine na kojoj su motori
d_heli = 0.41; %ukupna duzina helica
d_p = 0.2; %razmak od pivota do pitch rotora
d_y = 0.18; % razmak od pivota do yaw rotora
lcm = 0.01; %pomak centra mase od osi zakreta

J_propeler = 8.1e-6; %moment inercije propelera oko svog CM
J_sipka_p = m_sipka * d_sipka^2 / 12; %moment inercije sipke oko pitch osi;

%momenti inercije dobiveni u solidworksu
J_p = 0.0147;
J_y = 0.0165;

%moment proizveden od motora
K_pp = 0.35 * d_p; %pitch motor, pitch moment (Nm/V)
K_yy = 0.35 * d_y; %yaw motor, yaw moment (Nm/V)

K_py = 0.018; %protumomenti motora
K_yp = 0.018;

%trenje
B_p = 0.3;
B_y = 0.5;

%pocetni Q i R u ovisnosti o rasponu djelovanja
Q = diag(2000*[10000*90^(-2) 10000*180^(-2) (1.1781*500)^(-2) (2.3562*500)^(-2)]);
R = diag([6 6]);

%druga varijanta
%Q = diag([300 200 100 50]);
%R = diag([5 5]);

%za integrator
%Q = diag([340 220 230 80 200 200]);
%R = diag([6 6]);
