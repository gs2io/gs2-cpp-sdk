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

#ifndef GS2_PROJECT_MODEL_BILLINGMETHOD_HPP_
#define GS2_PROJECT_MODEL_BILLINGMETHOD_HPP_

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
 * 支払い方法
 *
 * @author Game Server Services, Inc.
 *
 */
class BillingMethod : public Gs2Object
{
    friend bool operator!=(const BillingMethod& lhs, const BillingMethod& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 支払い方法 */
        optional<StringHolder> billingMethodId;
        /** GS2アカウントの名前 */
        optional<StringHolder> accountName;
        /** 名前 */
        optional<StringHolder> name;
        /** 名前 */
        optional<StringHolder> description;
        /** 支払い方法 */
        optional<StringHolder> methodType;
        /** クレジットカードカスタマーID */
        optional<StringHolder> cardCustomerId;
        /** カード署名 */
        optional<StringHolder> cardSignatureName;
        /** カードブランド */
        optional<StringHolder> cardBrand;
        /** 末尾4桁 */
        optional<StringHolder> cardLast4;
        /** パートナーID */
        optional<StringHolder> partnerId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            billingMethodId(data.billingMethodId),
            accountName(data.accountName),
            name(data.name),
            description(data.description),
            methodType(data.methodType),
            cardCustomerId(data.cardCustomerId),
            cardSignatureName(data.cardSignatureName),
            cardBrand(data.cardBrand),
            cardLast4(data.cardLast4),
            partnerId(data.partnerId),
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
            if (std::strcmp(name_, "billingMethodId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->billingMethodId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "methodType") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->methodType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "cardCustomerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->cardCustomerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "cardSignatureName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->cardSignatureName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "cardBrand") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->cardBrand.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "cardLast4") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->cardLast4.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "partnerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->partnerId.emplace(jsonValue.GetString());
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
    BillingMethod() = default;
    BillingMethod(const BillingMethod& billingMethod) = default;
    BillingMethod(BillingMethod&& billingMethod) = default;
    ~BillingMethod() = default;

    BillingMethod& operator=(const BillingMethod& billingMethod) = default;
    BillingMethod& operator=(BillingMethod&& billingMethod) = default;

    BillingMethod deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(BillingMethod);
    }

    const BillingMethod* operator->() const
    {
        return this;
    }

    BillingMethod* operator->()
    {
        return this;
    }
    /**
     * 支払い方法を取得
     *
     * @return 支払い方法
     */
    const optional<StringHolder>& getBillingMethodId() const
    {
        return ensureData().billingMethodId;
    }

    /**
     * 支払い方法を設定
     *
     * @param billingMethodId 支払い方法
     */
    void setBillingMethodId(StringHolder billingMethodId)
    {
        ensureData().billingMethodId.emplace(std::move(billingMethodId));
    }

    /**
     * 支払い方法を設定
     *
     * @param billingMethodId 支払い方法
     */
    BillingMethod& withBillingMethodId(StringHolder billingMethodId)
    {
        setBillingMethodId(std::move(billingMethodId));
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
    BillingMethod& withAccountName(StringHolder accountName)
    {
        setAccountName(std::move(accountName));
        return *this;
    }

    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    BillingMethod& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 名前を設定
     *
     * @param description 名前
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 名前を設定
     *
     * @param description 名前
     */
    BillingMethod& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * 支払い方法を取得
     *
     * @return 支払い方法
     */
    const optional<StringHolder>& getMethodType() const
    {
        return ensureData().methodType;
    }

    /**
     * 支払い方法を設定
     *
     * @param methodType 支払い方法
     */
    void setMethodType(StringHolder methodType)
    {
        ensureData().methodType.emplace(std::move(methodType));
    }

    /**
     * 支払い方法を設定
     *
     * @param methodType 支払い方法
     */
    BillingMethod& withMethodType(StringHolder methodType)
    {
        setMethodType(std::move(methodType));
        return *this;
    }

    /**
     * クレジットカードカスタマーIDを取得
     *
     * @return クレジットカードカスタマーID
     */
    const optional<StringHolder>& getCardCustomerId() const
    {
        return ensureData().cardCustomerId;
    }

    /**
     * クレジットカードカスタマーIDを設定
     *
     * @param cardCustomerId クレジットカードカスタマーID
     */
    void setCardCustomerId(StringHolder cardCustomerId)
    {
        ensureData().cardCustomerId.emplace(std::move(cardCustomerId));
    }

    /**
     * クレジットカードカスタマーIDを設定
     *
     * @param cardCustomerId クレジットカードカスタマーID
     */
    BillingMethod& withCardCustomerId(StringHolder cardCustomerId)
    {
        setCardCustomerId(std::move(cardCustomerId));
        return *this;
    }

    /**
     * カード署名を取得
     *
     * @return カード署名
     */
    const optional<StringHolder>& getCardSignatureName() const
    {
        return ensureData().cardSignatureName;
    }

    /**
     * カード署名を設定
     *
     * @param cardSignatureName カード署名
     */
    void setCardSignatureName(StringHolder cardSignatureName)
    {
        ensureData().cardSignatureName.emplace(std::move(cardSignatureName));
    }

    /**
     * カード署名を設定
     *
     * @param cardSignatureName カード署名
     */
    BillingMethod& withCardSignatureName(StringHolder cardSignatureName)
    {
        setCardSignatureName(std::move(cardSignatureName));
        return *this;
    }

    /**
     * カードブランドを取得
     *
     * @return カードブランド
     */
    const optional<StringHolder>& getCardBrand() const
    {
        return ensureData().cardBrand;
    }

    /**
     * カードブランドを設定
     *
     * @param cardBrand カードブランド
     */
    void setCardBrand(StringHolder cardBrand)
    {
        ensureData().cardBrand.emplace(std::move(cardBrand));
    }

    /**
     * カードブランドを設定
     *
     * @param cardBrand カードブランド
     */
    BillingMethod& withCardBrand(StringHolder cardBrand)
    {
        setCardBrand(std::move(cardBrand));
        return *this;
    }

    /**
     * 末尾4桁を取得
     *
     * @return 末尾4桁
     */
    const optional<StringHolder>& getCardLast4() const
    {
        return ensureData().cardLast4;
    }

    /**
     * 末尾4桁を設定
     *
     * @param cardLast4 末尾4桁
     */
    void setCardLast4(StringHolder cardLast4)
    {
        ensureData().cardLast4.emplace(std::move(cardLast4));
    }

    /**
     * 末尾4桁を設定
     *
     * @param cardLast4 末尾4桁
     */
    BillingMethod& withCardLast4(StringHolder cardLast4)
    {
        setCardLast4(std::move(cardLast4));
        return *this;
    }

    /**
     * パートナーIDを取得
     *
     * @return パートナーID
     */
    const optional<StringHolder>& getPartnerId() const
    {
        return ensureData().partnerId;
    }

    /**
     * パートナーIDを設定
     *
     * @param partnerId パートナーID
     */
    void setPartnerId(StringHolder partnerId)
    {
        ensureData().partnerId.emplace(std::move(partnerId));
    }

    /**
     * パートナーIDを設定
     *
     * @param partnerId パートナーID
     */
    BillingMethod& withPartnerId(StringHolder partnerId)
    {
        setPartnerId(std::move(partnerId));
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
    BillingMethod& withCreatedAt(Int64 createdAt)
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
    BillingMethod& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const BillingMethod& lhs, const BillingMethod& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->billingMethodId != lhr.m_pData->billingMethodId)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->methodType != lhr.m_pData->methodType)
        {
            return true;
        }
        if (lhs.m_pData->cardCustomerId != lhr.m_pData->cardCustomerId)
        {
            return true;
        }
        if (lhs.m_pData->cardSignatureName != lhr.m_pData->cardSignatureName)
        {
            return true;
        }
        if (lhs.m_pData->cardBrand != lhr.m_pData->cardBrand)
        {
            return true;
        }
        if (lhs.m_pData->cardLast4 != lhr.m_pData->cardLast4)
        {
            return true;
        }
        if (lhs.m_pData->partnerId != lhr.m_pData->partnerId)
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

inline bool operator==(const BillingMethod& lhs, const BillingMethod& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_PROJECT_MODEL_BILLINGMETHOD_HPP_