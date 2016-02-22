#include <iostream>
#include <cassert>
#include <string>

int convert_roman_char(char c)
{
  switch(c)
  {
  case 'i':
    return 1;
  case 'v':
    return 5;
  case 'x':
    return 10;
  case 'l':
    return 50;
  case 'c':
    return 100;
  case 'd':
    return 500;
  case 'm':
    return 1000;
  default:
    break;
  }

  return 0;
}


int convert_roman_string(const std::string &s)
{
  if (s.size() == 0) return 0;

  int value = 0,
    prev_value = convert_roman_char(s[0]),
    next_value = 0;
  for (int i = 1; i < s.size(); ++i)
  {
    next_value = convert_roman_char(s[i]);
    if (prev_value < next_value)
    {
      prev_value *= -1;
    }

    value += prev_value;
    prev_value = next_value;
  }

  value += prev_value;
  return value;
}

int main(int argc, char *argv[])
{
  // Tests
  assert(convert_roman_string("") == 0);
  assert(convert_roman_string("i") == 1);
  assert(convert_roman_string("iii") == 3);
  assert(convert_roman_string("iv") == 4);
  assert(convert_roman_string("v") == 5);
  assert(convert_roman_string("vii") == 7);
  assert(convert_roman_string("ix") == 9);
  assert(convert_roman_string("xii") == 12);
  assert(convert_roman_string("xliv") == 44);
  
  return 0;
}
