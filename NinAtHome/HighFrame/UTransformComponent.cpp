﻿//---------------------------------------------------------------
// File: UTransformComponent.cpp
// Proj: NinAtHome
// Info: UIオブジェクトに動く位置に関してのコンポーネント
// Date: 2021.06.10
// Mail: cai_genkan@outlook.com
// Comt: NULL
//---------------------------------------------------------------

#include "UTransformComponent.h"
#include "UiObject.h"
#ifndef NIN_AT_HOME
#include <TP\glm\glm.hpp>
#include <TP\glm\gtc\type_ptr.hpp>
#endif // !NIN_AT_HOME

UTransformComponent::UTransformComponent(std::string _name,
    UiObject* _owner, int _order, Float3 _initValue) :
    UComponent(_name, _owner, _order),
    mPosition(_initValue), mRotation(_initValue),
    mScale(MakeFloat3(1.f, 1.f, 1.f)), mWorldMatrix(Matrix4x4f())
{

}

UTransformComponent::~UTransformComponent()
{

}

void UTransformComponent::CompInit()
{

}

void UTransformComponent::CompUpdate(float _deltatime)
{
    UpdateWorldMatrix();
}

void UTransformComponent::CompDestory()
{

}

void UTransformComponent::SetPosition(Float3 _pos)
{
    mPosition = _pos;
}

Float3 UTransformComponent::GetPosition() const
{
    return mPosition;
}

void UTransformComponent::SetRotation(Float3 _angle)
{
    mRotation = _angle;
}

Float3 UTransformComponent::GetRotation() const
{
    return mRotation;
}

void UTransformComponent::SetScale(Float3 _factor)
{
    mScale = _factor;
}

Float3 UTransformComponent::GetScale() const
{
    return mScale;
}

Matrix4x4f UTransformComponent::GetWorldMatrix() const
{
    return mWorldMatrix;
}

void UTransformComponent::Translate(Float3 _pos)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->Translate(_pos);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->Translate(_pos);
            }
        }
    }

    mPosition.x += _pos.x;
    mPosition.y += _pos.y;
    mPosition.z += _pos.z;
}

void UTransformComponent::TranslateXAsix(float _posx)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->TranslateXAsix(_posx);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->TranslateXAsix(_posx);
            }
        }
    }

    mPosition.x += _posx;
}

void UTransformComponent::TranslateYAsix(float _posy)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->TranslateYAsix(_posy);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->TranslateYAsix(_posy);
            }
        }
    }

    mPosition.y += _posy;
}

void UTransformComponent::TranslateZAsix(float _posz)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->TranslateZAsix(_posz);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->TranslateZAsix(_posz);
            }
        }
    }

    mPosition.z += _posz;
}

void UTransformComponent::Rotate(Float3 _angle)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->Rotate(_angle);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->Rotate(_angle);
            }
        }
    }

    mRotation.x += _angle.x;
    mRotation.y += _angle.y;
    mRotation.z += _angle.z;
}

void UTransformComponent::RotateXAsix(float _anglex)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->RotateXAsix(_anglex);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->RotateXAsix(_anglex);
            }
        }
    }

    mRotation.x += _anglex;
}

void UTransformComponent::RotateYAsix(float _angley)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->RotateYAsix(_angley);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->RotateYAsix(_angley);
            }
        }
    }

    mRotation.y += _angley;
}

void UTransformComponent::RotateZAsix(float _anglez)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->RotateZAsix(_anglez);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->RotateZAsix(_anglez);
            }
        }
    }

    mRotation.z += _anglez;
}

void UTransformComponent::Scale(Float3 _factor)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->Scale(_factor);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->Scale(_factor);
            }
        }
    }

    mScale.x *= _factor.x;
    mScale.y *= _factor.y;
    mScale.z *= _factor.z;
}

void UTransformComponent::Scale(float _factor)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->Scale(_factor);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->Scale(_factor);
            }
        }
    }

    mScale.x *= _factor;
    mScale.y *= _factor;
    mScale.z *= _factor;
}

void UTransformComponent::ScaleXAsix(float _factorx)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->ScaleXAsix(_factorx);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->ScaleXAsix(_factorx);
            }
        }
    }

    mScale.x *= _factorx;
}

void UTransformComponent::ScaleYAsix(float _factory)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->ScaleYAsix(_factory);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->ScaleYAsix(_factory);
            }
        }
    }

    mScale.y *= _factory;
}

void UTransformComponent::ScaleZAsix(float _factorz)
{
    if (GetUiObjOwner()->GetChildrenArray()->size())
    {
        for (auto& child :
            *(GetUiObjOwner()->GetChildrenArray()))
        {
            std::string childName = child->GetObjectName();
            if (child->GetSpriteArray()->size() > 1)
            {
                for (int i = 0;
                    i < child->GetSpriteArray()->size(); i++)
                {
                    childName = childName + "-transform-" +
                        std::to_string(i + 1);
                    auto comp = child->GetUComponent(childName);
                    if (!comp)
                    {
                        return;
                    }
                    UTransformComponent* utc =
                        (UTransformComponent*)comp;
                    utc->ScaleZAsix(_factorz);
                }
            }
            else
            {
                childName = childName + "-transform";
                auto comp = child->GetUComponent(childName);
                if (!comp)
                {
                    return;
                }
                UTransformComponent* utc =
                    (UTransformComponent*)comp;
                utc->ScaleZAsix(_factorz);
            }
        }
    }

    mScale.z *= _factorz;
}

void UTransformComponent::UpdateWorldMatrix()
{
    mWorldMatrix =
    {
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    };

#ifdef NIN_AT_HOME
    mWorldMatrix = glm::translate(mWorldMatrix, mPosition);
    mWorldMatrix = glm::rotate(mWorldMatrix,
        glm::radians(mRotation.x), Float3(1.f, 0.f, 0.f));
    mWorldMatrix = glm::rotate(mWorldMatrix,
        glm::radians(mRotation.y), Float3(0.f, 1.f, 0.f));
    mWorldMatrix = glm::rotate(mWorldMatrix,
        glm::radians(mRotation.z), Float3(0.f, 0.f, 1.f));
    mWorldMatrix = glm::scale(mWorldMatrix, mScale);
#else
    glm::fmat4x4 world =
    {
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
    world = glm::translate(world, mPosition);
    world = glm::rotate(world,
        glm::radians(mRotation.x), Float3(1.f, 0.f, 0.f));
    world = glm::rotate(world,
        glm::radians(mRotation.y), Float3(0.f, 1.f, 0.f));
    world = glm::rotate(world,
        glm::radians(mRotation.z), Float3(0.f, 0.f, 1.f));
    world = glm::scale(world, mScale);
    float* matArray = glm::value_ptr(world);
    mWorldMatrix =
    {
        matArray[0],matArray[1],matArray[2],matArray[3],
        matArray[4],matArray[5],matArray[6],matArray[7],
        matArray[8],matArray[9],matArray[10],matArray[11],
        matArray[12],matArray[13],matArray[14],matArray[15]
    };
#endif // NIN_AT_HOME
}
