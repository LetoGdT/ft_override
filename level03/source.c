#include <stdio.h>
#include <stdlib.h>

int decrypt(char str)
{
  unsigned int i; // [esp+20h] [ebp-28h]
  unsigned int len; // [esp+24h] [ebp-24h]
  char v4[29]; // [esp+2Bh] [ebp-1Dh] BYREF
  int stack_canary; // [ebp-Ch]

  stack_canary = __readgsdword(0x14u);
  strcpy(v4, "Q}|u`sfg~sf{}|a3");
  len = strlen(v4);
  for ( i = 0; i < len; ++i )
    v4[i] ^= str;
  if ( !strcmp(v4, "Congratulations!") )
    return system("/bin/sh");
  else
    return puts("\nInvalid Password");
  check_stack_canary(stack_canary);
}

int test(int password, int key)
{
  int result; // eax
  char seed; // al

  switch ( key - password )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
      result = decrypt(key - password);
      break;
    default:
      seed = rand();
      result = decrypt(seed);
      break;
  }
  return result;
}

int main(int argc, const char **argv, const char **envp)
{
  unsigned int seed; // eax
  int password; // [esp+20h] [ebp+0h] BYREF

  seed = time(0);
  srand(seed);
  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");
  printf("Password:");
  scanf("%d", &password);
  test(password, 322424845);
  return 0;
}