#ifndef LIBOPI_WRAPPER_H
#define LIBOPI_WRAPPER_H

#include <unistd.h>
#include <libopi/SysInfo.h>

/**
 * @brief Get a text representation of the current system
 * @return a string like "Armada" or "Opi"
 */
string SysTypeText();

/**
 * @brief StorageDevice Get path to storage block device (/dev/sdg)
 * @return path to storage block device
 */
string StorageDevice();

/**
 * @brief StorageDeviceBlock Get storage device (sdg, mmcblk0)
 * @return name of storage device
 */
string StorageDeviceBlock();

/**
 * @brief StorageDevicePartition Get storage partition (1, -part1)
 * @return name of storage partition
 */
string StorageDevicePartition();

/**
 * @brief NetworkDevice Get active network device to use for operation
 * @return name of device i.e. "eth0"
 */
string NetworkDevice();

/**
 * @brief SerialNumber Get the serial number from the eeprom
 * @return the serial number "1748KEEP1234"
 */
string SerialNumber();


#endif // LIBOPI_WRAPPER_H

