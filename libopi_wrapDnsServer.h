#ifndef LIBOPI_WRAPDNSSERVER_H
#define LIBOPI_WRAPDNSSERVER_H

#include <unistd.h>
#include <libopi/SysConfig.h>
#include <libopi/DnsServer.h>

/******  DNS Server Wrapper    *********/

/**
 * @brief Login to OP servers to update DNS (only for DNS, use AuthServer for normal login)
 * @return auth-token in 'buf' as string to be used in http headers
 */

extern "C" bool UpdateDns();


#endif // LIBOPI_WRAPDNSSERVER_H
