#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    double x1,y1,x2,y2,x3,y3,area=0;
    scanf("%lf%lf",&x1,&y1);
    scanf("%lf%lf",&x2,&y2);
    while(scanf("%lf%lf",&x3,&y3)==2){
        area+=fabs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2;
        x2=x3;
        y2=y3;
    }
    printf("%.2f",area);
    
    return 0;
}
