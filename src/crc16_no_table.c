uint16_t crc16_software( char *message ) {
    uint64_t crc = 0xFFFF;
    while ( *message ) {
        crc ^= *message++ << 8;
        for ( int i = 0; i < 8; i++ ) {
            if ( crc & 0x8000 ) {
                crc = ( crc << 1 ) ^ 0x1021;
            }
            else {
                crc <<= 1;
            }
        }
    }
    return crc;
}