//
//  AddEventListener.h
//  Chess
//
//  Created by 星共法 on 2014/11/11.
//
//  イベントリスナーを対象のオブジェクトと紐づけて登録するための補助関数

#ifndef __Chess__AddEventListener__
#define __Chess__AddEventListener__

#include "cocos2d.h"

namespace MyGame{
    namespace Assistant{
        
        //--------------------------------------------------------
        //  @brief  タッチイベントをディスパッチャーに登録する
        //  @param  began       押された瞬間に実行する関数オブジェクト
        //  @param  moved       スライドされた時に実行する関数オブジェクト
        //  @param  ended       離された瞬間に実行する関数オブジェクト
        //  @param  cancelled   何らかの理由(システム的な事とか)でタッチが終了した時に実行する関数オブジェクト
        //  @param  target      タッチイベントに関連づける対象のcocosオブジェクト
        //  @sum    さすがに引数が長ったらしいのでなんとかしたい
        //          std::bindとかつかえば出来る？
        //--------------------------------------------------------
        static void AddEventListenerTouchOneByOne(std::function<bool(Touch*, Event*)> began ,
                                                  std::function<void(Touch*, Event*)> moved ,
                                                  std::function<void(Touch*, Event*)> ended ,
                                                  std::function<void(Touch*, Event*)> cancelled,
                                                  Node* target){
            auto t_listener = EventListenerTouchOneByOne::create();
            auto t_dispatcher = Director::getInstance()->getEventDispatcher();
            t_listener->onTouchBegan = began;
            t_listener->onTouchMoved = moved;
            t_listener->onTouchEnded = ended;
            t_listener->onTouchCancelled = cancelled;
            t_dispatcher->addEventListenerWithSceneGraphPriority(t_listener, target);
        }
        
        //--------------------------------------------------------
        //  @brief  タッチイベントをディスパッチャーに登録する
        //  @param  listener    タッチイベントを既に格納済みのリスナー
        //  @param  target      タッチイベントに関連づける対象のcocosオブジェクト
        //--------------------------------------------------------
        static void AddEventListenerTouchOneByOne(EventListenerTouchOneByOne* listener, Node* target){
            auto t_dispatcher = Director::getInstance()->getEventDispatcher();
            t_dispatcher->addEventListenerWithSceneGraphPriority(listener, target);
        }
    }
}


#endif /* defined(__Chess__AddEventListener__) */
