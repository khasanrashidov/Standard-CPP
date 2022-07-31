// arrays and strings
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
    char s[] = {'s', 't', 'r', 'i', 'n', 'g', 0};
    printf("Array of charaters is %s\n", s);
    printf("\n");

    char s1[] = "string";
    printf("Array of charaters is %s\n", s1);
    printf("\n");

    char s2[] = "string";
    for (int i = 0; s2[i]; ++i)
    {
        printf("char %d is %c\n", i, s[i]);
    }
    printf("\n");

    char s3[] = "string";
    for (char *cp = s3; *cp; ++cp)
    {
        printf("char %d (%s) is %c\n", cp, cp, *cp);
    }
    printf("\n");

    char s4[] = "string";
    for (char c : s4)
    {
        if (c == 0)
            break;
        printf("char is %c\n", c);
    }
    printf("\n");

    printf("\n");
    return 0;
}