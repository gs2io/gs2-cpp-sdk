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

#ifndef GS2_EXPERIENCE_CONTROL_DELETETHRESHOLDMASTERREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_DELETETHRESHOLDMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace experience
{

/**
 * ランクアップ閾値マスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteThresholdMasterRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ランクアップ閾値名 */
        optional<StringHolder> thresholdName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            thresholdName(data.thresholdName)
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
    DeleteThresholdMasterRequest() = default;
    DeleteThresholdMasterRequest(const DeleteThresholdMasterRequest& deleteThresholdMasterRequest) = default;
    DeleteThresholdMasterRequest(DeleteThresholdMasterRequest&& deleteThresholdMasterRequest) = default;
    ~DeleteThresholdMasterRequest() GS2_OVERRIDE = default;

    DeleteThresholdMasterRequest& operator=(const DeleteThresholdMasterRequest& deleteThresholdMasterRequest) = default;
    DeleteThresholdMasterRequest& operator=(DeleteThresholdMasterRequest&& deleteThresholdMasterRequest) = default;

    DeleteThresholdMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteThresholdMasterRequest);
    }

    const DeleteThresholdMasterRequest* operator->() const
    {
        return this;
    }

    DeleteThresholdMasterRequest* operator->()
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
    DeleteThresholdMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ランクアップ閾値名を取得
     *
     * @return ランクアップ閾値名
     */
    const optional<StringHolder>& getThresholdName() const
    {
        return ensureData().thresholdName;
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param thresholdName ランクアップ閾値名
     */
    void setThresholdName(StringHolder thresholdName)
    {
        ensureData().thresholdName.emplace(std::move(thresholdName));
    }

    /**
     * ランクアップ閾値名を設定
     *
     * @param thresholdName ランクアップ閾値名
     */
    DeleteThresholdMasterRequest& withThresholdName(StringHolder thresholdName)
    {
        ensureData().thresholdName.emplace(std::move(thresholdName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteThresholdMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteThresholdMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_DELETETHRESHOLDMASTERREQUEST_HPP_