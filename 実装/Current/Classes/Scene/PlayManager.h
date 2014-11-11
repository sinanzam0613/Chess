//
//  PlayManager.h
//  Chess
//
//  Created by 星共法 on 2014/11/08.
//
//

#ifndef __Chess__PlayManager__
#define __Chess__PlayManager__

#include "cocos2d.h"
#include "PieceManager.h"

USING_NS_CC;

namespace MyGame{
    class PlayManager : Node{
    public:
    	 //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        PlayManager();
        
        //--------------------------------------------------------
		//　@brief	必要クラスの実体化と子クラス化
		//	@sum	CREATE_FUNCとの兼ね合い上、これは必須
		//————————————————————————————----------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	PlayManagerのインスタンスを作成する
		//————————————————————————————----------------------------
        CREATE_FUNC(PlayManager)
        
    private:
        PieceManager m_pm;
    };
}

#endif /* defined(__Chess__PlayManager__) */
