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

#ifndef GS2_STAMINA_CONTROL_SETRECOVERINTERVALBYSTAMPSHEETRESULT_HPP_
#define GS2_STAMINA_CONTROL_SETRECOVERINTERVALBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/stamina/model/model.hpp>
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * スタンプシートでスタミナの最大値を更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class SetRecoverIntervalByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ */
        optional<Stamina> item;
        /** スタミナモデル */
        optional<StaminaModel> staminaModel;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
            if (data.staminaModel)
            {
                staminaModel = data.staminaModel->deepCopy();
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
            else if (std::strcmp(name_, "staminaModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->staminaModel.emplace();
                    detail::json::JsonParser::parse(&this->staminaModel->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SetRecoverIntervalByStampSheetResult() = default;
    SetRecoverIntervalByStampSheetResult(const SetRecoverIntervalByStampSheetResult& setRecoverIntervalByStampSheetResult) = default;
    SetRecoverIntervalByStampSheetResult(SetRecoverIntervalByStampSheetResult&& setRecoverIntervalByStampSheetResult) = default;
    ~SetRecoverIntervalByStampSheetResult() = default;

    SetRecoverIntervalByStampSheetResult& operator=(const SetRecoverIntervalByStampSheetResult& setRecoverIntervalByStampSheetResult) = default;
    SetRecoverIntervalByStampSheetResult& operator=(SetRecoverIntervalByStampSheetResult&& setRecoverIntervalByStampSheetResult) = default;

    SetRecoverIntervalByStampSheetResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SetRecoverIntervalByStampSheetResult);
    }

    const SetRecoverIntervalByStampSheetResult* operator->() const
    {
        return this;
    }

    SetRecoverIntervalByStampSheetResult* operator->()
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
    void setItem(Stamina item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * スタミナモデルを取得
     *
     * @return スタミナモデル
     */
    const optional<StaminaModel>& getStaminaModel() const
    {
        return ensureData().staminaModel;
    }

    /**
     * スタミナモデルを設定
     *
     * @param staminaModel スタミナモデル
     */
    void setStaminaModel(StaminaModel staminaModel)
    {
        ensureData().staminaModel.emplace(std::move(staminaModel));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<SetRecoverIntervalByStampSheetResult> AsyncSetRecoverIntervalByStampSheetResult;

} }

#endif //GS2_STAMINA_CONTROL_SETRECOVERINTERVALBYSTAMPSHEETRESULT_HPP_