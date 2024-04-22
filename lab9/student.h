#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string lastName;
    std::string firstName;
    std::string group;
    int studentID;

    Student() : lastName(""), firstName(""), group(""), studentID(0) {}

    Student(const std::string& lastName, const std::string& firstName, const std::string& group, int studentID)
        : lastName(lastName), firstName(firstName), group(group), studentID(studentID) {}
};

#endif
