# About the FS metalang

## Kernel-side
The kernel should implement a function to read the disk sectors that the driver will use for parsing the data on your disk.

The function prototype:
```c
uint16_t* sectors_read(uint16_t* lba, size_t count);
```
### Parameters

`lba`: an array of the LBA bytes.
- The number of bytes depend on the mode, they're either 48-bit or 28-bit
- Check [this page about ATA PIO mode](https://wiki.osdev.org/ATA_PIO_Mode)

`count`: how many sectors to read.

The function should return an array of the sectors that have been read.