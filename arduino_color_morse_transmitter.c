const char *codes[] = {
  // letters
  ".-","-...","-.-.","-..", ".", "..-.", "--.",
  "....", "..", ".---", "-.-", ".-..", "--",
  "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  // numbers
  "-----", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----."
};

const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

const int morseDelay = 200;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void loop() {
  morse("sos", 255, 0, 0); // red 'sos'
  morse("arduino", 100, 255, 100); // light green 'arduino'
}

void morse(char *text, int r, int g, int b) {
  int c = 0;
  char ch = text[0];
  int pos = 0;
  
  while (ch != 0) {
    if (ch == ' ') {
      delay(morseDelay * 7);
    } else {
      if (ch >= 'A' && ch <= 'Z') {
        ch -= 'A';
        ch += 'a';
      }
      
      if ((ch >= 'a' && ch <= 'z')) {
        pos = ch - 'a';
      } else if (ch >= '0' && ch <= '9') {
        pos = ch - '0' + 26;
      } else {
        pos = -1;
      }
          
      if (pos >= 0) {
        for (int i=0; i<strlen(codes[pos]); i++) {
          int dd = codes[pos][i] == '.' ? morseDelay : (morseDelay*3);
          
          analogWrite(redPin, r);
          analogWrite(greenPin, g);
          analogWrite(bluePin, b);
          delay(dd);
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
          delay(morseDelay);
        }
        
        delay(morseDelay * 3);
      }
    }
    
    ch = text[++c];
  }
  
  delay(morseDelay * 7);
}