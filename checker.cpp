#include <assert.h>

bool BpmIsOk(float bpm){
  return (bpm > 70 && bpm < 150);
}

bool SpO2isOk(float spo2){
  return spo2>=90;
}
  
bool respRateIsOk(float respRate){
  return (respRate > 30 && respRate < 95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if ( BpmIsOk(bpm) && SpO2isOk(spo2) && respRateIsOk(respRate) )
    return true;
  else 
    return false;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
