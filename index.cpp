#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(0, 1); // RX, TX

String Data = ""; // the data received
String servo1Pos = "";
int Data2, mapping, Data4;
String Data3;
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() {
    servo1.attach(3);
    servo2.attach(5);
    servo3.attach(6);
    servo4.attach(9);
    servo5.attach(10);
    servo6.attach(11);
    Bluetooth.begin(9600);
    Serial.println("Waiting for command...");
    Bluetooth.println("Send 1 to turn on the LED. Send 0 to turn Off");
    pinMode(LED, OUTPUT);

}

void loop() {
  if (Bluetooth.available() > 0) {
    Data = Bluetooth.readString(); //148A148A148
    Serial.println(Data.substring(0, 1));
    if (Data.substring(0, 1) == "A") {
      servo1.attach(3);
      String dataInS = Data.substring(1, Data.length());
      servo1Pos = dataInS.toInt();

      Serial.println(Data);
      Data2 = dataInS.indexOf('A');//4
      Data3 = dataInS.substring(0, Data2);
//      Serial.println(Data3);
      mapping = map(Data3.toInt(), 0, 180, 0, 180);
      servo1.write(mapping);
      delay(1000);
      //      servo1.detach();
//      Serial.println(mapping);

    }
    if (Data.substring(0, 1) == "B") {
      servo2.attach(5);
      String dataInS = Data.substring(1, Data.length());//47
      servo1Pos = dataInS.toInt();

      Serial.println(Data);
      Data2 = dataInS.indexOf('B');//3
      Data3 = dataInS.substring(0, Data2);
//      Serial.println(Data3);
      mapping = map(Data3.toInt(), 0, 180, 20, 90);
      servo2.write(mapping);
//      Serial.println(mapping);
      delay(1000);
      //      servo2.detach();
    }
    if (Data.substring(0, 1) == "C") {
      servo3.attach(6);
      String dataInS = Data.substring(1, Data.length());
      servo1Pos = dataInS.toInt();

      Serial.println(Data);
      Data2 = dataInS.indexOf('C');
      Data3 = dataInS.substring(0, Data2);
      Serial.println(Data3);
      mapping = map(Data3.toInt(), 0, 180, 70, 180);
      servo3.write(mapping);
      Serial.println(mapping);
      delay(1000);
      //      servo3.detach();
    }
    if (Data.substring(0, 1) == "D") {
      servo4.attach(9);

      String dataInS = Data.substring(1, Data.length());
      servo1Pos = dataInS.toInt();

      Serial.println(Data);
      Data2 = dataInS.indexOf('D');
      Data3 = dataInS.substring(0, Data2);
      Serial.println(Data3);
      mapping = map(Data3.toInt(), 0, 180, 90, 180);
      servo4.write(mapping);
      delay(1000);
      //      servo4.detach();
    }
    if (Data.substring(0, 1) == "E") {
      servo5.attach(10);

      String dataInS = Data.substring(1, Data.length());
      servo1Pos = dataInS.toInt();

      Serial.println(Data);
      Data2 = dataInS.indexOf('E');
      Data3 = dataInS.substring(0, Data2);
      Serial.println(Data3);
      mapping = map(Data3.toInt(), 0, 180, 20, 100);
      servo5.write(mapping);
      delay(1000);
      //      servo5.detach();
    }
    if (Data.substring(0, 1) == "F") {
      servo6.attach(11);
      String dataInS = Data.substring(1, Data.length());
      servo1Pos = dataInS.toInt();

      Serial.println(Data);
      Data2 = dataInS.indexOf('F');
      Data3 = dataInS.substring(0, Data2);
      Serial.println(Data3.toInt());
      Data4 = Data3.toInt();
      mapping = map(Data4, 0, 180, 90, 180);
      servo6.write(mapping);
      Serial.println(Data3.toInt());
      Serial.println(mapping);
      delay(1000);
      //      servo6.detach();
    }
    delay(300);
  }
}
