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

#ifndef GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKRESULT_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/money/model/model.hpp>
#include <memory>

namespace gs2 { namespace money
{

/**
 * ウォレットから残高を消費します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費後のウォレット */
        optional<Wallet> item;
        /** スタンプタスクの実行結果を記録したコンテキスト */
        optional<StringHolder> newContextStack;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            newContextStack(data.newContextStack)
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
            else if (std::strcmp(name_, "newContextStack") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->newContextStack.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    WithdrawByStampTaskResult() = default;
    WithdrawByStampTaskResult(const WithdrawByStampTaskResult& withdrawByStampTaskResult) = default;
    WithdrawByStampTaskResult(WithdrawByStampTaskResult&& withdrawByStampTaskResult) = default;
    ~WithdrawByStampTaskResult() = default;

    WithdrawByStampTaskResult& operator=(const WithdrawByStampTaskResult& withdrawByStampTaskResult) = default;
    WithdrawByStampTaskResult& operator=(WithdrawByStampTaskResult&& withdrawByStampTaskResult) = default;

    WithdrawByStampTaskResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WithdrawByStampTaskResult);
    }

    const WithdrawByStampTaskResult* operator->() const
    {
        return this;
    }

    WithdrawByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * 消費後のウォレットを取得
     *
     * @return 消費後のウォレット
     */
    const optional<Wallet>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 消費後のウォレットを設定
     *
     * @param item 消費後のウォレット
     */
    void setItem(Wallet item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを取得
     *
     * @return スタンプタスクの実行結果を記録したコンテキスト
     */
    const optional<StringHolder>& getNewContextStack() const
    {
        return ensureData().newContextStack;
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを設定
     *
     * @param newContextStack スタンプタスクの実行結果を記録したコンテキスト
     */
    void setNewContextStack(StringHolder newContextStack)
    {
        ensureData().newContextStack.emplace(std::move(newContextStack));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<WithdrawByStampTaskResult> AsyncWithdrawByStampTaskResult;

} }

#endif //GS2_MONEY_CONTROL_WITHDRAWBYSTAMPTASKRESULT_HPP_