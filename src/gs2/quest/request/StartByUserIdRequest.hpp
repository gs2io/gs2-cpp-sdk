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

#ifndef GS2_QUEST_CONTROL_STARTBYUSERIDREQUEST_HPP_
#define GS2_QUEST_CONTROL_STARTBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * ユーザIDを指定してクエストを開始 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class StartByUserIdRequest : public Gs2BasicRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
        /** クエストグループ名 */
        optional<StringHolder> questGroupName;
        /** クエストモデル名 */
        optional<StringHolder> questName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** すでに開始しているクエストがある場合にそれを破棄して開始するか */
        optional<Bool> force;
        /** スタンプシートの変数に適用する設定値 */
        optional<List<Config>> config;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            questGroupName(data.questGroupName),
            questName(data.questName),
            userId(data.userId),
            force(data.force),
            config(data.config),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            questGroupName(std::move(data.questGroupName)),
            questName(std::move(data.questName)),
            userId(std::move(data.userId)),
            force(std::move(data.force)),
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
    StartByUserIdRequest() :
        m_pData(nullptr)
    {}

    StartByUserIdRequest(const StartByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Quest(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    StartByUserIdRequest(StartByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Quest(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~StartByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    StartByUserIdRequest& operator=(const StartByUserIdRequest& startByUserIdRequest)
    {
        Gs2BasicRequest::operator=(startByUserIdRequest);
        Gs2Quest::operator=(startByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*startByUserIdRequest.m_pData);

        return *this;
    }

    StartByUserIdRequest& operator=(StartByUserIdRequest&& startByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(startByUserIdRequest));
        Gs2Quest::operator=(std::move(startByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = startByUserIdRequest.m_pData;
        startByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const StartByUserIdRequest* operator->() const
    {
        return this;
    }

    StartByUserIdRequest* operator->()
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
    StartByUserIdRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * クエストグループ名を取得
     *
     * @return クエストグループ名
     */
    const optional<StringHolder>& getQuestGroupName() const
    {
        return ensureData().questGroupName;
    }

    /**
     * クエストグループ名を設定
     *
     * @param questGroupName クエストグループ名
     */
    void setQuestGroupName(const Char* questGroupName)
    {
        ensureData().questGroupName.emplace(questGroupName);
    }

    /**
     * クエストグループ名を設定
     *
     * @param questGroupName クエストグループ名
     */
    StartByUserIdRequest& withQuestGroupName(const Char* questGroupName)
    {
        ensureData().questGroupName.emplace(questGroupName);
        return *this;
    }

    /**
     * クエストモデル名を取得
     *
     * @return クエストモデル名
     */
    const optional<StringHolder>& getQuestName() const
    {
        return ensureData().questName;
    }

    /**
     * クエストモデル名を設定
     *
     * @param questName クエストモデル名
     */
    void setQuestName(const Char* questName)
    {
        ensureData().questName.emplace(questName);
    }

    /**
     * クエストモデル名を設定
     *
     * @param questName クエストモデル名
     */
    StartByUserIdRequest& withQuestName(const Char* questName)
    {
        ensureData().questName.emplace(questName);
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
    StartByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * すでに開始しているクエストがある場合にそれを破棄して開始するかを取得
     *
     * @return すでに開始しているクエストがある場合にそれを破棄して開始するか
     */
    const optional<Bool>& getForce() const
    {
        return ensureData().force;
    }

    /**
     * すでに開始しているクエストがある場合にそれを破棄して開始するかを設定
     *
     * @param force すでに開始しているクエストがある場合にそれを破棄して開始するか
     */
    void setForce(Bool force)
    {
        ensureData().force.emplace(force);
    }

    /**
     * すでに開始しているクエストがある場合にそれを破棄して開始するかを設定
     *
     * @param force すでに開始しているクエストがある場合にそれを破棄して開始するか
     */
    StartByUserIdRequest& withForce(Bool force)
    {
        ensureData().force.emplace(force);
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
    StartByUserIdRequest& withConfig(const List<Config>& config)
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
    StartByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    StartByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    StartByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    StartByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    StartByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_QUEST_CONTROL_STARTBYUSERIDREQUEST_HPP_