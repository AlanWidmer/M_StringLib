/**
 * @file
 *
 * This file contains the handling of fatal errors and assertions.
 *
 * @author Alan Widmer
 */
#include "Problems.h"
/** This variable is used to save any fault codes that caused a reset
 * then the code is written to the fault event log after the reset has
 * restarted the firmware
 */
_problemStore problemIDStore; /* Deliberately not initialized */


/**
 * When a firmware problem is detected this function will record it
 * The problem will be for unexpected things like a NULL pointer, CASE:
 * should never be reached, invalid parameters passed to a function, etc.
 * @param problemID Unique ID of the problem that will allow it to be traced
 *  back to a line of source.
 * @warning Don't use this for fault handling that is a external fault. This
 * code is specifically for firmware problems that are unexpected. May be
 * compiled out of final customer code and just used during development on some
 * projects.
 */
void LogProblem(_problemID problemID, char * file, int lineNumber)
{
    problemIDStore.ID = problemID;
    // TODO ESTOP0;
    for (;;);
    problemIDStore.ID = problemID; /* Dummy to allow skipping to this point */
}


/**
 * When a firmware problem is detected this function will record it
 * The problem will be for unexpected things like a NULL pointer, CASE:
 * should never be reached.
 * The problem is only logged if the assertCondition is false
 * @param assertCondition A true or false flag that is the result of the
 * condition being checked. Typically the assert condition is written directly
 * into the function call as the parameter.
 * @param problemID An enumeration that specifies the class of problem that
 * was being checked for.
 * @warning Don't use this for fault handling that is a external fault. This
 * code is specifically for firmware problems that are unexpected. May be
 * compiled out of final customer code and just using development on some
 * projects.
 */
#ifndef _NDEBUG
void AssertProblem(bool assertCondition, _problemID problemID)
{
    if (!assertCondition)
    {
        problemIDStore.ID = problemID;
        //TODO ESTOP0;
        for (;;)
            ;
        problemIDStore.ID = problemID; /* Dummy to allow skipping to this point */
    }
}
#endif
