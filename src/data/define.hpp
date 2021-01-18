#ifndef DEFINE_H
#define DEFINE_H
#include "data.hpp"
#include <iostream>

// define integer
Data define_int(int ele);

// define float
Data define_float(float ele);

// define character
Data define_char(const char *ele);

// define string
Data define_string(const std::string ele);

// printing
void print(Data data);

#endif
