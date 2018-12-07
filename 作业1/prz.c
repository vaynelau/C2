#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

struct ab{
    int a;
    int b;
};

int comp(const void *x, const void *y)
{
    struct ab *x1 = (struct ab *)x;
    struct ab *y1 = (struct ab *)y;
    return (x1->a > y1->a) - (x1->a < y1->a);
}

int main(void)
{
    FILE *in = fopen("prz.in","r");
    FILE *out = fopen("prz.out","w");
    int n=0;
    int i,j,k;
    struct ab num[50001]; 
     
    while(fscanf(in, "%d %d\n", &num[n].a, &num[n].b) == 2){
        n++;
    }
    fclose(in);
    
    qsort(num, n, sizeof(struct ab), comp);

    k=0;
    for(i=1;i<n;i++){
        if(num[i].a<=num[k].b){
            if(num[i].b>num[k].b){
                num[k].b=num[i].b;
            }
        }
        else{
            fprintf(out,"%d %d\n",num[k].a, num[k].b);
            k = i;
        }
    }
    fprintf(out,"%d %d\n",num[k].a, num[k].b);
    
    fclose(out);
    return 0;
}
