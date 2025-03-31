/*
MORSE CODE TRANSLATOR
Hi, I've included some comments on each segment to explain each purpose and how they work
change the variable according to what you want, I've used this because it's confusing and helps me to keep on differentiating things
- P.S: The Autumn Engineer
*/

String rem = "";
const int button = 2;
int reading = 0;
int counter = 0; 
int bounce = 0; 
int wordtimer = 0;
String morse = "";
String ren = "";
String period = ".";
String dash = "-";

String morseAlphabet[] = { //Yk what this is (✿╹◡╹)
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
    counter++; bounce = 0; wordtimer = 0;
    delay(10);
  } 
  else if (reading == HIGH && counter > 0) { //checks if the button is not pressed and will check the input 
    if (counter > 20) { rem += dash; } 
    else if (counter > 1) { rem += period; }  
    Serial.print("Morse: ");
    Serial.println(rem);
    counter = 0; bounce = 1;
  }

  if (reading == HIGH && bounce > 0) { //starts the bouncer for the precedding segment
    bounce++; 
    wordtimer++; 
  }

  if (bounce == 30 && reading == HIGH) {
    for (int i = 0; i < 26; i++) { //we iterate on each to find a match and return it
      if (rem == morseAlphabet[i]) {
        Serial.println(alphabet[i]);
        ren += alphabet[i]; rem = "";
        break;
      } 
    }
    rem = ""; //resets once it did not find a match
  } 

  if (bounce == 100) { //induces a space, the most efficient one I found so far (ￗ﹏ￗ )
    ren += " "; Serial.println("space");
  }

  //This segment checks if you paused for print and then prints out your word
  if (wordtimer == 180 && reading == HIGH) {
    Serial.println(ren);  
    ren = "";
    bounce = 0; 
    wordtimer = 0;
    rem = "";
  }
  delay(10); //necessary, to avoid conflicting inputs
}
