String library with protection from buffer overruns
===================================================

Introduction
------------

This project contains a library of functions to replace string.h with functions that protect against buffer overruns.
In addition, handling of circular buffers will be added.
The code is intended to be used on products that are required to be certified to IEC61508 (and possibly the FDA equivalent).
This puts restrictions on dynamic memory allocations so unlike most modern string libraries, this library does not expand buffers to fit strings but rather it fails safely and predictably if an overrun would occur.

The basic string type is not simply a `char *`, it is a `struct` that contains a pointer to the character buffer and the size of the buffer. The buffer will still be zero terminated so that the string.h functions can be used once the overrun conditions have been checked. This keeps the library code small and uses the optimized string.h functions to do the compute intensive work.

The full string library that I intend to implement is:

    _PTR     memchr(const _PTR, int, size_t)
    int      memcmp(const _PTR, const _PTR, size_t)
    _PTR     memcpy(_PTR, const _PTR, size_t)
    _PTR     memmove(_PTR, const _PTR, size_t)
    _PTR     memset(_PTR, int, size_t)
    char *  strcat(char *, const char *)
    char *  strchr(const char *, int)
    int     strcmp(const char *, const char *)
    int     strcoll(const char *, const char *)
    char *  strcpy(char *, const char *)
    size_t  strcspn(const char *, const char *)
    char *  strerror(int)
    size_t  strlen(const char *)
    char *  strncat(char *, const char *, size_t)
    int     strncmp(const char *, const char *, size_t)
    char *  strncpy(char *, const char *, size_t)
    char *  strpbrk(const char *, const char *)
    char *  strrchr(const char *, int)
    size_t  strspn(const char *, const char *)
    char *  strstr(const char *, const char *)

Alan Widmer 
