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

#ifndef GS2_SHOWCASE_CONTROL_UPDATESHOWCASEREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATESHOWCASEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateShowcaseRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "UpdateShowcase";

private:
    class Data : public Gs2Object
    {
    public:
        /** ショーケースの名前 */
        optional<StringHolder> showcaseName;
        /** 説明文 */
        optional<StringHolder> description;
        /** 公開許可判定 に実行されるGS2-Script */
        optional<StringHolder> releaseConditionTriggerScript;
        /** 購入直前 に実行されるGS2-Script */
        optional<StringHolder> buyTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            showcaseName(data.showcaseName),
            description(data.description),
            releaseConditionTriggerScript(data.releaseConditionTriggerScript),
            buyTriggerScript(data.buyTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            showcaseName(std::move(data.showcaseName)),
            description(std::move(data.description)),
            releaseConditionTriggerScript(std::move(data.releaseConditionTriggerScript)),
            buyTriggerScript(std::move(data.buyTriggerScript))
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
    UpdateShowcaseRequest() :
        m_pData(nullptr)
    {}

    UpdateShowcaseRequest(const UpdateShowcaseRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateShowcaseRequest(UpdateShowcaseRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateShowcaseRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateShowcaseRequest& operator=(const UpdateShowcaseRequest& updateShowcaseRequest)
    {
        Gs2BasicRequest::operator=(updateShowcaseRequest);
        Gs2Showcase::operator=(updateShowcaseRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateShowcaseRequest.m_pData);

        return *this;
    }

    UpdateShowcaseRequest& operator=(UpdateShowcaseRequest&& updateShowcaseRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateShowcaseRequest));
        Gs2Showcase::operator=(std::move(updateShowcaseRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateShowcaseRequest.m_pData;
        updateShowcaseRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateShowcaseRequest* operator->() const
    {
        return this;
    }

    UpdateShowcaseRequest* operator->()
    {
        return this;
    }

    /**
     * ショーケースの名前を取得
     *
     * @return ショーケースの名前
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    void setShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
    }

    /**
     * ショーケースの名前を設定
     *
     * @param showcaseName ショーケースの名前
     */
    UpdateShowcaseRequest& withShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
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
    UpdateShowcaseRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * 公開許可判定 に実行されるGS2-Scriptを取得
     *
     * @return 公開許可判定 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReleaseConditionTriggerScript() const
    {
        return ensureData().releaseConditionTriggerScript;
    }

    /**
     * 公開許可判定 に実行されるGS2-Scriptを設定
     *
     * @param releaseConditionTriggerScript 公開許可判定 に実行されるGS2-Script
     */
    void setReleaseConditionTriggerScript(const Char* releaseConditionTriggerScript)
    {
        ensureData().releaseConditionTriggerScript.emplace(releaseConditionTriggerScript);
    }

    /**
     * 公開許可判定 に実行されるGS2-Scriptを設定
     *
     * @param releaseConditionTriggerScript 公開許可判定 に実行されるGS2-Script
     */
    UpdateShowcaseRequest& withReleaseConditionTriggerScript(const Char* releaseConditionTriggerScript)
    {
        ensureData().releaseConditionTriggerScript.emplace(releaseConditionTriggerScript);
        return *this;
    }

    /**
     * 購入直前 に実行されるGS2-Scriptを取得
     *
     * @return 購入直前 に実行されるGS2-Script
     */
    const optional<StringHolder>& getBuyTriggerScript() const
    {
        return ensureData().buyTriggerScript;
    }

    /**
     * 購入直前 に実行されるGS2-Scriptを設定
     *
     * @param buyTriggerScript 購入直前 に実行されるGS2-Script
     */
    void setBuyTriggerScript(const Char* buyTriggerScript)
    {
        ensureData().buyTriggerScript.emplace(buyTriggerScript);
    }

    /**
     * 購入直前 に実行されるGS2-Scriptを設定
     *
     * @param buyTriggerScript 購入直前 に実行されるGS2-Script
     */
    UpdateShowcaseRequest& withBuyTriggerScript(const Char* buyTriggerScript)
    {
        ensureData().buyTriggerScript.emplace(buyTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateShowcaseRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateShowcaseRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateShowcaseRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateShowcaseRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SHOWCASE_CONTROL_UPDATESHOWCASEREQUEST_HPP_