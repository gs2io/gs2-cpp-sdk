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
    friend bool operator!=(const Money& lhs, const Money& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 課金通貨 のGRN */
        optional<StringHolder> moneyId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 課金通貨の名前 */
        optional<StringHolder> name;
        /** 課金通貨の説明 */
        optional<StringHolder> description;
        /** 消費優先度 */
        optional<StringHolder> priority;
        /** 無償課金通貨を異なるスロットで共有するか */
        optional<Bool> shareFree;
        /** 通貨の種類 */
        optional<StringHolder> currency;
        /** Apple AppStore のバンドルID */
        optional<StringHolder> appleKey;
        /** Google PlayStore の秘密鍵 */
        optional<StringHolder> googleKey;
        /** UnityEditorが出力する偽のレシートで決済できるようにするか */
        optional<Bool> enableFakeReceipt;
        /** ウォレット新規作成時 に実行されるスクリプト のGRN */
        optional<StringHolder> createWalletTriggerScriptId;
        /** ウォレット新規作成完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> createWalletDoneTriggerScriptId;
        /** ウォレット新規作成完了時 にジョブを登録するキュー のGRN */
        optional<StringHolder> createWalletDoneTriggerQueueId;
        /** ウォレット残高加算時 に実行されるスクリプト のGRN */
        optional<StringHolder> depositTriggerScriptId;
        /** ウォレット残高加算完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> depositDoneTriggerScriptId;
        /** ウォレット残高加算完了時 にジョブを登録するキュー のGRN */
        optional<StringHolder> depositDoneTriggerQueueId;
        /** ウォレット残高消費時 に実行されるスクリプト のGRN */
        optional<StringHolder> withdrawTriggerScriptId;
        /** ウォレット残高消費完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> withdrawDoneTriggerScriptId;
        /** ウォレット残高消費完了時 にジョブを登録するキュー のGRN */
        optional<StringHolder> withdrawDoneTriggerQueueId;
        /** 未使用残高 */
        optional<Double> balance;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

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
            appleKey(data.appleKey),
            googleKey(data.googleKey),
            enableFakeReceipt(data.enableFakeReceipt),
            createWalletTriggerScriptId(data.createWalletTriggerScriptId),
            createWalletDoneTriggerScriptId(data.createWalletDoneTriggerScriptId),
            createWalletDoneTriggerQueueId(data.createWalletDoneTriggerQueueId),
            depositTriggerScriptId(data.depositTriggerScriptId),
            depositDoneTriggerScriptId(data.depositDoneTriggerScriptId),
            depositDoneTriggerQueueId(data.depositDoneTriggerQueueId),
            withdrawTriggerScriptId(data.withdrawTriggerScriptId),
            withdrawDoneTriggerScriptId(data.withdrawDoneTriggerScriptId),
            withdrawDoneTriggerQueueId(data.withdrawDoneTriggerQueueId),
            balance(data.balance),
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
            appleKey(std::move(data.appleKey)),
            googleKey(std::move(data.googleKey)),
            enableFakeReceipt(std::move(data.enableFakeReceipt)),
            createWalletTriggerScriptId(std::move(data.createWalletTriggerScriptId)),
            createWalletDoneTriggerScriptId(std::move(data.createWalletDoneTriggerScriptId)),
            createWalletDoneTriggerQueueId(std::move(data.createWalletDoneTriggerQueueId)),
            depositTriggerScriptId(std::move(data.depositTriggerScriptId)),
            depositDoneTriggerScriptId(std::move(data.depositDoneTriggerScriptId)),
            depositDoneTriggerQueueId(std::move(data.depositDoneTriggerQueueId)),
            withdrawTriggerScriptId(std::move(data.withdrawTriggerScriptId)),
            withdrawDoneTriggerScriptId(std::move(data.withdrawDoneTriggerScriptId)),
            withdrawDoneTriggerQueueId(std::move(data.withdrawDoneTriggerQueueId)),
            balance(std::move(data.balance)),
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
            else if (std::strcmp(name, "enableFakeReceipt") == 0) {
                if (jsonValue.IsBool())
                {
                    this->enableFakeReceipt = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "createWalletTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createWalletDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createWalletDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "depositTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "depositDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "depositDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "withdrawTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "withdrawDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "withdrawDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "balance") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->balance = jsonValue.GetDouble();
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
     * 課金通貨 のGRNを取得
     *
     * @return 課金通貨 のGRN
     */
    const optional<StringHolder>& getMoneyId() const
    {
        return ensureData().moneyId;
    }

    /**
     * 課金通貨 のGRNを設定
     *
     * @param moneyId 課金通貨 のGRN
     */
    void setMoneyId(const Char* moneyId)
    {
        ensureData().moneyId.emplace(moneyId);
    }

    /**
     * 課金通貨 のGRNを設定
     *
     * @param moneyId 課金通貨 のGRN
     */
    Money& withMoneyId(const Char* moneyId)
    {
        setMoneyId(moneyId);
        return *this;
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
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Money& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * 課金通貨の名前を取得
     *
     * @return 課金通貨の名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param name 課金通貨の名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param name 課金通貨の名前
     */
    Money& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 課金通貨の説明を取得
     *
     * @return 課金通貨の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 課金通貨の説明を設定
     *
     * @param description 課金通貨の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 課金通貨の説明を設定
     *
     * @param description 課金通貨の説明
     */
    Money& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * 消費優先度を取得
     *
     * @return 消費優先度
     */
    const optional<StringHolder>& getPriority() const
    {
        return ensureData().priority;
    }

    /**
     * 消費優先度を設定
     *
     * @param priority 消費優先度
     */
    void setPriority(const Char* priority)
    {
        ensureData().priority.emplace(priority);
    }

    /**
     * 消費優先度を設定
     *
     * @param priority 消費優先度
     */
    Money& withPriority(const Char* priority)
    {
        setPriority(priority);
        return *this;
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
     * 無償課金通貨を異なるスロットで共有するかを設定
     *
     * @param shareFree 無償課金通貨を異なるスロットで共有するか
     */
    Money& withShareFree(Bool shareFree)
    {
        setShareFree(shareFree);
        return *this;
    }

    /**
     * 通貨の種類を取得
     *
     * @return 通貨の種類
     */
    const optional<StringHolder>& getCurrency() const
    {
        return ensureData().currency;
    }

    /**
     * 通貨の種類を設定
     *
     * @param currency 通貨の種類
     */
    void setCurrency(const Char* currency)
    {
        ensureData().currency.emplace(currency);
    }

    /**
     * 通貨の種類を設定
     *
     * @param currency 通貨の種類
     */
    Money& withCurrency(const Char* currency)
    {
        setCurrency(currency);
        return *this;
    }

    /**
     * Apple AppStore のバンドルIDを取得
     *
     * @return Apple AppStore のバンドルID
     */
    const optional<StringHolder>& getAppleKey() const
    {
        return ensureData().appleKey;
    }

    /**
     * Apple AppStore のバンドルIDを設定
     *
     * @param appleKey Apple AppStore のバンドルID
     */
    void setAppleKey(const Char* appleKey)
    {
        ensureData().appleKey.emplace(appleKey);
    }

    /**
     * Apple AppStore のバンドルIDを設定
     *
     * @param appleKey Apple AppStore のバンドルID
     */
    Money& withAppleKey(const Char* appleKey)
    {
        setAppleKey(appleKey);
        return *this;
    }

    /**
     * Google PlayStore の秘密鍵を取得
     *
     * @return Google PlayStore の秘密鍵
     */
    const optional<StringHolder>& getGoogleKey() const
    {
        return ensureData().googleKey;
    }

    /**
     * Google PlayStore の秘密鍵を設定
     *
     * @param googleKey Google PlayStore の秘密鍵
     */
    void setGoogleKey(const Char* googleKey)
    {
        ensureData().googleKey.emplace(googleKey);
    }

    /**
     * Google PlayStore の秘密鍵を設定
     *
     * @param googleKey Google PlayStore の秘密鍵
     */
    Money& withGoogleKey(const Char* googleKey)
    {
        setGoogleKey(googleKey);
        return *this;
    }

    /**
     * UnityEditorが出力する偽のレシートで決済できるようにするかを取得
     *
     * @return UnityEditorが出力する偽のレシートで決済できるようにするか
     */
    const optional<Bool>& getEnableFakeReceipt() const
    {
        return ensureData().enableFakeReceipt;
    }

    /**
     * UnityEditorが出力する偽のレシートで決済できるようにするかを設定
     *
     * @param enableFakeReceipt UnityEditorが出力する偽のレシートで決済できるようにするか
     */
    void setEnableFakeReceipt(Bool enableFakeReceipt)
    {
        ensureData().enableFakeReceipt.emplace(enableFakeReceipt);
    }

    /**
     * UnityEditorが出力する偽のレシートで決済できるようにするかを設定
     *
     * @param enableFakeReceipt UnityEditorが出力する偽のレシートで決済できるようにするか
     */
    Money& withEnableFakeReceipt(Bool enableFakeReceipt)
    {
        setEnableFakeReceipt(enableFakeReceipt);
        return *this;
    }

    /**
     * ウォレット新規作成時 に実行されるスクリプト のGRNを取得
     *
     * @return ウォレット新規作成時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateWalletTriggerScriptId() const
    {
        return ensureData().createWalletTriggerScriptId;
    }

    /**
     * ウォレット新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createWalletTriggerScriptId ウォレット新規作成時 に実行されるスクリプト のGRN
     */
    void setCreateWalletTriggerScriptId(const Char* createWalletTriggerScriptId)
    {
        ensureData().createWalletTriggerScriptId.emplace(createWalletTriggerScriptId);
    }

    /**
     * ウォレット新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createWalletTriggerScriptId ウォレット新規作成時 に実行されるスクリプト のGRN
     */
    Money& withCreateWalletTriggerScriptId(const Char* createWalletTriggerScriptId)
    {
        setCreateWalletTriggerScriptId(createWalletTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット新規作成完了時 に実行されるスクリプト のGRNを取得
     *
     * @return ウォレット新規作成完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateWalletDoneTriggerScriptId() const
    {
        return ensureData().createWalletDoneTriggerScriptId;
    }

    /**
     * ウォレット新規作成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param createWalletDoneTriggerScriptId ウォレット新規作成完了時 に実行されるスクリプト のGRN
     */
    void setCreateWalletDoneTriggerScriptId(const Char* createWalletDoneTriggerScriptId)
    {
        ensureData().createWalletDoneTriggerScriptId.emplace(createWalletDoneTriggerScriptId);
    }

    /**
     * ウォレット新規作成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param createWalletDoneTriggerScriptId ウォレット新規作成完了時 に実行されるスクリプト のGRN
     */
    Money& withCreateWalletDoneTriggerScriptId(const Char* createWalletDoneTriggerScriptId)
    {
        setCreateWalletDoneTriggerScriptId(createWalletDoneTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット新規作成完了時 にジョブを登録するキュー のGRNを取得
     *
     * @return ウォレット新規作成完了時 にジョブを登録するキュー のGRN
     */
    const optional<StringHolder>& getCreateWalletDoneTriggerQueueId() const
    {
        return ensureData().createWalletDoneTriggerQueueId;
    }

    /**
     * ウォレット新規作成完了時 にジョブを登録するキュー のGRNを設定
     *
     * @param createWalletDoneTriggerQueueId ウォレット新規作成完了時 にジョブを登録するキュー のGRN
     */
    void setCreateWalletDoneTriggerQueueId(const Char* createWalletDoneTriggerQueueId)
    {
        ensureData().createWalletDoneTriggerQueueId.emplace(createWalletDoneTriggerQueueId);
    }

    /**
     * ウォレット新規作成完了時 にジョブを登録するキュー のGRNを設定
     *
     * @param createWalletDoneTriggerQueueId ウォレット新規作成完了時 にジョブを登録するキュー のGRN
     */
    Money& withCreateWalletDoneTriggerQueueId(const Char* createWalletDoneTriggerQueueId)
    {
        setCreateWalletDoneTriggerQueueId(createWalletDoneTriggerQueueId);
        return *this;
    }

    /**
     * ウォレット残高加算時 に実行されるスクリプト のGRNを取得
     *
     * @return ウォレット残高加算時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDepositTriggerScriptId() const
    {
        return ensureData().depositTriggerScriptId;
    }

    /**
     * ウォレット残高加算時 に実行されるスクリプト のGRNを設定
     *
     * @param depositTriggerScriptId ウォレット残高加算時 に実行されるスクリプト のGRN
     */
    void setDepositTriggerScriptId(const Char* depositTriggerScriptId)
    {
        ensureData().depositTriggerScriptId.emplace(depositTriggerScriptId);
    }

    /**
     * ウォレット残高加算時 に実行されるスクリプト のGRNを設定
     *
     * @param depositTriggerScriptId ウォレット残高加算時 に実行されるスクリプト のGRN
     */
    Money& withDepositTriggerScriptId(const Char* depositTriggerScriptId)
    {
        setDepositTriggerScriptId(depositTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット残高加算完了時 に実行されるスクリプト のGRNを取得
     *
     * @return ウォレット残高加算完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDepositDoneTriggerScriptId() const
    {
        return ensureData().depositDoneTriggerScriptId;
    }

    /**
     * ウォレット残高加算完了時 に実行されるスクリプト のGRNを設定
     *
     * @param depositDoneTriggerScriptId ウォレット残高加算完了時 に実行されるスクリプト のGRN
     */
    void setDepositDoneTriggerScriptId(const Char* depositDoneTriggerScriptId)
    {
        ensureData().depositDoneTriggerScriptId.emplace(depositDoneTriggerScriptId);
    }

    /**
     * ウォレット残高加算完了時 に実行されるスクリプト のGRNを設定
     *
     * @param depositDoneTriggerScriptId ウォレット残高加算完了時 に実行されるスクリプト のGRN
     */
    Money& withDepositDoneTriggerScriptId(const Char* depositDoneTriggerScriptId)
    {
        setDepositDoneTriggerScriptId(depositDoneTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット残高加算完了時 にジョブを登録するキュー のGRNを取得
     *
     * @return ウォレット残高加算完了時 にジョブを登録するキュー のGRN
     */
    const optional<StringHolder>& getDepositDoneTriggerQueueId() const
    {
        return ensureData().depositDoneTriggerQueueId;
    }

    /**
     * ウォレット残高加算完了時 にジョブを登録するキュー のGRNを設定
     *
     * @param depositDoneTriggerQueueId ウォレット残高加算完了時 にジョブを登録するキュー のGRN
     */
    void setDepositDoneTriggerQueueId(const Char* depositDoneTriggerQueueId)
    {
        ensureData().depositDoneTriggerQueueId.emplace(depositDoneTriggerQueueId);
    }

    /**
     * ウォレット残高加算完了時 にジョブを登録するキュー のGRNを設定
     *
     * @param depositDoneTriggerQueueId ウォレット残高加算完了時 にジョブを登録するキュー のGRN
     */
    Money& withDepositDoneTriggerQueueId(const Char* depositDoneTriggerQueueId)
    {
        setDepositDoneTriggerQueueId(depositDoneTriggerQueueId);
        return *this;
    }

    /**
     * ウォレット残高消費時 に実行されるスクリプト のGRNを取得
     *
     * @return ウォレット残高消費時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getWithdrawTriggerScriptId() const
    {
        return ensureData().withdrawTriggerScriptId;
    }

    /**
     * ウォレット残高消費時 に実行されるスクリプト のGRNを設定
     *
     * @param withdrawTriggerScriptId ウォレット残高消費時 に実行されるスクリプト のGRN
     */
    void setWithdrawTriggerScriptId(const Char* withdrawTriggerScriptId)
    {
        ensureData().withdrawTriggerScriptId.emplace(withdrawTriggerScriptId);
    }

    /**
     * ウォレット残高消費時 に実行されるスクリプト のGRNを設定
     *
     * @param withdrawTriggerScriptId ウォレット残高消費時 に実行されるスクリプト のGRN
     */
    Money& withWithdrawTriggerScriptId(const Char* withdrawTriggerScriptId)
    {
        setWithdrawTriggerScriptId(withdrawTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット残高消費完了時 に実行されるスクリプト のGRNを取得
     *
     * @return ウォレット残高消費完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getWithdrawDoneTriggerScriptId() const
    {
        return ensureData().withdrawDoneTriggerScriptId;
    }

    /**
     * ウォレット残高消費完了時 に実行されるスクリプト のGRNを設定
     *
     * @param withdrawDoneTriggerScriptId ウォレット残高消費完了時 に実行されるスクリプト のGRN
     */
    void setWithdrawDoneTriggerScriptId(const Char* withdrawDoneTriggerScriptId)
    {
        ensureData().withdrawDoneTriggerScriptId.emplace(withdrawDoneTriggerScriptId);
    }

    /**
     * ウォレット残高消費完了時 に実行されるスクリプト のGRNを設定
     *
     * @param withdrawDoneTriggerScriptId ウォレット残高消費完了時 に実行されるスクリプト のGRN
     */
    Money& withWithdrawDoneTriggerScriptId(const Char* withdrawDoneTriggerScriptId)
    {
        setWithdrawDoneTriggerScriptId(withdrawDoneTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット残高消費完了時 にジョブを登録するキュー のGRNを取得
     *
     * @return ウォレット残高消費完了時 にジョブを登録するキュー のGRN
     */
    const optional<StringHolder>& getWithdrawDoneTriggerQueueId() const
    {
        return ensureData().withdrawDoneTriggerQueueId;
    }

    /**
     * ウォレット残高消費完了時 にジョブを登録するキュー のGRNを設定
     *
     * @param withdrawDoneTriggerQueueId ウォレット残高消費完了時 にジョブを登録するキュー のGRN
     */
    void setWithdrawDoneTriggerQueueId(const Char* withdrawDoneTriggerQueueId)
    {
        ensureData().withdrawDoneTriggerQueueId.emplace(withdrawDoneTriggerQueueId);
    }

    /**
     * ウォレット残高消費完了時 にジョブを登録するキュー のGRNを設定
     *
     * @param withdrawDoneTriggerQueueId ウォレット残高消費完了時 にジョブを登録するキュー のGRN
     */
    Money& withWithdrawDoneTriggerQueueId(const Char* withdrawDoneTriggerQueueId)
    {
        setWithdrawDoneTriggerQueueId(withdrawDoneTriggerQueueId);
        return *this;
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
     * 未使用残高を設定
     *
     * @param balance 未使用残高
     */
    Money& withBalance(Double balance)
    {
        setBalance(balance);
        return *this;
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
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    Money& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
        return *this;
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

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    Money& withUpdateAt(Int64 updateAt)
    {
        setUpdateAt(updateAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Money& lhs, const Money& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->moneyId != lhr.m_pData->moneyId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
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
        if (lhs.m_pData->priority != lhr.m_pData->priority)
        {
            return true;
        }
        if (lhs.m_pData->shareFree != lhr.m_pData->shareFree)
        {
            return true;
        }
        if (lhs.m_pData->currency != lhr.m_pData->currency)
        {
            return true;
        }
        if (lhs.m_pData->appleKey != lhr.m_pData->appleKey)
        {
            return true;
        }
        if (lhs.m_pData->googleKey != lhr.m_pData->googleKey)
        {
            return true;
        }
        if (lhs.m_pData->enableFakeReceipt != lhr.m_pData->enableFakeReceipt)
        {
            return true;
        }
        if (lhs.m_pData->createWalletTriggerScriptId != lhr.m_pData->createWalletTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->createWalletDoneTriggerScriptId != lhr.m_pData->createWalletDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->createWalletDoneTriggerQueueId != lhr.m_pData->createWalletDoneTriggerQueueId)
        {
            return true;
        }
        if (lhs.m_pData->depositTriggerScriptId != lhr.m_pData->depositTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->depositDoneTriggerScriptId != lhr.m_pData->depositDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->depositDoneTriggerQueueId != lhr.m_pData->depositDoneTriggerQueueId)
        {
            return true;
        }
        if (lhs.m_pData->withdrawTriggerScriptId != lhr.m_pData->withdrawTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->withdrawDoneTriggerScriptId != lhr.m_pData->withdrawDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->withdrawDoneTriggerQueueId != lhr.m_pData->withdrawDoneTriggerQueueId)
        {
            return true;
        }
        if (lhs.m_pData->balance != lhr.m_pData->balance)
        {
            return true;
        }
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
        {
            return true;
        }
        if (lhs.m_pData->updateAt != lhr.m_pData->updateAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Money& lhs, const Money& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_MONEY_HPP_