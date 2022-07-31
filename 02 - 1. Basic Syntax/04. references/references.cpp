// references and differences between references and pointers
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
   int x = 5;
   int *ip = &x;
   int &y = x;

   printf("The value of x is %d\n", x);     // 5
   printf("The value of *ip is %d\n", *ip); // 5
   printf("The value of y is %d\n", y);     // 5
   printf("\n");

   x = 64;

   printf("The value of x is %d\n", x);     // 64
   printf("The value of *ip is %d\n", *ip); // 64
   printf("The value of y is %d\n", y);     // 64
   printf("\n");

   y = 27;

   printf("The value of x is %d\n", x);     // 27
   printf("The value of *ip is %d\n", *ip); // 27
   printf("The value of y is %d\n", y);     // 27
   printf("\n");
   
   *ip = 33;

   printf("The value of x is %d\n", x);     // 33
   printf("The value of *ip is %d\n", *ip); // 33
   printf("The value of y is %d\n", y);     // 33
   printf("\n");

   int z = 123;
   ip = &z;

   printf("The value of x is %d\n", x);     // 33
   printf("The value of *ip is %d\n", *ip); // 123
   printf("The value of y is %d\n", y);     // 33
   printf("The value of z is %d\n", z);     // 123
   printf("\n");

   y = z;

   printf("The value of x is %d\n", x);     // 123
   printf("The value of *ip is %d\n", *ip); // 123
   printf("The value of y is %d\n", y);     // 123
   printf("The value of z is %d\n", z);     // 123
   printf("\n");

   /*

   The main differences between pointers and references are -

   1) References are used to refer an existing variable in another name
      whereas pointers are used to store address of variable.

   2) References cannot have a null value assigned but pointer can.

   3) A reference variable can be referenced by pass by value
      whereas a pointer can be referenced but pass by reference.

   5) A reference must be initialized on declaration
      while it is not necessary in case of pointer.

   6) A reference shares the same memory address with the original variable
      but also takes up some space on the stack
      whereas a pointer has its own memory address and size on the stack.

   */
   printf("\n");
   return 0;
}