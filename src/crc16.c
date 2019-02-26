uint16_t crc_table16[256] = {0,};
void init() {
    uint16_t remainder16 = 0;
    for ( int i = 0; i < 256; i++ ) {
        remainder16 = i << 8;
        for ( int i = 0; i < 8; i++ ) {
            if ( remainder16 & 0x8000 )
                remainder16 = ( remainder16 << 1 ) ^ 0x1021;
            else
                remainder16 <<= 1;
        }
        crc_table16[ i ] = remainder16;
    }
}
uint16_t crc16_software_table( char *message ) {
    uint16_t crc = 0xFFFF;
    while ( *message )
        crc = (crc << 8)^crc_table16[((crc >> 8)^*message++)];
    return crc;
}