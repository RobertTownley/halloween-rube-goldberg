#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

// #include "BluefruitConfig.h"

#if SOFTWARE_SERIAL_AVAILABLE
  #include <SoftwareSerial.h>
#endif

/* Constants */
bool previousPressState = false;

const int EXTERNAL_LED_PIN = 11;
const int BUTTON_PIN = 2;
const int BUTTON_SENSITIVITY_THRESHOLD = 200;

/* Setup and Main Loop */
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(EXTERNAL_LED_PIN, OUTPUT);
  pinMode(INPUT_PULLUP, BUTTON_PIN);

  setupBluetooth();
}

void loop() {
  bool currentPressState = detectCurrentPressState();
  if(previousPressState != currentPressState) {
    previousPressState = currentPressState;
    handlePress(currentPressState);
  };
}

// See if button is currently pressed or not
bool detectCurrentPressState() {
  int value = analogRead(BUTTON_PIN);
  return value > BUTTON_SENSITIVITY_THRESHOLD;
}

// Take action if button state has changed
void handlePress(bool state) {
  if(state == false){
    return;
  }
  // Kid has pressed the button

  // Turn off the light until the button is ready to be pressed again
  digitalWrite(EXTERNAL_LED_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  
  // Inform python server of button press
  broadcastButtonPress();

  // Wait a few seconds, and then turn back on the button
  const int BUTTON_DELAY = 3000;
  delay(BUTTON_DELAY);
  digitalWrite(EXTERNAL_LED_PIN, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
}

/* Bluetooth Settings */
#define BLUEFRUIT_SPI_CS               8
#define BLUEFRUIT_SPI_IRQ              7
#define BLUEFRUIT_SPI_RST              4    // Optional but recommended, set to -1 if unused
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

void setupBluetooth() {
  while (!Serial);  // required for Flora & Micro
  delay(500);

  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit HID Keyboard Example"));
  Serial.println(F("---------------------------------------"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(true) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );

  ble.echo(false);
  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();
  // Set device name
  Serial.println(F("Setting device name to 'TownButton2': "));
  if (! ble.sendCommandCheckOK(F( "AT+GAPDEVNAME=TownButton2" )) ) {
    error(F("Could not set device name?"));
  }
}

void broadcastButtonPress() {
  Serial.println("I would tell the python server now...");
  ble.print("AT+BleKeyboard=");
  ble.println("TEST COMMAND FROM BLUETOOTH");
}