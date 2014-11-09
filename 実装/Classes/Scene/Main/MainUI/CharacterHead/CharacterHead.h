//
//  CharacterHead.h
//  MyGame
//
//  Created by 星共法 on 2014/10/21.
//
//

#ifndef __MyGame__CharacterHead__
#define __MyGame__CharacterHead__

#include "cocos2d.h"
#include "ShowCharacterStatus/ShowCharacterStatus.h"
#include <map>

USING_NS_CC;

namespace MyGame{
    class CharacterHead : public Node{
    public:
        
        //--------------------------------------------------------
		//　@brief	ノーマルなコンストラクタ
		//--------------------------------------------------------
        CharacterHead();
        
        //--------------------------------------------------------
		//　@brief	必要クラスの実体化など
		//--------------------------------------------------------
        bool init();
        
        //--------------------------------------------------------
		//　@brief	ココス定義のポピュラーなcreate
		//--------------------------------------------------------
        CREATE_FUNC(CharacterHead);
        
        //--------------------------------------------------------
		//　@brief	この顔画像の表示非表示を切り替える
        //  @param  active  表示するか否か
		//--------------------------------------------------------
        void setActive(bool active);
        
        //--------------------------------------------------------
		//　@brief	表示されているか否か
		//--------------------------------------------------------
        bool getActive();
        
    private:
        //--------------------------------------------------------
        //  @brief  表示する詳細情報を変更する
        //  @param  index   画像の登録されているインデックス
        //--------------------------------------------------------
        void ChangeSprite(int index);
        
        //--------------------------------------------------------
		//　@brief	タッチされた時の処理
        //  @sum    引数はタッチリスナーに合わせる
		//--------------------------------------------------------
        bool onTouchBegan(Touch* touch, Event* event);
        
    private:
        class Impl;
        
        //  実際にUIとして現在表示するスプライト
        Sprite* m_showSprite;
        //  現在表示する画像のインデックス
        int m_ShowingIndex;
        //  詳細情報の表示に関しての管理クラス
        ShowCharacterStatus* m_charaStates;
        //  キャラクターの顔を出す位置
        Point m_showPosition;
        //  キャラクターの顔の表示サイズ
        const Size m_showSize;
        //  キャラの顔を表示するか？
        bool m_isActive;
        //  隠蔽
        std::unique_ptr<Impl> m_impl;
    };
}

#endif /* defined(__MyGame__CharacterHead__) */
