//
//  MainBackGround.h
//  MyGame
//
//  Created by 星共法 on 2014/10/19.
//
//

#ifndef __MyGame__MainBackGround__
#define __MyGame__MainBackGround__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    class MainBackGround : public Node{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        MainBackGround();
        
        //--------------------------------------------------------
		//　@brief	背景画像の作成など
		//————————————————————————————----------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	cocos定義のインスタンス化関数
		//————————————————————————————----------------------------
        CREATE_FUNC(MainBackGround);
    };
}

#endif /* defined(__MyGame__MainBackGround__) */
