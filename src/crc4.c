// https://ieeexplore.ieee.org/document/6987839
int CRC4_procByte( int acc, int data, int table[256] )
{
    return acc>>8 ^ table[ (data^acc) & 0xFF ];
}