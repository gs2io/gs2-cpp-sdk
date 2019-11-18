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

#ifndef GS2_JOBQUEUE_CONTROL_RUNRESULT_HPP_
#define GS2_JOBQUEUE_CONTROL_RUNRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/jobQueue/model/model.hpp>
#include <memory>

namespace gs2 { namespace jobQueue
{

/**
 * ジョブを実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RunResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ジョブ */
        optional<Job> item;
        /** ジョブの実行結果 */
        optional<JobResultBody> result;
        /** None */
        optional<Bool> isLastJob;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            isLastJob(data.isLastJob)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
            if (data.result)
            {
                result = data.result->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "result") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->result.emplace();
                    detail::json::JsonParser::parse(&this->result->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "isLastJob") == 0)
            {
                if (jsonValue.IsBool())
                {
                    this->isLastJob = jsonValue.GetBool();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RunResult() = default;
    RunResult(const RunResult& runResult) = default;
    RunResult(RunResult&& runResult) = default;
    ~RunResult() = default;

    RunResult& operator=(const RunResult& runResult) = default;
    RunResult& operator=(RunResult&& runResult) = default;

    RunResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RunResult);
    }

    const RunResult* operator->() const
    {
        return this;
    }

    RunResult* operator->()
    {
        return this;
    }
    /**
     * ジョブを取得
     *
     * @return ジョブ
     */
    const optional<Job>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ジョブを設定
     *
     * @param item ジョブ
     */
    void setItem(Job item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * ジョブの実行結果を取得
     *
     * @return ジョブの実行結果
     */
    const optional<JobResultBody>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * ジョブの実行結果を設定
     *
     * @param result ジョブの実行結果
     */
    void setResult(JobResultBody result)
    {
        ensureData().result.emplace(std::move(result));
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Bool>& getIsLastJob() const
    {
        return ensureData().isLastJob;
    }

    /**
     * Noneを設定
     *
     * @param isLastJob None
     */
    void setIsLastJob(Bool isLastJob)
    {
        ensureData().isLastJob.emplace(isLastJob);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<RunResult> AsyncRunResult;

} }

#endif //GS2_JOBQUEUE_CONTROL_RUNRESULT_HPP_