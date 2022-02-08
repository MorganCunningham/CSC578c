
int analogPin4 = A4;
int analogPin3 = A3;
int analogPin2 = A2;
int analogPin1 = A1;
int value = 0;
String hour1 = "9:00";
String hour2 = "10:00";
String hour3 = "11:00";
String hour4 = "12:00";
String hour5 = "13:00";
String startDate = "2022-12-31";
bool label = true;

void setup() {
  Serial.begin(9600);
  pinMode(analogPin4, INPUT);
  pinMode(analogPin3, INPUT);
  pinMode(analogPin2, INPUT);
  pinMode(analogPin1, INPUT);

}

void loop() {
  
  
  Serial.print("Subject");
  Serial.print(",");
  Serial.print("Start date");
  Serial.print(",");
  Serial.print("Start time");
  Serial.print(",");
  Serial.print("End date");
  Serial.print(",");
  Serial.println("End time");
  
  printer(startDate, hour1, hour2, analogPin4);
  printer(startDate, hour2, hour3, analogPin3);
  printer(startDate, hour3, hour4, analogPin2);
  printer(startDate, hour4, hour5, analogPin1);


  delay(5000);

}

void printer(String day, String startT, String endT, int pin) {
  value = analogRead(pin);
  
  if (value <= 100){
    Serial.print("OPEN");
    //Serial.println(value);
  }
 
  else if (value > 950 and value < 1100){
    Serial.print("AAFC");
    //Serial.println(value);
  }

  else if (value > 900 and value < 949){
    Serial.print("WORK");
    //Serial.println(value);
  }
  else if (value > 600 and value < 700){
    Serial.print("WORKOUT");
    //Serial.println(value);
  }
  
  else if (value > 400 and value < 600){
    Serial.print("ERRANDS");
    //Serial.println(value);
  }
  Serial.print(",");
  Serial.print(day);
  Serial.print(",");
  Serial.print(startT);
  Serial.print(",");
  Serial.print(day);
  Serial.print(",");
  Serial.println(endT);
  

}
