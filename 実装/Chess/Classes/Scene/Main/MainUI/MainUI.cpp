//
//  MainUI.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/21.
//
//

#include "MainUI.h"
#include "AddObject.h"
#include "GameManager.h"
#include "MyMath.h"
#include "CharacterHead/CharacterHead.h"

namespace  {
    //  ChildTag
    const int TAG_STATESBAR = 0;
    const int TAG_CHARACTER_HEAD = 1;
    //  LayerDepth
    const int LAYER_STATESBAR = 0;
    const int LAYER_CHARACTER_HEAD = 1;
}

namespace MyGame{
    MainUI::MainUI(){

    }
    
    bool MainUI::init(){
        if(!Node::init()){
            return false;
        }
        
        GameManager* t_gm = GameManager::getInstance();
        
        //  メニューの大枠となるUIの作成
        Sprite* t_statesBarSprite = nullptr;
        t_statesBarSprite = Assistant::AddSprite(this,
                                                 Sprite::create("dbTex_Main_StatesUI_Layout2.png"),
                                                 TAG_STATESBAR,
                                                 Point::ZERO,
                                                 LAYER_STATESBAR);
        if(t_statesBarSprite){
            t_statesBarSprite->setPosition(t_gm->getScreenCenter());
            //  画面幅に合わせて縮尺を合わせる
            Size t_scaling = Math::ScreenToMagnification(t_statesBarSprite->getContentSize());
            t_statesBarSprite->setScale(t_scaling.width, t_scaling.height);
        }
        
        //  キャラクターの画像表示、管理クラス
        CharacterHead* t_ch = CharacterHead::create();
        t_ch->setTag(TAG_CHARACTER_HEAD);
        this->addChild(t_ch, LAYER_CHARACTER_HEAD);
        
        return true;
    }
}