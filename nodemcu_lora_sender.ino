#include <LoRa.h>
#define SS 15
#define RST 16
#define DIO0 2
String data = "Subscribe Tech Vegan";
int x;
void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Sender Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    delay(100);
    while (1);
  }
}
void loop()
{
  Serial.print("Sending Data: ");
  Serial.println(x);
  LoRa.beginPacket();
  LoRa.print(x);
  LoRa.endPacket();
  x+=1;
  delay(500);
}