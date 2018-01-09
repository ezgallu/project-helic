close all; clear all; clc;

syms  t theta(t) psi(t) l_cm

q = [theta, psi];
dq =  [diff(theta(t), t), diff(psi(t), t)];

T_0_1 = [cos(psi(t)), sin(psi(t)), 0, 0;
    -sin(psi(t)), cos(psi(t)), 0, 0;
    0, 0, 1, 0;
    0, 0, 0, 1];

T_1_2 = [cos(theta(t)), 0, -sin(theta(t)), 0;
    0, 1, 0, 0;
    sin(theta(t)), 0, cos(theta(t)), 0;
    0, 0, 0, 1];

T_2_3 = [1, 0, 0, l_cm;
    0, 1, 0, 0;
    0, 0, 1, 0;
    0, 0, 0, 1];

T_0_3 = T_0_1 * T_1_2 * T_2_3;

x_cm = T_0_3(1,4);
y_cm = T_0_3(2,4);
z_cm = T_0_3(3,4);
 
dx_cm = diff(x_cm, t);
dy_cm = diff(y_cm, t);
dz_cm = diff(z_cm, t);
 
syms x1 x2 x3 x4
subs({theta(t),psi(t)}, {x1,x2});
subs({diff(theta(t),t),diff(psi(t),t)}, {x3,x4});