#include <assert.h>
const int bpmLimits[] = {70, 150};
const int respRateLimits[] = {30, 95};
const int spo2Limit = 90;

//for vital with upper and lower value
bool anyVitalIsOk(float value, int low, int high){
  return (value>low && value<high);
}

//for vital with only cutoff
bool anyVitalIsOk(float value, int cutOff){
  return value>=cutOff;

  
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return ( anyVitalIsOk(bpm, bpmLimits[0], bpmLimits[1]) && anyVitalIsOk(spo2, spo2Limit) && anyVitalIsOk(respRate, respRateLimits[0], respRateLimits[1]));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  
  assert(anyVitalIsOk(10, 5, 15) == true); 
  assert(anyVitalIsOk(2, 5, 15) == false); 
  assert(anyVitalIsOk(20, 5, 15) == false); 
  
  assert(anyVitalIsOk(10,20)==false);
  assert(anyVitalIsOk(30,20)==true);
  
  assert(anyVitalIsOk(10, 50, 100) == false);
  assert(anyVitalIsOk(150, 50, 100) == false);
  assert(anyVitalIsOk(75, 50, 100) == true);
  
}
