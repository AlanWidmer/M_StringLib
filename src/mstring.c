/** @file
 * All of the functions that make up the mstring library
 *  @author Alan Widmer
 */
#include "mstring.h"

/**
 * Initializes the mstring with its size and buffer. This function initializes
 * the string to a NULL string.
 * @param newString A string of type mstring that will have been initialized if
 * this function returns without error
 * @param buffer The buffer that will hold the contents of the string. The
 * string will be zero terminated at all times so the buffer must be sized to
 * accommodate the extra character.
 * @param newSize The size of the buffer allocated by the calling function to
 * hold the mstring.
 * @return True if the string initialized correctly, false if there was an
 * error during initialization.
 */
bool mstrInit(mstring * newString, const char * const buffer,
              const mstrSize_t newSize) {
  bool initSuccess = true;
  if (buffer == NULL) {
    initSuccess = false;
    newString->size = 0;
    newString->string = NULL;
  } else {
    newString->size = newSize - 1;
    newString->string = buffer;
    newString->string[0] = 0; /* Null terminated string with zero length */
  }
  return initSuccess;
}


/**
 * Sets the destination mstring to be a copy of the source string. The source
 * is a char buffer containing a null terminated C string. This is useful for
 * setting the mstring to a string constant.
 * @param mdest
 * @param msrc
 * @return true if the string was set with no errors, false if there was an
 *  error
 */
bool mstrSet(mstring *mdest, const char *msrc) {
  bool success, terminated = false;
  mstrSize_t i = 0;
  while ((i < mdest->size) && !terminated) {
    mdest->string[i] = msrc[i];
    if (msrc[i] == 0) {
      terminated = true;
    }
    i++;
  }
  if (!terminated) {
    mdest->string[i] = '\0'; /* Make sure it's null terminated */
  }
  //TODO The success variable may be redundant
  success = terminated;
  return success;
}

/**
 * Copy the source string to the destination. If the source string is longer
 * than the destination size, the string is copied until the destination is
 * full and false is returned. If either source or destination is NULL then
 * false is returned.
 * @param mdest A string that will be set equal to the source.
 * @param msrc The source string to be copied to the destination.
 * @return False if an error occurred, true if there were no errors.
 */
bool mstrCpy(mstring *mdest, const mstring *msrc) {
  bool success = true;
  if (msrc->string == NULL || mdest->string == NULL) {
    success = false;
  } else {
    mstrSize_t i = 0;
    mstrSize_t limit;
    bool terminated = false;
    if ((msrc->size) <= (mdest->size)) {
      limit = msrc->size;
    } else {
      limit = mdest->size;
    }
    while ((i <= limit) && (!terminated)) {
      mdest->string[i] = msrc->string[i];
      if (msrc->string[i] == 0) {
        terminated = true;
      }
      i++;

    }
    if (!terminated) {
      mdest->string[i] = 0;
      success = false;
    }
  }

  return success;
}


/**
 * Returns the length of the source string. If the source is found to not be
 * null terminated the length returned is the size of the mstring buffer - 1;
 * @param msrc The string whose length is to be determined
 * @return The number of characters in the string. Does not include the null termination character.
 */
mstrSize_t mstrLen(const mstring const * msrc) {
  mstrSize_t i = 0, length;
  while (i < msrc->size && msrc->string[i] != 0) {
    i++;
  }
  length = i;
  return length;
}

/**
 * Copy the source string to the end of the destination string. If the resultant
 * string would be longer
 * than the destination size, the string is copied until the destination is
 * full and false is returned. If either source or destination is NULL then
 * false is returned.
 * @param mdest A string that will be set equal to the source.
 * @param msrc The source string to be copied to the destination.
 * @return False if an error occurred, true if there were no errors.
 */
bool mstrCatLiteral(mstring *mdest, const char *msrc) {
  bool success = true;
  if (mdest->string == NULL) {
    success = false;
  } else {
    mstrSize_t i = 0;
    mstrSize_t k = 0;

    bool terminated = false;

    i = mstrLen(mdest);
    while ((i <= mdest->size) && (!terminated)) {
      mdest->string[i] = msrc[k];
      if (msrc[k] == 0) {
        terminated = true;
      }
      i++;
      k++;
    }
    if (!terminated) {
      mdest->string[i] = 0;
      success = false;
    }
  }

  return success;
}

/**
 * Compares two strings. The mstrCmp function compares the string str1 against
 * str2, returning a value that has the same sign as the difference between
 * the first differing pair of characters (interpreted as unsigned char
 * objects, then promoted to int).
 * If the two strings are equal, mstrCmp returns 0.
 * A consequence of the ordering used by mstrCmp is that if s1 is an initial
 * substring of str2, then str1 is considered to be less than str2.
 * mstrCmp does not take sorting conventions of the language the strings are written in into account.
 * @param str1 The first string
 * @param str2 The second string
 * @return <0 the first character that does not match has a lower value in str1 than in str2
 *         0 the contents of both strings are equal
 *         >0 the first character that does not match has a greater value in str1 than in str2
 */
int16_t mstrCmp(const mstring * str1, const mstring * str2) {
  return (strncmp(str1->string, str2->string, MIN(str1->size, str2->size)));
}

