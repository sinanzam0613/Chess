//
//  PlayManager.cpp
//  Chess
//
//  Created by 星共法 on 2014/11/08.
//
//

#include "PlayManager.h"
#include "GameManager.h"

const int PIECE_NUM = 3;

namespace MyGame{
    PlayManager::PlayManager()
    : m_pm(PIECE_NUM){
        
    }
    
    bool PlayManager::init(){
        if(!Node::init()){
            return false;
        }
        
        //this->addChild(m_pieceManager.getObject(0), TAG_PIECE);
        
        return true;
    }
}