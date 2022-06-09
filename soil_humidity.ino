// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 9;     // the number of the pushbutton pin
const int buttonPin2 = 8;
const int buttonPin3 = 7;
const int buttonPin4 = 4;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

const int AirValue = 497;   //you need to replace this value with Value_1
const int WaterValue = 260;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  digitalWrite(buttonPin1, HIGH);
  pinMode(buttonPin2, INPUT);
  digitalWrite(buttonPin2, HIGH);
  pinMode(buttonPin3, INPUT);
  digitalWrite(buttonPin3, HIGH);
   pinMode(buttonPin4, INPUT);
  digitalWrite(buttonPin4, HIGH);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  // Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent >= 100)
  {
    Serial.println("100");
  }
  else if(soilmoisturepercent <=0)
  {
    Serial.println("0");
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    Serial.print(soilmoisturepercent);
    Serial.println(" ");
  }
  Serial.print(" ");
  Serial.print(buttonState1);
  Serial.print(" ");
  Serial.print(buttonState2);
  Serial.print(" ");
  Serial.print(buttonState3);
  Serial.print(" ");
  Serial.print(buttonState4);
  Serial.print(" ");
}
