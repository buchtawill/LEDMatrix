#ifndef __FRAMES_H
#define __FRAMES_H

uint8_t characters[38][8] = {
  {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C}, //0
  {0x10, 0x18, 0x14, 0x10, 0x10, 0x10, 0x10, 0x3C}, //1
  {0x3C, 0x42, 0x40, 0x40, 0x3C, 0x02, 0x02, 0x7E}, //2
  {0x3C, 0x40, 0x40, 0x3C, 0x40, 0x40, 0x42, 0x3C}, //3
  {0x22, 0x22, 0x22, 0x22, 0x7E, 0x20, 0x20, 0x20}, //4
  {0x7E, 0x02, 0x02, 0x3E, 0x40, 0x40, 0x42, 0x3C}, //5
  {0x3C, 0x02, 0x02, 0x3E, 0x42, 0x42, 0x42, 0x3C}, //6
  {0x3C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40}, //7
  {0x3C, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x42, 0x3C}, //8
  {0x3C, 0x42, 0x42, 0x42, 0x3C, 0x40, 0x40, 0x3C}, //9
  { 0x00,  0x3C,  0x66,  0x66,  0x7E,  0x66,  0x66,  0x66},     // 10 : A
  { 0x00,  0x7C,  0x66,  0x66,  0x7C,  0x66,  0x66,  0x7C },    // 11 : B
  { 0x00,  0x3C,  0x66,  0x60,  0x60,  0x60,  0x66,  0x3C },    // 12 : C
  { 0x00,  0x7C,  0x66,  0x66,  0x66,  0x66,  0x66,  0x7C },    // 13 : D
  { 0x00,  0x7E,  0x60,  0x60,  0x7C,  0x60,  0x60,  0x7E },    // 14 : E
  { 0x00,  0x7E,  0x60,  0x60,  0x7C,  0x60,  0x60,  0x60 },    // 15 : F
  { 0x00,  0x3C,  0x66,  0x60,  0x60,  0x6E,  0x66,  0x3C },    // 16 : G
  { 0x00,  0x66,  0x66,  0x66,  0x7E,  0x66,  0x66,  0x66 },    // 17 : H
  { 0x00,  0x3C,  0x18,  0x18,  0x18,  0x18,  0x18,  0x3C },    // 18 : I
  { 0x00,  0x1E,  0x0C,  0x0C,  0x0C,  0x6C,  0x6C,  0x38 },    // 19 : J
  { 0x00,  0x66,  0x6C,  0x78,  0x70,  0x78,  0x6C,  0x66 },    // 20 : K
  { 0x00,  0x60,  0x60,  0x60,  0x60,  0x60,  0x60,  0x7E },    // 21 : L
  { 0x00,  0x63,  0x77,  0x7F,  0x6B,  0x63,  0x63,  0x63 },    // 22 : M
  { 0x00,  0x63,  0x73,  0x7B,  0x6F,  0x67,  0x63,  0x63 },    // 23 : N
  { 0x00,  0x3C,  0x66,  0x66,  0x66,  0x66,  0x66,  0x3C },    // 24 : O
  { 0x00,  0x7C,  0x66,  0x66,  0x66,  0x7C,  0x60,  0x60 },    // 24 : P
  { 0x00,  0x3C,  0x66,  0x66,  0x66,  0x6E,  0x3C,  0x06 },    // 26 : Q
  { 0x00,  0x7C,  0x66,  0x66,  0x7C,  0x78,  0x6C,  0x66 },    // 27 : R
  { 0x00,  0x3C,  0x66,  0x60,  0x3C,  0x06,  0x66,  0x3C },    // 28 : S
  { 0x00,  0x7E,  0x5A,  0x18,  0x18,  0x18,  0x18,  0x18 },    // 29 : T
  { 0x00,  0x66,  0x66,  0x66,  0x66,  0x66,  0x66,  0x3E },    // 30 : U
  { 0x00,  0x66,  0x66,  0x66,  0x66,  0x66,  0x3C,  0x18 },    // 31 : V
  { 0x00,  0x63,  0x63,  0x63,  0x6B,  0x7F,  0x77,  0x63 },    // 32 : W
  { 0x00,  0x63,  0x63,  0x36,  0x1C,  0x36,  0x63,  0x63 },    // 33 : X
  { 0x00,  0x66,  0x66,  0x66,  0x3C,  0x18,  0x18,  0x18 },    // 34 : Y
  { 0x00,  0x7E,  0x06,  0x0C,  0x18,  0x30,  0x60,  0x7E },    // 35 : Z
  {0xc3, 0xc3, 0x00, 0x18, 0x18, 0x81, 0xff, 0x7e},         // 36 smiley
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}                  //37 space
};
//uint8_t smallCharacters[38][6] = {
//  {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C}, //0
//  {0x10, 0x18, 0x14, 0x10, 0x10, 0x10, 0x10, 0x3C}, //1
//  {0x3C, 0x42, 0x40, 0x40, 0x3C, 0x02, 0x02, 0x7E}, //2
//  {0x3C, 0x40, 0x40, 0x3C, 0x40, 0x40, 0x42, 0x3C}, //3
//  {0x22, 0x22, 0x22, 0x22, 0x7E, 0x20, 0x20, 0x20}, //4
//  {0x7E, 0x02, 0x02, 0x3E, 0x40, 0x40, 0x42, 0x3C}, //5
//  {0x3C, 0x02, 0x02, 0x3E, 0x42, 0x42, 0x42, 0x3C}, //6
//  {0x3C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40}, //7
//  {0x3C, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x42, 0x3C}, //8
//  {0x3C, 0x42, 0x42, 0x42, 0x3C, 0x40, 0x40, 0x3C}, //9
//  { 12,18,18,30,18,18 },     // 10 : A
//  { 28,18,28,18,18,28 },    // 11 : B
//  { 14,16,16,16,16,14 },    // 12 : C
//  { 28,18,18,18,18,30 },    // 13 : D
//  { 00,28,16,24,16,28 },    // 14 : E
//  {  },    // 15 : F
//  {  },    // 16 : G
//  {  },    // 17 : H
//  {  },    // 18 : I
//  {  },    // 19 : J
//  {  },    // 20 : K
//  {  },    // 21 : L
//  {  },    // 22 : M
//  {  },    // 23 : N
//  {  },    // 24 : O
//  {  },    // 24 : P
//  {  },    // 26 : Q
//  {  },    // 27 : R
//  {  },    // 28 : S
//  {  },    // 29 : T
//  {  },    // 30 : U
//  {  },    // 31 : V
//  {  },    // 32 : W
//  {  },    // 33 : X
//  {  },    // 34 : Y
//  {  },    // 35 : Z
//  {0xc3, 0xc3, 0x00, 0x18, 0x18, 0x81, 0xff, 0x7e},         // 36 smiley
//  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}                  //37 space
//};

