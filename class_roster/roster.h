#ifndef C867_ROSTER_H
#define C867_ROSTER_H

#include "student.h"

class Roster {

public:

    // ---------------- Constructor & Destructor ---------------- //

    Roster ();
    ~Roster();

    // ---------------- Getter Functions ---------------- //

    std::string_view    getStudentID (int i);
    [[nodiscard]] int   getActiveStudents () const;

    // ---------------- Student Functions ---------------- //

    void addStudent     (const std::string& studentData);
    void removeStudent  (std::string_view studentID);

    // ---------------- Print Functions ---------------- //

    void printAvgCourseDuration (std::string_view studentID) const;
    void printAll () const;
    void printInvalidEmails () const;
    void printRosterDegree (Degree degree) const;

private:

    Student*    classRosterArray [5]{};
    int         activeStudents {};

};

#endif //C867_ROSTER_H
