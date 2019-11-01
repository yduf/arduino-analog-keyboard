#include <Arduino.h>

/* RobotDyn Keypad 3x4
   0 - 3
   4 - 7  => connnector on the right
   8 - 11 */ 
void setup() { Serial.begin(9600); } 

// decision table for 5v input
int GetButtonNumber(int value) { 
   if(value > 975) return 3; 
   if(value > 890) return 7; 
   if(value > 820) return 11; 
   if(value > 760) return 2; 
   if(value > 705) return 6; 
   if(value > 660) return 10; 
   if(value > 620) return 1; 
   if(value > 585) return 5; 
   if(value > 555) return 9; 
   if(value > 525) return 0; 
   if(value > 500) return 4; 
   if(value > 480) return 8; 
   return -1; 
}

void loop() { 
    int keyPress = analogRead(0); 
    int button = GetButtonNumber(keyPress); 
    
    if (button >= 0) { 
    	Serial.print(button); 
        Serial.print(": "); 
        Serial.println(keyPress); 
    } 
    else if( keyPress > 0) {
        Serial.print("no btn: "); 
        Serial.print(": "); 
        Serial.println(keyPress);     
    }
    
    delay(200); 
}
