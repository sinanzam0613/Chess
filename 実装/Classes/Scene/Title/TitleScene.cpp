//
//  TitleScene.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/15.
//
//

#include "TitleScene.h"
#include "TitleBackGround.h"
#include "TitleMenu.h"
#include "Enum.h"

const int TAG_BACKGROUND = 0;
const int TAG_MENU = 1;

namespace MyGame {
    TitleScene::TitleScene(){
        
    }
    
    bool TitleScene::init(){
        if(!Layer::init()){
            return false;
        }
        
        //  背景要素の子クラス化
        TitleBackGround* t_backGround = TitleBackGround::create();
        t_backGround->setTag(TAG_BACKGROUND);
        this->addChild(t_backGround, LayerDepth::BACKGROUND);
        
        //  メニュー要素の子クラス化
        TitleMenu* t_menu = TitleMenu::create();
        t_menu->setTag(TAG_MENU);
        this->addChild(t_menu, LayerDepth::MENU);
        
        return true;
    }
}