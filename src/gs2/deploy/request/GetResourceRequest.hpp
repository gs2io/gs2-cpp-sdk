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

#ifndef GS2_DEPLOY_CONTROL_GETRESOURCEREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_GETRESOURCEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/deploy/Gs2DeployConst.hpp>
#include <gs2/deploy/model/model.hpp>
#include <memory>

namespace gs2 { namespace deploy
{

/**
 * 作成されたのリソースを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetResourceRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** スタック名 */
        optional<StringHolder> stackName;
        /** 作成中のリソース名 */
        optional<StringHolder> resourceName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            stackName(data.stackName),
            resourceName(data.resourceName)
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
    GetResourceRequest() = default;
    GetResourceRequest(const GetResourceRequest& getResourceRequest) = default;
    GetResourceRequest(GetResourceRequest&& getResourceRequest) = default;
    ~GetResourceRequest() GS2_OVERRIDE = default;

    GetResourceRequest& operator=(const GetResourceRequest& getResourceRequest) = default;
    GetResourceRequest& operator=(GetResourceRequest&& getResourceRequest) = default;

    GetResourceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetResourceRequest);
    }

    const GetResourceRequest* operator->() const
    {
        return this;
    }

    GetResourceRequest* operator->()
    {
        return this;
    }

    /**
     * スタック名を取得
     *
     * @return スタック名
     */
    const optional<StringHolder>& getStackName() const
    {
        return ensureData().stackName;
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    void setStackName(StringHolder stackName)
    {
        ensureData().stackName.emplace(std::move(stackName));
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    GetResourceRequest& withStackName(StringHolder stackName)
    {
        ensureData().stackName.emplace(std::move(stackName));
        return *this;
    }

    /**
     * 作成中のリソース名を取得
     *
     * @return 作成中のリソース名
     */
    const optional<StringHolder>& getResourceName() const
    {
        return ensureData().resourceName;
    }

    /**
     * 作成中のリソース名を設定
     *
     * @param resourceName 作成中のリソース名
     */
    void setResourceName(StringHolder resourceName)
    {
        ensureData().resourceName.emplace(std::move(resourceName));
    }

    /**
     * 作成中のリソース名を設定
     *
     * @param resourceName 作成中のリソース名
     */
    GetResourceRequest& withResourceName(StringHolder resourceName)
    {
        ensureData().resourceName.emplace(std::move(resourceName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetResourceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetResourceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_GETRESOURCEREQUEST_HPP_