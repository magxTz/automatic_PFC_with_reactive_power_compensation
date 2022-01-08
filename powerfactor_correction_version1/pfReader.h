struct pf_data{
 float PF;
 float ANGLE;
 float PF_MAX = 0;
 float ANGLE_MAX = 0;
};

pf_data computePF(uint8_t p){
  for (ctr = 0; ctr <= 4; ctr++) // Perform 4 measurements then reset
  {
  // 1st line calculates the phase angle in degrees from differentiated time pulse
  // Function COS uses radians not Degree's hence conversion made by dividing angle / 57.2958
   angle = ((((pulseIn(p, HIGH)) * nano)* degree)* frequency);
  pf = cos(angle / rads);
  
   if (angle > angle_max) // Test if the angle is maximum angle
     {
      angle_max = angle; // If maximum record in variable "angle_max"
      pf_max = cos(angle_max / rads); // Calc PF from "angle_max"
     }
   }
   if (angle_max > 360) // If the calculation is higher than 360 do following...
   {
    angle_max = 0; // assign the 0 to "angle_max"
    pf_max = 1; // Assign the Unity PF to "pf_max"
   }
   if (angle_max == 0) // If the calculation is higher than 360 do following...
   {
    angle_max = 0; // assign the 0 to "angle_max"
    pf_max = 1; // Assign the Unity PF to "pf_max"
   }
   pf_data data;
   data.PF=pf;
   data.ANGLE=angle;
   data.PF_MAX=pf_max;
   data.ANGLE_MAX=angle_max;
   return data;
}
void showResult(pf_data d){
  Serial.print(d.ANGLE_MAX, 2); // Print the result
   Serial.print(",");
   Serial.println(d.PF_MAX, 2);
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("PF=");
   lcd.setCursor(4,0);
   lcd.print(d.PF_MAX);
   lcd.print(" ");
   lcd.setCursor(0,1);
   lcd.print("Ph-Shift=");
   lcd.setCursor(10,1);
   lcd.print(d.ANGLE_MAX);
   lcd.print(" ");
   
   // Reset variables for next test
   angle = 0; 
   angle_max = 0;
}
