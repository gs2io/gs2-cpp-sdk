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

#ifndef GS2_QUEST_CONTROL_STARTRESULT_HPP_
#define GS2_QUEST_CONTROL_STARTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * クエストを開始 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class StartResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストの開始処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            stampSheet(std::move(data.stampSheet))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "stampSheet") == 0) {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
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
    StartResult() :
        m_pData(nullptr)
    {}

    StartResult(const StartResult& startResult) :
        Gs2Object(startResult),
        m_pData(startResult.m_pData != nullptr ? new Data(*startResult.m_pData) : nullptr)
    {}

    StartResult(StartResult&& startResult) :
        Gs2Object(std::move(startResult)),
        m_pData(startResult.m_pData)
    {
        startResult.m_pData = nullptr;
    }

    ~StartResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    StartResult& operator=(const StartResult& startResult)
    {
        Gs2Object::operator=(startResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*startResult.m_pData);

        return *this;
    }

    StartResult& operator=(StartResult&& startResult)
    {
        Gs2Object::operator=(std::move(startResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = startResult.m_pData;
        startResult.m_pData = nullptr;

        return *this;
    }

    const StartResult* operator->() const
    {
        return this;
    }

    StartResult* operator->()
    {
        return this;
    }
    /**
     * クエストの開始処理の実行に使用するスタンプシートを取得
     *
     * @return クエストの開始処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * クエストの開始処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet クエストの開始処理の実行に使用するスタンプシート
     */
    void setStampSheet(const Char* stampSheet)
    {
        ensureData().stampSheet.emplace(stampSheet);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_QUEST_CONTROL_STARTRESULT_HPP_