// file management with stdio
#include <cstdio>
using namespace std;

// Let's take a quick look at how we create, rename,
// and delete files using the C++ standard library.

int main(int argc, char **argv)
{
    const static char *fn1 = "file1";
    // Creating the file using fopen(). Getting a file handle.
    // Using the write mode in our mode string.
    FILE *fh = fopen(fn1, "w");
    // And we're just gonna go ahead and close it right away with fclose().
    fclose(fh);
    // And then we'll just put a string that says "Done".
    // Now, when we we build and run this, it says "Done".
    // And a file has been created in the directory where
    // our executable is.
    // So, that file is now created.
    // And now if we wanna rename the file,
    // we're gonna create another constant for the name
    // we're gonna name it to. Just call it file2.
    const static char *fn2 = "file2";

    // rename(), the first argument is what we're renaming it from
    // and the second argument is what we're renaming it to.
    rename(fn1, fn2); // int rename(const char *_OldFileName, const char *_NewFileName)
    // So, the file system will look for the file with
    // the filename file1 and it will rename it to file2.

    // And so our file1 file has been renamed to file2.

    // Now if we wanna delete the file, we simply call remove()
    // and its filename is now fn2. It's now the file2 name.
    remove(fn2);
    // Now the file is gone.

    // Both rename and remove return zero on success
    // or non-zero value if there's an error.
    // We'll look at how to read the error codes in handling system errors part.

    // That's how we create, delete, and rename files using the C++ standard library.
    puts("Done.");

    return 0;
}