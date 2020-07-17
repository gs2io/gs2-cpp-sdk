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

#ifndef GS2_EXCHANGE_CONTROL_EXCHANGEBYSTAMPSHEETRESULT_HPP_
#define GS2_EXCHANGE_CONTROL_EXCHANGEBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/exchange/model/model.hpp>
#include <memory>

namespace gs2 { namespace exchange
{

/**
 * スタンプシートで交換を実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ExchangeByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換レートモデル */
        optional<RateModel> item;
        /** 交換処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet)
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
            else if (std::strcmp(name_, "stampSheet") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ExchangeByStampSheetResult() = default;
    ExchangeByStampSheetResult(const ExchangeByStampSheetResult& exchangeByStampSheetResult) = default;
    ExchangeByStampSheetResult(ExchangeByStampSheetResult&& exchangeByStampSheetResult) = default;
    ~ExchangeByStampSheetResult() = default;

    ExchangeByStampSheetResult& operator=(const ExchangeByStampSheetResult& exchangeByStampSheetResult) = default;
    ExchangeByStampSheetResult& operator=(ExchangeByStampSheetResult&& exchangeByStampSheetResult) = default;

    ExchangeByStampSheetResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ExchangeByStampSheetResult);
    }

    const ExchangeByStampSheetResult* operator->() const
    {
        return this;
    }

    ExchangeByStampSheetResult* operator->()
    {
        return this;
    }
    /**
     * 交換レートモデルを取得
     *
     * @return 交換レートモデル
     */
    const optional<RateModel>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 交換レートモデルを設定
     *
     * @param item 交換レートモデル
     */
    void setItem(RateModel item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 交換処理の実行に使用するスタンプシートを取得
     *
     * @return 交換処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 交換処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet 交換処理の実行に使用するスタンプシート
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

typedef AsyncResult<ExchangeByStampSheetResult> AsyncExchangeByStampSheetResult;

} }

#endif //GS2_EXCHANGE_CONTROL_EXCHANGEBYSTAMPSHEETRESULT_HPP_