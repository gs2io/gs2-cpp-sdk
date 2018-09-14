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

#ifndef GS2_LEVEL_CONTROL_DELETERESOURCETYPEMASTERREQUEST_HPP_
#define GS2_LEVEL_CONTROL_DELETERESOURCETYPEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace level
{

/**
 * @author Game Server Services, Inc.
 */
class DeleteResourceTypeMasterRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "DeleteResourceTypeMaster";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** リソースタイプ */
        optional<StringHolder> resourceTypeName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            resourceTypeName(data.resourceTypeName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            resourceTypeName(std::move(data.resourceTypeName))
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
    DeleteResourceTypeMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteResourceTypeMasterRequest(const DeleteResourceTypeMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteResourceTypeMasterRequest(DeleteResourceTypeMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteResourceTypeMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteResourceTypeMasterRequest& operator=(const DeleteResourceTypeMasterRequest& deleteResourceTypeMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteResourceTypeMasterRequest);
        Gs2Level::operator=(deleteResourceTypeMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteResourceTypeMasterRequest.m_pData);

        return *this;
    }

    DeleteResourceTypeMasterRequest& operator=(DeleteResourceTypeMasterRequest&& deleteResourceTypeMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteResourceTypeMasterRequest));
        Gs2Level::operator=(std::move(deleteResourceTypeMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteResourceTypeMasterRequest.m_pData;
        deleteResourceTypeMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteResourceTypeMasterRequest* operator->() const
    {
        return this;
    }

    DeleteResourceTypeMasterRequest* operator->()
    {
        return this;
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
    DeleteResourceTypeMasterRequest& withResourcePoolName(const Char* resourcePoolName)
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
    DeleteResourceTypeMasterRequest& withResourceTypeName(const Char* resourceTypeName)
    {
        ensureData().resourceTypeName.emplace(resourceTypeName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteResourceTypeMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteResourceTypeMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteResourceTypeMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteResourceTypeMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_DELETERESOURCETYPEMASTERREQUEST_HPP_