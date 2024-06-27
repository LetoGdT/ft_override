#include <stdio.h>
#include <stdlib.h>

char user_name[100];

int verify_user_name()
{
  puts("verifying username....\n");
  return memcmp(user_name, "dat_wil", 7u) != 0;
}

int verify_user_pass(char *password)
{
  return memcmp(password, "admin", 5u) != 0;
}

int main(int argc, const char **argv, const char **envp)
{
  char password[64];
  int is_correct;

  memset(password, 0, sizeof(password));
  is_correct = 0;
  puts("********* ADMIN LOGIN PROMPT *********");
  printf("Enter Username: ");
  fgets(user_name, 256, stdin);
  is_correct = verify_user_name();
  if ( is_correct )
  {
    puts("nope, incorrect username...\n");
  }
  else
  {
    puts("Enter Password: ");
    fgets(password, 100, stdin);
    is_correct = verify_user_pass(password);
    puts("nope, incorrect password...\n");
  }
  return 1;
}
