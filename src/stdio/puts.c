#include <internal/syscall.h>
#include <string.h>
int puts(const char *str)
{
    int biti = syscall(1, 1, str, strlen(str));
    int b = syscall(1, 1, "\n", 1);
    return biti + b;
}
