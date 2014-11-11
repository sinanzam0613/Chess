//
//  Def.h
//  MyGame
//
//  Created by 星共法 on 2014/10/17.
//
//

#ifndef MyGame_Def_h
#define MyGame_Def_h

#define __DEBUG

//--------------------------------------------------------
//  @brief  __TYPE__をcoco2d::Scene型にaddChildしたシーンを作成する
//  @param  __TYPE__    Sceneに入れたい任意の型名
//————————————————————————————----------------------------
#define CREATE_FUNC_IN_SCENE(__TYPE__) \
static Scene* create() { \
    Scene* t_pRetScene = Scene::create(); \
    __TYPE__* t_pChild = new __TYPE__();  \
    if (t_pChild && t_pChild->init()) {  \
        t_pChild->autorelease();  \
        t_pRetScene->addChild(t_pChild);  \
        return t_pRetScene;  \
    }  \
    else {  \
        CC_SAFE_DELETE(t_pChild); \
        return NULL; \
    }  \
}

//————————————————————————————----------------------------
//  @brief  ログを出力する
//  @sum    ココス定義のログ出力機能を利用して視覚的に改良したもの
//          実行関数の名前を同時に出力してくれるので位置特定がしやすい
//————————————————————————————----------------------------
#define LOG_CUSTOM(arg, ...) \
cocos2d::log( \
    "%s [L:%d]:\n-- %s", \
    __PRETTY_FUNCTION__, \
    __LINE__, \
    cocos2d::StringUtils::format(arg, ##__VA_ARGS__).c_str() \
)

typedef unsigned int uint;

#endif
