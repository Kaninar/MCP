
     --a--
    |     |
    f     b
    |     |
     --g--
    |     |
    e     c
    |     |
     --d--   *DP
leonardo _  8   765432
light    5  10
         Dgfedcba
byte numberSegments[] = {
    0b00000001, //a
    0b00000010, //b
    0b00000100, //c
    0b00001000, //d
    0b00010000, //e
    0b00100000, //f
    0b01000000, //g
    0b10000000, //dp
};

byte numberSegments[] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
};