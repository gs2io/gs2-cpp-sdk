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

#ifndef GS2_MATCHMAKING_CONTROL_DELETEGATHERINGREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_DELETEGATHERINGREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace matchmaking
{

/**
 * ギャザリングを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteGatheringRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ギャザリング名 */
        optional<StringHolder> gatheringName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            gatheringName(data.gatheringName)
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
    DeleteGatheringRequest() = default;
    DeleteGatheringRequest(const DeleteGatheringRequest& deleteGatheringRequest) = default;
    DeleteGatheringRequest(DeleteGatheringRequest&& deleteGatheringRequest) = default;
    ~DeleteGatheringRequest() GS2_OVERRIDE = default;

    DeleteGatheringRequest& operator=(const DeleteGatheringRequest& deleteGatheringRequest) = default;
    DeleteGatheringRequest& operator=(DeleteGatheringRequest&& deleteGatheringRequest) = default;

    DeleteGatheringRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteGatheringRequest);
    }

    const DeleteGatheringRequest* operator->() const
    {
        return this;
    }

    DeleteGatheringRequest* operator->()
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
    DeleteGatheringRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ギャザリング名を取得
     *
     * @return ギャザリング名
     */
    const optional<StringHolder>& getGatheringName() const
    {
        return ensureData().gatheringName;
    }

    /**
     * ギャザリング名を設定
     *
     * @param gatheringName ギャザリング名
     */
    void setGatheringName(StringHolder gatheringName)
    {
        ensureData().gatheringName.emplace(std::move(gatheringName));
    }

    /**
     * ギャザリング名を設定
     *
     * @param gatheringName ギャザリング名
     */
    DeleteGatheringRequest& withGatheringName(StringHolder gatheringName)
    {
        ensureData().gatheringName.emplace(std::move(gatheringName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteGatheringRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteGatheringRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_DELETEGATHERINGREQUEST_HPP_