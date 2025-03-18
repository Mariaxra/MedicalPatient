#include "hospital.hpp"
#include "patient.hpp"
#include <iostream>

int main()
{
    Hospital hospital;

    hospital.Add_Patient(Patient("Mary", 25, 39.99, 70, 18, 110));
    hospital.Add_Patient(Patient("jack", 40, 38.2, 120, 22, 130));
    hospital.Add_Patient(Patient("leo", 30, 37.0, 80, 19, 115));
    // hospital.Add_Patient(Patient("" , 60 , 34 , 36 , 30 , 100)); // Error for empty
    // hospital.Add_Patient(Patient("asal" , -12 , 34 , 36 , 30 , 100)); // Error for non-posetive data



    std::cout << "Patient List:\n";
    hospital.Print();

    return 0;
}