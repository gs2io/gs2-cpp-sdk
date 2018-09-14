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

#ifndef GS2_JOBQUEUE_CONTROL_PUSHREQUEST_HPP_
#define GS2_JOBQUEUE_CONTROL_PUSHREQUEST_HPP_

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
class PushRequest : public Gs2BasicRequest, public Gs2JobQueue
{
public:
    constexpr static const Char* const FUNCTION = "Push";

private:
    class Data : public Gs2Object
    {
    public:
        /** ジョブキューの名前 */
        optional<StringHolder> queueName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** 追加するジョブの情報 */
        optional<List<PushJob>> jobs;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            queueName(data.queueName),
            userId(data.userId),
            jobs(data.jobs)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            queueName(std::move(data.queueName)),
            userId(std::move(data.userId)),
            jobs(std::move(data.jobs))
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
    PushRequest() :
        m_pData(nullptr)
    {}

    PushRequest(const PushRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2JobQueue(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    PushRequest(PushRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2JobQueue(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~PushRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PushRequest& operator=(const PushRequest& pushRequest)
    {
        Gs2BasicRequest::operator=(pushRequest);
        Gs2JobQueue::operator=(pushRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*pushRequest.m_pData);

        return *this;
    }

    PushRequest& operator=(PushRequest&& pushRequest)
    {
        Gs2BasicRequest::operator=(std::move(pushRequest));
        Gs2JobQueue::operator=(std::move(pushRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = pushRequest.m_pData;
        pushRequest.m_pData = nullptr;

        return *this;
    }

    const PushRequest* operator->() const
    {
        return this;
    }

    PushRequest* operator->()
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
    PushRequest& withQueueName(const Char* queueName)
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
    PushRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 追加するジョブの情報を取得
     *
     * @return 追加するジョブの情報
     */
    const optional<List<PushJob>>& getJobs() const
    {
        return ensureData().jobs;
    }

    /**
     * 追加するジョブの情報を設定
     *
     * @param jobs 追加するジョブの情報
     */
    void setJobs(const List<PushJob>& jobs)
    {
        ensureData().jobs.emplace(jobs);
    }

    /**
     * 追加するジョブの情報を設定
     *
     * @param jobs 追加するジョブの情報
     */
    PushRequest& withJobs(const List<PushJob>& jobs)
    {
        ensureData().jobs.emplace(jobs);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    PushRequest& withGs2ClientId(const Char* gs2ClientId)
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
    PushRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    PushRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PushRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_JOBQUEUE_CONTROL_PUSHREQUEST_HPP_