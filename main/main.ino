//RFID
#include <SPI.h>
#include <RFID.h>
#define SDA_DIO 9
#define RESET_DIO 8

RFID RC522(SDA_DIO, RESET_DIO);
int mode;
String recievedata;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600); //baud rate = 57600

  //RFID set up
  SPI.begin();
  RC522.init();

  mode = 1;//
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    recievedata = Serial.read();
  }
  
  if (mode==1){
    
  }

  //RFID Mode
  else if (mode==2){
    if (RC522.isCard())
  {
      /* If so then get its serial number */
      RC522.readCardSerial();
      Serial.println("Card detected:");
      for(int i=0;i<5;i++)
      {
      Serial.print(RC522.serNum[i],DEC);
      //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
      }
      Serial.println();
      Serial.println();
      }
      delay(1000);
  }
}
