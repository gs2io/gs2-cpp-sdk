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

#ifndef GS2_GACHA_CONTROL_CREATEGACHAPOOLREQUEST_HPP_
#define GS2_GACHA_CONTROL_CREATEGACHAPOOLREQUEST_HPP_

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
class CreateGachaPoolRequest : public Gs2BasicRequest, public Gs2Gacha
{
public:
    constexpr static const Char* const FUNCTION = "CreateGachaPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** ガチャプール名 */
        optional<StringHolder> name;
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
            name(data.name),
            description(data.description),
            publicDrawRate(data.publicDrawRate),
            allowAccessGachaInfo(data.allowAccessGachaInfo),
            restrict(data.restrict),
            drawPrizeTriggerScript(data.drawPrizeTriggerScript),
            drawPrizeDoneTriggerScript(data.drawPrizeDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
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
    CreateGachaPoolRequest() :
        m_pData(nullptr)
    {}

    CreateGachaPoolRequest(const CreateGachaPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gacha(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGachaPoolRequest(CreateGachaPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gacha(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGachaPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGachaPoolRequest& operator=(const CreateGachaPoolRequest& createGachaPoolRequest)
    {
        Gs2BasicRequest::operator=(createGachaPoolRequest);
        Gs2Gacha::operator=(createGachaPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGachaPoolRequest.m_pData);

        return *this;
    }

    CreateGachaPoolRequest& operator=(CreateGachaPoolRequest&& createGachaPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGachaPoolRequest));
        Gs2Gacha::operator=(std::move(createGachaPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGachaPoolRequest.m_pData;
        createGachaPoolRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGachaPoolRequest* operator->() const
    {
        return this;
    }

    CreateGachaPoolRequest* operator->()
    {
        return this;
    }

    /**
     * ガチャプール名を取得
     *
     * @return ガチャプール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ガチャプール名を設定
     *
     * @param name ガチャプール名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ガチャプール名を設定
     *
     * @param name ガチャプール名
     */
    CreateGachaPoolRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateGachaPoolRequest& withDescription(const Char* description)
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
    CreateGachaPoolRequest& withPublicDrawRate(const Char* publicDrawRate)
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
    CreateGachaPoolRequest& withAllowAccessGachaInfo(const Char* allowAccessGachaInfo)
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
    CreateGachaPoolRequest& withRestrict(const Char* restrict)
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
    CreateGachaPoolRequest& withDrawPrizeTriggerScript(const Char* drawPrizeTriggerScript)
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
    CreateGachaPoolRequest& withDrawPrizeDoneTriggerScript(const Char* drawPrizeDoneTriggerScript)
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
    CreateGachaPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGachaPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGachaPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGachaPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_GACHA_CONTROL_CREATEGACHAPOOLREQUEST_HPP_