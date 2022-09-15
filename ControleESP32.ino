#include <BleGamepad.h>

BleGamepad bleGamepad("Controle DIY", "LLombardi", 100);

// TRIGGER BUTTONS
  #define L1 27
  #define L2 14
  #define R1 26
  #define R2 25
  #define L3 32
  #define R3 33

// LEFT-JOYSTICK
  #define LX 36
  #define LY 39

// RIGHT-JOYSTICK
  #define RX 34
  #define RY 35


// D-PAD
  #define dDown 15
  #define dRight 4
  #define dLeft 16
  #define dUp 17

//D-ACTIONS
  #define A 5 
  #define B 19 
  #define X 18 
  #define Y 21

  #define start 22
  #define select 23


  byte Keys[] = {A, B, X, Y, L1, L2, R1, R2, start, select, L3, R3};
  byte Hats[] = {dDown, dUp, dLeft, dRight};
  byte Buttons[] = {BUTTON_1, BUTTON_2, BUTTON_4, BUTTON_5, BUTTON_7, BUTTON_9, BUTTON_8, BUTTON_10, BUTTON_12, BUTTON_11, BUTTON_14, BUTTON_15};
  bool CurrentButton[16];
  bool previousButton[16];
  byte i;
  
  byte x = 1;
  byte y = 1;
  byte m[3][3]={{8,1,2},{7,0,3},{6,5,4}};


  
  int potOu[] = {-32768, -32621, -32474, -32327, -32180, -32033, -31886, -31739, -31592, -31445, -31298, -31151, -31004, -30857, -30710, -30563, -30416, -30269, -30122, -29975, -29828, -29681, -29534, -29387, -29240, -29093, -28946, -28799, -28652, -28505, -28358, -28211, -28064, -27917, -27770, -27623, -27476, -27329, -27182, -27035, -26888, -26741, -26594, -26447, -26300, -26153, -26006, -25859, -25712, -25565, -25418, -25271, -25124, -24977, -24830, -24683, -24536, -24389, -24242, -24095, -23948, -23801, -23654, -23507, -23360, -23213, -23066, -22919, -22772, -22625, -22478, -22331, -22184, -22037, -21890, -21743, -21596, -21449, -21302, -21155, -21008, -20861, -20714, -20567, -20420, -20273, -20126, -19979, -19832, -19685, -19538, -19391, -19244, -19097, -18950, -18803, -18656, -18509, -18362, -18215, -18068, -17921, -17774, -17627, -17480, -17333, -17186, -17039, -16892, -16745, -16598, -16451, -16304, -16157, -16010, -15863, -15716, -15569, -15422, -15275, -15128, -14981, -14834, -14687, -14540, -14393, -14246, -14099, -13952, -13805, -13658, -13511, -13364, -13217, -13070, -12923, -12776, -12629, -12482, -12335, -12188, -12041, -11894, -11747, -11600, -11453, -11306, -11159, -11012, -10865, -10718, -10571, -10424, -10277, -10130, -9983, -9836, -9689, -9542, -9395, -9248, -9101, -8954, -8807, -8660, -8513, -8366, -8219, -8072, -7925, -7778, -7631, -7484, -7337, -7190, -7043, -6896, -6749, -6602, -6455, -6308, -6161, -6014, -5867, -5720, -5573, -5426, -5279, -5132, -4985, -4838, -4691, -4544, -4397, -4250, -4103, -3956, -3809, -3662, -3515, -3368, -3221, -3074, -2927, -2780, -2633, -2486, -2339, -2192, -2045, -1898, -1751, -1604, -1457, -1310, -1163, -1016, -869, -722, -575, -428, -281, 0, 0, 0, 0, 0, 342, 456, 570, 684, 798, 912, 1026, 1140, 1254, 1368, 1482, 1596, 1710, 1824, 1938, 2052, 2166, 2280, 2394, 2508, 2622, 2736, 2850, 2964, 3078, 3192, 3306, 3420, 3534, 3648, 3762, 3876, 3990, 4104, 4218, 4332, 4446, 4560, 4674, 4788, 4902, 5016, 5130, 5244, 5358, 5472, 5586, 5700, 5814, 5928, 6042, 6156, 6270, 6384, 6498, 6612, 6726, 6840, 6954, 7068, 7182, 7296, 7410, 7524, 7638, 7752, 7866, 7980, 8094, 8208, 8322, 8436, 8550, 8664, 8778, 8892, 9006, 9120, 9234, 9348, 9462, 9576, 9690, 9804, 9918, 10032, 10146, 10260, 10374, 10488, 10602, 10716, 10830, 10944, 11058, 11172, 11286, 11400, 11514, 11628, 11742, 11856, 11970, 12084, 12198, 12312, 12426, 12540, 12654, 12768, 12882, 12996, 13110, 13224, 13338, 13452, 13566, 13680, 13794, 13908, 14022, 14136, 14250, 14364, 14478, 14592, 14706, 14820, 14934, 15048, 15162, 15276, 15390, 15504, 15618, 15732, 15846, 15960, 16074, 16188, 16302, 16416, 16530, 16644, 16758, 16872, 16986, 17100, 17214, 17328, 17442, 17556, 17670, 17784, 17898, 18012, 18126, 18240, 18354, 18468, 18582, 18696, 18810, 18924, 19038, 19152, 19266, 19380, 19494, 19608, 19722, 19836, 19950, 20064, 20178, 20292, 20406, 20520, 20634, 20748, 20862, 20976, 21090, 21204, 21318, 21432, 21546, 21660, 21774, 21888, 22002, 22116, 22230, 22344, 22458, 22572, 22686, 22800, 22914, 23028, 23142, 23256, 23370, 23484, 23598, 23712, 23826, 23940, 24054, 24168, 24282, 24396, 24510, 24624, 24738, 24852, 24966, 25080, 25194, 25308, 25422, 25536, 25650, 25764, 25878, 25992, 26106, 26220, 26334, 26448, 26562, 26676, 26790, 26904, 27018, 27132, 27246, 27360, 27474, 27588, 27702, 27816, 27930, 28044, 28158, 28272, 28386, 28500, 28614, 28728, 28842, 28956, 29070, 29184, 29298, 29412, 29526, 29640, 29754, 29868, 29982, 30096, 30210, 30324, 30438, 30552, 30666, 30780, 30894, 31008, 31122, 31236, 31350, 31464, 31578, 31692, 31806, 31920, 32034, 32148, 32262, 32376, 32490, 32604, 32718};

  int period = 1000;
  unsigned long time_now = 0;

  const byte numberOfPotSamples = 5;     // Number of pot samples to take (to smooth the values)
  const byte delayBetweenSamples = 2;    // Delay in milliseconds between pot samples
  const byte delayBetweenHIDReports = 5; // Additional delay in milliseconds between HID reports
  const byte debounceDelay = 10;         // Delay in milliseconds between button press





