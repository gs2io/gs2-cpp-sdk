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

#ifndef GS2_DEPLOY_CONTROL_DELETESTACKREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_DELETESTACKREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DeployConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace deploy
{

/**
 * スタックを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteStackRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタック名 */
        optional<StringHolder> stackName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            stackName(data.stackName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            stackName(std::move(data.stackName))
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
    DeleteStackRequest() :
        m_pData(nullptr)
    {}

    DeleteStackRequest(const DeleteStackRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Deploy(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteStackRequest(DeleteStackRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Deploy(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteStackRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteStackRequest& operator=(const DeleteStackRequest& deleteStackRequest)
    {
        Gs2BasicRequest::operator=(deleteStackRequest);
        Gs2Deploy::operator=(deleteStackRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteStackRequest.m_pData);

        return *this;
    }

    DeleteStackRequest& operator=(DeleteStackRequest&& deleteStackRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteStackRequest));
        Gs2Deploy::operator=(std::move(deleteStackRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteStackRequest.m_pData;
        deleteStackRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteStackRequest* operator->() const
    {
        return this;
    }

    DeleteStackRequest* operator->()
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
    DeleteStackRequest& withStackName(const Char* stackName)
    {
        ensureData().stackName.emplace(stackName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteStackRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteStackRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteStackRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteStackRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_DEPLOY_CONTROL_DELETESTACKREQUEST_HPP_