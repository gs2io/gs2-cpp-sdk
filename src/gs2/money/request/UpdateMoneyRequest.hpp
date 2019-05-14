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
 * 課金通貨を新規作成します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateMoneyRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 課金通貨の名前 */
        optional<StringHolder> moneyName;
        /** 課金通貨の説明 */
        optional<StringHolder> description;
        /** 消費優先度 */
        optional<StringHolder> priority;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            moneyName(data.moneyName),
            description(data.description),
            priority(data.priority),
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
            withdrawDoneTriggerQueueId(data.withdrawDoneTriggerQueueId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            moneyName(std::move(data.moneyName)),
            description(std::move(data.description)),
            priority(std::move(data.priority)),
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
            withdrawDoneTriggerQueueId(std::move(data.withdrawDoneTriggerQueueId))
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
     * 課金通貨の名前を取得
     *
     * @return 課金通貨の名前
     */
    const optional<StringHolder>& getMoneyName() const
    {
        return ensureData().moneyName;
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param moneyName 課金通貨の名前
     */
    void setMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
    }

    /**
     * 課金通貨の名前を設定
     *
     * @param moneyName 課金通貨の名前
     */
    UpdateMoneyRequest& withMoneyName(const Char* moneyName)
    {
        ensureData().moneyName.emplace(moneyName);
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
    UpdateMoneyRequest& withDescription(const Char* description)
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
    UpdateMoneyRequest& withPriority(const Char* priority)
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
    UpdateMoneyRequest& withAppleKey(const Char* appleKey)
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
    UpdateMoneyRequest& withGoogleKey(const Char* googleKey)
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
    UpdateMoneyRequest& withEnableFakeReceipt(Bool enableFakeReceipt)
    {
        ensureData().enableFakeReceipt.emplace(enableFakeReceipt);
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
    UpdateMoneyRequest& withCreateWalletTriggerScriptId(const Char* createWalletTriggerScriptId)
    {
        ensureData().createWalletTriggerScriptId.emplace(createWalletTriggerScriptId);
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
    UpdateMoneyRequest& withCreateWalletDoneTriggerScriptId(const Char* createWalletDoneTriggerScriptId)
    {
        ensureData().createWalletDoneTriggerScriptId.emplace(createWalletDoneTriggerScriptId);
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
    UpdateMoneyRequest& withCreateWalletDoneTriggerQueueId(const Char* createWalletDoneTriggerQueueId)
    {
        ensureData().createWalletDoneTriggerQueueId.emplace(createWalletDoneTriggerQueueId);
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
    UpdateMoneyRequest& withDepositTriggerScriptId(const Char* depositTriggerScriptId)
    {
        ensureData().depositTriggerScriptId.emplace(depositTriggerScriptId);
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
    UpdateMoneyRequest& withDepositDoneTriggerScriptId(const Char* depositDoneTriggerScriptId)
    {
        ensureData().depositDoneTriggerScriptId.emplace(depositDoneTriggerScriptId);
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
    UpdateMoneyRequest& withDepositDoneTriggerQueueId(const Char* depositDoneTriggerQueueId)
    {
        ensureData().depositDoneTriggerQueueId.emplace(depositDoneTriggerQueueId);
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
    UpdateMoneyRequest& withWithdrawTriggerScriptId(const Char* withdrawTriggerScriptId)
    {
        ensureData().withdrawTriggerScriptId.emplace(withdrawTriggerScriptId);
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
    UpdateMoneyRequest& withWithdrawDoneTriggerScriptId(const Char* withdrawDoneTriggerScriptId)
    {
        ensureData().withdrawDoneTriggerScriptId.emplace(withdrawDoneTriggerScriptId);
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
    UpdateMoneyRequest& withWithdrawDoneTriggerQueueId(const Char* withdrawDoneTriggerQueueId)
    {
        ensureData().withdrawDoneTriggerQueueId.emplace(withdrawDoneTriggerQueueId);
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