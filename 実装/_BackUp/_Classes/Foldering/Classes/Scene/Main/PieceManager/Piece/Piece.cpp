//
//  Player.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/19.
//
//

#include "Piece.h"
#include "GameManager.h"
#include "AddObject.h"
#include "MyMath.h"
#include "Def.h"

namespace{
    const int TAG_PLAYER_SPRITE = 0;
}

namespace MyGame{
    Piece::Piece(){
        
    }
    
    bool Piece::init(){
        if(!Node::init()){
            return false;
        }
        
        GameManager* t_gm = GameManager::getInstance();
        
        //  プレイヤー画像の作成
        Sprite* t_sprite = Sprite::create("dbTex_Main_Player.png");
        t_sprite->setPosition(t_gm->getScreenOrigin());
        t_sprite->setTag(TAG_PLAYER_SPRITE);
        this->addChild(t_sprite);
        //Assistant::AddSprite(this, t_sprite, TAG_PLAYER_SPRITE, t_gm->getScreenCenter(), 5);
        
        auto t_touchListener = EventListenerTouchOneByOne::create();
        
        //  タッチされたときの処理をラムダで記述
        t_touchListener->onTouchBegan = [t_sprite](Touch* touch, Event* event){
            return true;
        };
        //  スライドされたときの処理を記述
        t_touchListener->onTouchMoved = [t_sprite](Touch* touch, Event* event){
            t_sprite->setPosition(touch->getLocation());
        };
        t_touchListener->onTouchEnded = [t_sprite](Touch* touch, Event* event){
            Point t_pos = t_sprite->getPosition();
            Size t_size = t_sprite->getContentSize();
            Rect t_rect = Rect(t_pos.x, t_pos.y, t_size.width, t_size.height);
            
            if (Math::IsRectInPoint(t_rect, touch->getLocation())){
                LOG_CUSTOM("touch end");
            }
        };
        //  リスナーを登録
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touchListener, t_sprite);
        
        LOG_CUSTOM("pPos : %f, %f", t_sprite->getPosition().x, t_sprite->getPosition().y);
        
        return true;
    }
}












