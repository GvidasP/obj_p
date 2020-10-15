#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student
{
    std::string name;
    std::string surname;
    std::vector<int> marks;
    int exam;
    float final_mark_avg;
    float final_mark_med;
    std::string category;
    bool file;
};

#endif
