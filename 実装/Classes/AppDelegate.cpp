#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include "Scene/Title/TitleScene.h"
#include "CreateScene.h"

USING_NS_CC;
using namespace MyGame;

AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate() {
    
}

bool AppDelegate::applicationDidFinishLaunching() {
    //  ディレクターの作成
    //  ディレクター自体はシングルトンで実装されているが、
    //  GLなどの初期化が必要なので、ここで初期化を行う
    Director* director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("ORIGIN_GAME");
        director->setOpenGLView(glview);
    }

    //  デバッグデータを画面上に表示するように設定
    director->setDisplayStats(true);

    //  FPS値を60に設定する
    director->setAnimationInterval(1.0 / 60);

    //  シーンを作成し、directorに渡す
    Scene* t_scene = Assistant::CreateScene::CreateSceneIn<TitleScene>();

    // run
    director->runWithScene(t_scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    //  描画を停止
    Director::getInstance()->stopAnimation();
    
    LOG_CUSTOM("This_Game_Hide_In_BackGounrd");
    
    //  音楽を管理しているエンジンを一時停止させる
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    //  描画の再開
    Director::getInstance()->startAnimation();

    LOG_CUSTOM("This_Game_ReStarting");
    
    // 音楽を管理しているエンジンを再起動させる
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
