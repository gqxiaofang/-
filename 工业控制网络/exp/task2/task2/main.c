#include "main.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i = 0;
    printf("---------CRC算法示例程序--------\n");
    //数据
    unsigned char data[] = {0xA5};
    uchar r8 = calc_CRC8(data, 1);
    ushort r16 = calc_crc16(data, 1, 0x8005, 0xFFFF, 1);
    ushort r16x = calc_crc16x(data, 1);
    ushort r16c = calc_crc16c(data, 1);
    printf("CRC8校验码：0x%02X\n", r8);
    printf("CRC16校验码：0x%04X\n", r16);
    printf("CRC-16/XMODEM校验码：0x%04X\n", r16x);
    printf("CRC-16/CCITT校验码：0x%04X\n", r16c);
    system("pause");
    return 0;
}
