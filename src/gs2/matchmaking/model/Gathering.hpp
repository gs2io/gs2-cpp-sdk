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

#ifndef GS2_MATCHMAKING_MODEL_GATHERING_HPP_
#define GS2_MATCHMAKING_MODEL_GATHERING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AttributeRange.hpp"
#include "CapacityOfRole.hpp"
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * ギャザリング
 *
 * @author Game Server Services, Inc.
 *
 */
class Gathering : public Gs2Object
{
    friend bool operator!=(const Gathering& lhs, const Gathering& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ギャザリング */
        optional<StringHolder> gatheringId;
        /** ギャザリング名 */
        optional<StringHolder> name;
        /** 募集条件 */
        optional<List<AttributeRange>> attributeRanges;
        /** 参加者 */
        optional<List<CapacityOfRole>> capacityOfRoles;
        /** 参加を許可するユーザIDリスト */
        optional<List<StringHolder>> allowUserIds;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gatheringId(data.gatheringId),
            name(data.name),
            attributeRanges(data.attributeRanges),
            capacityOfRoles(data.capacityOfRoles),
            allowUserIds(data.allowUserIds),
            metadata(data.metadata),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gatheringId(std::move(data.gatheringId)),
            name(std::move(data.name)),
            attributeRanges(std::move(data.attributeRanges)),
            capacityOfRoles(std::move(data.capacityOfRoles)),
            allowUserIds(std::move(data.allowUserIds)),
            metadata(std::move(data.metadata)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gatheringId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "attributeRanges") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->attributeRanges.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AttributeRange item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->attributeRanges, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "capacityOfRoles") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->capacityOfRoles.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        CapacityOfRole item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->capacityOfRoles, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "allowUserIds") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->allowUserIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->allowUserIds, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    Gathering() :
        m_pData(nullptr)
    {}

    Gathering(const Gathering& gathering) :
        Gs2Object(gathering),
        m_pData(gathering.m_pData != nullptr ? new Data(*gathering.m_pData) : nullptr)
    {}

    Gathering(Gathering&& gathering) :
        Gs2Object(std::move(gathering)),
        m_pData(gathering.m_pData)
    {
        gathering.m_pData = nullptr;
    }

    ~Gathering()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Gathering& operator=(const Gathering& gathering)
    {
        Gs2Object::operator=(gathering);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gathering.m_pData);

        return *this;
    }

    Gathering& operator=(Gathering&& gathering)
    {
        Gs2Object::operator=(std::move(gathering));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gathering.m_pData;
        gathering.m_pData = nullptr;

        return *this;
    }

    const Gathering* operator->() const
    {
        return this;
    }

    Gathering* operator->()
    {
        return this;
    }
    /**
     * ギャザリングを取得
     *
     * @return ギャザリング
     */
    const optional<StringHolder>& getGatheringId() const
    {
        return ensureData().gatheringId;
    }

    /**
     * ギャザリングを設定
     *
     * @param gatheringId ギャザリング
     */
    void setGatheringId(const Char* gatheringId)
    {
        ensureData().gatheringId.emplace(gatheringId);
    }

    /**
     * ギャザリングを設定
     *
     * @param gatheringId ギャザリング
     */
    Gathering& withGatheringId(const Char* gatheringId)
    {
        setGatheringId(gatheringId);
        return *this;
    }

    /**
     * ギャザリング名を取得
     *
     * @return ギャザリング名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ギャザリング名を設定
     *
     * @param name ギャザリング名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ギャザリング名を設定
     *
     * @param name ギャザリング名
     */
    Gathering& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 募集条件を取得
     *
     * @return 募集条件
     */
    const optional<List<AttributeRange>>& getAttributeRanges() const
    {
        return ensureData().attributeRanges;
    }

    /**
     * 募集条件を設定
     *
     * @param attributeRanges 募集条件
     */
    void setAttributeRanges(const List<AttributeRange>& attributeRanges)
    {
        ensureData().attributeRanges.emplace(attributeRanges);
    }

    /**
     * 募集条件を設定
     *
     * @param attributeRanges 募集条件
     */
    Gathering& withAttributeRanges(const List<AttributeRange>& attributeRanges)
    {
        setAttributeRanges(attributeRanges);
        return *this;
    }

    /**
     * 参加者を取得
     *
     * @return 参加者
     */
    const optional<List<CapacityOfRole>>& getCapacityOfRoles() const
    {
        return ensureData().capacityOfRoles;
    }

    /**
     * 参加者を設定
     *
     * @param capacityOfRoles 参加者
     */
    void setCapacityOfRoles(const List<CapacityOfRole>& capacityOfRoles)
    {
        ensureData().capacityOfRoles.emplace(capacityOfRoles);
    }

    /**
     * 参加者を設定
     *
     * @param capacityOfRoles 参加者
     */
    Gathering& withCapacityOfRoles(const List<CapacityOfRole>& capacityOfRoles)
    {
        setCapacityOfRoles(capacityOfRoles);
        return *this;
    }

    /**
     * 参加を許可するユーザIDリストを取得
     *
     * @return 参加を許可するユーザIDリスト
     */
    const optional<List<StringHolder>>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    /**
     * 参加を許可するユーザIDリストを設定
     *
     * @param allowUserIds 参加を許可するユーザIDリスト
     */
    void setAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        ensureData().allowUserIds.emplace(allowUserIds);
    }

    /**
     * 参加を許可するユーザIDリストを設定
     *
     * @param allowUserIds 参加を許可するユーザIDリスト
     */
    Gathering& withAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        setAllowUserIds(allowUserIds);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    Gathering& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Gathering& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Gathering& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Gathering& lhs, const Gathering& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->gatheringId != lhr.m_pData->gatheringId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->attributeRanges != lhr.m_pData->attributeRanges)
        {
            return true;
        }
        if (lhs.m_pData->capacityOfRoles != lhr.m_pData->capacityOfRoles)
        {
            return true;
        }
        if (lhs.m_pData->allowUserIds != lhr.m_pData->allowUserIds)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Gathering& lhs, const Gathering& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_GATHERING_HPP_