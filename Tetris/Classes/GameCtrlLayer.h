//
//  GameCtrlLayer.h
//  AITetris
//
//  Created by yangjh on 15/4/28.
//
//

#ifndef __AITetris__GameCtrlLayer__
#define __AITetris__GameCtrlLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;
USING_NS_TIMELINE;
using namespace cocos2d::ui;


class GameCtrlLayerDelegate
{
public:
    virtual void gameCtrlLayerClickStartGame() = 0;
    virtual void gameCtrlLayerStartAI(bool AIOn) = 0;
    virtual void gameCtrlLayerClickAccelerate() = 0;
    virtual void gameCtrlLayerClickDecelerate() = 0;
    virtual float gameCtrlLayerGetAISpeed() = 0;
    virtual void gameCtrlLayerClickLeft() = 0;
    virtual void gameCtrlLayerClickRight() = 0;
    virtual void gameCtrlLayerClickRotate() = 0;
    virtual void gameCtrlLayerClickThrowDown() = 0;
};

class GameCtrlLayer : public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(GameCtrlLayer);
    
    void setDelegate(GameCtrlLayerDelegate *delegate) { m_delegate = delegate; }
    
private:
    void clickStartGameButton();
    void clickAISwitchButton();
    void clickLeftButton();
    void clickRightButton();
    void clickUpButton();
    void clickDownButton();
    
private:
    GameCtrlLayerDelegate *m_delegate;
    
    bool m_AIOn;
    Label *m_labelAISwitch;
    Label *m_labelAISpeed;
    Menu *m_menuLeft;
    Menu *m_menuRight;
};

#endif /* defined(__AITetris__GameCtrlLayer__) */
