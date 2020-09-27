#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

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


int main()
{
    std::string name;
    std::string surname;
    std::string line;
    int n;
    int avg;
    std::vector<int> marks;
    int exam;
    float final_mark;

    cout << "Iveskite varda ir pavarde: ";
    cin >> name >> surname;

    cout << "Iveskite egzamino pazymi: ";
    cin >> exam;

    cout << "Isvesti vidurki ar mediana? (1/2)";
    cin >> avg;
    
    cout << "Iveskite pazymius: \n";
    while (cin >> n)
        marks.push_back(n);

    int sum_of_marks{};

    for (auto& i : marks)
        sum_of_marks += i;

    if (avg == 1) {
        final_mark = 0.4 * (sum_of_marks / marks.size()) + 0.6 * exam;
        cout << "Vardas Pavarde Galutinis (Vid.)" << std::endl;
        cout << name << " " << surname << " " << final_mark;
    }

    else {
        final_mark = 0.4 * median(marks) + 0.6 * exam;
        cout << "Vardas Pavarde Galutinis (Med.)" << std::endl;
        cout << name << " " << surname << " " << final_mark;
    }
        

}