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

#ifndef GS2_STAMINA_CONTROL_DELETERECOVERVALUETABLEMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_DELETERECOVERVALUETABLEMASTERREQUEST_HPP_

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
 * スタミナ回復量テーブルマスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteRecoverValueTableMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スタミナ回復量テーブル名 */
        optional<StringHolder> recoverValueTableName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            recoverValueTableName(data.recoverValueTableName)
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
    DeleteRecoverValueTableMasterRequest() = default;
    DeleteRecoverValueTableMasterRequest(const DeleteRecoverValueTableMasterRequest& deleteRecoverValueTableMasterRequest) = default;
    DeleteRecoverValueTableMasterRequest(DeleteRecoverValueTableMasterRequest&& deleteRecoverValueTableMasterRequest) = default;
    ~DeleteRecoverValueTableMasterRequest() GS2_OVERRIDE = default;

    DeleteRecoverValueTableMasterRequest& operator=(const DeleteRecoverValueTableMasterRequest& deleteRecoverValueTableMasterRequest) = default;
    DeleteRecoverValueTableMasterRequest& operator=(DeleteRecoverValueTableMasterRequest&& deleteRecoverValueTableMasterRequest) = default;

    DeleteRecoverValueTableMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteRecoverValueTableMasterRequest);
    }

    const DeleteRecoverValueTableMasterRequest* operator->() const
    {
        return this;
    }

    DeleteRecoverValueTableMasterRequest* operator->()
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
    DeleteRecoverValueTableMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * スタミナ回復量テーブル名を取得
     *
     * @return スタミナ回復量テーブル名
     */
    const optional<StringHolder>& getRecoverValueTableName() const
    {
        return ensureData().recoverValueTableName;
    }

    /**
     * スタミナ回復量テーブル名を設定
     *
     * @param recoverValueTableName スタミナ回復量テーブル名
     */
    void setRecoverValueTableName(StringHolder recoverValueTableName)
    {
        ensureData().recoverValueTableName.emplace(std::move(recoverValueTableName));
    }

    /**
     * スタミナ回復量テーブル名を設定
     *
     * @param recoverValueTableName スタミナ回復量テーブル名
     */
    DeleteRecoverValueTableMasterRequest& withRecoverValueTableName(StringHolder recoverValueTableName)
    {
        ensureData().recoverValueTableName.emplace(std::move(recoverValueTableName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteRecoverValueTableMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteRecoverValueTableMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_DELETERECOVERVALUETABLEMASTERREQUEST_HPP_