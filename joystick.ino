const int Vy = A0;
const int Vx = A1;
const int SW = 2;

int xVal;
int yVal;

void setup() {
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  xVal = analogRead(Vx);
  yVal = analogRead(Vy);

  if (xVal > 700) {
    Serial.print("l"); // Left
  }
  else if (xVal < 400) {
    Serial.print("r"); // Right
  }
  else {
    Serial.print("o");
  }

  if (yVal > 700) {
    Serial.print("u"); // Up
  } else if (yVal < 400) {
    Serial.print("d"); // Down
  } else {
    Serial.print("o");
  }

  if(digitalRead(SW)==LOW){
    Serial.print("l");
  }else{
    Serial.print("h");
  }

  Serial.println("");
  delay(200);
}
