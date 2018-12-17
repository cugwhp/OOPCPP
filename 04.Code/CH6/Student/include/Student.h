#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using std::string;

// Attendance State
enum eAttendState
{
    AS_Attendance = 0,
    AS_Late = 1,
    AS_Absence = 2,
};

class Student
{
    public:
        Student(const string& strName);
        virtual ~Student();

        string getName() const;
        unsigned int getAttendanceCount(eAttendState eAs = AS_Attendance) const;
        float getAttendanceRate() const;
        void addOneRecord(eAttendState eAs);

    protected:
        string m_strName;   //Student Name
        unsigned int m_aryAttendance[3];    //Attendance count,[0]-Attendance,[1]-Late,[2]-Absence
    private:
};

#endif // STUDENT_H
