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
    ;% Auto data (q_heli_2d_open_loop_P)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% q_heli_2d_open_loop_P.K_AMP
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_open_loop_P.K_EC_P
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_open_loop_P.K_EC_Y
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_open_loop_P.VMAX_AMP_P
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_open_loop_P.VMAX_AMP_Y
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_open_loop_P.theta_0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput_FinalValue
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput1_FinalValue
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput_InitialValue
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput1_InitialValue
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput_InputFilter
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput1_InputFilter
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput_MaxMissedTicks
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput1_MaxMissedTicks
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput_MaxMissedTicks
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput1_MaxMissedTicks
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput_YieldWhenWaiting
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput1_YieldWhenWaiting
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput_YieldWhenWaiting
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput1_YieldWhenWaiting
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% q_heli_2d_open_loop_P.AnalogOutput_Channels
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput1_Channels
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput_Channels
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_open_loop_P.EncoderInput1_Channels
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput_RangeMode
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput1_RangeMode
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput_VoltRange
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_open_loop_P.AnalogOutput1_VoltRange
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% q_heli_2d_open_loop_P.SignalGeneratorPitchV_Amplitude
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_open_loop_P.SignalGeneratorPitchV_Frequency
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_open_loop_P.AmplitudePitchV_Gain
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_open_loop_P.ConstantPitchV_Value
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_open_loop_P.SignalGeneratorYawV_Amplitude
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_open_loop_P.SignalGeneratorYawV_Frequency
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_open_loop_P.AmplitudeYawV_Gain
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_open_loop_P.ConstantYawV_Value
	  section.data(8).logicalSrcIdx = 35;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_open_loop_P.DerivativeFilterPitch_A
	  section.data(9).logicalSrcIdx = 36;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_open_loop_P.DerivativeFilterPitch_C
	  section.data(10).logicalSrcIdx = 37;
	  section.data(10).dtTransOffset = 10;
	
	  ;% q_heli_2d_open_loop_P.DerivativeFilterYaw_A
	  section.data(11).logicalSrcIdx = 38;
	  section.data(11).dtTransOffset = 12;
	
	  ;% q_heli_2d_open_loop_P.DerivativeFilterYaw_C
	  section.data(12).logicalSrcIdx = 39;
	  section.data(12).dtTransOffset = 14;
	
	  ;% q_heli_2d_open_loop_P.NoDesired_Value
	  section.data(13).logicalSrcIdx = 40;
	  section.data(13).dtTransOffset = 16;
	
	  ;% q_heli_2d_open_loop_P.Gain_Gain
	  section.data(14).logicalSrcIdx = 41;
	  section.data(14).dtTransOffset = 18;
	
	  ;% q_heli_2d_open_loop_P.Gain_Gain_h
	  section.data(15).logicalSrcIdx = 42;
	  section.data(15).dtTransOffset = 19;
	
	  ;% q_heli_2d_open_loop_P.NoSimulation_Value
	  section.data(16).logicalSrcIdx = 43;
	  section.data(16).dtTransOffset = 20;
	
	  ;% q_heli_2d_open_loop_P.Gain_Gain_k
	  section.data(17).logicalSrcIdx = 44;
	  section.data(17).dtTransOffset = 24;
	
	  ;% q_heli_2d_open_loop_P.NoVm_sim_Value
	  section.data(18).logicalSrcIdx = 45;
	  section.data(18).dtTransOffset = 25;
	
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
    ;% Auto data (q_heli_2d_open_loop_B)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% q_heli_2d_open_loop_B.SignalGeneratorPitchV
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_open_loop_B.AmplitudePitchV
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_open_loop_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_open_loop_B.PitchAMPVoltageLimit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_open_loop_B.PitchampGainPreCompensation
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_open_loop_B.SignalGeneratorYawV
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_open_loop_B.AmplitudeYawV
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_open_loop_B.Sum1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_open_loop_B.YawAMPVoltageLimit
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_open_loop_B.YawampGainPreCompensation
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% q_heli_2d_open_loop_B.EncoderInput
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% q_heli_2d_open_loop_B.EncoderInput1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% q_heli_2d_open_loop_B.EncoderResolutionPitch
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% q_heli_2d_open_loop_B.Bias
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% q_heli_2d_open_loop_B.DerivativeFilterPitch
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% q_heli_2d_open_loop_B.DerivativeFilterYaw
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% q_heli_2d_open_loop_B.EncoderResolutionYaw
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% q_heli_2d_open_loop_B.Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% q_heli_2d_open_loop_B.Gain_m
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% q_heli_2d_open_loop_B.Gain_l
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% q_heli_2d_open_loop_B.NoVm_sim
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 27;
	
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
    ;% Auto data (q_heli_2d_open_loop_DW)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% q_heli_2d_open_loop_DW.AnalogOutput_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% q_heli_2d_open_loop_DW.AnalogOutput1_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% q_heli_2d_open_loop_DW.EncoderInput_PWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% q_heli_2d_open_loop_DW.EncoderInput1_PWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% q_heli_2d_open_loop_DW.psideg_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% q_heli_2d_open_loop_DW.psi_dotdegs_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% q_heli_2d_open_loop_DW.thetadeg_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% q_heli_2d_open_loop_DW.theta_dotdegs_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% q_heli_2d_open_loop_DW.Vm_actualV_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% q_heli_2d_open_loop_DW.Vm_simV_PWORK.LoggedData
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


  targMap.checksum0 = 4209688749;
  targMap.checksum1 = 775728109;
  targMap.checksum2 = 1059099552;
  targMap.checksum3 = 2884881347;

