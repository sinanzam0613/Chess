//
//  GameManager.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/15.
//
//

#include "GameManager.h"

namespace MyGame{
    GameManager::GameManager()
    : m_pDirector(Director::getInstance())
    , m_scrSize(Director::getInstance()->getVisibleSize())
    , m_scrCenter(Director::getInstance()->getVisibleSize() / 2)
    , m_scrOrigin(Director::getInstance()->getVisibleOrigin()){
        
    }
    
    GameManager::~GameManager(){
        
    }
    
    Point GameManager::getScreenCenter(){
        return m_scrCenter;
    }
    
    Point GameManager::getScreenOrigin(){
        return m_scrOrigin;
    }
    
    Size GameManager::getScreenSize(){
        return m_scrSize;
    }
}