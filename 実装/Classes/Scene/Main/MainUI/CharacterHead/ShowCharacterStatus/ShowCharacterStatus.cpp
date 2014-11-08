//
//  ShowCharacterStatus.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/22.
//
//

#include "ShowCharacterStatus.h"
#include "MyMath.h"
#include "Def.h"
#include <vector>

namespace MyGame{
    class ShowCharacterStatus::Impl{
    public:
        Impl(int spriteNum){
            m_spriteNameList.resize(spriteNum);
            m_spriteNameList[0] = "dbTex_SummonsMonster_0.jpg";
            m_spriteNameList[1] = "dbTex_SummonsMonster_1.jpg";
            m_spriteNameList[2] = "dbTex_SummonsMonster_2.jpg";
        }
        ~Impl(){
            
        }
        
        std::vector<std::string> m_spriteNameList;
    };
    
    ShowCharacterStatus::ShowCharacterStatus(unsigned int textureBufferNum)
    : m_impl(new Impl(textureBufferNum))
    , m_showIndex(0)
    , m_isActive(false)
    , m_showSize(426, 610){
        //  本来なら画面サイズや表示領域から計算式で算出するべきだが、
        //  今のところメニューバーの配置などが仮決めなので直接代入
        m_showPosition = Point(m_showSize.width / 2, m_showSize.height / 2);
    }
    
    ShowCharacterStatus::~ShowCharacterStatus(){
        delete m_impl;
        m_impl = 0;
    }
    
#include <memory>
    
    bool ShowCharacterStatus::init(){
        if(!Node::init()){
            return false;
        }
        
        std::shared_ptr<Sprite> t_ptr;
        
        //  表示するためのスプライトを作成
        m_showSprite = Sprite::create("EscapeTexture.png");
        Size t_scale = Math::SizeToMagnification(m_showSize, m_showSprite->getContentSize());
        
        m_showSprite->setPosition(m_showPosition);
        m_showSprite->setScale(t_scale.width, t_scale.height);
        
        this->addChild(m_showSprite);
        
        this->setActive(false);
        
        //  タッチイベントの登録
        auto t_listener = EventListenerTouchOneByOne::create();
        auto t_dispatcher = Director::getInstance()->getEventDispatcher();
        
        t_listener->onTouchBegan = CC_CALLBACK_2(ShowCharacterStatus::onTouchBegan, this);
        t_dispatcher->addEventListenerWithSceneGraphPriority(t_listener, m_showSprite);
        
        return true;
    }
    
    ShowCharacterStatus* ShowCharacterStatus::create(unsigned int textureBufferNum){
        ShowCharacterStatus *pRet = new ShowCharacterStatus(textureBufferNum);
        if (pRet && pRet->init()){
            pRet->autorelease();
            return pRet;
        }
        delete pRet;
        pRet = NULL;
        return NULL;
    }
    
    void ShowCharacterStatus::setActive(bool active){
        m_showSprite->setVisible(active);
        m_isActive = active;
    }
    
    bool ShowCharacterStatus::getIsActive(){
        return m_isActive;
    }
    
    void ShowCharacterStatus::ChangeSprite(int index){
        Texture2D* t_texture = Director::getInstance()->getTextureCache()->addImage(m_impl->m_spriteNameList[index]);
        m_showSprite->setTexture(t_texture);
    }
    
    bool ShowCharacterStatus::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
        Sprite* t_target = static_cast<Sprite*>(event->getCurrentTarget());
        Point t_touchLocation = t_target->convertToNodeSpace(touch->getLocation());
        Size t_size = t_target->getContentSize();
        Rect t_rect = Rect(0, 0, t_size.width, t_size.height);
        
        //  自身が活動中かつ範囲内をタッチされていたら
        if(m_isActive && t_rect.containsPoint(t_touchLocation)){
            LOG_CUSTOM("States Touch : %f", t_touchLocation.x);
        }
        
        return true;
    }
}















