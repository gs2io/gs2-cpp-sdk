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

#ifndef GS2_FORMATION_CONTROL_GETFORMMODELMASTERREQUEST_HPP_
#define GS2_FORMATION_CONTROL_GETFORMMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/Gs2FormationConst.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * フォームマスターを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetFormModelMasterRequest : public Gs2BasicRequest, public Gs2Formation
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** フォーム名 */
        optional<StringHolder> formModelName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            formModelName(data.formModelName)
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
    GetFormModelMasterRequest() = default;
    GetFormModelMasterRequest(const GetFormModelMasterRequest& getFormModelMasterRequest) = default;
    GetFormModelMasterRequest(GetFormModelMasterRequest&& getFormModelMasterRequest) = default;
    ~GetFormModelMasterRequest() GS2_OVERRIDE = default;

    GetFormModelMasterRequest& operator=(const GetFormModelMasterRequest& getFormModelMasterRequest) = default;
    GetFormModelMasterRequest& operator=(GetFormModelMasterRequest&& getFormModelMasterRequest) = default;

    GetFormModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetFormModelMasterRequest);
    }

    const GetFormModelMasterRequest* operator->() const
    {
        return this;
    }

    GetFormModelMasterRequest* operator->()
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
    GetFormModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * フォーム名を取得
     *
     * @return フォーム名
     */
    const optional<StringHolder>& getFormModelName() const
    {
        return ensureData().formModelName;
    }

    /**
     * フォーム名を設定
     *
     * @param formModelName フォーム名
     */
    void setFormModelName(StringHolder formModelName)
    {
        ensureData().formModelName.emplace(std::move(formModelName));
    }

    /**
     * フォーム名を設定
     *
     * @param formModelName フォーム名
     */
    GetFormModelMasterRequest& withFormModelName(StringHolder formModelName)
    {
        ensureData().formModelName.emplace(std::move(formModelName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetFormModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetFormModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FORMATION_CONTROL_GETFORMMODELMASTERREQUEST_HPP_