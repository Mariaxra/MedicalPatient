
#include "hospital.hpp"
#include <fstream>
#include <sstream>

void Hospital::Add_Patient(const Patient &patient)
{
    patients.push_back(patient);
}
void Hospital ::ReadFromFile()
{
    std :: ifstream file("patients_data.txt");
    if(!file.is_open())
    {
        std :: cerr <<"Error openning the file.\n";
        return;
    }
    std :: string Data;
    while(std :: getline(file , Data))
    {
        std :: string DecryptedLine = Data;
        char key = 'X';
        for(char &c : DecryptedLine)
        {
            c ^= key;
        }
        std :: stringstream ss(DecryptedLine);
        std :: string name ;
        int age , hr , rr , bp;
        double temp;
        std :: getline(ss , name , '|');
        std :: string A;
        std :: getline(ss , A , '|');
        age = std :: stoi(A);
        std :: getline(ss , A , '|');
        temp = std :: stod(A);
        std :: getline(ss , A , '|');
        hr = std :: stoi(A);
        std :: getline(ss , A , '|');
        rr = stoi(A);
        std :: getline(ss , A , '|');
        bp = std :: stoi(A);

        try{
           Patient P(name , age , temp , hr , rr , bp , true);
           Add_Patient(P);
        }
        catch(const std :: invalid_argument &e)
        {
            std :: cerr << "Skipped invalid Data"<<e.what() <<'\n';
        }
    }
    file.close();
}

void Hospital::Print() const
{
    for (const auto &patient : patients)
    {
        patient.Print_Patient();
        std::cout << "--------------------------\n";
    }
}
