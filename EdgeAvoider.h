#include "SensorMap.h"

class EdgeAvoider{
    public:
    //A sensor map that maps three values of sensors as indexes to direction of robot
    //Mappings can be manipulated to desired effects. This mapping is configured for basic functionality using three sensors
    SensorMap sensormap;
    
    EdgeAvoider(){
        sensormap.SetValueAt(HIGH, LOW, LOW, "Left"); //Turn lefy
        sensormap.SetValueAt(HIGH, HIGH, LOW, "Left");
        
        sensormap.SetValueAt(LOW, LOW, HIGH, "Right");  //Turn right
        sensormap.SetValueAt(LOW, HIGH, HIGH, "Right"); 
        
        sensormap.SetValueAt(HIGH, LOW, HIGH, "Backward"); //Turn back
        sensormap.SetValueAt(HIGH, HIGH, HIGH, "Forward");
        sensormao.SetValueAt(LOW, HIGH, LOW, "Backward");
        
        sensormap.SetValueAt(LOW, LOW, LOW, "Backward"); //Move ahead
    
    }
    
    void StartCode(){
      Serial.print("leftsensorval = ");
      Serial.println(leftsensorval);
      Serial.print("rightsensorval = ");
      Serial.println(rightsensorval);
    
      leftsensorval = digitalRead(leftsensor);
      rightsensorval = digitalRead(rightsensor);
      midsensorval = digitalRead(midsensor);
      
      String action = sensormap.GetValueAt(leftsensorval, midsensorval, rightsensorval);
      if(action == "Forward"){DriveForward();}
      else if(action == "Backward"){DriveBackward(); delay(100); DriveLeft(); delay(50);}
      else if(action == "Left"){DriveLeft(); delay(200);}
      else if(action == "Right"){DriveRight; delay(200);}
      
    }
    
    void run(){
        while(true){
            StartCode();
        }
    }
};
