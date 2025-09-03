#include <stdio.h>
int main()
{
    int a=15; 
    int b=2, k; 
    float q; 

    
    q = (float)a / b;
    
    printf("%u %f %d\n", q, q, q);
    
    q = a / b;
    
    printf("%u %f %d\n", q, q, q);
    
    k = a / b;
    
    printf("%u %f %d\n", k, k, k);
    
    k = (float)a / b;
    
    printf("%u %f %d\n", k, k, k);
}
