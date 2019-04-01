#include <oyoung/zbuffer.h>

int main(int agrc, char**argv)
{

    char memory[31];

    int i32 = 0x11223344;
    unsigned u32 = 0xAABBCCDD;

    short i16 = 0x55EE;
    unsigned short u16 = 0x7799;
    ZBuffer buffer = ZBuffer_make(memory, sizeof (memory));

    ZBuffer_print(&buffer);
    ZBuffer_writeInt32LE(&buffer, i32, 0);
    ZBuffer_writeInt32BE(&buffer, i32, 5);
    ZBuffer_writeUInt32LE(&buffer, u32, 10);
    ZBuffer_writeUInt32BE(&buffer, u32, 15);

    ZBuffer_writeInt16LE(&buffer, i16, 20);
    ZBuffer_writeInt16BE(&buffer, i16, 23);
    ZBuffer_writeUInt16LE(&buffer, u16, 26);
    ZBuffer_writeUInt16BE(&buffer, u16, 29);

    ZBuffer_print(&buffer);

    printf("read little endian int32 from buffer[0]: %d\n", ZBuffer_readInt32LE(&buffer, 0));
    printf("read big endian int32 from buffer[5]: %d\n", ZBuffer_readInt32BE(&buffer, 5));

    ZBuffer_clear(&buffer);
    ZBuffer_writeCString(&buffer, "How do think this library is?", 0);
    ZBuffer_print(&buffer);

    return 0;
}

