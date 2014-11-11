//
//  TitleBackGround.h
//  MyGame
//
//  Created by 星共法 on 2014/10/18.
//
//

#ifndef __MyGame__TitleBackGround__
#define __MyGame__TitleBackGround__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    class TitleBackGround : public Node{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//------------------------------------------------------
        TitleBackGround();
        
        //--------------------------------------------------------
		//　@brief	背景の表示に必要なクラスの実体化など
		//————————————————————————————--------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	cocos定義のインスタンス化関数
		//————————————————————————————--------------------------
        CREATE_FUNC(TitleBackGround);
    };
}
#endif /* defined(__MyGame__TitleBackGround__) */
