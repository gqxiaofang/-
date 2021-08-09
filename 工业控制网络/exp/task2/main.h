#include <stdio.h>
#include <stdlib.h>

#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int

//计算CRC8
uchar calc_CRC8(uchar *pData, uint len);
//计算CRC16X
ushort calc_crc16x(uchar *pData, uchar len);
//计算CRC16C
ushort calc_crc16c(uchar *pData, uchar len);

//倒转字节
void invert_uint8(uchar *dstBuf, uchar *srcBuf);
//倒转双字节
void invert_uint16(ushort *dstBuf, ushort *srcBuf);
//通用CRC16计算函数
ushort calc_crc16(uchar *data,uint size,const ushort crc_poly,ushort init_value,uchar ref_flag);
