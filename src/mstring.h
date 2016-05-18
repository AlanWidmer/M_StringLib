/** @file
 * Library header file. This file must be included in every source file that uses mstrings
 */

#ifndef MSTRING_H_
#define MSTRING_H_

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include "problems.h"


/* TODO: Assume for now that maximum string length is 65535. Later this should
 * be a compile variable.
 */
typedef uint16_t mstrSize_t;

#define PARAM_DELIMITER ' '

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

#define mstrProblem(x) {LogProblemFull(x, __FILE__, __LINE__);}
#define mstrAssert(c, x) {if (!c) {LogProblemFull(x, __FILE__, __LINE__);}}

typedef struct managedString {
    char * string;
    mstrSize_t size;
} mstring;

extern bool mstrInit(mstring * newString, const char * const buffer, const mstrSize_t newSize);
extern bool mstrSet(mstring *mdest, const char *msrc);
extern mstrSize_t mstrLen(const mstring const * msrc);
extern bool mstrCatLiteral(mstring *mdest, const char *msrc) ;
extern bool mstrCpy(mstring *, const mstring *);
extern int16_t mstrCmp(const mstring * str1, const mstring * str2);
extern int16_t mstrCmpLiteral(const mstring * str1, const char * str2);
extern int16_t mstrCmpLimited(const mstring * str1, const mstring * str2, const uint16_t limit_number_of_chars);
extern int16_t mstrCmpLiteralLimited(const mstring * str1, const char * str2, const uint16_t limit_number_of_chars);
extern char * mstrget_next_param(const mstring * const param_string, char ** pOffsetResult);
extern bool mstrToUpper(mstring* msrc);

#endif /* MSTRING_H_ */
