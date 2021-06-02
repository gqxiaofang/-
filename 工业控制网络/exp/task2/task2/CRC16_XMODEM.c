#include "main.h"
//实现CRC-16/XMODEM
//pData为数据指针，len为数据长度
ushort calc_crc16x(uchar *pData, uchar len)
{
    uchar j;
    ushort crc = 0, tmp = 0;
    uchar byte;
    while(len--)
    {
        byte = *(pData++);  
        crc = crc ^ (byte << 8);
        for (j = 0; j < 8; j++)
        {
            tmp = crc & 0x8000;
            crc <<= 1;
            if (tmp)
            {
                crc ^= 0x1021;
            }
        }
    }
    return(crc);
}
