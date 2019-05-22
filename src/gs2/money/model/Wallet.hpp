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
 * ウォレットの詳細
 *
 * @author Game Server Services, Inc.
 *
 */
class Wallet : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ウォレットの詳細 のGRN */
        optional<StringHolder> walletId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** None */
        optional<Int32> slot;
        /** 単価 */
        optional<Float> price;
        /** 所持量 */
        optional<Int32> count;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            walletId(data.walletId),
            userId(data.userId),
            slot(data.slot),
            price(data.price),
            count(data.count),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            walletId(std::move(data.walletId)),
            userId(std::move(data.userId)),
            slot(std::move(data.slot)),
            price(std::move(data.price)),
            count(std::move(data.count)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
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
            else if (std::strcmp(name, "price") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->price = jsonValue.GetFloat();
                }
            }
            else if (std::strcmp(name, "count") == 0) {
                if (jsonValue.IsInt())
                {
                    this->count = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * ウォレットの詳細 のGRNを取得
     *
     * @return ウォレットの詳細 のGRN
     */
    const optional<StringHolder>& getWalletId() const
    {
        return ensureData().walletId;
    }

    /**
     * ウォレットの詳細 のGRNを設定
     *
     * @param walletId ウォレットの詳細 のGRN
     */
    void setWalletId(const Char* walletId)
    {
        ensureData().walletId.emplace(walletId);
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
     * 所持量を取得
     *
     * @return 所持量
     */
    const optional<Int32>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 所持量を設定
     *
     * @param count 所持量
     */
    void setCount(Int32 count)
    {
        ensureData().count.emplace(count);
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

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_MODEL_WALLET_HPP_