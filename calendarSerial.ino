
int analogPin4 = A4;
int analogPin3 = A3;
int analogPin2 = A2;
int analogPin1 = A1;
int value = 0;
String hour1 = "09:00-10:00";
String hour2 = "10:00-11:00";
String hour3 = "11:00-12:00";
String hour4 = "12:00-13:00";


bool label = true;

void setup() {
  Serial.begin(9600);
  pinMode(analogPin4, INPUT);
  pinMode(analogPin3, INPUT);
  pinMode(analogPin2, INPUT);
  pinMode(analogPin1, INPUT);

}

void loop() {
  
  
  Serial.println("Morning Schedule");
  delay(500);
  printer(hour1, analogPin4);
  printer(hour2, analogPin3);
  printer(hour3, analogPin2);
  printer(hour4, analogPin1);
  Serial.print("");

  delay(2000);

}

void printer(String hour, int pin) {
  value = analogRead(pin);
  Serial.print(hour);
  if (value <= 100){
    Serial.println(": OPEN");
    //Serial.println(value);
  }
 
  else if (value > 950 and value < 1100){
    Serial.println(": AAFC MEETING");
    //Serial.println(value);
  }

  else if (value > 900 and value < 949){
    Serial.println(": SCHOOL WORK");
    //Serial.println(value);
  }
  else if (value > 600 and value < 700){
    Serial.println(": WORKOUT");
    //Serial.println(value);
  }
  
  else if (value > 400 and value < 600){
    Serial.println(": ERRANDS");
    //Serial.println(value);
  }
  delay(500);

}
