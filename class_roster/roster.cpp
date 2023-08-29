#include <iostream>
#include "roster.h"
#include "student.h"

// ---------------- Constructor ---------------- //

Roster::Roster(  )
{
    for (auto & i : classRosterArray) {
        i = new Student();
    }
}

// ---------------- Destructor ---------------- //

Roster::~Roster() {
    for (int i = 0; i < activeStudents; ++i) {
        delete classRosterArray[i];
    }
}

// ---------------- Getter Functions ---------------- //

std::string_view Roster::getStudentID (int i)
{
    return classRosterArray[i]->getStudentID();
};

int Roster::getActiveStudents() const
{
    return activeStudents;
}

// ---------------- Enum To String ---------------- //

std::string degreeToString(Degree degree)
{
    using enum Degree;

    switch(degree)
    {
        case security:
            return "Security";
            break;
        case network:
            return "Network";
            break;
        case software:
            return "Software";
            break;
        case unknown:
        default:
            return "Unknown";
            break;
    }
}

// ---------------- Student Functions ---------------- //

void Roster::addStudent (const std::string& studentData )
{
        size_t rhs = studentData.find(',');
        std::string pStudentID = studentData.substr(0, rhs);
        classRosterArray[activeStudents]->setStudentID(pStudentID);

        size_t lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        std::string pFirstName = studentData.substr(lhs, rhs - lhs);
        classRosterArray[activeStudents]->setFirstName(pFirstName);

        lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        std::string pLastName = studentData.substr(lhs, rhs - lhs);
        classRosterArray[activeStudents]->setLastName(pLastName);

        lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        std::string pEmailAddress = studentData.substr(lhs, rhs - lhs);
        classRosterArray[activeStudents]->setEmailAddress(pEmailAddress);

        lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        int pAge = stoi(studentData.substr(lhs, rhs - lhs));
        classRosterArray[activeStudents]->setAge(pAge);

        lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        int pCourseArray1 = stoi(studentData.substr(lhs, rhs - lhs));
        classRosterArray[activeStudents]->setCourseDuration(0, pCourseArray1);

        lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        int pCourseArray2 = stoi(studentData.substr(lhs, rhs - lhs));
        classRosterArray[activeStudents]->setCourseDuration(1, pCourseArray2);

        lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        int pCourseArray3 = stoi(studentData.substr(lhs, rhs - lhs));
        classRosterArray[activeStudents]->setCourseDuration(2, pCourseArray3);

        lhs = rhs + 1;
        rhs = studentData.find(',', lhs);
        std::string pDegree = studentData.substr(lhs, rhs - lhs);
        if (pDegree == "SECURITY")
        {
            classRosterArray[activeStudents]->setDegree(Degree::security);
        }
        else if (pDegree == "NETWORK")
        {
            classRosterArray[activeStudents]->setDegree(Degree::network);
        }
        else if (pDegree == "SOFTWARE")
        {
            classRosterArray[activeStudents]->setDegree(Degree::software);
        }
        else
        {
            classRosterArray[activeStudents]->setDegree(Degree::unknown);
        }
    activeStudents++;
}

void Roster::removeStudent (std::string_view studentID) {

    int deletedStudent = 0;

    for (int i = 0; i < activeStudents; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            delete classRosterArray[i];

            for (int j = i; j < activeStudents; j++)
            {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[activeStudents - 1] = nullptr;
            activeStudents--;
            i--;
            deletedStudent++;
            std::cout << "Removed Student: " << studentID << "\n";
        }
    }
    if (deletedStudent == 0)
    {
        std::cout << "No student exists with ID: " << studentID;
    }
}

bool isValidEmail(std::string_view email)
{
    return
    email.find(' ') == std::string::npos &&
    email.find('@') != std::string::npos &&
    email.find('.') != std::string::npos;
}

// ---------------- Print Functions ---------------- //

void Roster::printAll() const
{
    std::cout << "Current Students:\n\n";

    for (int i = 0; i < activeStudents; ++i)
    {
        classRosterArray[i]->printAll();
    }
}

void Roster::printAvgCourseDuration(std::string_view studentID) const
{
    int avgCourseDuration {};
    int courseCount {3};

    for (int i = 0; i < activeStudents; i++)
    {
        if (studentID == classRosterArray[i]->getStudentID())
        {
            for (int j = 0; j < courseCount; j++)
            avgCourseDuration = avgCourseDuration + classRosterArray[i]->getCourseDuration(j) ;
        }
    }
    std::cout << studentID << " - " << avgCourseDuration / courseCount << " average days per course\n";
}

void Roster::printInvalidEmails() const
{
    std::cout << "Invalid Email Address(s):\n\n";
    for (int i = 0; i < activeStudents; i++)
    {
        std::string_view email = classRosterArray[i]->getEmailAddress();

        if (!isValidEmail(email))
        {
            std::cout << classRosterArray[i]->getStudentID() << " - " << email <<  "\n";
        }
    }
}

void Roster::printRosterDegree (Degree degree) const
{
    std::cout << "Students in Degree Program = " << degreeToString(degree) << ":\n\n";

    for (int i = 0; i < activeStudents; i++)
    {
        if (classRosterArray[i]->getDegree() == degree)
        {
            classRosterArray[i]->printAll();
        }
    }
}