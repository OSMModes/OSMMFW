// Interrupts.ino
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
// 57 68 61 74 20 77 65 20 68 61 76 65 20 64 6f 6e 65 20 66 6f 72 20 6f 75 72 73 65 6c 76 65 73 20 61 6c 6f 6e 65 20 64 69 65 73 20 77 69 74 68 20 75 73 3b 20 77 68 61 74 20 77 65 20 68 61 76 65 20 64 6f 6e 65 20 66 6f 72 20 6f 74 68 65 72 73 20 61 6e 64 20 74 68 65 20 77 6f 72 6c 64 20 72 65 6d 61 69 6e 73 20 61 6e 64 20 69 73 20 69 6d 6d 6f 72 74 61 6c 2e 0a


	volatile uint8_t PushCounter[]= 
	{
		0, 4, 8, 12, 16, 20,24	,28	,32	,36	,40	,44	,48	,52
		,56	,60	,64	,68	,72	,76	,80	,84	,88	,92	,96	,100	,104	,108	,112	,116	,120	,124
		,128	,132	,136	,140	,144	,148	,151	,156	,160	,164	,168	,172	,176
		,180	,184	,188	,192	,196	,200	,204	,208	,212	,216	,220	,224	,228
		,232	,236	,240	, 244	, 248	,252	, 255
	};




	void pushInterrupt()
	{
		;
	}





