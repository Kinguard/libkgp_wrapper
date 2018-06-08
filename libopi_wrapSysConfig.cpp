#include "libopi_wrapSysConfig.h"
#include <string.h>

using namespace OPI;


bool GetKeyAsString(char *c_scope, char *c_key, char *buf)
{
    SysConfig sysConfig;
    string scope(c_scope);
    string key(c_key);

    try {
        strcpy(buf,sysConfig.GetKeyAsString(scope,key).c_str());
    }
    catch (runtime_error e) {
        return false;
    }
    return true;
}

bool GetKeyAsInt(char *c_scope, char *c_key, int *res)
{
    SysConfig sysConfig;
    string scope(c_scope);
    string key(c_key);

    try {
        *res = sysConfig.GetKeyAsInt(scope,key);
    }
    catch (runtime_error e) {
        return false;
    }
    return true;
}

bool GetKeyAsBool(char *c_scope, char *c_key, int *res)
{
    SysConfig sysConfig;
    string scope(c_scope);
    string key(c_key);

    try {
        *res = sysConfig.GetKeyAsBool(scope,key);
    }
    catch (runtime_error e) {
        return false;
    }
    return true;
}
