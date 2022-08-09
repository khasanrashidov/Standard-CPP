// character-escape sequences
#include <cstdio>
using namespace std;

// Some characters in C++ have special meaning,
// or are otherwise not normally accessible using the C++ language character set.
// Escape sequences are used to access these characters.

// Each escape sequence begins with a backslash character.

int main(int argc, char **argv)
{
    puts("backslash \\");
    puts("single quote \'");
    puts("double quote \"");
    puts("at sign \x40");    // \x40 is the @ sign

    // This only works if the system supports Unicode, 
    // so we may not see a Mu on our system.
    puts("Greek Mu \u03bc"); // \u03bc is a Greek Mu

    puts("audible bell\a"); // sound
    

    puts("Character-escape sequences");
    puts("");
    return 0;
}

// Character Escape Sequences
// |||||||||||||||| Full Table |||||||||||||||||
// | \'         | single quote    | byte 0x27  |
// | \"         | double quote    | byte 0x22  |
// | \?         | question mark   | byte 0x3f  |
// | \\         | backslash       | byte 0x5c  |
// | \0         | null character  | byte 0x00  |
// | \a         | audible bell    | byte 0x07  |
// | \b         | backspace       | byte 0x08  |
// | \f         | form feed       | byte 0x0c  |
// | \n         | line feed       | byte 0x0a  |
// | \r         | carriage return | byte 0x0d  |
// | \t         | horizontal tab  | byte 0x09  |
// | \v         | vertical tab    | byte 0x0b  |
// | \nnn       | octal value     | byte 0nnn  |
// | \xnn       | hexadecimal     | byte 0xnn  |
// | \unnnn     | Unicode value   | code point |
// | \unnnnnnnn | Unicode value   | code point |
// |||||||||||||||||||||||||||||||||||||||||||||

// Character escape sequences are commonly used to provide special characters
// and string constants that may not otherwise be accessible on the keyboard,
// or due to conflicts in the language.
