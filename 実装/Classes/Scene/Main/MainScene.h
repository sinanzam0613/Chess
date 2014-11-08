//
//  MainScene.h
//  MyGame
//
//  Created by 星共法 on 2014/10/17.
//
//

#ifndef __MyGame__MainScene__
#define __MyGame__MainScene__

#include "cocos2d.h"
#include "Def.h"
#include "PieceManager.h"

USING_NS_CC;

namespace MyGame{
    class MainScene : public Layer{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        MainScene();
        
        //--------------------------------------------------------
		//　@brief	必要クラスの実体化と子クラス化
		//	@sum	CREATE_FUNC_IN_SCENEとの兼ね合い上、これは必須
		//————————————————————————————----------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	MainSceneレイヤーをScene型に突っ込んで返す
		//	@sum	1Scene1Layerの規約のもと、こういう設計にした
		//————————————————————————————----------------------------
        CREATE_FUNC_IN_SCENE(MainScene);
        
    private:
        PieceManager m_pieceManager;
    };
}

#endif /* defined(__MyGame__MainScene__) */
