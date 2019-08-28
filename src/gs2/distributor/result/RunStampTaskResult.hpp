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

#ifndef GS2_DISTRIBUTOR_CONTROL_RUNSTAMPTASKRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_RUNSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * スタンプシートのタスクを実行する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RunStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** タスクの実行結果を反映したコンテキストスタック */
        optional<StringHolder> contextStack;
        /** レスポンス内容 */
        optional<StringHolder> result;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            contextStack(data.contextStack),
            result(data.result)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            contextStack(std::move(data.contextStack)),
            result(std::move(data.result))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "contextStack") == 0) {
                if (jsonValue.IsString())
                {
                    this->contextStack.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "result") == 0) {
                if (jsonValue.IsString())
                {
                    this->result.emplace(jsonValue.GetString());
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
    RunStampTaskResult() :
        m_pData(nullptr)
    {}

    RunStampTaskResult(const RunStampTaskResult& runStampTaskResult) :
        Gs2Object(runStampTaskResult),
        m_pData(runStampTaskResult.m_pData != nullptr ? new Data(*runStampTaskResult.m_pData) : nullptr)
    {}

    RunStampTaskResult(RunStampTaskResult&& runStampTaskResult) :
        Gs2Object(std::move(runStampTaskResult)),
        m_pData(runStampTaskResult.m_pData)
    {
        runStampTaskResult.m_pData = nullptr;
    }

    ~RunStampTaskResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RunStampTaskResult& operator=(const RunStampTaskResult& runStampTaskResult)
    {
        Gs2Object::operator=(runStampTaskResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*runStampTaskResult.m_pData);

        return *this;
    }

    RunStampTaskResult& operator=(RunStampTaskResult&& runStampTaskResult)
    {
        Gs2Object::operator=(std::move(runStampTaskResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = runStampTaskResult.m_pData;
        runStampTaskResult.m_pData = nullptr;

        return *this;
    }

    const RunStampTaskResult* operator->() const
    {
        return this;
    }

    RunStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * タスクの実行結果を反映したコンテキストスタックを取得
     *
     * @return タスクの実行結果を反映したコンテキストスタック
     */
    const optional<StringHolder>& getContextStack() const
    {
        return ensureData().contextStack;
    }

    /**
     * タスクの実行結果を反映したコンテキストスタックを設定
     *
     * @param contextStack タスクの実行結果を反映したコンテキストスタック
     */
    void setContextStack(const Char* contextStack)
    {
        ensureData().contextStack.emplace(contextStack);
    }

    /**
     * レスポンス内容を取得
     *
     * @return レスポンス内容
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * レスポンス内容を設定
     *
     * @param result レスポンス内容
     */
    void setResult(const Char* result)
    {
        ensureData().result.emplace(result);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<RunStampTaskResult> AsyncRunStampTaskResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_RUNSTAMPTASKRESULT_HPP_