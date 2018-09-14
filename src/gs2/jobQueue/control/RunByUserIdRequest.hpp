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

#ifndef GS2_JOBQUEUE_CONTROL_RUNBYUSERIDREQUEST_HPP_
#define GS2_JOBQUEUE_CONTROL_RUNBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2JobQueueConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace jobQueue
{

/**
 * @author Game Server Services, Inc.
 */
class RunByUserIdRequest : public Gs2BasicRequest, public Gs2JobQueue
{
public:
    constexpr static const Char* const FUNCTION = "RunByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** ジョブキューの名前 */
        optional<StringHolder> queueName;
        /** ユーザID */
        optional<StringHolder> userId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            queueName(data.queueName),
            userId(data.userId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            queueName(std::move(data.queueName)),
            userId(std::move(data.userId))
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
    RunByUserIdRequest() :
        m_pData(nullptr)
    {}

    RunByUserIdRequest(const RunByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2JobQueue(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    RunByUserIdRequest(RunByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2JobQueue(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~RunByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RunByUserIdRequest& operator=(const RunByUserIdRequest& runByUserIdRequest)
    {
        Gs2BasicRequest::operator=(runByUserIdRequest);
        Gs2JobQueue::operator=(runByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*runByUserIdRequest.m_pData);

        return *this;
    }

    RunByUserIdRequest& operator=(RunByUserIdRequest&& runByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(runByUserIdRequest));
        Gs2JobQueue::operator=(std::move(runByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = runByUserIdRequest.m_pData;
        runByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const RunByUserIdRequest* operator->() const
    {
        return this;
    }

    RunByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ジョブキューの名前を取得
     *
     * @return ジョブキューの名前
     */
    const optional<StringHolder>& getQueueName() const
    {
        return ensureData().queueName;
    }

    /**
     * ジョブキューの名前を設定
     *
     * @param queueName ジョブキューの名前
     */
    void setQueueName(const Char* queueName)
    {
        ensureData().queueName.emplace(queueName);
    }

    /**
     * ジョブキューの名前を設定
     *
     * @param queueName ジョブキューの名前
     */
    RunByUserIdRequest& withQueueName(const Char* queueName)
    {
        ensureData().queueName.emplace(queueName);
        return *this;
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    RunByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    RunByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    RunByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    RunByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    RunByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_JOBQUEUE_CONTROL_RUNBYUSERIDREQUEST_HPP_