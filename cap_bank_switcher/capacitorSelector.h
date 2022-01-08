float cap_vals[]={2.5,3.0,7.8,12.5};
int cap_pin[]={13,12,11,10};

float getNearest(float x,float y, float target){
  if(target-x >= y-target)
    return y;
   else
    return x;
}

float getNearestElement(Vector <float> arr,int n, float target){
  if(target <= arr[0]){
    return arr[0];
  }
  if(target>=arr[n-1]){
    return arr[n-1];
  }
  int left=0,right=n,mid=0;
  while(left<right){
    mid=(left+right)/2;
    if(arr[mid]==target){
      return arr[mid];
    }
    if (target<arr[mid]){
      if(mid>0 && target> arr[mid-1]){
        return getNearest(arr[mid-1],arr[mid],target);
   
      }
      right=mid;
      }
    else{
      if(mid < n-1 && target<arr[mid+1]){
        return getNearest(arr[mid],arr[mid+1],target);
      }
      left=mid+1;
      }
    }
    return arr[mid];
  }

  int getIndex(Vector <float> arr, float key){
      int len=arr.size();
      for(int i=0;i<len;i++){
        if (arr[i]==key)
          return i;
    }
  }



  Vector <int> capacitors_making_a_target(Vector <float> arr,int n, float target,bool debug=0){
    float diff=1;
    typedef Vector <int> cap_indices;
    const int ind_len=10;
    int cap_ind_storage_array[ind_len];
    cap_indices indicesArray;
    indicesArray.setStorage(cap_ind_storage_array);


    typedef Vector <float> copy;
    copy arrCopy;
    const int arr_size=sizeof(cap_vals)/sizeof(cap_vals[0]);
    float cparr[arr_size];
    arrCopy.setStorage(cparr);
    for(int i=0;i<arr.size();i++){
      arrCopy.push_back(arr[i]);
    }
       
    while(diff>0&&arrCopy.size()>0){
      int nCopy=arrCopy.size(); 
      float closest=getNearestElement(arrCopy,nCopy,target);
      if(debug){
        Serial.print("target is ");
        Serial.print(target);
        Serial.print(" and the closest value is ");
        Serial.println(closest);
      }
      diff=target-closest;
      target=diff;
      indicesArray.push_back(getIndex(arr,closest));
      arrCopy.remove(getIndex(arrCopy,closest));
      


    }
    for (int i=0;i<indicesArray.size();i++){
      if(debug){
        Serial.print("switch Capacitor Number ");
        Serial.println(indicesArray[i]+1);
      }
    }
    return indicesArray;
  }
  void CBOFF(){
    for(int i=0;i<sizeof(cap_pin)/sizeof(cap_pin[0]);i++){
    //switching off all caps 
    digitalWrite(cap_pin[i],0);
  }
  }

  void switchCapacitorBank(Vector <int> rqc_ap){
  CBOFF();
  for(int i=0;i<rqc_ap.size();i++)
    digitalWrite(cap_pin[rqc_ap[i]],1);
}
