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

#ifndef GS2_LIMIT_CONTROL_COUNTUPREQUEST_HPP_
#define GS2_LIMIT_CONTROL_COUNTUPREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/limit/Gs2LimitConst.hpp>
#include <gs2/limit/model/model.hpp>
#include <memory>

namespace gs2 { namespace limit
{

/**
 * カウントアップ のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CountUpRequest : public Gs2BasicRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 回数制限の種類の名前 */
        optional<StringHolder> limitName;
        /** カウンターの名前 */
        optional<StringHolder> counterName;
        /** カウントアップする量 */
        optional<Int32> countUpValue;
        /** カウントアップを許容する最大値 を入力してください */
        optional<Int32> maxValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            limitName(data.limitName),
            counterName(data.counterName),
            countUpValue(data.countUpValue),
            maxValue(data.maxValue),
            duplicationAvoider(data.duplicationAvoider)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    CountUpRequest() = default;
    CountUpRequest(const CountUpRequest& countUpRequest) = default;
    CountUpRequest(CountUpRequest&& countUpRequest) = default;
    ~CountUpRequest() GS2_OVERRIDE = default;

    CountUpRequest& operator=(const CountUpRequest& countUpRequest) = default;
    CountUpRequest& operator=(CountUpRequest&& countUpRequest) = default;

    CountUpRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CountUpRequest);
    }

    const CountUpRequest* operator->() const
    {
        return this;
    }

    CountUpRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    CountUpRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    CountUpRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setLimitName(StringHolder limitName)
    {
        ensureData().limitName.emplace(std::move(limitName));
    }

    /**
     * 回数制限の種類の名前を設定
     *
     * @param limitName 回数制限の種類の名前
     */
    CountUpRequest& withLimitName(StringHolder limitName)
    {
        ensureData().limitName.emplace(std::move(limitName));
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
    void setCounterName(StringHolder counterName)
    {
        ensureData().counterName.emplace(std::move(counterName));
    }

    /**
     * カウンターの名前を設定
     *
     * @param counterName カウンターの名前
     */
    CountUpRequest& withCounterName(StringHolder counterName)
    {
        ensureData().counterName.emplace(std::move(counterName));
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
    CountUpRequest& withCountUpValue(Int32 countUpValue)
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
    CountUpRequest& withMaxValue(Int32 maxValue)
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
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    CountUpRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CountUpRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CountUpRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LIMIT_CONTROL_COUNTUPREQUEST_HPP_