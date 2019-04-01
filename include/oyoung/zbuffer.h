#ifndef OYOUNG_ZBUFFER_H
#define OYOUNG_ZBUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ZBuffer_Initializer {NULL, 0}
#define ZBuffer_data(buffer) (buffer->data)
#define ZBuffer_size(buffer) (buffer->size)

typedef int8_t      ZInt8;
typedef uint8_t     ZUInt8;
typedef int16_t     ZInt16;
typedef uint16_t    ZUInt16;
typedef int32_t     ZInt32;
typedef uint32_t    ZUInt32;
typedef size_t      ZSize;
typedef ssize_t     ZSSize;

typedef struct ZBuffer
{
    ZUInt8 *data;
    ZSize size;
} ZBuffer;



ZBuffer ZBuffer_make(void *data, ZSize size);

void ZBuffer_clear(ZBuffer *buffer);
ZSize ZBuffer_read(const ZBuffer* buffer, void *data, ZSize size, ZSize pos);
ZSize ZBuffer_write(ZBuffer* buffer, const void *data, ZSize size, ZSize pos);

ZSize ZBuffer_writeInt8(ZBuffer* buffer, ZInt8 n, ZSize pos);
ZSize ZBuffer_writeInt16LE(ZBuffer* buffer, ZInt16 n, ZSize pos);
ZSize ZBuffer_writeInt32LE(ZBuffer* buffer, ZInt32 n, ZSize pos);

ZSize ZBuffer_writeUInt8(ZBuffer* buffer, ZUInt8 n, ZSize pos);
ZSize ZBuffer_writeUInt16LE(ZBuffer* buffer, ZUInt16 n, ZSize pos);
ZSize ZBuffer_writeUInt32LE(ZBuffer* buffer, ZUInt32 n, ZSize pos);

ZSize ZBuffer_writeInt16BE(ZBuffer* buffer, ZInt16 n, ZSize pos);
ZSize ZBuffer_writeInt32BE(ZBuffer* buffer, ZInt32 n, ZSize pos);

ZSize ZBuffer_writeUInt16BE(ZBuffer* buffer, ZUInt16 n, ZSize pos);
ZSize ZBuffer_writeUInt32BE(ZBuffer* buffer, ZUInt32 n, ZSize pos);

ZSize ZBuffer_writeCString(ZBuffer *buffer, const char *str, ZSize pos);

ZInt8   ZBuffer_readInt8(const ZBuffer* buffer, ZSize pos);
ZUInt8  ZBuffer_readUInt8(const ZBuffer* buffer, ZSize pos);

ZInt16   ZBuffer_readInt16LE(const ZBuffer* buffer, ZSize pos);
ZUInt16  ZBuffer_readUInt16LE(const ZBuffer* buffer, ZSize pos);
ZInt16   ZBuffer_readInt16BE(const ZBuffer* buffer, ZSize pos);
ZUInt16  ZBuffer_readUInt16BE(const ZBuffer* buffer, ZSize pos);


ZInt32   ZBuffer_readInt32LE(const ZBuffer* buffer, ZSize pos);
ZUInt32  ZBuffer_readUInt32LE(const ZBuffer* buffer, ZSize pos);
ZInt32   ZBuffer_readInt32BE(const ZBuffer* buffer, ZSize pos);
ZUInt32  ZBuffer_readUInt32BE(const ZBuffer* buffer, ZSize pos);



void ZBuffer_print(const ZBuffer *buffer);

#ifdef __cplusplus
}
#endif

#endif
