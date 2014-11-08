//
//  TitleMenu.h
//  MyGame
//
//  Created by 星共法 on 2014/10/18.
//
//

#ifndef __MyGame__TitleMenu__
#define __MyGame__TitleMenu__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    class TitleMenu : public Node{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        TitleMenu();
        
        //--------------------------------------------------------
		//　@brief	メニューの構成に必要なクラスの実体化など
		//————————————————————————————----------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	cocos定義のインスタンス化関数
		//————————————————————————————----------------------------
        CREATE_FUNC(TitleMenu);
    };
}
#endif /* defined(__MyGame__TitleMenu__) */
