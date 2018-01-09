  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_heli_2d_ff_lqr_i_nas_P)
    ;%
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_P.B_p
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.B_y
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.J_eq_p
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.J_eq_y
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_AMP
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 12;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_EC_P
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 13;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_EC_Y
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 14;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_ff
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 15;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_pp
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 16;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_py
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 17;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_yp
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 18;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.K_yy
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 19;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SAT_INT_ERR_PITCH
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 20;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SAT_INT_ERR_YAW
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Tr_p
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Tr_y
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 23;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.VMAX_AMP_P
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 24;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.VMAX_AMP_Y
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 25;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.g
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 26;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.l_cm
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 27;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.m_heli
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 28;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.theta_0
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 29;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput_FinalValue
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 30;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput1_FinalValue
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 31;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput_InitialValue
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 32;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput1_InitialValue
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 33;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput_InputFilter
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 34;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput1_InputFilter
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 35;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput_MaxMissedTicks
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 36;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput1_MaxMissedTicks
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 37;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput_MaxMissedTicks
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 38;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput1_MaxMissedTicks
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 39;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput_YieldWhenWaiting
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 40;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput1_YieldWhenWaiting
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 41;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput_YieldWhenWaiting
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 42;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput1_YieldWhenWaiting
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 43;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchRelay_const
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 44;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.CompareToConstant_const
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 45;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawRelay_const
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 46;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.CompareToConstant_const_n
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 47;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchRelay_const_p
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 48;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.CompareToConstant_const_d
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 49;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawRelay_const_i
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 50;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.CompareToConstant_const_e
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 51;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.ConstantPitchdeg_gain
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 52;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.EncoderInput1_Channels
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 48;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput1_Channels
	  section.data(4).logicalSrcIdx = 49;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 50;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput1_RangeMode
	  section.data(6).logicalSrcIdx = 51;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 52;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AnalogOutput1_VoltRange
	  section.data(8).logicalSrcIdx = 53;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 58;
      section.data(58)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_P.LQR1LQRI2Pitchopenloop3Yawopenloop4_Value
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Constant_Value
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorPitchV_Amplitude
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorPitchV_Frequency
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AmplitudePitchV_Gain
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.ConstantPitchV_Value
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Constant_Value_i
	  section.data(7).logicalSrcIdx = 60;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorPitch_Amplitude
	  section.data(8).logicalSrcIdx = 61;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorPitch_Frequency
	  section.data(9).logicalSrcIdx = 62;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AmplitudePitchdeg_Gain
	  section.data(10).logicalSrcIdx = 63;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Constant_Value_k
	  section.data(11).logicalSrcIdx = 64;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Gain1_Gain
	  section.data(12).logicalSrcIdx = 65;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.DerivativeFilterPitch_A
	  section.data(13).logicalSrcIdx = 66;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.DerivativeFilterPitch_C
	  section.data(14).logicalSrcIdx = 67;
	  section.data(14).dtTransOffset = 14;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.DerivativeFilterYaw_A
	  section.data(15).logicalSrcIdx = 68;
	  section.data(15).dtTransOffset = 16;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.DerivativeFilterYaw_C
	  section.data(16).logicalSrcIdx = 69;
	  section.data(16).dtTransOffset = 18;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.X_Gain
	  section.data(17).logicalSrcIdx = 70;
	  section.data(17).dtTransOffset = 20;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorYaw_Amplitude
	  section.data(18).logicalSrcIdx = 71;
	  section.data(18).dtTransOffset = 36;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorYaw_Frequency
	  section.data(19).logicalSrcIdx = 72;
	  section.data(19).dtTransOffset = 37;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AmplitudeYawdeg_Gain
	  section.data(20).logicalSrcIdx = 73;
	  section.data(20).dtTransOffset = 38;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.ConstantYawdeg_Value
	  section.data(21).logicalSrcIdx = 74;
	  section.data(21).dtTransOffset = 39;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Gain1_Gain_g
	  section.data(22).logicalSrcIdx = 75;
	  section.data(22).dtTransOffset = 40;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.X_Gain_k
	  section.data(23).logicalSrcIdx = 76;
	  section.data(23).dtTransOffset = 41;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.ControlGainK_Gain
	  section.data(24).logicalSrcIdx = 77;
	  section.data(24).dtTransOffset = 57;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Integrator_IC
	  section.data(25).logicalSrcIdx = 78;
	  section.data(25).dtTransOffset = 65;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Memory_X0
	  section.data(26).logicalSrcIdx = 79;
	  section.data(26).dtTransOffset = 66;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Gain_Gain
	  section.data(27).logicalSrcIdx = 80;
	  section.data(27).dtTransOffset = 67;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorYawV_Amplitude
	  section.data(28).logicalSrcIdx = 81;
	  section.data(28).dtTransOffset = 68;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.SignalGeneratorYawV_Frequency
	  section.data(29).logicalSrcIdx = 82;
	  section.data(29).dtTransOffset = 69;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.AmplitudeYawV_Gain
	  section.data(30).logicalSrcIdx = 83;
	  section.data(30).dtTransOffset = 70;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.ConstantYawV_Value
	  section.data(31).logicalSrcIdx = 84;
	  section.data(31).dtTransOffset = 71;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Constant_Value_o
	  section.data(32).logicalSrcIdx = 85;
	  section.data(32).dtTransOffset = 72;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Integrator_IC_i
	  section.data(33).logicalSrcIdx = 86;
	  section.data(33).dtTransOffset = 73;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Memory_X0_m
	  section.data(34).logicalSrcIdx = 87;
	  section.data(34).dtTransOffset = 74;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchIntegralControlGainK15_Gain
	  section.data(35).logicalSrcIdx = 88;
	  section.data(35).dtTransOffset = 75;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawCrossIntegralControlGainK16_Gain
	  section.data(36).logicalSrcIdx = 89;
	  section.data(36).dtTransOffset = 76;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawIntegralControlGainK26_Gain
	  section.data(37).logicalSrcIdx = 90;
	  section.data(37).dtTransOffset = 77;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchCrossIntegralControlGainK25_Gain
	  section.data(38).logicalSrcIdx = 91;
	  section.data(38).dtTransOffset = 78;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Gain_Gain_a
	  section.data(39).logicalSrcIdx = 92;
	  section.data(39).dtTransOffset = 79;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Gain_Gain_d
	  section.data(40).logicalSrcIdx = 93;
	  section.data(40).dtTransOffset = 80;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.psi_IC
	  section.data(41).logicalSrcIdx = 94;
	  section.data(41).dtTransOffset = 81;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.theta_dot_IC
	  section.data(42).logicalSrcIdx = 95;
	  section.data(42).dtTransOffset = 82;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.psi_dot_IC
	  section.data(43).logicalSrcIdx = 96;
	  section.data(43).dtTransOffset = 83;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Gain_Gain_l
	  section.data(44).logicalSrcIdx = 97;
	  section.data(44).dtTransOffset = 84;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Constant_Value_a
	  section.data(45).logicalSrcIdx = 98;
	  section.data(45).dtTransOffset = 85;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Constant_Value_p
	  section.data(46).logicalSrcIdx = 99;
	  section.data(46).dtTransOffset = 86;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.X_Gain_j
	  section.data(47).logicalSrcIdx = 100;
	  section.data(47).dtTransOffset = 87;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.X_Gain_d
	  section.data(48).logicalSrcIdx = 101;
	  section.data(48).dtTransOffset = 103;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.ControlGainK_Gain_h
	  section.data(49).logicalSrcIdx = 102;
	  section.data(49).dtTransOffset = 119;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Integrator_IC_p
	  section.data(50).logicalSrcIdx = 103;
	  section.data(50).dtTransOffset = 127;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Memory_X0_c
	  section.data(51).logicalSrcIdx = 104;
	  section.data(51).dtTransOffset = 128;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Constant_Value_d
	  section.data(52).logicalSrcIdx = 105;
	  section.data(52).dtTransOffset = 129;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Integrator_IC_b
	  section.data(53).logicalSrcIdx = 106;
	  section.data(53).dtTransOffset = 130;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.Memory_X0_a
	  section.data(54).logicalSrcIdx = 107;
	  section.data(54).dtTransOffset = 131;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchIntegralControlGainK15_Gain_a
	  section.data(55).logicalSrcIdx = 108;
	  section.data(55).dtTransOffset = 132;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawCrossIntegralControlGainK16_Gain_j
	  section.data(56).logicalSrcIdx = 109;
	  section.data(56).dtTransOffset = 133;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawIntegralControlGainK26_Gain_h
	  section.data(57).logicalSrcIdx = 110;
	  section.data(57).dtTransOffset = 134;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchCrossIntegralControlGainK25_Gain_a
	  section.data(58).logicalSrcIdx = 111;
	  section.data(58).dtTransOffset = 135;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchAdd1_Bias
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawAdd1_Bias
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.PitchAdd1_Bias_b
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_P.YawAdd1_Bias_j
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_heli_2d_ff_lqr_i_nas_B)
    ;%
      section.nData     = 153;
      section.data(153)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_B.SignalGeneratorPitchV
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.AmplitudePitchV
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ChoosePitchRelay
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Add
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.SignalGeneratorPitch
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.AmplitudePitchdeg
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.SliderGain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum_h
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Gain1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.EncoderInput
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.EncoderInput1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.EncoderResolutionPitch
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Bias
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.EncoderResolutionYaw
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.DerivativeFilterPitch
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.DerivativeFilterYaw
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TmpSignalConversionAtXInport1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.X
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 25;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.SignalGeneratorYaw
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 26;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.AmplitudeYawdeg
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 27;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 28;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Gain1_h
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 29;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum1_e
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 30;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TmpSignalConversionAtControlGainKInport1
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 31;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ControlGainK
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 35;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.X_l
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum2_c
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 41;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum1_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 42;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TmpSignalConversionAtControlGainKInport1_b
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 43;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ControlGainK_l
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 47;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Integrator
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 49;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Saturate
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 50;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Memory
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 51;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Switch
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 52;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Pitchu_ol_pLQR
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 53;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 54;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchAMPVoltageLimit
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 55;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchampGainPreCompensation
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 56;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.SignalGeneratorYawV
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 57;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.AmplitudeYawV
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 58;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum1_p
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 59;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ChooseYawRelay
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 60;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Add_m
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 61;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Integrator_b
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 62;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Saturate_c
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 63;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Memory_b
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 64;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Switch_p
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 65;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Yawu_ol_yLQR
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 66;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawAMPVoltageLimit
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 67;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawampGainPreCompensation
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 68;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchIntegralControlGainK15
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 69;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawCrossIntegralControlGainK16
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 70;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.IntegralInputVs
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 71;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.uv
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 72;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchResetTime
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 73;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum_d
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 74;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TrigonometricFunction
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 75;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.FeedforwardPitchGain
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 76;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawIntegralControlGainK26
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 77;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchCrossIntegralControlGainK25
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 78;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.IntegralInputVs_m
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 79;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.uv_i
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 80;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawResetTime
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 81;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum_c
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 82;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Gain_l
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 83;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Gain_lx
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 85;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.theta
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 89;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.psi
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 90;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.theta_dot
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 91;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.psi_dot
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 92;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TmpSignalConversionAtXInport1_i
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 93;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Gain_b
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 97;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ChoosePitchRelay_d
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 101;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Add_i
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 102;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.X_c
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 103;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum2_a
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 107;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum1_g
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 108;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TmpSignalConversionAtControlGainKInport1_be
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 109;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ControlGainK_j
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 113;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.X_n
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 115;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum2_o
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 119;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum1_e4
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 120;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TmpSignalConversionAtControlGainKInport1_be1
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 121;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ControlGainK_b
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 125;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Integrator_k
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 127;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Saturate_e
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 128;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Memory_g
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 129;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Switch_m
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 130;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Pitchu_ol_pLQR_n
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 131;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchAMPVoltageLimit_i
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 132;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ChooseYawRelay_m
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 133;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Add_l
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 134;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Integrator_h
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 135;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Saturate_g
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 136;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Memory_k
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 137;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Switch_g
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 138;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Yawu_ol_yLQR_e
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 139;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawAMPVoltageLimit_h
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 140;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchIntegralControlGainK15_c
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 141;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawCrossIntegralControlGainK16_k
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 142;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.IntegralInputVs_p
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 143;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.uv_l
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 144;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchResetTime_b
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 145;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum_a
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 146;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TrigonometricFunction_f
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 147;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.FeedforwardPitchGain_f
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 148;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawIntegralControlGainK26_i
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 149;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchCrossIntegralControlGainK25_p
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 150;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.IntegralInputVs_i
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 151;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.uv_b
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 152;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawResetTime_a
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 153;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum_k
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 154;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.CrosstorqueactingonPitchfromYawMotor
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 155;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.CrosstorqueactingonYawfromPitchMotor
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 156;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ThrusttorquefromYawMotor
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 157;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.costheta
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 158;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.sinpsi
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 159;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Product
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 160;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.umlcm2
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 161;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawViscousDamping
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 162;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum4
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 163;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.costheta_h
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 164;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.costheta2
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 165;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.m_helil_cm2
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 166;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum3
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 167;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.DividebyInertia
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 168;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TrigonometricFunction_k
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 169;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.mglcm
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 170;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.ThrusttorquefromPitchMotor
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 171;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.sintheta
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 172;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.costheta_f
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 173;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Product_p
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 174;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.mlcm2
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 175;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchViscousDamping
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 176;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Sum2_g
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 177;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchInertia
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 178;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawControlSwitch
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 179;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawLQRI
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 180;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchControlSwitch
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 181;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TrigonometricFunction_m
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 182;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.FeedforwardPitchGain_n
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 183;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchFFLQR
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 184;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchLQRI
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 185;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawControlSwitch_l
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 186;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawLQRI_l
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 187;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchControlSwitch_b
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 188;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.TrigonometricFunction_mn
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 189;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.FeedforwardPitchGain_h
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 190;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.FFGainAdj
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 191;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchFFLQR_b
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 192;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchLQRI_n
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 193;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchAdd1
	  section.data(2).logicalSrcIdx = 154;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare_m
	  section.data(3).logicalSrcIdx = 155;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare_g
	  section.data(4).logicalSrcIdx = 156;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawAdd1
	  section.data(5).logicalSrcIdx = 157;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare_j
	  section.data(6).logicalSrcIdx = 158;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare_n
	  section.data(7).logicalSrcIdx = 159;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.PitchAdd1_c
	  section.data(8).logicalSrcIdx = 160;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare_mw
	  section.data(9).logicalSrcIdx = 161;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare_mq
	  section.data(10).logicalSrcIdx = 162;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.YawAdd1_b
	  section.data(11).logicalSrcIdx = 163;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli_2d_ff_lqr_i_nas_B.Compare_l
	  section.data(12).logicalSrcIdx = 164;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (q_heli_2d_ff_lqr_i_nas_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_DW.Add_DWORK1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.Memory_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.Memory_PreviousInput_e
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.Memory_PreviousInput_h
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.Memory_PreviousInput_o
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% q_heli_2d_ff_lqr_i_nas_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.EncoderInput1_PWORK
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.AnalogOutput_PWORK
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.AnalogOutput1_PWORK
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.psideg_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.psi_dotdegs_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.thetadeg_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.theta_dotdegs_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.Vm_actualV_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_ff_lqr_i_nas_DW.Vm_simV_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2610135989;
  targMap.checksum1 = 39944652;
  targMap.checksum2 = 1915647499;
  targMap.checksum3 = 3412405042;

