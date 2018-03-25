//
//  CharselectScene.cpp
//  PuzzleRPG
//
//  Created by neko on 2018/03/25.
//

#include "CharselectScene.h"
#include "QuestScene.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "GameDataSQL.h"
#include "AudioManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* CharselectScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CharselectScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CharselectScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("charselect/CharselectScene.csb");
    if(rootNode == nullptr){
        return false;
    }
    addChild(rootNode);
    
    m_popup_1 = rootNode->getChildByName<Node*>( "popup_1" );
    auto char1_btn = m_popup_1->getChildByName<ui::Button*>( "char1_btn" );
    char1_btn->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
            onChar( SelectCharNo01 );
        }
    });
    auto char2_btn = m_popup_1->getChildByName<ui::Button*>( "char2_btn" );
    char2_btn->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
            onChar( SelectCharNo02 );
        }
    });
    auto char3_btn = m_popup_1->getChildByName<ui::Button*>( "char3_btn" );
    char3_btn->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
            onChar( SelectCharNo03 );
        }
    });
    
    m_popup_2 = rootNode->getChildByName<Node*>( "popup_2" );
    m_popup_2->setVisible(false);
    m_popup_3 = rootNode->getChildByName<Node*>( "popup_3" );
    m_popup_3->setVisible(false);
    
    this->scheduleUpdate();
    return true;
}

void CharselectScene::onChar( SelectCharNo no )
{
    AudioManager::getInstance()->playSe("ui_title_start");
    m_popup_1->setVisible(false);
    
    auto yes_btn = m_popup_2->getChildByName<ui::Button*>( "yes_btn" );
    yes_btn->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
            onYes();
        }
    });
    
    auto back_btn = m_popup_2->getChildByName<ui::Button*>( "back_btn" );
    back_btn->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
            onBack();
        }
    });
    /*
    auto AttributeNode = m_popup_2->getChildByName<Node*>( "AttributeNode" );
    
    auto NameText = m_popup_2->getChildByName<ui::Text*>( "NameText" );
    NameText->setString( CharData.char[_id].name );
    
    auto LevelText = m_popup_2->getChildByName<ui::Text*>( "LevelText" );
    
    auto AtkText = m_popup_2->getChildByName<ui::Text*>( "AtkText" );
    AtkText->setString( CharData.char[_id].atk );
    
    auto SkillText = m_popup_2->getChildByName<ui::Text*>( "SkillText" );
    SkillText->setString( CharData.char[_id].skillText );
    
    auto chara_princessselect = m_popup_2->getChildByName<Node*>( "chara_princessselect" );
    chara_princessselect->removeAllChildren();
    
    var charSprite = new charSelectSprite( _id+1 );
    chara_princessselect.addChild( charSprite, 1 );
    */
    m_popup_2->setVisible(true);
}

void CharselectScene::onYes()
{
    m_popup_2->setVisible(false);
    auto start_btn = m_popup_3->getChildByName<ui::Button*>( "start_btn" );
    start_btn->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
            // 何度も押されないように一度押されたらアクションを無効にする
            this->getEventDispatcher()->removeAllEventListeners();
            
            // 0.5秒待ってからCallFuncを呼ぶ
            auto delay = DelayTime::create(0.2f);
            
            // ゲームを始めるアクション
            auto startGame = CallFunc::create([]{
                // スタートボタン音SE再生
                AudioManager::getInstance()->playSe("ui_title_start");
                // 初回起動時にローカルDBデータを作成する
                GameDataSQL::sqliteCreateTable();
                // クエスト選択画面へ移行
                auto transition = TransitionFade::create(0.5f, QuestScene::createScene(), Color3B::WHITE);
                Director::getInstance()->replaceScene(transition);
            });
            this->runAction(Sequence::create(delay, startGame, NULL));
        }
    });
    
    /*
    auto NameText = m_popup_3->getChildByName<ui::Text*>( "NameText" );
    NameText.setString( CharData.char[this.selectId].name );
    auto chara_princessselect = m_popup_3->getChildByName<ui::Button*>( "chara_princessselect" );
    
     var charSprite = new charSelectSprite( this.selectId+1 );
     chara_princessselect.addChild( charSprite );
     */
    m_popup_3->setVisible(true);
}

void CharselectScene::onBack()
{
    m_popup_1->setVisible(true);
    m_popup_2->setVisible(false);
    m_popup_3->setVisible(false);
}

void CharselectScene::onStart()
{
    
}
