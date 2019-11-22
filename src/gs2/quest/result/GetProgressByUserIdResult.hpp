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

#ifndef GS2_QUEST_CONTROL_GETPROGRESSBYUSERIDRESULT_HPP_
#define GS2_QUEST_CONTROL_GETPROGRESSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/quest/model/model.hpp>
#include <memory>

namespace gs2 { namespace quest
{

/**
 * ユーザIDを指定してクエスト挑戦を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetProgressByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト挑戦 */
        optional<Progress> item;
        /** クエストグループ */
        optional<QuestGroupModel> questGroup;
        /** クエストモデル */
        optional<QuestModel> quest;

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
    GetProgressByUserIdResult() = default;
    GetProgressByUserIdResult(const GetProgressByUserIdResult& getProgressByUserIdResult) = default;
    GetProgressByUserIdResult(GetProgressByUserIdResult&& getProgressByUserIdResult) = default;
    ~GetProgressByUserIdResult() = default;

    GetProgressByUserIdResult& operator=(const GetProgressByUserIdResult& getProgressByUserIdResult) = default;
    GetProgressByUserIdResult& operator=(GetProgressByUserIdResult&& getProgressByUserIdResult) = default;

    GetProgressByUserIdResult deepCopy() const;

    const GetProgressByUserIdResult* operator->() const
    {
        return this;
    }

    GetProgressByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * クエスト挑戦を取得
     *
     * @return クエスト挑戦
     */
    const optional<Progress>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * クエスト挑戦を設定
     *
     * @param item クエスト挑戦
     */
    void setItem(Progress item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * クエストグループを取得
     *
     * @return クエストグループ
     */
    const optional<QuestGroupModel>& getQuestGroup() const
    {
        return ensureData().questGroup;
    }

    /**
     * クエストグループを設定
     *
     * @param questGroup クエストグループ
     */
    void setQuestGroup(QuestGroupModel questGroup)
    {
        ensureData().questGroup.emplace(std::move(questGroup));
    }

    /**
     * クエストモデルを取得
     *
     * @return クエストモデル
     */
    const optional<QuestModel>& getQuest() const
    {
        return ensureData().quest;
    }

    /**
     * クエストモデルを設定
     *
     * @param quest クエストモデル
     */
    void setQuest(QuestModel quest)
    {
        ensureData().quest.emplace(std::move(quest));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetProgressByUserIdResult> AsyncGetProgressByUserIdResult;

} }

#endif //GS2_QUEST_CONTROL_GETPROGRESSBYUSERIDRESULT_HPP_