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

#ifndef GS2_FORMATION_MODEL_SLOT_HPP_
#define GS2_FORMATION_MODEL_SLOT_HPP_

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
 * スロット
 *
 * @author Game Server Services, Inc.
 *
 */
class Slot : public Gs2Object
{
    friend bool operator!=(const Slot& lhs, const Slot& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スロットモデル名 */
        optional<StringHolder> name;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** メタデータ */
        optional<StringHolder> metadata;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            propertyId(data.propertyId),
            metadata(data.metadata)
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
            else if (std::strcmp(name_, "propertyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->propertyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Slot() = default;
    Slot(const Slot& slot) = default;
    Slot(Slot&& slot) = default;
    ~Slot() = default;

    Slot& operator=(const Slot& slot) = default;
    Slot& operator=(Slot&& slot) = default;

    Slot deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Slot);
    }

    const Slot* operator->() const
    {
        return this;
    }

    Slot* operator->()
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
    Slot& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    Slot& withPropertyId(StringHolder propertyId)
    {
        setPropertyId(std::move(propertyId));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    Slot& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Slot& lhs, const Slot& lhr)
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
        if (lhs.m_pData->propertyId != lhr.m_pData->propertyId)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Slot& lhs, const Slot& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FORMATION_MODEL_SLOT_HPP_