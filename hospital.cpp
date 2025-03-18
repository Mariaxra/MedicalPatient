
#include "hospital.hpp"

void Hospital::Add_Patient(const Patient &patient)
{
    patients.push_back(patient);
}

void Hospital::Print() const
{
    for (const auto &patient : patients)
    {
        patient.Print_Patient();
        std::cout << "--------------------------\n";
    }
}