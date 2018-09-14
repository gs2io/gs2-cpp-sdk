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

#ifndef GS2_LEVEL_CONTROL_GETSTATUSBYRESOURCETYPEREQUEST_HPP_
#define GS2_LEVEL_CONTROL_GETSTATUSBYRESOURCETYPEREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"

namespace gs2 { namespace level {

/**
 * @author Game Server Services, Inc.
 */
class GetStatusByResourceTypeRequest : public Gs2UserRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "GetStatus";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** リソースタイプ */
        optional<StringHolder> resourceTypeName;
        /** リソースID */
        optional<StringHolder> resourceId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            resourceTypeName(data.resourceTypeName),
            resourceId(data.resourceId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            resourceTypeName(std::move(data.resourceTypeName)),
            resourceId(std::move(data.resourceId))
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
    GetStatusByResourceTypeRequest() :
        m_pData(nullptr)
    {}

    GetStatusByResourceTypeRequest(const GetStatusByResourceTypeRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetStatusByResourceTypeRequest(GetStatusByResourceTypeRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetStatusByResourceTypeRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetStatusByResourceTypeRequest& operator=(const GetStatusByResourceTypeRequest& getStatusByResourceTypeRequest)
    {
        Gs2UserRequest::operator=(getStatusByResourceTypeRequest);
        Gs2Level::operator=(getStatusByResourceTypeRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getStatusByResourceTypeRequest.m_pData);

        return *this;
    }

    GetStatusByResourceTypeRequest& operator=(GetStatusByResourceTypeRequest&& getStatusByResourceTypeRequest)
    {
        Gs2UserRequest::operator=(std::move(getStatusByResourceTypeRequest));
        Gs2Level::operator=(std::move(getStatusByResourceTypeRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getStatusByResourceTypeRequest.m_pData;
        getStatusByResourceTypeRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * リソースプールを取得
     *
     * @return リソースプール
     */
    const optional<StringHolder>& getResourcePoolName() const
    {
        return ensureData().resourcePoolName;
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    void setResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    GetStatusByResourceTypeRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * リソースタイプを取得
     *
     * @return リソースタイプ
     */
    const optional<StringHolder>& getResourceTypeName() const
    {
        return ensureData().resourceTypeName;
    }

    /**
     * リソースタイプを設定
     *
     * @param resourceTypeName リソースタイプ
     */
    void setResourceTypeName(const Char* resourceTypeName)
    {
        ensureData().resourceTypeName.emplace(resourceTypeName);
    }

    /**
     * リソースタイプを設定
     *
     * @param resourceTypeName リソースタイプ
     */
    GetStatusByResourceTypeRequest& withResourceTypeName(const Char* resourceTypeName)
    {
        ensureData().resourceTypeName.emplace(resourceTypeName);
        return *this;
    }

    /**
     * リソースIDを取得
     *
     * @return リソースID
     */
    const optional<StringHolder>& getResourceId() const
    {
        return ensureData().resourceId;
    }

    /**
     * リソースIDを設定
     *
     * @param resourceId リソースID
     */
    void setResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
    }

    /**
     * リソースIDを設定
     *
     * @param resourceId リソースID
     */
    GetStatusByResourceTypeRequest& withResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetStatusByResourceTypeRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetStatusByResourceTypeRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetStatusByResourceTypeRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetStatusByResourceTypeRequest& withRequestId(const Char* gs2RequestId)
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
    GetStatusByResourceTypeRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_LEVEL_CONTROL_GETSTATUSBYRESOURCETYPEREQUEST_HPP_