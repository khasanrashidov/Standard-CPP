// unformatted character IO with stdio
#include <cstdio>
using namespace std;

// The C++ standard library provides some simple
// functions for unformatted character I/O.

int main(int argc, char **argv)
{
    // Call to puts(). It has a C string when we build and run
    // it displays that C string on the console, terminated by
    // a new line even though the new line isn't there in the string.
    // That new line is what puts this program ended on the next line.
    // What puts() does is it takes that C string
    // and it displays it on standard out.
    // Actually more technically what it's doing,
    // is it's writing it to a file handle
    // which points to the standard out console.
    // Then it displays a new line and then
    // it flushes the buffer on that file handle.
    puts("Unformatted character IO with stdio");
    // There's another function called fputs()
    // which does not add a new line and does not flush the buffer
    // and it also does not default to standard out.
    // We can give it any file handle at all.
    // Here we're going to just give it standard out,
    // so that it will operate exactly the same as puts(),
    // well not quite exactly because we can notice,
    // when we build and run, program ended is now on the same line
    // as the string we printed out. This is actually an important
    // distinction because puts() without the f is not only adding
    // a new line but it's also flushing the buffer.
    // So fputs() will write a string to a file handle,
    // in this case we're using the standard out file handle for convenience.
    fputs("Unformatted character IO with stdio\n", stdout);
    // There's a corresponding function called fgets() and before
    // we demonstrate that we need to create a buffer for it,
    // to put the string and that we're going to type at the console
    // because what fgets() does is it takes input from a file handle,
    // in this case, we're going to use standard in.
    const static int bufsize = 256; // 256 bytes
    char buf[bufsize];              // buffer itself
    fputs("Prompt: ", stdout);
    // So fgets() takes three arguments,
    // the first one is our character buffer,
    // the second one is the size of the buffer,
    // so that fgets() won't overwrite the buffer.
    // The third one is the file handle that we're
    // going to be reading from and in this case
    // we're just gonna use standard in.
    fgets(buf, bufsize, stdin); // char * fgets(char *_Buffer, int _MaxCount, FILE *_Stream)
    // Then we're going to go ahead and use fputs() again
    // to display whatever it is that we type on the console.
    // That will be the buffer, and
    // the file handle will be standard out.
    // When we build and run this, it's going to work on our console,
    // it may not on others' console and we'll explain why in a moment.
    // There will be a new line after entering a string.
    // That's the Return key (Enter key) when we press the Return key (Enter key)
    // that gets put in the buffer and that gets displayed.
    // So, a lot of times we will not see this Prompt
    // and the reason for that is that fputs() by default
    // is not suppose to flush the buffer.
    // If the buffer's not flushed then the characters
    // are not actually sent out to that string.
    // In a lot of cases, in some libraries it does flush the buffer
    // and in some libraries, it doesn't.
    // In the one that we're using here, apparently it does.
    // All we need to do to make this work consistently
    // is to put in a statement here
    // (between fputs() prompt and fgets() input)
    // or a function call called fflush()
    // and the file stream that we wanna flush.
    // In this case it's standard out.
    fflush(stdout);
    fputs(buf, stdout);
    // Now when we build and run this program on any system,
    // it will flush the buffer at that point causing those characters
    // to be displayed or to be written to that file
    // and then we can type in our string,
    // and the rest of the code will work.
    // Now another really important note,
    // is that just like we have puts()
    // which is a shortcut for fputs() with standard out
    // and a new line and a buffer flush there's also something
    // called gets() without the f.
    // I want to say this very clearly and
    // I want others to be sure to remember this,
    // do NOT ever use gets(), that's the version without the f,
    // gets() by itself. gets() works on standard in
    // but it does not check the buffer length,
    // so we can easily override a buffer
    // and this is a huge security risk.
    // Buffer overflow, types of errors are very, very common
    // ways to take over a system and
    // to spread viruses around the internet.
    // So, we just don't ever want to use the version of gets() without the f.
    // fgets(), on the other hand, will read only up until
    // the buffer size minus one, so that it makes sure that it
    // never overwrites that buffer. It's easy for us to just use stdin,
    // we don't ever need the gets() without the f.

    // This is the basic unformatted character I/O functions.
    // Of course, these work with any file,
    // not just with standard out and standard in,
    // not just with the console.
    // These are a part of the C++ standard library
    // so they're available on every system.

    return 0;
}