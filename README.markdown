String library with protection from buffer overruns
===================================================

Introduction
------------

This project contains a library of functions to replace string.h with functions that protect against buffer overruns.
In addition, handling of circular buffers will be added.
The code is intended to be used on products that are required to be certified to IEC61508 (and possibly the FDA equivalent).
This puts restrictions on dynamic memory allocations so unlike most modern string libraries, this library does not expand buffers to fit strings but rather it fails safely and predictably if an overrun would occur.

The basic string type is not simply a `char *`, it is a `struct` that contains a pointer to the character buffer and the size of the buffer. The buffer will still be zero terminated so that the string.h functions can be used once the overrun conditions have been checked. This keeps the library code small and uses the optimized string.h functions to do the compute intensive work.

The functions implemented are:
```
    bool        mstrInit(mstring * newString, const char * const buffer, const mstrSize_t newSize)
    bool        mstrSet(mstring *mdest, const char *msrc)
    mstrSize_t  mstrLen(const mstring const * msrc)
    bool        mstrCatLiteral(mstring *mdest, const char *msrc)
    bool        mstrCpy(mstring *, const mstring *)
    int16_t     mstrCmp(const mstring * str1, const mstring * str2)
    int16_t     mstrCmpLiteral(const mstring * str1, const char * str2)
    int16_t     mstrCmpLimited(const mstring * str1, const mstring * str2, const uint16_t limit_number_of_chars)
    int16_t     mstrCmpLiteralLimited(const mstring * str1, const char * str2, const uint16_t limit_number_of_chars)
    char *      mstrget_next_param(const mstring * const param_string, char ** pOffsetResult)
    bool        mstrToUpper(mstring* msrc)
```
The full string library contains these other functions which I intend to implement sometime:
```
    _PTR    memchr(const _PTR, int, size_t)
    _PTR    memmove(_PTR, const _PTR, size_t)
    char *  strchr(const char *, int)
    int     strcoll(const char *, const char *)
    size_t  strcspn(const char *, const char *)
    char *  strerror(int)
    char *  strpbrk(const char *, const char *)
    char *  strrchr(const char *, int)
    size_t  strspn(const char *, const char *)
    char *  strstr(const char *, const char *)
            printf?
            sprintf?
            itoa
            atoi
            scanf
            strtok (probably not as mstrget_next_param works well for this)
```

TODO
----

Figure out how to handle errors. ASSERT? global error 'object'. What does MISRA suggest?

Alan Widmer
