#include <iostream>
#include <cassert>
#include <string>
#include <map>

struct cmp_str {
  bool operator()(char const a, char const b) {
    int i_a = a - '0', i_b = b - '0';
    if (i_a == i_b) {
      return true;
    }

    return false;
  }
};

// TODO: fix; dereferencing the map doesn't work
void remove_duplicates_old(char *s)
{
  std::map<char, int, cmp_str> frequencyTable;

  char *a, *b;
  for (a = b = s; *a != '\0'; ++a) {
    *b = *a;

    printf("%c\n", *a);
    frequencyTable[*a];

    // if (++frequencyTable[*a] == 1) ++b;
  }

  // *b = '\0';
}

void remove_duplicates(char *s)
{

}

int main()
{
  char *s = (char *) std::string("asdf").c_str();

  std::cout << (s[4] == '\0') << std::endl;

  cmp_str cs;
  std::cout << cs('a', 'a') << std::endl;
  std::cout << cs('a', 'b') << std::endl;

  // std::map<char, int> frequencyTable;
  // frequencyTable['0'];

  remove_duplicates_old(s);
  std::cout << s << std::endl;

  return 0;
}
