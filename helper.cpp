#include "helper.h"
#include "student.h"

#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iterator>
#include <chrono>

int median(const std::vector<int> & numbers)
{
    int size = numbers.size(); // vectors know how many elements they have
    std::vector<int> copy = numbers; // we copy the vector into a local, that we will modify later, leaving numbers unchanged
    std::sort(copy.begin(), copy.end()); // sort is a std:: function
    return (size % 2) ? // this is a single expression that chooses from two subexpressions. It is called (the) "ternary operator" (ternary being of three parameters)
        copy[size/2] : // even
        (copy[size/2] + copy[(size/2) - 1])/2; // odd
}

bool compareString(Student &a, Student &b)
{
    return a.name < b.name;
}

std::list<Student> sortStudents(std::list<Student> students) {
    auto start = std::chrono::steady_clock::now();

    std::list<Student> vargsiukai;

    // std::partition_copy(students.begin(), students.end(), vargsiukai.begin(), kietekai.begin(), [](Student s){return s.final_mark_avg < 5;});

    //std::partition_copy(begin(students), end(students), back_inserter(vargsiukai), back_inserter(kietekai), [](Student s){ return s.final_mark_avg < 5; });

    std::remove_copy_if(begin(students), end(students), back_inserter(vargsiukai), [](Student s){ return s.final_mark_avg < 5; });

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Studentu rusiavimas i 2 kategorijas uztruko: " << elapsed_seconds.count() << "\n";

    return vargsiukai;
}

std::list<Student> readFile()
{
    try
    {
        auto start = std::chrono::steady_clock::now();

        std::ifstream ifs("studentai1000000.txt");
        if (!ifs.is_open())
        {
            throw ("Failas neegzistuoja.");
        }
        std::list<Student> students;
        std::string line;

        std::getline(ifs, line);
        while (std::getline(ifs, line))
        {
            std::istringstream iss(line);
            std::istream_iterator<std::string> begin(iss), end;
            std::vector<std::string> tokens(begin, end);

            Student stu;
            int temp = 2;

            stu.name = tokens[0];
            stu.surname = tokens[1];

            if(tokens.size() < 10)
                throw "Masyvas per trumpas.";

            for (int i = 0; i < 7; i++)
            {
                stu.marks.push_back(stoi(tokens[temp]));
                temp++;
            }
            stu.exam = stoi(tokens[7]);
            temp = 2;
            students.push_back(stu);
        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Failo nuskaitymas uztruko: " << elapsed_seconds.count() << "\n";

        return students;
    }

    catch (const char* e)
    {
        std::cout << "Exception: " << e << "\n";
    }
}
