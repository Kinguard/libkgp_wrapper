#ifndef LIBOPI_WRAPPER_H
#define LIBOPI_WRAPPER_H

#include <unistd.h>
#include <libopi/SysInfo.h>

/**
 * @brief Get a text representation of the current system
 * @return a string like "Armada" or "Opi"
 */
extern "C" const char* SysTypeText();

/**
 * @brief StorageDevice Get path to storage block device (/dev/sdg)
 * @return path to storage block device
 */
extern "C" const char* StorageDevice();

/**
 * @brief StorageDeviceBlock Get storage device (sdg, mmcblk0)
 * @return name of storage device
 */
extern "C" const char* StorageDeviceBlock();

/**
 * @brief StorageDevicePartition Get storage partition (1, -part1)
 * @return name of storage partition
 */
extern "C" const char* StorageDevicePartition();

/**
 * @brief NetworkDevice Get active network device to use for operation
 * @return name of device i.e. "eth0"
 */
extern "C" const char* NetworkDevice();

/**
 * @brief SerialNumber Get the serial number from the eeprom
 * @return the serial number "1748KEEP1234"
 */
extern "C" const char* SerialNumber();


#endif // LIBOPI_WRAPPER_H

