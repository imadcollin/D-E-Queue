//
//  main.cpp
//  D-E-Queue
//
//  Created by Imad Collin on 2017-11-12.
//  Copyright © 2017 Imad Collin. All rights reserved.
//

#include <iostream>
using namespace std;
class DQueue
{
    struct QNode
    {
        QNode *left, *right;
        int val;
    };
    
    QNode *leftSentinel, *rightSentinel;
    
public:
    
    DQueue()
    {
        // TODO
    }
    
    void PushLeft(int val)
    {
        // TODO
    }
    
    void PushRight(int val)
    {
        // TODO
    }
    
    int PopLeft()
    {
        // TODO
        return -1;
    }
    
    int PopRight()
    {
        // TODO
        return -1;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}


