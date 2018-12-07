/* 存在bug */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define todigit(c)  (isdigit(c) ? (c)-'0' : 0)
#define tochar(d)   ((d) + '0')
#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MIN(a,b)    ((a) < (b) ? (a) : (b))
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMP(x,y)   (((x) < (y))? -1: ((x) == (y)) ? 0 : 1)
#define CLR(a)      memset(a, 0, sizeof(a))
#define LEN(a)      (sizeof(a)/sizeof(a[0]))
#define NEW(n,type) (type*)malloc(n*sizeof(type))

char s[20005];
char buf[20005];
char input[1000][10];
int trans[1000][1000], output[1000][1000];
int out[1000];
int cnt = 0;
char sign[1000];
int l = 0;
int main(void)
{
    FILE *in = fopen("dfa.in", "r");
    fgets(s, 2000000, in);
    int len = strlen(s), m = 1;
    while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n') {
        s[--len] = '\0';
    }
    char *start = s;
    sscanf(start, "%s", buf);
    start += strlen(buf);
    while (*start == ' ' || *start == '\t') {
        start++;
    }
    while (*start != '\0') {
        sscanf(start, "%s", input[m]);
        start += strlen(input[m++]);
        while (*start == ' ' || *start == '\t') {
            start++;
        }
    }

    int i, j, k, z;
    int state;
    char *pbuf;
    while (fgets(s, 2000000, in) != NULL) {
        len = strlen(s);
        while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n') {
            s[--len] = '\0';
        }
        start = s;
        sscanf(start, "%s", buf);
        start += strlen(buf);
        while (*start == ' ' || *start == '\t') {
            start++;
        }
        l = 0;
        while (!isdigit(buf[l])) {
            sign[l] = buf[l];
            l++;
        }
        sign[l] = '\0';
        pbuf = &buf[l];
        sscanf(pbuf, "%d", &i);
        if (*start != '\0') {
            j = 1;
            while (*start != '\0' ) {
                sscanf(start, "%s", buf);
                start += strlen(buf);
                while (*start == ' ' || *start == '\t') {
                    start++;
                }
                l = 0;
                while (!isdigit(buf[l])) {
                    l++;
                }
                pbuf = &buf[l];
                sscanf(pbuf, "%d,%d", &k, &z);
                trans[i][j] = k;
                output[i][j] = z;
                j++;
            }
        } else {
            state = i;
            break;
        }

    }
    fgets(s, 2000000, in);
    len = strlen(s);
    while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n') {
        s[--len] = '\0';
    }
    start = s;
    while (*start == ' ' || *start == '\t') {
        start++;
    }
    while (*start != '\0') {
        sscanf(start, "%s", buf);
        start += strlen(buf);
        while (*start == ' ' || *start == '\t') {
            start++;
        }
        for (i = 1; i <= m; i++) {
            if (strcmp(input[i], buf) == 0) {
                out[cnt++] = output[state][i];
                state = trans[state][i];
                break;
            }
        }
    }
    printf("%s%d\n", sign, state);
    for (i = 0; i < cnt; i++) {
        printf("%d ", out[i]);
    }

    fclose(in);
    return 0;
}
