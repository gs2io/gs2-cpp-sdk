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

#ifndef GS2_INBOX_MODEL_RECEIVED_HPP_
#define GS2_INBOX_MODEL_RECEIVED_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * 受信済みグローバルメッセージ名
 *
 * @author Game Server Services, Inc.
 *
 */
class Received : public Gs2Object
{
    friend bool operator!=(const Received& lhs, const Received& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 受信済みグローバルメッセージ名 */
        optional<StringHolder> receivedId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 受信したグローバルメッセージ名 */
        optional<List<StringHolder>> receivedGlobalMessageNames;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            receivedId(data.receivedId),
            userId(data.userId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.receivedGlobalMessageNames)
            {
                receivedGlobalMessageNames = data.receivedGlobalMessageNames->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "receivedId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->receivedId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "receivedGlobalMessageNames") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->receivedGlobalMessageNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->receivedGlobalMessageNames += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Received() = default;
    Received(const Received& received) = default;
    Received(Received&& received) = default;
    ~Received() = default;

    Received& operator=(const Received& received) = default;
    Received& operator=(Received&& received) = default;

    Received deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Received);
    }

    const Received* operator->() const
    {
        return this;
    }

    Received* operator->()
    {
        return this;
    }
    /**
     * 受信済みグローバルメッセージ名を取得
     *
     * @return 受信済みグローバルメッセージ名
     */
    const optional<StringHolder>& getReceivedId() const
    {
        return ensureData().receivedId;
    }

    /**
     * 受信済みグローバルメッセージ名を設定
     *
     * @param receivedId 受信済みグローバルメッセージ名
     */
    void setReceivedId(StringHolder receivedId)
    {
        ensureData().receivedId.emplace(std::move(receivedId));
    }

    /**
     * 受信済みグローバルメッセージ名を設定
     *
     * @param receivedId 受信済みグローバルメッセージ名
     */
    Received& withReceivedId(StringHolder receivedId)
    {
        setReceivedId(std::move(receivedId));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Received& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 受信したグローバルメッセージ名を取得
     *
     * @return 受信したグローバルメッセージ名
     */
    const optional<List<StringHolder>>& getReceivedGlobalMessageNames() const
    {
        return ensureData().receivedGlobalMessageNames;
    }

    /**
     * 受信したグローバルメッセージ名を設定
     *
     * @param receivedGlobalMessageNames 受信したグローバルメッセージ名
     */
    void setReceivedGlobalMessageNames(List<StringHolder> receivedGlobalMessageNames)
    {
        ensureData().receivedGlobalMessageNames.emplace(std::move(receivedGlobalMessageNames));
    }

    /**
     * 受信したグローバルメッセージ名を設定
     *
     * @param receivedGlobalMessageNames 受信したグローバルメッセージ名
     */
    Received& withReceivedGlobalMessageNames(List<StringHolder> receivedGlobalMessageNames)
    {
        setReceivedGlobalMessageNames(std::move(receivedGlobalMessageNames));
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
    Received& withCreatedAt(Int64 createdAt)
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
    Received& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Received& lhs, const Received& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->receivedId != lhr.m_pData->receivedId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->receivedGlobalMessageNames != lhr.m_pData->receivedGlobalMessageNames)
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

inline bool operator==(const Received& lhs, const Received& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_RECEIVED_HPP_