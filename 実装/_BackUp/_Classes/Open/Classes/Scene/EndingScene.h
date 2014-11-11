//
//  EndingScene.h
//  MyGame
//
//  Created by 星共法 on 2014/10/17.
//
//

#ifndef __MyGame__EndingScene__
#define __MyGame__EndingScene__

#include "cocos2d.h"
#include "Def.h"

USING_NS_CC;

namespace MyGame{
    class EndingScene : Layer{
    public:
        EndingScene();
        
        bool init();
        
        CREATE_FUNC_IN_SCENE(EndingScene);
    };
}
#endif /* defined(__MyGame__EndingScene__) */
