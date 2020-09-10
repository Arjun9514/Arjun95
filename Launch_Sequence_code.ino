//-------------------------------------------------->Global variables<
//-------------------------------------------------->Led pin defintions<
int rled = 13;
int gled = 12;
//-------------------------------------------------->variable for countdown<
int count = 10;
//-------------------------------------------------->other variables<
int p;
int q;
int r;
int s;
//-------------------------------------------------->other Booleans<
boolean codeRight = false;
//-------------------------------------------------->setup<
void setup() {
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  Serial.begin(9600);
}
//-------------------------------------------------->loop<
void loop() {
  if (codeRight == false)LSci();
  if (codeRight == true)countDown();
}
//-------------------------------------------------->countDown<
void countDown() {
  if (count == 0) {
    if (count >= -1)digitalWrite(gled, HIGH);
    Serial.println("launch off");
    Serial.println();
  }
  if (count > 0) {
    Serial.println(count);
    digitalWrite(rled, HIGH);
  }
  if (count >= -1)count--;
  if (count <= 0)digitalWrite(rled, LOW);
  delay(1000);
}
//-------------------------------------------------->LSci (Launch_Sequence_Code_Input)<
void LSci() {
  int a = 4732;
  int b = 3849;
  int c = 1336;
  int d = 5202;
  Serial.print("Launch Sequence code: ");
  inputValue();
  if (a != p || b != q || c != r || d != s) {
    Serial.println();
    Serial.println("Error!!");
    delay(1000);
    Serial.println("Re-enter the Launch Sequence Code");
    delay(500);
    Serial.println();
    return;
  } else {
    codeRight = true;
    Serial.println();
    Serial.println("Initiating Launch Sequence");
    Serial.println();
    delay(500);
    Serial.println("Please leave the launch parameters");
    Serial.println("Stay back at Safety line");
    Serial.println();
  }
}
//------------------------------------------------->input_Value<
void inputValue() {

  while (!Serial.available());
  p = Serial.parseInt();
  Serial.parseInt();
  Serial.print(p);
  delay(100);
  Serial.print(" - ");

  while (!Serial.available());
  q = Serial.parseInt();
  Serial.parseInt();
  Serial.print(q);
  delay(100);
  Serial.print(" - ");

  while (!Serial.available());
  r = Serial.parseInt();
  Serial.parseInt();
  Serial.print(r);
  delay(100);
  Serial.print(" - ");

  while (!Serial.available());
  s = Serial.parseInt();
  Serial.parseInt();
  Serial.print(s);
  Serial.println();
}
//-------------------------------------------------->************End***********<
