# Data

* The way we store data is important in any language. The defined types of data in this are:

  - DataType_Nil
  - DataType_Int
  - DataType_Float
  - DataType_Char
  - DataType_String
  - DataType_Pair

* Pair is kinda an array, with two elements - car, cdr.
  - car - the first element.
  - cdr - the second element, which can store a different pair.
  - For example:
    - (car, cdr)
    - (2,3)

    - (car, (car, cdr))
    - (2, (3, 4)) = (2, 3, 4)
* These types are defined using enum as `type`.
* The values (mainly for the size of each type) is defined as union `value`.

## Macros

* A macro for initializing the elements in pair:

  - `#define car(ele) ((ele).value.pair->atom[0])`
  - `#define cdr(ele) ((ele).value.pair->atom[1])`

* A macro to check if the data is type of NULL:

  - `#define nilp(data) ((data).type == DataType_Nil)`

### Assigning pairs

* The method `assignPairs` is used to assign the elements in the pair.
* The pair array consists of the pointers to the values.
* First the type is defined along with allocating memory to the pair using `malloc`.
* Then the values are stored in the pair.

## Defining the types
