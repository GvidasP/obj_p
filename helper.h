#ifndef HELPER_H
#define HELPER_H

#include "student.h"
#include <vector>

int median(std::vector<int> data);

bool compareString(Student &a, Student &b);

std::vector<Student> readFile();

#endif