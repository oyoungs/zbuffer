
#include <oyoung/zbuffer.h>

ZBuffer ZBuffer_make(void *data, ZSize size)
{
    ZBuffer buffer = {(ZUInt8 *)data, size};
    memset(data, 0, size);
    return buffer;
}

void ZBuffer_clear(ZBuffer* buffer)
{
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    if(data && size) {
        memset(data, 0, size);
    }
}

void ZBuffer_print(const ZBuffer *buffer)
{
    static const char hexMap[] = "0123456789ABCDEF";
    ZUInt8 byte;
    const ZUInt8 *buffer_data = ZBuffer_data(buffer);
    ZSize i, last, buffer_size = ZBuffer_size(buffer);

    if(buffer_data == NULL) return;

    last = buffer_size - 1;
    printf("<Buffer(%zu) ", buffer_size);
    for(i = 0; i < last; ++i) {
        byte = buffer_data[i];
        printf("%c%c ", hexMap[byte >> 4], hexMap[byte & 0x0f]);
    }
    byte = buffer_data[last];
    printf("%c%c>\n", hexMap[byte >> 4], hexMap[byte & 0x0f]);
}

ZSize ZBuffer_read(const ZBuffer* buffer, void *data, ZSize size, ZSize pos)
{
    const ZUInt8 *buffer_data = ZBuffer_data(buffer);
    ZSize   buffer_size = ZBuffer_size(buffer);
    if(buffer_data == NULL) return 0;
    if(buffer_size <= pos)  return 0;
    if(buffer_size <= pos + size) size = buffer_size - pos;
    memcpy(data, buffer_data + pos, size);
    return size;
}

ZSize ZBuffer_write(struct ZBuffer* buffer, const void *data, ZSize size, ZSize pos)
{
    ZUInt8 *buffer_data = ZBuffer_data(buffer);
    ZSize   buffer_size = ZBuffer_size(buffer);
    if(buffer_data == NULL) return 0;
    if(buffer_size <= pos)  return 0;
    if(buffer_size <= pos + size) size = buffer_size - pos;
    memcpy(buffer_data + pos, data, size);
    return size;
}


ZSize ZBuffer_writeInt8(ZBuffer* buffer, ZInt8 n, ZSize pos)
{
    union {
        ZInt8 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos + nsize] = number.u8[nsize];
    }
    return nsize;
}
ZSize ZBuffer_writeInt16LE(ZBuffer* buffer, ZInt16 n, ZSize pos)
{
    union {
        ZInt16 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos + nsize] = number.u8[nsize];
    }
    return nsize;
}

ZSize ZBuffer_writeInt32LE(ZBuffer* buffer, ZInt32 n, ZSize pos)
{
    union {
        ZInt32 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos + nsize] = number.u8[nsize];
    }
    return nsize;
}

ZSize ZBuffer_writeUInt8(ZBuffer* buffer, ZUInt8 n, ZSize pos)
{
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    data[pos] = n;
    return nsize;
}
ZSize ZBuffer_writeUInt16LE(ZBuffer* buffer, ZUInt16 n, ZSize pos)
{
    union {
        ZUInt16 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos + nsize] = number.u8[nsize];
    }
    return nsize;
}
ZSize ZBuffer_writeUInt32LE(ZBuffer* buffer, ZUInt32 n, ZSize pos)
{
    union {
        ZUInt32 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos + nsize] = number.u8[nsize];
    }
    return nsize;
}

ZSize ZBuffer_writeInt16BE(ZBuffer* buffer, ZInt16 n, ZSize pos)
{
    union {
        ZInt16 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos++] = number.u8[nsize];
    }
    return nsize;
}
ZSize ZBuffer_writeInt32BE(ZBuffer* buffer, ZInt32 n, ZSize pos)
{
    union {
        ZInt32 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos++] = number.u8[nsize];
    }
    return nsize;
}


ZSize ZBuffer_writeUInt16BE(ZBuffer* buffer, ZUInt16 n, ZSize pos)
{
    union {
        ZUInt16 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos++] = number.u8[nsize];
    }
    return nsize;
}
ZSize ZBuffer_writeUInt32BE(ZBuffer* buffer, ZUInt32 n, ZSize pos)
{
    union {
        ZUInt32 n;
        ZUInt8 u8[sizeof (n)];
    } number = {n};
    ZUInt8 *data = ZBuffer_data(buffer);
    ZSize   size = ZBuffer_size(buffer);
    ZSize   nsize = sizeof (n);
    if(size < pos + nsize) return 0;
    while (nsize--) {
        data[pos++] = number.u8[nsize];
    }
    return nsize;
}

ZSize ZBuffer_writeCString(ZBuffer *buffer, const char *str, ZSize pos)
{
    return ZBuffer_write(buffer, str, strlen(str), pos);
}

ZInt8   ZBuffer_readInt8(const ZBuffer* buffer, ZSize pos)
{
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    if(size < pos + sizeof (ZInt8)) return 0;
    return *(const ZInt8 *)(data + pos);
}
ZUInt8  ZBuffer_readUInt8(const ZBuffer* buffer, ZSize pos)
{
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    if(size < pos + sizeof (ZUInt8)) return 0;
    return *(data + pos);
}

ZInt16   ZBuffer_readInt16LE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZInt16 n;
        ZUInt8 u8[sizeof (ZInt16)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos + nsize];
    }

    return number.n;
}
ZUInt16  ZBuffer_readUInt16LE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZUInt16 n;
        ZUInt8 u8[sizeof (ZUInt16)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos + nsize];
    }

    return number.n;
}
ZInt16   ZBuffer_readInt16BE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZInt16 n;
        ZUInt8 u8[sizeof (ZInt16)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos++];
    }

    return number.n;
}
ZUInt16  ZBuffer_readUInt16BE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZUInt16 n;
        ZUInt8 u8[sizeof (ZUInt16)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos++];
    }

    return number.n;
}


ZInt32   ZBuffer_readInt32LE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZInt32 n;
        ZUInt8 u8[sizeof (ZInt32)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos + nsize];
    }

    return number.n;
}
ZUInt32  ZBuffer_readUInt32LE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZUInt32 n;
        ZUInt8 u8[sizeof (ZUInt32)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos++];
    }

    return number.n;
}
ZInt32   ZBuffer_readInt32BE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZInt32 n;
        ZUInt8 u8[sizeof (ZUInt32)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos++];
    }

    return number.n;
}
ZUInt32  ZBuffer_readUInt32BE(const ZBuffer* buffer, ZSize pos)
{
    union {
        ZUInt32 n;
        ZUInt8 u8[sizeof (ZUInt32)];
    } number;
    const ZUInt8 *data = ZBuffer_data(buffer);
    ZSize         size = ZBuffer_size(buffer);
    ZSize        nsize = sizeof (number.n);
    if(size < pos + nsize) return 0;

    while (nsize --) {
        number.u8[nsize] = data[pos++];
    }

    return number.n;
}
