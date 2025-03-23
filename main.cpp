#include "hospital.hpp"
#include "patient.hpp"
#include <iostream>
using namespace std;

int main()
{
    Hospital hospital;
    hospital.ReadFromFile();
    string command =""; // we have add , and print command.
    while(command != "logout")
    {
        cout << "Enter command : ";
        cin >> command;
        if(command=="add")
        {
            string name;
            int age , hr , rr , bp;
            double temp;
            cout << "Enter name :";
            cin >> name;
            cout << "Enter age :";
            cin >> age; 
            cout << "Enter tempeture : ";
            cin >> temp;
            cout << "Enter Heart Rate :";
            cin >> hr;
            cout << "Enter Respiratory Rate :";
            cin >> rr;
            cout << "Enter BloodPressure :";
            cin >> bp;
            hospital.Add_Patient(Patient(name , age , temp , hr , rr , bp , false ));
            
        }
        if(command == "print")
        {
            
    std::cout << "Patient List:\n";
    hospital.Print();

        }

    }

    // hospital.Add_Patient(Patient("" , 60 , 34 , 36 , 30 , 100)); // Error for empty
    // hospital.Add_Patient(Patient("asal" , -12 , 34 , 36 , 30 , 100)); // Error for non-posetive data

    return 0;
}