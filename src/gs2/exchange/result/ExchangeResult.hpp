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

#ifndef GS2_EXCHANGE_CONTROL_EXCHANGERESULT_HPP_
#define GS2_EXCHANGE_CONTROL_EXCHANGERESULT_HPP_

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
 * 交換を実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ExchangeResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換レートモデル */
        optional<RateModel> item;
        /** 交換処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;
        /** スタンプシートの署名計算に使用した暗号鍵GRN */
        optional<StringHolder> stampSheetEncryptionKeyId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet),
            stampSheetEncryptionKeyId(data.stampSheetEncryptionKeyId)
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
            else if (std::strcmp(name_, "stampSheetEncryptionKeyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stampSheetEncryptionKeyId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ExchangeResult() = default;
    ExchangeResult(const ExchangeResult& exchangeResult) = default;
    ExchangeResult(ExchangeResult&& exchangeResult) = default;
    ~ExchangeResult() = default;

    ExchangeResult& operator=(const ExchangeResult& exchangeResult) = default;
    ExchangeResult& operator=(ExchangeResult&& exchangeResult) = default;

    ExchangeResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ExchangeResult);
    }

    const ExchangeResult* operator->() const
    {
        return this;
    }

    ExchangeResult* operator->()
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

    /**
     * スタンプシートの署名計算に使用した暗号鍵GRNを取得
     *
     * @return スタンプシートの署名計算に使用した暗号鍵GRN
     */
    const optional<StringHolder>& getStampSheetEncryptionKeyId() const
    {
        return ensureData().stampSheetEncryptionKeyId;
    }

    /**
     * スタンプシートの署名計算に使用した暗号鍵GRNを設定
     *
     * @param stampSheetEncryptionKeyId スタンプシートの署名計算に使用した暗号鍵GRN
     */
    void setStampSheetEncryptionKeyId(StringHolder stampSheetEncryptionKeyId)
    {
        ensureData().stampSheetEncryptionKeyId.emplace(std::move(stampSheetEncryptionKeyId));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ExchangeResult> AsyncExchangeResult;

} }

#endif //GS2_EXCHANGE_CONTROL_EXCHANGERESULT_HPP_