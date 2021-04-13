#ifndef LCDMENU_H
#define LCDMENU_H

//LCD_MENU error codes
#define LCD_MENU_OKE 0
#define LCD_MENU_ERROR 1

const unsigned char botFireFrame1[8] = {

    0b00000000,
    0b00000010,
    0b00001000,
    0b00000101,
    0b00010100,
    0b00011110,
    0b00011111,
    0b00011111
};

const unsigned char botFireFrame2[8] = {

    0b00000000,
    0b00000010,
    0b00001000,
    0b00000001,
    0b00010100,
    0b00011110,
    0b00011111,
    0b00011111
};

const unsigned char botFireFrame3[8] = {

    0b00001000,
    0b00000001,
    0b00000000,
    0b00000100,
    0b00001100,
    0b00011111,
    0b00011111,
    0b00011111
};

const unsigned char botFireFrame4[8] = {

    0b00000010,
    0b00000000,
    0b00000000,
    0b00000100,
    0b00010100,
    0b00011110,
    0b00011111,
    0b00011111
};

const unsigned char topFireFrame1[8] = {

    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000010,
    0b00001000,
    0b00000001
};

const unsigned char topFireFrame2[8] = {

    0b00000000,
    0b00000000,
    0b00000000,
    0b00000010,
    0b00001000,
    0b00000001,
    0b00000000,
    0b00000010
};

const unsigned char topFireFrame3[8] = {

    0b00000000,
    0b00000010,
    0b00001000,
    0b00000001,
    0b00000000,
    0b00000010,
    0b00001000,
    0b00000001
};

const unsigned char topFireFrame4[8] = {

    0b00001000,
    0b00000001,
    0b00000000,
    0b00000000,
    0b00000010,
    0b00001000,
    0b00000001,
    0b00000010
};

/*
Call this method to start the animation

-Returns:       
-Parameters:    a pointer to the lcd info
*/
void doFancyAnimation(i2c_lcd1602_info_t*);

#endif