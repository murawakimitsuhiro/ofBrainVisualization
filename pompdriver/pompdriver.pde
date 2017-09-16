import oscP5.*;
import netP5.*;
import processing.serial.*;
import cc.arduino.*;
import org.firmata.*;

Arduino arduino;
OscP5 oscP5;
NetAddress myRemoteLocation;
int Value=0;

//smoothing
final int HairetuNum =5;
int []  readings=new int [HairetuNum];
// the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int firstValue=0;


void setup() {
  frameRate(25);
  arduino= new Arduino(this, "/dev/cu.usbmodem1441", 57600);
  oscP5 = new OscP5(this, 1050);
  myRemoteLocation = new NetAddress("192,168,0,3", 12000);
  arduino.pinMode(6, Arduino.OUTPUT);
  arduino.pinMode(2, Arduino.OUTPUT);
  arduino.pinMode(3, Arduino.OUTPUT);
  arduino.pinMode(4, Arduino.OUTPUT);
  arduino.pinMode(5, Arduino.OUTPUT);
}

void oscEvent(OscMessage theOscMessage) {
  if(theOscMessage.checkAddrPattern("/test")==true) {//ラベルが/testかチェック
   firstValue = theOscMessage.get(0).intValue();  //get(0)で一番目の値を取る
  }
}



void draw() { 
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = firstValue;
  //add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= HairetuNum) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / HairetuNum;
  // send it to the computer as ASCII digits
  Value=average;
  println(Value);

  if (Value==1) {
    arduino.digitalWrite(6, Arduino.HIGH);
    arduino.digitalWrite(2, Arduino.HIGH);
    arduino.digitalWrite(3, Arduino.HIGH);
    arduino.digitalWrite(4, Arduino.HIGH);
    arduino.digitalWrite(5, Arduino.HIGH);
    delay(300);                                                       //数値が継続しポンプが稼働するための時間稼ぎ
  }
  arduino.digitalWrite(6, Arduino.LOW);
  arduino.digitalWrite(2, Arduino.LOW);
  arduino.digitalWrite(3, Arduino.LOW);
  arduino.digitalWrite(4, Arduino.LOW);
  arduino.digitalWrite(5, Arduino.LOW);
}