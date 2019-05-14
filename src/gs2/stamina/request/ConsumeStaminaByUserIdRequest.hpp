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

#ifndef GS2_STAMINA_CONTROL_CONSUMESTAMINABYUSERIDREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CONSUMESTAMINABYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタミナを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class ConsumeStaminaByUserIdRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタミナの種類名 */
        optional<StringHolder> groupName;
        /** スタミナの種類名 */
        optional<StringHolder> staminaModelName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 消費するスタミナ量 */
        optional<Int32> consumeValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            groupName(data.groupName),
            staminaModelName(data.staminaModelName),
            userId(data.userId),
            consumeValue(data.consumeValue),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            groupName(std::move(data.groupName)),
            staminaModelName(std::move(data.staminaModelName)),
            userId(std::move(data.userId)),
            consumeValue(std::move(data.consumeValue)),
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
    ConsumeStaminaByUserIdRequest() :
        m_pData(nullptr)
    {}

    ConsumeStaminaByUserIdRequest(const ConsumeStaminaByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ConsumeStaminaByUserIdRequest(ConsumeStaminaByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ConsumeStaminaByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeStaminaByUserIdRequest& operator=(const ConsumeStaminaByUserIdRequest& consumeStaminaByUserIdRequest)
    {
        Gs2BasicRequest::operator=(consumeStaminaByUserIdRequest);
        Gs2Stamina::operator=(consumeStaminaByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeStaminaByUserIdRequest.m_pData);

        return *this;
    }

    ConsumeStaminaByUserIdRequest& operator=(ConsumeStaminaByUserIdRequest&& consumeStaminaByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(consumeStaminaByUserIdRequest));
        Gs2Stamina::operator=(std::move(consumeStaminaByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeStaminaByUserIdRequest.m_pData;
        consumeStaminaByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const ConsumeStaminaByUserIdRequest* operator->() const
    {
        return this;
    }

    ConsumeStaminaByUserIdRequest* operator->()
    {
        return this;
    }
    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    void setGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    ConsumeStaminaByUserIdRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
        return *this;
    }

    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getStaminaModelName() const
    {
        return ensureData().staminaModelName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaModelName スタミナの種類名
     */
    void setStaminaModelName(const Char* staminaModelName)
    {
        ensureData().staminaModelName.emplace(staminaModelName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaModelName スタミナの種類名
     */
    ConsumeStaminaByUserIdRequest& withStaminaModelName(const Char* staminaModelName)
    {
        ensureData().staminaModelName.emplace(staminaModelName);
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
    ConsumeStaminaByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 消費するスタミナ量を取得
     *
     * @return 消費するスタミナ量
     */
    const optional<Int32>& getConsumeValue() const
    {
        return ensureData().consumeValue;
    }

    /**
     * 消費するスタミナ量を設定
     *
     * @param consumeValue 消費するスタミナ量
     */
    void setConsumeValue(Int32 consumeValue)
    {
        ensureData().consumeValue.emplace(consumeValue);
    }

    /**
     * 消費するスタミナ量を設定
     *
     * @param consumeValue 消費するスタミナ量
     */
    ConsumeStaminaByUserIdRequest& withConsumeValue(Int32 consumeValue)
    {
        ensureData().consumeValue.emplace(consumeValue);
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
    ConsumeStaminaByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    ConsumeStaminaByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ConsumeStaminaByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ConsumeStaminaByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ConsumeStaminaByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_STAMINA_CONTROL_CONSUMESTAMINABYUSERIDREQUEST_HPP_