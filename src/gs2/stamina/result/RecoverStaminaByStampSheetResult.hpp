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

#ifndef GS2_STAMINA_CONTROL_RECOVERSTAMINABYSTAMPSHEETRESULT_HPP_
#define GS2_STAMINA_CONTROL_RECOVERSTAMINABYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタンプシートを使用してスタミナを回復 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RecoverStaminaByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ */
        optional<Stamina> item;
        /** スタミナ値の上限を超えて受け取れずに GS2-Inbox に転送したスタミナ値 */
        optional<Int64> overflowValue;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            overflowValue(data.overflowValue)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            overflowValue(std::move(data.overflowValue))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "overflowValue") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->overflowValue = jsonValue.GetInt64();
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
    RecoverStaminaByStampSheetResult() :
        m_pData(nullptr)
    {}

    RecoverStaminaByStampSheetResult(const RecoverStaminaByStampSheetResult& recoverStaminaByStampSheetResult) :
        Gs2Object(recoverStaminaByStampSheetResult),
        m_pData(recoverStaminaByStampSheetResult.m_pData != nullptr ? new Data(*recoverStaminaByStampSheetResult.m_pData) : nullptr)
    {}

    RecoverStaminaByStampSheetResult(RecoverStaminaByStampSheetResult&& recoverStaminaByStampSheetResult) :
        Gs2Object(std::move(recoverStaminaByStampSheetResult)),
        m_pData(recoverStaminaByStampSheetResult.m_pData)
    {
        recoverStaminaByStampSheetResult.m_pData = nullptr;
    }

    ~RecoverStaminaByStampSheetResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RecoverStaminaByStampSheetResult& operator=(const RecoverStaminaByStampSheetResult& recoverStaminaByStampSheetResult)
    {
        Gs2Object::operator=(recoverStaminaByStampSheetResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*recoverStaminaByStampSheetResult.m_pData);

        return *this;
    }

    RecoverStaminaByStampSheetResult& operator=(RecoverStaminaByStampSheetResult&& recoverStaminaByStampSheetResult)
    {
        Gs2Object::operator=(std::move(recoverStaminaByStampSheetResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = recoverStaminaByStampSheetResult.m_pData;
        recoverStaminaByStampSheetResult.m_pData = nullptr;

        return *this;
    }

    const RecoverStaminaByStampSheetResult* operator->() const
    {
        return this;
    }

    RecoverStaminaByStampSheetResult* operator->()
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
     * スタミナ値の上限を超えて受け取れずに GS2-Inbox に転送したスタミナ値を取得
     *
     * @return スタミナ値の上限を超えて受け取れずに GS2-Inbox に転送したスタミナ値
     */
    const optional<Int64>& getOverflowValue() const
    {
        return ensureData().overflowValue;
    }

    /**
     * スタミナ値の上限を超えて受け取れずに GS2-Inbox に転送したスタミナ値を設定
     *
     * @param overflowValue スタミナ値の上限を超えて受け取れずに GS2-Inbox に転送したスタミナ値
     */
    void setOverflowValue(Int64 overflowValue)
    {
        ensureData().overflowValue.emplace(overflowValue);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<RecoverStaminaByStampSheetResult> AsyncRecoverStaminaByStampSheetResult;

} }

#endif //GS2_STAMINA_CONTROL_RECOVERSTAMINABYSTAMPSHEETRESULT_HPP_