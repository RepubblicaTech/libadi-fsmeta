#ifndef __DISK_H__
#define __DISK_H__

#include "../../types.h"
#include "../misc/storage.h"

typedef enum {
    ML_FS_RAMFS,
    ML_FS_ISO9660,
    ML_FS_FAT12,
    ML_FS_FAT16,
    ML_FS_FAT32,
    ML_FS_EXT,
    ML_FS_EXT2,
    ML_FS_EXT3,
    ML_FS_EXT4,
    ML_FS_VFS
} ml_fs_type;

typedef struct {
    metalanguage_t (*init)(sdev_ident_t disk, ml_fs_type fs_type);

    // TODO: reading sectors, we're more likely going to do ATAPI
} metalang_fs_t;


#endif