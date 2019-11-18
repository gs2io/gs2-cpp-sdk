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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/distributor/model/model.hpp>
#include <memory>

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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            contextStack(data.contextStack),
            result(data.result)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "contextStack") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->contextStack.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "result") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->result.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RunStampTaskResult() = default;
    RunStampTaskResult(const RunStampTaskResult& runStampTaskResult) = default;
    RunStampTaskResult(RunStampTaskResult&& runStampTaskResult) = default;
    ~RunStampTaskResult() = default;

    RunStampTaskResult& operator=(const RunStampTaskResult& runStampTaskResult) = default;
    RunStampTaskResult& operator=(RunStampTaskResult&& runStampTaskResult) = default;

    RunStampTaskResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RunStampTaskResult);
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
    void setContextStack(StringHolder contextStack)
    {
        ensureData().contextStack.emplace(std::move(contextStack));
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
    void setResult(StringHolder result)
    {
        ensureData().result.emplace(std::move(result));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<RunStampTaskResult> AsyncRunStampTaskResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_RUNSTAMPTASKRESULT_HPP_