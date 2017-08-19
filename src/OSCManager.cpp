//
//  OSCManager.cpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/20.
//
//

#include "OSCManager.hpp"

void OSCManager::setup() {
    receiver.setup(fromPort);
}

void OSCManager::update() {
    //receive message
    while( receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        for (int i=0; i<messageReceivers.size(); i++) {
            if (m.getAddress() == messageReceivers[i].address){
                *messageReceivers[i].variablePointer = m.getArgAsInt32(0);
            }
        }
        //dumpOSC(m);
    }
}

void OSCManager::dumpOSC(ofxOscMessage m) {
    string msg_string;
    msg_string = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
}

void OSCManager::setMessageReceiver(OSCMessageReceiver messageReceiver) {
    messageReceivers.push_back(messageReceiver);
}
