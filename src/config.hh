#ifndef _CONFIG_HH_
#define _CONFIG_HH_

#include "tinyxml2.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define STAIR 0
#define RS 1
#define LRC 2
#define HCODE 3

class config{
  public:
    int _rackNum;
    int _nodePerRack;
    int _nodeNum;

    double _localRate;
    double _globalRate;
};

#endif


