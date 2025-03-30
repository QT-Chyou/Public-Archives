String rem = "";
const int button = 2;
int reading = 0;
int counter = 0; int bounce = 0; int wordtimer = 0;
String morse = "";
String ren = "";
String period = String(".");
String dash = String("-");

String morseAlphabet[] = { 
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
      ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
      ".--", "-..-", "-.--", "--.." };

char alphabet[] = { 
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  reading = digitalRead(button);
  if (reading == LOW) {
    counter++; bounce = 0;
    delay(10);
  } 
  else if (reading == HIGH && counter > 0) {
    if (counter > 20) { rem += dash; }  
    else if (counter > 1) { rem += period; }  
    Serial.print("Morse: ");
    Serial.println(rem);
    counter = 0; bounce = 1;
  }

  if (reading == HIGH && bounce > 0) {
    bounce++; wordtimer++;
  }

  if (bounce == 30) {
    if (rem == "") {
      ren += " ";
    }
    for (int i = 0; i < 26; i++) {
      if (rem == morseAlphabet[i]) {
        Serial.println(alphabet[i]);
        ren += alphabet[i]; rem = "";
        break;  
      } 
    }
    rem = "";
  } 
  //This segment checks if y
  if (wordtimer == 120) {
    Serial.println(ren);  
    ren = "";
    bounce = 0; 
    wordtimer = 0;
  }
  delay(10);
}