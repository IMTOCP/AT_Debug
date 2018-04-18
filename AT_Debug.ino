

// Set serial for debug console (to the Serial Monitor, speed 115200)
//Set end of the line to new line or Both NL and CR
#define SerialMon Serial

// Set serial for AT commands (to the module)
// Use Hardware Serial on Mega, Leonardo, Micro
#define SerialAT Serial1

// or Software Serial on Uno, Nano
//#include <SoftwareSerial.h>
//SoftwareSerial SerialAT(2, 3); // RX, TX


#define _rstpin 4


// Module baud rate
uint32_t rate = 115200; // Set to 0 for Auto-Detect

void setup() {
  // Set console baud rate
  SerialMon.begin(115200);
  SerialMon.println("BEGIN SETUP");
  delay(1000);
  pinMode(_rstpin, OUTPUT);
  digitalWrite(_rstpin, HIGH);
  delay(10);
  digitalWrite(_rstpin, LOW);
  delay(100);
  digitalWrite(_rstpin, HIGH);
  SerialAT.begin(115200);
  SerialMon.println("END SETUP");
}

void loop() {

  // Access AT commands from Serial Monitor
  SerialMon.println(F("***********************************************************"));
  SerialMon.println(F(" You can now send AT commands"));
  SerialMon.println(F(" Enter \"AT\" (without quotes), and you should see \"OK\""));
  SerialMon.println(F(" If it doesn't work, select \"Both NL & CR\" in Serial Monitor"));
  SerialMon.println(F("***********************************************************"));

  while(true) {
    if (SerialAT.available()) {
      SerialMon.write(SerialAT.read());
    }
    if (SerialMon.available()) {
      SerialAT.write(SerialMon.read());
    }
    delay(0);
  }
}

