//
//  BrainModelData.h
//  BrainFu_k
//
//  Created by Murawaki on 2017/08/29.
//
//

#include <stdio.h>
#include "ofMain.h"

#ifndef BrainModelData_h
#define BrainModelData_h

struct BrainModelData {
public:
    static const int modelNum = 152;
    static const string basePath;
    static const string modelNames[modelNum];
};

#endif /* BrainModelData_h */
