//Header include guard for the extension file (lcd-menu-elaboration.c)
#ifndef LCD_MENU_C
#define LCD_MENU_C

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "smbus.h"
#include "i2c-lcd1602.h"
#include "lcd-menu.h"
#include "lcd-menu-elaboration.h"

//ID's of every lcd menu (is also the number in the lcdMenus array)
#define MAIN_MENU_ID 0
#define ECHO_MENU_ID 1
#define RADIO_MENU_ID 2
#define CLOCK_MENU_ID 3
#define SPEECH_MENU_ID 4

#define INVALID 99

static i2c_lcd1602_info_t *tmp_lcd_info;

//Static functions
static void doFancyAnimation(i2c_lcd1602_info_t*);


int menu_updateMenu(i2c_lcd1602_info_t *lcdInfo, void *p)
{
    if (lcdMenus[currentLcdMenu].update == NULL)
        return LCD_MENU_ERROR;
    
    if (p != NULL)
        lcdMenus[currentLcdMenu].update(p);

    return refreshMenu(lcdInfo, currentLcdMenu, currentMenuItem);
}

//Animation that plays when u start the application
static void doFancyAnimation(i2c_lcd1602_info_t* lcdInfo)
{
    i2c_lcd1602_move_cursor(lcdInfo, 0, 0);
    for(int i = 0; i < 20; i++)
    {
        i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_0);
        vTaskDelay(15 / portTICK_RATE_MS);
    }
    i2c_lcd1602_move_cursor(lcdInfo, 19, 1);
    i2c_lcd1602_set_right_to_left(lcdInfo);
    for(int i = 0; i < 20; i++)
    {
        i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_0);
        vTaskDelay(15 / portTICK_RATE_MS);
    }
    i2c_lcd1602_move_cursor(lcdInfo, 0, 2);
    i2c_lcd1602_set_left_to_right(lcdInfo);
    for(int i = 0; i < 20; i++)
    {
        i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_0);
        vTaskDelay(15 / portTICK_RATE_MS);
    }
    i2c_lcd1602_move_cursor(lcdInfo, 19, 3);
    i2c_lcd1602_set_right_to_left(lcdInfo);
    for(int i = 0; i < 20; i++)
    {
        i2c_lcd1602_write_char(lcdInfo, I2C_LCD1602_CHARACTER_CUSTOM_0);
        vTaskDelay(15 / portTICK_RATE_MS);
    }
    i2c_lcd1602_set_left_to_right(lcdInfo);
    vTaskDelay(100 / portTICK_RATE_MS);
}

i2c_lcd1602_info_t* menu_getLcdInfo()
{
    return tmp_lcd_info;
}

#endif