//
//  TitleMenu.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/18.
//
//

#include "TitleMenu.h"
#include "MainScene.h"
#include "GameManager.h"
#include "CreateScene.h"

using namespace MyGame::Assistant;

namespace MyGame {
    TitleMenu::TitleMenu(){
        
    }
    
    bool TitleMenu::init(){
        if(!Node::init()){
            return false;
        }
        
        GameManager* t_gm = GameManager::getInstance();
        
        //  MainSceneへ飛ぶためのラムダ
        auto t_funcSceneNext = [](Ref* pSender){
            Scene* t_transition = CreateScene::TransitionBL(MainScene::create(), 2.0f);
            Director::getInstance()->replaceScene(t_transition);
        };
        
        //  MainSceneへ飛ぶためのボタンの作成
        MenuItemImage* t_item = MenuItemImage::create("dbTex_Title_GotoNextSceneButton.png", "dbTex_Title_GotoNextSceneButton.png", t_funcSceneNext);
        t_item->setPosition(t_gm->getScreenCenter());
        
        //  ボタン群をまとめるメニューの作成
        Menu* t_menu = Menu::create(t_item, NULL);
        t_item->setPosition(t_gm->getScreenOrigin());
        
        //  メニューの子クラス化
        this->addChild(t_menu);
        
        return true;
    }
}