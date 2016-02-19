#include <iostream>
#include <cassert>
#include <string>

void reverse(char *s, int len)
{
  for (int i = 0; i < len / 2; ++i)
  {
    char temp = s[i];
    s[i] = s[len - i - 1];
    s[len - i - 1] = temp;
  }
}

int main()
{
  char *s = (char *) std::string("asdf").c_str();
  reverse(s, 4);
  std::cout << s << std::endl;

  return 0;
}
