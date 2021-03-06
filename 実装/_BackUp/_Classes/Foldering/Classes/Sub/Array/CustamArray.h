//
//  CustamArray.h
//  MyGame
//
//  Created by 星共法 on 2014/10/24.
//
//  std::vectorをラッピングしてCocosのオブジェクト専用のリストを作成するクラス

#ifndef __MyGame__CustamArray__
#define __MyGame__CustamArray__

#include "cocos2d.h"
#include "Def.h"
#include <vector>

namespace MyGame{
    class CustamArray{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//————————————————————————————----------------------------
        CustamArray();
        
        //--------------------------------------------------------
		//　@brief	バッファサイズを指定してクラスを作成する
        //  @param  size    バッファの初期サイズ
		//————————————————————————————----------------------------
        CustamArray(uint size);
        
        //--------------------------------------------------------
		//　@brief	ノーマルなデストラクタ
		//————————————————————————————----------------------------
        ~CustamArray();
        
        //--------------------------------------------------------
		//　@brief	リストの末尾に要素を追加する
        //  @param  node    追加する要素
		//————————————————————————————----------------------------
        cocos2d::Node* PushBack(cocos2d::Node* node);
        
        //--------------------------------------------------------
		//　@brief	指定した位置の要素をリストから外す
        //  @param  index   外す要素数
		//————————————————————————————----------------------------
        cocos2d::Node* Remove(uint index);
        
        //--------------------------------------------------------
		//　@brief	指定した位置に要素を挿入する
        //  @param  index   挿入する位置
        //  @param  node    挿入する要素
		//————————————————————————————----------------------------
        cocos2d::Node* Insert(uint index, cocos2d::Node* node);
        
        //--------------------------------------------------------
		//　@brief	指定した位置の要素を返す
        //  @param  index   返す要素の位置
        //--------------------------------------------------------
        cocos2d::Node* get(uint index);
        
    private:
        //  Nodeを継承したオブジェクトをリスト管理する
        std::vector<cocos2d::Node*> m_list;
    };
}

#endif /* defined(__MyGame__CustamArray__) */
