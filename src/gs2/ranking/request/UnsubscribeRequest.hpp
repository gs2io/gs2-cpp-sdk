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

#ifndef GS2_RANKING_CONTROL_UNSUBSCRIBEREQUEST_HPP_
#define GS2_RANKING_CONTROL_UNSUBSCRIBEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/Gs2RankingConst.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * 購読の購読を解除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UnsubscribeRequest : public Gs2BasicRequest, public Gs2Ranking
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
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** 購読されるユーザID */
        optional<StringHolder> targetUserId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            categoryName(data.categoryName),
            targetUserId(data.targetUserId),
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
    UnsubscribeRequest() = default;
    UnsubscribeRequest(const UnsubscribeRequest& unsubscribeRequest) = default;
    UnsubscribeRequest(UnsubscribeRequest&& unsubscribeRequest) = default;
    ~UnsubscribeRequest() GS2_OVERRIDE = default;

    UnsubscribeRequest& operator=(const UnsubscribeRequest& unsubscribeRequest) = default;
    UnsubscribeRequest& operator=(UnsubscribeRequest&& unsubscribeRequest) = default;

    UnsubscribeRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UnsubscribeRequest);
    }

    const UnsubscribeRequest* operator->() const
    {
        return this;
    }

    UnsubscribeRequest* operator->()
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
    UnsubscribeRequest& withAccessToken(StringHolder accessToken)
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
    UnsubscribeRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    void setCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    UnsubscribeRequest& withCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
        return *this;
    }

    /**
     * 購読されるユーザIDを取得
     *
     * @return 購読されるユーザID
     */
    const optional<StringHolder>& getTargetUserId() const
    {
        return ensureData().targetUserId;
    }

    /**
     * 購読されるユーザIDを設定
     *
     * @param targetUserId 購読されるユーザID
     */
    void setTargetUserId(StringHolder targetUserId)
    {
        ensureData().targetUserId.emplace(std::move(targetUserId));
    }

    /**
     * 購読されるユーザIDを設定
     *
     * @param targetUserId 購読されるユーザID
     */
    UnsubscribeRequest& withTargetUserId(StringHolder targetUserId)
    {
        ensureData().targetUserId.emplace(std::move(targetUserId));
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
    UnsubscribeRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    UnsubscribeRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UnsubscribeRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_RANKING_CONTROL_UNSUBSCRIBEREQUEST_HPP_