char ch;
int LED_1 = 3;
int LED_2 = 4;
int LED_3 = 5;
int LED_4 = 6;
int LED_5 = 7;
int LED_6 = 8;
int LED_7 = 9;
int LED_8 = 10;
int LED_9 = 11;
int LED_10 = 12;



void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(LED_1,OUTPUT);
 pinMode(LED_2,OUTPUT);
 pinMode(LED_3,OUTPUT);
 pinMode(LED_4,OUTPUT);
 pinMode(LED_5,OUTPUT);
 pinMode(LED_6,OUTPUT);
 pinMode(LED_7,OUTPUT);
 pinMode(LED_8,OUTPUT);
 pinMode(LED_9,OUTPUT);
 pinMode(LED_10,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:

if(Serial.available()){
    ch = Serial.read();
    Serial.write(ch);
    doWork(ch);
  }
}

void doWork(char ch){
  switch(ch){
    case 'A': //code for all leds turned on
              digitalWrite(LED_1,HIGH);
              digitalWrite(LED_2,HIGH);
              digitalWrite(LED_3,HIGH);
              digitalWrite(LED_4,HIGH);
              digitalWrite(LED_5,HIGH);
              digitalWrite(LED_6,HIGH);
              digitalWrite(LED_7,HIGH);
              digitalWrite(LED_8,HIGH);
              digitalWrite(LED_9,HIGH);
              digitalWrite(LED_10,HIGH);
              break;
    case 'a': //code for all leds turned off
              digitalWrite(LED_1,LOW);
              digitalWrite(LED_2,LOW);
              digitalWrite(LED_3,LOW);
              digitalWrite(LED_4,LOW);
              digitalWrite(LED_5,LOW);
              digitalWrite(LED_6,LOW);
              digitalWrite(LED_7,LOW);
              digitalWrite(LED_8,LOW);
              digitalWrite(LED_9,LOW);
              digitalWrite(LED_10,LOW);
              break;
   case 'B':  //code for all odd leds turned on
              digitalWrite(LED_1,HIGH);
              digitalWrite(LED_3,HIGH);
              digitalWrite(LED_5,HIGH);
              digitalWrite(LED_7,HIGH);
              digitalWrite(LED_9,HIGH);
              break;
   case 'b':  //code for all odd leds turned off
              digitalWrite(LED_1,LOW);
              digitalWrite(LED_3,LOW);
              digitalWrite(LED_5,LOW);
              digitalWrite(LED_7,LOW);
              digitalWrite(LED_9,LOW);;
              break;
   case 'C': //code for all even leds turned on
              digitalWrite(LED_2,HIGH);
              digitalWrite(LED_4,HIGH);
              digitalWrite(LED_6,HIGH);
              digitalWrite(LED_8,HIGH);
              digitalWrite(LED_10,HIGH);
              break;
   case 'c': //code for all even leds turned off
              digitalWrite(LED_2,LOW);
              digitalWrite(LED_4,LOW);
              digitalWrite(LED_6,LOW);
              digitalWrite(LED_8,LOW);
              digitalWrite(LED_10,LOW);
              break;
  }
}
