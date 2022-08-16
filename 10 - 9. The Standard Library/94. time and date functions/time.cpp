// time and date functions
#include <cstdio>
#include <ctime> // ctime header defines time_t type, along with following functions below.
using namespace std;

// The standard C++ library provides some basic functions for handling time and date.
//

int main(int argc, char **argv)
{
    const static size_t bufsize = 128;
    // ctime header defines time_t type.
    // time_t is typically a 64 bit signed integer
    // giving the number of seconds since midnight,
    // January first, 1970, GMT or UTC.
    // This value is sometimes called the Unix epoch date.
    // It was traditionally a 32 bit number,
    // but that size would not hold a date beyond 19 January, 2038,
    // so the Unix world has begun transitioning to 64 epoch dates,
    // and a 64 bit epoch date will not run out until about
    // 292 billion years from now, so the universe is commonly
    // accepted to be less than 14 billion years old, so I think we're safe. :)
    // When we build and run this code, we can notice that we're taking
    // the size of time_t here, and output at the top says,
    // "On this system, time_t is 64 bits", so that's good,
    // it's not going to run out in a few years,
    // it will run out rather in a few billion years.
    time_t t = time(nullptr); // the current time

    printf("On this system, size of time_t is %ld bits.\n", sizeof(time_t) * 8);

    // So, the GMT time function and the local time function
    // these both return a structure called struct tm,
    // and this structure has members for the different parts of the date and time.
    // The GM time returns the structured time in GMT, and
    // the local time returns the structured time in our local time for our system,
    // assuming that our system is set up properly
    // and knows what its local timezone is.
    struct tm gmt = *gmtime(&t); // structured time in GMT
    // tm * gmtime(const time_t *const _Time)
    struct tm localt = *localtime(&t); // structured time local
    // tm * localtime(const time_t *const _Time)

    // And then we can use this tm structure to grab all these different
    // parts of the structure and the parts of the date and time,
    // and let's take a look at what those different parts are.
    //
    // struct tm
    // {
    //     int tm_sec;   // seconds after the minute - [0, 60] including leap second
    //     int tm_min;   // minutes after the hour - [0, 59]
    //     int tm_hour;  // hours since midnight - [0, 23]
    //     int tm_mday;  // day of the month - [1, 31]
    //     int tm_mon;   // months since January - [0, 11]
    //     int tm_year;  // years since 1900
    //     int tm_wday;  // days since Sunday - [0, 6]
    //     int tm_yday;  // days since January 1 - [0, 365]
    //     int tm_isdst; // daylight savings time flag
    // };
    //
    // struct tm layout
    // There's one for second after the minute,
    // minutes after the hour, hours since midnight,
    // day of the month scaled to one through 31,
    // the months since January,
    // and this one is actually scaled from zero to 11,
    // so we need to add one to that to get the month number.
    // Years since 1900, so if we want a four-digit date,
    // we have to add 1900 to that.
    // Days since Sunday, days since January first,
    // and a flag for whether or not our local timezones supports daylight savings time.
    printf("direct from struct tm:\n");
    // So, here we're using each of these members of this structure,
    // We're getting the year, we're adding 1900 to it,
    // To convert from tm_year to the Gregorian year, you add 1900.
    // We're getting the month, we're adding one to it,
    // and the day, hour, and time, and seconds,
    // and so this is the universal time,
    // UTC stands for "Universal Coordinated Time",
    // and we see that we're formatting it simply with printf().
    // (A very nice readable format.)
    printf("universal time is now %04d-%02d-%02d %02d:%02d:%02d\n",
           gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday,
           gmt.tm_hour, gmt.tm_min, gmt.tm_sec);
    // And the same thing for the local time.
    printf("local time is now %04d-%02d-%02d %02d:%02d:%02d\n",
           localt.tm_year + 1900, localt.tm_mon + 1, localt.tm_mday,
           localt.tm_hour, localt.tm_min, localt.tm_sec);

    puts("");

    char buf[bufsize]; // buffer for strftime()
    // And there's another function called strftime(),
    // which directly formats the time and it uses its own
    // formatting tokens that are different from printf(),
    // but they're pretty obvious here,
    // capital Y is for the four-digit year,
    // lowercase m is for the two-digit month, day, hours, minutes, and seconds,
    // and so again we have universal time and local time,
    // and these both use pointers to these tm structures.
    size_t len = strftime(buf, bufsize, "%Y-%m-%d %H:%M:%S", &gmt);
    // size_t strftime(char *_Buffer, size_t _SizeInBytes, const char *_Format, const tm *_Tm)
    printf("from strftime (gmt):\n");
    printf("universal time is now %s (%ld characters)\n", buf, len);

    len = strftime(buf, bufsize, "%Y-%m-%d %H:%M:%S %Z", &localt);
    printf("from strftime (localt):\n");
    printf("local time is now %s (%ld characters)\n", buf, len);

    puts("");

    // So, the basic time and date functions are rudimentary,
    // but they're standardized and they're functional for many purposes.
    // For more advanced time and date functionality,
    // we may need to use functions more specific
    // to our target operating system.

    return 0;
}
