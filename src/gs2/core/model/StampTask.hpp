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

#ifndef GS2_CORE_MODEL_STAMPTASK_HPP_
#define GS2_CORE_MODEL_STAMPTASK_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

GS2_START_OF_NAMESPACE

/**
 * スタンプシートタスク
 *
 * @author Game Server Services, Inc.
 *
 */
class StampTask : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アクション名 */
        optional<StringHolder> action;
        /** スタンプシートタスクデータ */
        optional<StringHolder> task;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            action(data.action),
            task(data.task)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            action(std::move(data.action)),
            task(std::move(data.task))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "action") == 0) {
                if (jsonValue.IsString())
                {
                    this->action.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "task") == 0) {
                if (jsonValue.IsString())
                {
                    this->task.emplace(jsonValue.GetString());
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
    StampTask() :
        m_pData(nullptr)
    {}

    StampTask(const StampTask& stampTask) :
        Gs2Object(stampTask),
        m_pData(stampTask.m_pData != nullptr ? new Data(*stampTask.m_pData) : nullptr)
    {}

    StampTask(StampTask&& stampTask) :
        Gs2Object(std::move(stampTask)),
        m_pData(stampTask.m_pData)
    {
        stampTask.m_pData = nullptr;
    }

    ~StampTask()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    StampTask& operator=(const StampTask& stampTask)
    {
        Gs2Object::operator=(stampTask);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*stampTask.m_pData);

        return *this;
    }

    StampTask& operator=(StampTask&& stampTask)
    {
        Gs2Object::operator=(std::move(stampTask));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = stampTask.m_pData;
        stampTask.m_pData = nullptr;

        return *this;
    }

    const StampTask* operator->() const
    {
        return this;
    }

    StampTask* operator->()
    {
        return this;
    }


    /**
     * アクション名を取得
     *
     * @return アクション名
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * アクション名を設定
     *
     * @param action アクション名
     */
    void setAction(const Char* action)
    {
        ensureData().action.emplace(action);
    }

    /**
     * スタンプシートタスクデータを取得
     *
     * @return スタンプシートタスクデータ
     */
    const optional<StringHolder>& getTask() const
    {
        return ensureData().task;
    }

    /**
     * スタンプシートタスクデータを設定
     *
     * @param task スタンプシートタスクデータ
     */
    void setTask(const Char* task)
    {
        ensureData().task.emplace(task);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_MODEL_STAMPTASK_HPP_