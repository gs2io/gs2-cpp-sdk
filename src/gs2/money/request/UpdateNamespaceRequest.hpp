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

#ifndef GS2_MONEY_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_MONEY_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * ネームスペースを更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペースの名前 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** 消費優先度 */
        optional<StringHolder> priority;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            priority(data.priority),
            appleKey(data.appleKey),
            googleKey(data.googleKey),
            enableFakeReceipt(data.enableFakeReceipt),
            createWalletScript(data.createWalletScript),
            depositScript(data.depositScript),
            withdrawScript(data.withdrawScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            priority(std::move(data.priority)),
            appleKey(std::move(data.appleKey)),
            googleKey(std::move(data.googleKey)),
            enableFakeReceipt(std::move(data.enableFakeReceipt)),
            createWalletScript(std::move(data.createWalletScript)),
            depositScript(std::move(data.depositScript)),
            withdrawScript(std::move(data.withdrawScript))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    UpdateNamespaceRequest() :
        m_pData(nullptr)
    {}

    UpdateNamespaceRequest(const UpdateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(updateNamespaceRequest);
        Gs2Money::operator=(updateNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateNamespaceRequest.m_pData);

        return *this;
    }

    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateNamespaceRequest));
        Gs2Money::operator=(std::move(updateNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateNamespaceRequest.m_pData;
        updateNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateNamespaceRequest* operator->() const
    {
        return this;
    }

    UpdateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペースの名前を取得
     *
     * @return ネームスペースの名前
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param namespaceName ネームスペースの名前
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param namespaceName ネームスペースの名前
     */
    UpdateNamespaceRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    UpdateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    UpdateNamespaceRequest& withPriority(const Char* priority)
    {
        ensureData().priority.emplace(priority);
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
    UpdateNamespaceRequest& withAppleKey(const Char* appleKey)
    {
        ensureData().appleKey.emplace(appleKey);
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
    UpdateNamespaceRequest& withGoogleKey(const Char* googleKey)
    {
        ensureData().googleKey.emplace(googleKey);
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
    UpdateNamespaceRequest& withEnableFakeReceipt(Bool enableFakeReceipt)
    {
        ensureData().enableFakeReceipt.emplace(enableFakeReceipt);
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
    void setCreateWalletScript(const ScriptSetting& createWalletScript)
    {
        ensureData().createWalletScript.emplace(createWalletScript);
    }

    /**
     * ウォレット新規作成したときに実行するスクリプトを設定
     *
     * @param createWalletScript ウォレット新規作成したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCreateWalletScript(const ScriptSetting& createWalletScript)
    {
        ensureData().createWalletScript.emplace(createWalletScript);
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
    void setDepositScript(const ScriptSetting& depositScript)
    {
        ensureData().depositScript.emplace(depositScript);
    }

    /**
     * ウォレット残高加算したときに実行するスクリプトを設定
     *
     * @param depositScript ウォレット残高加算したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withDepositScript(const ScriptSetting& depositScript)
    {
        ensureData().depositScript.emplace(depositScript);
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
    void setWithdrawScript(const ScriptSetting& withdrawScript)
    {
        ensureData().withdrawScript.emplace(withdrawScript);
    }

    /**
     * ウォレット残高消費したときに実行するスクリプトを設定
     *
     * @param withdrawScript ウォレット残高消費したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withWithdrawScript(const ScriptSetting& withdrawScript)
    {
        ensureData().withdrawScript.emplace(withdrawScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_MONEY_CONTROL_UPDATENAMESPACEREQUEST_HPP_