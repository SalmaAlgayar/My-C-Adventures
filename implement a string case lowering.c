#include <stdio.h>

void lower_case(char * str, int size) {
    for (int i = 0; i < size; i++) {
        if ( * (str + i) >= 65 && * (str + i) <= 90) * (str + i) = * (str + i) + 32;
    }
}


int main()
{
    char str[] = "SWAYYYY WItH mE ... !!!";
    printf("%s\n", str);

    lower_case(str, sizeof(str));
    printf("%s\n", str);
}
