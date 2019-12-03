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

#ifndef GS2_FORMATION_CONTROL_UPDATECURRENTFORMMASTERRESULT_HPP_
#define GS2_FORMATION_CONTROL_UPDATECURRENTFORMMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * 現在有効なフォーム設定を更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentFormMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効なフォーム設定 */
        optional<CurrentFormMaster> item;

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
    UpdateCurrentFormMasterResult() = default;
    UpdateCurrentFormMasterResult(const UpdateCurrentFormMasterResult& updateCurrentFormMasterResult) = default;
    UpdateCurrentFormMasterResult(UpdateCurrentFormMasterResult&& updateCurrentFormMasterResult) = default;
    ~UpdateCurrentFormMasterResult() = default;

    UpdateCurrentFormMasterResult& operator=(const UpdateCurrentFormMasterResult& updateCurrentFormMasterResult) = default;
    UpdateCurrentFormMasterResult& operator=(UpdateCurrentFormMasterResult&& updateCurrentFormMasterResult) = default;

    UpdateCurrentFormMasterResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateCurrentFormMasterResult);
    }

    const UpdateCurrentFormMasterResult* operator->() const
    {
        return this;
    }

    UpdateCurrentFormMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効なフォーム設定を取得
     *
     * @return 更新した現在有効なフォーム設定
     */
    const optional<CurrentFormMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効なフォーム設定を設定
     *
     * @param item 更新した現在有効なフォーム設定
     */
    void setItem(CurrentFormMaster item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateCurrentFormMasterResult> AsyncUpdateCurrentFormMasterResult;

} }

#endif //GS2_FORMATION_CONTROL_UPDATECURRENTFORMMASTERRESULT_HPP_