#include <defs.h>

int get_unum()
{
  int v1[3]; // [esp+1Ch] [ebp-Ch] BYREF

  v1[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&unk_8048AD0, v1);
  clear_stdin();
  return v1[0];
}

int store_number(int *array)
{
  unsigned int unum; // [esp+18h] [ebp-10h]
  unsigned int index; // [esp+1Ch] [ebp-Ch]

  printf(" Number: ");
  unum = get_unum();
  printf(" Index: ");
  index = get_unum();
  if ( index == 3 * (index / 3) || HIBYTE(unum) == 183 )
  {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return 1;
  }
  else
  {
    array[index] = unum;
    return 0;
  }
}

int read_number(int array)
{
  int index; // [esp+1Ch] [ebp-Ch]

  printf(" Index: ");
  index = get_unum();
  printf(" Number at data[%u] is %u\n", index, array[index]);
  return 0;
}

int main(int argc, const char **argv, const char **envp)
{
  int array[100]; // [esp+24h] [ebp-1B8h] BYREF
  int error; // [esp+1B4h] [ebp-28h]
  char s[20]; // [esp+1B8h] [ebp-24h] BYREF
  unsigned int stack_canary; // [esp+1CCh] [ebp-10h]

  stack_canary = __readgsdword(0x14u);
  store_stack_canary_on_stack(stack_canary);
  number = 0;
  memset(s, 0, sizeof(s));
  memset(array, 0, sizeof(array));
  while ( *argv )
  {
    memset((void *)*argv, 0, strlen(*argv));
    ++argv;
  }
  while ( *envp )
  {
    memset((void *)*envp, 0, strlen(*envp));
    ++envp;
  }
  puts(
    "----------------------------------------------------\n"
    "  Welcome to wil's crappy number storage service!   \n"
    "----------------------------------------------------\n"
    " Commands:                                          \n"
    "    store - store a number into the data storage    \n"
    "    read  - read a number from the data storage     \n"
    "    quit  - exit the program                        \n"
    "----------------------------------------------------\n"
    "   wil has reserved some storage :>                 \n"
    "----------------------------------------------------\n");
  while ( 1 )
  {
    printf("Input command: ");
    error = 1;
    fgets(s, 20, stdin);
    s[strlen(s) - 1] = 0;
    if ( !memcmp(s, "store", 5u) )
    {
      error = store_number(array);
    }
    else if ( !memcmp(s, "read", 4u) )
    {
      error = read_number(array);
    }
    else if ( !memcmp(s, "quit", 4u) )
      return 0;
    if ( error )
      printf(" Failed to do %s command\n", s);
    else
      printf(" Completed %s command successfully\n", s);
    memset(s, 0, sizeof(s));
  }
  verify(stack_canary)
}