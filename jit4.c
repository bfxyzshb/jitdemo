// Most basic JIT; patches a partially-encoded function
// and executes it.
//
// Only works on x86-64!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

const unsigned char code[] =
        "\x55\x48\x89\xe5\x48\x89\x7d\xf8\x48\x89\x75\xf0"\
        "\x48\x8b\x75\xf8\x8b\x06\x89\x45\xec\x48\x8b\x75"\
        "\xf0\x8b\x06\x48\x8b\x75\xf8\x89\x06\x8b\x45\xec"\
        "\x48\x8b\x75\xf0\x89\x06\x5d\xc3\x0f\x1f\x40\x00";

typedef void (*FUN)(int*, int*);

void main() {
    int a = 1;
    int b = 2;
    void (*func)(int*, int*);

    void *mem = mmap(NULL, sizeof(code), PROT_WRITE | PROT_EXEC,
                     MAP_ANON | MAP_PRIVATE, -1, 0);
    memcpy(mem, code, sizeof(code));
    FUN func1 = (void*) code;
    FUN func2 = (void*) mem;
    func1(&a, &b);
    printf("a= %d, b = %d\n", a, b);
    func2(&a, &b);
    printf("a= %d, b = %d\n", a, b);
}
