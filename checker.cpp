#include <assert.h>
const int bpmLimits[] = {70, 150};
const int respRateLimits[] = {30, 95};
const int spo2Limit = 90;

bool BpmIsOk(float bpm ,int low, int high){
  return (bpm > low && bpm < high );
}

bool SpO2isOk(float spo2, int cutOff){
  return spo2>=cutOff;
}
  
bool respRateIsOk(float respRate, int low, int high){
  return (respRate > low && respRate < high);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return ( BpmIsOk(bpm, bpmLimits[0], bpmLimits[1]) && SpO2isOk(spo2, spo2limit) && respRateIsOk(respRate, respRateLimits[0], respRateLimits[1]));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  
  assert(BpmIsOk(10, 5, 15) == true); 
  assert(BpmIsOk(2, 5, 15) == false); 
  assert(BpmIsOk(20, 5, 15) == false); 
  
  assert(SpO2isOk(10,20)==false);
  assert(SpO2isOk(30,20)==true);
  
  assert(respRateIsOk(10, 50, 100) == false);
  assert(respRateIsOk(150, 50, 100) == false);
  assert(respRateIsOk(75, 50, 100) == true);
  
}
