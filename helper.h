#ifndef HELPER_H
#define HELPER_H

#include "student.h"
#include <vector>
#include <list>

int median(const std::vector<int> & numbers);

bool compareString(Student &a, Student &b);

std::list<Student> readFile();

std::list<Student> sortStudents(std::list<Student> students);

#endif
