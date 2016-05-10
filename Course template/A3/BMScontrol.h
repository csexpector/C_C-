#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "CourseArray.h"

class BMScontrol {
  public:
    BMScontrol();
    void launch();
    virtual ~BMScontrol();
  private:
    UImanager   view;
    CourseArray courses;
    Inventory * items[MAX_INVENTORY];
    int numInventory;
};

#endif

