
%% SETUP_LAB_HELI_2D
%
% 2 DOF Helicopter (2DHELI) Control Lab: 
% Design of a FF+LQR+I position controller
% 
% SETUP_LAB_HELI_2D sets the model parameters and set the controller
% parameters for the Quanser 2DOF Helicopter system.
%
% Copyright (C) 2010 Quanser Consulting Inc.
% Quanser Consulting Inc.
%
clear all;
%
%% Amplifier/Voltage and Position Settings
% Amplifier Gain: set to 3 when using VoltPAQ-X2. 
% NOTE: If using VoltPAQ-X1, make sure both Gain switches are set to 3.
K_AMP = 1;
% Maximum Output Voltage (V): YAW limited to 15 V. PITCH limited to 24 V.
VMAX_AMP_P = 3.2;
VMAX_AMP_Y = 3.2;
% Initial Angle of Pitch (rad)
theta_0 = -47*pi/180;
% Pitch and Yaw Axis Encoder Resolution (rad/count)
K_EC_P = 2 * pi / 2400;
K_EC_Y = 2 * pi / 2400;
%
%% Controller Configuration
% Anti-windup: integrator saturation (V)
SAT_INT_ERR_PITCH =3.2;
SAT_INT_ERR_YAW = 3.2;
% Anti-windup: integrator reset time (s)
Tr_p = 1;
Tr_y = 1;
% Type of Controller: set it to 'LQR_AUTO' or 'MANUAL'  
CONTROLLER_TYPE = 'LQR_AUTO';    % LQR controller design: automatic mode
%CONTROLLER_TYPE = 'MANUAL';    % controller design: manual mode
% Specifications of a second-order low-pass filter
wcf = 2 * pi * 20; % filter cutting frequency
zetaf = 0.85;        % filter damping ratio
%% Load Model
% Set the model parameters of the 2DOF HELI.
% These parameters are used for model representation and controller design.
parametri;
%
% For the following state vector: X = [ theta; psi; theta_dot; psi_dot]
% Initialization the state-Space representation of the open-loop System
ABCD;
%
%% Display
if strcmp ( CONTROLLER_TYPE, 'LQR_AUTO' )
    % Feed-forward gain adjustment (V/V)
    K_ff = 1;
    % LQR Controller Design Specifications
    Q = diag([300 200 100 50]);
    R = diag([5 5]);

    % Automatically calculate the LQR controller gain
    [ K ] = d_heli_2d_lqr( A, B, C, D, Q, R );    
    % Display the calculated gains
    disp( ' ' )
    disp( 'Calculated LQR controller gain elements: ' )
    disp( [ 'K = [' num2str( K(1,1),3 ) ' V/rad  '  num2str( K(1,2),3 ) ' V/rad  ' num2str( K(1,3),3 ) ' V.s/rad  '  num2str( K(1,4),3 ) ' V.s/rad]'] )
    disp( [ '    [' num2str( K(2,1),3 ) ' V/rad  '  num2str( K(2,2),3 ) ' V/rad  ' num2str( K(2,3),3 ) ' V.s/rad  '  num2str( K(2,4),3 ) ' V.s/rad]'] )
    %
    % LQR+I Controller Design Specifications
    R = diag([5 5]);
    % Automatically calculate the LQR controller gain
    [ Ki ] = d_heli_2d_lqr_i( A, B, C, D, Qi, Ri );    
    % Display the calculated gains
    disp( ' ' )
    disp( 'Calculated LQR+I controller gain elements: ' )
    disp( [ 'Ki = [' num2str( Ki(1,1),3 ) ' V/rad  '  num2str( Ki(1,2),3 ) ' V/rad  ' num2str( Ki(1,3),3 ) ' V.s/rad  '  num2str( Ki(1,4),3 ) ' V.s/rad ' num2str( Ki(1,5),3 ) ' V/(rad.s) ' num2str( Ki(1,6),3 ) ' V/(rad.s)]'] )
    disp( [ '    [' num2str( Ki(2,1),3 ) ' V/rad  '  num2str( Ki(2,2),3 ) ' V/rad  ' num2str( Ki(2,3),3 ) ' V.s/rad  '  num2str( Ki(2,4),3 ) ' V.s/rad ' num2str( Ki(2,5),3 ) ' V/(rad.s) ' num2str( Ki(2,6),3 ) ' V/(rad.s)]' ] )    
elseif strcmp ( CONTROLLER_TYPE, 'MANUAL' )
    disp( [ 'K = [' 0 ' V/rad  '  0 ' V/rad  ' 0 ' V.s/rad  '  0 ' V.s/rad]'] )
    disp( ' ' )
    disp( 'STATUS: manual mode' ) 
    disp( 'The model parameters of your Single Pendulum and IP01 or IP02 system have been set.' )
    disp( 'You can now design your state-feedback position controller.' )
    disp( ' ' )
else
    error( 'Error: Please set the type of controller that you wish to implement.' )
end
