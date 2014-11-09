//
//  EndingScene.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/17.
//
//

#include "EndingScene.h"
#include "AddObject.h"
#include "MyMath.h"

namespace MyGame {
    EndingScene::EndingScene(){
        
    }
    
    bool EndingScene::init(){
        if(!Layer::init()){
            return false;
        }
        
        Sprite* t_backGround = nullptr;
        t_backGround = Assistant::AddSprite(this, Sprite::create("dbTex_Ending_BackGround.png"));
        Size t_scaling;
        t_scaling = Math::ScreenToMagnification(t_backGround->getContentSize());
        t_backGround->setScale(t_scaling.width, t_scaling.height);
        
        return true;
    }
}