uint32_t jumpFrames[24][12] = {
  {
    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x83f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x43f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0x20f80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0x10f80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0x8f80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x4780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x2780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x1380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {

    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x980000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x0,
    0x0,
    0x480000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x0,
    0x200000,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x100000,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x80000,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x40000,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x10000,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x8000,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x2000,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x1000,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x800,
    0x0,
    0x0,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x0,
    0x400,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x0,
    0x200,
    0x80000,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x0,
    0x0,
    0x80100,
    0x180000,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  },

  {
    0x0,
    0x0,
    0x0,
    0x0,
    0x80000,
    0x180040,
    0x380000,
    0x780000,
    0xf80000,
    0x3f80000,
    0x1ff80000,
    0xfffffffe
  }
};

uint32_t amongUsFrames [16][12] = {
  { //frame 1 of 16
    0b00111111100000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001111110000000000000000000000,
    0b11010000001000000000000000000000,
    0b11010000001000000000000000000000,
    0b11001111110000000000000000000000,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 2 of 16
    0b00111111100000000000000000000000,
    0b01000000010000000000000000000010,
    0b01001111110000000000000000000010,
    0b11010000001000000000000000000010,
    0b11010000001000000000000000000010,
    0b11001111110000000000000000000010,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 3 of 16
    0b00111111100000000000000000000000,
    0b01000000010000000000000000001100,
    0b01001111110000000000000000001010,
    0b11010000001000000000000000001100,
    0b11010000001000000000000000001010,
    0b11001111110000000000000000001010,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 4 of 16
    0b00111111100000000000000000000000,
    0b01000000010000000000000000110010,
    0b01001111110000000000000000101010,
    0b11010000001000000000000000110010,
    0b11010000001000000000000000101010,
    0b11001111110000000000000000101010,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 5 of 16
    0b00111111100000000000000000000000,
    0b01000000010000000000000110011100,
    0b01001111110000000000000101010000,
    0b11010000001000000000000110011000,
    0b11010000001000000000000101010000,
    0b11001111110000000000000101011100,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 6 of 16
    0b00111111100000000000000000000000,
    0b01000000010000000000011001110110,
    0b01001111110000000000010101000100,
    0b11010000001000000000011001100100,
    0b11010000001000000000010101000100,
    0b11001111110000000000010101110110,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 7 of 16
    0b00111111100000000000000000000000,
    0b01000000010000000001100111011000,
    0b01001111110000000001010100010100,
    0b11010000001000000001100110010100,
    0b11010000001000000001010100010100,
    0b11001111110000000001010111011000,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 8 of 16
    0b00111111100000000000000000000000,
    0b01000000010000011001110110000000,
    0b01001111110000010101000101000000,
    0b11010000001000011001100101000000,
    0b11010000001000010101000101000000,
    0b11001111110000010101110110000000,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000000,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 9 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000000,
    0b01000000010000000000000000000010,
    0b01001110010000000000000000000000,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000000
  },
  { //frame 10 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000000110,
    0b01000000010000000000000000001000,
    0b01001110010000000000000000000110,
    0b01001010010000000000000000000000,
    0b01111011110000000000000000000110
  },
  { //frame 11 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010000000000000000110010,
    0b01000000010000000000000001000010,
    0b01001110010000000000000000110010,
    0b01001010010000000000000000001010,
    0b01111011110000000000000000110010
  },
  { //frame 12 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010000000000000110010100,
    0b01000000010000000000001000010100,
    0b01001110010000000000000110010100,
    0b01001010010000000000000001010100,
    0b01111011110000000000000110011100
  },
  { //frame 13 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010000000000110010100110,
    0b01000000010000000001000010101000,
    0b01001110010000000000110010100110,
    0b01001010010000000000001010100000,
    0b01111011110000000000110011100110
  },
  { //frame 14 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010000000110010100110000,
    0b01000000010000001000010101000000,
    0b01001110010000000110010100110000,
    0b01001010010000000001010100001000,
    0b01111011110000000110011100110000
  },
  { //frame 15 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010000110010100110000000,
    0b01000000010001000010101000000000,
    0b01001110010000110010100110000000,
    0b01001010010000001010100001000000,
    0b01111011110000110011100110000000
  },
  { //frame 16 of 16
    0b00111111100000000000000000000000,
    0b01000000010001100111011000000000,
    0b01001111110001010100010100000000,
    0b11010000001001100110010100000000,
    0b11010000001001010100010100000000,
    0b11001111110001010111011000000000,
    0b11000000010000000000000000000000,
    0b11000000010001100101001100000000,
    0b01000000010010000101010000000000,
    0b01001110010001100101001100000000,
    0b01001010010000010101000010000000,
    0b01111011110001100111001100000000
  }
};

#endif