/**
 * Compares two strings. The mstrCmp function compares the string str1 against
 * str2, returning a value that has the same sign as the difference between
 * the first differing pair of characters (interpreted as unsigned char
 * objects, then promoted to int).
 * If the two strings are equal, mstrCmp returns 0.
 * A consequence of the ordering used by mstrCmp is that if s1 is an initial
 * substring of str2, then str1 is considered to be less than str2.
 * mstrCmp does not take sorting conventions of the language the strings are written in into account.
 * @param str1 The first string
 * @param str2 The second string
 * @return <0 the first character that does not match has a lower value in str1 than in str2
 *         0 the contents of both strings are equal
 *         >0 the first character that does not match has a greater value in str1 than in str2
 */
int16_t mstrCmpLiteral(const mstring * str1, const char * str2) {
  return (strncmp(str1->string, str2, str1->size));
}

/**
 * Compares two strings. The mstrCmp function compares the string str1 against
 * str2, returning a value that has the same sign as the difference between
 * the first differing pair of characters (interpreted as unsigned char
 * objects, then promoted to int).
 * If the two strings are equal, mstrCmp returns 0.
 * A consequence of the ordering used by mstrCmp is that if s1 is an initial
 * substring of str2, then str1 is considered to be less than str2.
 * mstrCmp does not take sorting conventions of the language the strings are written in into account.
 * @param str1 The first string
 * @param str2 The second string
 * @param limit_number_of_chars limit the number of characters compared to this number.
 * The result returned is based on the result of just comparing this number of characters.
 * @return <0 the first character that does not match has a lower value in str1 than in str2
 *         0 the contents of both strings are equal
 *         >0 the first character that does not match has a greater value in str1 than in str2
 */
int16_t mstrCmpLimited(const mstring * str1, const mstring * str2, const uint16_t limit_number_of_chars) {
  uint16_t limit_count = MIN(str1->size, str2->size);
  limit_count = MIN(limit_count, limit_number_of_chars);
  return (strncmp(str1->string, str2->string, limit_count));
}

/**
 * Compares two strings. The mstrCmp function compares the string str1 against
 * str2, returning a value that has the same sign as the difference between
 * the first differing pair of characters (interpreted as unsigned char
 * objects, then promoted to int).
 * If the two strings are equal, mstrCmp returns 0.
 * A consequence of the ordering used by mstrCmp is that if s1 is an initial
 * substring of str2, then str1 is considered to be less than str2.
 * mstrCmp does not take sorting conventions of the language the strings are written in into account.
 * @param str1 The first string
 * @param str2 The second string
 * @param limit_number_of_chars limit the number of characters compared to this number.
 * The result returned is based on the result of just comparing this number of characters.
 * @return <0 the first character that does not match has a lower value in str1 than in str2
 *         0 the contents of both strings are equal
 *         >0 the first character that does not match has a greater value in str1 than in str2
 */
int16_t mstrCmpLiteralLimited(const mstring * str1, const char * str2, const uint16_t limit_number_of_chars) {
  return (strncmp(str1->string, str2, MIN(str1->size, limit_number_of_chars)));
}

/**
 * This function returns a pointer to a string that is the next string up to
 * the delimiter ',' or the end of string. The pointer returned points to a
 * null terminated string because this function replaces the delimiter with
 * a null. This means that the original string is modified as this function is
 * called.
 * Yes I am aware of the library function strtok() but it requires dynamic
 * memory allocation and this was deemed undesirable as none of the rest
 * of the code uses malloc() or free() and we would have to consider memory
 * fragmentation.
 * @param param_string Points to the string to extract the next parameter
 * from.
 * @param pOffsetResult On entry this is a pointer to the start of the string
 * to process to extract parameters in a comma separated list. On exit from
 * the function it point to the start of the next parameter or a null if this
 * call found the last parameter in the list.
 * @note pOffsetResult must point to a position in the ->string field of
 * param_string
 * @return Pointer to the start of a null terminated string that is the next
 * parameter in a comma separated list of parameters.
 */
char * mstrget_next_param(const mstring * const param_string,
                          char ** pOffsetResult) {
  char * stringStart;

  stringStart = *pOffsetResult;
  AssertProblem(*pOffsetResult != NULL, PROBLEM_NULL_POINTER);
  if (*pOffsetResult != '\0') {
    /* Loop until we find the next delimiter or end of string */
    // TODO add a check that the size of param_string has not been exceeded
    // TODO Allow for other PARAM_DELIMITERs, should be able to specify a list eg ",;\s\t"
    while ((**pOffsetResult != PARAM_DELIMITER) && (**pOffsetResult != '\0')) {
      (*pOffsetResult)++;
    }
    if (**pOffsetResult != '\0') {
      /* Change the comma delimiter to a termination character. */
      **pOffsetResult = '\0';
      /* Update to point to the char after the end of this substring */
      (*pOffsetResult)++;
    }
  }
  return (stringStart);
}


/**
 * Convert a string to all upper case ascii. The string is converted in-place, there is no copy.
 * If the input string is "Cat" the same string after this function call will be "CAT"
 * @param msrc The string to be converted
 * @return True if the function completed without error. False if there was an error.
 * Currently there are no error conditions and the function always returns true.
 * @note This may not be the most efficient implementation because it uses the
 * ctype macro toupper repeatedly and there is a lot of promoting from char to int
 * and back to char.
 */
bool mstrToUpper(mstring* msrc) {
  mstrSize_t i = 0;
  while (i < msrc->size && msrc->string[i] != 0) {
    msrc->string[i] = toupper(msrc->string[i]);
    i++;
  }

  return true;

}
