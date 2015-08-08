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
        int _ecN;
        int _ecK;
        int _repPlaPolicy;

        int _replicaNum;
        double _bandwidth;
        int _blockSize;
        int _randSeed;

        // workload related
        double _writeInterval;
        double _inClusWritePercent;
        double _bgTrafficInterval;
        double _inRackTrafficPercent;
        int _encodingStripeCount;
        int _maxInRack;

        // stairCode configs
        int _stairRow;
        int _stairColumn;
        int _stairGlobalVecLen;
        int* _stairGlobalVec;

        // RS and LRC setting
        int _rsK;
        int _lrcK;
        int _hcodeK;
        
        // coding schemes
        int _codScheme;
        // read interval, 10 by default
        double _readInterval;

        int _failedNode;

        config();
        int getRackNum(){return _rackNum;};
        int getNodePerRack(){return _nodePerRack;};
        int getNodeNum(){return _nodeNum;};
        int getEcN(){return _ecN;};
        int getEcK(){return _ecK;};
        int getReplicaNum(){return _replicaNum;};
        int getRepPlaPolicy(){return _repPlaPolicy;};
        int getBlockSize(){return _blockSize;};
        double getBandwidth(){return _bandwidth;};
};

#endif


