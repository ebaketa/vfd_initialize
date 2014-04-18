// *********************************************************
// Program: 	VFD Initialize (PT6312)
// Version: 	1.0
// Author: 	Elvis Baketa
// Description: 
// *********************************************************

#define DAT 2
#define CLK 3
#define STB 4

#define displayMode 0x01         // 5 digits, 16 segments
#define dataSettings 0x40        // Data write & read mode settings
#define incrementAddress 0x40    // Increment address after data has been written
#define fixedAddress 0x44        // Fixed address
#define addressSettings 0xC0     // Address settings command
#define startAddress 0x00        // start address of ram memory
#define endAddress 0x09          // end address of ram memory
#define displayControl 0x8F      // Display settings ON/OFF

// standard Arduino setup routine
void setup()
{
  // initialize vfd display
  initDisplay();
  // send some data to display
  updateFixedAddres(startAddres, 0b01110111)
}

// standard Arduino loop routine
void loop()
{
}

// routines for sending commands
void sendCommand(unsigned int command, boolean data)
{
  digitalWrite(CLK, HIGH);
  digitalWrite(STB, LOW);
  
  for(int i = 0; i < 8; i++)
  {
    if(bitRead(command, i) & 0x01)
    {
      digitalWrite(DAT, HIGH);
    }else{
      digitalWrite(DAT, LOW);
    }
    digitalWrite(CLK, LOW);
    digitalWrite(CLK, HIGH);
  }
  
  if(data) digitalWrite(STB, HIGH);
}

// routines for sending data
void sendData(unsigned int data, boolean last)
{ 
  for(int i = 0; i < 8; i++)
  {
    if(bitRead(data, i) & 0x01)
    {
      digitalWrite(DAT, HIGH);
    }else{
      digitalWrite(DAT, LOW);
    }
    digitalWrite(CLK, LOW);
    digitalWrite(CLK, HIGH);
  }
  
  if(last) digitalWrite(STB, HIGH);
}

// routines for set ram address
void setAddress(unsigned int address, boolean data)
{
  sendCommand(addressSettings | (address & 0x1F), data);
}

// routine cleaning of display memory
void clearDisplay()
{
  sendCommand(incrementAddress, true);
  setAddress(startAddress, false);
  for(int i = 0; i <= endAddress; i++)
  {
    sendData(0x00, false);
  }
  digitalWrite(STB, HIGH);
}

// routines for initialize display
void initDisplay()
{
  delay (200);
  
  // define communication pins
  pinMode(DAT, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(STB, OUTPUT);
  
  // clear display ram memory
  clearDisplay();
  
  // set display mode to 5 digits, 16 segments
  sendCommand(displayMode, true);
  // set display on and maximum dimming
  sendCommand(displayControl, true);
}

// routine to update fixed memory addresses
void updateFixedAddres(int address, int data)
{
  sendCommand(fixedAddress, true);
  setAddress(address, false);
  sendData(data, true);
}
