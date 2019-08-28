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

#ifndef GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETRESULT_HPP_

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
 * スタンプシートの完了を報告する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RunStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レスポンス内容 */
        optional<StringHolder> result;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            result(data.result)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            result(std::move(data.result))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "result") == 0) {
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
    RunStampSheetResult() :
        m_pData(nullptr)
    {}

    RunStampSheetResult(const RunStampSheetResult& runStampSheetResult) :
        Gs2Object(runStampSheetResult),
        m_pData(runStampSheetResult.m_pData != nullptr ? new Data(*runStampSheetResult.m_pData) : nullptr)
    {}

    RunStampSheetResult(RunStampSheetResult&& runStampSheetResult) :
        Gs2Object(std::move(runStampSheetResult)),
        m_pData(runStampSheetResult.m_pData)
    {
        runStampSheetResult.m_pData = nullptr;
    }

    ~RunStampSheetResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RunStampSheetResult& operator=(const RunStampSheetResult& runStampSheetResult)
    {
        Gs2Object::operator=(runStampSheetResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*runStampSheetResult.m_pData);

        return *this;
    }

    RunStampSheetResult& operator=(RunStampSheetResult&& runStampSheetResult)
    {
        Gs2Object::operator=(std::move(runStampSheetResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = runStampSheetResult.m_pData;
        runStampSheetResult.m_pData = nullptr;

        return *this;
    }

    const RunStampSheetResult* operator->() const
    {
        return this;
    }

    RunStampSheetResult* operator->()
    {
        return this;
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

typedef AsyncResult<RunStampSheetResult> AsyncRunStampSheetResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_RUNSTAMPSHEETRESULT_HPP_