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

USING_NS_CC;

namespace MyGame {
    class TitleScene : Layer{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        TitleScene();
        
        //--------------------------------------------------------
		//　@brief	必要クラスの実体化と子クラス化
		//	@sum	CREATE_FUNC_IN_SCENEとの兼ね合い上、これは必須
		//————————————————————————————----------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	TitleSceneレイヤーをScene型に突っ込んで返す
		//	@sum	1Scene1Layerの規約のもと、こういう設計にした
		//————————————————————————————----------------------------
        CREATE_FUNC_IN_SCENE(TitleScene);
        
    };
}

#endif /* defined(__MyGame__MyTitle__) */
