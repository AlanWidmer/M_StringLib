/** @file
 * Library header file. This file must be included in every source file that
 * uses u8 managed arrays (marrays)
 */

#ifndef MARRAY_H_
#define MARRAY_H_

#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include "problems.h"


/* Assume for now that maximum array length is 65535. Later this should
 * be a compile variable.
 */
typedef uint16_t marray_size_t;

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

#define mstrProblem(x) {LogProblemFull(x, __FILE__, __LINE__);}
#define mstrAssert(c, x) {if (!c) {LogProblemFull(x, __FILE__, __LINE__);}}

typedef struct managed_array_u8 {
    uint8_t * array;
    marray_size_t size;
    marray_size_t length;
} marray_u8;

extern bool marrayU8Init(marray_u8 * newarray, uint8_t * const buffer, const marray_size_t newSize);
extern bool marrayU8Set(marray_u8 *mdest, uint8_t * const msrc, marray_size_t src_length);
extern marray_size_t marrayU8Len(const marray_u8 const * msrc);
extern bool marrayU8Cpy(marray_u8 * dest, const marray_u8 * src);
extern int16_t marrayU8Cmp(const marray_u8 * array1, const marray_u8 * array2);
extern bool marrayU8CatLiteral(marray_u8 *mdest, const uint8_t *msrc);

#endif /* MARRAY_H_ */
