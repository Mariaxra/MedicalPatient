#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>
#include <string>
#include <vector>

class Patient
{
private:
    std::string name;
    int age;
    double BodyTemperature;
    int HeartRate;
    int RespiratoryRate;
    int BloodPressure;
    std::string encryptData(const std::string &data) const; 
   

public:
    Patient(std::string name, int age, double temp, int hr, int rr, int bp);
    ~Patient();
    void Print_Patient() const;
    std::string getEncryptedData() const;
   
};

#endif