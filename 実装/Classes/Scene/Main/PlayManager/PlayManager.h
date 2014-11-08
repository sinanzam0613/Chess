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
#include "../PieceManager/PieceManager.h"

USING_NS_CC;

namespace MyGame{
    class PlayManager : Node{
    public:
        PlayManager();
        
        bool init();
        
        CREATE_FUNC(PlayManager)
        
    private:
        PieceManager m_pm;
    };
}

#endif /* defined(__Chess__PlayManager__) */
