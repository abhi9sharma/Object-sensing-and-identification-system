const int trigPin = 7; long duration; int distance; const int echoPin = 6;
#include <Servo.h>
Servo myservo;
Servo myservo1;
int val = 90; int val1 = 90;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  myservo1.attach(10);
  myservo.write(val); myservo1.write(val1);
}

void loop()
{
  calculateDistance();
  Serial.print("|| Distance= "); Serial.print(distance); Serial.println("Cms  ||");
  if (Serial.available() > 0)
  {
    char a = Serial.read();
    if (a == 'W')
    { if (val < 180)
      {
        val = val + 10;
        myservo.write(val);
      }
    }
    if (a == 'S')
    { if (val > 0)
      {
        val = val - 10;
        myservo.write(val);
      }
    }
    if (a == 'D')
    { if (val1 < 180)
      {
        val1 = val1 + 10;
        myservo1.write(val1);
      }
    }
    if (a == 'A')
    { if (val > 0)
      {
        val1 = val1 - 10;
        myservo1.write(val1);
      }
    }


  }
  delay(50);

}
