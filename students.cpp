#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "student.h"
#include "helper.h"

using std::cin;
using std::cout;

int main()
{
    std::vector<Student> students = readFile();

    int avg, n;

    Student student;

    cout << "Iveskite varda ir pavarde: ";
    cin >> student.name >> student.surname;

    cout << "Iveskite egzamino pazymi: ";
    cin >> student.exam;

    cout << "Iveskite pazymius: \n";
    while (cin >> n)
        student.marks.push_back(n);

    students.push_back(student);

    std::sort(students.begin(), students.end(), compareString);

    cout << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    cout << std::setfill('-') << std::setw(80) << "-" << std::setfill(' ') << std::endl;

    for (auto &s : students)
    {
        int sum_of_marks{};

        for (auto &i : s.marks)
            sum_of_marks += i;

        s.final_mark_avg = 0.4 * (sum_of_marks / s.marks.size()) + 0.6 * s.exam;
        s.final_mark_med = 0.4 * median(s.marks) + 0.6 * s.exam;

        cout << std::setw(15) << s.surname << std::setw(15) << s.name << std::setw(15) << s.final_mark_avg << std::setw(15) << s.final_mark_med << std::endl;
    }
}