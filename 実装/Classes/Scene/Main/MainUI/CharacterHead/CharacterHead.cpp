//
//  CharacterHead.cpp
//  MyGame
//
//  Created by 星共法 on 2014/10/21.
//
//

#include "CharacterHead.h"
#include "Def.h"
#include "MyMath.h"
#include "AddObject.h"
#include "GameManager.h"

#include <vector>

namespace MyGame{
    class CharacterHead::Impl{
    public:
        //********************************************************
		//　@brief	ノーマルなコンストラクタ
        //********************************************************
        Impl()
        : m_spriteNum(3){
            //  配列の作成
            m_spriteNameList.resize(m_spriteNum);
            m_spriteNameList[0] = "dbTex_Character_0.jpg";
            m_spriteNameList[1] = "dbTex_Character_1.jpg";
            m_spriteNameList[2] = "dbTex_Character_2.jpg";
        }
        
        //********************************************************
		//　@brief	ノーマルなデストラクタ
        //********************************************************
        ~Impl(){
            m_spriteNameList.clear();
            LOG_CUSTOM("deleted Impl class");
        }
        
        //  表示するスプライトの名前を保持する配列
        std::vector<std::string> m_spriteNameList;
        //  スプライトの枚数
        const int m_spriteNum;
    };
    
    
    CharacterHead::CharacterHead()
    : m_showSprite(nullptr)
    , m_impl(new Impl())
    , m_showSize(142, 142)
    , m_isActive(false)
    , m_ShowingIndex(0){
        GameManager* t_gm = GameManager::getInstance();
        
        //  キャラの顔をどこに表示するかの座標を算出する  ============
        Size t_scrSize = t_gm->getScreenSize();
        Point t_pos;
        float t_temp = 0.0f;
        //  x座標の算出
        t_temp = t_scrSize.width / 4;
        t_pos.x = t_temp * 3 + (t_temp / 2);
        //  y座標の算出
        t_temp = t_scrSize.height / 4;
        t_pos.y = t_temp * 3 + (t_temp / 2);
        
        m_showPosition = t_pos;
    }
    
    bool CharacterHead::init(){
        if(!Node::init()){
            return  false;
        }
        
        int t_summonsMonsterNum = 3;
        
        //  最初はデフォルトの画像で作成 でないとスプライトのリサイズがめんどい
        m_showSprite = Sprite::create("EscapeTexture.png");
        this->addChild(m_showSprite);
        m_showSprite->setPosition(m_showPosition);
        
        //  キャラの詳細に関するクラス
        m_charaStates = ShowCharacterStatus::create(t_summonsMonsterNum);
        
        //  表示するスプライトを規定のサイズにリサイズ
        Size t_scale = Math::SizeToMagnification(Size(144, 144), m_showSprite->getContentSize());
        m_showSprite->setScale(t_scale.width, t_scale.height);
        this->addChild(m_charaStates);
        
        
        auto t_touchListener = EventListenerTouchOneByOne::create();
        auto t_dispatcher = Director::getInstance()->getEventDispatcher();
        //  タッチされた時画像変える（デバッグ用）
        t_touchListener->onTouchBegan = CC_CALLBACK_2(CharacterHead::onTouchBegan, this);
        //  リスナーの登録
        t_dispatcher->addEventListenerWithSceneGraphPriority(t_touchListener, m_showSprite);
        
        //  一応、自身を表示状態で初期化
        this->setActive(true);
        
        return true;
    }
    
    void CharacterHead::setActive(bool active){
        m_isActive = active;
        this->setVisible(active);
        //  自身が停止する時に子が働いてたら同時に停止させる
        if(!active && m_charaStates->getIsActive()){
            m_charaStates->setVisible(false);
        }
    }
    
    bool CharacterHead::getActive(){
        return m_isActive;
    }
    
    void CharacterHead::ChangeSprite(int index){
        m_charaStates->ChangeSprite(index);
    }
    
    bool CharacterHead::onTouchBegan(Touch* touch, Event* event){
        Sprite* t_target = static_cast<Sprite*>(event->getCurrentTarget());
        Point t_touchLocation = t_target->convertToNodeSpace(touch->getLocation());
        Size t_size = t_target->getContentSize();
        Rect t_rect = Rect(0, 0, t_size.width, t_size.height);
        
        //  自身が活動中かつ範囲内をタッチされていたら
        if(m_isActive && t_rect.containsPoint(t_touchLocation)){
            //  子が活動中であれば停止させる
            if(m_charaStates->getIsActive()){
                m_charaStates->setActive(false);
            }
            else{
                this->ChangeSprite(1);
                m_charaStates->setActive(true);
            }
        }
        return true;
    }
}