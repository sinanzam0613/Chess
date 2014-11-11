//
//  CreateScene.h
//  MyGame
//
//  Created by 星共法 on 2014/10/19.
//
//  MyGame::Assistant::CreateScene
//      主にシーン遷移時に演出を付加したい場合に利用する関数群
//      基本的に、作成済みのノーマルなシーンを引数に渡す事で演出を付与してくれるように設計

#ifndef MyGame_CreateScene_h
#define MyGame_CreateScene_h

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    namespace Assistant{
        namespace CreateScene{
            //--------------------------------------------------------
            //  @brief  トランジション:BottomLeftへ向かってフェード
            //  @sum    引数で渡されたシーンに遷移効果を加えたものを返却する
            //————————————————————————————----------------------------
            static Scene* TransitionBL(Scene* scene, float duration = 1.0f){
                Scene* t_retTransScene = nullptr;
                if(scene){
                    t_retTransScene = TransitionFadeBL::create(duration, scene);
                }
                return t_retTransScene;
            }
            
            //--------------------------------------------------------
            //　@brief	インスタンス作成関数
            //  @sum    Sceneの子にしながら作成しつつ返却
            //          主にレイヤーをインスタンス化する時に使う
            //--------------------------------------------------------
            template<class T>
            static Scene* CreateSceneIn(Scene* parrent = NULL){
                if(!parrent){
                    parrent = Scene::create();
                }
                T* t_pChild = new T();
                if (t_pChild && t_pChild->init()) {
                    t_pChild->autorelease();
                    parrent->addChild(t_pChild);
                    return parrent;
                }
                else {
                    CC_SAFE_DELETE(t_pChild);
                    return NULL;
                }
            }
        }
    }
}

#endif
