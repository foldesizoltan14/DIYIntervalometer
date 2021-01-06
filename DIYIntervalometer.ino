#define buttonDown     2
#define buttonUp       3
#define buttonLeft     4
#define buttonRight    5
#define buttonEnter    6
#define buttonBack     7
#define buttonBulb     8
int menuPosition =     0; 
int shutterSpeed = 0;
int N = 0;
int numOfEntersPressed = 0;
int dHour = 0;
int dMinute = 0;
int dSecond = 0; 
int inHour = 0;
int inMinute = 0;
int inSecond = 0;
int numOfPictures = 0;
int isDone  = 0;

const unsigned long SECOND = 1000;
const unsigned long MINUTE = 60*SECOND;
const unsigned long HOUR = 60*MINUTE;


 void setup() {

 pinMode(buttonDown, INPUT_PULLUP);
 pinMode(buttonUp, INPUT_PULLUP);
 pinMode(buttonLeft, INPUT_PULLUP);
 pinMode(buttonRight, INPUT_PULLUP);
 pinMode(buttonEnter, INPUT_PULLUP);
 pinMode(buttonBack, INPUT_PULLUP);
  pinMode(buttonBulb, INPUT_PULLUP);
 Serial.begin(9600);

}

void loop() {

while(digitalRead(buttonBulb) == 0){
  //open relay
  Serial.println("IT\"S WORKING");
  }
  
if (digitalRead(buttonDown) == 0){
    menuPosition ++;
    Serial.println(menuPosition);
    delay(250);
    }

  if (digitalRead(buttonUp) == 0){
    if(menuPosition == 0){
      menuPosition = 3;
       Serial.println(menuPosition);
      delay(250);
      }
    else {  
    menuPosition --;
    Serial.println(menuPosition);
    delay(250);
    }
    }

    switch(menuPosition){

             case 0:
                  Serial.println("Intervalometer");
             case 1 :
                      if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 0){
                        shutterSpeed++;
                        delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 0){
                        shutterSpeed--;
                        
                         delay(250);
                        }

                      if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 1){
                        N++;
                         delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 1){
                        N--;
                         delay(250);
                        }
                      
                      
                      if (digitalRead(buttonEnter) == 0){
                        numOfEntersPressed++;
                        delay(300);
                        }

                      if (numOfEntersPressed == 2){
                        Mode1(shutterSpeed,N);
                        numOfEntersPressed=0;
                        shutterSpeed = 0;
                        N = 0;
                        menuPosition=0;
                        
                        }

                      break; 
             case 2 : 
                     if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 0){
                        N++;
                         delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 0){
                        N--;
                         delay(250);
                        }
                        if (digitalRead(buttonEnter) == 0){
                        numOfEntersPressed++;
                        delay(300);
                        }

                      if (numOfEntersPressed == 1){
                        Mode2(N);
                        numOfEntersPressed=0;
                        N = 0;
                        menuPosition=0;
                        
                        }
                      break;
             case 3 :if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 0){
                        dHour++;
                        Serial.println("dHour");
                        Serial.println(dHour);
                        delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 0){
                        dHour--;
                        Serial.println("dHour");
                        Serial.println(dHour);
                         delay(250);
                        }

                      if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 1){
                       dMinute++;
                       Serial.println("dMinute");
                       Serial.println(dMinute);
                         delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 1){
                        dMinute--;
                        Serial.println("dMinute");
                        Serial.println(dMinute);
                         delay(250);
                        }
                         if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 2){
                       dSecond++;
                       Serial.println("dSecond");
                       Serial.println(dSecond);
                         delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 2){
                        dSecond--;
                        Serial.println("dSecond");
                        Serial.println(dSecond);
                         delay(250);
                        }
                        if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 3){
                        inHour++;
                        Serial.println("inHour");
                        Serial.println(inHour);
                        delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 3){
                        inHour--;
                         Serial.println("inHour");
                        Serial.println(inHour);
                         delay(250);
                        }

                      if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 4){
                       inMinute++;
                       Serial.println("inMinute");
                       Serial.println(inMinute);
                         delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 4){
                        inMinute--;
                        Serial.println("inMinute");
                        Serial.println(inMinute);
                         delay(250);
                        }
                         if (digitalRead(buttonRight) == 0 and numOfEntersPressed == 5){
                       inSecond++;
                        Serial.println("inSecond");
                       Serial.println(inSecond);
                         delay(250);
                        }

                      if (digitalRead(buttonLeft) == 0 and numOfEntersPressed == 5){
                        inSecond--;
                        Serial.println("inSecond");
                        Serial.println(inSecond);
                         delay(250);
                        }
             
                    if (digitalRead(buttonEnter) == 0){
                        numOfEntersPressed++;
                        delay(300);
                        }
             
             if (numOfEntersPressed == 6){
               if(isDone == 0){
                        Mode3(dHour,dMinute,dSecond,inHour,inMinute,inSecond);
               }
               else{
                     Serial.println("Done,pictures taken : ");
                    Serial.println(numOfPictures);
               }
                    
             }
      if ( numOfEntersPressed == 7 && isDone == 1){
                        N = 0;
                        menuPosition=0;
                        dHour = 0;
                        dMinute = 0;
                        dSecond = 0; 
                        inHour = 0;
                        inMinute = 0;
                        inSecond = 0;
                    numOfPictures = 0;
                isDone=0;
                numOfEntersPressed=0;
                Serial.println(dSecond);
                        }
                      break;
             default: menuPosition = 0;
                      break;         


    }
                              
}


void Mode1(int shutterSpeed,int N){
  
  for(int i=0;i<=N;i++){
    //relayConnect(shutterSpeed);
    Serial.println(i);
    
    
    }
  
  
  }
void Mode2(int N ){
    for(int i = 0; i<=N;i++){
      //close relay
      //open relay
       Serial.println(i);
      
      }
}



void Mode3(int dHour,int dMinute, int dSecond, int inHour, int inMinute, int inSecond ){
  uint32_t duration = (dHour*HOUR)+(dMinute*MINUTE)+(dSecond*SECOND);
  uint32_t interval = (inHour*HOUR)+(inMinute*MINUTE)+(inSecond*SECOND);
  for( uint32_t tStart = millis();  (millis()-tStart) < duration;  ){


      
    if ( digitalRead(buttonBack) == 0){
        break;
      }
      Serial.println("Pic taken");
      delay(interval);
      numOfPictures++;
    
  }
  
  isDone = 1;
  
  
  }      
  


  

  
