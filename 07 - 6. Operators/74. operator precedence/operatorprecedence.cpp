// operator precedence
#include <cstdio>
using namespace std;

// Operator Precedence is the order in which operators
// are evaluated in an expression.

// In this 33 * 7 + 21 / 7 expression we could have different results
// depending on what order it's evaluated in.
// For example, using parentheses to bind parts of the expression together.
// If we give precedence to the addition then we get this result.
// 33 * (7 + 21) / 7 = 132
// And if we move the parentheses around a bit we get a different result.
// ((33 * 7) + 21) / 7 = 36
// And if remove the parentheses altogether we get yet a different result.
// 33 * 7 + 21 / 7 = 234
// The order of evaluation without any parentheses is its
// division happens first, then the multiplication, and then the addition.
// It's as if it were parenthesized like this.
// (33 * 7) + (21 / 7) = 234

// The point of understanding Operator Precedence is to be aware of the rules.
// We don't need to memorize the rules.
// There are plenty of handy reference tables available
// but we do need to know that this is how it works.
// And ultimately, if we care about the order of the evaluation of an expression
// it's always best to use parentheses.

// There is an Operator Precedence table (pdf) in th folder.
// The Precedence is the order of evaluation.
// And associativity is the order in which the Operators are evaluated.
// Most Operators are evaluated left to right except prefix, unary,
// and assignment Operators are evaluated right to left.

// It's important to understand Operator Precedence
// but it's not so important to memorize it.
// It's easy to keep a (laminated) chart near our workstation
// for when we need to read someone else's code
// who may not have been so considerate as to use parentheses.

// Most of the time though, it's a good idea to use parentheses
// to specify the order that we want our expressions to be evaluated in.
// That will make our job a lot easier when we want to read the code later.

int main(int argc, char **argv)
{
    puts("Operator Precedence");

    return 0;
}
