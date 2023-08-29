#include <iostream>
#include "degree.h"
#include "roster.h"

int main()
{
    std::cout << "C867 - Scripting & Programming: Applications\n";
    std::cout << "Language: C++\n";
    std::cout << "Student ID: 010989340\n";
    std::cout << "Name: Brendan Delfortrie\n" << std::endl;

    const std::string studentData[] =
            {
                    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                    "A5,Brendan,Delfortrie,bdelfo1@wgu.edu,27,14,14,21,SOFTWARE"
            };

    auto* classRoster = new Roster;

    for (const auto & i : studentData)
    {
        classRoster->addStudent(i);
    }

    classRoster->printAll();
    std::cout << std::endl;

    classRoster->printInvalidEmails();
    std::cout << std::endl;

    std::cout << "Average Days in Course:\n\n";

    for (int i = 0; i < classRoster->getActiveStudents(); i++)
    {
        classRoster->printAvgCourseDuration(classRoster->getStudentID(i));
    }
    std::cout << std::endl;

    classRoster->printRosterDegree(Degree::software);
    std::cout << std::endl;

    classRoster->removeStudent("A3");
    std::cout << std::endl;

    classRoster->printAll();
    std::cout << std::endl;

    classRoster->removeStudent("A3");
    std::cout << std::endl;

    delete classRoster;
    classRoster = nullptr;

    return 0;
}