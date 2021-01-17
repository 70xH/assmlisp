#ifndef DATA_H
#define DATA_H

#include <iostream>

struct Data {

  // define the type
  enum {
    DataType_Nil,                                         // same as NULL in C/C++
    DataType_Int,                                         // integer
    DataType_Float,                                       // float
    DataType_Char,                                        // character
    DataType_String,                                      // string
    DataType_Pair,                                        // kinda an array
  } type;

  // define the size when declared
  union {
    struct Pair *pair;
    int Int;
    float Float;
    const char *c;
    std::string *str;
  } value;
};

// pair has two elements - car, cdr (where cdr can store a pair)
struct Pair {
  struct Data data[2];
};

// define type Data
typedef struct Data Data;

// macros
#define car(ele) ((ele).value.pair->data[0])
#define cdr(ele) ((ele).value.pair->data[1])
#define nilc(data) ((data).type == Data::DataType_Nil)

// define nil
static const Data nil = { Data::DataType_Nil };

// a method to assigning the elements in a pair - data.cpp
Data assignPairs(Data car_value, Data cdr_value);

#endif
