//
//  ShowCharacterStatus.h
//  MyGame
//
//  Created by 星共法 on 2014/10/22.
//
//

#ifndef __MyGame__ShowCharacterStatus__
#define __MyGame__ShowCharacterStatus__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    class ShowCharacterStatus : public Node{
    public:
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//————————————————————————————----------------------------
        ShowCharacterStatus(unsigned int textureBufferNum);
        
        //--------------------------------------------------------
		//　@brief	ノーマルなデストラクタ
		//————————————————————————————----------------------------
        ~ShowCharacterStatus();
        
        //--------------------------------------------------------
		//　@brief	必要なクラスのインスタンス化など
		//————————————————————————————----------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	ココス定義のポピュラーなcreate
		//————————————————————————————----------------------------
        static ShowCharacterStatus* create(unsigned int textureBufferNum);
        
        //--------------------------------------------------------
		//　@brief	詳細ステータスの表示非表示を切り替える
        //  @param  active 詳細ステータスを表示するか否か
		//————————————————————————————----------------------------
        void setActive(bool active);
        
        //--------------------------------------------------------
		//　@brief	詳細ステータスを表示しているかを取得
        //--------------------------------------------------------
        bool getIsActive();
        
        //--------------------------------------------------------
		//　@brief	表示する詳細ステータスに使う画像を切り替える
        //  @param  index   対象の画像が割り当てられているインデックス
		//————————————————————————————----------------------------
        void ChangeSprite(int index);
        
    private:
        //  画像の名前リストとその管理を隠したい
        class Impl;
        
    private:
        //  隠蔽
        Impl* m_impl;
        //  表示する画像の容器
        Sprite* m_showSprite;
        //  表示するスプライトのインデックス
        int m_showIndex;
        //  詳細情報を表示しているか？
        bool m_isActive;
        //  表示するサイズ
        const Size m_showSize;
        //  表示する座標
        Point m_showPosition;
    };
}

#endif /* defined(__MyGame__ShowCharacterStatus__) */








