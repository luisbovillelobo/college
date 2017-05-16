#include <stdio.h>

union byte {
    unsigned char b;
    struct {
        unsigned int bit8:1;
        unsigned int bit7:1;
        unsigned int bit6:1;
        unsigned int bit5:1;
        unsigned int bit4:1;
        unsigned int bit3:1;
        unsigned int bit2:1;
        unsigned int bit1:1;
    } bits;
    struct {
        unsigned int nibble2:4;
        unsigned int nibble1:4;
    } nibbles;
};

typedef union byte BYTE;

void main() {

    BYTE x;

    printf("Numero de bytes = %d\n",sizeof x);

    x.b = 0x3A;

    printf("Byte Hex = 0x%X\nBits : ",x.b);
    printf("%d ", x.bits.bit1);
    printf("%d ", x.bits.bit2);
    printf("%d ", x.bits.bit3);
    printf("%d ", x.bits.bit4);
    printf("%d ", x.bits.bit5);
    printf("%d ", x.bits.bit6);
    printf("%d ", x.bits.bit7);
    printf("%d\n", x.bits.bit8);

    printf("Nibble1 = %X\n", x.nibbles.nibble1);
    printf("Nibble2 = %X\n", x.nibbles.nibble2);

    x.bits.bit2 = 1;
    x.bits.bit3 = 0;
    printf("%02X\n", x.b);

}
