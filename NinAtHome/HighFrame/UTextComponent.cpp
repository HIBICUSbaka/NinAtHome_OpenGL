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
    mTextColor(MakeFloat4(1.f, 1.f, 1.f, 1.f)), mTextPtr(nullptr),
    mKanaUV({})
{
    mKanaUV.clear();
}

UTextComponent::~UTextComponent()
{

}

void UTextComponent::CompInit()
{
    // TODO add here
    mKanaUV.insert(std::make_pair(
        "��", MakeFloat3(0.0f * MOJI_U, 5.0 * MOJI_V, 1.0f)));
    mKanaUV.insert(std::make_pair(
        "��", MakeFloat3(1.0f * MOJI_U, 5.0 * MOJI_V, 1.0f)));
    mKanaUV.insert(std::make_pair(
        "��", MakeFloat3(2.0f * MOJI_U, 5.0 * MOJI_V, 1.0f)));
    mKanaUV.insert(std::make_pair(
        "��", MakeFloat3(3.0f * MOJI_U, 5.0 * MOJI_V, 1.0f)));
    mKanaUV.insert(std::make_pair(
        "��", MakeFloat3(4.0f * MOJI_U, 5.0 * MOJI_V, 1.0f)));
}

void UTextComponent::CompUpdate(float _deltatime)
{
    mTextPtr = mTextString.c_str();
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
    SetTexture(mFontTexture);
    Float3 nowPosition = mTextPosition;

    for (auto i = mTextString.length() - mTextString.length();
        i < mTextString.length() + 1; i++)
    {
        if (mTextPtr[i] == '\0')
        {
            break;
        }
        else if (mTextPtr[i] == '\n')
        {
            nowPosition.x = mTextPosition.x;
            nowPosition.y += mFontSize.y;
            continue;
        }
        // TODO check kana here
        /*else if (false)
        {

        }*/
        else if (mTextPtr[i] >= 32 && mTextPtr[i] <= 126)
        {
            unsigned int index = mTextPtr[i] - 32;
            Float2 uv = MakeFloat2(
                (float)(index % MOJI_TEX_H_NUM) * MOJI_U,
                (float)(index / MOJI_TEX_H_NUM) * MOJI_V);

#ifdef NIN_AT_HOME
            {
                float zeroMove[16] =
                {
                    1.f,0.f,0.f,0.f,
                    0.f,1.f,0.f,0.f,
                    0.f,0.f,1.f,0.f,
                    0.f,0.f,0.f,1.f
                };
                glUniformMatrix4fv(
                    glGetUniformLocation(
                        GetGlHelperPtr()->GetShaderID("default"),
                        "uWorld"), 1, GL_TRUE, zeroMove);
            }
#else

#endif // NIN_AT_HOME

            DrawSprite(nowPosition.x, nowPosition.y,
                mFontSize.x, mFontSize.y, uv.x, uv.y,
                MOJI_U, MOJI_V, mTextColor);

            nowPosition.x += mFontSize.x;
        }
    }
}
