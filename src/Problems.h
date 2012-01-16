/** @file
 * Contains the definitions for the code that traps problems in the running
 * code. This is an extension to the assert C library and adds features that
 * are richer and specifically tailored to embedded systems.
 * @author Alan Widmer
 */

#ifndef PROBLEMS_H_
#define PROBLEMS_H_
#include <stdbool.h>

/** This enum is used during development to indicate errors that should
 * never occur. The values start at 0x4000 in order to disambiguate them
 * from the other MISC_FAIL codes in the event logging.
 * @note IT is a MISRA requirement that if one value is specified in an enum
 * then all values must be specified.
 */
typedef enum problem
{
    NO_PROBLEM = 0,
    NULL_POINTER = 0x4000,
    UNEXPECTED_CASE = 0x4001,
    DIV_BY_ZERO = 0x4002,
    LOG_OF_ZERO = 0x4003,
    PARAM_OVERRANGE = 0x4004,
    PARAM_UNDERRANGE = 0x4005,
    ILLEGAL_MATH = 0x4006,
    RTOS_TIMEOUT = 0x4007,
    INVALID_NVM_ADDRESS = 0x4008,
    MAILBOX_SIZE_INCORRECT = 0x4009,
    UNHANDLED_CONDITION = 0x400A,
    MAILBOX_POST_OVERRUN = 0x400B,
    MAILBOX_PEND_FAIL = 0x400C,
    SEMAPHORE_PEND_FAIL = 0x400D,
    UNIMPLEMENTED = 0x400E,
    SPI_TIMEOUT = 0x400F,
    MODBUS_WDOG_RESET = 0x4010,
    SPI_UNEXPECTED_COMMAND = 0x4011,
    CPU_FAILURE = 0x4012,
    BOOT_CAUSE_PROBLEM = 0x4013,
    UNKNOWN_HWREV_NAME = 0x4014,
    UNEXPECTED_REBOOT = 0x4015
} _problemID;

typedef struct
{
    _problemID ID;
} _problemStore;

/* Externally defined variables "extern" go here, if not in above includes. */

/* All prototypes of externally referenced functions go here. */


/* Validate the size of a message buffer against mailbox message size */
extern _problemStore problemIDStore;
extern void LogProblem(_problemID problemID, char * file, int lineNumber);

#ifndef _NDEBUG
    extern void AssertProblem(bool assertCondition, _problemID problemID);
#else
#define AssertProblem(X, Y) {}
#endif

#endif /* PROBLEMS_H_ */
