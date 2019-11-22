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

#ifndef GS2_STAMINA_CONTROL_CONSUMESTAMINABYUSERIDRESULT_HPP_
#define GS2_STAMINA_CONTROL_CONSUMESTAMINABYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/stamina/model/model.hpp>
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * ユーザIDを指定してスタミナを消費 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ConsumeStaminaByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ */
        optional<Stamina> item;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ConsumeStaminaByUserIdResult() = default;
    ConsumeStaminaByUserIdResult(const ConsumeStaminaByUserIdResult& consumeStaminaByUserIdResult) = default;
    ConsumeStaminaByUserIdResult(ConsumeStaminaByUserIdResult&& consumeStaminaByUserIdResult) = default;
    ~ConsumeStaminaByUserIdResult() = default;

    ConsumeStaminaByUserIdResult& operator=(const ConsumeStaminaByUserIdResult& consumeStaminaByUserIdResult) = default;
    ConsumeStaminaByUserIdResult& operator=(ConsumeStaminaByUserIdResult&& consumeStaminaByUserIdResult) = default;

    ConsumeStaminaByUserIdResult deepCopy() const;

    const ConsumeStaminaByUserIdResult* operator->() const
    {
        return this;
    }

    ConsumeStaminaByUserIdResult* operator->()
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ConsumeStaminaByUserIdResult> AsyncConsumeStaminaByUserIdResult;

} }

#endif //GS2_STAMINA_CONTROL_CONSUMESTAMINABYUSERIDRESULT_HPP_