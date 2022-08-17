// IO streams, iostream formatting
#include <iostream>
#include <iomanip>
using namespace std;

// The iostream library is fairly rich,
// but most of it is there as backend support,
// so there's really just a few classes we'll normally use.

// IOstreams come in two basic flavors:
// input streams and output streams.
// Output stream "cout" class from iostream that
// overloads the left shift operator and
// displays stuff on the console.
int main(int argc, char **argv)
{
    // cout is a very common class from iostream
    cout << "Hello, World!\n";

    // In this case, we're going to see a demonstration of "cin",
    // which uses the right shift operator to take something
    // from the console that we type in and put it into,
    // in this case, a string class variable.
    string istr;
    cout << "Prompt: ";
    // We get a prompt here from the "cout".
    // And then we're going to take input into this string.
    cin >> istr;                       // one word at a time
    cout << "Input: " << istr << endl; // And we're going to display it on the console.

    // "cin" discards everything but it just takes the first word.
    // And that's really the way "cin" works, at least by default.
    // And it's kind of why most people never use it.
    // Instead we can use getline(), which actually is more line-oriented,
    // but it doesn't use a string.
    cout << "Prompt2: ";
    // We need to declare a cstring buffer.
    char buf[128];
    // And then we're going to use cin.getline()
    // and give it the address of the buffer
    // and the size of the buffer.
    cin.getline(buf, sizeof(buf));
    // And then we'll just "cout" the buffer.
    cout << "Input2: " << buf << endl;
    // Now this seems a little awkward because
    // it's actually using a cstring, a plain character buffer.
    // But that's the way that getline works.
    // And if we're going to use "cin", this is the way most people
    // will get input from the console.

    // Output formatting with "cout".
    // integer formatting
    int i1 = 75;
    int i2 = 210;
    int i3 = 3033;
    // "cin" just displays the numbers, default is in decimal,
    // and it has its default formats.
    // We can modify the format of things with manipulators,
    // and these manipulators like "hex", "showbase", "oct", "decimal".
    // These manipulators are special member functions that
    // are used without arguments as part of a stream.
    cout << "default: " << i1 << ' ' << i2 << ' ' << i3 << endl;
    cout << "hex: " << hex << i1 << ' ' << i2 << ' ' << i3 << endl;
    // "hex" with "showbase" is with "0x" before hexadecimal values
    cout << "hex with showbase: " << showbase << hex << i1 << ' ' << i2 << ' ' << i3 << endl;
    // "octal" still has "showbase" set,
    // so, it has a zero in front of these octal numbers,
    // because we set "showbase" in a previous "cout",
    // and it remembers that.
    cout << "octal with showbase: " << oct << i1 << ' ' << i2 << ' ' << i3 << endl;
    // Then we can get back to default by saying "noshowbase"
    // and decimal and then we get our results again.
    cout << "default: " << noshowbase << dec << i1 << ' ' << i2 << ' ' << i3 << endl;

    // floating point numbers
    // floating point formatting options
    double d1, d2, d3;
    d1 = 3.1415926534; // pi
    d2 = 1234.5;
    d3 = 4.2e-10;
    cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // the "fixed" manipulator
    cout << "fixed: " << fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // the "scientific" manipulator
    cout << "scientific: " << scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // "setprecision" with the "fixed" manipulator
    cout << "fixed (3): " << setprecision(3) << fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // "setprecision" with the "scientific" manipulator
    cout << "scientific (7): " << setprecision(7) << scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    // cout.unsetf(ios_base::floatfield) to reset the defaults
    cout.unsetf(ios_base::floatfield);
    cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;

    // string formatting options
    string s1 = "This is a string.";                                                      // normal
    string s2 = "This is a much longer string.";                                          // large
    string s3 = "Today's news: Nasa's James Webb telescope reveals millions of galaxies"; // extra large

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    // Setting a width with "setw()" and
    // having the strings right flushed to that width with "right".
    cout << setw(64) << right << s1 << endl;
    cout << setw(64) << right << s2 << endl;
    cout << setw(72) << right << s3 << endl;

    // And we can set a fill with "setfill()",
    // so the "right" flush has the dashes, or spaces which is the default.
    cout << setfill('-') << setw(64) << right << s1 << endl;
    cout << setfill(' ') << setw(64) << right << s1 << endl;
    // And then we can set it "left" to display left.
    cout << left << s1 << endl;

    // So finally, I just want to give one more note.
    // We can notice each of these ends with an "endl".
    // This "endl" is actually a manipulator as well.
    // "endl" is a manipulator that provides an end of line
    // character and also flushes the output stream buffers.
    // And so, it's actually very common and
    // is the right way to end a line rather than
    // just putting a new line character in the stream.

    return 0;
}