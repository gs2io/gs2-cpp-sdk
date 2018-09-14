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

#ifndef GS2_GACHA_CONTROL_UPDATEGACHAPOOLREQUEST_HPP_
#define GS2_GACHA_CONTROL_UPDATEGACHAPOOLREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GachaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gacha
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateGachaPoolRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "UpdateGachaPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプールの名前を指定します。 */
        optional<StringHolder> gachaPoolName;
        /** 説明文 */
        optional<StringHolder> description;
        /** 排出確率を公開するか */
        optional<StringHolder> publicDrawRate;
        /** ガチャ一覧の取得を許すか */
        optional<StringHolder> allowAccessGachaInfo;
        /** 抽選実行を制限するか */
        optional<StringHolder> restrict;
        /** 排出判定時 に実行されるGS2-Script */
        optional<StringHolder> drawPrizeTriggerScript;
        /** 排出判定完了時 に実行されるGS2-Script */
        optional<StringHolder> drawPrizeDoneTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gachaPoolName(data.gachaPoolName),
            description(data.description),
            publicDrawRate(data.publicDrawRate),
            allowAccessGachaInfo(data.allowAccessGachaInfo),
            restrict(data.restrict),
            drawPrizeTriggerScript(data.drawPrizeTriggerScript),
            drawPrizeDoneTriggerScript(data.drawPrizeDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gachaPoolName(std::move(data.gachaPoolName)),
            description(std::move(data.description)),
            publicDrawRate(std::move(data.publicDrawRate)),
            allowAccessGachaInfo(std::move(data.allowAccessGachaInfo)),
            restrict(std::move(data.restrict)),
            drawPrizeTriggerScript(std::move(data.drawPrizeTriggerScript)),
            drawPrizeDoneTriggerScript(std::move(data.drawPrizeDoneTriggerScript))
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
    UpdateGachaPoolRequest() :
        m_pData(nullptr)
    {}

    UpdateGachaPoolRequest(const UpdateGachaPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateGachaPoolRequest(UpdateGachaPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateGachaPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateGachaPoolRequest& operator=(const UpdateGachaPoolRequest& updateGachaPoolRequest)
    {
        Gs2BasicRequest::operator=(updateGachaPoolRequest);
        Gs2Gacha::operator=(updateGachaPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateGachaPoolRequest.m_pData);

        return *this;
    }

    UpdateGachaPoolRequest& operator=(UpdateGachaPoolRequest&& updateGachaPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateGachaPoolRequest));
        Gs2Gacha::operator=(std::move(updateGachaPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateGachaPoolRequest.m_pData;
        updateGachaPoolRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateGachaPoolRequest* operator->() const
    {
        return this;
    }

    UpdateGachaPoolRequest* operator->()
    {
        return this;
    }

    /**
     * ガチャプールの名前を指定します。を取得
     *
     * @return ガチャプールの名前を指定します。
     */
    const optional<StringHolder>& getGachaPoolName() const
    {
        return ensureData().gachaPoolName;
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    void setGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
    }

    /**
     * ガチャプールの名前を指定します。を設定
     *
     * @param gachaPoolName ガチャプールの名前を指定します。
     */
    UpdateGachaPoolRequest& withGachaPoolName(const Char* gachaPoolName)
    {
        ensureData().gachaPoolName.emplace(gachaPoolName);
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
    UpdateGachaPoolRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * 排出確率を公開するかを取得
     *
     * @return 排出確率を公開するか
     */
    const optional<StringHolder>& getPublicDrawRate() const
    {
        return ensureData().publicDrawRate;
    }

    /**
     * 排出確率を公開するかを設定
     *
     * @param publicDrawRate 排出確率を公開するか
     */
    void setPublicDrawRate(const Char* publicDrawRate)
    {
        ensureData().publicDrawRate.emplace(publicDrawRate);
    }

    /**
     * 排出確率を公開するかを設定
     *
     * @param publicDrawRate 排出確率を公開するか
     */
    UpdateGachaPoolRequest& withPublicDrawRate(const Char* publicDrawRate)
    {
        ensureData().publicDrawRate.emplace(publicDrawRate);
        return *this;
    }

    /**
     * ガチャ一覧の取得を許すかを取得
     *
     * @return ガチャ一覧の取得を許すか
     */
    const optional<StringHolder>& getAllowAccessGachaInfo() const
    {
        return ensureData().allowAccessGachaInfo;
    }

    /**
     * ガチャ一覧の取得を許すかを設定
     *
     * @param allowAccessGachaInfo ガチャ一覧の取得を許すか
     */
    void setAllowAccessGachaInfo(const Char* allowAccessGachaInfo)
    {
        ensureData().allowAccessGachaInfo.emplace(allowAccessGachaInfo);
    }

    /**
     * ガチャ一覧の取得を許すかを設定
     *
     * @param allowAccessGachaInfo ガチャ一覧の取得を許すか
     */
    UpdateGachaPoolRequest& withAllowAccessGachaInfo(const Char* allowAccessGachaInfo)
    {
        ensureData().allowAccessGachaInfo.emplace(allowAccessGachaInfo);
        return *this;
    }

    /**
     * 抽選実行を制限するかを取得
     *
     * @return 抽選実行を制限するか
     */
    const optional<StringHolder>& getRestrict() const
    {
        return ensureData().restrict;
    }

    /**
     * 抽選実行を制限するかを設定
     *
     * @param restrict 抽選実行を制限するか
     */
    void setRestrict(const Char* restrict)
    {
        ensureData().restrict.emplace(restrict);
    }

    /**
     * 抽選実行を制限するかを設定
     *
     * @param restrict 抽選実行を制限するか
     */
    UpdateGachaPoolRequest& withRestrict(const Char* restrict)
    {
        ensureData().restrict.emplace(restrict);
        return *this;
    }

    /**
     * 排出判定時 に実行されるGS2-Scriptを取得
     *
     * @return 排出判定時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDrawPrizeTriggerScript() const
    {
        return ensureData().drawPrizeTriggerScript;
    }

    /**
     * 排出判定時 に実行されるGS2-Scriptを設定
     *
     * @param drawPrizeTriggerScript 排出判定時 に実行されるGS2-Script
     */
    void setDrawPrizeTriggerScript(const Char* drawPrizeTriggerScript)
    {
        ensureData().drawPrizeTriggerScript.emplace(drawPrizeTriggerScript);
    }

    /**
     * 排出判定時 に実行されるGS2-Scriptを設定
     *
     * @param drawPrizeTriggerScript 排出判定時 に実行されるGS2-Script
     */
    UpdateGachaPoolRequest& withDrawPrizeTriggerScript(const Char* drawPrizeTriggerScript)
    {
        ensureData().drawPrizeTriggerScript.emplace(drawPrizeTriggerScript);
        return *this;
    }

    /**
     * 排出判定完了時 に実行されるGS2-Scriptを取得
     *
     * @return 排出判定完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDrawPrizeDoneTriggerScript() const
    {
        return ensureData().drawPrizeDoneTriggerScript;
    }

    /**
     * 排出判定完了時 に実行されるGS2-Scriptを設定
     *
     * @param drawPrizeDoneTriggerScript 排出判定完了時 に実行されるGS2-Script
     */
    void setDrawPrizeDoneTriggerScript(const Char* drawPrizeDoneTriggerScript)
    {
        ensureData().drawPrizeDoneTriggerScript.emplace(drawPrizeDoneTriggerScript);
    }

    /**
     * 排出判定完了時 に実行されるGS2-Scriptを設定
     *
     * @param drawPrizeDoneTriggerScript 排出判定完了時 に実行されるGS2-Script
     */
    UpdateGachaPoolRequest& withDrawPrizeDoneTriggerScript(const Char* drawPrizeDoneTriggerScript)
    {
        ensureData().drawPrizeDoneTriggerScript.emplace(drawPrizeDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateGachaPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateGachaPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateGachaPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateGachaPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_UPDATEGACHAPOOLREQUEST_HPP_