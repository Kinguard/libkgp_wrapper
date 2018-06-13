#ifndef LIBOPI_WRAPAUTHSERVER_H
#define LIBOPI_WRAPAUTHSERVER_H

#include <unistd.h>
#include <libopi/SysConfig.h>
#include <libopi/AuthServer.h>
#include <libopi/Secop.h>

/******  Auth Server Wrapper    *********/

/**
 * @brief Login to OP servers
 * @return auth-token in 'buf' as string to be used in http headers
 */

extern "C" int Login(char *buf);
extern "C" bool isLocked();

#endif // LIBOPI_WRAPAUTHSERVER_H
