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

#ifndef GS2_QUEST_CONTROL_UPDATEQUESTGROUPMODELMASTERRESULT_HPP_
#define GS2_QUEST_CONTROL_UPDATEQUESTGROUPMODELMASTERRESULT_HPP_

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
 * クエストグループマスターを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateQuestGroupModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新したクエストグループマスター */
        optional<QuestGroupModelMaster> item;

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
    UpdateQuestGroupModelMasterResult() = default;
    UpdateQuestGroupModelMasterResult(const UpdateQuestGroupModelMasterResult& updateQuestGroupModelMasterResult) = default;
    UpdateQuestGroupModelMasterResult(UpdateQuestGroupModelMasterResult&& updateQuestGroupModelMasterResult) = default;
    ~UpdateQuestGroupModelMasterResult() = default;

    UpdateQuestGroupModelMasterResult& operator=(const UpdateQuestGroupModelMasterResult& updateQuestGroupModelMasterResult) = default;
    UpdateQuestGroupModelMasterResult& operator=(UpdateQuestGroupModelMasterResult&& updateQuestGroupModelMasterResult) = default;

    UpdateQuestGroupModelMasterResult deepCopy() const;

    const UpdateQuestGroupModelMasterResult* operator->() const
    {
        return this;
    }

    UpdateQuestGroupModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新したクエストグループマスターを取得
     *
     * @return 更新したクエストグループマスター
     */
    const optional<QuestGroupModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新したクエストグループマスターを設定
     *
     * @param item 更新したクエストグループマスター
     */
    void setItem(QuestGroupModelMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateQuestGroupModelMasterResult> AsyncUpdateQuestGroupModelMasterResult;

} }

#endif //GS2_QUEST_CONTROL_UPDATEQUESTGROUPMODELMASTERRESULT_HPP_