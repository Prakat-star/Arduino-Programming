
const int In1 = 22;
const int In2 = 21;
const int EN = 23;

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(EN, OUTPUT);

}

void loop() {
 
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      digitalWrite(EN, HIGH);
      delay(3000);
 
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      digitalWrite(EN, HIGH);
       delay(3000);
   
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(EN, LOW);
     delay(3000);
}
