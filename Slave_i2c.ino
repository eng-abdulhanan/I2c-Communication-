#include<Wire.h>
int x = 0;
void setup() {
  Serial.begin(9600);
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent); 
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void requestEvent()                                //This Function is called when Master wants value from slave
{
  int mul=2;
  int S_ans=x*mul;
  Wire.write(S_ans);                          // sends one byte converted POT value to master
}

void loop() {
  if(x)
  {
  Serial.println("Value From Master: ");
  Serial.println(x);
  x=0;
  }
}
