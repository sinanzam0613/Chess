//
//  PlayerManager.h
//  MyGame
//
//  Created by 星共法 on 2014/10/23.
//
//

#ifndef __MyGame__PlayerManager__
#define __MyGame__PlayerManager__

#include "cocos2d.h"
#include "Def.h"
#include "CustamArray.h"

USING_NS_CC;

namespace MyGame{
    class PieceManager{
    public:
        //--------------------------------------------------------
		//　@brief	駒を複数保持する
        //  @param  num    駒数
        //--------------------------------------------------------
        PieceManager(uint num);
        
        //--------------------------------------------------------
		//　@brief	指定した位置の要素を返す
        //  @param  index   取得したい要素の位置
		//————————————————————————————----------------------------
        Node* getObject(uint index);
        
        //--------------------------------------------------------
		//　@brief	指定した位置に要素を挿入する
        //  @param  index   挿入する位置
        //  @param  node    挿入する要素
		//————————————————————————————----------------------------
        Node* Insert(uint index, Node* node);
        
        //--------------------------------------------------------
		//　@brief	指定した位置の要素を削除する
        //  @param  index   削除する位置
		//————————————————————————————----------------------------
        void Remove(uint index);
        
    private:
        CustamArray m_list;
    };
}

#endif /* defined(__MyGame__PlayerManager__) */
