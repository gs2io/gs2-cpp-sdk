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

#ifndef GS2_STAMINA_CONTROL_RECOVERSTAMINABYUSERIDRESULT_HPP_
#define GS2_STAMINA_CONTROL_RECOVERSTAMINABYUSERIDRESULT_HPP_

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
 * ユーザIDを指定してスタミナを回復 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RecoverStaminaByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ */
        optional<Stamina> item;
        /** スタミナ値の上限を超えて受け取れずに GS2-Inbox に転送したスタミナ値 */
        optional<Int64> overflowValue;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            overflowValue(data.overflowValue)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
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
            else if (std::strcmp(name_, "overflowValue") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->overflowValue = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RecoverStaminaByUserIdResult() = default;
    RecoverStaminaByUserIdResult(const RecoverStaminaByUserIdResult& recoverStaminaByUserIdResult) = default;
    RecoverStaminaByUserIdResult(RecoverStaminaByUserIdResult&& recoverStaminaByUserIdResult) = default;
    ~RecoverStaminaByUserIdResult() = default;

    RecoverStaminaByUserIdResult& operator=(const RecoverStaminaByUserIdResult& recoverStaminaByUserIdResult) = default;
    RecoverStaminaByUserIdResult& operator=(RecoverStaminaByUserIdResult&& recoverStaminaByUserIdResult) = default;

    RecoverStaminaByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RecoverStaminaByUserIdResult);
    }

    const RecoverStaminaByUserIdResult* operator->() const
    {
        return this;
    }

    RecoverStaminaByUserIdResult* operator->()
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

typedef AsyncResult<RecoverStaminaByUserIdResult> AsyncRecoverStaminaByUserIdResult;

} }

#endif //GS2_STAMINA_CONTROL_RECOVERSTAMINABYUSERIDRESULT_HPP_