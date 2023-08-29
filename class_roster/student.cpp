#include <iostream>
#include "student.h"

// ---------------- Constructor ---------------- //

Student::Student
        (
                std::string_view  passStudentID,
                std::string_view  passFirstName,
                std::string_view  passLastName,
                std::string_view  passEmailAddress,
                int               passAge,
                int               passCourseArray1,
                int               passCourseArray2,
                int               passCourseArray3,
                Degree            passDegree
        )
        : studentID       (passStudentID),
          firstName       (passFirstName),
          lastName        (passLastName),
          emailAddress    (passEmailAddress),
          age             (passAge),
          courseDuration  {passCourseArray1,passCourseArray2,passCourseArray3},
          degree          (passDegree)
        {
        }

// ---------------- Getter Functions ---------------- //

std::string_view Student::getStudentID() const
{
    return studentID;
}

std::string_view Student::getFirstName() const
{
    return firstName;
}

std::string_view Student::getLastName() const
{
    return lastName;
}

std::string_view Student::getEmailAddress() const
{
    return emailAddress;
}

int Student::getAge() const
{
    return age;
}

int Student::getCourseDuration(int i = 0) const
{
    if (i < 0 || i  >= std::size(courseDuration))
        return 0;

    return courseDuration[i];
}

Degree Student::getDegree() const
{
    using enum Degree;

    switch (degree)
    {
        case security:
            return security;
            break;
        case network:
            return network;
            break;
        case software:
            return software;
            break;
        case unknown:
        default:
            return unknown;
            break;
    }
}

// ---------------- Setter Functions ---------------- //

void Student::setStudentID(std::string_view ID)
{
    studentID = std::string(ID);
}

void Student::setFirstName(std::string_view fName)
{
    firstName = std::string(fName);
}

void Student::setLastName(std::string_view lName)
{
    lastName = std::string(lName);
}

void Student::setEmailAddress(std::string_view email)
{
    emailAddress = std::string(email);
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setCourseDuration(int index, int value)
{
    if (index < 0 || index >= std::size(courseDuration))
        return;

    courseDuration[index] = value;
}

void Student::setDegree(Degree d)
{
    using enum Degree;

    switch (d)
    {
        case security:
            degree = security;
            break;
        case network:
            degree = network;
            break;
        case software:
            degree = software;
            break;
        case unknown:
            break;
        default:
            degree = unknown;
    }
}

// ---------------- Print Functions ---------------- //

void Student::printStudentID() const
{
    std::cout << studentID;
}

void Student::printFirstName() const
{
    std::cout << firstName;
}

void Student::printLastName() const
{
    std::cout << lastName;
}

void Student::printEmailAddress() const
{
    std::cout << emailAddress;
}

void Student::printAge() const
{
    std::cout << age;
}

void Student::printCourseDuration() const
{
    std::cout << "{ ";

    for (const auto &i: courseDuration) {
        std::cout << i << ", ";
    }

    std::cout << "}";
}

void Student::printDegree() const
{
    using enum Degree;

    switch (degree)
    {
        case security:
            std::cout << "security";
            break;
        case network:
            std::cout << "network";
            break;
        case software:
            std::cout << "software";
            break;
        case unknown:
        default:
            std::cout << "unknown";
            break;
    }
}

void Student::printAll() const
{
    printStudentID();
    std::cout << "   First Name: ";
    printFirstName();
    std::cout << "   Last Name: ";
    printLastName();
    std::cout << "   Email Address: ";
    printEmailAddress();
    std::cout << "   Age: ";
    printAge();
    std::cout << "   Course Duration (days): ";
    printCourseDuration();
    std::cout << "   Degree Program: ";
    printDegree();
    std::cout << std::endl;
}
