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
        
        bool MyGameScene::Initialize(){
            if(!Layer::init()){
                return false;
            }
            
            
            
            return true;
        }
        
        Scene* MyGameScene::create(){
            Scene* t_pRetScene = Scene::create();
            MyGameScene* t_pChild = new MyGameScene();
            if (t_pChild && t_pChild->init()) {
                t_pChild->autorelease();
                t_pRetScene->addChild(t_pChild);
                return t_pRetScene;
            }
            else {
                CC_SAFE_DELETE(t_pChild);
                return NULL;
            }
        }
    }
}
