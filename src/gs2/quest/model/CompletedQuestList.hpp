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

#ifndef GS2_QUEST_MODEL_COMPLETEDQUESTLIST_HPP_
#define GS2_QUEST_MODEL_COMPLETEDQUESTLIST_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * クエスト進行
 *
 * @author Game Server Services, Inc.
 *
 */
class CompletedQuestList : public Gs2Object
{
    friend bool operator!=(const CompletedQuestList& lhs, const CompletedQuestList& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト進行 */
        optional<StringHolder> completedQuestListId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** クエストグループ名 */
        optional<StringHolder> questGroupName;
        /** 攻略済みのクエスト名一覧のリスト */
        optional<List<StringHolder>> completeQuestNames;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            completedQuestListId(data.completedQuestListId),
            userId(data.userId),
            questGroupName(data.questGroupName),
            completeQuestNames(data.completeQuestNames),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            completedQuestListId(std::move(data.completedQuestListId)),
            userId(std::move(data.userId)),
            questGroupName(std::move(data.questGroupName)),
            completeQuestNames(std::move(data.completeQuestNames)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "completedQuestListId") == 0) {
                if (jsonValue.IsString())
                {
                    this->completedQuestListId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "questGroupName") == 0) {
                if (jsonValue.IsString())
                {
                    this->questGroupName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "completeQuestNames") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->completeQuestNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->completeQuestNames, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
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
    CompletedQuestList() :
        m_pData(nullptr)
    {}

    CompletedQuestList(const CompletedQuestList& completedQuestList) :
        Gs2Object(completedQuestList),
        m_pData(completedQuestList.m_pData != nullptr ? new Data(*completedQuestList.m_pData) : nullptr)
    {}

    CompletedQuestList(CompletedQuestList&& completedQuestList) :
        Gs2Object(std::move(completedQuestList)),
        m_pData(completedQuestList.m_pData)
    {
        completedQuestList.m_pData = nullptr;
    }

    ~CompletedQuestList()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CompletedQuestList& operator=(const CompletedQuestList& completedQuestList)
    {
        Gs2Object::operator=(completedQuestList);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*completedQuestList.m_pData);

        return *this;
    }

    CompletedQuestList& operator=(CompletedQuestList&& completedQuestList)
    {
        Gs2Object::operator=(std::move(completedQuestList));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = completedQuestList.m_pData;
        completedQuestList.m_pData = nullptr;

        return *this;
    }

    const CompletedQuestList* operator->() const
    {
        return this;
    }

    CompletedQuestList* operator->()
    {
        return this;
    }
    /**
     * クエスト進行を取得
     *
     * @return クエスト進行
     */
    const optional<StringHolder>& getCompletedQuestListId() const
    {
        return ensureData().completedQuestListId;
    }

    /**
     * クエスト進行を設定
     *
     * @param completedQuestListId クエスト進行
     */
    void setCompletedQuestListId(const Char* completedQuestListId)
    {
        ensureData().completedQuestListId.emplace(completedQuestListId);
    }

    /**
     * クエスト進行を設定
     *
     * @param completedQuestListId クエスト進行
     */
    CompletedQuestList& withCompletedQuestListId(const Char* completedQuestListId)
    {
        setCompletedQuestListId(completedQuestListId);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    CompletedQuestList& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * クエストグループ名を取得
     *
     * @return クエストグループ名
     */
    const optional<StringHolder>& getQuestGroupName() const
    {
        return ensureData().questGroupName;
    }

    /**
     * クエストグループ名を設定
     *
     * @param questGroupName クエストグループ名
     */
    void setQuestGroupName(const Char* questGroupName)
    {
        ensureData().questGroupName.emplace(questGroupName);
    }

    /**
     * クエストグループ名を設定
     *
     * @param questGroupName クエストグループ名
     */
    CompletedQuestList& withQuestGroupName(const Char* questGroupName)
    {
        setQuestGroupName(questGroupName);
        return *this;
    }

    /**
     * 攻略済みのクエスト名一覧のリストを取得
     *
     * @return 攻略済みのクエスト名一覧のリスト
     */
    const optional<List<StringHolder>>& getCompleteQuestNames() const
    {
        return ensureData().completeQuestNames;
    }

    /**
     * 攻略済みのクエスト名一覧のリストを設定
     *
     * @param completeQuestNames 攻略済みのクエスト名一覧のリスト
     */
    void setCompleteQuestNames(const List<StringHolder>& completeQuestNames)
    {
        ensureData().completeQuestNames.emplace(completeQuestNames);
    }

    /**
     * 攻略済みのクエスト名一覧のリストを設定
     *
     * @param completeQuestNames 攻略済みのクエスト名一覧のリスト
     */
    CompletedQuestList& withCompleteQuestNames(const List<StringHolder>& completeQuestNames)
    {
        setCompleteQuestNames(completeQuestNames);
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
    CompletedQuestList& withCreatedAt(Int64 createdAt)
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
    CompletedQuestList& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const CompletedQuestList& lhs, const CompletedQuestList& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->completedQuestListId != lhr.m_pData->completedQuestListId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->questGroupName != lhr.m_pData->questGroupName)
        {
            return true;
        }
        if (lhs.m_pData->completeQuestNames != lhr.m_pData->completeQuestNames)
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

inline bool operator==(const CompletedQuestList& lhs, const CompletedQuestList& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_COMPLETEDQUESTLIST_HPP_