// a simple jump table
#include <cstdio>
using namespace std;

// function prototypes
void fa() { puts("this is fa()"); }
void fb() { puts("this is fb()"); }
void fc() { puts("this is fc()"); }
void fd() { puts("this is fd()"); }
void fe() { puts("this is fe()"); }

/*
    A jump table is a special array of pointer-to-functions.
    Since, this is an array, and as we know that
    all array elements must be of same type, therefore,
    it requires that all functions must be of same type and
    all take same number and same type of parameters.
*/

// jumptable declared and initialized
void (*funcs[])() = {fa, fb, fc, fd, fe, nullptr};

// prompt and return string
const char *prompt()
{
    puts("Choose an option:");
    puts("1. Function fa()");
    puts("2. Function fb()");
    puts("3. Function fc()");
    puts("4. Function fd()");
    puts("5. Function fe()");
    puts("Q. Quit.");
    printf(">> ");

    fflush(stdout); // flush after prompt

    const int buffsz = 16;          // constant for buffer size
    static char response[buffsz];   // static storage for response buffer
    fgets(response, buffsz, stdin); // get response from console

    return response;
}

// jump table
int jump(const char *rs)
{
    char code = rs[0];
    if (code == 'q' || code == 'Q') return 0;

    // get the length of the funcs array
    int func_length = 0;
    while(funcs[func_length] != NULL) func_length++; // or using func_length = sizeof(funcs) / sizeof(funcs[0]);

    int i = (int)code - '0'; // convert ASCII numeral to int
    i--;

    if (i < 1 || i >= func_length)
    {
        puts("invalid choice");
        return 1;
    }
    else
    {
        funcs[i](); // array is zero-based
        return 1;
    }
}

int main(int argc, char **argv)
{
    while (jump(prompt()));
    puts("\nDone.");
    return 0;
}
