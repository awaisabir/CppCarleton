#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "Dlist.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
  private:
    UImanager* view;                         //changed
    Dlist* courses;                   //changed
};

#endif

