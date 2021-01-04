#define buttonDown     2
#define buttonUp       3
#define buttonLeft     4
#define buttonRight    5
#define buttonEnter    6
#define buttonBack     7
int menuPosition =     0; 
int shutterSpeed = 0;
int N = 0;
int numOfEntersPressed = 0;

 void setup() {

 pinMode(buttonDown, INPUT_PULLUP);
 pinMode(buttonUp, INPUT_PULLUP);
 pinMode(buttonLeft, INPUT_PULLUP);
 pinMode(buttonRight, INPUT_PULLUP);
 pinMode(buttonEnter, INPUT_PULLUP);
 pinMode(buttonBack, INPUT_PULLUP);
 Serial.begin(9600);

}

void loop() {
if (digitalRead(buttonDown) == 0){
    menuPosition ++;
    Serial.println(menuPosition);
    delay(250);
    }

  if (digitalRead(buttonUp) == 0){
    menuPosition --;
    Serial.println(menuPosition);
    delay(250);
    }

    switch(menuPosition){
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
             case 3 : Serial.println("Mode3");
                      menuPosition = 0;
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



void Mode2(int duration,int interval){
  
  
  }      

  
