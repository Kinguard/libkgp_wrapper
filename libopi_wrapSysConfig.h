#ifndef LIBOPI_WRAPSYSCONFIG_H
#define LIBOPI_WRAPSYSCONFIG_H

#include <unistd.h>
#include <libopi/SysConfig.h>


/*******   SYSCONFIG WRAPPER  *************/

/**
 * @brief GetKeyAsString Get the value of 'key' in section 'scope' from sysconfig.json
 * @return the value of 'key' in buf as a string
 */
extern "C" bool GetKeyAsString(char *c_scope, char *c_key, char *buf);

/**
 * @brief GetKeyAsInt Get the value of 'key' in secton 'scope' from sysconfig.json
 * @return the value of 'key' as int
 */
extern "C" bool GetKeyAsInt(char *c_scope, char *c_key, int *res);

/**
 * @brief GetKeyAsBool Get the value of 'key' in secton 'scope' from sysconfig.json
 * @return the value of 'key' as bool
 */
extern "C" bool GetKeyAsBool(char *c_scope, char *c_key, int *res);


#endif // LIBOPI_WRAPSYSCONFIG_H
