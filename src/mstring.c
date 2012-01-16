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
bool mstrInit(mstring * newString, const char const * buffer, const mstrSize_t newSize)
{
    bool initSuccess = true;
    if (buffer == NULL)
    {
        initSuccess = false;
        newString->size = 0;
        newString->string = NULL;
    }
    else
    {
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
 * @return
 */
bool mstrSet(mstring *mdest, const char *msrc)
{
    bool success, terminated=false;
    mstrSize_t i;
    while ((i<mdest->size) && !terminated)
    {
        if(msrc[i]==0)
        {
            terminated = true;
        }
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
bool mstrCpy(mstring *mdest, const mstring *msrc)
{
    bool success = true;
    if (msrc->string == NULL || mdest->string == NULL)
    {
        success = false;
    }
    else
    {
        mstrSize_t i, limit;
        bool terminated = false;
        if((msrc->size) <= (mdest->size))
        {
            limit = msrc->size;
        }
        else
        {
            limit = mdest->size;
        }
        while ((i <= limit) && (!terminated))
        {
            mdest->string[i] = msrc->string[i];
            if (msrc->string[i] == 0)
            {
                terminated = true;
            }
            i++;

        }
        if (!terminated)
        {
            mdest->string[i] = 0;
            success = false;
        }
    }

    return success;
}


/**
 * Returns the length of the source string. If the source is found to not be
 * null terminated the length returned is the size of the mstring buffer - 1;
 * @param msrc
 * @return
 */
mstrSize_t mstrLen(const mstring const * msrc)
{
    mstrSize_t i=0, length;
    while (i< msrc->size && msrc->string[i] != 0)
    {

    }
    length = i;
    return length;
}


/**
 *
 * @param assertion
 */
void mstrAssert(bool assertion)
{
    if (!assertion)
    {
        for (int i = 0;1;)
        {

        }
    }
}
