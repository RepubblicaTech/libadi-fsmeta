#ifndef __ADI_CORE_H__
#define __ADI_CORE_H__

#include "types.h"

#include "metalanguages/arch/x86_64.h"
#include "metalanguages/bus/pci.h"
#include "metalanguages/hid/pointer.h"
#include "metalanguages/hid/kb.h"
#include "metalanguages/video/screenmgmt.h"
#include "metalanguages/video/fb.h"
#include "metalanguages/misc/storage.h"
#include "metalanguages/misc/timekeeper.h"

typedef struct {
    metalang_x86_64_t* arch_x86_64;
    metalang_pci_t* bus_pci;
    metalang_pointer_t* hid_pointer;
    metalang_kb_t* hid_kb;
    metalang_screenmgmt_t* video_screenmgmt;
    metalang_fb_t* video_fb;
    metalang_storage_t* misc_storage;
    metalang_timekeeper_t* misc_timekeeper;

    //Logging API
    void (*log_info)(char* format,...);
    void (*log_warning)(char* format,...);
    void (*log_error)(char* format,...);
    void (*panic)(char* format,...);
    void (*exit)(bool success);

    //Device API
    uint32_t (*register_device)(metalanguage_t* metalanguages_implemented,uint32_t metalanguage_count);
    void (*unregister_device)(uint32_t device_id);

    // Memory API
    void* (*alloc)(size_t size);
    bool  (*free)(void* ptr);
    void* (*realloc)(void* ptr, size_t size);

    bool (*memcpy)(void* dst, void* src, size_t size);
    bool (*memset)(void* dst, uint8_t value, size_t size); 

} adi_core_t;

#endif // __ADI_CORE_H__