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
            //--------------------------------------------------------
            //  @brief  コンストラクタ
            //  @sum    特に渡されなければ勝手にnewして管理する
            //--------------------------------------------------------
            MyUnique(){
                m_managePtr = new TYPE;
            }
            
            //--------------------------------------------------------
            //  @brief  引数有りコンストラクタ
            //  @sum    渡されたオブジェクトを今後管理してゆく
            //--------------------------------------------------------
            MyUnique(TYPE* manage){
                m_managePtr = manage;
            }
            
            //--------------------------------------------------------
            //  @brief  デストラクタ
            //--------------------------------------------------------
            ~MyUnique(){
                delete m_managePtr;
                m_managePtr = 0;
                log("deleted_MyUnique");
            }
            
            //--------------------------------------------------------
            //  @brief  アローのオペレータ
            //  @sum    管理しているクラスのポインタを返す
            //--------------------------------------------------------
            TYPE* operator->(){
                return m_managePtr;
            }
            
        private:
            //  任意の型のポインタを持つ
            TYPE* m_managePtr;
        };
    }
}


#endif /* defined(__Chess__MyUnique__) */
