//
//  TitleBackGround.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/18.
//
//

#include "TitleBackGround.h"
#include "GameManager.h"
#include "MyMath.h"

namespace MyGame {
    TitleBackGround::TitleBackGround(){
        
    }
    
    bool TitleBackGround::init(){
        if(!Node::init()){
            return false;
        }
        
        GameManager* t_gm = GameManager::getInstance();
        
        //  表示する背景画像の作成
        Sprite* t_sprite = Sprite::create("dbTex_Title_BackGround.png");
        
        //  画面いっぱいに背景画像を表示するように調整
        Size t_scaling = Math::ScreenToMagnification(t_sprite->getContentSize());
        
        t_sprite->setScale(t_scaling.width, t_scaling.height);
        
        t_sprite->setPosition(t_gm->getScreenCenter());
        
        this->addChild(t_sprite);
        
        return true;
    }
}