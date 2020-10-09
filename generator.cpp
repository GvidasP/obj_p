#include "student.h"
#include "helper.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <iomanip>

std::vector<int> generateRandomMarks(int number)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<int> marks(number);
    std::uniform_int_distribution<> dis(1, 10);
    std::generate(marks.begin(), marks.end(), [&](){ return dis(gen); });
    return marks;
}

int sumOfMarks (std::vector<int> marks)
{
    int sum_of_marks{};

    for (auto &i : marks)
        sum_of_marks += i;

    return sum_of_marks;
}

float calculateAvg(std::vector<int> marks, int exam)
{
    return 0.4 * (sumOfMarks(marks) / marks.size()) + 0.6 * exam;
}

float calculateMedian(std::vector<int> marks, int exam)
{
    return 0.4 * median(marks) + 0.6 * exam;
}

std::vector<Student> generateStudents(int amount)
{
    std::vector<Student> students;

    for(int i = 0; i < amount; i++) {
        Student student;

        student.name = "Vardas" + std::to_string(i);
        student.surname = "Pavarde" + std::to_string(i);
        student.marks = generateRandomMarks(13);
        student.exam = rand() % 10 + 1;
        student.final_mark_avg = calculateAvg(student.marks, student.exam);
        student.final_mark_med = calculateMedian(student.marks, student.exam);

        std::cout << student.name << "\n";

        students.push_back(student);
    }

    return students;
}

std::ostream& operator<< (std::ostream& strm, const Student& s)
{
    return strm << std::setw(15) << s.surname << std::setw(15) << s.name << std::setw(15) << s.final_mark_avg << std::setw(15) << s.final_mark_med << std::endl;
}

void writeStudents(int amount)
{
    std::vector<Student> students = generateStudents(amount);

    std::string file_name = "studentai" + std::to_string(students.size()) + ".txt";
    std::ofstream students_file(file_name);

    for(const Student& s : students)
    {
        students_file << s;
    }

    std::cout << "Studentai sekmingai irasyti.";
}
