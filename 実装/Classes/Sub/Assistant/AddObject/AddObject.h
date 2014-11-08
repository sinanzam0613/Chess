//
//  AddObject.h
//  MyGame
//
//  Created by 星共法 on 2014/10/21.
//
//

#ifndef MyGame_AddObject_h
#define MyGame_AddObject_h

#include "cocos2d.h"
#include "Def.h"

namespace MyGame {
    namespace Assistant{
        //--------------------------------------------------------
        //  @brief  NodeにSpriteを追加する
        //  @oaram  node
        //--------------------------------------------------------
        static cocos2d::Sprite* AddSprite(cocos2d::Node* node, Sprite* sprite){
            if(node){
                //  作成済みの正しいスプライトが渡されたなら
                if(sprite){
                    node->addChild(sprite);
                    return sprite;
                }
                //  不正なスプライトを渡されたならそれを示す
                LOG_CUSTOM("%s", "AddError_OnCreateEscapeTexture");
                Sprite* t_retSprite = Sprite::create("EscapeTexture.png");
                node->addChild(t_retSprite);
                return t_retSprite;
            }
            return NULL;
        }
        
        //--------------------------------------------------------
        //  @brief  NodeにSpriteを追加する
        //--------------------------------------------------------
        static cocos2d::Sprite* AddSprite(cocos2d::Node* node, Sprite* sprite, int tag, cocos2d::Point pos, int priority = 0){
            if(node){
                //  失敗している時のためのスプライト
                Sprite* t_retSprite = nullptr;
                //  作成済みの正しいスプライトが渡されたなら
                if(sprite){
                    node->addChild(sprite, priority);
                    t_retSprite = sprite;
                }
                else{
                    //  不正なスプライトを渡されたならそれを示す
                    LOG_CUSTOM("%s", "AddError_OnCreateEscapeTexture");
                    t_retSprite = Sprite::create("EscapeTexture.png");
                    node->addChild(t_retSprite, priority);
                }
                t_retSprite->setPosition(pos);
                t_retSprite->setTag(tag);
                return t_retSprite;
            }
            return NULL;
        }
    }
}

#endif
