#include "hospital.h"
#include <fstream>
#include <iostream>

void Hospital::addDepartment(const Department& department) {
    departments.push_back(department);
}

void Hospital::removeDepartment(const std::string& deptName) {
    for (auto it = departments.begin(); it != departments.end(); ++it) {
        if (it->getname() == deptName) {
            departments.erase(it);
            break;
        }
    }
}

void Hospital::addDoctor(const std::string& deptName, const Doctor& doctor) {
    for (auto& dept : departments) {
        if (dept.getname() == deptName) {
            dept.addDoctor(doctor);
            break;
        }
    }
}

void Hospital::removeDoctor(const std::string& deptName, const std::string& doctorName) {
    for (auto& dept : departments) {
        if (dept.getname() == deptName) {
            auto oldSize = dept.getdoctors().size();
            dept.removeDoctor(doctorName);
            if (dept.getdoctors().size() == oldSize) {
                std::cout << "Errot" << std::endl;
            }
            return;
        }
    }
    std::cout << "Error" << std::endl;
}

void Hospital::admitPatient(const Patient& patient, const std::string& deptName) {
    for (auto& dept : departments) {
        if (dept.getname() == deptName) {
            dept.addPatient(patient);
            allpatients.push_back(patient);
            break;
        }
    }
}

void Hospital::dischargePatient(const std::string& patientName, const std::string& deptName) {
    for (auto& dept : departments) {
        if (dept.getname() == deptName) {
            auto oldSize = dept.getpatients().size();
            dept.removePatient(patientName);
            if (dept.getpatients().size() == oldSize) {
                std::cout << "Error" << std::endl;
                return;
            }
            for (auto& patient : allpatients) {
                if (patient.getname1() + " " + patient.getname2() == patientName) {
                    patient.setstatus("discharged");
                    patient.setvday(0);
                    break;
                }
            }
            break;
        }
    }
}

void Hospital::skipDays(int days) {
    for (auto& patient : allpatients) {
        if (patient.getstatus() == "hospitalized") {
            patient.setgday(patient.getgday() + days);
            int newVday = patient.getvday() - days;
            if (newVday <= 0) {
                patient.setstatus("discharged");
                patient.setvday(0);
                for (auto& dept : departments) {
                    for (const auto& deptPatient : dept.getpatients()) {
                        if (deptPatient.getname1() + " " + deptPatient.getname2() ==
                            patient.getname1() + " " + patient.getname2()) {
                            dept.removePatient(patient.getname1() + " " + patient.getname2());
                            break;
                        }
                    }
                }
            }
            else {
                patient.setvday(newVday);
            }
        }
    }
}

void Hospital::printAllDepartments() const {
    for (const auto& dept : departments) {
        std::cout << "Отделение: " << dept.getname() << ", Мест: " << dept.getplace()
            << ", Свободно: " << dept.getfreeplace() << "\n";
        std::cout << "Врачи:\n";
        for (const auto& doctor : dept.getdoctors()) {
            std::cout << "  " << doctor.getname() << " (" << doctor.getspec() << ")\n";
        }
    }
}

void Hospital::printDepartmentDoctors(const std::string& departmentName) const {
    for (const auto& dept : departments) {
        if (dept.getname() == departmentName) {
            const auto& doctors = dept.getdoctors();
            if (doctors.empty()) {
                std::cout << "Error\n";
            }
            else {
                std::cout << "Врачи в отделении " << departmentName << ":\n";
                for (const auto& doc : doctors) {
                    std::cout << "- " << doc.getname() << " (" << doc.getspec() << ")\n";
                }
            }
            return;
        }
    }
    std::cout << "Error\n";
}

void Hospital::printDepartmentPatients(const std::string& deptName) const {
    for (const auto& dept : departments) {
        if (dept.getname() == deptName) {
            std::cout << "Пациенты в отделении " << deptName << ":\n";
            for (const auto& patient : dept.getpatients()) {
                std::cout << patient.getname1() << " " << patient.getname2() << " " << patient.getname3()
                    << ", Пол: " << patient.getgender() << ", Возраст: " << patient.getage()
                    << ", Диагноз: " << patient.getdiagnos() << ", Врач: " << patient.getdoctor()
                    << ", Статус: " << patient.getstatus() << ", Осталось дней: " << patient.getvday() << "\n";
            }
            break;
        }
    }
}

void Hospital::printAllPatients() const {
    std::cout << "Все пациенты:\n";
    for (const auto& patient : allpatients) {
        std::cout << patient.getname1() << " " << patient.getname2() << " " << patient.getname3()
            << ", Пол: " << patient.getgender() << ", Возраст: " << patient.getage()
            << ", Диагноз: " << patient.getdiagnos() << ", Врач: " << patient.getdoctor()
            << ", Статус: " << patient.getstatus() << ", Осталось дней: " << patient.getvday()
            << ", Дней в больнице: " << patient.getgday() << "\n";
    }
}

void Hospital::printHospitalizedPatients() const {
    std::cout << "Госпитализированные пациенты:\n";
    for (const auto& patient : allpatients) {
        if (patient.getstatus() == "hospitalized") {
            std::cout << patient.getname1() << " " << patient.getname2() << " " << patient.getname3()
                << ", Пол: " << patient.getgender() << ", Возраст: " << patient.getage()
                << ", Диагноз: " << patient.getdiagnos() << ", Врач: " << patient.getdoctor()
                << ", Осталось дней: " << patient.getvday() << "\n";
        }
    }
}

void Hospital::printDischargedPatients() const {
    std::cout << "Выписанные пациенты:\n";
    for (const auto& patient : allpatients) {
        if (patient.getstatus() == "discharged") {
            std::cout << patient.getname1() << " " << patient.getname2() << " " << patient.getname3()
                << ", Пол: " << patient.getgender() << ", Возраст: " << patient.getage()
                << ", Диагноз: " << patient.getdiagnos() << ", Врач: " << patient.getdoctor() << "\n";
        }
    }
}

void Hospital::saveToFile(const std::string& deptFile, const std::string& patientFile) const {
    std::ofstream deptOut(deptFile);
    if (deptOut.is_open()) {
        for (const auto& dept : departments) {
            deptOut << dept << "\n";
        }
        deptOut.close();
    }

    std::ofstream patientOut(patientFile);
    if (patientOut.is_open()) {
        for (const auto& patient : allpatients) {
            patientOut << patient << "\n";
        }
        patientOut.close();
    }
}

void Hospital::loadFromFile(const std::string& deptFile, const std::string& patientFile) {
    departments.clear();
    allpatients.clear();

    std::ifstream deptIn(deptFile);
    if (deptIn.is_open()) {
        Department dept;
        while (deptIn >> dept) {
            departments.push_back(dept);
        }
        deptIn.close();
    }

    std::ifstream patientIn(patientFile);
    if (patientIn.is_open()) {
        Patient patient;
        while (patientIn >> patient) {
            allpatients.push_back(patient);
            if (patient.getstatus() == "hospitalized") {
                for (auto& dept : departments) {
                    if (dept.getfreeplace() > 0) {
                        dept.addPatient(patient);
                        break;
                    }
                }
            }
        }
        patientIn.close();
    }
}
