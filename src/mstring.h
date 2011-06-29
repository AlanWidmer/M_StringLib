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
typedef uint16_t mstrSize;

typedef struct mstring_t {
    char * string;
    mstrSize size;
} mstring;

#define mstrAssert(x) {LogProblem(bool x, __FILE__, __LINENO__);}
bool mstrInit(mstring newString, char * buffer, mstrSize newSize);

#endif /* MSTRING_H_ */
