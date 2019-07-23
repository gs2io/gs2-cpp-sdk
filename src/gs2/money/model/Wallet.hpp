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

#ifndef GS2_MONEY_MODEL_WALLET_HPP_
#define GS2_MONEY_MODEL_WALLET_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ウォレット
 *
 * @author Game Server Services, Inc.
 *
 */
class Wallet : public Gs2Object
{
    friend bool operator!=(const Wallet& lhs, const Wallet& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ウォレット */
        optional<StringHolder> walletId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> slot;
        /** 有償課金通貨所持量 */
        optional<Int32> paid;
        /** 無償課金通貨所持量 */
        optional<Int32> free;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            walletId(data.walletId),
            userId(data.userId),
            slot(data.slot),
            paid(data.paid),
            free(data.free),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            walletId(std::move(data.walletId)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            paid(std::move(data.paid)),
            free(std::move(data.free)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "walletId") == 0) {
                if (jsonValue.IsString())
                {
                    this->walletId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    Wallet() :
        m_pData(nullptr)
    {}

    Wallet(const Wallet& wallet) :
        Gs2Object(wallet),
        m_pData(wallet.m_pData != nullptr ? new Data(*wallet.m_pData) : nullptr)
    {}

    Wallet(Wallet&& wallet) :
        Gs2Object(std::move(wallet)),
        m_pData(wallet.m_pData)
    {
        wallet.m_pData = nullptr;
    }

    ~Wallet()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Wallet& operator=(const Wallet& wallet)
    {
        Gs2Object::operator=(wallet);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*wallet.m_pData);

        return *this;
    }

    Wallet& operator=(Wallet&& wallet)
    {
        Gs2Object::operator=(std::move(wallet));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = wallet.m_pData;
        wallet.m_pData = nullptr;

        return *this;
    }

    const Wallet* operator->() const
    {
        return this;
    }

    Wallet* operator->()
    {
        return this;
    }
    /**
     * ウォレットを取得
     *
     * @return ウォレット
     */
    const optional<StringHolder>& getWalletId() const
    {
        return ensureData().walletId;
    }

    /**
     * ウォレットを設定
     *
     * @param walletId ウォレット
     */
    void setWalletId(const Char* walletId)
    {
        ensureData().walletId.emplace(walletId);
    }

    /**
     * ウォレットを設定
     *
     * @param walletId ウォレット
     */
    Wallet& withWalletId(const Char* walletId)
    {
        setWalletId(walletId);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Wallet& withUserId(const Char* userId)
    {
        setUserId(userId);
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
    Wallet& withSlot(Int32 slot)
    {
        setSlot(slot);
        return *this;
    }

    /**
     * 有償課金通貨所持量を取得
     *
     * @return 有償課金通貨所持量
     */
    const optional<Int32>& getPaid() const
    {
        return ensureData().paid;
    }

    /**
     * 有償課金通貨所持量を設定
     *
     * @param paid 有償課金通貨所持量
     */
    void setPaid(Int32 paid)
    {
        ensureData().paid.emplace(paid);
    }

    /**
     * 有償課金通貨所持量を設定
     *
     * @param paid 有償課金通貨所持量
     */
    Wallet& withPaid(Int32 paid)
    {
        setPaid(paid);
        return *this;
    }

    /**
     * 無償課金通貨所持量を取得
     *
     * @return 無償課金通貨所持量
     */
    const optional<Int32>& getFree() const
    {
        return ensureData().free;
    }

    /**
     * 無償課金通貨所持量を設定
     *
     * @param free 無償課金通貨所持量
     */
    void setFree(Int32 free)
    {
        ensureData().free.emplace(free);
    }

    /**
     * 無償課金通貨所持量を設定
     *
     * @param free 無償課金通貨所持量
     */
    Wallet& withFree(Int32 free)
    {
        setFree(free);
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
    Wallet& withCreatedAt(Int64 createdAt)
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
    Wallet& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Wallet& lhs, const Wallet& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->walletId != lhr.m_pData->walletId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->slot != lhr.m_pData->slot)
        {
            return true;
        }
        if (lhs.m_pData->paid != lhr.m_pData->paid)
        {
            return true;
        }
        if (lhs.m_pData->free != lhr.m_pData->free)
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

bool operator==(const Wallet& lhs, const Wallet& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_WALLET_HPP_