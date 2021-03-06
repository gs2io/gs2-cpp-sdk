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

#ifndef GS2_DEPLOY_CONTROL_GETOUTPUTREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_GETOUTPUTREQUEST_HPP_

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
 * アウトプットを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetOutputRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** スタック名 */
        optional<StringHolder> stackName;
        /** アウトプット名 */
        optional<StringHolder> outputName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            stackName(data.stackName),
            outputName(data.outputName)
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
    GetOutputRequest() = default;
    GetOutputRequest(const GetOutputRequest& getOutputRequest) = default;
    GetOutputRequest(GetOutputRequest&& getOutputRequest) = default;
    ~GetOutputRequest() GS2_OVERRIDE = default;

    GetOutputRequest& operator=(const GetOutputRequest& getOutputRequest) = default;
    GetOutputRequest& operator=(GetOutputRequest&& getOutputRequest) = default;

    GetOutputRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetOutputRequest);
    }

    const GetOutputRequest* operator->() const
    {
        return this;
    }

    GetOutputRequest* operator->()
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
    GetOutputRequest& withStackName(StringHolder stackName)
    {
        ensureData().stackName.emplace(std::move(stackName));
        return *this;
    }

    /**
     * アウトプット名を取得
     *
     * @return アウトプット名
     */
    const optional<StringHolder>& getOutputName() const
    {
        return ensureData().outputName;
    }

    /**
     * アウトプット名を設定
     *
     * @param outputName アウトプット名
     */
    void setOutputName(StringHolder outputName)
    {
        ensureData().outputName.emplace(std::move(outputName));
    }

    /**
     * アウトプット名を設定
     *
     * @param outputName アウトプット名
     */
    GetOutputRequest& withOutputName(StringHolder outputName)
    {
        ensureData().outputName.emplace(std::move(outputName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetOutputRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetOutputRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_GETOUTPUTREQUEST_HPP_