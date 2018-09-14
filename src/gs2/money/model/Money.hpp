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

#ifndef GS2_MONEY_MODEL_MONEY_HPP_
#define GS2_MONEY_MODEL_MONEY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * 課金通貨
 *
 * @author Game Server Services, Inc.
 *
 */
class Money : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 課金通貨GRN */
        optional<StringHolder> moneyId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 課金通貨名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 支払い優先度 */
        optional<StringHolder> priority;
        /** 無償課金通貨を異なるスロットで共有するか */
        optional<Bool> shareFree;
        /** 通貨 */
        optional<StringHolder> currency;
        /** ストアプラットフォームのレシートの検証機能を利用するか */
        optional<Bool> useVerifyReceipt;
        /** Apple のアプリケーションバンドルID */
        optional<StringHolder> appleKey;
        /** Google のレシート検証用公開鍵 */
        optional<StringHolder> googleKey;
        /** 未使用残高 */
        optional<Double> balance;
        /** ウォレット新規作成時 に実行されるGS2-Script */
        optional<StringHolder> createWalletTriggerScript;
        /** ウォレット新規作成完了時 に実行されるGS2-Script */
        optional<StringHolder> createWalletDoneTriggerScript;
        /** ウォレット残高加算時 に実行されるGS2-Script */
        optional<StringHolder> chargeWalletTriggerScript;
        /** ウォレット残高加算完了時 に実行されるGS2-Script */
        optional<StringHolder> chargeWalletDoneTriggerScript;
        /** ウォレット残高消費時 に実行されるGS2-Script */
        optional<StringHolder> consumeWalletTriggerScript;
        /** ウォレット残高消費完了時 に実行されるGS2-Script */
        optional<StringHolder> consumeWalletDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            moneyId(data.moneyId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            priority(data.priority),
            shareFree(data.shareFree),
            currency(data.currency),
            useVerifyReceipt(data.useVerifyReceipt),
            appleKey(data.appleKey),
            googleKey(data.googleKey),
            balance(data.balance),
            createWalletTriggerScript(data.createWalletTriggerScript),
            createWalletDoneTriggerScript(data.createWalletDoneTriggerScript),
            chargeWalletTriggerScript(data.chargeWalletTriggerScript),
            chargeWalletDoneTriggerScript(data.chargeWalletDoneTriggerScript),
            consumeWalletTriggerScript(data.consumeWalletTriggerScript),
            consumeWalletDoneTriggerScript(data.consumeWalletDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            moneyId(std::move(data.moneyId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            priority(std::move(data.priority)),
            shareFree(std::move(data.shareFree)),
            currency(std::move(data.currency)),
            useVerifyReceipt(std::move(data.useVerifyReceipt)),
            appleKey(std::move(data.appleKey)),
            googleKey(std::move(data.googleKey)),
            balance(std::move(data.balance)),
            createWalletTriggerScript(std::move(data.createWalletTriggerScript)),
            createWalletDoneTriggerScript(std::move(data.createWalletDoneTriggerScript)),
            chargeWalletTriggerScript(std::move(data.chargeWalletTriggerScript)),
            chargeWalletDoneTriggerScript(std::move(data.chargeWalletDoneTriggerScript)),
            consumeWalletTriggerScript(std::move(data.consumeWalletTriggerScript)),
            consumeWalletDoneTriggerScript(std::move(data.consumeWalletDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "moneyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->moneyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "priority") == 0) {
                if (jsonValue.IsString())
                {
                    this->priority.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "shareFree") == 0) {
                if (jsonValue.IsBool())
                {
                    this->shareFree = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "currency") == 0) {
                if (jsonValue.IsString())
                {
                    this->currency.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "useVerifyReceipt") == 0) {
                if (jsonValue.IsBool())
                {
                    this->useVerifyReceipt = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "appleKey") == 0) {
                if (jsonValue.IsString())
                {
                    this->appleKey.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "googleKey") == 0) {
                if (jsonValue.IsString())
                {
                    this->googleKey.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "balance") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->balance = jsonValue.GetDouble();
                }
            }
            else if (std::strcmp(name, "createWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "chargeWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->chargeWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "chargeWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->chargeWalletDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeWalletTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeWalletTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeWalletDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeWalletDoneTriggerScript.emplace(jsonValue.GetString());
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
    Money() :
        m_pData(nullptr)
    {}

    Money(const Money& money) :
        Gs2Object(money),
        m_pData(money.m_pData != nullptr ? new Data(*money.m_pData) : nullptr)
    {}

    Money(Money&& money) :
        Gs2Object(std::move(money)),
        m_pData(money.m_pData)
    {
        money.m_pData = nullptr;
    }

    ~Money()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Money& operator=(const Money& money)
    {
        Gs2Object::operator=(money);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*money.m_pData);

        return *this;
    }

    Money& operator=(Money&& money)
    {
        Gs2Object::operator=(std::move(money));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = money.m_pData;
        money.m_pData = nullptr;

        return *this;
    }

    const Money* operator->() const
    {
        return this;
    }

    Money* operator->()
    {
        return this;
    }


    /**
     * 課金通貨GRNを取得
     *
     * @return 課金通貨GRN
     */
    const optional<StringHolder>& getMoneyId() const
    {
        return ensureData().moneyId;
    }

    /**
     * 課金通貨GRNを設定
     *
     * @param moneyId 課金通貨GRN
     */
    void setMoneyId(const Char* moneyId)
    {
        ensureData().moneyId.emplace(moneyId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * 課金通貨名を取得
     *
     * @return 課金通貨名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 課金通貨名を設定
     *
     * @param name 課金通貨名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 支払い優先度を取得
     *
     * @return 支払い優先度
     */
    const optional<StringHolder>& getPriority() const
    {
        return ensureData().priority;
    }

    /**
     * 支払い優先度を設定
     *
     * @param priority 支払い優先度
     */
    void setPriority(const Char* priority)
    {
        ensureData().priority.emplace(priority);
    }

    /**
     * 無償課金通貨を異なるスロットで共有するかを取得
     *
     * @return 無償課金通貨を異なるスロットで共有するか
     */
    const optional<Bool>& getShareFree() const
    {
        return ensureData().shareFree;
    }

    /**
     * 無償課金通貨を異なるスロットで共有するかを設定
     *
     * @param shareFree 無償課金通貨を異なるスロットで共有するか
     */
    void setShareFree(Bool shareFree)
    {
        ensureData().shareFree.emplace(shareFree);
    }

    /**
     * 通貨を取得
     *
     * @return 通貨
     */
    const optional<StringHolder>& getCurrency() const
    {
        return ensureData().currency;
    }

    /**
     * 通貨を設定
     *
     * @param currency 通貨
     */
    void setCurrency(const Char* currency)
    {
        ensureData().currency.emplace(currency);
    }

    /**
     * ストアプラットフォームのレシートの検証機能を利用するかを取得
     *
     * @return ストアプラットフォームのレシートの検証機能を利用するか
     */
    const optional<Bool>& getUseVerifyReceipt() const
    {
        return ensureData().useVerifyReceipt;
    }

    /**
     * ストアプラットフォームのレシートの検証機能を利用するかを設定
     *
     * @param useVerifyReceipt ストアプラットフォームのレシートの検証機能を利用するか
     */
    void setUseVerifyReceipt(Bool useVerifyReceipt)
    {
        ensureData().useVerifyReceipt.emplace(useVerifyReceipt);
    }

    /**
     * Apple のアプリケーションバンドルIDを取得
     *
     * @return Apple のアプリケーションバンドルID
     */
    const optional<StringHolder>& getAppleKey() const
    {
        return ensureData().appleKey;
    }

    /**
     * Apple のアプリケーションバンドルIDを設定
     *
     * @param appleKey Apple のアプリケーションバンドルID
     */
    void setAppleKey(const Char* appleKey)
    {
        ensureData().appleKey.emplace(appleKey);
    }

    /**
     * Google のレシート検証用公開鍵を取得
     *
     * @return Google のレシート検証用公開鍵
     */
    const optional<StringHolder>& getGoogleKey() const
    {
        return ensureData().googleKey;
    }

    /**
     * Google のレシート検証用公開鍵を設定
     *
     * @param googleKey Google のレシート検証用公開鍵
     */
    void setGoogleKey(const Char* googleKey)
    {
        ensureData().googleKey.emplace(googleKey);
    }

    /**
     * 未使用残高を取得
     *
     * @return 未使用残高
     */
    const optional<Double>& getBalance() const
    {
        return ensureData().balance;
    }

    /**
     * 未使用残高を設定
     *
     * @param balance 未使用残高
     */
    void setBalance(Double balance)
    {
        ensureData().balance.emplace(balance);
    }

    /**
     * ウォレット新規作成時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレット新規作成時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletTriggerScript() const
    {
        return ensureData().createWalletTriggerScript;
    }

    /**
     * ウォレット新規作成時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletTriggerScript ウォレット新規作成時 に実行されるGS2-Script
     */
    void setCreateWalletTriggerScript(const Char* createWalletTriggerScript)
    {
        ensureData().createWalletTriggerScript.emplace(createWalletTriggerScript);
    }

    /**
     * ウォレット新規作成完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレット新規作成完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletDoneTriggerScript() const
    {
        return ensureData().createWalletDoneTriggerScript;
    }

    /**
     * ウォレット新規作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletDoneTriggerScript ウォレット新規作成完了時 に実行されるGS2-Script
     */
    void setCreateWalletDoneTriggerScript(const Char* createWalletDoneTriggerScript)
    {
        ensureData().createWalletDoneTriggerScript.emplace(createWalletDoneTriggerScript);
    }

    /**
     * ウォレット残高加算時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレット残高加算時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChargeWalletTriggerScript() const
    {
        return ensureData().chargeWalletTriggerScript;
    }

    /**
     * ウォレット残高加算時 に実行されるGS2-Scriptを設定
     *
     * @param chargeWalletTriggerScript ウォレット残高加算時 に実行されるGS2-Script
     */
    void setChargeWalletTriggerScript(const Char* chargeWalletTriggerScript)
    {
        ensureData().chargeWalletTriggerScript.emplace(chargeWalletTriggerScript);
    }

    /**
     * ウォレット残高加算完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレット残高加算完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getChargeWalletDoneTriggerScript() const
    {
        return ensureData().chargeWalletDoneTriggerScript;
    }

    /**
     * ウォレット残高加算完了時 に実行されるGS2-Scriptを設定
     *
     * @param chargeWalletDoneTriggerScript ウォレット残高加算完了時 に実行されるGS2-Script
     */
    void setChargeWalletDoneTriggerScript(const Char* chargeWalletDoneTriggerScript)
    {
        ensureData().chargeWalletDoneTriggerScript.emplace(chargeWalletDoneTriggerScript);
    }

    /**
     * ウォレット残高消費時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレット残高消費時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeWalletTriggerScript() const
    {
        return ensureData().consumeWalletTriggerScript;
    }

    /**
     * ウォレット残高消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeWalletTriggerScript ウォレット残高消費時 に実行されるGS2-Script
     */
    void setConsumeWalletTriggerScript(const Char* consumeWalletTriggerScript)
    {
        ensureData().consumeWalletTriggerScript.emplace(consumeWalletTriggerScript);
    }

    /**
     * ウォレット残高消費完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレット残高消費完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getConsumeWalletDoneTriggerScript() const
    {
        return ensureData().consumeWalletDoneTriggerScript;
    }

    /**
     * ウォレット残高消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeWalletDoneTriggerScript ウォレット残高消費完了時 に実行されるGS2-Script
     */
    void setConsumeWalletDoneTriggerScript(const Char* consumeWalletDoneTriggerScript)
    {
        ensureData().consumeWalletDoneTriggerScript.emplace(consumeWalletDoneTriggerScript);
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

#endif //GS2_MONEY_MODEL_MONEY_HPP_