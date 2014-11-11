//
//  MyGameScene.h
//  Chess
//
//  Created by 星共法 on 2014/11/09.
//
//  シーンを作成する際に同一機能を利用するのでそれをまとめて基底クラスにします

#ifndef __Chess__MyGameScene__
#define __Chess__MyGameScene__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    namespace Base{
        class MyGameScene  : public Layer{
        public:
            //--------------------------------------------------------
            //　@brief	コンストラクタ
            //--------------------------------------------------------
            MyGameScene();
            
            //--------------------------------------------------------
            //　@brief	デストラクタ
            //--------------------------------------------------------
            virtual ~MyGameScene();
            
            //--------------------------------------------------------
            //　@brief	初期化関数
            //  @sum    cocosで言うところのinit関数
            //--------------------------------------------------------
            virtual bool Initialize();
            
            //--------------------------------------------------------
            //　@brief	インスタンス作成関数
            //  @sum    cocosで言うところのcreate(CREATE_FUNC)関数
            //--------------------------------------------------------
            static Scene* create();
        };
    }
}


#endif /* defined(__Chess__MyGameScene__) */
