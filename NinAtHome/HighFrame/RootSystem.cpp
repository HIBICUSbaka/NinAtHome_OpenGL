﻿//---------------------------------------------------------------
// File: RootSystem.cpp
// Proj: NinAtHome
// Info: システムを全体的に管理する
// Date: 2021.06.09
// Mail: cai_genkan@outlook.com
// Comt: NULL
//---------------------------------------------------------------

#include "RootSystem.h"
#include "SceneManager.h"
#include "PropertyManager.h"
#include "ObjectFactory.h"
#include "main.h"
#include "controller.h"
#include "sound.h"

RootSystem::RootSystem() :
    mSceneManagerPtr(nullptr), mPropertyManagerPtr(nullptr),
    mObjectFactoryPtr(nullptr), mLastTime(0.f), mDeltaTime(0.16f)
{

}

RootSystem::~RootSystem()
{

}

bool RootSystem::StartUp()
{
    MY_NN_LOG(LOG_MESSAGE,
        "[START UP] : starting up ROOT SYSTEM\n");

    mSceneManagerPtr = new SceneManager();
    mPropertyManagerPtr = new PropertyManager();
    mObjectFactoryPtr = new ObjectFactory();

    bool result1 = InitSystem();
    bool result2 = InitSound();
    bool result3 = mSceneManagerPtr->StartUp();
    bool result4 = mPropertyManagerPtr->StartUp();
    bool result5 = mObjectFactoryPtr->StartUp(
        mPropertyManagerPtr, mSceneManagerPtr);
    mSceneManagerPtr->PostStartUp(
        mPropertyManagerPtr, mObjectFactoryPtr);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glFrontFace(GL_CCW);

    InitController();

    bool result = result1 && result2 && 
        result3 && result4 && result5;

    if (result)
    {
        MY_NN_LOG(LOG_MESSAGE,
            "[START UP] : start up ROOT SYSTEM successed\n");
    }
    else
    {
        MY_NN_LOG(LOG_ERROR,
            "[START UP] : start up ROOT SYSTEM failed\n");
    }

    return result;
}

void RootSystem::ClearAndStop()
{
    if (mSceneManagerPtr)
    {
        mSceneManagerPtr->CleanAndStop();
        delete mSceneManagerPtr;
        mSceneManagerPtr = nullptr;
    }
    if (mPropertyManagerPtr)
    {
        mPropertyManagerPtr->CleanAndStop();
        delete mPropertyManagerPtr;
        mPropertyManagerPtr = nullptr;
    }
    if (mObjectFactoryPtr)
    {
        mObjectFactoryPtr->CleanAndStop();
        delete mObjectFactoryPtr;
        mObjectFactoryPtr = nullptr;
    }

    UninitController();

    UninitSound();

    UninitSystem();

    MY_NN_LOG(LOG_MESSAGE,
        "[CLEAN STOP] : stop ROOT SYSTEM successed\n");
}

void RootSystem::RunGameLoop()
{
    while (true)
    {
        glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        UpdateController();

        mSceneManagerPtr->UpdateSceneManager(mDeltaTime);

        SwapAndClacDeltaTime();

        if (ShouldQuit())
        {
            break;
        }
    }
}

void RootSystem::SwapAndClacDeltaTime()
{
    float time = 0.f;
#ifdef NIN_AT_HOME
    time = SwapBuffers();
#else
    SwapBuffers();
    nn::os::Tick t = nn::os::GetSystemTick();
    time = (float)(t.ToTimeSpan().GetMilliSeconds()) / 1000.f;
#endif // NIN_AT_HOME
    mDeltaTime = time - mLastTime;
    mLastTime = time;
    time = MAX_DELTA - mDeltaTime;
    //NN_LOG("current delta : %f , delta with max %f\n",
        //mDeltaTime, time);
    if (time > 0.001f)
    {
        mLastTime += time;
#ifdef NIN_AT_HOME
        Sleep((int)(1000.f * time));
#else

#endif // NIN_AT_HOME
        mDeltaTime = MAX_DELTA;
    }
    else if (time < 0.f)
    {
        mDeltaTime = MAX_DELTA;
    }
    //NN_LOG("final delta : %f\n", mDeltaTime);
}
