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

#ifndef GS2_SCHEDULE_CONTROL_TRIGGERBYUSERIDREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_TRIGGERBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScheduleConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * ユーザIDを指定してトリガーを登録 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class TriggerByUserIdRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** トリガーの名前 */
        optional<StringHolder> triggerName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** トリガーの引き方の方針 */
        optional<StringHolder> triggerStrategy;
        /** トリガーの有効期限(秒) */
        optional<Int32> ttl;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            triggerName(data.triggerName),
            userId(data.userId),
            triggerStrategy(data.triggerStrategy),
            ttl(data.ttl),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            triggerName(std::move(data.triggerName)),
            userId(std::move(data.userId)),
            triggerStrategy(std::move(data.triggerStrategy)),
            ttl(std::move(data.ttl)),
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
    TriggerByUserIdRequest() :
        m_pData(nullptr)
    {}

    TriggerByUserIdRequest(const TriggerByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    TriggerByUserIdRequest(TriggerByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~TriggerByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    TriggerByUserIdRequest& operator=(const TriggerByUserIdRequest& triggerByUserIdRequest)
    {
        Gs2BasicRequest::operator=(triggerByUserIdRequest);
        Gs2Schedule::operator=(triggerByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*triggerByUserIdRequest.m_pData);

        return *this;
    }

    TriggerByUserIdRequest& operator=(TriggerByUserIdRequest&& triggerByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(triggerByUserIdRequest));
        Gs2Schedule::operator=(std::move(triggerByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = triggerByUserIdRequest.m_pData;
        triggerByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const TriggerByUserIdRequest* operator->() const
    {
        return this;
    }

    TriggerByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    TriggerByUserIdRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * トリガーの名前を取得
     *
     * @return トリガーの名前
     */
    const optional<StringHolder>& getTriggerName() const
    {
        return ensureData().triggerName;
    }

    /**
     * トリガーの名前を設定
     *
     * @param triggerName トリガーの名前
     */
    void setTriggerName(const Char* triggerName)
    {
        ensureData().triggerName.emplace(triggerName);
    }

    /**
     * トリガーの名前を設定
     *
     * @param triggerName トリガーの名前
     */
    TriggerByUserIdRequest& withTriggerName(const Char* triggerName)
    {
        ensureData().triggerName.emplace(triggerName);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    TriggerByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * トリガーの引き方の方針を取得
     *
     * @return トリガーの引き方の方針
     */
    const optional<StringHolder>& getTriggerStrategy() const
    {
        return ensureData().triggerStrategy;
    }

    /**
     * トリガーの引き方の方針を設定
     *
     * @param triggerStrategy トリガーの引き方の方針
     */
    void setTriggerStrategy(const Char* triggerStrategy)
    {
        ensureData().triggerStrategy.emplace(triggerStrategy);
    }

    /**
     * トリガーの引き方の方針を設定
     *
     * @param triggerStrategy トリガーの引き方の方針
     */
    TriggerByUserIdRequest& withTriggerStrategy(const Char* triggerStrategy)
    {
        ensureData().triggerStrategy.emplace(triggerStrategy);
        return *this;
    }

    /**
     * トリガーの有効期限(秒)を取得
     *
     * @return トリガーの有効期限(秒)
     */
    const optional<Int32>& getTtl() const
    {
        return ensureData().ttl;
    }

    /**
     * トリガーの有効期限(秒)を設定
     *
     * @param ttl トリガーの有効期限(秒)
     */
    void setTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
    }

    /**
     * トリガーの有効期限(秒)を設定
     *
     * @param ttl トリガーの有効期限(秒)
     */
    TriggerByUserIdRequest& withTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
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
    TriggerByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    TriggerByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    TriggerByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    TriggerByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    TriggerByUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_TRIGGERBYUSERIDREQUEST_HPP_