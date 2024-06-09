#include "SensorMap.h"

struct ThreeSensorVals{
    bool left_val = -1;
    bool mid_val = -1;
    bool right_val = -1;
    String value = "No Value";
};


class SensorMap{
    
    public:
    const int length = 8;
    struct ThreeSensorVals sensors[length];
    
    //keeps track of free indexes, didn't want to deal with shifting arrays and segmentation faults;
    int currently_available[27];
    
    
    SensorMap(){
        //Initialize availability here
        for(int i = 0; i < length; i++){
            currently_available[i] = i;
        }
    }
    
    int _get_free_index(){
        //Gives the next free index else returns -2;
        for(int i = 0; i < length; i++){
            if(currently_available[i] != -1){
                    return i;
            }
        }
        
        return -2;
    }
    bool SetValueAt(bool left, bool mid, bool right, String value){
        //Time complexity O(1) mostly -1 means index not available
        int index = currently_available[0];
        if(index == -1){
            index = _get_free_index();
            if(index == -2;){
                return false;
            }
        }
        sensors[index].left_val = left;
        sensors[index].right_val = right;
        sensors[index].mid_val = mid;
        currently_available[index] = -1;
        return true;
    }
    
    
    bool DeleteValueAt(bool left, bool, mid, bool right){
        //Time complexity O(n)
        for(int i = 0; i < length; i++){
            if(sensors[i].left_val == left && sensors[i].mid_val == mid && sensors[i].right_val == right){
                sensors[i].left_val = -1;
                sensors[i].mid_val = -1;
                sensors[i].right_val = -1;
                sensors[i].value = "No Value";
                currently_available[i] = i;
                return true;
            }
        }
        
        return false;
    }
    
    String GetValueAt(bool left, bool mid, bool right){
        //Time complexcity O(n)
        for(int i = 0; i < length; i++){
            if(sensors[i].left_val == left && sensors[i].mid_val == mid && sensors[i].right_val == right) return sensors[i].value;
        }
        
        String return_val = "None";
        return return_val;
    }
};
