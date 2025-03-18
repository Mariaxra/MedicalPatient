#include "patient.hpp"
#include <fstream>
#include <stdexcept>

Patient::Patient(std::string name, int age, double temp, int hr, int rr, int bp)
    : name(name), age(age), BodyTemperature(temp), HeartRate(hr), RespiratoryRate(rr), BloodPressure(bp)
{
    if (name.empty())
    {
        throw std ::invalid_argument("Error ! empty name is invaild.");
    }
    if (age < 0 || temp < 0 || hr < 0 || rr < 0 || bp < 0)
    {
        throw std ::invalid_argument("Error ! nagetive numbers aren't availiable");
    }

    if (temp < 36.0 || temp > 37.5)
    {
        std::cout << "Warning! Abnormal body temperature! Patient : " << name << '\n';
    }
    if (hr < 60 || hr > 100)
    {
        std::cout << "Warning! Abnormal heart rate! Patient : " << name << '\n';
    }
    if (age >= 50)
    {
        if (rr < 18 || rr > 25)
            std ::cout << "Warning! Abnormal respiratory rate! Patient : " << name << '\n';
    }
    else if (age > 10 && age < 50)
    {

        if (rr < 16 || rr > 20)
        {
            std::cout << "Warning! Abnormal respiratory rate! Patient : " << name << '\n';
        }
    }
    else if (age > 6 && age <= 10)
    {
        if (rr < 17 || rr > 23)
            std::cout << "Warning! Abnormal respiratory rate! Patient : " << name << '\n';
    }
    else if (age > 3 && age <= 6)
    {
        if (rr < 20 || rr > 30)
            std::cout << "Warning! Abnormal respiratory rate! Patient : " << name << '\n';
    }
    else if (age <= 3)
    {
        if (rr < 25 || rr > 40)
            std::cout << "Warning! Abnormal respiratory rate! Patient : " << name << '\n';
    }

    if (bp < 80 || bp > 120)
    {
        std::cout << "Warning! Abnormal blood pressure! Patient : " << name << '\n';
    }
}

Patient::~Patient()
{
    std::string encryptedData = getEncryptedData();
std::ofstream file("patients_data.txt", std::ios::app);
if (file.is_open())
{
    file << encryptedData << '\n';
    file.close();
}
   
}

void Patient::Print_Patient() const
{
    std::cout << "Name: " << name << '\n'
    << "Age: " << age << '\n'
    << "Temperature: "
    << BodyTemperature << "C\n"
    << "Heart Rate: " << HeartRate << " bpm\n"
    << "Respiratory Rate: " << RespiratoryRate << '\n'
    << "Blood Pressure: " << BloodPressure << '\n';
}
std::string Patient::encryptData(const std::string &data) const
{
    std::string encrypted = data;
    char key = 'X';
    for (char &c : encrypted)
    {
        c ^= key;
    }
    return encrypted;
}
std::string Patient::getEncryptedData() const
{
    std::string Data = name + "|" + std::to_string(age) + "|" +
    std::to_string(BodyTemperature) + "|" +
    std::to_string(HeartRate) + "|" +
    std::to_string(RespiratoryRate) + "|" +
    std::to_string(BloodPressure);

    return encryptData(Data);
}



