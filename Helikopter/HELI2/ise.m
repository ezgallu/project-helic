function j = ise(Q)
    A( 1, 1 ) = 0;
    A( 1, 2 ) = 0;
    A( 1, 3 ) = 1;
    A( 1, 4 ) = 0;
    A( 2, 1 ) = 0;
    A( 2, 2 ) = 0;
    A( 2, 3 ) = 0;
    A( 2, 4 ) = 1;
    A( 3, 1 ) = 0;
    A( 3, 2 ) = 0;
    A( 3, 3 ) = -20.4082;
    A( 3, 4 ) = 0;
    A( 4, 1 ) = 0;
    A( 4, 2 ) = 0;
    A( 4, 3 ) = 0;
    A( 4, 4 ) = -27.2727;
    
    B( 1, 1 ) = 0;
    B( 1, 2 ) = 0;
    B( 2, 1 ) = 0;
    B( 2, 2 ) = 0;
    B( 3, 1 ) = 4.6429;
    B( 3, 2 ) = 1.2245;
    B( 4, 1 ) = 1.0909;
    B( 4, 2 ) = 3.9242;

    K_i = lrq_i(A,B,Q,diag([3 3]));
    set_param('model/simulacija/kontroler/Control Gain: K','Gain',mat2str(K_i(:,1:4)));
    set_param('model/simulacija/kontroler/p_antiwindup/Pitch Integral Control Gain: K(1,5)','Gain',mat2str(K_i(1,5)));
    set_param('model/simulacija/kontroler/p_antiwindup/Yaw Cross-Integral Control Gain: K(1,6)','Gain',mat2str(K_i(1,6)));
    set_param('model/simulacija/kontroler/y_antiwindup/Yaw Integral Control Gain: K(2,6)','Gain',mat2str(K_i(2,6)));
    set_param('model/simulacija/kontroler/y_antiwindup/Pitch Cross-Integral Control Gain: K(2,5)','Gain',mat2str(K_i(2,5)));
    sim('model');
    [m,a] = max(abs(p));
    [m,b] = max(abs(y));
    j = (abs(y_error(b)) + abs(p_error(a)))^2;
    %kazna za veliko odstupanje
    if (abs(y_error(b)) > 0.3) || (abs(p_error(a)) > 0.5)
        j = j*1000000;
    end
end