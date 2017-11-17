//
//  main.cpp
//  D-E-Queue
//
//  Created by Imad Collin on 2017-11-12.
//  Copyright © 2017 Imad Collin. All rights reserved.
//

#include <iostream>
#define  transaction 1
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
        leftSentinel=NULL;
        rightSentinel=NULL;
    }
    // pushes the given value to the left end of the deque
    void PushLeft(int val)
    {
#if transaction
        __transaction_atomic{
#endif
            //If no Elements!
            if(leftSentinel==NULL)
            {
                leftSentinel=new (struct QNode);
                leftSentinel->val=val;
                leftSentinel->left=NULL;
                leftSentinel->right=NULL;
                rightSentinel = leftSentinel;
            }
            else{
                struct QNode *temp =new (struct QNode);
                temp->right=leftSentinel;
                temp->left=NULL;
                temp->val=val;
                leftSentinel->left=temp;
                leftSentinel=temp;
            }
#if transaction
        }
#endif
    }
    
    // pushes the given value to the right end of the deque
    void PushRight(int val)
    {
#if transaction
        __transaction_atomic{
#endif
            
            //If no Elments!
            if(leftSentinel==NULL){
                rightSentinel=new (struct QNode);
                rightSentinel->val=val;
                rightSentinel->left=NULL;
                rightSentinel->right=NULL;
                leftSentinel = rightSentinel;
            }
            else{
                struct QNode *temp =new (struct QNode);
                temp->left=rightSentinel;
                temp->right=NULL;
                temp->val=val;
                rightSentinel->right=temp;
                rightSentinel=temp;
            }
#if transaction
        }
#endif
        
    }
    
    // pops the leftmost value from the deque (-1 if empty)
    int PopLeft()
    {
#if transaction
        __transaction_atomic{
#endif
            if(leftSentinel==NULL){
                return -1;
            }
            else{
                int temp_val = leftSentinel->val;
                QNode* temp_node = leftSentinel->right;
                delete(leftSentinel);
                leftSentinel=temp_node;
                if(leftSentinel!=NULL){
                    leftSentinel->left=NULL;
                }
                return temp_val;
            }
#if transaction
        }
#endif
    }
    
    // pops the rightmost value from the deque (-1 if empty)
    int PopRight()
    {
#if transaction
        __transaction_atomic{
#endif
            
            if(leftSentinel==NULL){
                return -1;
            }
            else{
                int temp_val = rightSentinel->val;
                if(rightSentinel->left!=NULL){
                    QNode* temp_node = rightSentinel->left;
                    delete(rightSentinel);
                    
                    rightSentinel=temp_node;
                }
                if(leftSentinel!=NULL){
                    rightSentinel->right=NULL;
                }
                return temp_val;
            }
            
        }
#if transaction
    }
#endif
};

int main(int argc, const char * argv[]) {
    // insert code here...
#if transaction
    cout<<"testing... "<<endl;
#endif
    DQueue d;
    int i;
    for(i=0 ;i<10;i++){
        d.PushLeft(i);
        //  d.PushRight(i);
    }
    cout<<d.PopLeft()<<endl;
    
    
    return 0;
}

