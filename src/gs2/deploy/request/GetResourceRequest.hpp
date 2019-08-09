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

#ifndef GS2_DEPLOY_CONTROL_GETRESOURCEREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_GETRESOURCEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DeployConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace deploy
{

/**
 * 作成されたのリソースを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetResourceRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタック名 */
        optional<StringHolder> stackName;
        /** 作成中のリソース名 */
        optional<StringHolder> resourceName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            stackName(data.stackName),
            resourceName(data.resourceName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            stackName(std::move(data.stackName)),
            resourceName(std::move(data.resourceName))
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
    GetResourceRequest() :
        m_pData(nullptr)
    {}

    GetResourceRequest(const GetResourceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Deploy(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetResourceRequest(GetResourceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Deploy(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetResourceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetResourceRequest& operator=(const GetResourceRequest& getResourceRequest)
    {
        Gs2BasicRequest::operator=(getResourceRequest);
        Gs2Deploy::operator=(getResourceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getResourceRequest.m_pData);

        return *this;
    }

    GetResourceRequest& operator=(GetResourceRequest&& getResourceRequest)
    {
        Gs2BasicRequest::operator=(std::move(getResourceRequest));
        Gs2Deploy::operator=(std::move(getResourceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getResourceRequest.m_pData;
        getResourceRequest.m_pData = nullptr;

        return *this;
    }

    const GetResourceRequest* operator->() const
    {
        return this;
    }

    GetResourceRequest* operator->()
    {
        return this;
    }

    /**
     * スタック名を取得
     *
     * @return スタック名
     */
    const optional<StringHolder>& getStackName() const
    {
        return ensureData().stackName;
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    void setStackName(const Char* stackName)
    {
        ensureData().stackName.emplace(stackName);
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    GetResourceRequest& withStackName(const Char* stackName)
    {
        ensureData().stackName.emplace(stackName);
        return *this;
    }

    /**
     * 作成中のリソース名を取得
     *
     * @return 作成中のリソース名
     */
    const optional<StringHolder>& getResourceName() const
    {
        return ensureData().resourceName;
    }

    /**
     * 作成中のリソース名を設定
     *
     * @param resourceName 作成中のリソース名
     */
    void setResourceName(const Char* resourceName)
    {
        ensureData().resourceName.emplace(resourceName);
    }

    /**
     * 作成中のリソース名を設定
     *
     * @param resourceName 作成中のリソース名
     */
    GetResourceRequest& withResourceName(const Char* resourceName)
    {
        ensureData().resourceName.emplace(resourceName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetResourceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetResourceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetResourceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetResourceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_GETRESOURCEREQUEST_HPP_