void setup(){
  
analogReadResolution(9);

BleGamepadConfiguration bleGamepadConfig;

bleGamepadConfig.setControllerType(CONTROLLER_TYPE_GAMEPAD);
bleGamepadConfig.setHidReportId(01);
bleGamepadConfig.setButtonCount(12);
bleGamepadConfig.setHatSwitchCount(1);
bleGamepadConfig.setAutoReport(true);
bleGamepadConfig.setIncludeStart(false);
bleGamepadConfig.setIncludeSelect(false);
bleGamepadConfig.setIncludeMenu(false);
bleGamepadConfig.setIncludeHome(false);
bleGamepadConfig.setIncludeBack(false);
bleGamepadConfig.setIncludeVolumeInc(false);
bleGamepadConfig.setIncludeVolumeDec(false);
bleGamepadConfig.setIncludeVolumeMute(false);
bleGamepadConfig.setIncludeXAxis(true);
bleGamepadConfig.setIncludeYAxis(true);
bleGamepadConfig.setIncludeZAxis(true);
bleGamepadConfig.setIncludeRxAxis(false);
bleGamepadConfig.setIncludeRyAxis(false);
bleGamepadConfig.setIncludeRzAxis(true);
bleGamepadConfig.setIncludeSlider1(false);
bleGamepadConfig.setIncludeSlider2(false);
bleGamepadConfig.setIncludeRudder(false);
bleGamepadConfig.setIncludeThrottle(false);
bleGamepadConfig.setIncludeAccelerator(false);
bleGamepadConfig.setIncludeBrake(false);
bleGamepadConfig.setIncludeSteering(false);
  //bleGamepadConfig.setVid();
  //bleGamepadConfig.setPid();

void analogSetWidth();



  Serial.begin(115200);

  for(i = 0; i < 16; i++){
    previousButton[i] = HIGH;
  }

  for(i = 0; i < 12; i++){
    pinMode(Keys[i], INPUT_PULLUP);;
  }
  
  pinMode(dDown, INPUT_PULLUP);
  pinMode(dRight, INPUT_PULLUP);
  pinMode(dLeft, INPUT_PULLUP);
  pinMode(dUp, INPUT_PULLUP);
  
  bleGamepad.begin(&bleGamepadConfig);
  
  Serial.println("Starting BLE work!");

}


