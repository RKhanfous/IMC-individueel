#ifndef LCD_MENU_C
#define LCD_MENU_C

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "smbus.h"
#include "i2c-lcd1602.h"
#include "lcd-menu.h"

//Static functions
void doFancyAnimation(i2c_lcd1602_info_t*);

void defineCustmChar(i2c_lcd1602_info_t* lcdInfo)
{
    //bot fire
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_0, botFireFrame1);
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_1, botFireFrame2);
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_2, botFireFrame3);
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_3, botFireFrame4);

    //top fire
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_4, topFireFrame1);
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_5, topFireFrame2);
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_6, topFireFrame3);
    i2c_lcd1602_define_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_7, topFireFrame4);
}

/*
    Tried to reduce the amount of duplicate code through a method, method didnt work for some reason.
    Because of the time im leaving it like this, I will keep the method in as proof of me trying to do it.
*/

// void displayCustmChar(i2c_lcd1602_info_t* lcdInfo, int row, int charID)
// {
//     for(int i = 0; i < 20; i++)
//         {
//             i2c_lcd1602_move_cursor(lcdInfo, i, row);
//             i2c_lcd1602_write_char(lcdInfo, charID);
//             vTaskDelay(10/portTICK_RATE_MS);
//         }
// }

//Animation that plays when u start the application
void doFancyAnimation(i2c_lcd1602_info_t* lcdInfo)
{
    i2c_lcd1602_set_cursor(lcdInfo, false);
    /*
        custom 0 = bot fire  first frame.
        custom 1 = bot fire  second frame.
        custom 2 = bot fire  third frame.
        custom 3 = bot fire  fourth frame.

        custom 4 = top fire  first frame.
        custom 5 = top fire  second frame.
        custom 6 = top fire  third frame.
        custom 7 = top fire  fourth frame.
    */
    defineCustmChar(lcdInfo);

    for(int i = 0; i < 10; i++){

        //frame 1
        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 3);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_0);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 2);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_4);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 1);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_4);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 0);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_4);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        i2c_lcd1602_clear(lcdInfo);

        //frame 2
        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 3);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_1);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 2);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_5);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 1);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_5);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 0);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_5);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        i2c_lcd1602_clear(lcdInfo);

        //frame 3
        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 3);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_2);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 2);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_6);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 1);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_6);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 0);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_6);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        i2c_lcd1602_clear(lcdInfo);

        //frame 4
        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 3);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_3);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 2);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_7);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 1);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_7);
            vTaskDelay(10/portTICK_RATE_MS);
        }

        for(int i = 0; i < 20; i++)
        {
            i2c_lcd1602_move_cursor(lcdInfo, i, 0);
            i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_7);
            vTaskDelay(10/portTICK_RATE_MS);
        }

    }

}

#endif