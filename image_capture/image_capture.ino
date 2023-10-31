// Note : The library OptiMouse only provides basic functions to
//        get the X and Y displacements only.
//        Hence, modified the library to get the Image Buffer stored
//        on ADNS-2610
// --------------------------------------------------------------------

#include "ADNS2610.h"

#define SCLK 2                            // Serial clock pin on the Arduino
#define SDIO 3                            // Serial data (I/O) pin on the Arduino

#define FRAME_SIZE  (324)                 // The Pixel buffer is 18px * 18px = 324 Pixels

ADNS2610 Optical1 = ADNS2610(SCLK, SDIO);   // initialize the Optical Sensor object

uint8_t tempReg = 0x00;                     // temporary variable to hold register value
uint8_t Pixel_Data[FRAME_SIZE] = {0};       // Frame Buffer
uint16_t Current_Pixel_Index = 0;
int Temp = 0;                               // Temporary variable to confirm there was only one start of Frame

void setup()
{
  Serial.begin(115200);
  Optical1.begin();                       // Resync (not really necessary?)

  // setting to force awake mode, 
  // so that the LED stays always on, irrespective of motion detected or not
  tempReg = Optical1.read_config_reg();
  Serial.print("Config : ");
  Serial.println(tempReg);

  tempReg |= (1 << 0);    // last bit is force awake mode

  Optical1.write_config_reg(tempReg);

  Serial.println("After");
  tempReg = Optical1.read_config_reg();
  Serial.print("Config : ");
  Serial.println(tempReg);

  delay(3000);
}

void loop()
{

  // write something to Pixel data, to reset the FrameGrabber
  Optical1.write_pixel_data_reg();

  // wait for 5 seconds ~ 5.1 would be nice
  delay(5100);

  // reset the Pixel Index Counter
  Current_Pixel_Index = 0;

  do
  {
    // read the pixel from register
    Pixel_Data[Current_Pixel_Index] = Optical1.read_pixel_data_reg();

    if (0 == Current_Pixel_Index)     // if first pixel
    {
      // check if both bit 7 (Start_Of_Frame) and bit 6 (Data_Valid) are set
      // 11xxxxxx = 128 + some value (between 0 to 63)
      if (Pixel_Data[Current_Pixel_Index] >= 128)
      {
        Current_Pixel_Index++;
      }
    }
    else                              // else any other subsequent pixels
    {
      // check if bit 6 (Data_Valid) is set
      // 01xxxxxx = 64 + some value (between 0 to 63)
      if (Pixel_Data[Current_Pixel_Index] > 64)
      {
        Current_Pixel_Index++;
      }

    }
    
    delayMicroseconds(1);             // little delay before next read

  } while ( Current_Pixel_Index < (uint16_t)FRAME_SIZE );

  // just read an extra byte to check the rollover was done
  // this may or may not have both SOF and Data_valid bits set
  tempReg = Optical1.read_pixel_data_reg();

  Temp = 0;       // reset the temporary counter

  // print the array
  Serial.println("-----------------------------------------------");
  
  Serial.println("Pixel Data");
  for (int i=0; i < (int)FRAME_SIZE; i++)
  {
    Serial.print(Pixel_Data[i]);
    Serial.print(", ");

    if (0 == (i + 1) % 18)
    {
      Serial.println();
    }

    // just checking how many pixels had start of frame bit set, should be 1 only
    if (Pixel_Data[i] >= 128)
    {
      Temp++;
    }
  }

  Serial.print("Temp : ");
  Serial.println(Temp);

  Serial.print("tempReg : ");
  Serial.println(tempReg);

  Serial.println("-----------------------------------------------");

}



