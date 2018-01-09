g = 9.81;

%mase
m_propeler = 0.007;
m_motor_drzac = 0.01;
m_motor = 0.185;
m_enkoder = 0.3;
m_sipka = 0.04;
m_drzac = 0.015;
m_heli = 2*(m_propeler + m_motor + m_motor_drzac) + m_sipka + m_drzac;

d_sipka = 0.35; %duzina osovine na kojoj su motori
d_heli = 0.41; %ukupna duzina helica
d_p = 0.195; %razmak od pivota do pitch rotora
d_y = 0.185; % razmak od pivota do yaw rotora
l_cm = 0.005; %pomak centra mase od osi zakreta

J_propeler = 4.1e-6; %moment inercije propelera oko svog CM
J_sipka_p = m_sipka * d_sipka^2 / 12; %moment inercije sipke oko pitch osi;

%momenti inercije dobiveni u solidworksu
J_p = 0.0147;
J_y = 0.0165;

J_eq_y = J_y - m_heli*l_cm^2;

%moment proizveden od motora
K_pp = 0.25 * d_p; %pitch motor, pitch moment (Nm/V)
K_yy = 0.25 * d_y; %yaw motor, yaw moment (Nm/V)

K_py = 0.01; %protumomenti motora
K_yp = 0.01;

%trenje
B_p = 0.08;
B_y = 0.14;

%za integrator
%Qi = diag([500 450 180 120 150 180]);
Ri = diag([3 3]);

%izracunati Q
Qi = diag([340 260 300 200 180 220]);

%Qi = diag([340 220 450 400 180 180]);
