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

#ifndef GS2_JOBQUEUE_CONTROL_DESCRIBEJOBSBYUSERIDRESULT_HPP_
#define GS2_JOBQUEUE_CONTROL_DESCRIBEJOBSBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace jobQueue
{

/**
 * ジョブの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeJobsByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ジョブのリスト */
        optional<List<Job>> items;
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

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Job item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "nextPageToken") == 0) {
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
    DescribeJobsByUserIdResult() :
        m_pData(nullptr)
    {}

    DescribeJobsByUserIdResult(const DescribeJobsByUserIdResult& describeJobsByUserIdResult) :
        Gs2Object(describeJobsByUserIdResult),
        m_pData(describeJobsByUserIdResult.m_pData != nullptr ? new Data(*describeJobsByUserIdResult.m_pData) : nullptr)
    {}

    DescribeJobsByUserIdResult(DescribeJobsByUserIdResult&& describeJobsByUserIdResult) :
        Gs2Object(std::move(describeJobsByUserIdResult)),
        m_pData(describeJobsByUserIdResult.m_pData)
    {
        describeJobsByUserIdResult.m_pData = nullptr;
    }

    ~DescribeJobsByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeJobsByUserIdResult& operator=(const DescribeJobsByUserIdResult& describeJobsByUserIdResult)
    {
        Gs2Object::operator=(describeJobsByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeJobsByUserIdResult.m_pData);

        return *this;
    }

    DescribeJobsByUserIdResult& operator=(DescribeJobsByUserIdResult&& describeJobsByUserIdResult)
    {
        Gs2Object::operator=(std::move(describeJobsByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeJobsByUserIdResult.m_pData;
        describeJobsByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const DescribeJobsByUserIdResult* operator->() const
    {
        return this;
    }

    DescribeJobsByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * ジョブのリストを取得
     *
     * @return ジョブのリスト
     */
    const optional<List<Job>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ジョブのリストを設定
     *
     * @param items ジョブのリスト
     */
    void setItems(const List<Job>& items)
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

} }

#endif //GS2_JOBQUEUE_CONTROL_DESCRIBEJOBSBYUSERIDRESULT_HPP_