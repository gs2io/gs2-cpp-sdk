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

#ifndef GS2_EXPERIENCE_CONTROL_GETSTATUSESREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_GETSTATUSESREQUEST_HPP_

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
class GetStatusesRequest : public Gs2UserRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 経験値名 */
        optional<StringHolder> experienceName;
        /** プロパティのリスト */
        optional<List<Property>> properties;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            experienceName(data.experienceName),
            properties(data.properties),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            experienceName(std::move(data.experienceName)),
            properties(std::move(data.properties)),
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
    GetStatusesRequest() :
        m_pData(nullptr)
    {}

    GetStatusesRequest(const GetStatusesRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetStatusesRequest(GetStatusesRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetStatusesRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetStatusesRequest& operator=(const GetStatusesRequest& getStatusesRequest)
    {
        Gs2UserRequest::operator=(getStatusesRequest);
        Gs2Experience::operator=(getStatusesRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getStatusesRequest.m_pData);

        return *this;
    }

    GetStatusesRequest& operator=(GetStatusesRequest&& getStatusesRequest)
    {
        Gs2UserRequest::operator=(std::move(getStatusesRequest));
        Gs2Experience::operator=(std::move(getStatusesRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getStatusesRequest.m_pData;
        getStatusesRequest.m_pData = nullptr;

        return *this;
    }

    const GetStatusesRequest* operator->() const
    {
        return this;
    }

    GetStatusesRequest* operator->()
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
    GetStatusesRequest& withExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
        return *this;
    }

    /**
     * プロパティのリストを取得
     *
     * @return プロパティのリスト
     */
    const optional<List<Property>>& getProperties() const
    {
        return ensureData().properties;
    }

    /**
     * プロパティのリストを設定
     *
     * @param properties プロパティのリスト
     */
    void setProperties(const List<Property>& properties)
    {
        ensureData().properties.emplace(properties);
    }

    /**
     * プロパティのリストを設定
     *
     * @param properties プロパティのリスト
     */
    GetStatusesRequest& withProperties(const List<Property>& properties)
    {
        ensureData().properties.emplace(properties);
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
    GetStatusesRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    GetStatusesRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetStatusesRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetStatusesRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetStatusesRequest& withRequestId(const Char* gs2RequestId)
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
    GetStatusesRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_EXPERIENCE_CONTROL_GETSTATUSESREQUEST_HPP_