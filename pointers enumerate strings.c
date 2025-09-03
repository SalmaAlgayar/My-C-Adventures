#include <stdio.h>
#include <string.h>

int main()      

{
  char str[32];
  char *p = str;
  
  strncpy(str,
        "Food is ALWAYS THE BEST!, trust me!, HAHAHAHAAHA!",
        sizeof(str)/sizeof(char) - 1);
  str[strlen(str)] = '\0';
  printf("%s\n%s\n", str, p);


  for (; *p != '\0' ;p++) {
    printf("\n%c", *p);
  }

}
