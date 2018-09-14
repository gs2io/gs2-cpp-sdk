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

#ifndef GS2_GOLD_CONTROL_CREATEGOLDMASTERREQUEST_HPP_
#define GS2_GOLD_CONTROL_CREATEGOLDMASTERREQUEST_HPP_

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
class CreateGoldMasterRequest : public Gs2BasicRequest, public Gs2Gold
{
public:
    constexpr static const Char* const FUNCTION = "CreateGoldMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゴールドプールの名前 */
        optional<StringHolder> goldPoolName;
        /** ゴールド名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 各ウォレットの残高の最大値 */
        optional<Int64> balanceMax;
        /** 取得量の期間制限のタイプ */
        optional<StringHolder> resetType;
        /** 期間内の取得量をリセットする日にち */
        optional<Int32> resetDayOfMonth;
        /** 期間内の取得量をリセットする曜日 */
        optional<StringHolder> resetDayOfWeek;
        /** 期間内の取得量をリセットする時 */
        optional<Int32> resetHour;
        /** 期間内の最大取得量 */
        optional<Int64> latestGainMax;
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
            name(data.name),
            meta(data.meta),
            balanceMax(data.balanceMax),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour),
            latestGainMax(data.latestGainMax),
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
            name(std::move(data.name)),
            meta(std::move(data.meta)),
            balanceMax(std::move(data.balanceMax)),
            resetType(std::move(data.resetType)),
            resetDayOfMonth(std::move(data.resetDayOfMonth)),
            resetDayOfWeek(std::move(data.resetDayOfWeek)),
            resetHour(std::move(data.resetHour)),
            latestGainMax(std::move(data.latestGainMax)),
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
    CreateGoldMasterRequest() :
        m_pData(nullptr)
    {}

    CreateGoldMasterRequest(const CreateGoldMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gold(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGoldMasterRequest(CreateGoldMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gold(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGoldMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGoldMasterRequest& operator=(const CreateGoldMasterRequest& createGoldMasterRequest)
    {
        Gs2BasicRequest::operator=(createGoldMasterRequest);
        Gs2Gold::operator=(createGoldMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGoldMasterRequest.m_pData);

        return *this;
    }

    CreateGoldMasterRequest& operator=(CreateGoldMasterRequest&& createGoldMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGoldMasterRequest));
        Gs2Gold::operator=(std::move(createGoldMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGoldMasterRequest.m_pData;
        createGoldMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGoldMasterRequest* operator->() const
    {
        return this;
    }

    CreateGoldMasterRequest* operator->()
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
    CreateGoldMasterRequest& withGoldPoolName(const Char* goldPoolName)
    {
        ensureData().goldPoolName.emplace(goldPoolName);
        return *this;
    }

    /**
     * ゴールド名を取得
     *
     * @return ゴールド名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ゴールド名を設定
     *
     * @param name ゴールド名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ゴールド名を設定
     *
     * @param name ゴールド名
     */
    CreateGoldMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
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
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    CreateGoldMasterRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
    }

    /**
     * 各ウォレットの残高の最大値を取得
     *
     * @return 各ウォレットの残高の最大値
     */
    const optional<Int64>& getBalanceMax() const
    {
        return ensureData().balanceMax;
    }

    /**
     * 各ウォレットの残高の最大値を設定
     *
     * @param balanceMax 各ウォレットの残高の最大値
     */
    void setBalanceMax(Int64 balanceMax)
    {
        ensureData().balanceMax.emplace(balanceMax);
    }

    /**
     * 各ウォレットの残高の最大値を設定
     *
     * @param balanceMax 各ウォレットの残高の最大値
     */
    CreateGoldMasterRequest& withBalanceMax(Int64 balanceMax)
    {
        ensureData().balanceMax.emplace(balanceMax);
        return *this;
    }

    /**
     * 取得量の期間制限のタイプを取得
     *
     * @return 取得量の期間制限のタイプ
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * 取得量の期間制限のタイプを設定
     *
     * @param resetType 取得量の期間制限のタイプ
     */
    void setResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
    }

    /**
     * 取得量の期間制限のタイプを設定
     *
     * @param resetType 取得量の期間制限のタイプ
     */
    CreateGoldMasterRequest& withResetType(const Char* resetType)
    {
        ensureData().resetType.emplace(resetType);
        return *this;
    }

    /**
     * 期間内の取得量をリセットする日にちを取得
     *
     * @return 期間内の取得量をリセットする日にち
     */
    const optional<Int32>& getResetDayOfMonth() const
    {
        return ensureData().resetDayOfMonth;
    }

    /**
     * 期間内の取得量をリセットする日にちを設定
     *
     * @param resetDayOfMonth 期間内の取得量をリセットする日にち
     */
    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
    }

    /**
     * 期間内の取得量をリセットする日にちを設定
     *
     * @param resetDayOfMonth 期間内の取得量をリセットする日にち
     */
    CreateGoldMasterRequest& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
        return *this;
    }

    /**
     * 期間内の取得量をリセットする曜日を取得
     *
     * @return 期間内の取得量をリセットする曜日
     */
    const optional<StringHolder>& getResetDayOfWeek() const
    {
        return ensureData().resetDayOfWeek;
    }

    /**
     * 期間内の取得量をリセットする曜日を設定
     *
     * @param resetDayOfWeek 期間内の取得量をリセットする曜日
     */
    void setResetDayOfWeek(const Char* resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(resetDayOfWeek);
    }

    /**
     * 期間内の取得量をリセットする曜日を設定
     *
     * @param resetDayOfWeek 期間内の取得量をリセットする曜日
     */
    CreateGoldMasterRequest& withResetDayOfWeek(const Char* resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(resetDayOfWeek);
        return *this;
    }

    /**
     * 期間内の取得量をリセットする時を取得
     *
     * @return 期間内の取得量をリセットする時
     */
    const optional<Int32>& getResetHour() const
    {
        return ensureData().resetHour;
    }

    /**
     * 期間内の取得量をリセットする時を設定
     *
     * @param resetHour 期間内の取得量をリセットする時
     */
    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
    }

    /**
     * 期間内の取得量をリセットする時を設定
     *
     * @param resetHour 期間内の取得量をリセットする時
     */
    CreateGoldMasterRequest& withResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
        return *this;
    }

    /**
     * 期間内の最大取得量を取得
     *
     * @return 期間内の最大取得量
     */
    const optional<Int64>& getLatestGainMax() const
    {
        return ensureData().latestGainMax;
    }

    /**
     * 期間内の最大取得量を設定
     *
     * @param latestGainMax 期間内の最大取得量
     */
    void setLatestGainMax(Int64 latestGainMax)
    {
        ensureData().latestGainMax.emplace(latestGainMax);
    }

    /**
     * 期間内の最大取得量を設定
     *
     * @param latestGainMax 期間内の最大取得量
     */
    CreateGoldMasterRequest& withLatestGainMax(Int64 latestGainMax)
    {
        ensureData().latestGainMax.emplace(latestGainMax);
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
    CreateGoldMasterRequest& withCreateWalletTriggerScript(const Char* createWalletTriggerScript)
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
    CreateGoldMasterRequest& withCreateWalletDoneTriggerScript(const Char* createWalletDoneTriggerScript)
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
    CreateGoldMasterRequest& withDepositIntoWalletTriggerScript(const Char* depositIntoWalletTriggerScript)
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
    CreateGoldMasterRequest& withDepositIntoWalletDoneTriggerScript(const Char* depositIntoWalletDoneTriggerScript)
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
    CreateGoldMasterRequest& withWithdrawFromWalletTriggerScript(const Char* withdrawFromWalletTriggerScript)
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
    CreateGoldMasterRequest& withWithdrawFromWalletDoneTriggerScript(const Char* withdrawFromWalletDoneTriggerScript)
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
    CreateGoldMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGoldMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGoldMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGoldMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GOLD_CONTROL_CREATEGOLDMASTERREQUEST_HPP_