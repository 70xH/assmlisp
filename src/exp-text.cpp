#include "data/data.hpp"
#include "data/define.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
  print(define_int(42));
  print(define_char("\n"));
  print(define_char("c"));
  print(define_char("\n"));
  print(assignPairs(define_int(10), define_string("string")));
  print(define_char("\n"));
  return 0;
}
