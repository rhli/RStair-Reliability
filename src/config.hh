#ifndef _CONFIG_HH_
#define _CONFIG_HH_

#include "tinyxml2.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>

class config{
  public:
    int _rackNum;
    int _nodePerRack;
    int _nodeNum;

    double _localRate;
    double _globalRate;

    std::vector<int> _stairVec;
    config();
};

#endif


