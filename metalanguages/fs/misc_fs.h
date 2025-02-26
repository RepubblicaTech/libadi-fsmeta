#ifndef __MISC_FS__
#define __MISC_FS__

#include "../../types.h"
#include "../misc/storage.h"

typedef enum {
    ADI_FILE_FILE,
    ADI_FILE_DIRECTORY,
    ADI_FILE_SYMLINK,
    ADI_FILE_HARDLINK
} adi_filetype;

typedef enum {
    ADI_FATTRIB_READ,
    ADI_FATTRIB_WRITE,
    ADI_FATTRIB_HIDDEN,
} adi_file_attribs;

// TODO: UNIX-like permissions (chmod xxx)

typedef struct {
    char* parent_path;
    char* filename;

    adi_filetype file_type;
    adi_file_attribs attributes;

    size_t size;

    // TODO: what time/date standard should we use?
    uint64_t creation_date;
    uint64_t creation_time;

    uint64_t accessed_date;
    uint64_t accessed_time;

    void* file_start;   // and address where the file buffer starts
} adi_file_t;

// 48 bit PIO
// @param lba: array of 3 16-bit values of the LBA -> [lo, mid, hi]
// @returns an array of <sector count> bytes
typedef uint16_t (*sector_read)(uint16_t* lba, uint16_t count);

typedef struct {
    metalanguage_t (*init)(sector_read sector_read);

    // parse the file system for a directory or a file
    adi_file_t* (*path_lookup)(char* path);

    // create and delete entries for the file system
    void (*fs_create)(adi_file_t* properties);
    void (*fs_delete)(char* path);

    void* (*file_read)(adi_file_t* file, size_t bytes);
    void (*file_write)(adi_file_t* file, void* src, size_t bytes);
} metalang_filesystem_t;

#endif  // __MISC_FS__