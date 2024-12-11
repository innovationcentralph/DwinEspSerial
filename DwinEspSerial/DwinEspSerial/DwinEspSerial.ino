#include <HardwareSerial.h>

// Create a HardwareSerial object for Serial2
HardwareSerial mySerial(2);

// DIALOG HEX
uint8_t dialogNone[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x00, 0x00, 0x00};
uint8_t dialogPlastic[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x00, 0x00, 0x01};
uint8_t dialogMetal[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x00, 0x00, 0x02};
uint8_t dialogOther[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x00, 0x00, 0x03};

// PLASTIC STATUS HEX
uint8_t plasticNone[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x01, 0x00, 0x00};
uint8_t plasticGreen[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x01, 0x00, 0x04};
uint8_t plasticYellow[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x01, 0x00, 0x05};
uint8_t plasticRed[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x01, 0x00, 0x06};

// METAL STATUS HEX
uint8_t metalNone[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x02, 0x00, 0x00};
uint8_t metalGreen[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x02, 0x00, 0x04};
uint8_t metalYellow[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x02, 0x00, 0x05};
uint8_t metalRed[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x02, 0x00, 0x06};

// OTHER STATUS HEX
uint8_t otherNone[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x03, 0x00, 0x00};
uint8_t otherGreen[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x03, 0x00, 0x04};
uint8_t otherYellow[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x03, 0x00, 0x05};
uint8_t otherRed[] = {0x5A, 0xA5, 0x05, 0x82, 0x55, 0x03, 0x00, 0x06};

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);

  // Initialize Serial2 (pins RX2 and TX2)
  mySerial.begin(115200, SERIAL_8N1, 16, 17); // RX2 = GPIO16, TX2 = GPIO17 (adjust pins as needed)

  Serial.println("Starting Serial Communication...");
}

void loop() {
  // Debug each sequence before sending
  Serial.println("Sending plasticNone");
  for (uint8_t i = 0; i < sizeof(plasticNone); i++) {
    Serial.print("0x");
    Serial.print(plasticNone[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  mySerial.write(plasticNone, sizeof(plasticNone));
  delay(5000); // Wait 1 second

  // Repeat for other sequences
  Serial.println("Sending plasticGreen");
  for (uint8_t i = 0; i < sizeof(plasticGreen); i++) {
    Serial.print("0x");
    Serial.print(plasticGreen[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  mySerial.write(plasticGreen, sizeof(plasticGreen));
  delay(5000);

  Serial.println("Sending plasticYellow");
  for (uint8_t i = 0; i < sizeof(plasticYellow); i++) {
    Serial.print("0x");
    Serial.print(plasticYellow[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  mySerial.write(plasticYellow, sizeof(plasticYellow));
  delay(5000);

  Serial.println("Sending plasticRed");
  for (uint8_t i = 0; i < sizeof(plasticRed); i++) {
    Serial.print("0x");
    Serial.print(plasticRed[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  mySerial.write(plasticRed, sizeof(plasticRed));
  delay(5000);
}
