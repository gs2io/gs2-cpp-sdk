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

#ifndef GS2_DEPLOY_CONTROL_GETOUTPUTREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_GETOUTPUTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DeployConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace deploy
{

/**
 * アウトプットを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetOutputRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタック名 */
        optional<StringHolder> stackName;
        /** アウトプット名 */
        optional<StringHolder> outputName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            stackName(data.stackName),
            outputName(data.outputName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            stackName(std::move(data.stackName)),
            outputName(std::move(data.outputName))
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
    GetOutputRequest() :
        m_pData(nullptr)
    {}

    GetOutputRequest(const GetOutputRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Deploy(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetOutputRequest(GetOutputRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Deploy(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetOutputRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetOutputRequest& operator=(const GetOutputRequest& getOutputRequest)
    {
        Gs2BasicRequest::operator=(getOutputRequest);
        Gs2Deploy::operator=(getOutputRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getOutputRequest.m_pData);

        return *this;
    }

    GetOutputRequest& operator=(GetOutputRequest&& getOutputRequest)
    {
        Gs2BasicRequest::operator=(std::move(getOutputRequest));
        Gs2Deploy::operator=(std::move(getOutputRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getOutputRequest.m_pData;
        getOutputRequest.m_pData = nullptr;

        return *this;
    }

    const GetOutputRequest* operator->() const
    {
        return this;
    }

    GetOutputRequest* operator->()
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
    GetOutputRequest& withStackName(const Char* stackName)
    {
        ensureData().stackName.emplace(stackName);
        return *this;
    }

    /**
     * アウトプット名を取得
     *
     * @return アウトプット名
     */
    const optional<StringHolder>& getOutputName() const
    {
        return ensureData().outputName;
    }

    /**
     * アウトプット名を設定
     *
     * @param outputName アウトプット名
     */
    void setOutputName(const Char* outputName)
    {
        ensureData().outputName.emplace(outputName);
    }

    /**
     * アウトプット名を設定
     *
     * @param outputName アウトプット名
     */
    GetOutputRequest& withOutputName(const Char* outputName)
    {
        ensureData().outputName.emplace(outputName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetOutputRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetOutputRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetOutputRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetOutputRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_GETOUTPUTREQUEST_HPP_