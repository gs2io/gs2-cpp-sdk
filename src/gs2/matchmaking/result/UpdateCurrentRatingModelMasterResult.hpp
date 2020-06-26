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

#ifndef GS2_MATCHMAKING_CONTROL_UPDATECURRENTRATINGMODELMASTERRESULT_HPP_
#define GS2_MATCHMAKING_CONTROL_UPDATECURRENTRATINGMODELMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/matchmaking/model/model.hpp>
#include <memory>

namespace gs2 { namespace matchmaking
{

/**
 * 現在有効な所持品マスターを更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentRatingModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効な所持品マスター */
        optional<CurrentRatingModelMaster> item;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    UpdateCurrentRatingModelMasterResult() = default;
    UpdateCurrentRatingModelMasterResult(const UpdateCurrentRatingModelMasterResult& updateCurrentRatingModelMasterResult) = default;
    UpdateCurrentRatingModelMasterResult(UpdateCurrentRatingModelMasterResult&& updateCurrentRatingModelMasterResult) = default;
    ~UpdateCurrentRatingModelMasterResult() = default;

    UpdateCurrentRatingModelMasterResult& operator=(const UpdateCurrentRatingModelMasterResult& updateCurrentRatingModelMasterResult) = default;
    UpdateCurrentRatingModelMasterResult& operator=(UpdateCurrentRatingModelMasterResult&& updateCurrentRatingModelMasterResult) = default;

    UpdateCurrentRatingModelMasterResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateCurrentRatingModelMasterResult);
    }

    const UpdateCurrentRatingModelMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentRatingModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効な所持品マスターを取得
     *
     * @return 更新した現在有効な所持品マスター
     */
    const optional<CurrentRatingModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効な所持品マスターを設定
     *
     * @param item 更新した現在有効な所持品マスター
     */
    void setItem(CurrentRatingModelMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateCurrentRatingModelMasterResult> AsyncUpdateCurrentRatingModelMasterResult;

} }

#endif //GS2_MATCHMAKING_CONTROL_UPDATECURRENTRATINGMODELMASTERRESULT_HPP_