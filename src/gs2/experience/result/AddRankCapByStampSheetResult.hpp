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

#ifndef GS2_EXPERIENCE_CONTROL_ADDRANKCAPBYSTAMPSHEETRESULT_HPP_
#define GS2_EXPERIENCE_CONTROL_ADDRANKCAPBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ランクキャップを加算 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class AddRankCapByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 加算後のステータス */
        optional<Status> item;

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
    AddRankCapByStampSheetResult() :
        m_pData(nullptr)
    {}

    AddRankCapByStampSheetResult(const AddRankCapByStampSheetResult& addRankCapByStampSheetResult) :
        Gs2Object(addRankCapByStampSheetResult),
        m_pData(addRankCapByStampSheetResult.m_pData != nullptr ? new Data(*addRankCapByStampSheetResult.m_pData) : nullptr)
    {}

    AddRankCapByStampSheetResult(AddRankCapByStampSheetResult&& addRankCapByStampSheetResult) :
        Gs2Object(std::move(addRankCapByStampSheetResult)),
        m_pData(addRankCapByStampSheetResult.m_pData)
    {
        addRankCapByStampSheetResult.m_pData = nullptr;
    }

    ~AddRankCapByStampSheetResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AddRankCapByStampSheetResult& operator=(const AddRankCapByStampSheetResult& addRankCapByStampSheetResult)
    {
        Gs2Object::operator=(addRankCapByStampSheetResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*addRankCapByStampSheetResult.m_pData);

        return *this;
    }

    AddRankCapByStampSheetResult& operator=(AddRankCapByStampSheetResult&& addRankCapByStampSheetResult)
    {
        Gs2Object::operator=(std::move(addRankCapByStampSheetResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = addRankCapByStampSheetResult.m_pData;
        addRankCapByStampSheetResult.m_pData = nullptr;

        return *this;
    }

    const AddRankCapByStampSheetResult* operator->() const
    {
        return this;
    }

    AddRankCapByStampSheetResult* operator->()
    {
        return this;
    }
    /**
     * 加算後のステータスを取得
     *
     * @return 加算後のステータス
     */
    const optional<Status>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 加算後のステータスを設定
     *
     * @param item 加算後のステータス
     */
    void setItem(const Status& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_ADDRANKCAPBYSTAMPSHEETRESULT_HPP_