#ifndef C867_STUDENT_H
#define C867_STUDENT_H

#include "degree.h"

class Student {

public:

    // ---------------- Constructor Declaration ---------------- //

    Student
    (
            std::string_view  studentID = "",
            std::string_view  firstName = "",
            std::string_view  lastName = "",
            std::string_view  emailAddress = "",
            int               age = 0,
            int               courseArray1 = 0,
            int               courseArray2 = 0,
            int               courseArray3 = 0,
            Degree            degree = Degree::unknown
            );

    // ---------------- Getter Functions ---------------- //

    [[nodiscard]] std::string_view  getStudentID () const;
    [[nodiscard]] std::string_view  getFirstName () const;
    [[nodiscard]] std::string_view  getLastName () const;
    [[nodiscard]] std::string_view  getEmailAddress() const;
    [[nodiscard]] int               getAge () const;
    [[nodiscard]] int               getCourseDuration (int i) const;
    [[nodiscard]] Degree            getDegree () const;

    // ---------------- Setter Functions ---------------- //

    void setStudentID       (std::string_view studentID);
    void setFirstName       (std::string_view fName);
    void setLastName        (std::string_view LName);
    void setEmailAddress    (std::string_view email);
    void setAge             (int age);
    void setCourseDuration  (int index, int value);
    void setDegree          (Degree d);

    // ---------------- Print Functions ---------------- //

    void printStudentID () const;
    void printFirstName () const;
    void printLastName () const;
    void printEmailAddress() const;
    void printAge () const;
    void printCourseDuration () const;
    void printDegree () const;
    void printAll () const;

private:

    std::string  studentID {};
    std::string  firstName {};
    std::string  lastName {};
    std::string  emailAddress {};
    int          age {};
    int          courseDuration [3];
    Degree       degree {};

};

#endif //C867_STUDENT_H

