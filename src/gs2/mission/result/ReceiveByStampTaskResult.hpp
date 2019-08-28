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

#ifndef GS2_MISSION_CONTROL_RECEIVEBYSTAMPTASKRESULT_HPP_
#define GS2_MISSION_CONTROL_RECEIVEBYSTAMPTASKRESULT_HPP_

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
 * 達成状況を作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ReceiveByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 達成状況 */
        optional<Complete> item;
        /** スタンプタスクの実行結果を記録したコンテキスト */
        optional<StringHolder> newContextStack;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            newContextStack(data.newContextStack)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            newContextStack(std::move(data.newContextStack))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "newContextStack") == 0) {
                if (jsonValue.IsString())
                {
                    this->newContextStack.emplace(jsonValue.GetString());
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
    ReceiveByStampTaskResult() :
        m_pData(nullptr)
    {}

    ReceiveByStampTaskResult(const ReceiveByStampTaskResult& receiveByStampTaskResult) :
        Gs2Object(receiveByStampTaskResult),
        m_pData(receiveByStampTaskResult.m_pData != nullptr ? new Data(*receiveByStampTaskResult.m_pData) : nullptr)
    {}

    ReceiveByStampTaskResult(ReceiveByStampTaskResult&& receiveByStampTaskResult) :
        Gs2Object(std::move(receiveByStampTaskResult)),
        m_pData(receiveByStampTaskResult.m_pData)
    {
        receiveByStampTaskResult.m_pData = nullptr;
    }

    ~ReceiveByStampTaskResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ReceiveByStampTaskResult& operator=(const ReceiveByStampTaskResult& receiveByStampTaskResult)
    {
        Gs2Object::operator=(receiveByStampTaskResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*receiveByStampTaskResult.m_pData);

        return *this;
    }

    ReceiveByStampTaskResult& operator=(ReceiveByStampTaskResult&& receiveByStampTaskResult)
    {
        Gs2Object::operator=(std::move(receiveByStampTaskResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = receiveByStampTaskResult.m_pData;
        receiveByStampTaskResult.m_pData = nullptr;

        return *this;
    }

    const ReceiveByStampTaskResult* operator->() const
    {
        return this;
    }

    ReceiveByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * 達成状況を取得
     *
     * @return 達成状況
     */
    const optional<Complete>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 達成状況を設定
     *
     * @param item 達成状況
     */
    void setItem(const Complete& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを取得
     *
     * @return スタンプタスクの実行結果を記録したコンテキスト
     */
    const optional<StringHolder>& getNewContextStack() const
    {
        return ensureData().newContextStack;
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを設定
     *
     * @param newContextStack スタンプタスクの実行結果を記録したコンテキスト
     */
    void setNewContextStack(const Char* newContextStack)
    {
        ensureData().newContextStack.emplace(newContextStack);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ReceiveByStampTaskResult> AsyncReceiveByStampTaskResult;

} }

#endif //GS2_MISSION_CONTROL_RECEIVEBYSTAMPTASKRESULT_HPP_