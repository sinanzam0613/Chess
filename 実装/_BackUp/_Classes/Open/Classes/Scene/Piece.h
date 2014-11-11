//
//  Player.h
//  MyGame
//
//  Created by 星共法 on 2014/10/19.
//
//

#ifndef __MyGame__Player__
#define __MyGame__Player__

#include "cocos2d.h"
#include "Def.h"

USING_NS_CC;

struct PieceData{
    std::string textureName;
    uint dictionaryIndex;
};

namespace MyGame{
    class Piece : public Node{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        Piece();
        
        //--------------------------------------------------------
		//　@brief	プレイヤーを構成するためのクラスの実体化など
		//————————————————————————————----------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	cocos定義のインスタンス化関数
		//————————————————————————————----------------------------
        CREATE_FUNC(Piece);
    };
}

#endif /* defined(__MyGame__Player__) */
