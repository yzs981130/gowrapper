#include <stddef.h>
#include <dlfcn.h>

#include "cuda_dl.h"

#define DLSYM(x, sym)                           \
do {                                            \
    dlerror();				                    \
    x = dlsym(handle, #sym);                    \
    if (dlerror() != NULL) {                    \
        return -1;                              \
    }                                           \
} while (0)

typedef CUresult (*cudaSym_t)();

static void *handle;

CUresult cuDeviceGetName_dl(char *name, int len, CUdevice dev) {
    handle = dlopen("libcuda.so", RTLD_LAZY | RTLD_GLOBAL);
    cudaSym_t sym;
    DLSYM(sym, cuDeviceGetName);
    return ((*sym)(name, len, dev));
}