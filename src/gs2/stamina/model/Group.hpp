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

#ifndef GS2_STAMINA_MODEL_GROUP_HPP_
#define GS2_STAMINA_MODEL_GROUP_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナの種類
 *
 * @author Game Server Services, Inc.
 *
 */
class Group : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナの種類 のGRN */
        optional<StringHolder> groupId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** スタミナの種類名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN */
        optional<StringHolder> overflowTriggerScriptId;
        /** スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRN */
        optional<StringHolder> overflowTriggerQueueId;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            groupId(data.groupId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            overflowTriggerScriptId(data.overflowTriggerScriptId),
            overflowTriggerQueueId(data.overflowTriggerQueueId),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            groupId(std::move(data.groupId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            overflowTriggerScriptId(std::move(data.overflowTriggerScriptId)),
            overflowTriggerQueueId(std::move(data.overflowTriggerQueueId)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "groupId") == 0) {
                if (jsonValue.IsString())
                {
                    this->groupId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "overflowTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->overflowTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "overflowTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->overflowTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
    Group() :
        m_pData(nullptr)
    {}

    Group(const Group& group) :
        Gs2Object(group),
        m_pData(group.m_pData != nullptr ? new Data(*group.m_pData) : nullptr)
    {}

    Group(Group&& group) :
        Gs2Object(std::move(group)),
        m_pData(group.m_pData)
    {
        group.m_pData = nullptr;
    }

    ~Group()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Group& operator=(const Group& group)
    {
        Gs2Object::operator=(group);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*group.m_pData);

        return *this;
    }

    Group& operator=(Group&& group)
    {
        Gs2Object::operator=(std::move(group));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = group.m_pData;
        group.m_pData = nullptr;

        return *this;
    }

    const Group* operator->() const
    {
        return this;
    }

    Group* operator->()
    {
        return this;
    }
    /**
     * スタミナの種類 のGRNを取得
     *
     * @return スタミナの種類 のGRN
     */
    const optional<StringHolder>& getGroupId() const
    {
        return ensureData().groupId;
    }

    /**
     * スタミナの種類 のGRNを設定
     *
     * @param groupId スタミナの種類 のGRN
     */
    void setGroupId(const Char* groupId)
    {
        ensureData().groupId.emplace(groupId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param name スタミナの種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRNを取得
     *
     * @return スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN
     */
    const optional<StringHolder>& getOverflowTriggerScriptId() const
    {
        return ensureData().overflowTriggerScriptId;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN
     */
    void setOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRNを取得
     *
     * @return スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRN
     */
    const optional<StringHolder>& getOverflowTriggerQueueId() const
    {
        return ensureData().overflowTriggerQueueId;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRNを設定
     *
     * @param overflowTriggerQueueId スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRN
     */
    void setOverflowTriggerQueueId(const Char* overflowTriggerQueueId)
    {
        ensureData().overflowTriggerQueueId.emplace(overflowTriggerQueueId);
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_MODEL_GROUP_HPP_