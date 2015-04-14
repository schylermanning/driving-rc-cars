
const int upPin = 3;
const int downPin = 4;
const int leftPin = 5;
const int rightPin = 6;
int c;
boolean isOn = true;

void setup()
{
  Serial.begin(115200);
  Serial.println("Connected! ");
  pinMode(upPin, OUTPUT);
  pinMode(downPin, OUTPUT);
  pinMode(leftPin, OUTPUT);
  pinMode(rightPin, OUTPUT);
  digitalWrite(upPin, HIGH);
  digitalWrite(downPin, HIGH);
  digitalWrite(leftPin, HIGH);
  digitalWrite(rightPin, HIGH);
}

void loop() {

  if(isOn == true){
      if (Serial.available()) {
        c = Serial.read();
        switch (c) {
            case 48: // ascii '0' -> FORWARD
                digitalWrite(upPin, LOW);
                Serial.println("Forward ");
                break;
            case 49: // ascii '1' -> BACK
                digitalWrite(downPin, LOW);
                Serial.println("Back ");
                break;
            case 50: // ascii '2' -> LEFT
                digitalWrite(leftPin, LOW);
                break;
            case 51: // ascii '3' -> RIGHT
                digitalWrite(rightPin, LOW);
                break;
            case 52: // ascii '4' -> STOP
                digitalWrite(upPin, HIGH);
                digitalWrite(downPin, HIGH);
                digitalWrite(leftPin, HIGH);
                digitalWrite(rightPin, HIGH);
                break;
            default:
                break; // ...
        }
     }
  }

  boolean isOn = false;

}