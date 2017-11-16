/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  03-30-15
 ************************************************************************
 功能描述：
 智能垃圾桶：通过红外检测到有人体靠近需要丢垃圾，则通过舵机控制垃圾桶盖自动打开，
 丢完垃圾后垃圾桶盖自动关闭。

 所需器件:
 1.舵机
 2.E18-D80NK红外光电开关

 接线说明:
 SG90 9G舵机                  核心板
 1.红线                       +5V
 2.暗灰线                     GND
 3.橙黄线                     A0

 E18-D80NK
 1.红色线                     +5V
 2.黑色线                     GND
 3.黄色线                     D0
 */

#include <WidgetWastebin.h>

#define SERVO_CONTROL_PIN		A0

//打开和关闭垃圾桶盖时，舵机需要旋转的角度
#define OPEN_ANGLE	            70
#define	CLOSE_ANGLE	            180

WidgetWastebin wasteBin = WidgetWastebin();
Servo myservo;

uint32_t countNum = 0;

void wastebinSwitchCb(void)
{
    if(wasteBin.getWastebinSwitch())
    {
        countNum++;
        myservo.write(OPEN_ANGLE);
        wasteBin.displayWastebinStatus(1);
        wasteBin.displayOpenCount(countNum);
    }
    else
    {
        myservo.write(CLOSE_ANGLE);
        wasteBin.displayWastebinStatus(0);
    }
}

void setup()
{
    //初始化
    myservo.attach(SERVO_CONTROL_PIN);
    //接收舵机控制
    wasteBin.displayOpenCount(countNum);
    wasteBin.begin(wastebinSwitchCb);
}

void loop()
{
}
