#include <stdio.h>
#include <stdint.h>

int extractExp(float f);


int main(int argc, char *argv)
{
    float f;
    scanf("%f", &f);

    printf("%d\n", extractExp(f));
    return 0;
}


int extractExp(float f) {
    union {
        float f;
        struct {
            uint32_t mantissa   : 23;
            uint32_t exp        : 8;
            uint32_t sign       : 1;
        } field;
    } fl;

    fl.f = f;
    return fl.field.exp;
}