const double g = 9.81;

//mase
const double m_propeler = 0.007;
const double m_motor_drzac = 0.01;
const double m_motor = 0.185;
const double m_enkoder = 0.3;
const double m_sipka = 0.04;
const double m_drzac = 0.015;
const double m_heli = 2*(m_propeler + m_motor + m_motor_drzac) + m_sipka + m_drzac;

const double d_sipka = 0.35; //duzina osovine na kojoj su motori
const double d_heli = 0.41; //ukupna duzina helica
const double d_p = 0.195; //razmak od pivota do pitch rotora
const double d_y = 0.185; // razmak od pivota do yaw rotora
const double l_cm = 0.005; //pomak centra mase od osi zakreta

const double J_propeler = 4.1e-6; //moment inercije propelera oko svog CM
const double J_sipka_p = m_sipka * d_sipka^2 / 12; //moment inercije sipke oko pitch osi;
//momenti inercije dobiveni u solidworksu
const double J_p = 0.0147;
const double J_y = 0.0165;

const double J_eq_y = J_y - m_heli*l_cm^2;

//moment proizveden od motora
const double K_pp = 0.25 * d_p; //pitch motor, pitch moment (Nm/V)
const double K_yy = 0.25 * d_y; //yaw motor, yaw moment (Nm/V)

const double K_py = 0.01; //protumomenti motora
const double K_yp = 0.01;

//trenje
const double B_p = 0.08;
const double B_y = 0.14;

//za integrator
const double Qi = diag([500 450 180 120 150 180]);
const double Ri = diag([3 3]);

//izracunati Q
const double Qi = diag([340 260 300 200 180 220]);

//Qi = diag([340 220 450 400 180 180]);
