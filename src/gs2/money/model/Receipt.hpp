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

#ifndef GS2_MONEY_MODEL_RECEIPT_HPP_
#define GS2_MONEY_MODEL_RECEIPT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace money {

/**
 * レシート
 *
 * @author Game Server Services, Inc.
 *
 */
class Receipt : public Gs2Object
{
    friend bool operator!=(const Receipt& lhs, const Receipt& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** レシート */
        optional<StringHolder> receiptId;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 種類 */
        optional<StringHolder> type;
        /** スロット番号 */
        optional<Int32> slot;
        /** 単価 */
        optional<Float> price;
        /** 有償課金通貨 */
        optional<Int32> paid;
        /** 無償課金通貨 */
        optional<Int32> free;
        /** 総数 */
        optional<Int32> total;
        /** ストアプラットフォームで販売されているコンテンツID */
        optional<StringHolder> contentsId;
        /** 作成日時 */
        optional<Int64> createdAt;

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
    Receipt() = default;
    Receipt(const Receipt& receipt) = default;
    Receipt(Receipt&& receipt) = default;
    ~Receipt() = default;

    Receipt& operator=(const Receipt& receipt) = default;
    Receipt& operator=(Receipt&& receipt) = default;

    Receipt deepCopy() const;

    const Receipt* operator->() const
    {
        return this;
    }

    Receipt* operator->()
    {
        return this;
    }
    /**
     * レシートを取得
     *
     * @return レシート
     */
    const optional<StringHolder>& getReceiptId() const
    {
        return ensureData().receiptId;
    }

    /**
     * レシートを設定
     *
     * @param receiptId レシート
     */
    void setReceiptId(StringHolder receiptId)
    {
        ensureData().receiptId.emplace(std::move(receiptId));
    }

    /**
     * レシートを設定
     *
     * @param receiptId レシート
     */
    Receipt& withReceiptId(StringHolder receiptId)
    {
        setReceiptId(std::move(receiptId));
        return *this;
    }

    /**
     * トランザクションIDを取得
     *
     * @return トランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    Receipt& withTransactionId(StringHolder transactionId)
    {
        setTransactionId(std::move(transactionId));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Receipt& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 種類を取得
     *
     * @return 種類
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 種類を設定
     *
     * @param type 種類
     */
    void setType(StringHolder type)
    {
        ensureData().type.emplace(std::move(type));
    }

    /**
     * 種類を設定
     *
     * @param type 種類
     */
    Receipt& withType(StringHolder type)
    {
        setType(std::move(type));
        return *this;
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
    }

    /**
     * スロット番号を設定
     *
     * @param slot スロット番号
     */
    Receipt& withSlot(Int32 slot)
    {
        setSlot(slot);
        return *this;
    }

    /**
     * 単価を取得
     *
     * @return 単価
     */
    const optional<Float>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 単価を設定
     *
     * @param price 単価
     */
    void setPrice(Float price)
    {
        ensureData().price.emplace(price);
    }

    /**
     * 単価を設定
     *
     * @param price 単価
     */
    Receipt& withPrice(Float price)
    {
        setPrice(price);
        return *this;
    }

    /**
     * 有償課金通貨を取得
     *
     * @return 有償課金通貨
     */
    const optional<Int32>& getPaid() const
    {
        return ensureData().paid;
    }

    /**
     * 有償課金通貨を設定
     *
     * @param paid 有償課金通貨
     */
    void setPaid(Int32 paid)
    {
        ensureData().paid.emplace(paid);
    }

    /**
     * 有償課金通貨を設定
     *
     * @param paid 有償課金通貨
     */
    Receipt& withPaid(Int32 paid)
    {
        setPaid(paid);
        return *this;
    }

    /**
     * 無償課金通貨を取得
     *
     * @return 無償課金通貨
     */
    const optional<Int32>& getFree() const
    {
        return ensureData().free;
    }

    /**
     * 無償課金通貨を設定
     *
     * @param free 無償課金通貨
     */
    void setFree(Int32 free)
    {
        ensureData().free.emplace(free);
    }

    /**
     * 無償課金通貨を設定
     *
     * @param free 無償課金通貨
     */
    Receipt& withFree(Int32 free)
    {
        setFree(free);
        return *this;
    }

    /**
     * 総数を取得
     *
     * @return 総数
     */
    const optional<Int32>& getTotal() const
    {
        return ensureData().total;
    }

    /**
     * 総数を設定
     *
     * @param total 総数
     */
    void setTotal(Int32 total)
    {
        ensureData().total.emplace(total);
    }

    /**
     * 総数を設定
     *
     * @param total 総数
     */
    Receipt& withTotal(Int32 total)
    {
        setTotal(total);
        return *this;
    }

    /**
     * ストアプラットフォームで販売されているコンテンツIDを取得
     *
     * @return ストアプラットフォームで販売されているコンテンツID
     */
    const optional<StringHolder>& getContentsId() const
    {
        return ensureData().contentsId;
    }

    /**
     * ストアプラットフォームで販売されているコンテンツIDを設定
     *
     * @param contentsId ストアプラットフォームで販売されているコンテンツID
     */
    void setContentsId(StringHolder contentsId)
    {
        ensureData().contentsId.emplace(std::move(contentsId));
    }

    /**
     * ストアプラットフォームで販売されているコンテンツIDを設定
     *
     * @param contentsId ストアプラットフォームで販売されているコンテンツID
     */
    Receipt& withContentsId(StringHolder contentsId)
    {
        setContentsId(std::move(contentsId));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Receipt& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Receipt& lhs, const Receipt& lhr);

inline bool operator==(const Receipt& lhs, const Receipt& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_RECEIPT_HPP_