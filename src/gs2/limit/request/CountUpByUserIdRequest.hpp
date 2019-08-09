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

#ifndef GS2_LIMIT_CONTROL_COUNTUPBYUSERIDREQUEST_HPP_
#define GS2_LIMIT_CONTROL_COUNTUPBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LimitConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace limit
{

/**
 * ユーザIDを指定してカウントアップ のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CountUpByUserIdRequest : public Gs2BasicRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 回数制限の種類の名前 */
        optional<StringHolder> limitName;
        /** カウンターの名前 */
        optional<StringHolder> counterName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** カウントアップする量 */
        optional<Int32> countUpValue;
        /** カウントアップを許容する最大値 を入力してください */
        optional<Int32> maxValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            limitName(data.limitName),
            counterName(data.counterName),
            userId(data.userId),
            countUpValue(data.countUpValue),
            maxValue(data.maxValue),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            limitName(std::move(data.limitName)),
            counterName(std::move(data.counterName)),
            userId(std::move(data.userId)),
            countUpValue(std::move(data.countUpValue)),
            maxValue(std::move(data.maxValue)),
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
    CountUpByUserIdRequest() :
        m_pData(nullptr)
    {}

    CountUpByUserIdRequest(const CountUpByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Limit(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CountUpByUserIdRequest(CountUpByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Limit(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CountUpByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CountUpByUserIdRequest& operator=(const CountUpByUserIdRequest& countUpByUserIdRequest)
    {
        Gs2BasicRequest::operator=(countUpByUserIdRequest);
        Gs2Limit::operator=(countUpByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*countUpByUserIdRequest.m_pData);

        return *this;
    }

    CountUpByUserIdRequest& operator=(CountUpByUserIdRequest&& countUpByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(countUpByUserIdRequest));
        Gs2Limit::operator=(std::move(countUpByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = countUpByUserIdRequest.m_pData;
        countUpByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const CountUpByUserIdRequest* operator->() const
    {
        return this;
    }

    CountUpByUserIdRequest* operator->()
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
    CountUpByUserIdRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * 回数制限の種類の名前を取得
     *
     * @return 回数制限の種類の名前
     */
    const optional<StringHolder>& getLimitName() const
    {
        return ensureData().limitName;
    }

    /**
     * 回数制限の種類の名前を設定
     *
     * @param limitName 回数制限の種類の名前
     */
    void setLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
    }

    /**
     * 回数制限の種類の名前を設定
     *
     * @param limitName 回数制限の種類の名前
     */
    CountUpByUserIdRequest& withLimitName(const Char* limitName)
    {
        ensureData().limitName.emplace(limitName);
        return *this;
    }

    /**
     * カウンターの名前を取得
     *
     * @return カウンターの名前
     */
    const optional<StringHolder>& getCounterName() const
    {
        return ensureData().counterName;
    }

    /**
     * カウンターの名前を設定
     *
     * @param counterName カウンターの名前
     */
    void setCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
    }

    /**
     * カウンターの名前を設定
     *
     * @param counterName カウンターの名前
     */
    CountUpByUserIdRequest& withCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
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
    CountUpByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * カウントアップする量を取得
     *
     * @return カウントアップする量
     */
    const optional<Int32>& getCountUpValue() const
    {
        return ensureData().countUpValue;
    }

    /**
     * カウントアップする量を設定
     *
     * @param countUpValue カウントアップする量
     */
    void setCountUpValue(Int32 countUpValue)
    {
        ensureData().countUpValue.emplace(countUpValue);
    }

    /**
     * カウントアップする量を設定
     *
     * @param countUpValue カウントアップする量
     */
    CountUpByUserIdRequest& withCountUpValue(Int32 countUpValue)
    {
        ensureData().countUpValue.emplace(countUpValue);
        return *this;
    }

    /**
     * カウントアップを許容する最大値 を入力してくださいを取得
     *
     * @return カウントアップを許容する最大値 を入力してください
     */
    const optional<Int32>& getMaxValue() const
    {
        return ensureData().maxValue;
    }

    /**
     * カウントアップを許容する最大値 を入力してくださいを設定
     *
     * @param maxValue カウントアップを許容する最大値 を入力してください
     */
    void setMaxValue(Int32 maxValue)
    {
        ensureData().maxValue.emplace(maxValue);
    }

    /**
     * カウントアップを許容する最大値 を入力してくださいを設定
     *
     * @param maxValue カウントアップを許容する最大値 を入力してください
     */
    CountUpByUserIdRequest& withMaxValue(Int32 maxValue)
    {
        ensureData().maxValue.emplace(maxValue);
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
    CountUpByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    CountUpByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CountUpByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CountUpByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CountUpByUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_LIMIT_CONTROL_COUNTUPBYUSERIDREQUEST_HPP_