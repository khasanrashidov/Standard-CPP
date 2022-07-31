// puts(), printf() // commenting out the code
#include <cstdio>
using namespace std;

// standard and common way of declaring the main function
int main(int argc, char **argv) // this perfectly legal and standard declaration of main function
{
    puts("Hello, World!");     // puts newline in the end
    printf("Hello, World!\n"); // doesn't put newline in the end, so we put \n in the end
    // puts and printf are lightweight and not complex

    return 0;
}

// The main function can be declared like this,
// int main(int argc, char *argv[]) {}
// or like this,
// int main() {}