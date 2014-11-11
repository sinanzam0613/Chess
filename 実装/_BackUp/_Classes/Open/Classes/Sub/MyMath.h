//
//  Math.h
//  MyGame
//
//  Created by 星共法 on 2014/10/18.
//
//

#ifndef MyGame_MyMath_h
#define MyGame_MyMath_h

#include "cocos2d.h"
#include "GameManager.h"

USING_NS_CC;

namespace MyGame{
    namespace Math{
        //--------------------------------------------------------
        //  @brief  スクリーンサイズに対するパラメータの倍率を算出する
        //  @param  size	スクリーンと比較したい数値
        //————————————————————————————----------------------------
        static Size ScreenToMagnification(Size size){
            Size t_retMagni;
            t_retMagni.width = GameManager::getInstance()->getScreenSize().width / size.width;
            t_retMagni.height = GameManager::getInstance()->getScreenSize().height / size.height;
            return t_retMagni;
        }
        
        //--------------------------------------------------------
        //  @brief  targetSizeに対するanySizeの倍率を算出する
        //  @param  targetSize  倍率算出の基準となる数値
        //  @param  anySize     targetSizeと比較したい数値
        //  @sum    ScreenToMagnificationと内容が被っている
        //          こっちに絞っても良いかもしれない
        //————————————————————————————----------------------------
        static Size SizeToMagnification(Size targetSize, Size anySize){
            Size t_retMagni;
            t_retMagni.width = targetSize.width / anySize.width;
            t_retMagni.height = targetSize.height / anySize.height;
            return t_retMagni;
        }
        
        //--------------------------------------------------------
        //  @brief  pointがrectの範囲内か否か
        //  @param  rect    範囲
        //  @param  point   位置
        //--------------------------------------------------------
        static bool IsRectInPoint(Rect rect, Point point){
            return rect.containsPoint(point);
        }
    }
}

#endif







