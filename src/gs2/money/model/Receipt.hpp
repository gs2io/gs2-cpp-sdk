/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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
        /** ユーザID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> slot;
        /** 種類 */
        optional<StringHolder> type;
        /** 金額 */
        optional<Double> price;
        /** 有償課金通貨 */
        optional<Int32> paid;
        /** 無償課金通貨 */
        optional<Int32> free;
        /** 総数 */
        optional<Int32> total;
        /** 用途 */
        optional<Int32> use;
        /** 決済日時(エポック秒) */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            slot(data.slot),
            type(data.type),
            price(data.price),
            paid(data.paid),
            free(data.free),
            total(data.total),
            use(data.use),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            type(std::move(data.type)),
            price(std::move(data.price)),
            paid(std::move(data.paid)),
            free(std::move(data.free)),
            total(std::move(data.total)),
            use(std::move(data.use)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
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
                if (jsonValue.IsDouble())
                {
                    this->price = jsonValue.GetDouble();
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
            else if (std::strcmp(name, "use") == 0) {
                if (jsonValue.IsInt())
                {
                    this->use = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
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
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
     * 金額を取得
     *
     * @return 金額
     */
    const optional<Double>& getPrice() const
    {
        return ensureData().price;
    }

    /**
     * 金額を設定
     *
     * @param price 金額
     */
    void setPrice(Double price)
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
     * 用途を取得
     *
     * @return 用途
     */
    const optional<Int32>& getUse() const
    {
        return ensureData().use;
    }

    /**
     * 用途を設定
     *
     * @param use 用途
     */
    void setUse(Int32 use)
    {
        ensureData().use.emplace(use);
    }

    /**
     * 決済日時(エポック秒)を取得
     *
     * @return 決済日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 決済日時(エポック秒)を設定
     *
     * @param createAt 決済日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
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