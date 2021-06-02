#include "main.h"

//倒转字节
void invert_uint8(uchar *dstBuf, uchar *srcBuf)
{
    uchar i,tmp = 0;
    for (i=0; i<8; i++)
    {
        if (srcBuf[0] & (1<<i))
        {
            tmp |= 1 << (7-i);
        }
    }
    *dstBuf = tmp;
}

//倒转双字节
void invert_uint16(ushort *dstBuf, ushort *srcBuf)
{
    ushort i,tmp = 0;
    for (i = 0; i < 16; i++)
    {
        if (srcBuf[0] & (1 << i))
        {
            tmp |= 1 << (15-i);
        }
    }
    *dstBuf = tmp;
}

//计算CRC16值的算法实现，适配所有CRC16的协议
//data,数据指针; size,数据长度; crc_poly,多项式; init_value,初始值;
//ref_flag,数据位序翻转，true-低位在前，高位在后
ushort calc_crc16(uchar *data,uint size, ushort crc_poly, ushort init_value, uchar ref_flag)
{
    ushort crc_reg = init_value, tmp = 0;
    uchar j,byte = 0;

    while (size--)
    {
        byte = *(data++);
        if (ref_flag)
        {
           invert_uint8(&byte,&byte);
        }
        crc_reg = crc_reg^(byte << 8);
        for (j = 0; j < 8; j++)
        {
            tmp = crc_reg & 0x8000;
            crc_reg <<= 1;
            if (tmp)
            {
                crc_reg ^= crc_poly;
            }
        }
    }
    if (ref_flag)
    {
        invert_uint16(&crc_reg,&crc_reg);
    }
    //XOROUT数值固定为0x0000
    return crc_reg;
}

