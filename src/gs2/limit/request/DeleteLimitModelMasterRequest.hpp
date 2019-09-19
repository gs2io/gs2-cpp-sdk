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

#ifndef GS2_LIMIT_CONTROL_DELETELIMITMODELMASTERREQUEST_HPP_
#define GS2_LIMIT_CONTROL_DELETELIMITMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LimitConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace limit
{

/**
 * 回数制限の種類マスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteLimitModelMasterRequest : public Gs2BasicRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 回数制限の種類名 */
        optional<StringHolder> limitName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            limitName(data.limitName)
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
    DeleteLimitModelMasterRequest() = default;
    DeleteLimitModelMasterRequest(const DeleteLimitModelMasterRequest& deleteLimitModelMasterRequest) = default;
    DeleteLimitModelMasterRequest(DeleteLimitModelMasterRequest&& deleteLimitModelMasterRequest) = default;
    ~DeleteLimitModelMasterRequest() GS2_OVERRIDE = default;

    DeleteLimitModelMasterRequest& operator=(const DeleteLimitModelMasterRequest& deleteLimitModelMasterRequest) = default;
    DeleteLimitModelMasterRequest& operator=(DeleteLimitModelMasterRequest&& deleteLimitModelMasterRequest) = default;

    DeleteLimitModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteLimitModelMasterRequest);
    }

    const DeleteLimitModelMasterRequest* operator->() const
    {
        return this;
    }

    DeleteLimitModelMasterRequest* operator->()
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
    DeleteLimitModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 回数制限の種類名を取得
     *
     * @return 回数制限の種類名
     */
    const optional<StringHolder>& getLimitName() const
    {
        return ensureData().limitName;
    }

    /**
     * 回数制限の種類名を設定
     *
     * @param limitName 回数制限の種類名
     */
    void setLimitName(StringHolder limitName)
    {
        ensureData().limitName.emplace(std::move(limitName));
    }

    /**
     * 回数制限の種類名を設定
     *
     * @param limitName 回数制限の種類名
     */
    DeleteLimitModelMasterRequest& withLimitName(StringHolder limitName)
    {
        ensureData().limitName.emplace(std::move(limitName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteLimitModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteLimitModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LIMIT_CONTROL_DELETELIMITMODELMASTERREQUEST_HPP_