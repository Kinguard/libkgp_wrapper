#ifndef LIBOPI_WRAPSYSINFO_H
#define LIBOPI_WRAPSYSINFO_H

#include <unistd.h>
#include <libopi/SysInfo.h>


/******  Sys Info Wrapper    *********/

/**
 * @brief Get a text representation of the current system
 * @return a string like "Armada" or "Opi"
 */
extern "C" int SysTypeText(char *buf);

/**
 * @brief StorageDevice Get path to storage block device (/dev/sdg)
 * @return path to storage block device
 */
extern "C" int StorageDevice(char *buf);

/**
 * @brief StorageDeviceBlock Get storage device (sdg, mmcblk0)
 * @return name of storage device
 */
extern "C" int StorageDeviceBlock(char *buf);

/**
 * @brief StorageDevicePartition Get storage partition (1, -part1)
 * @return name of storage partition
 */
extern "C" int StorageDevicePartition(char *buf);

/**
 * @brief NetworkDevice Get active network device to use for operation
 * @return name of device i.e. "eth0"
 */
extern "C" int NetworkDevice(char *buf);

/**
 * @brief SerialNumber Get the serial number from the eeprom
 * @return the serial number "1748KEEP1234"
 */
extern "C" int SerialNumber(char *buf);

/**
 * @brief BackupRootPath Get base path on where remote FS for backup is mounted.
 * @return path to use for mount points, i.e. "/mnt/backup"
 */
extern "C" int BackupRootPath(char *buf);



/**
 * @brief Function to check what the currens system is
 * @return boolean
 */
extern "C" bool isPC();
extern "C" bool isArmada();
extern "C" bool isOpi();
extern "C" bool isXu4();
extern "C" bool isOlimexA20();



#endif // LIBOPI_WRAPSYSINFO_H

