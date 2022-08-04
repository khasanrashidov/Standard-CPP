// including files
#include <cstdio>    // <> for system files
#include "preproc.h" // "" for user created files and header files
using namespace std;

int main(int argc, char **argv)
{
    printf("preprocessor macro: %d\n", ONE);
    printf("integer constant: %d\n", _iOne);
    printf("character string constant: %s\n", _sOne);
    puts("");
    return 0;
}