ISR(TIMER2_COMPA_vect) // TIMER2 INTERRUPT @ 61HZ / 16.40ms
{ // TIMER2 ISR


if (AUTOCHANGE == 1)
{// if AUTOCHANGE
	if (Mode != 0)
	{
	BPM_Counter++;	
	} 
	
	
	if (BPM_Counter > BPM_Factor)
	{// if BPM_Counter
		
		//Serial.print(BPM_Counter);
		//Serial.print("  ");  Serial.print(BPM_Factor); Serial.println(F("  CHANGE"));
		BPM_Counter = 0;
			MaxUserModes = UserCmodes[CurrentUserBundle][0];
			CurrentUserMode++;
			if (CurrentUserMode > MaxUserModes) { CurrentUserMode = 1;}
			if (MaxUserModes==1)
			{
				Mode = 0;
			}
			else
			{
				Mode = (UserCmodes[CurrentUserBundle][CurrentUserMode]);
			}
			GLOBALCHANGE = 0;
			Click = 0;
			ToBorNotToB = 0;
			STATE = 0;
			VARIATION = 0;// Reset Change
	}// fi BPM_Counter
	
}// fi AUTOCHANGE



if (digitalRead (BUTTON) == LOW) // if we are pushing pushing
		{ // if digitalRead
		Int0count++;
		Pushed = 1;


		//////////////////////////////////////////////////////////////////////////////////////////////
		///////          STATE 1 == MODES    /////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////

								
				
				if (STATE == 1) // If STATE = 1 / Modes State
				{// if STATE == 1
                     
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					/////////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH /////// 
					if ( (Int0count > 3) && (Int0count < 32 ) ) // CLICK 0.05 sec to 0.5 sec 
					{ // if Click
					//PrintMaster++;
					//if (PrintMaster > 3) {AsteriscMaster++; PrintMaster = 0;}
						//if (Int0count == 4) { Serial.print(F("|")); PrintMaster=0; AsteriscMaster=1;}
						//if (Int0count == PushCounter[AsteriscMaster])
						//{ Serial.print(F("*"));}
					ClearToGo=0; 									
					Click = 1;
					COLORCHANGE_FLAG = 0;
					ToBorNotToB = 1;
					}// fi Click
                    /////////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH  //////  ATZILUTH ///////
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					
					
					
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					///////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////////////
					if ( (Int0count > 31 ) && (Int0count < 92 ) ) // OFF 0.5 sec to 1.5 sec
					{ // if OFF_MODE
						//PrintMaster++;
						//if (PrintMaster > 3) {AsteriscMaster++; PrintMaster=0;}
						//if (Int0count == 32) 
						//{
							//#if defined(VISUAL) 
								//Serial.print(F("|"));
							//#endif 
							//PrintMaster=0; AsteriscMaster=8;
						//}
						//if (Int0count == PushCounter[AsteriscMaster])
						//{
							//#if defined(VISUAL)
								//Serial.print(F("*"));
							//#endif
					    //}
						
					//PrintMaster = 0;
					
					ClearToGo = 0;
					AnalogBlank(); // All Off
					Click = 0;
					ToBorNotToB = 0;
					Armed = 0;
					ONNS = 0; // HeartBeat flag
					COLORCHANGE_FLAG = 0;
					WhatDmode = Mode;// save the current mode
					OFF_MODE = 1;
					}// fi OFF_MODE
                    ///////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////   BERIYAH  /////////////
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					
					

				
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					///////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////////////  	
					if ( (Int0count > 91 ) && (Int0count < 275 ) ) // VARIATION COLOR SET 1.5 sec to 4.5 sec
					{ // if COLORCHANGE_FLAG
						OFF_MODE = 0;
						if  (Int0count == 92) {BlinkyCount = 0;}// Reset Count
						
						if (Int0count == 92)
						{
							if ((Zflipped) && (!ONEMODE))
							{
							  ClearToGo=1; // reset Bundle
							  CurrentUserBundle=0;
							  Serial.println(F("Clear To Go"));	
							}	
						}
						
						//////////////////////////////////////////////////////////////////////////////////	
						if  (Mode == 0) /// OFF MODE /////// BUNDLES CHANGES /////////////////////////////
						{// if Mode 0
							ToBorNotToB = 1;
							if  ( (Zflipped) && (Int0count > 273))
							{// if Zflipped
								Int0count = 92;// Reset
								CurrentUserBundle++;
								if (CurrentUserBundle>4){CurrentUserBundle=0;}
							}// fi Zflipped
							
							
							if  ( (!Zflipped) && (Int0count > 273))
							{// if !Zflipped
								Int0count = 92;// Reset
								if ((!Zflipped) && (CurrentOffCounter == 1 || CurrentOffCounter == 4))
								{Serial.println(F("************************"));}// for timing
									
								CurrentOffCounter++;
								if (CurrentOffCounter>4){CurrentOffCounter=0;}
							}// fi !Zflipped
							Int0count++;
						}// fi Mode 0 /// OFF MODE /////// BUNDLES CHANGES /////////////////////////////
						////////////////////////////////////////////////////////////////////////////////
						
						
						////////////////////////////////////////////////////////////////////////////////
						////// ELSE, IF WHILE MODE PLAY /////  COLOD MODE CHANGE ///////////////////////
						else
						
						{// ELSE
						//PrintMaster++;
						//if (PrintMaster > 3) {AsteriscMaster++; PrintMaster=0; }
						//if (Int0count == 92) { Serial.print(F("|")); PrintMaster=0; AsteriscMaster=23;}
						//if (Int0count == PushCounter[AsteriscMaster])
						//{
							//#if defined(VISUAL) 
								//Serial.print(F("*"));
							//#endif
						//}
							if (BlinkyCount > 6) {BlinkyCount = 0;}
							BlinkyCount++;
							if (BlinkyCount == 1) {Blinky_ForInterrupt(1,1,0,200);}// was {Blinky_ForInterrupt(1,1,0,200);}
							if (BlinkyCount == 3) {Blinky_ForInterrupt(0,0,0,50);} // was {Blinky_ForInterrupt(0,0,0,50);}
							COLORCHANGE_FLAG = 1;
							//Serial.println(F(" > COLOR CHANGE INTERRUPT"));// DEBUGGGGGGGGGGGGGGGGGGGGGGGGG
							if (Int0count == 274)
							{
								
								BlinkyCount=5;
								while (BlinkyCount > 0)
								{
								Blinky_ForInterrupt(0,0,0,3200); // ADDED BLANK BEFORE SHADE 0
								BlinkyCount--;
								}
								/// PROBABLY DISABLE COLORCHANGE_FLAG
								COLORCHANGE_FLAG = 0; // 
							}
						}// ESLE
						////// ELSE, IF WHILE MODE PLAY /////  COLOD MODE CHANGE ///////////////////////
						////////////////////////////////////////////////////////////////////////////////
						

					}// if COLORCHANGE_FLAG
					///////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////  YETZIRAH   ////////////
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					
					
					
					
					
					
					
                    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					////////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ///////////////  
					if ( (Int0count > 274 ) && (Int0count < 609 ) ) // ONE MODE TOGGLE 
					{ // if  // ONE MODE TOGGLE
						
						if  (Int0count == 275) 
						{// if 275
							if (ONEMODE)
							{// if ONEMODE
								ONEMODE = 0;	
							}// fi ONEMODE
							else
							{// if ONEMODE not
							 ONEMODE = 1;
							}// fi ONEMODE not
							ONEMODE_FLAG = 1;
							BlinkyCount = 0;	
						}// fi 275	
						
						
						if (BlinkyCount > 6) {BlinkyCount = 0;}
						BlinkyCount++;
						if (BlinkyCount == 1) {Blinky_ForInterrupt(0,0,1,250);}  // was {Blinky_ForInterrupt(1,1,1,5);}
						if (BlinkyCount == 3) {Blinky_ForInterrupt(0,0,0,50);} // was {Blinky_ForInterrupt(0,0,0,50);} 
							
							if (Int0count == 607)
							{// if 607
								/// PROBABLY DISSABLE 
								BlinkyCount=5;
								while (BlinkyCount > 0)
								{
									Blinky_ForInterrupt(0,0,0,3200); // ADDED BLANK BEFORE SHADE 0
									BlinkyCount--;
								}
								ONEMODE_FLAG = 0;
							}// fi 607
	
						COLORCHANGE_FLAG = 0; // UNCOMMENT THIS
						Int0count++;// BYPASS ACCELERATION
						
					}// fi // ONE MODE TOGGLE
                    ////////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ////  ASIYAH  ///////////////
                    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



                    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					////////  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  ////////////// 
					if ( (Int0count > 608) && (Int0count < 801) ) // FACTORY RESET 10 SEC TO 20 SEC
					{ // if MODERESET_FLAG
					if (Int0count == 609)  
					{
						ONEMODE = 0;
						eeCheck();EEPROM.write(1,0);eeCheck();	// toggle off ONEMODE
						BlinkyCount = 0;
					}// Reset Count
					
					if (BlinkyCount > 6)   {BlinkyCount = 0;}
					BlinkyCount++;
					if (BlinkyCount == 2) {Blinky_ForInterrupt(1,0,0,500);} 
					if (BlinkyCount == 4) {Blinky_ForInterrupt(0,0,1,500);}
					MODERESET_FLAG = 1;	
					}// fi Click

					//////////////////////////////////////////////////////////////

					if (Int0count > 800) // +20 seconds , OH, CRAP I SCREWED UP... GO BACK TO BLANK
					{ // if Click
						#if defined(VISUAL)
							Serial.println();
							Serial.println(F("> OH, CRAP I SCREWED UP... NEVER MIND!"));
						#endif
					BlinkyCount = 0;// Reset Count
					AnalogBlank(); // All Off
					MODERESET_FLAG = 0;
					Click = 0;
					ToBorNotToB = 0;
					Mode = 0;
					}// fi MODERESET_FLAG
					////////  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  ///  MALKUTH  //////////////
					/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					

					//////////////////////////////////////////////////////////////
					//////////////////////////////////////////////////////////////
					//////////////////////////////////////////////////////////////
					
					
 
				}// fi STATE == 1 Modes
 
 
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
				//////////////////////////////////////////////////////////////////////////////////////////////
				///////          STATE 2 == COLOR VARIATION    ///////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 
				if (STATE == 2) /// Color Change
				{// if STATE 2 / Color Change
					//////////////////////////////////////////////////////////////
					//////////////////////////////////////////////////////////////
					

						//////////////////////////////////////////////////////////////
						if ( (Int0count > 3) && (Int0count < 32 ) ) // CLICK 0.05 sec to 0.5 sec
						{ // if Click
						Click = 1;
						shadeFlag = 0;
						
						
							//PrintMaster++;
							//if (PrintMaster > 3) {AsteriscMaster++; PrintMaster = 0;}
																
							if (Int0count == 31)
							{
								Blinky_ForInterrupt(0,0,0,2800); // ADDED BLANK BEFORE SHADE 0
								Int0count = 32;
							}														
																
							//if (Int0count == 4) 
							//{
								//PrintMaster=0; AsteriscMaster=1;
							//}
							//if ((VirtualPreview) && (Int0count == PushCounter[AsteriscMaster]))
							//{ 
								//#if defined(VISUAL)
								//Serial.print(F("*"));
							    //#endif
							//}
						
						//Int0count++;
						ToBorNotToB = 1;
						}// fi Click

						//////////////////////////////////////////////////////////////
											
						if ( (Int0count > 31 ) && (Int0count < 151 ) ) // OFF 0.5 sec to 1.5 sec
						{ // if Click
						
							if (!VirtualPreview)
							{
								if (Int0count == 32) {ONCE_SETUP_COLOR = 1; }
								Int0count++;
								shadeFlag = 1;
								CSHADE=0;
								ONNS = 0; // HeartBeat flag
								SaveDaColor = 1;
								//Blinky_ForInterrupt(0,0,0,200); // ADDED BLANK BEFORE SHADE 0
								//Int0count = 33;
							}
							else
							{// if VirtualPreview
								ToBorNotToB = 0;
								
								//PrintMaster++;
								//if (PrintMaster > 3) {AsteriscMaster++; PrintMaster=0;}
								if (Int0count == 32) 
								{
									//#if defined(VISUAL)
										 //Serial.print(F("|"));
									//#endif
									  //PrintMaster=0; AsteriscMaster=8;
									  //Blinky_ForInterrupt(0,0,0,200); // ADDED BLANK BEFORE SHADE 0
									  //Int0count = 33;
							     }
								//if ((VirtualPreview) && (Int0count == PushCounter[AsteriscMaster]))
								//{ 
									//#if defined(VISUAL)
									//Serial.print(F("*"));
									//#endif
								//}
									
								SaveDmode = 1;	
								
								
							}// fi VirtualPreview
							
						Click = 0;
						}// fi Click

//////////////////////////////////
						if ( (Int0count > 150 ) && (Int0count < 270 ) ) // VARIATION COLOR SET 1.5 sec to 2 sec
						{ // if Click
							
							if (!VirtualPreview)
							{// if !VirtualPreview
								if (Int0count == 151) {ONCE_SETUP_COLOR = 1; }
								CSHADE=1;
								Int0count++;
								SaveDaColor = 1;
							}// fi !VirtualPreview
							else
							{// else if VirtualPreview
								
								PrintMaster++;
								if (PrintMaster > 3) {AsteriscMaster++; PrintMaster=0;}
								if (Int0count == 151) 
								{
									 #if defined(VISUAL)
									 Serial.print(F("|"));
									 #endif 
									 PrintMaster=0; AsteriscMaster=38;
							    }
								if ((VirtualPreview) && (Int0count == PushCounter[AsteriscMaster]))
								{
									#if defined(VISUAL) 
									Serial.print(F("*"));
									#endif
								}

								if ((VirtualPreview) && (Int0count == 269) )
								{
									#if defined(VISUAL)
									Serial.print(F("**|"));
									#endif
								}
								
								DeleteColor = 1;									
								SaveDmode = 0;	
								
							}// esle if VirtualPreview
							
							Click = 0;
						}// fi Click

//////////////////////////////////	
					
						if ( (Int0count > 269 ) && (Int0count < 389 ) ) // OFF 2 sec to 2.5 sec
						{ // if Click
							
							if (!VirtualPreview)
							{
								if (Int0count == 270) {ONCE_SETUP_COLOR = 1;}
								CSHADE=2;
								Int0count++;
								SaveDaColor = 1;
							}
							else
							{
								Int0count = 270;
								goto  OutOfHereNow;
							}
							
							Click = 0;
						}// fi Click	
						
//////////////////////////////////
					
						if ( (Int0count > 388 ) && (Int0count < 509 ) ) // OFF 2.5 sec to 4.5 sec
						{ // if Click
							
							if (!VirtualPreview)
							{
								if (Int0count == 389) {ONCE_SETUP_COLOR = 1; }
								CSHADE=3;
								Int0count++;
								SaveDaColor = 1;
							}
							else
							{
								SaveDmode = 1;
							}
							
							Click = 0;
						}// fi Click


//////////////////////////////////											
						if ( (Int0count > 508 )) // OFF 0.5 sec to 1.5 sec
						{ // if Click
						Int0count = 4;
						CSHADE=0;
						Click = 0;
						}// fi Click



						
						
					//////////////////////////////////////////////////////////////
					//////////////////////////////////////////////////////////////
					
				}// if STATE 2 / Color Change
 
 
 
		}// fi digitalRead

		//if (STATE == 3)
		//{
			//Int0count = 0;
		//}
		//////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////
		else
		//////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////
		{ // else
		Int0count = 0;
		}// else
 
 OutOfHereNow:
 ;
 
 
}// 2EMIT ISR



