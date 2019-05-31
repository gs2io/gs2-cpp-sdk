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

#ifndef GS2_CORE_MODEL_STAMPSHEET_HPP_
#define GS2_CORE_MODEL_STAMPSHEET_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>
#include "StampTask.hpp"

GS2_START_OF_NAMESPACE

/**
 * スタンプシート
 *
 * @author Game Server Services, Inc.
 *
 */
class StampSheet : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプシートデータ */
        optional<StringHolder> sheet;
        /**  */
        optional<List<StampTask>> tasks;
        /** スタンプシート関連の処理の実行で使用するトランザクションID */
        optional<StringHolder> transactionId;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            sheet(data.sheet),
            tasks(data.tasks),
            transactionId(data.transactionId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            sheet(std::move(data.sheet)),
            tasks(std::move(data.tasks)),
            transactionId(std::move(data.transactionId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "sheet") == 0) {
                if (jsonValue.IsString())
                {
                    this->sheet.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "tasks") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->tasks.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        StampTask item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->tasks, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "transactionId") == 0) {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
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
    StampSheet() :
        m_pData(nullptr)
    {}

    StampSheet(const StampSheet& stampSheet) :
        Gs2Object(stampSheet),
        m_pData(stampSheet.m_pData != nullptr ? new Data(*stampSheet.m_pData) : nullptr)
    {}

    StampSheet(StampSheet&& stampSheet) :
        Gs2Object(std::move(stampSheet)),
        m_pData(stampSheet.m_pData)
    {
        stampSheet.m_pData = nullptr;
    }

    ~StampSheet()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    StampSheet& operator=(const StampSheet& stampSheet)
    {
        Gs2Object::operator=(stampSheet);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*stampSheet.m_pData);

        return *this;
    }

    StampSheet& operator=(StampSheet&& stampSheet)
    {
        Gs2Object::operator=(std::move(stampSheet));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = stampSheet.m_pData;
        stampSheet.m_pData = nullptr;

        return *this;
    }

    const StampSheet* operator->() const
    {
        return this;
    }

    StampSheet* operator->()
    {
        return this;
    }


    /**
     * スタンプシートデータを取得
     *
     * @return スタンプシートデータ
     */
    const optional<StringHolder>& getSheet() const
    {
        return ensureData().sheet;
    }

    /**
     * スタンプシートデータを設定
     *
     * @param sheet スタンプシートデータ
     */
    void setSheet(const Char* sheet)
    {
        ensureData().sheet.emplace(sheet);
    }

    /**
     * を取得
     *
     * @return 
     */
    const optional<List<StampTask>>& getTasks() const
    {
        return ensureData().tasks;
    }

    /**
     * を設定
     *
     * @param tasks 
     */
    void setTasks(const List<StampTask>& tasks)
    {
        ensureData().tasks.emplace(tasks);
    }

    /**
     * スタンプシート関連の処理の実行で使用するトランザクションIDを取得
     *
     * @return スタンプシート関連の処理の実行で使用するトランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * スタンプシート関連の処理の実行で使用するトランザクションIDを設定
     *
     * @param transactionId スタンプシート関連の処理の実行で使用するトランザクションID
     */
    void setTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_MODEL_STAMPSHEET_HPP_