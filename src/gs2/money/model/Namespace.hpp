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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "ScriptSetting.hpp"
#include "LogSetting.hpp"
#include <memory>

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
        /** ウォレット新規作成したときに実行するスクリプト */
        optional<ScriptSetting> createWalletScript;
        /** ウォレット残高加算したときに実行するスクリプト */
        optional<ScriptSetting> depositScript;
        /** ウォレット残高消費したときに実行するスクリプト */
        optional<ScriptSetting> withdrawScript;
        /** 未使用残高 */
        optional<Double> balance;
        /** ログの出力設定 */
        optional<LogSetting> logSetting;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const;

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
    void setNamespaceId(StringHolder namespaceId)
    {
        ensureData().namespaceId.emplace(std::move(namespaceId));
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(StringHolder namespaceId)
    {
        setNamespaceId(std::move(namespaceId));
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
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param name ネームスペースの名前
     */
    Namespace& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    Namespace& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    void setPriority(StringHolder priority)
    {
        ensureData().priority.emplace(std::move(priority));
    }

    /**
     * 消費優先度を設定
     *
     * @param priority 消費優先度
     */
    Namespace& withPriority(StringHolder priority)
    {
        setPriority(std::move(priority));
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
    void setCurrency(StringHolder currency)
    {
        ensureData().currency.emplace(std::move(currency));
    }

    /**
     * 通貨の種類を設定
     *
     * @param currency 通貨の種類
     */
    Namespace& withCurrency(StringHolder currency)
    {
        setCurrency(std::move(currency));
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
    void setAppleKey(StringHolder appleKey)
    {
        ensureData().appleKey.emplace(std::move(appleKey));
    }

    /**
     * Apple AppStore のバンドルIDを設定
     *
     * @param appleKey Apple AppStore のバンドルID
     */
    Namespace& withAppleKey(StringHolder appleKey)
    {
        setAppleKey(std::move(appleKey));
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
    void setGoogleKey(StringHolder googleKey)
    {
        ensureData().googleKey.emplace(std::move(googleKey));
    }

    /**
     * Google PlayStore の秘密鍵を設定
     *
     * @param googleKey Google PlayStore の秘密鍵
     */
    Namespace& withGoogleKey(StringHolder googleKey)
    {
        setGoogleKey(std::move(googleKey));
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
     * ウォレット新規作成したときに実行するスクリプトを取得
     *
     * @return ウォレット新規作成したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCreateWalletScript() const
    {
        return ensureData().createWalletScript;
    }

    /**
     * ウォレット新規作成したときに実行するスクリプトを設定
     *
     * @param createWalletScript ウォレット新規作成したときに実行するスクリプト
     */
    void setCreateWalletScript(ScriptSetting createWalletScript)
    {
        ensureData().createWalletScript.emplace(std::move(createWalletScript));
    }

    /**
     * ウォレット新規作成したときに実行するスクリプトを設定
     *
     * @param createWalletScript ウォレット新規作成したときに実行するスクリプト
     */
    Namespace& withCreateWalletScript(ScriptSetting createWalletScript)
    {
        setCreateWalletScript(std::move(createWalletScript));
        return *this;
    }

    /**
     * ウォレット残高加算したときに実行するスクリプトを取得
     *
     * @return ウォレット残高加算したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getDepositScript() const
    {
        return ensureData().depositScript;
    }

    /**
     * ウォレット残高加算したときに実行するスクリプトを設定
     *
     * @param depositScript ウォレット残高加算したときに実行するスクリプト
     */
    void setDepositScript(ScriptSetting depositScript)
    {
        ensureData().depositScript.emplace(std::move(depositScript));
    }

    /**
     * ウォレット残高加算したときに実行するスクリプトを設定
     *
     * @param depositScript ウォレット残高加算したときに実行するスクリプト
     */
    Namespace& withDepositScript(ScriptSetting depositScript)
    {
        setDepositScript(std::move(depositScript));
        return *this;
    }

    /**
     * ウォレット残高消費したときに実行するスクリプトを取得
     *
     * @return ウォレット残高消費したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getWithdrawScript() const
    {
        return ensureData().withdrawScript;
    }

    /**
     * ウォレット残高消費したときに実行するスクリプトを設定
     *
     * @param withdrawScript ウォレット残高消費したときに実行するスクリプト
     */
    void setWithdrawScript(ScriptSetting withdrawScript)
    {
        ensureData().withdrawScript.emplace(std::move(withdrawScript));
    }

    /**
     * ウォレット残高消費したときに実行するスクリプトを設定
     *
     * @param withdrawScript ウォレット残高消費したときに実行するスクリプト
     */
    Namespace& withWithdrawScript(ScriptSetting withdrawScript)
    {
        setWithdrawScript(std::move(withdrawScript));
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
     * ログの出力設定を取得
     *
     * @return ログの出力設定
     */
    const optional<LogSetting>& getLogSetting() const
    {
        return ensureData().logSetting;
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    void setLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    Namespace& withLogSetting(LogSetting logSetting)
    {
        setLogSetting(std::move(logSetting));
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

bool operator!=(const Namespace& lhs, const Namespace& lhr);

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MONEY_MODEL_NAMESPACE_HPP_