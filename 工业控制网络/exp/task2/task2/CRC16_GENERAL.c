#include "main.h"

//��ת�ֽ�
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

//��ת˫�ֽ�
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

//����CRC16ֵ���㷨ʵ�֣���������CRC16��Э��
//data,����ָ��; size,���ݳ���; crc_poly,����ʽ; init_value,��ʼֵ;
//ref_flag,����λ��ת��true-��λ��ǰ����λ�ں�
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
    //XOROUT��ֵ�̶�Ϊ0x0000
    return crc_reg;
}

