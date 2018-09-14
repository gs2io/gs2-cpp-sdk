/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace jobQueue
{

/**
 * @author Game Server Services, Inc.
 */
class RunResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ジョブ結果 */
        optional<JobResult> item;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
    RunResult() :
        m_pData(nullptr)
    {}

    RunResult(const RunResult& runResult) :
        Gs2Object(runResult),
        m_pData(runResult.m_pData != nullptr ? new Data(*runResult.m_pData) : nullptr)
    {}

    RunResult(RunResult&& runResult) :
        Gs2Object(std::move(runResult)),
        m_pData(runResult.m_pData)
    {
        runResult.m_pData = nullptr;
    }

    ~RunResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RunResult& operator=(const RunResult& runResult)
    {
        Gs2Object::operator=(runResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*runResult.m_pData);

        return *this;
    }

    RunResult& operator=(RunResult&& runResult)
    {
        Gs2Object::operator=(std::move(runResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = runResult.m_pData;
        runResult.m_pData = nullptr;

        return *this;
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
     * ジョブ結果を取得
     *
     * @return ジョブ結果
     */
    const optional<JobResult>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ジョブ結果を設定
     *
     * @param item ジョブ結果
     */
    void setItem(const JobResult& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_JOBQUEUE_CONTROL_RUNRESULT_HPP_