#include <stdio.h>
#include <stdlib.h>

#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int

//����CRC8
uchar calc_CRC8(uchar *pData, uint len);
//����CRC16X
ushort calc_crc16x(uchar *pData, uchar len);
//����CRC16C
ushort calc_crc16c(uchar *pData, uchar len);

//��ת�ֽ�
void invert_uint8(uchar *dstBuf, uchar *srcBuf);
//��ת˫�ֽ�
void invert_uint16(ushort *dstBuf, ushort *srcBuf);
//ͨ��CRC16���㺯��
ushort calc_crc16(uchar *data,uint size,const ushort crc_poly,ushort init_value,uchar ref_flag);
