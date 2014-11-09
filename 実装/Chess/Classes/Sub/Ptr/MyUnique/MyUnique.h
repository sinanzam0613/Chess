//
//  MyUnique.h
//  Chess
//
//  Created by 星共法 on 2014/11/09.
//
//  pimplをstd::uniqueで実装出来ないので、一時しのぎに自前のuniqueptrライクのものを作ってみる

#ifndef __Chess__MyUnique__
#define __Chess__MyUnique__

#include "cocos2d.h"

namespace MyGame {
    namespace Ptr{
        template<class TYPE>
        class MyUnique{
        public:
            MyUnique(){
                m_managePtr = new TYPE;
            }
            
            MyUnique(TYPE* manage){
                m_managePtr = manage;
            }
            
            ~MyUnique(){
                delete m_managePtr;
                m_managePtr = 0;
                log("deleted_MyUnique");
            }
            TYPE* operator->(){
                return m_managePtr;
            }
            
        private:
            TYPE* m_managePtr;
        };
    }
}


#endif /* defined(__Chess__MyUnique__) */
