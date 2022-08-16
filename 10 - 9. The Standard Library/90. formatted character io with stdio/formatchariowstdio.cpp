// formatted character IO with stdio
#include <cstdio>
using namespace std;

// The C++ standard library provides functions
// for formatted character output.

int main(int argc, char **argv)
{
    // So, for example, we have this unformatted output here
    // with this puts(), and when we build and run this,
    // it simply displays a string on the console.
    puts("unformatted output");
    // If we want formatted output,
    // then we need to use printf() instead,
    // and so we're going to declare, say, an integer,
    // and, say, a long integer, and a string,
    int i = 5;
    long int li = 1234567890;
    const char *s = "This is a string.";
    // and now we're going to use printf()
    // to display all of those in a formatted way.
    // And we can notice the function signature here.
    // It asks for constant character pointer, so that's a string,
    // that's called the format string.
    // Then there's a comma and an ellipsis.
    // So, that ellipsis means that this is a variadic function.
    // So, that means that it can take zero or more arguments after that first one.
    // So, we're gonna go ahead and type the format string,
    // The %d is called a format specifier, and that
    // indicates that this is going to be an integer,
    // and %ld for a long integer, and %s for a string.
    // And then we're gonna put in a new line.
    // And each of these arguments must be in exactly the same order
    // as their corresponding format specifiers in the format string.
    // The first string is called the format string, and
    // printf() writes to the standard output, so it'll show up on our console.
    printf("i is %d; li is %d; s is %s\n", i, li, s); // int printf(const char *const _Format, ...)
    // So, printf() by itself like that prints to the standard output stream.
    // If we want to specify a different stream, we can use fprintf(),
    // and then the first argument before the format string, is the output stream.
    // So we can say stdout as the first argument, and a comma,
    // and then our format string, and it'll do exactly the same thing.
    fprintf(stdout, "i is %d; li is %d; s is %s\n", i, li, s); // int fprintf(FILE *const _Stream, const char *const _Format, ...)
    // But normally, this is used for writing to a file,
    // and so instead here, we will open a file.
    FILE *fh = fopen("file.txt", "w"); // file handle, text file
    fprintf(fh, "i is %d; li is %d; s is %s\n", i, li, s);
    fclose(fh); // closing the file
    // And when we build and run the program, the fprintf() above
    // will not show up in the console, because we're not using it anymore,
    // and instead, we're going to find the output in a file in the file system.
    // And the file is going to be in the same directory as our output.
    // So, if we're on a PC (Windows OS), we've already got that open
    // because we're using the command string to run our program,
    // so it'll be right there in the same directory as our output.
    // On a Mac OS, it's a little harder to find.

    // We're specifying the file handle of an open file
    // that's open for write in fprintf().

    // Now there's another version of printf() called sprintf() or
    // snprintf(), we're gonna use the sn version.
    // (In Microsoft Visual Studio, use _snprintf() instead of snprintf().)
    // And we can notice its first argument is a character pointer,
    // and so we're going to create a buffer here.
    const size_t maxlen = 128;
    char buf[maxlen];
    // And then this first argument to snprintf() is going to be the buffer,
    // and the second argument is the size of the buffer.
    // So, there's another version of snprintf()
    // without the n called sprintf(),
    // and it does not take the maximum length version,
    // and don't ever use that version because
    // it's insecure and it's possible to overwrite that buffer.
    // sprintf(); // int sprintf(char *const _Buffer, const char *const _Format, ...)
    // This gives us this control.
    // snprintf() will not write more than the maxlen number
    // of bytes to our buffer.
    snprintf(buf, maxlen, "i is %d; li is %ld; s is %s\n", i, li, s);
    // int snprintf(char *const _Buffer, const size_t _BufferCount, const char *const _Format, ...)

    // And then we have the format string,
    // and now we can just use puts()
    // to put that buffer out to the console so we can see it.
    puts(buf);
    // But obviously we could use the character of string for
    // for a lot of things, we could put it in a database,
    // we can do all kinds of things with it besides displaying it
    // on the console once we have that character string.
    // And so now we're gonna build and run, and we see our
    // output from that buffer.

    // Now, we can notice the format specifiers here.
    // The printf() format string has a tremendous number of options
    // for those format specifiers.
    // These are just the most common ones.
    // A few handy format specifiers.
    // ||||||||||||||||||||||||||||||||||||||||
    // | Specifier | Meaning                  |
    // |    %d     | Integer number           |
    // |    %ld    | Long integer number      |
    // |    %lld   | Long long integer number |
    // |    %f     | Floating point number    |
    // |    %lf    | Double                   |
    // |    %s     | C-string                 |
    // |    %c     | Character                |
    // |    %p     | Pointer                  |
    // |    %%     | The % character          |
    // ||||||||||||||||||||||||||||||||||||||||

    // Th printf() function provides a great number of
    // format specifiers for a vast array of different circumstances.
    // This is a very small subset of the most common and useful specifiers.
    // Any good C or C++ reference will have a more complete listing
    // or we can just type printf() format string in any search engine,
    // and get some good references on that.

    // The printf() family of functions provides a simple methods
    // of formatting strings for output to the console, other strings, or files.

    return 0;
}