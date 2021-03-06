#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "esp32/rom/uart.h"

#include "smbus.h"
#include "i2c-lcd1602.h"
#include "lcd-menu.h"

#include <sys/types.h>
#include <string.h>

#define TAG "app"

// Undefine USE_STDIN if no stdin is available (e.g. no USB UART) - a fixed delay will occur instead of a wait for a keypress.
// #define USE_STDIN  1
#undef USE_STDIN

#define I2C_MASTER_NUM           I2C_NUM_0
#define I2C_MASTER_TX_BUF_LEN    0                     // disabled
#define I2C_MASTER_RX_BUF_LEN    0                     // disabled
#define I2C_MASTER_FREQ_HZ       100000
#define I2C_MASTER_SDA_IO        CONFIG_I2C_MASTER_SDA
#define I2C_MASTER_SCL_IO        CONFIG_I2C_MASTER_SCL
#define LCD_NUM_ROWS			 4
#define LCD_NUM_COLUMNS			 40
#define LCD_NUM_VIS_COLUMNS		 20

//lcd general settings
static i2c_lcd1602_info_t *lcdInfo;


static void i2cMasterInit(void)
{
    int i2cMasterPort = I2C_MASTER_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_DISABLE;  // GY-2561 provides 10kΩ pullups
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_DISABLE;  // GY-2561 provides 10kΩ pullups
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    i2c_param_config(i2cMasterPort, &conf);
    i2c_driver_install(i2cMasterPort, conf.mode,
                       I2C_MASTER_RX_BUF_LEN,
                       I2C_MASTER_TX_BUF_LEN, 0);
}

// Wait function
static void wait(unsigned int time)
{
    vTaskDelay(time / portTICK_RATE_MS);
}

// Init all the components that make use of the I2C protocol.
void i2cInit() 
{
    // Set up I2C
    i2cMasterInit();
    i2c_port_t i2cNum = I2C_MASTER_NUM;
    uint8_t address = CONFIG_LCD1602_I2C_ADDRESS;
    

    // // Set up the SMBus
    smbus_info_t *smbusInfo = smbus_malloc();
    smbus_init(smbusInfo, i2cNum, address);
    smbus_set_timeout(smbusInfo, 1000 / portTICK_RATE_MS);

    // Lcd and menu init
    lcdInfo = i2c_lcd1602_malloc();
    i2c_lcd1602_init(lcdInfo, smbusInfo, true, LCD_NUM_ROWS, LCD_NUM_COLUMNS, LCD_NUM_VIS_COLUMNS);
    i2c_lcd1602_set_cursor(lcdInfo, true);
}

void app_main()
{
    i2cInit();

    wait(500);
    
    doFancyAnimation(lcdInfo);

    while(1)
    {
        wait(5000);
    }
}