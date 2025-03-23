
#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "patient.hpp"
#include <vector>

class Hospital
{
private:
    std::vector<Patient> patients;

public:
    void Add_Patient(const Patient &patient);
    void Print() const;
    void ReadFromFile();
 
};

#endif