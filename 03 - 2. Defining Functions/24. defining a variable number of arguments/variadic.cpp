// defining a variable number of arguments
#include <cstdio>
#include <cstdarg> // The cstdarg header provides macros needed to suppport the variadic arguments.
using namespace std;

// first argument is int of remaining args
// ... means that this function takes a variable number of arguments
double average(const int count, ...)
{
    // macro called va_list which
    // declares the list of arguments that
    // appear after that first argument
    va_list ap;

    int i;
    double total = 0.0;

    // va_start macro points at the va_list variable and the count variable,
    // the count variable declares where the start of the variable argument list begins
    // it is the last argument that's not one of the variable list;
    // so the last one that's explicitly declared, in this case it's the count one, it's a;so the first one,
    // that's what we put there with va_start.
    va_start(ap, count);

    for (i = 0; i < count; ++i)
    {
        // va_arg macro grabs the next variable from the list, and
        // it also declares its type here.
        total += va_arg(ap, double);
    }

    // we call va_end when we are done or it can create problems later on
    va_end(ap);
    return total / count;
}

// worls like printf, format plus args
int message(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int rc = vfprintf(stdout, fmt, ap);
    va_end(ap);
    return rc;
}

int main(int argc, char **argv)
{
    message("This is a message\n");
    message("Average: %lf\n", average(5, 25.0, 35.7, 50.1, 127.6, 75.0)); // %lf for double
    return 0;
}