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

#ifndef GS2_MONEY_MODEL_NAMESPACE_HPP_
#define GS2_MONEY_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace money {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ネームスペースの名前 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
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
        /** ウォレット新規作成完了時 にジョブを登録するネームスペース のGRN */
        optional<StringHolder> createWalletDoneTriggerNamespaceId;
        /** ウォレット残高加算時 に実行されるスクリプト のGRN */
        optional<StringHolder> depositTriggerScriptId;
        /** ウォレット残高加算完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> depositDoneTriggerScriptId;
        /** ウォレット残高加算完了時 にジョブを登録するネームスペース のGRN */
        optional<StringHolder> depositDoneTriggerNamespaceId;
        /** ウォレット残高消費時 に実行されるスクリプト のGRN */
        optional<StringHolder> withdrawTriggerScriptId;
        /** ウォレット残高消費完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> withdrawDoneTriggerScriptId;
        /** ウォレット残高消費完了時 にジョブを登録するネームスペース のGRN */
        optional<StringHolder> withdrawDoneTriggerNamespaceId;
        /** 未使用残高 */
        optional<Double> balance;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
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
            createWalletDoneTriggerNamespaceId(data.createWalletDoneTriggerNamespaceId),
            depositTriggerScriptId(data.depositTriggerScriptId),
            depositDoneTriggerScriptId(data.depositDoneTriggerScriptId),
            depositDoneTriggerNamespaceId(data.depositDoneTriggerNamespaceId),
            withdrawTriggerScriptId(data.withdrawTriggerScriptId),
            withdrawDoneTriggerScriptId(data.withdrawDoneTriggerScriptId),
            withdrawDoneTriggerNamespaceId(data.withdrawDoneTriggerNamespaceId),
            balance(data.balance),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
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
            createWalletDoneTriggerNamespaceId(std::move(data.createWalletDoneTriggerNamespaceId)),
            depositTriggerScriptId(std::move(data.depositTriggerScriptId)),
            depositDoneTriggerScriptId(std::move(data.depositDoneTriggerScriptId)),
            depositDoneTriggerNamespaceId(std::move(data.depositDoneTriggerNamespaceId)),
            withdrawTriggerScriptId(std::move(data.withdrawTriggerScriptId)),
            withdrawDoneTriggerScriptId(std::move(data.withdrawDoneTriggerScriptId)),
            withdrawDoneTriggerNamespaceId(std::move(data.withdrawDoneTriggerNamespaceId)),
            balance(std::move(data.balance)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "namespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "createWalletDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->createWalletDoneTriggerNamespaceId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "depositDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->depositDoneTriggerNamespaceId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "withdrawDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->withdrawDoneTriggerNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "balance") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->balance = jsonValue.GetDouble();
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
    Namespace() :
        m_pData(nullptr)
    {}

    Namespace(const Namespace& namespace_) :
        Gs2Object(namespace_),
        m_pData(namespace_.m_pData != nullptr ? new Data(*namespace_.m_pData) : nullptr)
    {}

    Namespace(Namespace&& namespace_) :
        Gs2Object(std::move(namespace_)),
        m_pData(namespace_.m_pData)
    {
        namespace_.m_pData = nullptr;
    }

    ~Namespace()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Namespace& operator=(const Namespace& namespace_)
    {
        Gs2Object::operator=(namespace_);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*namespace_.m_pData);

        return *this;
    }

    Namespace& operator=(Namespace&& namespace_)
    {
        Gs2Object::operator=(std::move(namespace_));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = namespace_.m_pData;
        namespace_.m_pData = nullptr;

        return *this;
    }

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(const Char* namespaceId)
    {
        setNamespaceId(namespaceId);
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
    Namespace& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * ネームスペースの名前を取得
     *
     * @return ネームスペースの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param name ネームスペースの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param name ネームスペースの名前
     */
    Namespace& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    Namespace& withDescription(const Char* description)
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
    Namespace& withPriority(const Char* priority)
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
    Namespace& withShareFree(Bool shareFree)
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
    Namespace& withCurrency(const Char* currency)
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
    Namespace& withAppleKey(const Char* appleKey)
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
    Namespace& withGoogleKey(const Char* googleKey)
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
    Namespace& withEnableFakeReceipt(Bool enableFakeReceipt)
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
    Namespace& withCreateWalletTriggerScriptId(const Char* createWalletTriggerScriptId)
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
    Namespace& withCreateWalletDoneTriggerScriptId(const Char* createWalletDoneTriggerScriptId)
    {
        setCreateWalletDoneTriggerScriptId(createWalletDoneTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット新規作成完了時 にジョブを登録するネームスペース のGRNを取得
     *
     * @return ウォレット新規作成完了時 にジョブを登録するネームスペース のGRN
     */
    const optional<StringHolder>& getCreateWalletDoneTriggerNamespaceId() const
    {
        return ensureData().createWalletDoneTriggerNamespaceId;
    }

    /**
     * ウォレット新規作成完了時 にジョブを登録するネームスペース のGRNを設定
     *
     * @param createWalletDoneTriggerNamespaceId ウォレット新規作成完了時 にジョブを登録するネームスペース のGRN
     */
    void setCreateWalletDoneTriggerNamespaceId(const Char* createWalletDoneTriggerNamespaceId)
    {
        ensureData().createWalletDoneTriggerNamespaceId.emplace(createWalletDoneTriggerNamespaceId);
    }

    /**
     * ウォレット新規作成完了時 にジョブを登録するネームスペース のGRNを設定
     *
     * @param createWalletDoneTriggerNamespaceId ウォレット新規作成完了時 にジョブを登録するネームスペース のGRN
     */
    Namespace& withCreateWalletDoneTriggerNamespaceId(const Char* createWalletDoneTriggerNamespaceId)
    {
        setCreateWalletDoneTriggerNamespaceId(createWalletDoneTriggerNamespaceId);
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
    Namespace& withDepositTriggerScriptId(const Char* depositTriggerScriptId)
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
    Namespace& withDepositDoneTriggerScriptId(const Char* depositDoneTriggerScriptId)
    {
        setDepositDoneTriggerScriptId(depositDoneTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット残高加算完了時 にジョブを登録するネームスペース のGRNを取得
     *
     * @return ウォレット残高加算完了時 にジョブを登録するネームスペース のGRN
     */
    const optional<StringHolder>& getDepositDoneTriggerNamespaceId() const
    {
        return ensureData().depositDoneTriggerNamespaceId;
    }

    /**
     * ウォレット残高加算完了時 にジョブを登録するネームスペース のGRNを設定
     *
     * @param depositDoneTriggerNamespaceId ウォレット残高加算完了時 にジョブを登録するネームスペース のGRN
     */
    void setDepositDoneTriggerNamespaceId(const Char* depositDoneTriggerNamespaceId)
    {
        ensureData().depositDoneTriggerNamespaceId.emplace(depositDoneTriggerNamespaceId);
    }

    /**
     * ウォレット残高加算完了時 にジョブを登録するネームスペース のGRNを設定
     *
     * @param depositDoneTriggerNamespaceId ウォレット残高加算完了時 にジョブを登録するネームスペース のGRN
     */
    Namespace& withDepositDoneTriggerNamespaceId(const Char* depositDoneTriggerNamespaceId)
    {
        setDepositDoneTriggerNamespaceId(depositDoneTriggerNamespaceId);
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
    Namespace& withWithdrawTriggerScriptId(const Char* withdrawTriggerScriptId)
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
    Namespace& withWithdrawDoneTriggerScriptId(const Char* withdrawDoneTriggerScriptId)
    {
        setWithdrawDoneTriggerScriptId(withdrawDoneTriggerScriptId);
        return *this;
    }

    /**
     * ウォレット残高消費完了時 にジョブを登録するネームスペース のGRNを取得
     *
     * @return ウォレット残高消費完了時 にジョブを登録するネームスペース のGRN
     */
    const optional<StringHolder>& getWithdrawDoneTriggerNamespaceId() const
    {
        return ensureData().withdrawDoneTriggerNamespaceId;
    }

    /**
     * ウォレット残高消費完了時 にジョブを登録するネームスペース のGRNを設定
     *
     * @param withdrawDoneTriggerNamespaceId ウォレット残高消費完了時 にジョブを登録するネームスペース のGRN
     */
    void setWithdrawDoneTriggerNamespaceId(const Char* withdrawDoneTriggerNamespaceId)
    {
        ensureData().withdrawDoneTriggerNamespaceId.emplace(withdrawDoneTriggerNamespaceId);
    }

    /**
     * ウォレット残高消費完了時 にジョブを登録するネームスペース のGRNを設定
     *
     * @param withdrawDoneTriggerNamespaceId ウォレット残高消費完了時 にジョブを登録するネームスペース のGRN
     */
    Namespace& withWithdrawDoneTriggerNamespaceId(const Char* withdrawDoneTriggerNamespaceId)
    {
        setWithdrawDoneTriggerNamespaceId(withdrawDoneTriggerNamespaceId);
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
    Namespace& withBalance(Double balance)
    {
        setBalance(balance);
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
    Namespace& withCreatedAt(Int64 createdAt)
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
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
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
        if (lhs.m_pData->createWalletDoneTriggerNamespaceId != lhr.m_pData->createWalletDoneTriggerNamespaceId)
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
        if (lhs.m_pData->depositDoneTriggerNamespaceId != lhr.m_pData->depositDoneTriggerNamespaceId)
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
        if (lhs.m_pData->withdrawDoneTriggerNamespaceId != lhr.m_pData->withdrawDoneTriggerNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->balance != lhr.m_pData->balance)
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

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_NAMESPACE_HPP_