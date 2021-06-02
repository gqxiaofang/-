#include "main.h"
#define FACTOR (0x07 & 0xFF)   //多项式因子(取低8bit)

uchar calc_CRC8(uchar *pData, uint len)
{
    uchar i;
    uchar crc = 0x00;
    while(len--)
    {
        crc ^= *pData++;    //0xA5 10100101 按位异或 0->0 1->1 相当于赋值运算
        for (i=8; i>0; --i)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ FACTOR;  //右边补0 进行异或运算
            else
                crc = (crc << 1);           //右边补0
        }
    }
    return crc;
}
