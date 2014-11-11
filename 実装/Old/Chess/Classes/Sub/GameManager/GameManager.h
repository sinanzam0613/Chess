//
//  GameManager.h
//  MyGame
//
//  Created by 星共法 on 2014/10/15.
//
//  cocosとは言えどやっぱりラッピングせずにはいられずに作ったクラス
//  主に、cocosの内部数値を利用クラスへ持っていくための架け橋として使う

#ifndef __MyGame__GameManager__
#define __MyGame__GameManager__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    class GameManager{
    public:
        static GameManager* getInstance(){
            static GameManager t_inst;
            return &t_inst;
        }

        //--------------------------------------------------------
        //  @brief  スクリーンの中央となる座標をピクセル単位で返します
        //————————————————————————————----------------------------
        Point getScreenCenter();
        
        //--------------------------------------------------------
        //  @brief  スクリーンの原点となる座標をピクセル単位で返します
        //————————————————————————————----------------------------
        Point getScreenOrigin();

        //--------------------------------------------------------
        //  @brief  スクリーンのサイズをピクセル単位で返します
        //————————————————————————————----------------------------
        Size getScreenSize();
        
    private:
        //  利用者からのインスタンス生成などは禁止
        GameManager();
        ~GameManager();
        GameManager(const GameManager&){}
        GameManager operator=(const GameManager&){ return *this; }
        
    private:
        Director* m_pDirector;
        Size m_scrSize;
        Point m_scrCenter;
        Point m_scrOrigin;
    };
}
#endif /* defined(__MyGame__GameManager__) */
















