//
//  Enum.h
//  MyGame
//
//  Created by 星共法 on 2014/10/19.
//
//

#ifndef MyGame_Enum_h
#define MyGame_Enum_h

namespace MyGame{
    namespace LayerDepth{
        enum LD{
            BACKGROUND = 0, //  背景レイヤー
            OBJECT = 1,     //  ゲームオブジェクトレイヤー
            EFFECT = 2,     //  画面効果レイヤー
            UI = 3,         //  インターフェースレイヤー
            MENU = 4,       //  メニューレイヤー
        };
    }
}

#endif
