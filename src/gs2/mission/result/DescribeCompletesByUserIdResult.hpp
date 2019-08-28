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

#ifndef GS2_MISSION_CONTROL_DESCRIBECOMPLETESBYUSERIDRESULT_HPP_
#define GS2_MISSION_CONTROL_DESCRIBECOMPLETESBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace mission
{

/**
 * ユーザIDを指定して達成状況の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeCompletesByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 達成状況のリスト */
        optional<List<Complete>> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            nextPageToken(data.nextPageToken)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            nextPageToken(std::move(data.nextPageToken))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Complete item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "nextPageToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->nextPageToken.emplace(jsonValue.GetString());
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    DescribeCompletesByUserIdResult() :
        m_pData(nullptr)
    {}

    DescribeCompletesByUserIdResult(const DescribeCompletesByUserIdResult& describeCompletesByUserIdResult) :
        Gs2Object(describeCompletesByUserIdResult),
        m_pData(describeCompletesByUserIdResult.m_pData != nullptr ? new Data(*describeCompletesByUserIdResult.m_pData) : nullptr)
    {}

    DescribeCompletesByUserIdResult(DescribeCompletesByUserIdResult&& describeCompletesByUserIdResult) :
        Gs2Object(std::move(describeCompletesByUserIdResult)),
        m_pData(describeCompletesByUserIdResult.m_pData)
    {
        describeCompletesByUserIdResult.m_pData = nullptr;
    }

    ~DescribeCompletesByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeCompletesByUserIdResult& operator=(const DescribeCompletesByUserIdResult& describeCompletesByUserIdResult)
    {
        Gs2Object::operator=(describeCompletesByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeCompletesByUserIdResult.m_pData);

        return *this;
    }

    DescribeCompletesByUserIdResult& operator=(DescribeCompletesByUserIdResult&& describeCompletesByUserIdResult)
    {
        Gs2Object::operator=(std::move(describeCompletesByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeCompletesByUserIdResult.m_pData;
        describeCompletesByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const DescribeCompletesByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeCompletesByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 達成状況のリストを取得
     *
     * @return 達成状況のリスト
     */
    const optional<List<Complete>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 達成状況のリストを設定
     *
     * @param items 達成状況のリスト
     */
    void setItems(const List<Complete>& items)
    {
        ensureData().items.emplace(items);
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
    void setNextPageToken(const Char* nextPageToken)
    {
        ensureData().nextPageToken.emplace(nextPageToken);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeCompletesByUserIdResult> AsyncDescribeCompletesByUserIdResult;

} }

#endif //GS2_MISSION_CONTROL_DESCRIBECOMPLETESBYUSERIDRESULT_HPP_