void loop(){
/////////////////////////////////Analógicos///////////////////////////////////////////

   int potValues[numberOfPotSamples];
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValues[i] = analogRead(LX);
      delay(delayBetweenSamples);
    }
    int potValue = 0;
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValue += potValues[i];
      
    }
    potValue = potValue / numberOfPotSamples;
    int adjustedValue = potOu[potValue];

 

    int potValues2[numberOfPotSamples];
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValues2[i] = analogRead(LY);
      delay(delayBetweenSamples);
    }
    int potValue2 = 0;
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValue2 += potValues2[i];
      
    }
    potValue2 = potValue2 / numberOfPotSamples;
    int adjustedValue2 = potOu[potValue2];


    int potValues3[numberOfPotSamples];
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValues3[i] = analogRead(RX);
      delay(delayBetweenSamples);
    }
    int potValue3 = 0;
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValue3 += potValues3[i];
      
    }
    potValue3 = potValue3 / numberOfPotSamples;
    int adjustedValue3 = potOu[potValue3];


    int potValues4[numberOfPotSamples];
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValues4[i] = analogRead(RY);
      delay(delayBetweenSamples);
    }
    int potValue4 = 0;
    for (int i = 0 ; i < numberOfPotSamples ; i++) {
      potValue4 += potValues4[i];
      
    }
    potValue4 = potValue4 / numberOfPotSamples;
    int adjustedValue4 = potOu[potValue4];

////////////////////////////////////////Hats//////////////////////////////////////////////////////////////////// 

    CurrentButton[12] = digitalRead(Hats[0]);
    
    if (CurrentButton[12] != previousButton[12]) {
      if (CurrentButton[12] == LOW){
        y++;
      }
      else{
        y--;
      }
    }
    previousButton[12] = CurrentButton[12];




        CurrentButton[13] = digitalRead(Hats[1]);
    
    if (CurrentButton[13] != previousButton[13]) {
      if (CurrentButton[13] == LOW){
        y--;
      }
      else{
        y++;
      }
    }
    previousButton[13] = CurrentButton[13];


    CurrentButton[14] = digitalRead(Hats[2]);
    
    if (CurrentButton[14] != previousButton[14]) {
      if (CurrentButton[14] == LOW){
        x--;
      }
      else{
        x++;
      }
    }
    previousButton[14] = CurrentButton[14];


    

    CurrentButton[15] = digitalRead(Hats[3]);
    
    if (CurrentButton[15] != previousButton[15]) {
      if (CurrentButton[15] == LOW){
        x++;
      }
      else{
        x--;
      }
    }
    previousButton[15] = CurrentButton[15];


// envia a posição dos analógicos e setas direcionais 
   bleGamepad.setAxes(adjustedValue, adjustedValue2, adjustedValue3, adjustedValue4);
   bleGamepad.setHats(m[y][x]); //setas direcionais (Hats) unificadas em matriz
   delay(delayBetweenHIDReports);
  


//Scaneia os botões e alterações de estado

  for(i = 0; i < 12; i++){
    CurrentButton[i] = digitalRead(Keys[i]);

    if (CurrentButton[i] != previousButton[i]) {
      if (CurrentButton[i] == LOW){
        bleGamepad.press(Buttons[i]);
      }
      else{
        bleGamepad.release(Buttons[i]);
      }
    previousButton[i] = CurrentButton[i];
  }
  }

}