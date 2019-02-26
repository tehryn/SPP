// https://ieeexplore.ieee.org/document/6987839
int CRC4_procByte( int acc, int data, int table[256] )
{
    acc = acc ^ data;
    acc = acc >> 8  ^ table[acc & OxFF];
    acc = acc >> 8  ^ table[acc & OxFF];
    acc = acc >> 8  ^ table[acc & OxFF];
    return acc >> 8 ^ table[acc & OxFF];
}