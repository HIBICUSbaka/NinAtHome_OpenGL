﻿//---------------------------------------------------------------
// File: ASpriteComponent.h
// Proj: NinAtHome
// Info: ACTORオブジェクトにスプライトに関してのコンポーネント
// Date: 2021.06.11
// Mail: cai_genkan@outlook.com
// Comt: NULL
//---------------------------------------------------------------

#pragma once

#include "AComponent.h"

class ASpriteComponent :
    public AComponent
{
public:
    ASpriteComponent(std::string _name, class ActorObject* _owner,
        int _order, int _drawOrder);
    virtual ~ASpriteComponent();

    void SaveTexturePath(std::string _path);

    void DeleteTexture();

    unsigned int GetTexture() const;

    void SetTexWidth(float _width);

    void SetTexHeight(float _height);

    float GetTexWidth() const;

    float GetTexHeight() const;

    void SetOffsetColor(Float4 _color);

    Float4 GetOffsetColor() const;

    void SetVisible(bool _visible);

    bool GetVisible() const;

    int GetDrawOrder() const;

    void ResetDrawOrder(int _order);

    void ResetTexture(unsigned int _texture);

    void ResetFirstTexture();

    void SetUVValue(Float4 _value);

    void DrawASprite();

private:
    void LoadTextureByPath(std::string _path);

public:
    virtual void CompInit();

    virtual void CompUpdate(float _deltatime);

    virtual void CompDestory();

private:
    unsigned int mTexture;

    unsigned int mFirstTexture;

    std::string mTexPath;

    Float4 mOffsetColor;

    Float4 mUVValue;

    float mTexWidth;

    float mTexHeight;

    bool mVisible;

    int mDrawOrder;
};
