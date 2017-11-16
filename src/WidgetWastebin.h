#ifndef WIDGET_WASTEBIN_H_
#define WIDGET_WASTEBIN_H_

#include "application.h"

class WidgetWastebin : public WidgetBaseClass
{
    public:
        WidgetWastebin(uint8_t ucItem = 0);
        ~WidgetWastebin();

        void begin(void (*UserCallBack)(void) = NULL);
        char getWastebinSwitch(void);
        void displayWastebinStatus(uint8_t ucVal);
        void control(uint8_t ucPin, uint8_t ucVal);
        void displayOpenCount(int count);

    private:
        char pCmdSwitchTopic[64];
        char pDataStatusTopic[64];
        char pDataOpenTimesTopic[64];
        char _switchKey = 0;
        uint8_t _Item = 0;
        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
