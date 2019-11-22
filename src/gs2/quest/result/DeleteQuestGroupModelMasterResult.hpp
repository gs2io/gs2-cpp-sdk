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

#ifndef GS2_QUEST_CONTROL_DELETEQUESTGROUPMODELMASTERRESULT_HPP_
#define GS2_QUEST_CONTROL_DELETEQUESTGROUPMODELMASTERRESULT_HPP_

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
 * クエストグループマスターを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteQuestGroupModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除したクエストグループマスター */
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
    DeleteQuestGroupModelMasterResult() = default;
    DeleteQuestGroupModelMasterResult(const DeleteQuestGroupModelMasterResult& deleteQuestGroupModelMasterResult) = default;
    DeleteQuestGroupModelMasterResult(DeleteQuestGroupModelMasterResult&& deleteQuestGroupModelMasterResult) = default;
    ~DeleteQuestGroupModelMasterResult() = default;

    DeleteQuestGroupModelMasterResult& operator=(const DeleteQuestGroupModelMasterResult& deleteQuestGroupModelMasterResult) = default;
    DeleteQuestGroupModelMasterResult& operator=(DeleteQuestGroupModelMasterResult&& deleteQuestGroupModelMasterResult) = default;

    DeleteQuestGroupModelMasterResult deepCopy() const;

    const DeleteQuestGroupModelMasterResult* operator->() const
    {
        return this;
    }

    DeleteQuestGroupModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 削除したクエストグループマスターを取得
     *
     * @return 削除したクエストグループマスター
     */
    const optional<QuestGroupModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除したクエストグループマスターを設定
     *
     * @param item 削除したクエストグループマスター
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

typedef AsyncResult<DeleteQuestGroupModelMasterResult> AsyncDeleteQuestGroupModelMasterResult;

} }

#endif //GS2_QUEST_CONTROL_DELETEQUESTGROUPMODELMASTERRESULT_HPP_