//---------------------------------------------------------------
// File: AInteractionComponent.h
// Proj: NinAtHome
// Info: ACTOR���֥������Ȥ��������Ф��v���ƤΥ���ݩ`�ͥ��
// Date: 2021.06.11
// Mail: cai_genkan@outlook.com
// Comt: NULL
//---------------------------------------------------------------

#pragma once

#include "AComponent.h"

// TEMP-----------------
using ActorInterInitFuncType = void(*)();
using ActorInterUpdateFuncType = void(*)();
using ActorInterDestoryFuncType = void(*)();
// TEMP-----------------

class AInteractionComponent :
    public AComponent
{
public:
    AInteractionComponent(std::string _name,
        class ActorObject* _owner, int _order);
    virtual ~AInteractionComponent();

    void SetInitFunc(ActorInterInitFuncType _func);

    void SetUpdateFunc(ActorInterUpdateFuncType _func);

    void SetDestoryFunc(ActorInterDestoryFuncType _func);

    void ClearInitFunc();

    void ClearUpdateFunc();

    void ClearDestoryFunc();

public:
    virtual void CompInit();

    virtual void CompUpdate(float _deltatime);

    virtual void CompDestory();

private:
    ActorInterInitFuncType mInterInitFuncPtr;

    ActorInterUpdateFuncType mInterUpdateFuncPtr;

    ActorInterDestoryFuncType mInterDestoryFuncPtr;
};
