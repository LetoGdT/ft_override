#include <defs.h>

int secret_backdoor()
{
  char s[128]; // [rsp+0h] [rbp-80h] BYREF

  fgets(s, 128, stdin);
  return system(s);
}

int handle_msg()
{
  char message[184]; // [rsp+0h] [rbp-C0h] BYREF

  memset(message, 0, 180);
  *(int *)(message + 180) = 140;
  set_username(message);
  set_msg(message);
  return puts(">: Msg sent!");
}

char * set_msg(char* message)
{
  char s[1024]; // [rsp+10h] [rbp-400h] BYREF

  memset(s, 0, sizeof(s));
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(s, 1024, stdin);
  return strncpy(message, s, *(int *)(message + 180));
}

int set_username(char* message)
{
  char s[140]; // [rsp+10h] [rbp-90h] BYREF
  int i; // [rsp+9Ch] [rbp-4h]

  memset(s, 0, 128);
  puts(">: Enter your username");
  printf(">>: ");
  fgets(s, 128, stdin);
  for ( i = 0; i <= 40 && s[i]; ++i )
    message[i + 140] = s[i];
  return printf(">: Welcome, %s", message + 140);
}
// 9CD: using guessed type char s[140];

int main(int argc, const char **argv, const char **envp)
{
  puts(
    "--------------------------------------------\n"
    "|   ~Welcome to l33t-m$n ~    v1337        |\n"
    "--------------------------------------------");
  handle_msg();
  return 0;
}
