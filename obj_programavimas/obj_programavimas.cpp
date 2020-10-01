#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;

struct Student {
    string name;
    string surname;
    std::vector<int> marks;
    int exam;
    float final_mark_avg;
    float final_mark_med;
};

int median(std::vector<int> data) {
    const auto middleItr = data.begin() + data.size() / 2;
    std::nth_element(data.begin(), middleItr, data.end());
    if (data.size() % 2 == 0) {
        const auto leftMiddleItr = std::max_element(data.begin(), middleItr);
        return (*leftMiddleItr + *middleItr) / 2;
    }
    else {
        return *middleItr;
    }
}

std::vector<Student> readFile() {
    std::ifstream ifs("kursiokai.txt");
    if (!ifs.is_open()) {
        std::exit(EXIT_FAILURE);
    }
    std::vector<Student> students;
    string line;

    std::getline(ifs, line);
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::istream_iterator<string> begin(iss), end;
        std::vector<std::string> tokens(begin, end);

        Student stu;
        int temp = 2;

        stu.name = tokens[0];
        stu.surname = tokens[1];
        for (int i = 0; i < 5; i++) {
            stu.marks.push_back(stoi(tokens[temp]));
            temp++;
        }
        stu.exam = stoi(tokens[7]);
        temp = 2;
        students.push_back(stu);
    }

    return students;
}

bool compareString(Student &a, Student &b) {
    return a.name < b.name;
}


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

    for (auto& s : students) {
        int sum_of_marks{};

        for (auto& i : s.marks)
            sum_of_marks += i;

        s.final_mark_avg = 0.4 * (sum_of_marks / s.marks.size()) + 0.6 * s.exam;
        s.final_mark_med = 0.4 * median(s.marks) + 0.6 * s.exam;

        cout << std::setw(15) << s.surname << std::setw(15) << s.name << std::setw(15) << s.final_mark_avg << std::setw(15) << s.final_mark_med << std::endl;

    }
}