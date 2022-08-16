// handling system errors
#include <cstdio>
#include <cerrno>
#include <cstring>

// The C++ standard library provides a few simple resources
// for handling system level error conditions.

// #include <cerrno>
// cerrno provides access to the integer value errno.
// If errno is not zero, it'll contain a value representing an error.
// The supported values and their meanings are
// typically defined by the host operating system.
// So, (initially) when we build and run this
// we'll see the errno is zero and then
// when we try to erase a file that doesn't exist,
// now the errno is two.

int main(int argc, char **argv)
{
    printf("errno is: %d\n", errno);
    printf("Erasing file foo.bar\n");
    remove("foo.bar");
    printf("errno is: %d\n", errno);
    // And we see the perror() function.
    // We say "Couldn't erase file".
    // It takes a string as an argument
    // and it'll display that string followed by
    // the standard error message for that particular error.
    // It's in errno at that time and so in this case
    // it says, "No such file or directory".
    perror("Couldn't erase file");

    // And so that's the error that we got from trying
    // to remove a file that doesn't exist.
    // It says there is no such file or directory.

    // There's also a function called strerror()
    // which is actually defined in the C string header file.
    // And we're gonna use printf() to print its values.
    // We use sterror() and pass it the error number.
    printf("the error message is: %s\n", strerror(errno));
    // So, strerror() returns a C string and we can print that
    // with printf() using the %s symbol and now we'll
    // build and run and we see it says "the error message is",
    // and it's the same error message because we tried to
    // remove a file that doesn't exist.

    // With strerror(), we can send the error to standard out
    // as we did here or to a file or put it in a database
    // or use it however we like.
    // We've got a C string of the error message.

    puts("");
    puts("error messages:");
    int count = -1;
    while (count <= 43)
    {
        printf("error message %d: %s\n", count, strerror(count));
        count++;
    }
    puts("");

    return 0;
}

// error messages:
// error message -1: Unknown error
// error message 0: No error
// error message 1: Operation not permitted
// error message 2: No such file or directory
// error message 3: No such process
// error message 4: Interrupted function call
// error message 5: Input/output error
// error message 6: No such device or address
// error message 7: Arg list too long
// error message 8: Exec format error
// error message 9: Bad file descriptor
// error message 10: No child processes
// error message 11: Resource temporarily unavailable
// error message 12: Not enough space
// error message 13: Permission denied
// error message 14: Bad address
// error message 15: Unknown error
// error message 16: Resource device
// error message 17: File exists
// error message 18: Improper link
// error message 19: No such device
// error message 20: Not a directory
// error message 21: Is a directory
// error message 22: Invalid argument
// error message 23: Too many open files in system
// error message 24: Too many open files
// error message 25: Inappropriate I/O control operation
// error message 26: Unknown error
// error message 27: File too large
// error message 28: No space left on device
// error message 29: Invalid seek
// error message 30: Read-only file system
// error message 31: Too many links
// error message 32: Broken pipe
// error message 33: Domain error
// error message 34: Result too large
// error message 35: Unknown error
// error message 36: Resource deadlock avoided
// error message 37: Unknown error
// error message 38: Filename too long
// error message 39: No locks available
// error message 40: Function not implemented
// error message 41: Directory not empty
// error message 42: Illegal byte sequence
// error message 43: Unknown error
