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

#ifndef GS2_QUEST_CONTROL_ENDREQUEST_HPP_
#define GS2_QUEST_CONTROL_ENDREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"

namespace gs2 { namespace quest
{

/**
 * クエストを完了 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class EndRequest : public Gs2UserRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            transactionId(data.transactionId),
            rewards(data.rewards),
            isComplete(data.isComplete),
            config(data.config),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            transactionId(std::move(data.transactionId)),
            rewards(std::move(data.rewards)),
            isComplete(std::move(data.isComplete)),
            config(std::move(data.config)),
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
    EndRequest() :
        m_pData(nullptr)
    {}

    EndRequest(const EndRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Quest(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    EndRequest(EndRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Quest(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~EndRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    EndRequest& operator=(const EndRequest& endRequest)
    {
        Gs2UserRequest::operator=(endRequest);
        Gs2Quest::operator=(endRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*endRequest.m_pData);

        return *this;
    }

    EndRequest& operator=(EndRequest&& endRequest)
    {
        Gs2UserRequest::operator=(std::move(endRequest));
        Gs2Quest::operator=(std::move(endRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = endRequest.m_pData;
        endRequest.m_pData = nullptr;

        return *this;
    }

    const EndRequest* operator->() const
    {
        return this;
    }

    EndRequest* operator->()
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    EndRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    EndRequest& withTransactionId(const Char* transactionId)
    {
        ensureData().transactionId.emplace(transactionId);
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
    void setRewards(const List<Reward>& rewards)
    {
        ensureData().rewards.emplace(rewards);
    }

    /**
     * 実際にクエストで得た報酬を設定
     *
     * @param rewards 実際にクエストで得た報酬
     */
    EndRequest& withRewards(const List<Reward>& rewards)
    {
        ensureData().rewards.emplace(rewards);
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
    EndRequest& withIsComplete(Bool isComplete)
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
    void setConfig(const List<Config>& config)
    {
        ensureData().config.emplace(config);
    }

    /**
     * スタンプシートの変数に適用する設定値を設定
     *
     * @param config スタンプシートの変数に適用する設定値
     */
    EndRequest& withConfig(const List<Config>& config)
    {
        ensureData().config.emplace(config);
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
    EndRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    EndRequest& withGs2ClientId(const Char* gs2ClientId)
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
    EndRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    EndRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    EndRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    EndRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
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

#endif //GS2_QUEST_CONTROL_ENDREQUEST_HPP_