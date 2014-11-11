//
//  MyGameScene.cpp
//  Chess
//
//  Created by 星共法 on 2014/11/09.
//  シーンを管理するクラスの基底クラス
//  1シーン1レイヤーは崩さない

#include "MyGameScene.h"

namespace MyGame{
    namespace Base{
        MyGameScene::MyGameScene(){
            
        }
        
        MyGameScene::~MyGameScene(){
            
        }
        
        bool MyGameScene::init(){
            if(!Layer::init()){
                return false;
            }
            return true;
        }
    }
}
