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

#ifndef GS2_MONEY_CONTROL_UPDATEMONEYREQUEST_HPP_
#define GS2_MONEY_CONTROL_UPDATEMONEYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateMoneyRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "UpdateMoney";

private:
    class Data : public Gs2Object
    {
    public:
        /** 取得する課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 説明文(1024文字以内) */
        optional<StringHolder> description;
        /** 支払い優先度 */
        optional<StringHolder> priority;
        /** ストアプラットフォームのレシートの検証機能を利用するか */
        optional<Bool> useVerifyReceipt;
        /** Apple のアプリケーションバンドルID */
        optional<StringHolder> appleKey;
        /** Google のレシート検証用公開鍵 */
        optional<StringHolder> googleKey;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            description(data.description),
            priority(data.priority),
            useVerifyReceipt(data.useVerifyReceipt),
            appleKey(data.appleKey),
            googleKey(data.googleKey),
            createWalletTriggerScript(data.createWalletTriggerScript),
            createWalletDoneTriggerScript(data.createWalletDoneTriggerScript),
            chargeWalletTriggerScript(data.chargeWalletTriggerScript),
            chargeWalletDoneTriggerScript(data.chargeWalletDoneTriggerScript),
            consumeWalletTriggerScript(data.consumeWalletTriggerScript),
            consumeWalletDoneTriggerScript(data.consumeWalletDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            description(std::move(data.description)),
            priority(std::move(data.priority)),
            useVerifyReceipt(std::move(data.useVerifyReceipt)),
            appleKey(std::move(data.appleKey)),
            googleKey(std::move(data.googleKey)),
            createWalletTriggerScript(std::move(data.createWalletTriggerScript)),
            createWalletDoneTriggerScript(std::move(data.createWalletDoneTriggerScript)),
            chargeWalletTriggerScript(std::move(data.chargeWalletTriggerScript)),
            chargeWalletDoneTriggerScript(std::move(data.chargeWalletDoneTriggerScript)),
            consumeWalletTriggerScript(std::move(data.consumeWalletTriggerScript)),
            consumeWalletDoneTriggerScript(std::move(data.consumeWalletDoneTriggerScript))
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
    UpdateMoneyRequest() :
        m_pData(nullptr)
    {}

    UpdateMoneyRequest(const UpdateMoneyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateMoneyRequest(UpdateMoneyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateMoneyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateMoneyRequest& operator=(const UpdateMoneyRequest& updateMoneyRequest)
    {
        Gs2BasicRequest::operator=(updateMoneyRequest);
        Gs2Money::operator=(updateMoneyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateMoneyRequest.m_pData);

        return *this;
    }

    UpdateMoneyRequest& operator=(UpdateMoneyRequest&& updateMoneyRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateMoneyRequest));
        Gs2Money::operator=(std::move(updateMoneyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateMoneyRequest.m_pData;
        updateMoneyRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateMoneyRequest* operator->() const
    {
        return this;
    }

    UpdateMoneyRequest* operator->()
    {
        return this;
    }

    /**
     * 取得する課金通貨の名前を取得
     *
     * @return 取得する課金通貨の名前
     */
    const optional<StringHolder>& getMoneyName() const
    {
        return ensureData().moneyName;
    }

    /**
     * 取得する課金通貨の名前を設定
     *
     * @param moneyName 取得する課金通貨の名前
     */
    void setMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
    }

    /**
     * 取得する課金通貨の名前を設定
     *
     * @param moneyName 取得する課金通貨の名前
     */
    UpdateMoneyRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
        return *this;
    }

    /**
     * 説明文(1024文字以内)を取得
     *
     * @return 説明文(1024文字以内)
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文(1024文字以内)を設定
     *
     * @param description 説明文(1024文字以内)
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文(1024文字以内)を設定
     *
     * @param description 説明文(1024文字以内)
     */
    UpdateMoneyRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
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
     * 支払い優先度を設定
     *
     * @param priority 支払い優先度
     */
    UpdateMoneyRequest& withPriority(const Char* priority)
    {
        ensureData().priority.emplace(priority);
        return *this;
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
     * ストアプラットフォームのレシートの検証機能を利用するかを設定
     *
     * @param useVerifyReceipt ストアプラットフォームのレシートの検証機能を利用するか
     */
    UpdateMoneyRequest& withUseVerifyReceipt(Bool useVerifyReceipt)
    {
        ensureData().useVerifyReceipt.emplace(useVerifyReceipt);
        return *this;
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
     * Apple のアプリケーションバンドルIDを設定
     *
     * @param appleKey Apple のアプリケーションバンドルID
     */
    UpdateMoneyRequest& withAppleKey(const Char* appleKey)
    {
        ensureData().appleKey.emplace(appleKey);
        return *this;
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
     * Google のレシート検証用公開鍵を設定
     *
     * @param googleKey Google のレシート検証用公開鍵
     */
    UpdateMoneyRequest& withGoogleKey(const Char* googleKey)
    {
        ensureData().googleKey.emplace(googleKey);
        return *this;
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
     * ウォレット新規作成時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletTriggerScript ウォレット新規作成時 に実行されるGS2-Script
     */
    UpdateMoneyRequest& withCreateWalletTriggerScript(const Char* createWalletTriggerScript)
    {
        ensureData().createWalletTriggerScript.emplace(createWalletTriggerScript);
        return *this;
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
     * ウォレット新規作成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletDoneTriggerScript ウォレット新規作成完了時 に実行されるGS2-Script
     */
    UpdateMoneyRequest& withCreateWalletDoneTriggerScript(const Char* createWalletDoneTriggerScript)
    {
        ensureData().createWalletDoneTriggerScript.emplace(createWalletDoneTriggerScript);
        return *this;
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
     * ウォレット残高加算時 に実行されるGS2-Scriptを設定
     *
     * @param chargeWalletTriggerScript ウォレット残高加算時 に実行されるGS2-Script
     */
    UpdateMoneyRequest& withChargeWalletTriggerScript(const Char* chargeWalletTriggerScript)
    {
        ensureData().chargeWalletTriggerScript.emplace(chargeWalletTriggerScript);
        return *this;
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
     * ウォレット残高加算完了時 に実行されるGS2-Scriptを設定
     *
     * @param chargeWalletDoneTriggerScript ウォレット残高加算完了時 に実行されるGS2-Script
     */
    UpdateMoneyRequest& withChargeWalletDoneTriggerScript(const Char* chargeWalletDoneTriggerScript)
    {
        ensureData().chargeWalletDoneTriggerScript.emplace(chargeWalletDoneTriggerScript);
        return *this;
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
     * ウォレット残高消費時 に実行されるGS2-Scriptを設定
     *
     * @param consumeWalletTriggerScript ウォレット残高消費時 に実行されるGS2-Script
     */
    UpdateMoneyRequest& withConsumeWalletTriggerScript(const Char* consumeWalletTriggerScript)
    {
        ensureData().consumeWalletTriggerScript.emplace(consumeWalletTriggerScript);
        return *this;
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
     * ウォレット残高消費完了時 に実行されるGS2-Scriptを設定
     *
     * @param consumeWalletDoneTriggerScript ウォレット残高消費完了時 に実行されるGS2-Script
     */
    UpdateMoneyRequest& withConsumeWalletDoneTriggerScript(const Char* consumeWalletDoneTriggerScript)
    {
        ensureData().consumeWalletDoneTriggerScript.emplace(consumeWalletDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateMoneyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateMoneyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateMoneyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateMoneyRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_MONEY_CONTROL_UPDATEMONEYREQUEST_HPP_