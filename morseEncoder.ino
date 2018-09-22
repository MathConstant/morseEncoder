
int outputPin = 13;
String nums="1234567890";
String qwerty="qwertyuiop";
String asdfgh="asdfghjkl";
String zxcvb="zxcvbnm";
int state = 0;
int dotLen = 200;     
int dashLen = dotLen * 3;    
int elemPause = dotLen;

void setup() 
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
   lightsOff(0);
   String message = Serial.readString();
   message.toLowerCase();
   String newWord = "";
   if (message != "")
   {
     if (message == "encrypt")
     {
       Serial.println("selected 'encrypt'");
        state = 1;
     }
     else if (message == "decrypt")
     {
        Serial.println("selected 'decrypt'");
        state = 2;
     }
     else if (state == 0)
     {
        Serial.println("Please select a type ('encrypt' or 'decrypt')");
     }
     else if (state == 1)
     {
        for (int i=0; i < message.length();i++)
        {
          char letter = message[i];
          if (nums.indexOf(letter) != -1)
          {
            newWord += encoder(nums,letter);
          }
          else if (qwerty.indexOf(letter) != -1)
          {
            newWord += encoder(qwerty,letter);
          }
          else if (asdfgh.indexOf(letter) != -1)
          {
            newWord += encoder(asdfgh,letter);
          }
          else if (zxcvb.indexOf(letter) != -1)
          {
            newWord += encoder(zxcvb,letter);
          }
          else
          {
            Serial.println("Invalid String");
            return;
          }
        }
        Serial.println(newWord);
        for (int i=0; i < newWord.length();i++)
        {
          toMorse(newWord[i]);
        }
      }
     else if (state == 2)
     {
        for (int i=0; i < message.length();i++)
        {
          char letter = message[i];
          if (nums.indexOf(letter) != -1)
          {
            newWord += decoder(nums,letter);
          }
          else if (qwerty.indexOf(letter) != -1)
          {
            newWord += decoder(qwerty,letter);
          }
          else if (asdfgh.indexOf(letter) != -1)
          {
            newWord += decoder(asdfgh,letter);
          }
          else if (zxcvb.indexOf(letter) != -1)
          {
            newWord += decoder(zxcvb,letter);
          }
          else
          {
            Serial.println("Invalid String");
            return;
          }
        }
        Serial.println(newWord);
     }
   }
}
char encoder (String line, char letter)
{
  if(line.indexOf(letter) == 0)
  {
    return line[line.length()-1];
  }
  else
  {
    return line[line.indexOf(letter)-1];
  }
}

char decoder (String line, char letter)
{
  if(line.indexOf(letter) == line.length()-1)
  {
    return line[0];
  }
  else
  {
    return line[line.indexOf(letter)+1];
  }
}

void morseDot()
{
  digitalWrite(outputPin, HIGH);    
  delay(dotLen);              
}


void morseDash()
{
  digitalWrite(outputPin, HIGH);    
  delay(dashLen);
}

void lightsOff(int delayTime)
{
  digitalWrite(outputPin, LOW);     
  delay(delayTime);             
}

 void toMorse(char tmpChar)
{
  switch (tmpChar) {
    case 'a': 
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'b':
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'c':
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'd':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'e':
      morseDot();
      lightsOff(elemPause);
      break;
    case 'f':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'g':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'h':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'i':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'j':
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'k':
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'l':
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'm':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'n':
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'o':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'p':
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 'q':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'r':
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 's':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case 't':
      morseDash();
    lightsOff(elemPause);
    break;
    case 'u':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'v':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'w':
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'x':
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'y':
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case 'z':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case '1':
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case '2':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case '3':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case '4':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    case '5':
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case '6':
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case '7':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case '8':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case '9':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDot();
      lightsOff(elemPause);
      break;
    case '0':
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      morseDash();
      lightsOff(elemPause);
      break;
    default: 
    lightsOff(dashLen);      
  }
}


