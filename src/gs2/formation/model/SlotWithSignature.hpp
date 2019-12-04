/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_FORMATION_MODEL_SLOTWITHSIGNATURE_HPP_
#define GS2_FORMATION_MODEL_SLOTWITHSIGNATURE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace formation {

/**
 * 署名付きスロット
 *
 * @author Game Server Services, Inc.
 *
 */
class SlotWithSignature : public Gs2Object
{
    friend bool operator!=(const SlotWithSignature& lhs, const SlotWithSignature& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スロットモデル名 */
        optional<StringHolder> name;
        /** プロパティの種類 */
        optional<StringHolder> propertyType;
        /** ペイロード */
        optional<StringHolder> body;
        /** プロパティIDのリソースを所有していることを証明する署名 */
        optional<StringHolder> signature;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            propertyType(data.propertyType),
            body(data.body),
            signature(data.signature)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "propertyType") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->propertyType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "body") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SlotWithSignature() = default;
    SlotWithSignature(const SlotWithSignature& slotWithSignature) = default;
    SlotWithSignature(SlotWithSignature&& slotWithSignature) = default;
    ~SlotWithSignature() = default;

    SlotWithSignature& operator=(const SlotWithSignature& slotWithSignature) = default;
    SlotWithSignature& operator=(SlotWithSignature&& slotWithSignature) = default;

    SlotWithSignature deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SlotWithSignature);
    }

    const SlotWithSignature* operator->() const
    {
        return this;
    }

    SlotWithSignature* operator->()
    {
        return this;
    }
    /**
     * スロットモデル名を取得
     *
     * @return スロットモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スロットモデル名を設定
     *
     * @param name スロットモデル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スロットモデル名を設定
     *
     * @param name スロットモデル名
     */
    SlotWithSignature& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * プロパティの種類を取得
     *
     * @return プロパティの種類
     */
    const optional<StringHolder>& getPropertyType() const
    {
        return ensureData().propertyType;
    }

    /**
     * プロパティの種類を設定
     *
     * @param propertyType プロパティの種類
     */
    void setPropertyType(StringHolder propertyType)
    {
        ensureData().propertyType.emplace(std::move(propertyType));
    }

    /**
     * プロパティの種類を設定
     *
     * @param propertyType プロパティの種類
     */
    SlotWithSignature& withPropertyType(StringHolder propertyType)
    {
        setPropertyType(std::move(propertyType));
        return *this;
    }

    /**
     * ペイロードを取得
     *
     * @return ペイロード
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * ペイロードを設定
     *
     * @param body ペイロード
     */
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
    }

    /**
     * ペイロードを設定
     *
     * @param body ペイロード
     */
    SlotWithSignature& withBody(StringHolder body)
    {
        setBody(std::move(body));
        return *this;
    }

    /**
     * プロパティIDのリソースを所有していることを証明する署名を取得
     *
     * @return プロパティIDのリソースを所有していることを証明する署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * プロパティIDのリソースを所有していることを証明する署名を設定
     *
     * @param signature プロパティIDのリソースを所有していることを証明する署名
     */
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }

    /**
     * プロパティIDのリソースを所有していることを証明する署名を設定
     *
     * @param signature プロパティIDのリソースを所有していることを証明する署名
     */
    SlotWithSignature& withSignature(StringHolder signature)
    {
        setSignature(std::move(signature));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SlotWithSignature& lhs, const SlotWithSignature& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->propertyType != lhr.m_pData->propertyType)
        {
            return true;
        }
        if (lhs.m_pData->body != lhr.m_pData->body)
        {
            return true;
        }
        if (lhs.m_pData->signature != lhr.m_pData->signature)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const SlotWithSignature& lhs, const SlotWithSignature& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FORMATION_MODEL_SLOTWITHSIGNATURE_HPP_