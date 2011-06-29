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
bool mstrInit(mstring newString, char * buffer, mstrSize newSize)
{
  bool successFlag = false;
  if ((buffer != NULL) && (newSize != 0))
  {
    newString.string = buffer;
    newString.size = newSize;
    successFlag = true;
  }
  else
    {
      newString.size = 0;
      // TODO LogProblem(NULL_POINTER);
    }
  return successFlag;
}
