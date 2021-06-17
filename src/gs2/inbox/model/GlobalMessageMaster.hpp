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

#ifndef GS2_INBOX_MODEL_GLOBALMESSAGEMASTER_HPP_
#define GS2_INBOX_MODEL_GLOBALMESSAGEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include "TimeSpan.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * 全ユーザに向けたメッセージ
 *
 * @author Game Server Services, Inc.
 *
 */
class GlobalMessageMaster : public Gs2Object
{
    friend bool operator!=(const GlobalMessageMaster& lhs, const GlobalMessageMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 全ユーザに向けたメッセージ */
        optional<StringHolder> globalMessageId;
        /** 全ユーザに向けたメッセージ名 */
        optional<StringHolder> name;
        /** 全ユーザに向けたメッセージの内容に相当するメタデータ */
        optional<StringHolder> metadata;
        /** 開封時に実行する入手アクション */
        optional<List<AcquireAction>> readAcquireActions;
        /** メッセージを受信したあとメッセージが削除されるまでの期間 */
        optional<TimeSpan> expiresTimeSpan;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 全ユーザに向けたメッセージの受信期限 */
        optional<Int64> expiresAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            globalMessageId(data.globalMessageId),
            name(data.name),
            metadata(data.metadata),
            createdAt(data.createdAt),
            expiresAt(data.expiresAt)
        {
            if (data.readAcquireActions)
            {
                readAcquireActions = data.readAcquireActions->deepCopy();
            }
            if (data.expiresTimeSpan)
            {
                expiresTimeSpan = data.expiresTimeSpan->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "globalMessageId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->globalMessageId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "readAcquireActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->readAcquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->readAcquireActions += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "expiresTimeSpan") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->expiresTimeSpan.emplace();
                    detail::json::JsonParser::parse(&this->expiresTimeSpan->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "expiresAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->expiresAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GlobalMessageMaster() = default;
    GlobalMessageMaster(const GlobalMessageMaster& globalMessageMaster) = default;
    GlobalMessageMaster(GlobalMessageMaster&& globalMessageMaster) = default;
    ~GlobalMessageMaster() = default;

    GlobalMessageMaster& operator=(const GlobalMessageMaster& globalMessageMaster) = default;
    GlobalMessageMaster& operator=(GlobalMessageMaster&& globalMessageMaster) = default;

    GlobalMessageMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GlobalMessageMaster);
    }

    const GlobalMessageMaster* operator->() const
    {
        return this;
    }

    GlobalMessageMaster* operator->()
    {
        return this;
    }
    /**
     * 全ユーザに向けたメッセージを取得
     *
     * @return 全ユーザに向けたメッセージ
     */
    const optional<StringHolder>& getGlobalMessageId() const
    {
        return ensureData().globalMessageId;
    }

    /**
     * 全ユーザに向けたメッセージを設定
     *
     * @param globalMessageId 全ユーザに向けたメッセージ
     */
    void setGlobalMessageId(StringHolder globalMessageId)
    {
        ensureData().globalMessageId.emplace(std::move(globalMessageId));
    }

    /**
     * 全ユーザに向けたメッセージを設定
     *
     * @param globalMessageId 全ユーザに向けたメッセージ
     */
    GlobalMessageMaster& withGlobalMessageId(StringHolder globalMessageId)
    {
        setGlobalMessageId(std::move(globalMessageId));
        return *this;
    }

    /**
     * 全ユーザに向けたメッセージ名を取得
     *
     * @return 全ユーザに向けたメッセージ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 全ユーザに向けたメッセージ名を設定
     *
     * @param name 全ユーザに向けたメッセージ名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 全ユーザに向けたメッセージ名を設定
     *
     * @param name 全ユーザに向けたメッセージ名
     */
    GlobalMessageMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 全ユーザに向けたメッセージの内容に相当するメタデータを取得
     *
     * @return 全ユーザに向けたメッセージの内容に相当するメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 全ユーザに向けたメッセージの内容に相当するメタデータを設定
     *
     * @param metadata 全ユーザに向けたメッセージの内容に相当するメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 全ユーザに向けたメッセージの内容に相当するメタデータを設定
     *
     * @param metadata 全ユーザに向けたメッセージの内容に相当するメタデータ
     */
    GlobalMessageMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 開封時に実行する入手アクションを取得
     *
     * @return 開封時に実行する入手アクション
     */
    const optional<List<AcquireAction>>& getReadAcquireActions() const
    {
        return ensureData().readAcquireActions;
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    void setReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        ensureData().readAcquireActions.emplace(std::move(readAcquireActions));
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    GlobalMessageMaster& withReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        setReadAcquireActions(std::move(readAcquireActions));
        return *this;
    }

    /**
     * メッセージを受信したあとメッセージが削除されるまでの期間を取得
     *
     * @return メッセージを受信したあとメッセージが削除されるまでの期間
     */
    const optional<TimeSpan>& getExpiresTimeSpan() const
    {
        return ensureData().expiresTimeSpan;
    }

    /**
     * メッセージを受信したあとメッセージが削除されるまでの期間を設定
     *
     * @param expiresTimeSpan メッセージを受信したあとメッセージが削除されるまでの期間
     */
    void setExpiresTimeSpan(TimeSpan expiresTimeSpan)
    {
        ensureData().expiresTimeSpan.emplace(std::move(expiresTimeSpan));
    }

    /**
     * メッセージを受信したあとメッセージが削除されるまでの期間を設定
     *
     * @param expiresTimeSpan メッセージを受信したあとメッセージが削除されるまでの期間
     */
    GlobalMessageMaster& withExpiresTimeSpan(TimeSpan expiresTimeSpan)
    {
        setExpiresTimeSpan(std::move(expiresTimeSpan));
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
    GlobalMessageMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 全ユーザに向けたメッセージの受信期限を取得
     *
     * @return 全ユーザに向けたメッセージの受信期限
     */
    const optional<Int64>& getExpiresAt() const
    {
        return ensureData().expiresAt;
    }

    /**
     * 全ユーザに向けたメッセージの受信期限を設定
     *
     * @param expiresAt 全ユーザに向けたメッセージの受信期限
     */
    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt.emplace(expiresAt);
    }

    /**
     * 全ユーザに向けたメッセージの受信期限を設定
     *
     * @param expiresAt 全ユーザに向けたメッセージの受信期限
     */
    GlobalMessageMaster& withExpiresAt(Int64 expiresAt)
    {
        setExpiresAt(expiresAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const GlobalMessageMaster& lhs, const GlobalMessageMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->globalMessageId != lhr.m_pData->globalMessageId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->readAcquireActions != lhr.m_pData->readAcquireActions)
        {
            return true;
        }
        if (lhs.m_pData->expiresTimeSpan != lhr.m_pData->expiresTimeSpan)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->expiresAt != lhr.m_pData->expiresAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const GlobalMessageMaster& lhs, const GlobalMessageMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_GLOBALMESSAGEMASTER_HPP_