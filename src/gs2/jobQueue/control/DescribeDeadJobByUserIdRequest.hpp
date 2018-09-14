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

#ifndef GS2_JOBQUEUE_CONTROL_DESCRIBEDEADJOBBYUSERIDREQUEST_HPP_
#define GS2_JOBQUEUE_CONTROL_DESCRIBEDEADJOBBYUSERIDREQUEST_HPP_

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
class DescribeDeadJobByUserIdRequest : public Gs2BasicRequest, public Gs2JobQueue
{
public:
    constexpr static const Char* const FUNCTION = "DescribeDeadJobByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** ジョブキューの名前を指定します。 */
        optional<StringHolder> queueName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** データの取得を開始する位置を指定するトークン */
        optional<StringHolder> pageToken;
        /** データの取得件数 */
        optional<Int32> limit;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            queueName(data.queueName),
            userId(data.userId),
            pageToken(data.pageToken),
            limit(data.limit)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            queueName(std::move(data.queueName)),
            userId(std::move(data.userId)),
            pageToken(std::move(data.pageToken)),
            limit(std::move(data.limit))
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
    DescribeDeadJobByUserIdRequest() :
        m_pData(nullptr)
    {}

    DescribeDeadJobByUserIdRequest(const DescribeDeadJobByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2JobQueue(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeDeadJobByUserIdRequest(DescribeDeadJobByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2JobQueue(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeDeadJobByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeDeadJobByUserIdRequest& operator=(const DescribeDeadJobByUserIdRequest& describeDeadJobByUserIdRequest)
    {
        Gs2BasicRequest::operator=(describeDeadJobByUserIdRequest);
        Gs2JobQueue::operator=(describeDeadJobByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeDeadJobByUserIdRequest.m_pData);

        return *this;
    }

    DescribeDeadJobByUserIdRequest& operator=(DescribeDeadJobByUserIdRequest&& describeDeadJobByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeDeadJobByUserIdRequest));
        Gs2JobQueue::operator=(std::move(describeDeadJobByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeDeadJobByUserIdRequest.m_pData;
        describeDeadJobByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeDeadJobByUserIdRequest* operator->() const
    {
        return this;
    }

    DescribeDeadJobByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ジョブキューの名前を指定します。を取得
     *
     * @return ジョブキューの名前を指定します。
     */
    const optional<StringHolder>& getQueueName() const
    {
        return ensureData().queueName;
    }

    /**
     * ジョブキューの名前を指定します。を設定
     *
     * @param queueName ジョブキューの名前を指定します。
     */
    void setQueueName(const Char* queueName)
    {
        ensureData().queueName.emplace(queueName);
    }

    /**
     * ジョブキューの名前を指定します。を設定
     *
     * @param queueName ジョブキューの名前を指定します。
     */
    DescribeDeadJobByUserIdRequest& withQueueName(const Char* queueName)
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
    DescribeDeadJobByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * データの取得を開始する位置を指定するトークンを取得
     *
     * @return データの取得を開始する位置を指定するトークン
     */
    const optional<StringHolder>& getPageToken() const
    {
        return ensureData().pageToken;
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    void setPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    DescribeDeadJobByUserIdRequest& withPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
        return *this;
    }

    /**
     * データの取得件数を取得
     *
     * @return データの取得件数
     */
    const optional<Int32>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    void setLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    DescribeDeadJobByUserIdRequest& withLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeDeadJobByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeDeadJobByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeDeadJobByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeDeadJobByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_JOBQUEUE_CONTROL_DESCRIBEDEADJOBBYUSERIDREQUEST_HPP_