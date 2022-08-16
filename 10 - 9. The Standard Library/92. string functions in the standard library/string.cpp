// The string functions in the standard library.
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char **argv)
{
    const static size_t maxbuf = 128; // maximum size of a buffer of 128
    // A couple of constant strings and these are the pointer variety.
    // So, these are constant strings that cannot be changed.
    const char *s1 = "String one"; // pointer to literal string
    const char *s2 = "String two"; // pointer to literal string
    // A couple of buffers, which are the size of maxbuf, 128 bytes.
    char sd1[maxbuf];
    char sd2[maxbuf];
    int i = 0;          // integer
    char c = 0;         // character
    char *cp = nullptr; // character pointer

    // -- strncpy() -- copy a string
    // Function strncpy() copies from one string to another.
    // So, the first parameter is the destination,
    // the second parameter is the source, and
    // the third parameter is the maximum buffer size.
    strncpy(sd1, s1, maxbuf); // char * strncpy(char *_Destination, const char *_Source, size_t _Count)
    printf("sd1 is %s\n", sd1);
    strncpy(sd2, s2, maxbuf);
    printf("sd2 is %s\n", sd2);
    // There's another version of this called strcpy() without the n,
    // and we should really never use that version,
    // because it doesn't check the buffer size,
    // and so it's really not safe.
    // And again, we need to keep in mind that many of these functions
    // may show a warning in Microsoft C++ and some other environments.
    // Microsoft and some other environments provide their own versions
    // of these functions, often claiming that they're safer.
    // We need to feel free to use those other versions, if we prefer.
    // But we just need to understand that they're not standard
    // and may not be available on other systems.
    puts("");

    // -- strncat() -- concatenate string
    // strncat() is for concatenating strings.
    // strncat(), the first parameter is the destination,
    // the second parameter is the source, and
    // the third parameter is the maximum size.
    // And so, in this case, we can see for our maximum size
    // we're subtracting out what the value was before,
    // so that we know that we're not overflowing the buffer,
    // and we did the same thing in the second strncat() concatenation.
    strncat(sd1, " - ", maxbuf - strlen(sd1) - 1); // char * strncat(char *_Destination, const char *_Source, size_t _Count)
    // to know why size has that value
    // printf("overall value (size) is %d\n", maxbuf - strlen(sd1) - 1);
    // printf("maxbuf value (size) is %d\n", maxbuf);
    // printf("sd1 is \"%s\" and strlen value is %d\n", sd1, strlen(sd1));
    // printf("value (size) of 1 is %d\n", 1);
    strncat(sd1, s2, maxbuf - strlen(sd1) - 1);
    printf("sd1 is %s\n", sd1);
    puts("");

    // -- strnlen() --  get length of string
    // For taking the length of a string, we have strnlen()
    // and it just has two parameters, the string to take the length of
    // and the maximum length that we're going to count.
    // How this works is it actually goes through the string,
    // and it looks at every character sequentially, looking for that null value.
    // And so, if it doesn't find it, we could have a buffer overrun.
    // And so, that's why it's important to use
    // the safe version of this with the n.
    printf("length of sd1 is %ld\n", strnlen(sd1, maxbuf)); // size_t strnlen(const char *_String, size_t _MaxCount)
    printf("length of sd2 is %ld\n", strnlen(sd2, maxbuf));
    // There is another version, strlen(),
    // and we've been known to use that on occasion.
    // Sometimes we either forget or very very positive
    // that we have a null-terminated string that we're working with,
    // but it's really always safer to use the strnlen() version.
    puts("");

    // -- strcmp() -- compare strings
    // For comparing strings, we have strcmp(),
    // and this compares the values of two strings.
    // The result is either a negative value or a zero or a positive value.
    i = strcmp(sd1, sd2); // int strcmp(const char *_Str1, const char *_Str2)
    printf("sd1 %s sd2 (%d)\n", (i == 0) ? "==" : "!=", i);
    i = strcmp(sd2, s2);
    printf("sd2 %s s2 (%d)\n", (i == 0) ? "==" : "!=", i);

    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // strcmp() returns an integral value indicating the relationship between the strings:
    // | return | value indicates                                                                  |
    // |   <0   | the first character that does not match has a lower value in ptr1 than in ptr2   |
    // |    0   | the contents of both strings are equal                                           |
    // |   >0   | the first character that does not match has a greater value in ptr1 than in ptr2 |
    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    puts("");

    // -- strchr() -- find a char in string
    // With strchr() we can find a character in a string.
    // So, we're looking for the character n in the string sd1.
    // cp is our result.
    // strchr() returns either the position
    // of the first matching character or a null.
    c = 'n';
    cp = strchr(sd1, c); // const char * strchr(const char *_Str, int _Val)
    printf("Did we find a '%c' in sd1? %s\n", c, cp ? "yes" : "no");
    if (cp)
        printf("The first '%c' in sd1 is at position %ld\n", c, cp - sd1);
    // We can subtract sd1 from cp, (cp - sd1)
    // because both of them are pointers and hold address.
    // just to check
    // printf("cp is \"%s\" and has value %ld\n", cp, cp);
    // printf("sd1 is \"%s\" and has value %ld\n", sd1, sd1);

    // strchr() return value is:
    // A pointer to the first occurrence of character in str.
    // If the character is not found, the function returns a null pointer.

    // There's another version of this, strrchr(), which searches from
    // the right-hand side, and it'll find the last position.

    cp = strrchr(sd1, c); // const char * strchr(const char *_Str, int _Val)
    printf("Did we find a '%c' in sd1? %s\n", c, cp ? "yes" : "no");
    if (cp)
        // And so, in this case, the last n in sd1 is at position 17.
        printf("The last '%c' in sd1 is at position %ld\n", c, cp - sd1);
    puts("");

    // -- strstr() -- find a string in string
    // strstr() is for finding a string within a string,
    // and we're going to look for s2 within sd1.
    cp = strstr(sd1, s2); // const char * strstr(const char *_Str, const char *_SubStr)
    printf("Did we find '%s' in sd1? %s\n", s2, cp ? "yes" : "no");
    if (cp)
        printf("The first '%s' in sd1 is at position %ld\n", s2, cp - sd1);
    // It found the s2 at position 13.
    // And again, it returns the position of the first match
    // or a zero, if it's not found.
    puts("");

    // So, these are some of the more common string functions
    // that we'll find in the standard C++ library.
    // Even if we're using C++, we should never be afraid to use C strings.
    // There are times when they're necessary, and there are times when
    // they're just smaller and faster than C++ STL strings.
    // These functions are a great resource for working with C strings.

    return 0;
}