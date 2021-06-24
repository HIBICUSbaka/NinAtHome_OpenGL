//---------------------------------------------------------------
// File: UTextComponent.cpp
// Proj: NinAtHome
// Info: UI���֥������Ȥ����ֱ�ʾ���v���ƤΥ���ݩ`�ͥ��
// Date: 2021.06.10
// Mail: cai_genkan@outlook.com
// Comt: NULL
//---------------------------------------------------------------

#include "UTextComponent.h"
#include "UiObject.h"
#include "texture.h"
#include "sprite.h"

UTextComponent::UTextComponent(std::string _name,
    UiObject* _owner, int _order) :
    UComponent(_name, _owner, _order), mTextString(""),
    mTextPosition(MakeFloat3(0.f, 0.f, 0.f)),
    mFontSize(MakeFloat2(0.f, 0.f)), mFontTexture(0),
    mTextColor(MakeFloat4(1.f, 1.f, 1.f, 1.f))
{

}

UTextComponent::~UTextComponent()
{

}

void UTextComponent::CompInit()
{

}

void UTextComponent::CompUpdate(float _deltatime)
{

}

void UTextComponent::CompDestory()
{
    if (mFontTexture)
    {
        UnloadTexture(mFontTexture);
    }
}

void UTextComponent::SetTextPosition(Float3 _pos)
{
    mTextPosition = _pos;
}

void UTextComponent::SetFontSize(Float2 _size)
{
    mFontSize = _size;
}

Float2 UTextComponent::GetFontSize() const
{
    return mFontSize;
}

void UTextComponent::LoadFontTexture(std::string _path)
{
    mFontTexture = LoadTexture(_path);
}

void UTextComponent::ChangeTextString(std::string _text)
{
    mTextString = _text;
}

void UTextComponent::SetTextColor(Float4 _color)
{
    mTextColor = _color;
}

void UTextComponent::DrawUText()
{
    // TEMP----------------------------
    MY_NN_LOG(LOG_DEBUG, "draw this string [ %s ] \n",
        mTextString.c_str());
    MY_NN_LOG(LOG_DEBUG, "at position [ %f, %f, %f ] \n",
        mTextPosition.x, mTextPosition.y, mTextPosition.z);
    MY_NN_LOG(LOG_DEBUG, "with size [ %f, %f ] \n",
        mFontSize.x, mFontSize.y);
    MY_NN_LOG(LOG_DEBUG, "and color [ %f, %f, %f, %f ]\n",
        mTextColor.x, mTextColor.y,
        mTextColor.z, mTextColor.w);
    // TEMP----------------------------
}
