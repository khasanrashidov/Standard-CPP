// numword.h by Khasan Rashidov
#ifndef _NUMWORD_H_
#define _NUMWORD_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cmath>

#define _MY_NUMWORD_MAXSTR 1024

/*
    nine hundred ninty-nine quadrillion
    nine hundred ninty-nine trillion
    nine hundred ninty-nine billion
    nine hundred ninty-nine million
    nine hundred ninty-nine thousand
    nine hundred ninty-nine
*/

#define _MY_MAXNUM 999999999999999999

namespace my
{
    static const char *errnum = "error";
    static const char *_singles[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                                     "eight", "nine"};
    static const char *_teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                   "sixteen", "seventeen", "eighteen", "nineteen"};
    static const char *_tens[] = {errnum, errnum, "twenty", "thirty", "forty", "fifty", "sixty",
                                  "seventy", "eighty", "ninty"};
    static const char *_hundred = "hundred";
    static const char *_powers[] = {errnum, "thousand", "million", "billion", "trillion", "quadrillion"};

    static const char *_hyphen = "-";
    static const char *_space = " ";

    class numword // class definition
    {
    private:
        uint64_t _num = 0;        // number itself, there is a space for the number itself, it's uint64 type
        char *_buf = nullptr;     // a pointer for the buffer, where we are going to build the words
        size_t _buflen = 0;       // a counter for the length of the buffer
        bool hyphen_flag = false; // a hyphen flag, which is used for the compound numbers
                                  // between 20 and 99 are hyphenated, rather than using a space.
        // These private methods are not called from the outside.
        // They are only called from within the class.
        void clearbuf();               // for clearing the buffer
        void initbuf();                // for initializing the buffer
        void appendspace();            // for appending the space
        void appendbuf(const char *s); // for appending buffers when we are building compound words

    public:                                             // public interface
        numword() : _num(0) {}                          // default ctor, which assigns a zero to the number
        numword(const uint64_t num) : _num(num) {}      // constructor where we can pass in a number
        ~numword();                                     // destructor
        void setnum(const uint64_t num) { _num = num; } // setter
        uint64_t getnum() const { return _num; }        // getter
        uint64_t operator=(const uint64_t num);         // operload overload for the copy operator
        // words
        // the one without a parameter will simply make words
        // out of whatever number is stored in the number up here
        const char *words();
        const char *words(const uint64_t num); // words where we pass in a number
    };

} // namespace my

#endif /* _NUMWORD_H_ */
