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

#ifndef GS2_PROJECT_MODEL_RECEIPT_HPP_
#define GS2_PROJECT_MODEL_RECEIPT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace project {

/**
 * 領収書
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
        /** 領収書 */
        optional<StringHolder> receiptId;
        /** GS2アカウントの名前 */
        optional<StringHolder> accountName;
        /** 請求書名 */
        optional<StringHolder> name;
        /** 請求月 */
        optional<Int64> date;
        /** 請求金額 */
        optional<StringHolder> amount;
        /** PDF URL */
        optional<StringHolder> pdfUrl;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            receiptId(data.receiptId),
            accountName(data.accountName),
            name(data.name),
            date(data.date),
            amount(data.amount),
            pdfUrl(data.pdfUrl),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "receiptId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->receiptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "accountName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->accountName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "date") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->date = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "amount") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->amount.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "pdfUrl") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->pdfUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Receipt() = default;
    Receipt(const Receipt& receipt) = default;
    Receipt(Receipt&& receipt) = default;
    ~Receipt() = default;

    Receipt& operator=(const Receipt& receipt) = default;
    Receipt& operator=(Receipt&& receipt) = default;

    Receipt deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Receipt);
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
     * 領収書を取得
     *
     * @return 領収書
     */
    const optional<StringHolder>& getReceiptId() const
    {
        return ensureData().receiptId;
    }

    /**
     * 領収書を設定
     *
     * @param receiptId 領収書
     */
    void setReceiptId(StringHolder receiptId)
    {
        ensureData().receiptId.emplace(std::move(receiptId));
    }

    /**
     * 領収書を設定
     *
     * @param receiptId 領収書
     */
    Receipt& withReceiptId(StringHolder receiptId)
    {
        setReceiptId(std::move(receiptId));
        return *this;
    }

    /**
     * GS2アカウントの名前を取得
     *
     * @return GS2アカウントの名前
     */
    const optional<StringHolder>& getAccountName() const
    {
        return ensureData().accountName;
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    void setAccountName(StringHolder accountName)
    {
        ensureData().accountName.emplace(std::move(accountName));
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    Receipt& withAccountName(StringHolder accountName)
    {
        setAccountName(std::move(accountName));
        return *this;
    }

    /**
     * 請求書名を取得
     *
     * @return 請求書名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 請求書名を設定
     *
     * @param name 請求書名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 請求書名を設定
     *
     * @param name 請求書名
     */
    Receipt& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 請求月を取得
     *
     * @return 請求月
     */
    const optional<Int64>& getDate() const
    {
        return ensureData().date;
    }

    /**
     * 請求月を設定
     *
     * @param date 請求月
     */
    void setDate(Int64 date)
    {
        ensureData().date.emplace(date);
    }

    /**
     * 請求月を設定
     *
     * @param date 請求月
     */
    Receipt& withDate(Int64 date)
    {
        setDate(date);
        return *this;
    }

    /**
     * 請求金額を取得
     *
     * @return 請求金額
     */
    const optional<StringHolder>& getAmount() const
    {
        return ensureData().amount;
    }

    /**
     * 請求金額を設定
     *
     * @param amount 請求金額
     */
    void setAmount(StringHolder amount)
    {
        ensureData().amount.emplace(std::move(amount));
    }

    /**
     * 請求金額を設定
     *
     * @param amount 請求金額
     */
    Receipt& withAmount(StringHolder amount)
    {
        setAmount(std::move(amount));
        return *this;
    }

    /**
     * PDF URLを取得
     *
     * @return PDF URL
     */
    const optional<StringHolder>& getPdfUrl() const
    {
        return ensureData().pdfUrl;
    }

    /**
     * PDF URLを設定
     *
     * @param pdfUrl PDF URL
     */
    void setPdfUrl(StringHolder pdfUrl)
    {
        ensureData().pdfUrl.emplace(std::move(pdfUrl));
    }

    /**
     * PDF URLを設定
     *
     * @param pdfUrl PDF URL
     */
    Receipt& withPdfUrl(StringHolder pdfUrl)
    {
        setPdfUrl(std::move(pdfUrl));
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

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Receipt& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Receipt& lhs, const Receipt& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->receiptId != lhr.m_pData->receiptId)
        {
            return true;
        }
        if (lhs.m_pData->accountName != lhr.m_pData->accountName)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->date != lhr.m_pData->date)
        {
            return true;
        }
        if (lhs.m_pData->amount != lhr.m_pData->amount)
        {
            return true;
        }
        if (lhs.m_pData->pdfUrl != lhr.m_pData->pdfUrl)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Receipt& lhs, const Receipt& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_PROJECT_MODEL_RECEIPT_HPP_