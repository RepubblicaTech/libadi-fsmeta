#ifndef __FB_H__
#define __FB_H__

#include "../../types.h"

typedef struct {
    uintptr_t addr;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    //TODO: add more info, I can't type more on this fucking phone lul
} fbinfo_t;

typedef fbinfo_t (*fbinfo_request)(adi_device_t* dev,uint32_t fbid);

typedef struct {
    metalanguage_t (*init)();
} metalang_fb_t;
#endif // __FB_H__