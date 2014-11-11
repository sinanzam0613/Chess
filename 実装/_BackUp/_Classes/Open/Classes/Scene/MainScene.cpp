//
//  MainScene.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/17.
//
//

#include "MainScene.h"
#include "Enum.h"
#include "MainBackGround.h"
#include "MainUI.h"

const int TAG_BACKGROUND = 0;
const int TAG_PIECE = 1;
const int TAG_UI = 2;

namespace MyGame{
    MainScene::MainScene()
    : m_pieceManager(2){
        
    }
    
    bool MainScene::init(){
        if(!Layer::init()){
            return false;
        }
        
        
        
        //  背景の管理クラスを子クラス化
        MainBackGround* t_backGround = MainBackGround::create();
        t_backGround->setTag(TAG_BACKGROUND);
        this->addChild(t_backGround, LayerDepth::BACKGROUND);
        
        //  UIの管理クラスを子クラス化
        MainUI* t_ui = MainUI::create();
        t_ui->setTag(TAG_UI);
        this->addChild(t_ui, LayerDepth::UI);
        
        return true;
    }
}