#include "WidgetWastebin.h"


WidgetWastebin::WidgetWastebin(uint8_t ucItem)
{
    _Item = ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    memset(pDataOpenTimesTopic,0,sizeof(pDataOpenTimesTopic));
    sprintf(pCmdSwitchTopic,"channel/wastebin_%d/cmd/switch",_Item);
    sprintf(pDataStatusTopic,"channel/wastebin_%d/data/status",_Item);
    sprintf(pDataOpenTimesTopic,"channel/wastebin_%d/data/countnum",_Item);
}

WidgetWastebin::~WidgetWastebin()
{

}

void WidgetWastebin::begin(void (*UserCallBack)(void))
{
    _EventCb = UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

char WidgetWastebin::getWastebinSwitch(void)
{
    return _switchKey;
}

void WidgetWastebin::displayWastebinStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataStatusTopic,ucVal);
}

void WidgetWastebin::control(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    digitalWrite(ucPin, ucVal);
    displayWastebinStatus(ucVal);
}

void WidgetWastebin::displayOpenCount(int count)
{
    IntoRobot.publish(pDataOpenTimesTopic,count);
}

void WidgetWastebin::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(payload[0] == '1')
    {
        _switchKey = ON;
    }
    else
    {
        _switchKey = OFF;
    }
    _EventCb();
}
