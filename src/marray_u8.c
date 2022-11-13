/** @file
 * All of the functions that make up the marray library
 * @copyright Alan Widmer
 * All Rights Reserved
 * @author Alan Widmer
 */
#include <stddef.h>
#include <string.h>
#include "marray_u8.h"

/**
 * Initializes the marray with its size and buffer. This function initializes
 * the array to an empty array.
 * @param newArray A array of type marray that will have been initialized if
 * this function returns without error
 * @param buffer The buffer that will hold the contents of the u8 array.
 * @param newSize The size of the buffer allocated by the calling function to
 * hold the array.
 * @return True if the array initialized correctly, false if there was an
 * error during initialization.
 */
bool marrayU8Init(marray_u8 * newArray, uint8_t * const buffer,
              const marray_size_t newSize) {
  bool initSuccess = true;
  newArray->length = 0; // No elements in the array yet
  if (buffer == NULL) {
    initSuccess = false;
    newArray->size = 0;
    newArray->array = NULL;
  } else {
    newArray->size = newSize;
    newArray->array = buffer;
  }
  return initSuccess;
}


/**
 * Sets the destination marray to be a copy of the source array. The source
 * is a buffer containing a uint8 array. This is useful for
 * setting the marray to an array constant.
 * @param mdest
 * @param msrc
 * @param src_length The number of elements in the src
 * @return true if the array was set with no errors, false if there was an
 *  error
 */
bool marrayU8Set(marray_u8 *mdest, uint8_t * const msrc, marray_size_t src_length) {
  bool success = false;
  marray_size_t length;
  marray_size_t i = 0;

  length = MIN(mdest->size, src_length);
  while ((i < length)) {
    mdest->array[i] = msrc[i];
    i++;
  }
  mdest->length = i;
  success = true;
  return success;
}

/**
 * Copy the source array to the destination. If the source array is longer
 * than the destination size, the array is copied until the destination is
 * full and false is returned. If either source or destination is NULL then
 * false is returned.
 * @param mdest A array that will be set equal to the source.
 * @param msrc The source array to be copied to the destination.
 * @return False if an error occurred, true if there were no errors.
 */
bool marrayU8Cpy(marray_u8 *mdest, const marray_u8 *msrc) {
  bool success = true;
  if (msrc->array == NULL || mdest->array == NULL) {
    success = false;
  } else {
    marray_size_t i = 0;
    marray_size_t limit;
    if ((msrc->length) <= (mdest->size)) {
      limit = msrc->length;
    } else {
      limit = mdest->size;
    }
    while (i <= limit) {
      mdest->array[i] = msrc->array[i];
      i++;
    }
    mdest->length = i;
  }

  return success;
}


/**
 * Returns the length of the source array. If the source has no elements then the
 * length is zero.
 * @param msrc The array whose length is to be determined
 * @return The number of elements in the array.
 */
marray_size_t marrayU8Len(const marray_u8 const * msrc) {

  return msrc->length;
}


/**
 * Copy the source array to the end of the destination array. If the resultant
 * array would be longer
 * than the destination size, the array is copied until the destination is
 * full and false is returned. If either source or destination is NULL then
 * false is returned.
 * @param mdest A array that will be set equal to the source.
 * @param msrc The source array to be copied to the destination.
 * @return False if an error occurred, true if there were no errors.
 */
bool marrayU8CatLiteral(marray_u8 *mdest, const uint8_t *msrc) {
  bool success = true;
  if (mdest->array == NULL) {
    success = false;
  } else {
    marray_size_t i = 0;
    marray_size_t k = 0;

    i = marrayU8Len(mdest);
    while (i <= mdest->size) {
      mdest->array[i] = msrc[k];
      i++;
      k++;
    }
  }

  return success;
}


/**
 * Compares two arrays. The marrayCmp function compares the array array1 against
 * array2, returning a value that has the same sign as the difference between
 * the first differing pair of characters (interpreted as unsigned char
 * objects, then promoted to int).
 * If the two arrays are equal, marrayCmp returns 0.
 * @param array1 The first array
 * @param array2 The second array
 * @return <0 the first value that does not match has a lower value in array1 than in array2
 *         0 the contents of both arrays are equal
 *         >0 the first character that does not match has a greater value in array1 than in array2
 */
int16_t marrayU8Cmp(const marray_u8 * array1, const marray_u8 * array2) {
  return (memcmp(array1->array, array2->array, MIN(array1->length, array2->length)));
}

