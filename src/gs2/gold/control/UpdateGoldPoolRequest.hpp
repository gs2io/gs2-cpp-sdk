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

#ifndef GS2_GOLD_CONTROL_UPDATEGOLDPOOLREQUEST_HPP_
#define GS2_GOLD_CONTROL_UPDATEGOLDPOOLREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GoldConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gold
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateGoldPoolRequest : public Gs2BasicRequest, public Gs2Gold
{
public:
    constexpr static const Char* const FUNCTION = "UpdateGoldPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゴールドプールの名前 */
        optional<StringHolder> goldPoolName;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** ウォレットの生成時 に実行されるGS2-Script */
        optional<StringHolder> createWalletTriggerScript;
        /** ウォレットの生成完了時 に実行されるGS2-Script */
        optional<StringHolder> createWalletDoneTriggerScript;
        /** ウォレットへの加算時 に実行されるGS2-Script */
        optional<StringHolder> depositIntoWalletTriggerScript;
        /** ウォレットへの加算完了時 に実行されるGS2-Script */
        optional<StringHolder> depositIntoWalletDoneTriggerScript;
        /** ウォレットからの減算時 に実行されるGS2-Script */
        optional<StringHolder> withdrawFromWalletTriggerScript;
        /** ウォレットからの減算完了時 に実行されるGS2-Script */
        optional<StringHolder> withdrawFromWalletDoneTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            goldPoolName(data.goldPoolName),
            description(data.description),
            serviceClass(data.serviceClass),
            createWalletTriggerScript(data.createWalletTriggerScript),
            createWalletDoneTriggerScript(data.createWalletDoneTriggerScript),
            depositIntoWalletTriggerScript(data.depositIntoWalletTriggerScript),
            depositIntoWalletDoneTriggerScript(data.depositIntoWalletDoneTriggerScript),
            withdrawFromWalletTriggerScript(data.withdrawFromWalletTriggerScript),
            withdrawFromWalletDoneTriggerScript(data.withdrawFromWalletDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            goldPoolName(std::move(data.goldPoolName)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            createWalletTriggerScript(std::move(data.createWalletTriggerScript)),
            createWalletDoneTriggerScript(std::move(data.createWalletDoneTriggerScript)),
            depositIntoWalletTriggerScript(std::move(data.depositIntoWalletTriggerScript)),
            depositIntoWalletDoneTriggerScript(std::move(data.depositIntoWalletDoneTriggerScript)),
            withdrawFromWalletTriggerScript(std::move(data.withdrawFromWalletTriggerScript)),
            withdrawFromWalletDoneTriggerScript(std::move(data.withdrawFromWalletDoneTriggerScript))
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
    UpdateGoldPoolRequest() :
        m_pData(nullptr)
    {}

    UpdateGoldPoolRequest(const UpdateGoldPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gold(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateGoldPoolRequest(UpdateGoldPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gold(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateGoldPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateGoldPoolRequest& operator=(const UpdateGoldPoolRequest& updateGoldPoolRequest)
    {
        Gs2BasicRequest::operator=(updateGoldPoolRequest);
        Gs2Gold::operator=(updateGoldPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateGoldPoolRequest.m_pData);

        return *this;
    }

    UpdateGoldPoolRequest& operator=(UpdateGoldPoolRequest&& updateGoldPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateGoldPoolRequest));
        Gs2Gold::operator=(std::move(updateGoldPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateGoldPoolRequest.m_pData;
        updateGoldPoolRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateGoldPoolRequest* operator->() const
    {
        return this;
    }

    UpdateGoldPoolRequest* operator->()
    {
        return this;
    }

    /**
     * ゴールドプールの名前を取得
     *
     * @return ゴールドプールの名前
     */
    const optional<StringHolder>& getGoldPoolName() const
    {
        return ensureData().goldPoolName;
    }

    /**
     * ゴールドプールの名前を設定
     *
     * @param goldPoolName ゴールドプールの名前
     */
    void setGoldPoolName(const Char* goldPoolName)
    {
        ensureData().goldPoolName.emplace(goldPoolName);
    }

    /**
     * ゴールドプールの名前を設定
     *
     * @param goldPoolName ゴールドプールの名前
     */
    UpdateGoldPoolRequest& withGoldPoolName(const Char* goldPoolName)
    {
        ensureData().goldPoolName.emplace(goldPoolName);
        return *this;
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
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateGoldPoolRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    UpdateGoldPoolRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * ウォレットの生成時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットの生成時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletTriggerScript() const
    {
        return ensureData().createWalletTriggerScript;
    }

    /**
     * ウォレットの生成時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletTriggerScript ウォレットの生成時 に実行されるGS2-Script
     */
    void setCreateWalletTriggerScript(const Char* createWalletTriggerScript)
    {
        ensureData().createWalletTriggerScript.emplace(createWalletTriggerScript);
    }

    /**
     * ウォレットの生成時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletTriggerScript ウォレットの生成時 に実行されるGS2-Script
     */
    UpdateGoldPoolRequest& withCreateWalletTriggerScript(const Char* createWalletTriggerScript)
    {
        ensureData().createWalletTriggerScript.emplace(createWalletTriggerScript);
        return *this;
    }

    /**
     * ウォレットの生成完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットの生成完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCreateWalletDoneTriggerScript() const
    {
        return ensureData().createWalletDoneTriggerScript;
    }

    /**
     * ウォレットの生成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletDoneTriggerScript ウォレットの生成完了時 に実行されるGS2-Script
     */
    void setCreateWalletDoneTriggerScript(const Char* createWalletDoneTriggerScript)
    {
        ensureData().createWalletDoneTriggerScript.emplace(createWalletDoneTriggerScript);
    }

    /**
     * ウォレットの生成完了時 に実行されるGS2-Scriptを設定
     *
     * @param createWalletDoneTriggerScript ウォレットの生成完了時 に実行されるGS2-Script
     */
    UpdateGoldPoolRequest& withCreateWalletDoneTriggerScript(const Char* createWalletDoneTriggerScript)
    {
        ensureData().createWalletDoneTriggerScript.emplace(createWalletDoneTriggerScript);
        return *this;
    }

    /**
     * ウォレットへの加算時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットへの加算時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDepositIntoWalletTriggerScript() const
    {
        return ensureData().depositIntoWalletTriggerScript;
    }

    /**
     * ウォレットへの加算時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletTriggerScript ウォレットへの加算時 に実行されるGS2-Script
     */
    void setDepositIntoWalletTriggerScript(const Char* depositIntoWalletTriggerScript)
    {
        ensureData().depositIntoWalletTriggerScript.emplace(depositIntoWalletTriggerScript);
    }

    /**
     * ウォレットへの加算時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletTriggerScript ウォレットへの加算時 に実行されるGS2-Script
     */
    UpdateGoldPoolRequest& withDepositIntoWalletTriggerScript(const Char* depositIntoWalletTriggerScript)
    {
        ensureData().depositIntoWalletTriggerScript.emplace(depositIntoWalletTriggerScript);
        return *this;
    }

    /**
     * ウォレットへの加算完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットへの加算完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDepositIntoWalletDoneTriggerScript() const
    {
        return ensureData().depositIntoWalletDoneTriggerScript;
    }

    /**
     * ウォレットへの加算完了時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletDoneTriggerScript ウォレットへの加算完了時 に実行されるGS2-Script
     */
    void setDepositIntoWalletDoneTriggerScript(const Char* depositIntoWalletDoneTriggerScript)
    {
        ensureData().depositIntoWalletDoneTriggerScript.emplace(depositIntoWalletDoneTriggerScript);
    }

    /**
     * ウォレットへの加算完了時 に実行されるGS2-Scriptを設定
     *
     * @param depositIntoWalletDoneTriggerScript ウォレットへの加算完了時 に実行されるGS2-Script
     */
    UpdateGoldPoolRequest& withDepositIntoWalletDoneTriggerScript(const Char* depositIntoWalletDoneTriggerScript)
    {
        ensureData().depositIntoWalletDoneTriggerScript.emplace(depositIntoWalletDoneTriggerScript);
        return *this;
    }

    /**
     * ウォレットからの減算時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットからの減算時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getWithdrawFromWalletTriggerScript() const
    {
        return ensureData().withdrawFromWalletTriggerScript;
    }

    /**
     * ウォレットからの減算時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletTriggerScript ウォレットからの減算時 に実行されるGS2-Script
     */
    void setWithdrawFromWalletTriggerScript(const Char* withdrawFromWalletTriggerScript)
    {
        ensureData().withdrawFromWalletTriggerScript.emplace(withdrawFromWalletTriggerScript);
    }

    /**
     * ウォレットからの減算時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletTriggerScript ウォレットからの減算時 に実行されるGS2-Script
     */
    UpdateGoldPoolRequest& withWithdrawFromWalletTriggerScript(const Char* withdrawFromWalletTriggerScript)
    {
        ensureData().withdrawFromWalletTriggerScript.emplace(withdrawFromWalletTriggerScript);
        return *this;
    }

    /**
     * ウォレットからの減算完了時 に実行されるGS2-Scriptを取得
     *
     * @return ウォレットからの減算完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getWithdrawFromWalletDoneTriggerScript() const
    {
        return ensureData().withdrawFromWalletDoneTriggerScript;
    }

    /**
     * ウォレットからの減算完了時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletDoneTriggerScript ウォレットからの減算完了時 に実行されるGS2-Script
     */
    void setWithdrawFromWalletDoneTriggerScript(const Char* withdrawFromWalletDoneTriggerScript)
    {
        ensureData().withdrawFromWalletDoneTriggerScript.emplace(withdrawFromWalletDoneTriggerScript);
    }

    /**
     * ウォレットからの減算完了時 に実行されるGS2-Scriptを設定
     *
     * @param withdrawFromWalletDoneTriggerScript ウォレットからの減算完了時 に実行されるGS2-Script
     */
    UpdateGoldPoolRequest& withWithdrawFromWalletDoneTriggerScript(const Char* withdrawFromWalletDoneTriggerScript)
    {
        ensureData().withdrawFromWalletDoneTriggerScript.emplace(withdrawFromWalletDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateGoldPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateGoldPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateGoldPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateGoldPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GOLD_CONTROL_UPDATEGOLDPOOLREQUEST_HPP_