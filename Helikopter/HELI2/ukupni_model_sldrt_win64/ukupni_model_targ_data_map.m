  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
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
    ;% Auto data (ukupni_model_P)
    ;%
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% ukupni_model_P.B_p
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ukupni_model_P.B_y
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ukupni_model_P.J_eq_y
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ukupni_model_P.J_p
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ukupni_model_P.K_EC_P
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ukupni_model_P.K_EC_Y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ukupni_model_P.K_pp
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ukupni_model_P.K_py
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ukupni_model_P.K_yp
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ukupni_model_P.K_yy
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ukupni_model_P.Tr_p
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ukupni_model_P.Tr_y
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ukupni_model_P.g
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ukupni_model_P.l_cm
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ukupni_model_P.m_heli
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ukupni_model_P.max_u
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ukupni_model_P.theta_0
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% ukupni_model_P.AnalogOutput_FinalValue
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% ukupni_model_P.AnalogOutput1_FinalValue
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% ukupni_model_P.AnalogOutput_InitialValue
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% ukupni_model_P.AnalogOutput1_InitialValue
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% ukupni_model_P.EncoderInput_InputFilter
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% ukupni_model_P.EncoderInput1_InputFilter
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% ukupni_model_P.EncoderInput_MaxMissedTicks
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% ukupni_model_P.EncoderInput1_MaxMissedTicks
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% ukupni_model_P.AnalogOutput_MaxMissedTicks
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% ukupni_model_P.AnalogOutput1_MaxMissedTicks
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% ukupni_model_P.EncoderInput_YieldWhenWaiting
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% ukupni_model_P.EncoderInput1_YieldWhenWaiting
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% ukupni_model_P.AnalogOutput_YieldWhenWaiting
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% ukupni_model_P.AnalogOutput1_YieldWhenWaiting
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% ukupni_model_P.ConstantPitchdeg_gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% ukupni_model_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ukupni_model_P.EncoderInput1_Channels
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ukupni_model_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ukupni_model_P.AnalogOutput1_Channels
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ukupni_model_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ukupni_model_P.AnalogOutput1_RangeMode
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ukupni_model_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ukupni_model_P.AnalogOutput1_VoltRange
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% ukupni_model_P.SignalGeneratorPitch_Amplitude
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ukupni_model_P.SignalGeneratorPitch_Frequency
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ukupni_model_P.AmplitudePitchdeg_Gain
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ukupni_model_P.Constant_Value
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ukupni_model_P.Gain1_Gain
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ukupni_model_P.DerivativeFilterPitch_A
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ukupni_model_P.DerivativeFilterPitch_C
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 7;
	
	  ;% ukupni_model_P.DerivativeFilterYaw_A
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 9;
	
	  ;% ukupni_model_P.DerivativeFilterYaw_C
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 11;
	
	  ;% ukupni_model_P.X_Gain
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 13;
	
	  ;% ukupni_model_P.SignalGeneratorYaw_Amplitude
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 29;
	
	  ;% ukupni_model_P.SignalGeneratorYaw_Frequency
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 30;
	
	  ;% ukupni_model_P.AmplitudeYawdeg_Gain
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 31;
	
	  ;% ukupni_model_P.ConstantYawdeg_Value
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 32;
	
	  ;% ukupni_model_P.Gain1_Gain_c
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 33;
	
	  ;% ukupni_model_P.ControlGainK_Gain
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 34;
	
	  ;% ukupni_model_P.Integrator_IC
	  section.data(17).logicalSrcIdx = 56;
	  section.data(17).dtTransOffset = 42;
	
	  ;% ukupni_model_P.Gain_Gain
	  section.data(18).logicalSrcIdx = 57;
	  section.data(18).dtTransOffset = 43;
	
	  ;% ukupni_model_P.Integrator_IC_c
	  section.data(19).logicalSrcIdx = 58;
	  section.data(19).dtTransOffset = 44;
	
	  ;% ukupni_model_P.Gain1_Gain_d
	  section.data(20).logicalSrcIdx = 59;
	  section.data(20).dtTransOffset = 45;
	
	  ;% ukupni_model_P.PitchIntegralControlGainK15_Gain
	  section.data(21).logicalSrcIdx = 60;
	  section.data(21).dtTransOffset = 46;
	
	  ;% ukupni_model_P.YawCrossIntegralControlGainK16_Gain
	  section.data(22).logicalSrcIdx = 61;
	  section.data(22).dtTransOffset = 47;
	
	  ;% ukupni_model_P.YawIntegralControlGainK26_Gain
	  section.data(23).logicalSrcIdx = 62;
	  section.data(23).dtTransOffset = 48;
	
	  ;% ukupni_model_P.PitchCrossIntegralControlGainK25_Gain
	  section.data(24).logicalSrcIdx = 63;
	  section.data(24).dtTransOffset = 49;
	
	  ;% ukupni_model_P.Gain_Gain_i
	  section.data(25).logicalSrcIdx = 64;
	  section.data(25).dtTransOffset = 50;
	
	  ;% ukupni_model_P.Gain_Gain_l
	  section.data(26).logicalSrcIdx = 65;
	  section.data(26).dtTransOffset = 51;
	
	  ;% ukupni_model_P.theta_UpperSat
	  section.data(27).logicalSrcIdx = 66;
	  section.data(27).dtTransOffset = 52;
	
	  ;% ukupni_model_P.theta_LowerSat
	  section.data(28).logicalSrcIdx = 67;
	  section.data(28).dtTransOffset = 53;
	
	  ;% ukupni_model_P.psi_IC
	  section.data(29).logicalSrcIdx = 68;
	  section.data(29).dtTransOffset = 54;
	
	  ;% ukupni_model_P.theta_dot_IC
	  section.data(30).logicalSrcIdx = 69;
	  section.data(30).dtTransOffset = 55;
	
	  ;% ukupni_model_P.psi_dot_IC
	  section.data(31).logicalSrcIdx = 70;
	  section.data(31).dtTransOffset = 56;
	
	  ;% ukupni_model_P.Gain_Gain_b
	  section.data(32).logicalSrcIdx = 71;
	  section.data(32).dtTransOffset = 57;
	
	  ;% ukupni_model_P.X_Gain_o
	  section.data(33).logicalSrcIdx = 72;
	  section.data(33).dtTransOffset = 58;
	
	  ;% ukupni_model_P.ControlGainK_Gain_k
	  section.data(34).logicalSrcIdx = 73;
	  section.data(34).dtTransOffset = 74;
	
	  ;% ukupni_model_P.Integrator_IC_o
	  section.data(35).logicalSrcIdx = 74;
	  section.data(35).dtTransOffset = 82;
	
	  ;% ukupni_model_P.Integrator_IC_j
	  section.data(36).logicalSrcIdx = 75;
	  section.data(36).dtTransOffset = 83;
	
	  ;% ukupni_model_P.PitchIntegralControlGainK15_Gain_b
	  section.data(37).logicalSrcIdx = 76;
	  section.data(37).dtTransOffset = 84;
	
	  ;% ukupni_model_P.YawCrossIntegralControlGainK16_Gain_o
	  section.data(38).logicalSrcIdx = 77;
	  section.data(38).dtTransOffset = 85;
	
	  ;% ukupni_model_P.YawIntegralControlGainK26_Gain_g
	  section.data(39).logicalSrcIdx = 78;
	  section.data(39).dtTransOffset = 86;
	
	  ;% ukupni_model_P.PitchCrossIntegralControlGainK25_Gain_p
	  section.data(40).logicalSrcIdx = 79;
	  section.data(40).dtTransOffset = 87;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (ukupni_model_B)
    ;%
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% ukupni_model_B.SliderGain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ukupni_model_B.EncoderResolutionPitch
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ukupni_model_B.Bias
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ukupni_model_B.EncoderResolutionYaw
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ukupni_model_B.Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ukupni_model_B.Gain1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ukupni_model_B.Sum
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ukupni_model_B.Sum_f
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ukupni_model_B.Gain_a
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ukupni_model_B.Gain_d
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% ukupni_model_B.theta_dot
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% ukupni_model_B.psi_dot
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% ukupni_model_B.Gain_k
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% ukupni_model_B.PitchAMPVoltageLimit
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 20;
	
	  ;% ukupni_model_B.YawAMPVoltageLimit
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% ukupni_model_B.Sum_o
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% ukupni_model_B.Sum_j
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 23;
	
	  ;% ukupni_model_B.DividebyInertia
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 24;
	
	  ;% ukupni_model_B.PitchInertia
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 1;
    sectIdxOffset = 1;
    
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
    ;% Auto data (ukupni_model_DW)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% ukupni_model_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ukupni_model_DW.EncoderInput1_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ukupni_model_DW.AnalogOutput_PWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ukupni_model_DW.AnalogOutput1_PWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ukupni_model_DW.psideg_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ukupni_model_DW.psi_dotdegs_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ukupni_model_DW.thetadeg_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ukupni_model_DW.theta_dotdegs_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ukupni_model_DW.Vm_actualV_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ukupni_model_DW.Vm_simV_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
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


  targMap.checksum0 = 907498927;
  targMap.checksum1 = 2531890356;
  targMap.checksum2 = 1391664844;
  targMap.checksum3 = 826193499;

