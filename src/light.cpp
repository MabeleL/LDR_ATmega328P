#include "Arduino.h"

#define pinLight A0
#define pinLED 8
int thresholdvalue = 600;
const int time = 1000;
#define LDR A5

void setup(){
 Serial.begin(9600);
}

void loop(){
  int Max_ADC_Reading = 1023;
  int ADC_ref_Voltage = 5;
  int ref_resistance = 10;
  float Lux_Calc_Scalar = 12518931;
  float Lux_Exponent = -1.405;

  float value = analogRead(pinLight);
  float rawdata = analogRead(LDR);

  float resistorVoltage = rawdata /(Max_ADC_Reading * ADC_ref_Voltage);

 float ldrVoltage = ADC_ref_Voltage - resistorVoltage;

 float ldrResistance = ldrVoltage/(resistorVoltage * ref_resistance);

 float ldrLux = (Lux_Calc_Scalar * pow(ldrResistance, Lux_Exponent))/10000;


 Serial.println(value);
 delay(time);

 Serial.println(ldrLux);

 if(value < thresholdvalue)
 {
 digitalWrite(pinLED, HIGH);
 }
 else{
 digitalWrite(pinLED, LOW);
 }
}
