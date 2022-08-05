// converting numbers to words
// implementation file
#include "numword.h"
using namespace my;

// destructor which clears the buffer
numword::~numword()
{
    clearbuf();
}

// assignment operator
// which sets a number and returns a number
// type (w/ ptr if there is) class::operator symbol() {}
uint64_t numword::operator=(const uint64_t num)
{
    setnum(num);
    return getnum();
}

// words method doesn't take a parameter and calls
// the words method with a parameter
// with the number that's stored in the object
const char *numword::words()
{
    return words(_num);
}

// convert to words
// Here's where the meat of the work is done.
// This is the words method.
// This is where we build the string of words from the number.
const char *numword::words(const uint64_t num) // It gets passed a number.
{
    if (num > _MY_MAXNUM) // If the number's too big,
        return errnum;    // it returns the error.
    initbuf();            // We initialize the buffer.
    uint64_t n = num;     // We initialize our internal copy of the number.
    if (n == 0)           // If it's zero, we simply pass a zero
    {
        appendbuf(_singles[n]);
        return _buf; // and we return a zero and our work is done.
    }

    // If it's not, then we need to start at the largest possible number
    // and work our way down.

    // So for each of these chunks, we'll build the word for that chunk
    // and then each of the chunks gets appended on, and
    // it builds the whole string.

    // powers of 1000
    // This first part is for the powers of 1,000.
    if (n >= 1000) // It checks to see if the number's actually greater than 1,000.
    {
        // If it is, then it starts at the highest possible power, the power of 5,000,
        // and it works its way down, 1,000s by 1,000s.

        for (int i = 5; i > 0; --i)
        {
            // For each one of these, it calls itself.
            // It strips out that part, and by dividing by the power ...
            // For example, if we have, like, 143 million, it'll divide out that million part
            // and it'll just take that 143 and it creates a new object.
            // It calls numword again.
            // And that way, that'll get passed down into the rest of it,
            // and it can build that number recursively.
            // And so, this is actually a really, really useful use of recursion here.
            // It's limited because we can use recursion because we know it's not going to get out of hand.
            // We are only going to be recursing a few times at most.
            // So, once we've built that, then we append a space and we append the buffer,
            // and we append another space and the word for the power.
            // So this would be the word "million", for example.
            // Then we subtract out the part that we've already done and go back into the loop.
            // That's how the powers of 1,000 are done.

            uint64_t power = (uint64_t)pow(1000.0, i);
            uint64_t _n = (n - (n % power)) / power;
            if (_n)
            {
                int index = i;
                numword _nw(_n);
                appendspace();
                appendbuf(_nw.words());
                appendspace();
                appendbuf(_powers[index]);
                n -= _n * power;
            }
        }
    }

    // Then we come down here into the 100s, and it starts getting a lot simpler.
    // Again, we divide out the 100s,
    // we call numword again for the smaller part of it.
    // So, if it is 300, this will get a three, if it's 500, this will get a five.
    // And, again, a space, the words itself, another space, and the word "hundred".

    // hundreds
    if (n >= 100 && n < 1000)
    {
        uint64_t _n = (n - (n % 100)) / 100;
        numword _nw(_n);
        appendspace();
        appendbuf(_nw.words());
        appendspace();
        appendbuf(_hundred);
        n -= _n * 100;
    }

    // Then, for the tens ...
    // Once we divided that out, we have the hyphen flag so, if it's 20,
    // and there's another number after it, it's going to be hyphenated.
    // If it's, for example, 21, 30, it'll get a hyphen.

    // tens
    if (n >= 20 && n < 100) // This is the one between 20 and 100.
    {
        uint64_t _n = (n - (n % 10)) / 10;
        appendspace();
        appendbuf(_tens[_n]);
        n -= _n * 10;
        hyphen_flag = true;
    }

    // Then the teens and the singles are very simple.
    // We are simply looking it up in the table.
    // That's really all there is to it.
    // For the teens and the singles, it's almost the same code.
    // They're just pulling from different parts of the tables.
    // teens
    if (n >= 10 && n < 20)
    {
        appendspace();
        appendbuf(_teens[n - 10]);
        n = 0;
    }

    // singles
    if (n > 0 && n < 10)
    {
        appendspace();
        appendbuf(_singles[n]);
    }
    return _buf;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// -- private methods --

// reset the buffer
void numword::clearbuf()
{
    if (_buf != nullptr)
    {
        free(_buf);
        _buf = nullptr;
    }
    _buflen = 0;
}

// initialize the buffer
void numword::initbuf()
{
    clearbuf();
    // Malloc (memory allocation) returns a pointer to a buffer
    // that has that amount of space allocated.
    _buf = (char *)malloc(_MY_NUMWORD_MAXSTR);

    // We set the first byte of that buffer to zero.
    // So, we are terminating that string right away,
    // so we have a zero-length string that,
    // if for some reason somebody uses that,
    // it will be a zero-length string and
    // it will not create a buffer overflow.
    *_buf = 0;

    // We set our hyphen flag to false, because this is
    // really the initialization routine.
    // We are only going to use the hyphen flaf in special cases.
    // Most of the time, we are not using it.
    hyphen_flag = false;
}

// Then we have a couple of methods here which are used
// for building the string space.

// append space (or hyphen)
void numword::appendspace()
{
    if (_buflen)
    {
        // There is one that appends a space.
        // It checks the hyphen flag and it appends either a hyphen or a space.
        appendbuf(hyphen_flag ? _hyphen : _space);

        // Once it's appended a hyphen, it sets that hyphen flag back to false,
        // so that the next time it's called, it'll append a space unless
        // the hyphen flag gets set again.
        hyphen_flag = false;
    }
}

// append text to the string buffer
void numword::appendbuf(const char *s)
{
    // Then this one here is for appending text to string buffer.
    // Again, this is a little bit complex because we are doing this with C strings.
    // If we are using the standard string library, it will not be much work.

    // We check to make sure that our string length is not too big,
    // and we check for an error condition.
    if (!s)
        return;

    size_t slen = strnlen(s, _MY_NUMWORD_MAXSTR);

    if (slen < 1)
        return;

    if ((slen + _buflen + 1) >= _MY_NUMWORD_MAXSTR)
        return;

    // Then down here, we actually do the copying and
    // we copy from one buffer into the other,
    memcpy(_buf + _buflen, s, slen);

    // we increase the length, and
    _buflen += slen;

    // we set a terminating zero at the end.
    _buf[_buflen] = 0;
}

// So, that is really it.
// That's the code.
// That's the great solution.
// This is actually a useful real-world application.
// A class like this is typically used in banking applications,
// for writing checks and other documents where monetary values are
// typically expressed in words.