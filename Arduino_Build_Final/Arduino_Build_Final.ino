#include <Adafruit_ATParser.h>
#include <Adafruit_BLE.h>
#include <Adafruit_BLEBattery.h>
#include <Adafruit_BLEEddystone.h>
#include <Adafruit_BLEGatt.h>
#include <Adafruit_BLEMIDI.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>

#include <Adafruit_ATParser.h>
#include <Adafruit_BLE.h>
#include <Adafruit_BLEBattery.h>
#include <Adafruit_BLEEddystone.h>
#include <Adafruit_BLEGatt.h>
#include <Adafruit_BLEMIDI.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>

/*********************************************************************
  This is an example based on nRF51822 based Bluefruit LE modules

********************************************************************/

#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "BluefruitConfig.h"

#if SOFTWARE_SERIAL_AVAILABLE
#include <SoftwareSerial.h>
#endif

/*=========================================================================
       -----------------------------------------------------------------------*/
#define FACTORYRESET_ENABLE         0
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"
/*=========================================================================*/


Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

/* ...software SPI, using SCK/MOSI/MISO user-defined SPI pins and then user selected CS/IRQ/RST */
//Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_SCK, BLUEFRUIT_SPI_MISO,
//                             BLUEFRUIT_SPI_MOSI, BLUEFRUIT_SPI_CS,
//                             BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);


// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

/**************************************************************************/
/*!
    @brief  Sets up the HW an the BLE module (this function is called
            automatically on startup)
*/
/**************************************************************************/
char ch;
int LED_1 = 3;
int LED_2 = 4;
int LED_3 = 5;
int LED_4 = 6;
int LED_5 = 7;
int LED_6 = 8;
int LED_7 = 9;
int LED_8 = 10;
int LED_9 = 11;
int LED_10 = 12;

void setup() {

 {
  while (!Serial);  // required for Flora & Micro
  delay(500);

  Serial.begin(9600);
  Serial.println(F("Adafruit Bluefruit Command <-> Data Mode Example"));
  Serial.println(F("------------------------------------------------"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );

  if ( FACTORYRESET_ENABLE )
  {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ) {
      error(F("Couldn't factory reset"));
    }
  }

  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();



  ble.verbose(false);  // debug info is a little annoying after this point!


  Serial.println(F("******************************"));

  // LED Activity command is only supported from 0.6.6
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
  {
    // Change Mode LED Activity
    Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
  }

  //Give module a new name
  ble.println("AT+GAPDEVNAME=TLONE"); // named TLONE

  // Check response status
  ble.waitForOK();

  /* Wait for connection */
  while (! ble.isConnected()) {
    delay(500);
  }
  // Set module to DATA mode
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);

  Serial.println(F("******************************"));
}

/**************************************************************************/
/*!
    @brief  Constantly poll for new command or response data
*/
 
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(LED_1,OUTPUT);
 pinMode(LED_2,OUTPUT);
 pinMode(LED_3,OUTPUT);
 pinMode(LED_4,OUTPUT);
 pinMode(LED_5,OUTPUT);
 pinMode(LED_6,OUTPUT);
 pinMode(LED_7,OUTPUT);
 pinMode(LED_8,OUTPUT);
 pinMode(LED_9,OUTPUT);
 pinMode(LED_10,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
{
  // Check for user input
  char n, inputs[BUFSIZE + 1];

  if (Serial.available())
  {
    n = Serial.readBytes(inputs, BUFSIZE);
    inputs[n] = 0;
    // Send characters to Bluefruit
    Serial.print("Sending: ");
    Serial.println(inputs);

    // Send input data to host via Bluefruit
    ble.print(inputs);
  }
  if (ble.available()) {
    Serial.print("* "); Serial.print(ble.available()); Serial.println(F(" bytes available from BTLE"));
  }
  // Echo received data
  while ( ble.available() )
  {
    int c = ble.read();
    Serial.print((char)c);
  }
  delay(1000);
}

if(Serial.available()){
    ch = Serial.read();
    Serial.write(ch);
    doWork(ch);
  }
}

void doWork(char ch){
  switch(ch){
    case 'A': //code for all leds turned on
              digitalWrite(LED_1,HIGH);
              digitalWrite(LED_2,HIGH);
              digitalWrite(LED_3,HIGH);
              digitalWrite(LED_4,HIGH);
              digitalWrite(LED_5,HIGH);
              digitalWrite(LED_6,HIGH);
              digitalWrite(LED_7,HIGH);
              digitalWrite(LED_8,HIGH);
              digitalWrite(LED_9,HIGH);
              digitalWrite(LED_10,HIGH);
              break;
    case 'a': //code for all leds turned off
              digitalWrite(LED_1,LOW);
              digitalWrite(LED_2,LOW);
              digitalWrite(LED_3,LOW);
              digitalWrite(LED_4,LOW);
              digitalWrite(LED_5,LOW);
              digitalWrite(LED_6,LOW);
              digitalWrite(LED_7,LOW);
              digitalWrite(LED_8,LOW);
              digitalWrite(LED_9,LOW);
              digitalWrite(LED_10,LOW);
              break;
   case 'B':  //code for all odd leds turned on
              digitalWrite(LED_1,HIGH);
              digitalWrite(LED_3,HIGH);
              digitalWrite(LED_5,HIGH);
              digitalWrite(LED_7,HIGH);
              digitalWrite(LED_9,HIGH);
              break;
   case 'b':  //code for all odd leds turned off
              digitalWrite(LED_1,LOW);
              digitalWrite(LED_3,LOW);
              digitalWrite(LED_5,LOW);
              digitalWrite(LED_7,LOW);
              digitalWrite(LED_9,LOW);;
              break;
   case 'C': //code for all even leds turned on
              digitalWrite(LED_2,HIGH);
              digitalWrite(LED_4,HIGH);
              digitalWrite(LED_6,HIGH);
              digitalWrite(LED_8,HIGH);
              digitalWrite(LED_10,HIGH);
              break;
   case 'c': //code for all even leds turned off
              digitalWrite(LED_2,LOW);
              digitalWrite(LED_4,LOW);
              digitalWrite(LED_6,LOW);
              digitalWrite(LED_8,LOW);
              digitalWrite(LED_10,LOW);
              break;
  }
}
