//
//  MainUI.h
//  MyGame
//
//  Created by 星共法 on 2014/10/21.
//
//

#ifndef __MyGame__MainUI__
#define __MyGame__MainUI__

#include "cocos2d.h"

USING_NS_CC;

namespace MyGame{
    class MainUI : public Node{
    public:
        MainUI();
        
        bool init();
        
        CREATE_FUNC(MainUI);
    };
}

#endif /* defined(__MyGame__MainUI__) */
