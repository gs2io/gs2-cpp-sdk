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

#ifndef GS2_MISSION_CONTROL_CREATEMISSIONTASKMODELMASTERRESULT_HPP_
#define GS2_MISSION_CONTROL_CREATEMISSIONTASKMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/mission/model/model.hpp>
#include <memory>

namespace gs2 { namespace mission
{

/**
 * ミッションタスクマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateMissionTaskModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したミッションタスクマスター */
        optional<MissionTaskModelMaster> item;

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
    CreateMissionTaskModelMasterResult() = default;
    CreateMissionTaskModelMasterResult(const CreateMissionTaskModelMasterResult& createMissionTaskModelMasterResult) = default;
    CreateMissionTaskModelMasterResult(CreateMissionTaskModelMasterResult&& createMissionTaskModelMasterResult) = default;
    ~CreateMissionTaskModelMasterResult() = default;

    CreateMissionTaskModelMasterResult& operator=(const CreateMissionTaskModelMasterResult& createMissionTaskModelMasterResult) = default;
    CreateMissionTaskModelMasterResult& operator=(CreateMissionTaskModelMasterResult&& createMissionTaskModelMasterResult) = default;

    CreateMissionTaskModelMasterResult deepCopy() const;

    const CreateMissionTaskModelMasterResult* operator->() const
    {
        return this;
    }

    CreateMissionTaskModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したミッションタスクマスターを取得
     *
     * @return 作成したミッションタスクマスター
     */
    const optional<MissionTaskModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したミッションタスクマスターを設定
     *
     * @param item 作成したミッションタスクマスター
     */
    void setItem(MissionTaskModelMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CreateMissionTaskModelMasterResult> AsyncCreateMissionTaskModelMasterResult;

} }

#endif //GS2_MISSION_CONTROL_CREATEMISSIONTASKMODELMASTERRESULT_HPP_