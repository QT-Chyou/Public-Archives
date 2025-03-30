/*
MORSE CODE TRANSLATOR
Hi, I've included some comments on each segment to explain each purpose and how they work
change the variable according to what you want, I've used this because it's confusing and helps me to keep on differentitating things
- P.S: The Autumn Engineer
*/

String rem = "";
const int button = 2;
int reading = 0;
int counter = 0; int bounce = 0; int wordtimer = 0;
String morse = "";
String ren = "";
String period = String(".");
String dash = String("-");

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
  if (reading == LOW) { //checks when the button is not pressed
    counter++; bounce = 0;
    delay(10);
  } 
  else if (reading == HIGH && counter > 0) { //checks if the button is not pressed and will check the input 
    if (counter > 20) { rem += dash; } 
    else if (counter > 1) { rem += period; }  
    Serial.print("Morse: ");
    Serial.println(rem);
    counter = 0; bounce = 1;
  }

  if (reading == HIGH && bounce > 0) {
    bounce++; wordtimer++; //starts the bouncer for the precedding segment
  }

  if (bounce == 30) {
    if (rem == "") { //should add a space, yet to update(✿╹◡╹)..
      ren += " ";
    }
    for (int i = 0; i < 26; i++) { //we iterate on each to find a match and return it
      if (rem == morseAlphabet[i]) {
        Serial.println(alphabet[i]);
        ren += alphabet[i]; rem = "";
        break;  
      } 
    }
    rem = ""; //resets once it did not find a match
  } 

  //This segment checks if you paused for a while and then prints out your word
  if (wordtimer == 120) {
    Serial.println(ren);  
    ren = "";
    bounce = 0; 
    wordtimer = 0;
  }
  delay(10); //necessary, to avoid conflicting inputs
}
