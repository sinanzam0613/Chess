//
//  PlayerManager.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/23.
//
//

#include "PieceManager.h"

namespace MyGame{
    PieceManager::PieceManager(uint num)
    : m_list(num){
        
    }
    
    Node* PieceManager::getObject(uint index){
        return m_list.get(index);
    }
    
    Node* PieceManager::Insert(uint index, cocos2d::Node* node){
        return m_list.Insert(index, node);
    }
    
    void PieceManager::Remove(uint index) {
        m_list.Remove(index);
    }
}