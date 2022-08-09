// enumerations
#include <cstdio>
using namespace std;

// The C++ enumerated type called enum is a very useful thing.
// What's really interesting about this is that while it looks syntactically like a type,
// and it's even referred to as a type, it's not really a type in the same way as other types are.
// Enumerated names actually work more like constants than like types,
// and they make a great alternative to preprocessor constants.

// The keyword enum followed by the name of the enum
// and initializer list with the symbols
// that are going to be used for the enums.
// If we care about the values of the enum symbols,
// in the case with Spades, Hearts, Diamonds and Clubs,
// they're only ever used like that down here in the switch statement,
// so we don't really care what their values are.
enum card_suit
{
    SPD,
    HRT,
    DIA,
    CLB
};

// But if we do care, we can give them values, like this,
// and we can notice that we don't give values to King and Queen
// because by definition they're going to be sequential after the 11.
// Now, enum by default, has an underlying type of int,
// and so since we haven't specified anything else here,
// these are all treated as ints.
enum card_rank
{
    ACE = 1,
    DEUCE = 2,
    JACK = 11,
    QUEEN,
    KING
};

const char *aceString = "Ace";
const char *jckString = "Jack";
const char *queString = "Queen";
const char *kngString = "King";
const char *deuString = "Deuce";
const char *spdString = "Spades";
const char *hrtString = "Hearts";
const char *diaString = "Diamonds";
const char *clbString = "Clubs";

// Here we have a structure to represent the cards themselves,
// including rank and suit.
struct card
{
    unsigned char rank;
    unsigned char suit;
};

// And then here we have an array of cards.
// So when we initialize our array, we can notice that the structure for card
// has unsigned characters for rank and suit, and so ints will naturally promote
// to any scalar integer type, including unsigned char.
// So, we can initialize them with these enums,
// and we see that each of these at least has a suit enum,
// in the case of Ace, Deuce, Jack, Queen, and King, we used them interchangeably.
// We used 1, 2, and 11, 12, and 13, just as we used the enums
// and they can be used interchangeably because as far as the compiler's concerned,
// they resolve to the same thing.
card deck[52] = {
    {ACE, SPD}, {DEUCE, SPD}, {3, SPD}, {4, SPD}, {5, SPD}, {6, SPD}, {7, SPD}, \
    {8, SPD}, {9, SPD}, {10, SPD}, {JACK, SPD}, {QUEEN, SPD}, {KING, SPD},      \
    {1, HRT}, {2, HRT}, {3, HRT}, {4, HRT}, {5, HRT}, {6, HRT}, {7, HRT},       \
    {8, HRT}, {9, HRT}, {10, HRT}, {11, HRT}, {12, HRT}, {13, HRT},             \
    {1, DIA}, {2, DIA}, {3, DIA}, {4, DIA}, {5, DIA}, {6, DIA}, {7, DIA},       \
    {8, DIA}, {9, DIA}, {10, DIA}, {11, DIA}, {12, DIA}, {13, DIA},             \
    {1, CLB}, {2, CLB}, {3, CLB}, {4, CLB}, {5, CLB}, {6, CLB}, {7, CLB},       \
    {8, CLB}, {9, CLB}, {10, CLB}, {11, CLB}, {12, CLB}, {13, CLB}
};

// Then we print the cards using a switch...
void print_card(const card &c)
{
    if (c.rank >= 3 && c.rank <= 10)
    {
        printf("%d of ", c.rank);
    }
    else
    {
        // for card rank (for the Ace, Jack, Queen, King, and Deuce)
        // (that print out from string constants declared above)
        switch (c.rank)
        {
        case ACE:
            printf("%s of ", aceString);
            break;
        case JACK:
            printf("%s of ", jckString);
            break;
        case QUEEN:
            printf("%s of ", queString);
            break;
        case KING:
            printf("%s of ", kngString);
            break;
        case DEUCE:
            printf("%s of ", deuString);
            break;
        }
    }

    // for card suit (for the Spades, Hearts, Diamonds, and Clubs)
    // (that print out from string constants declared above)
    switch (c.suit)
    {
    case SPD:
        puts(spdString);
        break;
    case HRT:
        puts(hrtString);
        break;
    case DIA:
        puts(diaString);
        break;
    case CLB:
        puts(clbString);
        break;
    }
}

int main(int argc, char **argv)
{
    // What it does here is it lists out an entire deck of 52 cards in order.
    puts("The list of an entire deck of 52 cards:");
    puts("");
    for (card c : deck)
    {
        print_card(c);
    }
    puts("");
    // ******************************
    // So it really is that simple.
    // we could have used numbers here and
    // we could have used numbers in the switch statement,
    // but the code wouldn't have been as clear.
    // We could have used preprocessor constants,
    // and that would have also worked,
    // but then they're not typed and
    // they're not in the symbol table in the compiler.
    // ******************************
    // So for many uses constants may be a better choice
    // if we need something other than a scalar value,
    // but enum is often a great alternative to preprocessor constants,
    // and for some the enum type can be very handy as here,
    // for grouping scalar constants together
    // when they have a common usage.
    // ******************************
    return 0;
}
