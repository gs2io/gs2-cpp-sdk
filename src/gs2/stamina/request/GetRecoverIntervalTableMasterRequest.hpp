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

#ifndef GS2_STAMINA_CONTROL_GETRECOVERINTERVALTABLEMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_GETRECOVERINTERVALTABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/stamina/Gs2StaminaConst.hpp>
#include <gs2/stamina/model/model.hpp>
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * スタミナ回復間隔テーブルマスターを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetRecoverIntervalTableMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スタミナ回復間隔テーブル名 */
        optional<StringHolder> recoverIntervalTableName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            recoverIntervalTableName(data.recoverIntervalTableName)
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
    GetRecoverIntervalTableMasterRequest() = default;
    GetRecoverIntervalTableMasterRequest(const GetRecoverIntervalTableMasterRequest& getRecoverIntervalTableMasterRequest) = default;
    GetRecoverIntervalTableMasterRequest(GetRecoverIntervalTableMasterRequest&& getRecoverIntervalTableMasterRequest) = default;
    ~GetRecoverIntervalTableMasterRequest() GS2_OVERRIDE = default;

    GetRecoverIntervalTableMasterRequest& operator=(const GetRecoverIntervalTableMasterRequest& getRecoverIntervalTableMasterRequest) = default;
    GetRecoverIntervalTableMasterRequest& operator=(GetRecoverIntervalTableMasterRequest&& getRecoverIntervalTableMasterRequest) = default;

    GetRecoverIntervalTableMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetRecoverIntervalTableMasterRequest);
    }

    const GetRecoverIntervalTableMasterRequest* operator->() const
    {
        return this;
    }

    GetRecoverIntervalTableMasterRequest* operator->()
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
    GetRecoverIntervalTableMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * スタミナ回復間隔テーブル名を取得
     *
     * @return スタミナ回復間隔テーブル名
     */
    const optional<StringHolder>& getRecoverIntervalTableName() const
    {
        return ensureData().recoverIntervalTableName;
    }

    /**
     * スタミナ回復間隔テーブル名を設定
     *
     * @param recoverIntervalTableName スタミナ回復間隔テーブル名
     */
    void setRecoverIntervalTableName(StringHolder recoverIntervalTableName)
    {
        ensureData().recoverIntervalTableName.emplace(std::move(recoverIntervalTableName));
    }

    /**
     * スタミナ回復間隔テーブル名を設定
     *
     * @param recoverIntervalTableName スタミナ回復間隔テーブル名
     */
    GetRecoverIntervalTableMasterRequest& withRecoverIntervalTableName(StringHolder recoverIntervalTableName)
    {
        ensureData().recoverIntervalTableName.emplace(std::move(recoverIntervalTableName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetRecoverIntervalTableMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetRecoverIntervalTableMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_GETRECOVERINTERVALTABLEMASTERREQUEST_HPP_