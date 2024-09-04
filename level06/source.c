#include <defs.h>

int auth(char *login, int password)
{
  int i; // [esp+14h] [ebp-14h]
  int v4; // [esp+18h] [ebp-10h]
  int login_len; // [esp+1Ch] [ebp-Ch]

  login[strcspn(login, "\n")] = 0;
  login_len = strnlen(login, 32);
  if ( login_len <= 5 )
    return 1;
  if ( ptrace(PTRACE_TRACEME, 0, 1, 0) == -1 )
  {
    puts("\x1B[32m.---------------------------.");
    puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
    puts("\x1B[32m'---------------------------'");
    return 1;
  }
  else
  {
    v4 = (0x1300 + (login[3] ^ 0x37)) + 6221293;
    for ( i = 0; i < login_len; ++i )
    {
      if ( login[i] < ' ' )
        return 1;
      v4 += (v4 ^ (unsigned int)login[i]) % 0x539;
    }
    return password != v4;
  }
}

int main(int argc, const char **argv)
{
  int password; // [esp+2Ch] [ebp-24h] BYREF
  char login[28]; // [esp+30h] [ebp-20h] BYREF
  unsigned int stack_canary; // [esp+4Ch] [ebp-4h]

  stack_canary = __readgsdword(0x14u);
  store_stack_canary_on_stack(stack_canary);
  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(login, 32, stdin);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  scanf(&unk_8048A60, &password);
  if ( auth(login, password) )
    return 1;
  puts("Authenticated!");
  system("/bin/sh");
  verify(stack_canary)
  return 0;
}