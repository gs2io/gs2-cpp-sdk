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

#ifndef GS2_ACCOUNT_CONTROL_CREATETAKEOVERRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_CREATETAKEOVERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/account/model/model.hpp>
#include <memory>

namespace gs2 { namespace account
{

/**
 * 引き継ぎ設定を新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateTakeOverResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成した引き継ぎ設定 */
        optional<TakeOver> item;

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
    CreateTakeOverResult() = default;
    CreateTakeOverResult(const CreateTakeOverResult& createTakeOverResult) = default;
    CreateTakeOverResult(CreateTakeOverResult&& createTakeOverResult) = default;
    ~CreateTakeOverResult() = default;

    CreateTakeOverResult& operator=(const CreateTakeOverResult& createTakeOverResult) = default;
    CreateTakeOverResult& operator=(CreateTakeOverResult&& createTakeOverResult) = default;

    CreateTakeOverResult deepCopy() const;

    const CreateTakeOverResult* operator->() const
    {
        return this;
    }

    CreateTakeOverResult* operator->()
    {
        return this;
    }
    /**
     * 作成した引き継ぎ設定を取得
     *
     * @return 作成した引き継ぎ設定
     */
    const optional<TakeOver>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成した引き継ぎ設定を設定
     *
     * @param item 作成した引き継ぎ設定
     */
    void setItem(TakeOver item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CreateTakeOverResult> AsyncCreateTakeOverResult;

} }

#endif //GS2_ACCOUNT_CONTROL_CREATETAKEOVERRESULT_HPP_