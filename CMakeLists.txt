cmake_minimum_required(VERSION 3.10)
project(MedicalPatient)

add_executable(medical_patient
    main.cpp
    patient.cpp
    hospital.cpp
)

include_directories(include)