#ifndef LCDMENU_H
#define LCDMENU_H

//LCD_MENU error codes
#define LCD_MENU_OKE 0
#define LCD_MENU_ERROR 1

/*
Call this method to update the current lcd menu

-Returns:       a LCD_MENU error code
-Parameters:    a pointer to the lcd info, a generic value     
*/
int menu_updateMenu(i2c_lcd1602_info_t*, void*);

/*
Call this method to start the animation

-Returns:       Void
-Parameters:    a pointer to the lcd info
*/
void doFancyAnimation(i2c_lcd1602_info_t*);

//Returns the lcd info
i2c_lcd1602_info_t* menu_getLcdInfo();

#endif