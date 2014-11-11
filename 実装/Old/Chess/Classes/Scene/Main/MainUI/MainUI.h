//
//  MainUI.h
//  MyGame
//
//  Created by 星共法 on 2014/10/21.
//
//

#ifndef __MyGame__MainUI__
#define __MyGame__MainUI__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    class MainUI : public Node{
    public:
    	//--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        MainUI();
        
        //--------------------------------------------------------
		//　@brief	必要クラスの実体化と子クラス化
		//	@sum	CREATE_FUNCとの兼ね合い上、これは必須
		//————————————————————------------------------------------
        bool init();
        
         //--------------------------------------------------------
		//　@brief	MainUIのインスタンスを作成する
		//————————————————————————————----------------------------
        CREATE_FUNC(MainUI);
    };
}

#endif /* defined(__MyGame__MainUI__) */
