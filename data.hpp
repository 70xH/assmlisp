#ifndef DATA_H
#define DATA_H

#include <cstdlib>
#include <iostream>

struct Atom
{
  enum {
    AtomType_Integer,
    AtomType_Float,
    AtomType_Char,
    AtomType_String,
    AtomType_Pair,
    AtomType_Nil
  } type;

  union {
    struct Pair *pair;
    int Integer;
    float Float;
    const char *c;
    const std::string *str;
  } value;
};

struct Pair {
  struct Atom atom[2];
};

#define car(p) ((p).value.pair->atom[0])
#define cdr(p) ((p).value.pair->atom[1])
#define nilp(atom) ((atom).type == Atom::AtomType_Nil)

static const Atom nil = { Atom::AtomType_Nil };

Atom cons(Atom car_val, Atom cdr_val);

#endif
