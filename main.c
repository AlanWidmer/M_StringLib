/**
 * @file
 *
 * This is the main file, which is included only as an example of library usage.
 *
 * @author Alan Widmer
 */

#include "mstring.h"
#include <assert.h>

#define A_SIZE 10
#define B_SIZE 8
#define C_SIZE 12
#define D_SIZE 10


/**
 * Main function calls a series of test cases to show how the functions are used.
 * It assumes that the string.h printf( ) function will display text on the host machine in the IDE or debugger
 *
 */
int main(void)
{
    /* Declare a few strings */
    mstring a;
    char aBuf[A_SIZE];
    mstring b;
    char bBuf[B_SIZE];
    mstring c;
    char cBuf[C_SIZE];
    mstring d;
    char dBuf[D_SIZE];

    /* Unit tests */

    /* Check that instantiating the string does not return an fault */
    assert(mstrInit(&a, aBuf, A_SIZE));

    /* Check that the strings length is what we expect. For a newly
     * instantiated string the length should be zero. */
    assert(mstrLen(&a) == 0);

    /* Set the string to a known value */
    assert(mstrSet(&a, "Test 3"));

    /* Check the length of the string is as expected */
    assert(mstrLen(&a) == 6);

    /* Try setting the string to the NULL string */
    assert(mstrSet(&a, ""));

    /* Check the length of the string is as expected */
    assert(mstrLen(&a) == 0);

    /* Check that instantiating a shorter string does not return an fault */
    assert(mstrInit(&b, bBuf, B_SIZE));

    /* Check that the strings length is what we expect. For a newly
     * instantiated string the length should be zero. */
    assert(mstrLen(&b) == 0);

    /* Copy the a string to the b string */
    assert(mstrCpy(&b , &a));

    /* Check that the lengths are now the same */
    assert(mstrLen(&b) == mstrLen(&a));

    /* Check that the length of b is the same as the C style length */
    assert(mstrLen(&b) == strlen(bBuf));
}
