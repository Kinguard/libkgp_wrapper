#include "libopi_wrapDnsServer.h"
#include <libutils/Logger.h>
#include <cstring>

using namespace OPI;
using namespace Utils;

/*  DNS Server */
bool UpdateDns()
{
    string unit_id="";
    string fqdn="";
    SysConfig sysConfig;
    DnsServer dns;

    try
    {
        unit_id = sysConfig.GetKeyAsString("hostinfo","unitid");
        fqdn = sysConfig.GetKeyAsString("hostinfo","hostname") + "." + sysConfig.GetKeyAsString("hostinfo","domain");
    }
    catch (runtime_error& e)
    {
        logg << Logger::Error << e.what() << lend;
        logg << Logger::Error << "Failed to read needed data from config DB, using serial (empty args)"<<lend;
    }

    try
    {
        bool res = dns.UpdateDynDNS(unit_id,fqdn);
        if ( ! res )
        {
            logg << Logger::Error << "Failed to update DNS" <<lend;
        }
        return res;
    }
    catch (runtime_error& e)
    {
        logg << Logger::Error << "Failed to update DNS records"<<lend;
        logg << Logger::Error << e.what() << lend;
        return false;
    }
}
