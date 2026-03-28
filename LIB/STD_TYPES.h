#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;
typedef signed long long int s64;

typedef float  f32;
typedef double f64;

typedef enum
{
    FALSE = 0,
    TRUE = 1
} bool;

typedef enum
{
    LOW = 0,
    HIGH = 1
} logic_level;

typedef enum
{
    OFF = 0,
    ON = 1
} state;

typedef enum
{
    DISABLED = 0,
    ENABLED = 1
} status;

typedef enum
{
    ERROR = 0,
    SUCCESS = 1
} error_status;

typedef enum
{
    IDLE = 0,
    BUSY = 1
} operation_status;

typedef enum
{
    INPUT = 0,
    OUTPUT = 1
} pin_direction;

typedef enum
{
    LOW_NIBBLE = 0,
    HIGH_NIBBLE = 1
} nibble_position;

typedef enum
{
    FIRST_BYTE = 0,
    SECOND_BYTE = 1
} byte_position;

typedef enum
{
    FIRST_WORD = 0,
    SECOND_WORD = 1
} word_position;

typedef enum
{
    NO_ERROR = 0,
    NULL_POINTER_ERROR = 1,
    OUT_OF_RANGE_ERROR = 2,
    BUSY_ERROR = 3,
    UNKNOWN_ERROR = 4
} error_code;

typedef enum
{
    LOW_PRIORITY = 0,
    MEDIUM_PRIORITY = 1,
    HIGH_PRIORITY = 2,
    CRITICAL_PRIORITY = 3
} priority_level;

typedef enum
{
    MODE_0 = 0,
    MODE_1 = 1,
    MODE_2 = 2,
    MODE_3 = 3
} operation_mode;

typedef enum
{
    IDLE_STATE = 0,
    ACTIVE_STATE = 1,
    SLEEP_STATE = 2,
    DEEP_SLEEP_STATE = 3
} power_state;

typedef enum
{
    NO_INTERRUPT = 0,
    INTERRUPT_0 = 1,
    INTERRUPT_1 = 2,
    INTERRUPT_2 = 3
} interrupt_source;

typedef enum
{
    LOW_SPEED = 0,
    MEDIUM_SPEED = 1,
    HIGH_SPEED = 2,
    MAX_SPEED = 3
} speed_setting;

#define NULL         0
#define OK           0
#define NOK          1
#define NULL_POINTER 2
#define BUSY_FUNC    3


#endif
