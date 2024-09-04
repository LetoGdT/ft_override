#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *login = "aaaaaa";
    int v4;
    int i;

    v4 = (0x1300 + (login[3] ^ 0x37)) + 6221293;
    for ( i = 0; i < 6; ++i )
    {
      if ( login[i] < ' ' )
        return 1;
      v4 += (v4 ^ (unsigned int)login[i]) % 0x539;
    }
    printf("%d\n", v4);
    return 0;
}