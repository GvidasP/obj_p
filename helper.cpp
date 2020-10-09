#include "helper.h"
#include "student.h"

#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iterator>

int median(std::vector<int> data)
{
    const auto middleItr = data.begin() + data.size() / 2;
    std::nth_element(data.begin(), middleItr, data.end());
    if (data.size() % 2 == 0)
    {
        const auto leftMiddleItr = std::max_element(data.begin(), middleItr);
        return (*leftMiddleItr + *middleItr) / 2;
    }
    else
    {
        return *middleItr;
    }
}

bool compareString(Student &a, Student &b)
{
    return a.name < b.name;
}

std::vector<Student> readFile()
{
    try
    {
        std::ifstream ifs("kursiokai.txt");
        if (!ifs.is_open())
        {
            throw ("Failas neegzistuoja.");
        }
        std::vector<Student> students;
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

            if(tokens.size() < 13)
                throw "Masyvas per trumpas.";

            for (int i = 0; i < 14; i++)
            {
                stu.marks.push_back(stoi(tokens[temp]));
                temp++;
            }
            stu.exam = stoi(tokens[7]);
            temp = 2;
            students.push_back(stu);
        }

        return students;
    }

    catch (const char* e)
    {
        std::cout << "Exception: " << e << "\n";
    }
}
