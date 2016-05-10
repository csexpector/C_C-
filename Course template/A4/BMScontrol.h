#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "CourseArray.h"
#include "User.h"
#include "FirstYear.h"
#include "SeniorYear.h"
class BMScontrol {
  public:
    BMScontrol();
    void launch();
    virtual ~BMScontrol();
  private:
    UImanager   view;
    CourseArray<Course> courses;
    Inventory * items[MAX_INVENTORY];
    User* users[MAX_USER];
    int numInventory;
    int nUser;
};

#endif

