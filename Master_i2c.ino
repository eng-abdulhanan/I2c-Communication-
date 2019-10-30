#include<Wire.h>
int x = 0;
void setup() {
  Serial.begin(9600);
  Wire.begin(); 
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
  Wire.requestFrom(9,1);
  int ans = Wire.read();
  Serial.println("Answer Received: ");
  Serial.println(ans);
  x++; 
  if (x > 5) x = 0;
  delay(500);
}
