/** @file
 * Library header file. This file must be included in every source file that uses mstrings
 */

#ifndef MSTRING_H_
#define MSTRING_H_

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "Problems.h"


/* TODO: Assume for now that maximum string length is 65535. Later this should
 * be a compile variable.
 */
typedef uint16_t mstrSize_t;


#define mstrAssert(x) {LogProblem(x, __FILE__, __LINE__);}

typedef struct managedString {
    char * string;
    mstrSize_t size;
} mstring;

extern bool mstrInit(mstring * newString, char * buffer, const mstrSize_t newSize);
extern bool mstrSet(mstring *mdest, const char *msrc);
extern mstrSize_t mstrLen(const mstring const * msrc);
extern bool mstrCpy(mstring *, const mstring *);


#endif /* MSTRING_H_ */
