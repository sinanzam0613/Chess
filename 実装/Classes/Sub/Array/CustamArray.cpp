//
//  CustamArray.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/24.
//
//

#include "CustamArray.h"

USING_NS_CC;

namespace MyGame{
    CustamArray::CustamArray(){
        m_list.clear();
    }
    
    CustamArray::CustamArray(uint size){
        m_list.resize(size);
    }
    
    CustamArray::~CustamArray(){
        for(auto it = m_list.begin(); it != m_list.end(); ++it){
            (*it)->release();
        }
        m_list.clear();
    }

    Node* CustamArray::PushBack(Node* node) {
        m_list.push_back(node);
        node->retain();
        return node;
    }
    
    Node* CustamArray::Remove(uint index){
        auto t_it = m_list.begin() + index;
        m_list.erase(t_it);
        (*t_it)->release();
        return (*t_it);
    }
    
    Node* CustamArray::Insert(uint index, Node* node){
        if(m_list.at(index)){
            this->Remove(index);
        }
        auto t_it = m_list.begin() + index;
        m_list.insert(t_it, node);
        return node;
    }
    
    Node* CustamArray::get(uint index) {
        return m_list.at(index);
    }
}












