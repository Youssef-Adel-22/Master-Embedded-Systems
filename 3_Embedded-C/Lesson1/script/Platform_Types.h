/*
 * Platform_Types.h
 *
 *  Created on: Apr 26, 2023
 *      Author: Harby
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FLASE (boolean)false
#endif

#ifndef TRUE
#define TRUE (boolean)true
#endif

#define CPU_TYPE                        CPU_TYPE_32
#define CPU_BIT_ORDER                   MSB_FIRST
#define CPU_BYTE_ORDER                  HIGH_BYTE_FIRST

typedef _Bool					boolean;
typedef signed char 			sint8;
typedef unsigned char 			uint8;
typedef char 					char_t;
typedef short int 				sint16;
typedef unsigned short int 		uint16;
typedef int						sint32;
typedef unsigned int			uint32;
typedef long long int			sint64;
typedef unsigned long long int	uint64;

typedef volatile signed char	vsint8;
typedef volatile unsigned char	vuint8;

typedef volatile short 				vsint16;
typedef volatile unsigned short 	vuint16;

typedef volatile int				vsint32;
typedef volatile unsigned int		vuint32;

typedef volatile long long			vsint64;
typedef volatile unsigned long long	vuint64;
#endif /* PLATFORM_TYPES_H_ */
