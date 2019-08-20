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

#ifndef GS2_ACCOUNT_CONTROL_UPDATETIMEOFFSETREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_UPDATETIMEOFFSETREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * ゲームプレイヤーアカウントの現在時刻に対する補正値を更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateTimeOffsetRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** アカウントID */
        optional<StringHolder> userId;
        /** 現在時刻に対する補正値（現在時刻を起点とした秒数） */
        optional<Int32> timeOffset;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            timeOffset(data.timeOffset),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            userId(std::move(data.userId)),
            timeOffset(std::move(data.timeOffset)),
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
    UpdateTimeOffsetRequest() :
        m_pData(nullptr)
    {}

    UpdateTimeOffsetRequest(const UpdateTimeOffsetRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateTimeOffsetRequest(UpdateTimeOffsetRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateTimeOffsetRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateTimeOffsetRequest& operator=(const UpdateTimeOffsetRequest& updateTimeOffsetRequest)
    {
        Gs2BasicRequest::operator=(updateTimeOffsetRequest);
        Gs2Account::operator=(updateTimeOffsetRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateTimeOffsetRequest.m_pData);

        return *this;
    }

    UpdateTimeOffsetRequest& operator=(UpdateTimeOffsetRequest&& updateTimeOffsetRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateTimeOffsetRequest));
        Gs2Account::operator=(std::move(updateTimeOffsetRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateTimeOffsetRequest.m_pData;
        updateTimeOffsetRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateTimeOffsetRequest* operator->() const
    {
        return this;
    }

    UpdateTimeOffsetRequest* operator->()
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
    UpdateTimeOffsetRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * アカウントIDを取得
     *
     * @return アカウントID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * アカウントIDを設定
     *
     * @param userId アカウントID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * アカウントIDを設定
     *
     * @param userId アカウントID
     */
    UpdateTimeOffsetRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を取得
     *
     * @return 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    const optional<Int32>& getTimeOffset() const
    {
        return ensureData().timeOffset;
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を設定
     *
     * @param timeOffset 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    void setTimeOffset(Int32 timeOffset)
    {
        ensureData().timeOffset.emplace(timeOffset);
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を設定
     *
     * @param timeOffset 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    UpdateTimeOffsetRequest& withTimeOffset(Int32 timeOffset)
    {
        ensureData().timeOffset.emplace(timeOffset);
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
    UpdateTimeOffsetRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    UpdateTimeOffsetRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateTimeOffsetRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateTimeOffsetRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateTimeOffsetRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_UPDATETIMEOFFSETREQUEST_HPP_