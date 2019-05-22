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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * レシート
 *
 * @author Game Server Services, Inc.
 *
 */
class Receipt : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レシート のGRN */
        optional<StringHolder> receiptId;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** None */
        optional<Int32> slot;
        /** 種類 */
        optional<StringHolder> type;
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
        optional<Int64> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            receiptId(data.receiptId),
            transactionId(data.transactionId),
            userId(data.userId),
            slot(data.slot),
            type(data.type),
            price(data.price),
            paid(data.paid),
            free(data.free),
            total(data.total),
            contentsId(data.contentsId),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            receiptId(std::move(data.receiptId)),
            transactionId(std::move(data.transactionId)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            type(std::move(data.type)),
            price(std::move(data.price)),
            paid(std::move(data.paid)),
            free(std::move(data.free)),
            total(std::move(data.total)),
            contentsId(std::move(data.contentsId)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "receiptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "transactionId") == 0) {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "slot") == 0) {
                if (jsonValue.IsInt())
                {
                    this->slot = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "price") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->price = jsonValue.GetFloat();
                }
            }
            else if (std::strcmp(name, "paid") == 0) {
                if (jsonValue.IsInt())
                {
                    this->paid = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "free") == 0) {
                if (jsonValue.IsInt())
                {
                    this->free = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "total") == 0) {
                if (jsonValue.IsInt())
                {
                    this->total = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "contentsId") == 0) {
                if (jsonValue.IsString())
                {
                    this->contentsId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
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
    Receipt() :
        m_pData(nullptr)
    {}

    Receipt(const Receipt& receipt) :
        Gs2Object(receipt),
        m_pData(receipt.m_pData != nullptr ? new Data(*receipt.m_pData) : nullptr)
    {}

    Receipt(Receipt&& receipt) :
        Gs2Object(std::move(receipt)),
        m_pData(receipt.m_pData)
    {
        receipt.m_pData = nullptr;
    }

    ~Receipt()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Receipt& operator=(const Receipt& receipt)
    {
        Gs2Object::operator=(receipt);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*receipt.m_pData);

        return *this;
    }

    Receipt& operator=(Receipt&& receipt)
    {
        Gs2Object::operator=(std::move(receipt));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = receipt.m_pData;
        receipt.m_pData = nullptr;

        return *this;
    }

    const Receipt* operator->() const
    {
        return this;
    }

    Receipt* operator->()
    {
        return this;
    }
    /**
     * レシート のGRNを取得
     *
     * @return レシート のGRN
     */
    const optional<StringHolder>& getReceiptId() const
    {
        return ensureData().receiptId;
    }

    /**
     * レシート のGRNを設定
     *
     * @param receiptId レシート のGRN
     */
    void setReceiptId(const Char* receiptId)
    {
        ensureData().receiptId.emplace(receiptId);
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
    void setTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int32>& getSlot() const
    {
        return ensureData().slot;
    }

    /**
     * Noneを設定
     *
     * @param slot None
     */
    void setSlot(Int32 slot)
    {
        ensureData().slot.emplace(slot);
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
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
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
    void setContentsId(const Char* contentsId)
    {
        ensureData().contentsId.emplace(contentsId);
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_MODEL_RECEIPT_HPP_