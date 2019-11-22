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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

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

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CompletedQuestList() = default;
    CompletedQuestList(const CompletedQuestList& completedQuestList) = default;
    CompletedQuestList(CompletedQuestList&& completedQuestList) = default;
    ~CompletedQuestList() = default;

    CompletedQuestList& operator=(const CompletedQuestList& completedQuestList) = default;
    CompletedQuestList& operator=(CompletedQuestList&& completedQuestList) = default;

    CompletedQuestList deepCopy() const;

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
    void setCompletedQuestListId(StringHolder completedQuestListId)
    {
        ensureData().completedQuestListId.emplace(std::move(completedQuestListId));
    }

    /**
     * クエスト進行を設定
     *
     * @param completedQuestListId クエスト進行
     */
    CompletedQuestList& withCompletedQuestListId(StringHolder completedQuestListId)
    {
        setCompletedQuestListId(std::move(completedQuestListId));
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
    CompletedQuestList& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
    void setQuestGroupName(StringHolder questGroupName)
    {
        ensureData().questGroupName.emplace(std::move(questGroupName));
    }

    /**
     * クエストグループ名を設定
     *
     * @param questGroupName クエストグループ名
     */
    CompletedQuestList& withQuestGroupName(StringHolder questGroupName)
    {
        setQuestGroupName(std::move(questGroupName));
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
    void setCompleteQuestNames(List<StringHolder> completeQuestNames)
    {
        ensureData().completeQuestNames.emplace(std::move(completeQuestNames));
    }

    /**
     * 攻略済みのクエスト名一覧のリストを設定
     *
     * @param completeQuestNames 攻略済みのクエスト名一覧のリスト
     */
    CompletedQuestList& withCompleteQuestNames(List<StringHolder> completeQuestNames)
    {
        setCompleteQuestNames(std::move(completeQuestNames));
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

bool operator!=(const CompletedQuestList& lhs, const CompletedQuestList& lhr);

inline bool operator==(const CompletedQuestList& lhs, const CompletedQuestList& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_COMPLETEDQUESTLIST_HPP_