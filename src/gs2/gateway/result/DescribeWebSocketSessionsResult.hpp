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

#ifndef GS2_GATEWAY_CONTROL_DESCRIBEWEBSOCKETSESSIONSRESULT_HPP_
#define GS2_GATEWAY_CONTROL_DESCRIBEWEBSOCKETSESSIONSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/gateway/model/model.hpp>
#include <memory>

namespace gs2 { namespace gateway
{

/**
 * Websocketセッションの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeWebSocketSessionsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** Websocketセッションのリスト */
        optional<List<WebSocketSession>> items;
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
                        WebSocketSession item;
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
    DescribeWebSocketSessionsResult() = default;
    DescribeWebSocketSessionsResult(const DescribeWebSocketSessionsResult& describeWebSocketSessionsResult) = default;
    DescribeWebSocketSessionsResult(DescribeWebSocketSessionsResult&& describeWebSocketSessionsResult) = default;
    ~DescribeWebSocketSessionsResult() = default;

    DescribeWebSocketSessionsResult& operator=(const DescribeWebSocketSessionsResult& describeWebSocketSessionsResult) = default;
    DescribeWebSocketSessionsResult& operator=(DescribeWebSocketSessionsResult&& describeWebSocketSessionsResult) = default;

    DescribeWebSocketSessionsResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeWebSocketSessionsResult);
    }

    const DescribeWebSocketSessionsResult* operator->() const
    {
        return this;
    }

    DescribeWebSocketSessionsResult* operator->()
    {
        return this;
    }
    /**
     * Websocketセッションのリストを取得
     *
     * @return Websocketセッションのリスト
     */
    const optional<List<WebSocketSession>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * Websocketセッションのリストを設定
     *
     * @param items Websocketセッションのリスト
     */
    void setItems(List<WebSocketSession> items)
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

typedef AsyncResult<DescribeWebSocketSessionsResult> AsyncDescribeWebSocketSessionsResult;

} }

#endif //GS2_GATEWAY_CONTROL_DESCRIBEWEBSOCKETSESSIONSRESULT_HPP_