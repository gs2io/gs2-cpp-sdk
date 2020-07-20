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

#ifndef GS2_DISTRIBUTOR_CONTROL_RUNWITHOUTNAMESPACERESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_RUNWITHOUTNAMESPACERESULT_HPP_

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
 * スタンプタスクおよびスタンプシートを実行する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RunWithoutNamespaceResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプタスクの実行結果 */
        optional<List<StringHolder>> taskResults;
        /** スタンプシートの実行結果レスポンス内容 */
        optional<StringHolder> sheetResult;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            sheetResult(data.sheetResult)
        {
            if (data.taskResults)
            {
                taskResults = data.taskResults->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "taskResults") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->taskResults.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->taskResults += std::move(stringHolder);
                    }
                }
            }
            else if (std::strcmp(name_, "sheetResult") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->sheetResult.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RunWithoutNamespaceResult() = default;
    RunWithoutNamespaceResult(const RunWithoutNamespaceResult& runWithoutNamespaceResult) = default;
    RunWithoutNamespaceResult(RunWithoutNamespaceResult&& runWithoutNamespaceResult) = default;
    ~RunWithoutNamespaceResult() = default;

    RunWithoutNamespaceResult& operator=(const RunWithoutNamespaceResult& runWithoutNamespaceResult) = default;
    RunWithoutNamespaceResult& operator=(RunWithoutNamespaceResult&& runWithoutNamespaceResult) = default;

    RunWithoutNamespaceResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RunWithoutNamespaceResult);
    }

    const RunWithoutNamespaceResult* operator->() const
    {
        return this;
    }

    RunWithoutNamespaceResult* operator->()
    {
        return this;
    }
    /**
     * スタンプタスクの実行結果を取得
     *
     * @return スタンプタスクの実行結果
     */
    const optional<List<StringHolder>>& getTaskResults() const
    {
        return ensureData().taskResults;
    }

    /**
     * スタンプタスクの実行結果を設定
     *
     * @param taskResults スタンプタスクの実行結果
     */
    void setTaskResults(List<StringHolder> taskResults)
    {
        ensureData().taskResults.emplace(std::move(taskResults));
    }

    /**
     * スタンプシートの実行結果レスポンス内容を取得
     *
     * @return スタンプシートの実行結果レスポンス内容
     */
    const optional<StringHolder>& getSheetResult() const
    {
        return ensureData().sheetResult;
    }

    /**
     * スタンプシートの実行結果レスポンス内容を設定
     *
     * @param sheetResult スタンプシートの実行結果レスポンス内容
     */
    void setSheetResult(StringHolder sheetResult)
    {
        ensureData().sheetResult.emplace(std::move(sheetResult));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<RunWithoutNamespaceResult> AsyncRunWithoutNamespaceResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_RUNWITHOUTNAMESPACERESULT_HPP_