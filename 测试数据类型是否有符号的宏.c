#define TEST_UNSIGN(n) n = -1; if (n > 0)\
printf(#n " is unsigned\n");\
else printf(#n " is signed\n");


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h> 

int main(void)
{
    char c;

    TEST_UNSIGN(c);
    getchar();
    return 0;
}
