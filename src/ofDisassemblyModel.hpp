//
//  ofDisassemblyModel.hpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/23.
//
//

#ifndef ofDisassemblyModel_hpp
#define ofDisassemblyModel_hpp

#include <stdio.h>
#include "ofxAssimpModelLoader.h"

class ofDisassemblyModel: public ofxAssimpModelLoader {
public:
    void drawCustom();
};

#endif /* ofDisassemblyModel_hpp */
