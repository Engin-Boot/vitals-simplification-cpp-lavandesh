#include <assert.h>
#include <iostream>
using namespace std;

// Static Information (i.e. names, upper and lower values) of Vitals stored in the system
typedef struct vitalInfo
{
  char* vitalName;
  int high;
  int low;
};

vitalInfo spo2 = {"Blood oxygen", 90, 101};
vitalInfo bpm = {"BPM", 70, 150};
vitalInfo respRate = {"Respiratory rate", 30, 95};

struct vitalInfo infoArray[3] = {spo2, bpm, respRate};

//Alert type definations
class AlertType
{
    public:
    virtual void sendAlert(const char* vitalName, const char* message) = 0;

};

class AlertInSMS : AlertType
{
  public:
  void sendAlert(const char* vitalName, const char* message){
    std::cout << "SMS sent: " << vitalName << " " << message << std::endl;
  }
};

class AlertInAlarm : AlertType
{
  public:
    void sendAlert(const char* vitalName, const char* message){
      std::cout << "Alarm Sounded: " << vitalName << " " << message << std::endl;
  }
};



//Vital Checker - Checks each vital against safe limits
bool vitalIsOk(AlertType *alert, char* vitalname, float value, int low, int high){
  if (value<low)
  {
    alert->sendAlert(vitalname, "is low");
    return false;
  }

  else if (value>high)
  {
    alert->sendAlert(vitalname, "is high");
    return false;
  }

  else
    return true;
}
  

//Format of incoming Data
struct patientVitals{
  AlertType* alert;
  vitalInfo vital;
  float value;  
};

//Go through the list, populate upper and lower value, and send for check
bool patientIsOk (patientVitals* vitalList)
{
  bool status = true;
  for(int i = 0 ; i<sizeof(vitalList); i++)
  {
    if(!vitalIsOk(vitalList[i].alert, vitalList[i].vital.vitalName, vitalList[i].value, vitalList[i].vital.low, vitalList[i].vital.high))
    {
      status = false;
    }
  }
  return status;
}


int main() {

  AlertInSMS sms;
  AlertInAlarm alarm;

  //struct patientVitals patient1[3] ={ {&sms, bpm, 80}, }
  //assert(patientIsOk() == true);
  //assert(vitalsAreOk(60, 90, 40) == false);
  
  /*assert(anyVitalIsOk("vital", 10, 5, 15) == true); 
  assert(anyVitalIsOk("vital", 2, 5, 15) == false); 
  assert(anyVitalIsOk("vital", 20, 5, 15) == false); 
  
  assert(anyVitalIsOk("vital", 10,20, 1000)==false);
  assert(anyVitalIsOk("vital", 30,20, 1000)==true);
  
  assert(anyVitalIsOk("vital", 10, 50, 100) == false);
  assert(anyVitalIsOk("vital", 150, 50, 100) == false);
  assert(anyVitalIsOk("vital", 75, 50, 100) == true);
  */
  
}
