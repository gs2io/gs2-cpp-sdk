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

#ifndef GS2_STAMINA_CONTROL_RECOVERSTAMINABYUSERIDREQUEST_HPP_
#define GS2_STAMINA_CONTROL_RECOVERSTAMINABYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * ユーザIDを指定してスタミナを回復 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class RecoverStaminaByUserIdRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スタミナの種類名 */
        optional<StringHolder> staminaName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 回復するスタミナ量 */
        optional<Int32> recoverValue;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            staminaName(data.staminaName),
            userId(data.userId),
            recoverValue(data.recoverValue),
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
    RecoverStaminaByUserIdRequest() = default;
    RecoverStaminaByUserIdRequest(const RecoverStaminaByUserIdRequest& recoverStaminaByUserIdRequest) = default;
    RecoverStaminaByUserIdRequest(RecoverStaminaByUserIdRequest&& recoverStaminaByUserIdRequest) = default;
    ~RecoverStaminaByUserIdRequest() GS2_OVERRIDE = default;

    RecoverStaminaByUserIdRequest& operator=(const RecoverStaminaByUserIdRequest& recoverStaminaByUserIdRequest) = default;
    RecoverStaminaByUserIdRequest& operator=(RecoverStaminaByUserIdRequest&& recoverStaminaByUserIdRequest) = default;

    RecoverStaminaByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RecoverStaminaByUserIdRequest);
    }

    const RecoverStaminaByUserIdRequest* operator->() const
    {
        return this;
    }

    RecoverStaminaByUserIdRequest* operator->()
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    RecoverStaminaByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    RecoverStaminaByUserIdRequest& withStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
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
    RecoverStaminaByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * 回復するスタミナ量を取得
     *
     * @return 回復するスタミナ量
     */
    const optional<Int32>& getRecoverValue() const
    {
        return ensureData().recoverValue;
    }

    /**
     * 回復するスタミナ量を設定
     *
     * @param recoverValue 回復するスタミナ量
     */
    void setRecoverValue(Int32 recoverValue)
    {
        ensureData().recoverValue.emplace(recoverValue);
    }

    /**
     * 回復するスタミナ量を設定
     *
     * @param recoverValue 回復するスタミナ量
     */
    RecoverStaminaByUserIdRequest& withRecoverValue(Int32 recoverValue)
    {
        ensureData().recoverValue.emplace(recoverValue);
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
    RecoverStaminaByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    RecoverStaminaByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    RecoverStaminaByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_RECOVERSTAMINABYUSERIDREQUEST_HPP_