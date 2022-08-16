// file input and output (I/O) with stdio
#include <cstdio> // C standard IO header
// C standard IO header (#include <cstdio>) provides print depth,
// but it also provides most of the file IO functions as well.
using namespace std;

// Standard file IO is really very easy to do using the standard IO library.

const int maxString = 1024; // read buffer size

int main(int argc, char **argv)
{

    const char *fn = "test.file";                      // file name
    const char *str = "This is a literal C-string.\n"; // including new line "\n" in the end of string

    // create/write the file
    printf("writing file\n");
    // fopen() is used to open a file, fopen() takes two arguments.
    // A C string for the file name and a C string for mode flags.
    // And it returns a file handle, which is a pointer to a structure,
    // which is defined by this FILE macro in all capital letters,
    // which defined in the C standard IO header.
    // And that file handle is used to access the file,
    // we'll notice this fputs() call here, which uses that fw, file for writing,
    // file handle, and the string that is going to be printed, or rather
    // put in the file, and we'll see our string is defined here as a character string.
    // The distinction between fputs() and puts()
    // is that puts() always writes to the console to standard out, and
    // puts() also puts a line ending and flushes the buffer when we're done.
    // In this case, we're not flushing the buffer because we're just going to close the file,
    // and fputs() does not include that new line, and so we're including it in our string.
    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // |                              The fopen() mode string.                               |
    // | Mode string |          Meaning           |  If file exists  | If file doesn't exist |
    // |      r      | Open file for reading      | Read from start  | Failure               |
    // |      w      | Create a file for writing  | Destroy contents | Create new file       |
    // |      a      | Append to a file           | Write from end   | Create new file       |
    // |     r+      | Open file for read/write   | Read from start  | Failure               |
    // |     w+      | Create file for read/write | Destroy contents | Create new file       |
    // |     a+      | Open file for read/write   | Write from end   | Create new file       |
    // |      b      | Binary mode                |                  |                       |
    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // The mode string will be a combination of these letters which are called mode flags.
    // B is for binary mode. And this is because text files are handled differently in
    // different operating systems. So without the B the system will assume it's
    // a text file, and our operating system may or may not decide to translate file endings.
    // One major operating system that does translate file endings is Microsoft Windows,
    // so we need to be aware of this if our code is targeted to Microsoft Windows,
    // or any other operating system that does this, and we can test it to find out
    // whether it does. But we know that Microsoft Windows does this. Without the B,
    // it'll translate our line endings for us. So if we have new lines in our code,
    // and we're writing those new lines to a text file without the B mode, then it will
    // translate those to character line feed combinations.
    // And that's just on Microsoft Windows. Unix-like operating systems like Linux or
    // Max OS 10 will not. Generally, the B string is ignored in operating systems
    // where it's not needed, so it doesn't hurt anything to include it.
    // So if we're writing a binary file where we don't want those translations to happen,
    // then we need to include the B flag.
    // For our purpose, we're going to be writing a text file, so we can notice that
    // we do not have the B flag here.
    // We just use the "for loop" to write lines of text file using fputs(),
    // and then we close with fclose() and there's our file handle again and printf("done.\n");.
    FILE *fw = fopen(fn, "w");
    for (int i = 0; i < 5; i++)
    {
        fputs(str, fw);
    }

    fclose(fw);
    printf("done.\n");

    // read the file
    printf("reading file\n");
    char buf[maxString];
    // And then we open the file for reading, and we can notice here
    // our fopen() has an r, so it's opening the file for reading,
    // we're using fgets(), which is the opposite of fputs() to get
    // strings, and the string goes in this buffer, and fgets() has three
    // parameters, the pointer to the buffer,
    // and the maximum amount to read for a line of text,
    // the maximum size of our buffer, and the file handle,
    // and then we use fputs(), which is like puts() which we've been using
    // before with a couple of differences.
    // puts() without the f at the front will put a string to the console
    // using standard out and it will also add a line ending at the end
    // and flush the buffer. fputs() does not add a line ending,
    // and does not flush the buffer, and it does not assume
    // any particular output file string. We can specify standard,
    // or we could specify as we did up above, another file handle,
    // which is the file that we opened for write.
    // And so, fputs() is more flexible, and it doesn't do
    // a couple of things for us.
    // And so, in this case, since it's not including a new line at the end,
    // we have a new line in our string that we're writing to the file.
    // So, we're reading it from the file and we're writing it to the console
    // using fputs() and specifying standard out as the file,
    // which is the console file string.
    // So, now when we build and run, we can notice that it writes
    // to the file and then it reads the file and it prints those
    // strings back out to the console.
    // So, that's reading from the file, and it prints those strings out.
    FILE *fr = fopen(fn, "r");
    while (fgets(buf, maxString, fr))
    {
        fputs(buf, stdout);
    }

    // And we can notice also that we close the file and
    // after writing to it, and we remove the file.
    // This actually deletes the file from the file system.
    fclose(fr);
    remove(fn);

    printf("done.\n");

    // So, for writing text files, this works great.

    return 0;
}