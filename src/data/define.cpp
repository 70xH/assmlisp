#include "define.hpp"
#include "data.hpp"
#include <cstdlib>
#include <iostream>
#include <string.h>

// define integer
Data define_int(int ele)
{
  Data i;

  i.type = Data::DataType_Int;
  i.value.Int = ele;

  return i;
}

// define float
Data define_float(float ele)
{
  Data f;

  f.type = Data::DataType_Float;
  f.value.Float = ele;

  return f;
}

// define character
Data define_char(const char *ele)
{
  Data ch, sym;

  sym = symTab;
  while(!nilc(sym))
  {
    ch = car(sym);
    if(strcmp(ch.value.c, ele) == 0)
      return ch;
    sym = cdr(sym);
  }

  ch.type = Data::DataType_Char;
  ch.value.c = ele;
  symTab = assignPairs(ch, sym);

  return ch;
}

// define string
Data define_string(const std::string ele)
{
  Data s;

  s.type = Data::DataType_String;
  s.value.str = &ele;

  return s;
}

// printing
void print(Data data)
{
  switch(data.type)
  {
    // if integer
    case Data::DataType_Int:
      std::cout << data.value.Int;
      break;

    // if float
    case Data::DataType_Float:
      std::cout << data.value.Float;
      break;

    // if character
    case Data::DataType_Char:
      std::cout << data.value.c;
      break;

    // if string
    case Data::DataType_String:
      std::cout << *data.value.str;
      break;

    // if pair
    case Data::DataType_Pair:
      std::cout << "(";
      print(car(data));
      data = cdr(data);

      while(!nilc(data))
      {
        if(data.type == Data::DataType_Pair)
        {
          std::cout << " ";
          print(data);
          data = cdr(data);
        }
        else
        {
          std::cout << ".";
          print(data);
          break;
        }
      }
      std::cout << ")";
      break;

    // if nil
    case Data::DataType_Nil:
      std::cout << "NIL";
      break;

    // any other
    default:
      std::cout << "Undefined type";
      break;
  }
}
