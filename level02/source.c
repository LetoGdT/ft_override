#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv, const char **envp)
{
  char password[100];
  char password_from_file[48];
  char username[100];
  int bytes_read_from_file;
  FILE *stream;

  memset(username, 0, sizeof(username));
  memset(password_from_file, 0, 41);
  memset(password, 0, sizeof(password));
  stream = 0;
  bytes_read_from_file = 0;
  stream = fopen("/home/users/level03/.pass", "r");
  if ( !stream )
  {
    fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
    exit(1);
  }
  bytes_read_from_file = fread(password_from_file, 1, 41, stream);
  // Trim the string so it terminates on the first '\n'
  password_from_file[strcspn(password_from_file, "\n")] = 0;
  if ( bytes_read_from_file != 41 )
  {
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
    exit(1);
  }
  fclose(stream);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(username, 100, stdin);
  username[strcspn(username, "\n")] = 0;
  printf("--[ Password: ");
  fgets(password, 100, stdin);
  password[strcspn(password, "\n")] = 0;
  puts("*****************************************");
  if ( strncmp(password_from_file, password, 41) )
  {
    printf(username);
    puts(" does not have access!");
    exit(1);
  }
  printf("Greetings, %s!\n", username);
  system("/bin/sh");
  return 0;
}