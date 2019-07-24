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

#ifndef GS2_JOBQUEUE_CONTROL_RUNBYUSERIDRESULT_HPP_
#define GS2_JOBQUEUE_CONTROL_RUNBYUSERIDRESULT_HPP_

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
 * ユーザIDを指定してジョブを実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RunByUserIdResult : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            result(data.result),
            isLastJob(data.isLastJob)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            result(std::move(data.result)),
            isLastJob(std::move(data.isLastJob))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "result") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->result.emplace();
                    detail::json::JsonParser::parse(&this->result->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "isLastJob") == 0) {
                if (jsonValue.IsBool())
                {
                    this->isLastJob = jsonValue.GetBool();
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
    RunByUserIdResult() :
        m_pData(nullptr)
    {}

    RunByUserIdResult(const RunByUserIdResult& runByUserIdResult) :
        Gs2Object(runByUserIdResult),
        m_pData(runByUserIdResult.m_pData != nullptr ? new Data(*runByUserIdResult.m_pData) : nullptr)
    {}

    RunByUserIdResult(RunByUserIdResult&& runByUserIdResult) :
        Gs2Object(std::move(runByUserIdResult)),
        m_pData(runByUserIdResult.m_pData)
    {
        runByUserIdResult.m_pData = nullptr;
    }

    ~RunByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RunByUserIdResult& operator=(const RunByUserIdResult& runByUserIdResult)
    {
        Gs2Object::operator=(runByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*runByUserIdResult.m_pData);

        return *this;
    }

    RunByUserIdResult& operator=(RunByUserIdResult&& runByUserIdResult)
    {
        Gs2Object::operator=(std::move(runByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = runByUserIdResult.m_pData;
        runByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const RunByUserIdResult* operator->() const
    {
        return this;
    }

    RunByUserIdResult* operator->()
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
    void setItem(const Job& item)
    {
        ensureData().item.emplace(item);
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
    void setResult(const JobResultBody& result)
    {
        ensureData().result.emplace(result);
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

} }

#endif //GS2_JOBQUEUE_CONTROL_RUNBYUSERIDRESULT_HPP_