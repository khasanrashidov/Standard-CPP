// conditionals
#include<cstdio>
using namespace std;

int main(int argc, char ** argv)
{
    int x = 20, y = 20;

    if (x > y) {
        puts("x > y");
        puts("condition is true");
    } else if (x < y) {
        puts ("x < y");
        puts("condition is false");
    } else {
        puts("they are equal");
    }
    puts("");

    int z = 50;
    printf("the greater is %d\n", x > z ? x : z);

    puts("");
    return 0;
}