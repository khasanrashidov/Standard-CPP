// file input and output - structured file
#include <cstdio>
#include <cstring>
#include <cstdint>
using namespace std;

// We're writing and then reading this structure file that has a
// couple binary numbers, and it has this literal C string in it.

const size_t slen = 125; // size_t is the unsigned integer type
// And so we have this structure here, which has space for a couple
// of eight bit numbers, eight bit unsigned integers, and space for
// a character string, up to 125 characters,
// and it has plus one for the null byte at the end of the string.
struct s1
{
    uint8_t num;
    uint8_t len;
    char s[slen + 1];
};

int main(int argc, char **argv)
{
    const char *fn = "test.file"; // file name
    const char *str = "This is a literal C-string.";

    // create/write the file
    printf("writing file\n");
    // We have the b here because we're actually writing a binary file.
    // If one of these numbers is the same value as a new line,
    // we don't want it translated.
    // And so we're writing a binary file
    // so we're using the b there for our binary mode.
    FILE *fw = fopen(fn, "wb");

    // We create a buffer using that structure,
    struct s1 buf1;
    // and we use a "for loop" to write the data.
    for (int i = 0; i < 5; i++)
    {
        buf1.num = i;
        buf1.len = strlen(str);
        if (buf1.len > slen)
            buf1.len = slen;
        strncpy(buf1.s, str, slen);
        // char * strncpy(char *_Destination, const char *_Source, size_t _Count)
        if (buf1.len == slen)
            buf1.s[buf1.len] = 0; // make sure it's terminated
        // We write,
        // the first argument is the buffer address,
        // the second argument is the number of bytes to write,
        // the third argument is the number of records to write,
        // in this case it's just one, and
        // the fourth argument is the file handle,
        // which we have opened with fopen().
        fwrite(&buf1, sizeof(struct s1), 1, fw);
        // size_t fwrite(const void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream)

        // printf("size of struct s1: %d\n", sizeof(struct s1));
        // printf("size of buf1.num s1: %d\n", sizeof(buf1.num));
        // printf("size of buf1.len s1: %d\n", sizeof(buf1.len));
        // printf("size of buf1.s s1: %d\n", sizeof(buf1.s));
    }
    // And that's all in the "for loop", we've closed the file
    // and then we're going to open it again for reading.

    fclose(fw);
    printf("done.\n");

    // reading the file
    printf("reading file\n");
    // So, here we're opening with rb, and so the b again is binary mode,
    // and we're opening it in read mode, we have another
    // buffer to read it into, and now we're using fread() to read the file.
    FILE *fr = fopen(fn, "rb");
    struct s1 buf2;
    size_t rc;
    // fread() returns the number of bytes read, so when that gets to zero,
    // we're going to assume we're at the end of the file.
    // And so the "while" is just checking that return code,
    // the number of bytes read, and when it gets to zero the while loop will end.
    // And so we read it directly into the buffer,
    // the first argument is the buffer,
    // the second is the size,
    // the third is the number of records, and
    // the fourth is the file handle.
    while ((rc = fread(&buf2, sizeof(struct s1), 1, fr)))
    {
        // And once we've read it into the buffer,
        // then we can just dereference our buffer as we normally would,
        // and print out the number and the length and the string and
        // we get this result down here at the end.
        printf("a: %d, b: %d, s: %s\n", buf2.num, buf2.len, buf2.s);
    }

    // Then we close the file,
    fclose(fr);
    // we delete the file,
    remove(fn); // delete the file
    // and we're done.
    printf("done.\n");

    // So, this is all very simple and straightforward.
    // This is the basics of how we do file IO using the C++ standard library.

    return 0;
}