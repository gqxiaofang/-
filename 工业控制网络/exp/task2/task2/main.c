#include "main.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i = 0;
    printf("---------CRC�㷨ʾ������--------\n");
    //����
    unsigned char data[] = {0xA5};
    uchar r8 = calc_CRC8(data, 1);
    ushort r16 = calc_crc16(data, 1, 0x8005, 0xFFFF, 1);
    ushort r16x = calc_crc16x(data, 1);
    ushort r16c = calc_crc16c(data, 1);
    printf("CRC8У���룺0x%02X\n", r8);
    printf("CRC16У���룺0x%04X\n", r16);
    printf("CRC-16/XMODEMУ���룺0x%04X\n", r16x);
    printf("CRC-16/CCITTУ���룺0x%04X\n", r16c);
    system("pause");
    return 0;
}
