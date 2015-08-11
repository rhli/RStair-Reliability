#include <iostream>
#include <vector>
#include "config.hh"

using namespace std;

class RateGen{
    config* _conf;
    int _stateCount;
  public:
    RateGen(config* conf);
    int generate();
};

