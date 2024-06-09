#include "SensorMap.h"

class ObstacleAvoider{
    public:
    //A sensor map that maps three values of sensors as indexes to direction of robot
    //Mappings can be manipulated to desired effects. This mapping is configured for basic functionality using three sensors
    SensorMap sensormap;
    
    ObstacleAvoider(){
        sensormap.SetValueAt(HIGH, LOW, LOW, "Right"); //Turn Right
        sensormap.SetValueAt(HIGH, HIGH, LOW, "Right");
        
        sensormap.SetValueAt(LOW, LOW, HIGH, "Left");  //Turn Left
        sensormap.SetValueAt(LOW, HIGH, HIGH, "Left"); 
        
        sensormap.SetValueAt(HIGH, LOW, HIGH, "Backward"); //Turn back
        sensormap.SetValueAt(HIGH, HIGH, HIGH, "Backward");
        sensormao.SetValueAt(LOW, HIGH, LOW, "Backward");
        
        sensormap.SetValueAt(LOW, LOW, LOW, "Forward"); //Move ahead
    
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
      if(action == "Forward") DriveForward();
      else if(action == "Backward") DriveBackward();
      else if(action == "Left") DriveLeft();
      else if(action == "Right") DriveRight;
      
    }
    
    void run(){
        while(true){
            StartCode();
        }
    }
};
