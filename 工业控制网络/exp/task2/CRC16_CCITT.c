#include "main.h"
//实现CRC-16/CCITT
//pData为数据指针，len为数据长度
ushort calc_crc16c(uchar *pData, uchar len)
{
    ushort crc_reg = 0x00, tmp = 0;
    uchar j,byte = 0;
    while (len--)
    {
        byte = *(pData++);
        invert_uint8(&byte,&byte);
        crc_reg = crc_reg^(byte << 8);
        for (j = 0; j < 8; j++)
        {
            tmp = crc_reg & 0x8000;
            crc_reg <<= 1;
            if (tmp)
            {
                crc_reg ^= 0x1021;
            }
        }
    }
    invert_uint16(&crc_reg,&crc_reg);
    //XOROUT数值固定为0x0000
    return crc_reg;
}


