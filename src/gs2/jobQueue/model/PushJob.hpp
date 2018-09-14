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

#ifndef GS2_JOBQUEUE_MODEL_PUSHJOB_HPP_
#define GS2_JOBQUEUE_MODEL_PUSHJOB_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

/**
 * キューに追加するジョブ
 *
 * @author Game Server Services, Inc.
 *
 */
class PushJob : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スクリプト名 */
        optional<StringHolder> scriptName;
        /** 引数 */
        optional<StringHolder> args;
        /** 最大リトライ回数 */
        optional<Int32> maxRetry;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            scriptName(data.scriptName),
            args(data.args),
            maxRetry(data.maxRetry)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            scriptName(std::move(data.scriptName)),
            args(std::move(data.args)),
            maxRetry(std::move(data.maxRetry))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "scriptName") == 0) {
                if (jsonValue.IsString())
                {
                    this->scriptName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "args") == 0) {
                if (jsonValue.IsString())
                {
                    this->args.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "maxRetry") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxRetry = jsonValue.GetInt();
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
    PushJob() :
        m_pData(nullptr)
    {}

    PushJob(const PushJob& pushJob) :
        Gs2Object(pushJob),
        m_pData(pushJob.m_pData != nullptr ? new Data(*pushJob.m_pData) : nullptr)
    {}

    PushJob(PushJob&& pushJob) :
        Gs2Object(std::move(pushJob)),
        m_pData(pushJob.m_pData)
    {
        pushJob.m_pData = nullptr;
    }

    ~PushJob()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PushJob& operator=(const PushJob& pushJob)
    {
        Gs2Object::operator=(pushJob);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*pushJob.m_pData);

        return *this;
    }

    PushJob& operator=(PushJob&& pushJob)
    {
        Gs2Object::operator=(std::move(pushJob));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = pushJob.m_pData;
        pushJob.m_pData = nullptr;

        return *this;
    }

    const PushJob* operator->() const
    {
        return this;
    }

    PushJob* operator->()
    {
        return this;
    }


    /**
     * スクリプト名を取得
     *
     * @return スクリプト名
     */
    const optional<StringHolder>& getScriptName() const
    {
        return ensureData().scriptName;
    }

    /**
     * スクリプト名を設定
     *
     * @param scriptName スクリプト名
     */
    void setScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
    }

    /**
     * 引数を取得
     *
     * @return 引数
     */
    const optional<StringHolder>& getArgs() const
    {
        return ensureData().args;
    }

    /**
     * 引数を設定
     *
     * @param args 引数
     */
    void setArgs(const Char* args)
    {
        ensureData().args.emplace(args);
    }

    /**
     * 最大リトライ回数を取得
     *
     * @return 最大リトライ回数
     */
    const optional<Int32>& getMaxRetry() const
    {
        return ensureData().maxRetry;
    }

    /**
     * 最大リトライ回数を設定
     *
     * @param maxRetry 最大リトライ回数
     */
    void setMaxRetry(Int32 maxRetry)
    {
        ensureData().maxRetry.emplace(maxRetry);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_JOBQUEUE_MODEL_PUSHJOB_HPP_