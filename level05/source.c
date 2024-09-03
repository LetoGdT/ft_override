#include <defs.h>
#include <string.h>

int main(int argc, const char **argv)
{
  char s[100]; // [esp+28h] [ebp-70h] BYREF
  unsigned int i; // [esp+8Ch] [ebp-Ch]

  i = 0;
  fgets(s, 100, stdin);
  tolower(s);
  printf(s);
  exit(0);
}