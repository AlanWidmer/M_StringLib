This project contains a library of functions to replace string.h with functions that protect against buffer overruns.
In addition, handling of circular buffers will be added.
The code is intended to be used on products that are required to be certified to IEC61508 (and possibly the FDA equivalent).
This puts restrictions on dynamic memory alocations so unlike most modern string libraries, this library does not expand buffers to fit strings but rather it fails safely and predictably if an overrun would occur.

The basic string type is not simply a char *, it is a struct that contains a pointer to the character buffer and the size of the buffer. The buffer will still be zero terminiated so that the string.h functions can be used once the overrun conditions have been checked. This keeps the library code small and uses the optimized string.h functions to do the compute intensive work.

Alan Widmer 