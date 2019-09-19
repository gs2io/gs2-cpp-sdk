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

#ifndef GS2_QUEST_CONTROL_ENDBYUSERIDREQUEST_HPP_
#define GS2_QUEST_CONTROL_ENDBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace quest
{

/**
 * ユーザIDを指定してクエストを完了 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class EndByUserIdRequest : public Gs2BasicRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** 実際にクエストで得た報酬 */
        optional<List<Reward>> rewards;
        /** クエストをクリアしたか */
        optional<Bool> isComplete;
        /** スタンプシートの変数に適用する設定値 */
        optional<List<Config>> config;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            transactionId(data.transactionId),
            isComplete(data.isComplete),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.rewards)
            {
                rewards = data.rewards->deepCopy();
            }
            if (data.config)
            {
                config = data.config->deepCopy();
            }
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
    EndByUserIdRequest() = default;
    EndByUserIdRequest(const EndByUserIdRequest& endByUserIdRequest) = default;
    EndByUserIdRequest(EndByUserIdRequest&& endByUserIdRequest) = default;
    ~EndByUserIdRequest() GS2_OVERRIDE = default;

    EndByUserIdRequest& operator=(const EndByUserIdRequest& endByUserIdRequest) = default;
    EndByUserIdRequest& operator=(EndByUserIdRequest&& endByUserIdRequest) = default;

    EndByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EndByUserIdRequest);
    }

    const EndByUserIdRequest* operator->() const
    {
        return this;
    }

    EndByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    EndByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    EndByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * トランザクションIDを取得
     *
     * @return トランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    EndByUserIdRequest& withTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
        return *this;
    }

    /**
     * 実際にクエストで得た報酬を取得
     *
     * @return 実際にクエストで得た報酬
     */
    const optional<List<Reward>>& getRewards() const
    {
        return ensureData().rewards;
    }

    /**
     * 実際にクエストで得た報酬を設定
     *
     * @param rewards 実際にクエストで得た報酬
     */
    void setRewards(List<Reward> rewards)
    {
        ensureData().rewards.emplace(std::move(rewards));
    }

    /**
     * 実際にクエストで得た報酬を設定
     *
     * @param rewards 実際にクエストで得た報酬
     */
    EndByUserIdRequest& withRewards(List<Reward> rewards)
    {
        ensureData().rewards.emplace(std::move(rewards));
        return *this;
    }

    /**
     * クエストをクリアしたかを取得
     *
     * @return クエストをクリアしたか
     */
    const optional<Bool>& getIsComplete() const
    {
        return ensureData().isComplete;
    }

    /**
     * クエストをクリアしたかを設定
     *
     * @param isComplete クエストをクリアしたか
     */
    void setIsComplete(Bool isComplete)
    {
        ensureData().isComplete.emplace(isComplete);
    }

    /**
     * クエストをクリアしたかを設定
     *
     * @param isComplete クエストをクリアしたか
     */
    EndByUserIdRequest& withIsComplete(Bool isComplete)
    {
        ensureData().isComplete.emplace(isComplete);
        return *this;
    }

    /**
     * スタンプシートの変数に適用する設定値を取得
     *
     * @return スタンプシートの変数に適用する設定値
     */
    const optional<List<Config>>& getConfig() const
    {
        return ensureData().config;
    }

    /**
     * スタンプシートの変数に適用する設定値を設定
     *
     * @param config スタンプシートの変数に適用する設定値
     */
    void setConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
    }

    /**
     * スタンプシートの変数に適用する設定値を設定
     *
     * @param config スタンプシートの変数に適用する設定値
     */
    EndByUserIdRequest& withConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
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
    EndByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    EndByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    EndByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_QUEST_CONTROL_ENDBYUSERIDREQUEST_HPP_