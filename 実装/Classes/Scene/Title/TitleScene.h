//
//  MyTitle.h
//  MyGame
//
//  Created by 星共法 on 2014/10/15.
//
//

#ifndef __MyGame__MyTitle__
#define __MyGame__MyTitle__

#include "cocos2d.h"
#include "Def.h"
#include "MyGameScene.h"

USING_NS_CC;

namespace MyGame {
    class TitleScene : public Base::MyGameScene {
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        TitleScene();
        
        //--------------------------------------------------------
		//　@brief	必要クラスの実体化と子クラス化
		//	@sum	CREATE_FUNCとの兼ね合い上、これは必須
		//————————————————————————————----------------------------
        bool init() override;
    };
}

#endif /* defined(__MyGame__MyTitle__) */
