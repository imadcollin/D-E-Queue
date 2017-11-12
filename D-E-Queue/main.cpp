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
    int top1,top2;
    DQueue()
    {
        // TODO
        leftSentinel=NULL;
        rightSentinel=NULL;
         top1=0;
         top2=0;
        
    }
    // pushes the given value to the left end of the deque
    void PushLeft(int val)
    {
        //If no Elments!
        if(top1+top2==0)
        {
         leftSentinel=new (struct QNode);
            
            leftSentinel->val=val;
            leftSentinel->left=NULL;
            leftSentinel->right=NULL;
            top1++;
            
            cout<<"First element pushed into empty Deque"<<endl;
        }
        // TODO
    }
    
    // pushes the given value to the right end of the deque
    void PushRight(int val)
    {
        // TODO
    }
    
    // pops the leftmost value from the deque (-1 if empty)
    int PopLeft()
    {
        // TODO
        return -1;
    }
    
    // pops the rightmost value from the deque (-1 if empty)
    int PopRight()
    {
        // TODO
        return -1;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    DQueue d;
    d.PushLeft(4);
    return 0;
}


