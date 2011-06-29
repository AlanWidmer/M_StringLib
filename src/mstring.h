/** @file
 * Library header file. This file must be included in every source file that uses mstrings
 */

#ifndef MSTRING_H_
#define MSTRING_H_

#include <string.h>
#include <stdbool.h>

/* TODO: Assume for now that maximum string length is 65535. Later this should
 * be a compile variable.
 */
typedef uint16_t mstrSize_t;

typedef struct mstring {
    char *;
    mstrSize_t size;
};

void mstrAssert(bool assertion);
bool mstrInit(mstring newString, char * buffer, mstrSize_t newSize);

#endif /* MSTRING_H_ */
