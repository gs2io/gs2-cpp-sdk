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

#ifndef GS2_EXPERIENCE_CONTROL_GETTHRESHOLDMASTERREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_GETTHRESHOLDMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ランクアップ閾値を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetThresholdMasterRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 経験値名 */
        optional<StringHolder> experienceName;
        /** ランクアップ閾値名 */
        optional<StringHolder> thresholdName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            experienceName(data.experienceName),
            thresholdName(data.thresholdName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            experienceName(std::move(data.experienceName)),
            thresholdName(std::move(data.thresholdName))
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
    GetThresholdMasterRequest() :
        m_pData(nullptr)
    {}

    GetThresholdMasterRequest(const GetThresholdMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetThresholdMasterRequest(GetThresholdMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetThresholdMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetThresholdMasterRequest& operator=(const GetThresholdMasterRequest& getThresholdMasterRequest)
    {
        Gs2BasicRequest::operator=(getThresholdMasterRequest);
        Gs2Experience::operator=(getThresholdMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getThresholdMasterRequest.m_pData);

        return *this;
    }

    GetThresholdMasterRequest& operator=(GetThresholdMasterRequest&& getThresholdMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(getThresholdMasterRequest));
        Gs2Experience::operator=(std::move(getThresholdMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getThresholdMasterRequest.m_pData;
        getThresholdMasterRequest.m_pData = nullptr;

        return *this;
    }

    const GetThresholdMasterRequest* operator->() const
    {
        return this;
    }

    GetThresholdMasterRequest* operator->()
    {
        return this;
    }
    /**
     * 経験値名を取得
     *
     * @return 経験値名
     */
    const optional<StringHolder>& getExperienceName() const
    {
        return ensureData().experienceName;
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    void setExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    GetThresholdMasterRequest& withExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
        return *this;
    }

    /**
     * ランクアップ閾値名を取得
     *
     * @return ランクアップ閾値名
     */
    const optional<StringHolder>& getThresholdName() const
    {
        return ensureData().thresholdName;
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param thresholdName ランクアップ閾値名
     */
    void setThresholdName(const Char* thresholdName)
    {
        ensureData().thresholdName.emplace(thresholdName);
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param thresholdName ランクアップ閾値名
     */
    GetThresholdMasterRequest& withThresholdName(const Char* thresholdName)
    {
        ensureData().thresholdName.emplace(thresholdName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetThresholdMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetThresholdMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetThresholdMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetThresholdMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_EXPERIENCE_CONTROL_GETTHRESHOLDMASTERREQUEST_HPP_