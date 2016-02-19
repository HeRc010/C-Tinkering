#include <iostream>
#include <cassert>

#include <string>
#include <map>

bool uniqueCharacters(const std::string &s)
{
  std::map<char, int> frequencyTable;

  for (char c : s)
  {
    if (++frequencyTable[c] > 1) return false;
  }

  return true;
}

int main()
{
  assert(uniqueCharacters("asdf"));
  assert(!uniqueCharacters("asdff"));
  
  return 0;
}
