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

#ifndef GS2_GOLD_MODEL_WALLET_HPP_
#define GS2_GOLD_MODEL_WALLET_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gold {

/**
 * ウォレット
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
        /** ウォレットGRN */
        optional<StringHolder> walletId;
        /** ユーザID */
        optional<StringHolder> userId;
        /** ゴールド名 */
        optional<StringHolder> goldName;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 残高 */
        optional<Int64> balance;
        /** 直近の期間の取得量 */
        optional<Int64> latestGain;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            walletId(data.walletId),
            userId(data.userId),
            goldName(data.goldName),
            meta(data.meta),
            balance(data.balance),
            latestGain(data.latestGain),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            walletId(std::move(data.walletId)),
            userId(std::move(data.userId)),
            goldName(std::move(data.goldName)),
            meta(std::move(data.meta)),
            balance(std::move(data.balance)),
            latestGain(std::move(data.latestGain)),
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
            else if (std::strcmp(name, "goldName") == 0) {
                if (jsonValue.IsString())
                {
                    this->goldName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "balance") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->balance = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "latestGain") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->latestGain = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
     * ウォレットGRNを取得
     *
     * @return ウォレットGRN
     */
    const optional<StringHolder>& getWalletId() const
    {
        return ensureData().walletId;
    }

    /**
     * ウォレットGRNを設定
     *
     * @param walletId ウォレットGRN
     */
    void setWalletId(const Char* walletId)
    {
        ensureData().walletId.emplace(walletId);
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
     * ゴールド名を取得
     *
     * @return ゴールド名
     */
    const optional<StringHolder>& getGoldName() const
    {
        return ensureData().goldName;
    }

    /**
     * ゴールド名を設定
     *
     * @param goldName ゴールド名
     */
    void setGoldName(const Char* goldName)
    {
        ensureData().goldName.emplace(goldName);
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 残高を取得
     *
     * @return 残高
     */
    const optional<Int64>& getBalance() const
    {
        return ensureData().balance;
    }

    /**
     * 残高を設定
     *
     * @param balance 残高
     */
    void setBalance(Int64 balance)
    {
        ensureData().balance.emplace(balance);
    }

    /**
     * 直近の期間の取得量を取得
     *
     * @return 直近の期間の取得量
     */
    const optional<Int64>& getLatestGain() const
    {
        return ensureData().latestGain;
    }

    /**
     * 直近の期間の取得量を設定
     *
     * @param latestGain 直近の期間の取得量
     */
    void setLatestGain(Int64 latestGain)
    {
        ensureData().latestGain.emplace(latestGain);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GOLD_MODEL_WALLET_HPP_