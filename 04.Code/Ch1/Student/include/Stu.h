#ifndef STU_H
#define STU_H

#include <iostream>
#include <string>
#include <vector>

class Stu
{
public:
    Stu();
    virtual ~Stu();

    friend std::ostream& operator<<(std::ostream& os, const Stu& s);
    friend std::istream& operator>>(std::istream& is, Stu& s);

protected:
    void calcGPA();

private:
    std::string  strName; //Student Name
    std::string  strId;  //Student Id
    std::vector<int> vScores;    //Scores
    float   GPA;
};

#endif // STU_H
