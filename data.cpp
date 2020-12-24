#include <cstdlib>
#include "data.hpp"

Atom cons(Atom car_val, Atom cdr_val)
{
  Atom p;

  p.type = Atom::AtomType_Pair;
  p.value.pair = (struct Pair *) malloc(sizeof(struct Pair));

  car(p) = car_val;
  cdr(p) = cdr_val;

  return p;
}
