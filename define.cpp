#include <cstdlib>
#include <string.h>
#include <stdlib.h>

#include "data.hpp"

Atom make_int(int x)
{
  Atom p;

  p.type = Atom::AtomType_Integer;
  p.value.Integer = x;

  return p;
}

Atom make_float(float x)
{
  Atom p;

  p.type = Atom::AtomType_Float;
  p.value.Float = x;

  return p;
}

Atom make_char(const char *s)
{
  Atom p, a;

  p = sym_table;

  while(!nilp(p))
  {
    a = car(p);
    if(strcmp(a.value.c, s) == 0)
      return a;
    p = cdr(p);
  }

  a.type = Atom::AtomType_Char;
  a.value.c = strdup(s);
  sym_table = cons(a, sym_table);

  return a;
}

Atom make_string(const std::string s)
{
  Atom p;

  p.type = Atom::AtomType_String;
  p.value.str = &s;

  return p;
}

void print_expr(Atom atom)
{
  switch(atom.type)
  {
    case(Atom::AtomType_Integer):
      std::cout << atom.value.Integer;
      break;

    case(Atom::AtomType_Float):
      std::cout << atom.value.Float;
      break;

    case(Atom::AtomType_Char):
      std::cout << atom.value.c;
      break;

    case(Atom::AtomType_String):
      std::cout << *atom.value.str;
      break;

    case(Atom::AtomType_Pair):
      putchar('(');
      print_expr(car(atom));
      atom = cdr(atom);

      while(!nilp(atom))
      {
        if(atom.type == Atom::AtomType_Pair)
        {
          putchar(' ');
          print_expr(atom);
          atom = cdr(atom);
        }
        else
        {
          std::cout << " . ";
          print_expr(atom);
          break;
        }
      }

      putchar(')');
      break;

    case(Atom::AtomType_Nil):
      std::cout << "NULL";
      break;

    default:
      std::cout << "Invalid type";
      break;
  }
}

int main()
{
  print_expr(make_int(10));
  std::cout << std::endl;
  print_expr(make_float(10.032));
  std::cout << std::endl;
  print_expr(make_char("C"));
  std::cout << std::endl;

  print_expr(make_string("String"));
  std::cout << std::endl;

  print_expr(cons(make_int(10), make_float(10.02)));
  std::cout << std::endl;

  return 0;
}
