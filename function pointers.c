#include <stdio.h>
#include <string.h>
#define F fflush(stdout)
#define ADD 1
#define SUB 2
#define DIV 3
#define MUL 4

void x(int *target, int a, int b){*target = a + b;}
void y(int *target, int a, int b){*target = a - b;}
void z(int *target, int a, int b){*target = a / b;}
void w(int *target, int a, int b){*target = a * b;}

int main()
{
  void (*fp)(int*, int, int);
  int target, a, b, op;
  
  printf("Enter a number | 1: Addition, 2: Subtraction, 3: Division, 4: Multiplication| \n");
  scanf("%d", &op); F;
  printf("Enter the first number:\n");
  scanf("%d", &a); F; 
  printf("Enter the second number:\n");
  scanf("%d", &b); F;
  
  switch (op) {
    case ADD: fp = x; break;
    case SUB: fp = y; break;
    case DIV: fp = z; break;
    case MUL: fp = w; break;
  }
  
  (*fp)(&target,a,b); printf("%d\n", target);
}
