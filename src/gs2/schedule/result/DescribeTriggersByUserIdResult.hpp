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

#ifndef GS2_SCHEDULE_CONTROL_DESCRIBETRIGGERSBYUSERIDRESULT_HPP_
#define GS2_SCHEDULE_CONTROL_DESCRIBETRIGGERSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/schedule/model/model.hpp>
#include <memory>

namespace gs2 { namespace schedule
{

/**
 * ユーザIDを指定してトリガーの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeTriggersByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** トリガーのリスト */
        optional<List<Trigger>> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            nextPageToken(data.nextPageToken)
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
                        Trigger item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "nextPageToken") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->nextPageToken.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DescribeTriggersByUserIdResult() = default;
    DescribeTriggersByUserIdResult(const DescribeTriggersByUserIdResult& describeTriggersByUserIdResult) = default;
    DescribeTriggersByUserIdResult(DescribeTriggersByUserIdResult&& describeTriggersByUserIdResult) = default;
    ~DescribeTriggersByUserIdResult() = default;

    DescribeTriggersByUserIdResult& operator=(const DescribeTriggersByUserIdResult& describeTriggersByUserIdResult) = default;
    DescribeTriggersByUserIdResult& operator=(DescribeTriggersByUserIdResult&& describeTriggersByUserIdResult) = default;

    DescribeTriggersByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeTriggersByUserIdResult);
    }

    const DescribeTriggersByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeTriggersByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * トリガーのリストを取得
     *
     * @return トリガーのリスト
     */
    const optional<List<Trigger>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * トリガーのリストを設定
     *
     * @param items トリガーのリスト
     */
    void setItems(List<Trigger> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * リストの続きを取得するためのページトークンを取得
     *
     * @return リストの続きを取得するためのページトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * リストの続きを取得するためのページトークンを設定
     *
     * @param nextPageToken リストの続きを取得するためのページトークン
     */
    void setNextPageToken(StringHolder nextPageToken)
    {
        ensureData().nextPageToken.emplace(std::move(nextPageToken));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeTriggersByUserIdResult> AsyncDescribeTriggersByUserIdResult;

} }

#endif //GS2_SCHEDULE_CONTROL_DESCRIBETRIGGERSBYUSERIDRESULT_HPP_