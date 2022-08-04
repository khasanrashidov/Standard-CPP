// conditional.h by Khasan Rashidov
//////////////////////////////////////////////////
// #if is "if"
// #ifdef stands for "if defined"
// #ifndef stands for "if not defined"
// #else is "else"
// #elif stands for "else if"
// #endif is "end if"
//////////////////////////////////////////////////
// we can say
////////// #if defined(MACRO) ////////////////////
// which is the same as #ifdef
// and with the exclamation point
////////// #if !defined(MACRO) ////////////////////
// it's the same as
//////////////////////////////////////////////////

#ifndef CONDITIONAL_H_
#define CONDITIONAL_H_

#if defined(FOO)

#define NUMBER 20

#else

#define NUMBER 5

#endif

#endif /* CONDITIONAL_H_*/
