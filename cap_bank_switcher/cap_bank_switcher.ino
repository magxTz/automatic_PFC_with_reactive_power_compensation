#include <Vector.h>
#include "capacitorSelector.h"
//int cap_pin[4]={13,12,11,10};float cap_vals[]={2.5,3.0,7.8,12.5};

typedef Vector <float> cap;
    const int arr_size=sizeof(cap_vals)/sizeof(cap_vals[0]);
    float cap_array[arr_size];
    cap Array;
void setup() {
Serial.begin(9600);
delay(1000);
for(int i=0;i<sizeof(cap_pin)/sizeof(cap_pin[0]);i++){
  pinMode(cap_pin[i],OUTPUT);
  digitalWrite(cap_pin[i],0);
}
    Array.setStorage(cap_array);
 
    for(int i=0;i<arr_size;i++){
      Array.push_back(cap_vals[i]);
    }

}

void loop() {
  if (Serial.available()>0){
    float data=Serial.readString().toFloat();
    float target=data;
    int n=Array.size();
    if(target==0){
      CBOFF();
    }
    else{
        Vector <int> required_cap_indices=capacitors_making_a_target(Array,n,target,1);
        switchCapacitorBank(required_cap_indices);
    }

  }

}
