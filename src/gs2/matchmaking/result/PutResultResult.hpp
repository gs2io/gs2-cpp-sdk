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

#ifndef GS2_MATCHMAKING_CONTROL_PUTRESULTRESULT_HPP_
#define GS2_MATCHMAKING_CONTROL_PUTRESULTRESULT_HPP_

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
 * レーティング値の再計算を実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class PutResultResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新後の{model_name}の一覧 */
        optional<List<Rating>> items;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Rating item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item_);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    PutResultResult() = default;
    PutResultResult(const PutResultResult& putResultResult) = default;
    PutResultResult(PutResultResult&& putResultResult) = default;
    ~PutResultResult() = default;

    PutResultResult& operator=(const PutResultResult& putResultResult) = default;
    PutResultResult& operator=(PutResultResult&& putResultResult) = default;

    PutResultResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PutResultResult);
    }

    const PutResultResult* operator->() const
    {
        return this;
    }

    PutResultResult* operator->()
    {
        return this;
    }
    /**
     * 更新後の{model_name}の一覧を取得
     *
     * @return 更新後の{model_name}の一覧
     */
    const optional<List<Rating>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 更新後の{model_name}の一覧を設定
     *
     * @param items 更新後の{model_name}の一覧
     */
    void setItems(List<Rating> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<PutResultResult> AsyncPutResultResult;

} }

#endif //GS2_MATCHMAKING_CONTROL_PUTRESULTRESULT_HPP_