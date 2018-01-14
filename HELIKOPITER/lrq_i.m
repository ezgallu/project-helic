function [Ki] = lrq_i(A,B,Qi,Ri)

%Augment the state
A = [A(1,:) 0 0;
    A(2,:) 0 0;
    A(3,:) 0 0;
    A(4,:) 0 0;
    1 0 0 0 0 0;
    0 1 0 0 0 0 ];
   
B = [B;
    0 0;
    0 0];  

[ Ki, S, EIG_CL ] = lqr( A, B, Qi, Ri );

end