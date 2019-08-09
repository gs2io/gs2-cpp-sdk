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

#ifndef GS2_STAMINA_CONTROL_UPDATESTAMINABYUSERIDREQUEST_HPP_
#define GS2_STAMINA_CONTROL_UPDATESTAMINABYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * ユーザIDを指定してスタミナを作成・更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateStaminaByUserIdRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スタミナの種類名 */
        optional<StringHolder> staminaName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 最終更新時におけるスタミナ値 */
        optional<Int32> value;
        /** スタミナの最大値 */
        optional<Int32> maxValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            staminaName(data.staminaName),
            userId(data.userId),
            value(data.value),
            maxValue(data.maxValue),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            staminaName(std::move(data.staminaName)),
            userId(std::move(data.userId)),
            value(std::move(data.value)),
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
    UpdateStaminaByUserIdRequest() :
        m_pData(nullptr)
    {}

    UpdateStaminaByUserIdRequest(const UpdateStaminaByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateStaminaByUserIdRequest(UpdateStaminaByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateStaminaByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateStaminaByUserIdRequest& operator=(const UpdateStaminaByUserIdRequest& updateStaminaByUserIdRequest)
    {
        Gs2BasicRequest::operator=(updateStaminaByUserIdRequest);
        Gs2Stamina::operator=(updateStaminaByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateStaminaByUserIdRequest.m_pData);

        return *this;
    }

    UpdateStaminaByUserIdRequest& operator=(UpdateStaminaByUserIdRequest&& updateStaminaByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateStaminaByUserIdRequest));
        Gs2Stamina::operator=(std::move(updateStaminaByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateStaminaByUserIdRequest.m_pData;
        updateStaminaByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateStaminaByUserIdRequest* operator->() const
    {
        return this;
    }

    UpdateStaminaByUserIdRequest* operator->()
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
    UpdateStaminaByUserIdRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getStaminaName() const
    {
        return ensureData().staminaName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    void setStaminaName(const Char* staminaName)
    {
        ensureData().staminaName.emplace(staminaName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    UpdateStaminaByUserIdRequest& withStaminaName(const Char* staminaName)
    {
        ensureData().staminaName.emplace(staminaName);
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
    UpdateStaminaByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 最終更新時におけるスタミナ値を取得
     *
     * @return 最終更新時におけるスタミナ値
     */
    const optional<Int32>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 最終更新時におけるスタミナ値を設定
     *
     * @param value 最終更新時におけるスタミナ値
     */
    void setValue(Int32 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 最終更新時におけるスタミナ値を設定
     *
     * @param value 最終更新時におけるスタミナ値
     */
    UpdateStaminaByUserIdRequest& withValue(Int32 value)
    {
        ensureData().value.emplace(value);
        return *this;
    }

    /**
     * スタミナの最大値を取得
     *
     * @return スタミナの最大値
     */
    const optional<Int32>& getMaxValue() const
    {
        return ensureData().maxValue;
    }

    /**
     * スタミナの最大値を設定
     *
     * @param maxValue スタミナの最大値
     */
    void setMaxValue(Int32 maxValue)
    {
        ensureData().maxValue.emplace(maxValue);
    }

    /**
     * スタミナの最大値を設定
     *
     * @param maxValue スタミナの最大値
     */
    UpdateStaminaByUserIdRequest& withMaxValue(Int32 maxValue)
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
    UpdateStaminaByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    UpdateStaminaByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateStaminaByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateStaminaByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateStaminaByUserIdRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATESTAMINABYUSERIDREQUEST_HPP_