/*******************************************************************************
** $Revision: 3$
** $Date: 24/09/2014 08:33:37 a.m.$
** $Author: Bernabé Scarso$
**                                 COPYRIGHT (C) FORKWORKS. All rights reserved.
*******************************************************************************/
#ifndef _TYPES_H
#define _TYPES_H

#if defined (__arm__) 
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#define PACKED                              __packed
#define inline                              __inline              
#endif
#if defined(_MSC_VER)

#ifdef __cplusplus
    /// \exclude
    using std::size_t;
    /// \exclude
    typedef std::ptrdiff_t ssize_t;
#endif

    /// \exclude
    typedef signed char int8_t;
    /// \exclude
    typedef unsigned char uint8_t;

#if USHRT_MAX == 0xffff
    /// \exclude
    typedef short int16_t;
    /// \exclude
    typedef unsigned short uint16_t;
#elif UINT_MAX == 0xffff
    /// \exclude
    typedef int int16_t;
    /// \exclude
    typedef unsigned int uint16_t;
#elif ULONG_MAX == 0xffff
    /// \exclude
    typedef long int16_t;
    /// \exclude
    typedef unsigned long uint16_t;
#endif

#if USHRT_MAX == 0xffffffffUL
    /// \exclude
    typedef short int32_t;
    /// \exclude
    typedef unsigned short uint32_t;
#elif UINT_MAX == 0xffffffffUL
    /// \exclude
    typedef int int32_t;
    /// \exclude
    typedef unsigned int uint32_t;
#elif ULONG_MAX == 0xffffffffUL
    /// \exclude
    typedef long int32_t;
    /// \exclude
    typedef unsigned long uint32_t;
#endif

#if UINT_MAX == 18446744073709551615ULL
    #define PT_WITH_INT64 1
    /// \exclude
    typedef int int64_t;
    /// \exclude
    typedef unsigned int uint64_t;
#elif ULONG_MAX == 18446744073709551615ULL
    #define PT_WITH_INT64 1
    /// \exclude
    typedef long int64_t;
    /// \exclude
    typedef unsigned long uint64_t;
#elif ULLONG_MAX == 18446744073709551615ULL
    #define PT_WITH_INT64 1
    /// \exclude
    typedef long long int64_t;
    /// \exclude
    typedef unsigned long long uint64_t;
#endif

#elif defined(__GNUC__) || defined(__MWERKS_SYMBIAN__) //defined(__arm)
    #define PT_WITH_INT64 1
    /// \exclude
    typedef long long int64_t;
    /// \exclude
    typedef unsigned long long uint64_t;
#endif

typedef double real_T;
typedef float  real32_T;

/* Auxiliary boolean types */
typedef uint8_t bool8_t;
typedef uint16_t bool16_t;
typedef uint32_t bool32_t;

#ifdef __cplusplus
/* Pointer to Function returning Void (any number of parameters) */
typedef void(*PFV)(...);

/* Pointer to Function returning U32 (any number of parameters) */
typedef uint32_t (*PFU)(...);

/* Pointer to Function returning int32_t (any number of parameters) */
typedef int32_t (*PFS)(...);
#else
/* Pointer to Function returning Void (any number of parameters) */
typedef void (*PFV)();

/* Pointer to Function returning U32 (any number of parameters) */
typedef uint32_t (*PFU)();

/* Pointer to Function returning int32_t (any number of parameters) */
typedef int32_t  (*PFS)();
#endif

typedef union   {
    uint8_t  b[2];
    uint16_t w;
} tBw;

typedef union   {
    uint8_t  b[4];
    uint16_t w[2];
    uint32_t dw;
} tDw;

typedef struct {
    int32_t  l1ms;
    uint16_t w1us;
} tTime;

#endif // _TYPES_H
