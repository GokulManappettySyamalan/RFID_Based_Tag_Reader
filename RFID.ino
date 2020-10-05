#include <SPI.h>
#include <RFID.h>
#define SDA_DIO 9
#define RESET_DIO 8
RFID RC522(SDA_DIO, RESET_DIO);
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  RC522.init();
}
void loop()
{
  if (RC522.isCard())
  {
    RC522.readCardSerial();
    Serial.println("Card detected:");
    for (int i = 0; i < 5; i++)
    {
      Serial.print(RC522.serNum[i], DEC);
      Serial.println();
    }
    delay(1000);
  }
}
