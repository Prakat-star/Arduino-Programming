int marks[5] = {80, 75, 90, 85, 70};

void setup() {
  Serial.begin(9600);

  Serial.println("Student Marks:");

  int sum = 0;

  for (int i = 0; i < 5; i++) {
    Serial.print("Mark ");
    Serial.print(i + 1);
    Serial.print(" = ");
    Serial.println(marks[i]);

    sum += marks[i];
  }

  float average = sum / 5.0;

  Serial.println();
  Serial.print("Total Marks = ");
  Serial.println(sum);

  Serial.print("Average Marks = ");
  Serial.println(average);
}

void loop() {
}