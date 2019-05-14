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

#ifndef GS2_EXPERIENCE_CONTROL_GETSTATUSREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_GETSTATUSREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"

namespace gs2 { namespace experience
{

/**
 * ステータスを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetStatusRequest : public Gs2UserRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 経験値名 */
        optional<StringHolder> experienceName;
        /** 経験値の種類名 */
        optional<StringHolder> experienceModelName;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            experienceName(data.experienceName),
            experienceModelName(data.experienceModelName),
            propertyId(data.propertyId),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            experienceName(std::move(data.experienceName)),
            experienceModelName(std::move(data.experienceModelName)),
            propertyId(std::move(data.propertyId)),
            duplicationAvoider(std::move(data.duplicationAvoider))
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
    GetStatusRequest() :
        m_pData(nullptr)
    {}

    GetStatusRequest(const GetStatusRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetStatusRequest(GetStatusRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetStatusRequest& operator=(const GetStatusRequest& getStatusRequest)
    {
        Gs2UserRequest::operator=(getStatusRequest);
        Gs2Experience::operator=(getStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getStatusRequest.m_pData);

        return *this;
    }

    GetStatusRequest& operator=(GetStatusRequest&& getStatusRequest)
    {
        Gs2UserRequest::operator=(std::move(getStatusRequest));
        Gs2Experience::operator=(std::move(getStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getStatusRequest.m_pData;
        getStatusRequest.m_pData = nullptr;

        return *this;
    }

    const GetStatusRequest* operator->() const
    {
        return this;
    }

    GetStatusRequest* operator->()
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
    GetStatusRequest& withExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
        return *this;
    }

    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getExperienceModelName() const
    {
        return ensureData().experienceModelName;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    void setExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    GetStatusRequest& withExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
        return *this;
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    GetStatusRequest& withPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    GetStatusRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetStatusRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    GetStatusRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
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

#endif //GS2_EXPERIENCE_CONTROL_GETSTATUSREQUEST_HPP_