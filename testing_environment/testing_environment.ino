//NECESSARY LIBRARIES: Adafruit GFX Library, ESP32 BLE ANCS Notiications, GxEPD2

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <GxEPD2_BW.h>  // Change to GxEPD2_3C.h or GxEPD2_7C.h if using a multi-color display
#include "esp32notifications.h"
#include <iostream>

int buttonHoverX, buttonHoverY;

// Adjust pins and model to match your hardware wiring
GxEPD2_BW<GxEPD2_290_T9, GxEPD2_290_T9::HEIGHT> display(GxEPD2_290_T9(/*CS=*/5, /*DC=*/17, /*RST=*/16, /*BUSY=*/4));

void setup() {
  // put your setup code here, to run once:
  Serial.println("init setup");

  Serial.begin(115200);
  display.init(115200);

  render();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void render() {
  display.setFullWindow();  // Targets the whole screen, display.setPartialWindow(x, y, w, h); selects only a small zone
  display.firstPage();

  do {
    display.fillScreen(GxEPD_WHITE);
    // Draw full-screen content here...
  } while (display.nextPage());
}

