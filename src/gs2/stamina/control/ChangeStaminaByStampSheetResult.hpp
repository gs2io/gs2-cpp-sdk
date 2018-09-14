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

#ifndef GS2_STAMINA_CONTROL_CHANGESTAMINABYSTAMPSHEETRESULT_HPP_
#define GS2_STAMINA_CONTROL_CHANGESTAMINABYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * @author Game Server Services, Inc.
 */
class ChangeStaminaByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ */
        optional<Stamina> item;
        /** 次にスタミナが回復する時間 */
        optional<Int32> nextIncreaseTimestamp;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            nextIncreaseTimestamp(data.nextIncreaseTimestamp)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            nextIncreaseTimestamp(std::move(data.nextIncreaseTimestamp))
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
            else if (std::strcmp(name, "nextIncreaseTimestamp") == 0) {
                if (jsonValue.IsInt())
                {
                    this->nextIncreaseTimestamp = jsonValue.GetInt();
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
    ChangeStaminaByStampSheetResult() :
        m_pData(nullptr)
    {}

    ChangeStaminaByStampSheetResult(const ChangeStaminaByStampSheetResult& changeStaminaByStampSheetResult) :
        Gs2Object(changeStaminaByStampSheetResult),
        m_pData(changeStaminaByStampSheetResult.m_pData != nullptr ? new Data(*changeStaminaByStampSheetResult.m_pData) : nullptr)
    {}

    ChangeStaminaByStampSheetResult(ChangeStaminaByStampSheetResult&& changeStaminaByStampSheetResult) :
        Gs2Object(std::move(changeStaminaByStampSheetResult)),
        m_pData(changeStaminaByStampSheetResult.m_pData)
    {
        changeStaminaByStampSheetResult.m_pData = nullptr;
    }

    ~ChangeStaminaByStampSheetResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ChangeStaminaByStampSheetResult& operator=(const ChangeStaminaByStampSheetResult& changeStaminaByStampSheetResult)
    {
        Gs2Object::operator=(changeStaminaByStampSheetResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*changeStaminaByStampSheetResult.m_pData);

        return *this;
    }

    ChangeStaminaByStampSheetResult& operator=(ChangeStaminaByStampSheetResult&& changeStaminaByStampSheetResult)
    {
        Gs2Object::operator=(std::move(changeStaminaByStampSheetResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = changeStaminaByStampSheetResult.m_pData;
        changeStaminaByStampSheetResult.m_pData = nullptr;

        return *this;
    }

    const ChangeStaminaByStampSheetResult* operator->() const
    {
        return this;
    }

    ChangeStaminaByStampSheetResult* operator->()
    {
        return this;
    }


    /**
     * スタミナを取得
     *
     * @return スタミナ
     */
    const optional<Stamina>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * スタミナを設定
     *
     * @param item スタミナ
     */
    void setItem(const Stamina& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * 次にスタミナが回復する時間を取得
     *
     * @return 次にスタミナが回復する時間
     */
    const optional<Int32>& getNextIncreaseTimestamp() const
    {
        return ensureData().nextIncreaseTimestamp;
    }

    /**
     * 次にスタミナが回復する時間を設定
     *
     * @param nextIncreaseTimestamp 次にスタミナが回復する時間
     */
    void setNextIncreaseTimestamp(Int32 nextIncreaseTimestamp)
    {
        ensureData().nextIncreaseTimestamp.emplace(nextIncreaseTimestamp);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_CONTROL_CHANGESTAMINABYSTAMPSHEETRESULT_HPP_