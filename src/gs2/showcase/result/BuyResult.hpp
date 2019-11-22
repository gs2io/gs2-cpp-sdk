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

#ifndef GS2_SHOWCASE_CONTROL_BUYRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_BUYRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/showcase/model/model.hpp>
#include <memory>

namespace gs2 { namespace showcase
{

/**
 * 陳列棚を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class BuyResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品 */
        optional<SalesItem> item;
        /** 購入処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;

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
    BuyResult() = default;
    BuyResult(const BuyResult& buyResult) = default;
    BuyResult(BuyResult&& buyResult) = default;
    ~BuyResult() = default;

    BuyResult& operator=(const BuyResult& buyResult) = default;
    BuyResult& operator=(BuyResult&& buyResult) = default;

    BuyResult deepCopy() const;

    const BuyResult* operator->() const
    {
        return this;
    }

    BuyResult* operator->()
    {
        return this;
    }
    /**
     * 商品を取得
     *
     * @return 商品
     */
    const optional<SalesItem>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 商品を設定
     *
     * @param item 商品
     */
    void setItem(SalesItem item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 購入処理の実行に使用するスタンプシートを取得
     *
     * @return 購入処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 購入処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet 購入処理の実行に使用するスタンプシート
     */
    void setStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<BuyResult> AsyncBuyResult;

} }

#endif //GS2_SHOWCASE_CONTROL_BUYRESULT_HPP_