// implicit vs. explicit constructors
#include <cstdio>
using namespace std;

const size_t _maxsize = 1024;

class strsize
{
    size_t _size = 0;

public:
    // we can declare following constructors with "explicit" keyword for explicit conversion
    strsize(const int);    // constructor: size from int
    strsize(const char *); // constructor: size from c-string

    size_t size() const;
};

// implicit conversion (if constructor is not declared with 'explicit' keyword)
strsize::strsize(const int n)
{
    puts("constructor: size from int");
    _size = (n <= _maxsize) ? n : 0;
}

// implicit conversion (if constructor is not declared with 'explicit' keyword)
strsize::strsize(const char *s)
{
    puts("constructor: from c-string");
    for (size_t i = 0; i < _maxsize; i++)
    {
        if (s[i] == 0)
        {
            _size = i;
            return;
        }
    }
    _size = 0;
}

size_t strsize::size() const
{
    return _size;
}

void func(const strsize &s)
{
    printf("size is %ld\n", s.size());
}

int main(int argc, char **argv)
{
    // characters naturally promote to integers and larger scalar values.
    strsize s('x'); // does not give error even it is explicit, because we declare thusly if it is explicit
    printf("size is %ld\n", s.size());

    strsize t = 'x'; // gives an error if constructor is declared with 'explicit' keyword
    printf("size is %ld\n", t.size());

    func('x'); // gives an error if constructor is declared with 'explicit' keyword

    func(strsize('x')); // does not give error even it is explicit, because we declare thusly if it is explicit

    ////////////////////////////////////////////////////////////////////////////////

    strsize u = "x"; // gives an error if constructor is declared with 'explicit' keyword
    printf("size is %ld\n", u.size());

    strsize v("x"); // does not give error even it is explicit, because we declare thusly if it is explicit
    printf("size is %ld\n", v.size());

    func("x"); // gives an error if constructor is declared with 'explicit' keyword

    func(strsize("x")); // does not give error even it is explicit, because we declare thusly if it is explicit

    return 0;
}