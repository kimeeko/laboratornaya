#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <vector>
#include <string>
#include "department.h"
#include "patient.h"

class Hospital {
private:
    std::vector<Department> departments;
    std::vector<Patient> allpatients;

public:
    void addDepartment(const Department& department);
    void removeDepartment(const std::string& deptName);
    void addDoctor(const std::string& deptName, const Doctor& doctor);
    void removeDoctor(const std::string& deptName, const std::string& doctorName);
    void admitPatient(const Patient& patient, const std::string& deptName);
    void dischargePatient(const std::string& patientName, const std::string& deptName);
    void skipDays(int days);
    void printAllDepartments() const;
    void printDepartmentDoctors(const std::string& departmentName) const;
    void printDepartmentPatients(const std::string& deptName) const;
    void printAllPatients() const;
    void printHospitalizedPatients() const;
    void printDischargedPatients() const;
    void saveToFile(const std::string& deptFile, const std::string& patientFile) const;
    void loadFromFile(const std::string& deptFile, const std::string& patientFile);
    const std::vector<Department>& getDepartments() const { return departments; }
    std::vector<Department>& getDepartments() { return departments; }
    std::vector<Patient>& getPatients() { return allpatients; }
};

#endif