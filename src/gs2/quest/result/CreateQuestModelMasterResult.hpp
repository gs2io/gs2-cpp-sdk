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

#ifndef GS2_QUEST_CONTROL_CREATEQUESTMODELMASTERRESULT_HPP_
#define GS2_QUEST_CONTROL_CREATEQUESTMODELMASTERRESULT_HPP_

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
 * クエストモデルマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateQuestModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したクエストモデルマスター */
        optional<QuestModelMaster> item;

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
    CreateQuestModelMasterResult() = default;
    CreateQuestModelMasterResult(const CreateQuestModelMasterResult& createQuestModelMasterResult) = default;
    CreateQuestModelMasterResult(CreateQuestModelMasterResult&& createQuestModelMasterResult) = default;
    ~CreateQuestModelMasterResult() = default;

    CreateQuestModelMasterResult& operator=(const CreateQuestModelMasterResult& createQuestModelMasterResult) = default;
    CreateQuestModelMasterResult& operator=(CreateQuestModelMasterResult&& createQuestModelMasterResult) = default;

    CreateQuestModelMasterResult deepCopy() const;

    const CreateQuestModelMasterResult* operator->() const
    {
        return this;
    }

    CreateQuestModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したクエストモデルマスターを取得
     *
     * @return 作成したクエストモデルマスター
     */
    const optional<QuestModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したクエストモデルマスターを設定
     *
     * @param item 作成したクエストモデルマスター
     */
    void setItem(QuestModelMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CreateQuestModelMasterResult> AsyncCreateQuestModelMasterResult;

} }

#endif //GS2_QUEST_CONTROL_CREATEQUESTMODELMASTERRESULT_HPP_