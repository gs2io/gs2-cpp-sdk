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

#ifndef GS2_LOTTERY_MODEL_GROUP_HPP_
#define GS2_LOTTERY_MODEL_GROUP_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * グループの種類
 *
 * @author Game Server Services, Inc.
 *
 */
class Group : public Gs2Object
{
    friend bool operator!=(const Group& lhs, const Group& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** グループの種類 のGRN */
        optional<StringHolder> groupId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** グループ名 */
        optional<StringHolder> name;
        /** グループの種類の説明 */
        optional<StringHolder> description;
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
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            groupId(std::move(data.groupId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
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
     * グループの種類 のGRNを取得
     *
     * @return グループの種類 のGRN
     */
    const optional<StringHolder>& getGroupId() const
    {
        return ensureData().groupId;
    }

    /**
     * グループの種類 のGRNを設定
     *
     * @param groupId グループの種類 のGRN
     */
    void setGroupId(const Char* groupId)
    {
        ensureData().groupId.emplace(groupId);
    }

    /**
     * グループの種類 のGRNを設定
     *
     * @param groupId グループの種類 のGRN
     */
    Group& withGroupId(const Char* groupId)
    {
        setGroupId(groupId);
        return *this;
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
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Group& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * グループ名を取得
     *
     * @return グループ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * グループ名を設定
     *
     * @param name グループ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * グループ名を設定
     *
     * @param name グループ名
     */
    Group& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * グループの種類の説明を取得
     *
     * @return グループの種類の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * グループの種類の説明を設定
     *
     * @param description グループの種類の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * グループの種類の説明を設定
     *
     * @param description グループの種類の説明
     */
    Group& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
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
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    Group& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
        return *this;
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

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    Group& withUpdateAt(Int64 updateAt)
    {
        setUpdateAt(updateAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Group& lhs, const Group& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->groupId != lhr.m_pData->groupId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
        {
            return true;
        }
        if (lhs.m_pData->updateAt != lhr.m_pData->updateAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Group& lhs, const Group& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_GROUP_HPP_