#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    uint32_t id;
    char* name;

    void* lang_impl;
    void* params;
} metalanguage_t;

typedef struct {
    uint32_t id;
    char* name;
    metalanguage_t** metalangs_implemented;
    metalanguage_t** metalangs_used;
} adi_device_t;
#endif // __TYPES_H__