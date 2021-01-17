#include "data.hpp"

Data assignPairs(Data car_value, Data cdr_value)
{
  // declare a pair
  Data p;

  // define the type
  p.type = Data::DataType_Pair;

  // allocate memory for the pair
  p.value.pair = (struct Pair *) malloc(sizeof(struct Pair));

  // assign the values
  car(p) = car_value;
  cdr(p) = cdr_value;

  return p;
}
