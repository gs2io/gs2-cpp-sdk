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

#ifndef GS2_MATCHMAKING_CONTROL_CREATERATINGMODELMASTERREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_CREATERATINGMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/matchmaking/Gs2MatchmakingConst.hpp>
#include <gs2/matchmaking/model/model.hpp>
#include <memory>

namespace gs2 { namespace matchmaking
{

/**
 * レーティングモデルマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateRatingModelMasterRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** レーティングの種類名 */
        optional<StringHolder> name;
        /** レーティングモデルマスターの説明 */
        optional<StringHolder> description;
        /** レーティングの種類のメタデータ */
        optional<StringHolder> metadata;
        /** レート値の変動の大きさ */
        optional<Int32> volatility;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            volatility(data.volatility)
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
    CreateRatingModelMasterRequest() = default;
    CreateRatingModelMasterRequest(const CreateRatingModelMasterRequest& createRatingModelMasterRequest) = default;
    CreateRatingModelMasterRequest(CreateRatingModelMasterRequest&& createRatingModelMasterRequest) = default;
    ~CreateRatingModelMasterRequest() GS2_OVERRIDE = default;

    CreateRatingModelMasterRequest& operator=(const CreateRatingModelMasterRequest& createRatingModelMasterRequest) = default;
    CreateRatingModelMasterRequest& operator=(CreateRatingModelMasterRequest&& createRatingModelMasterRequest) = default;

    CreateRatingModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateRatingModelMasterRequest);
    }

    const CreateRatingModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateRatingModelMasterRequest* operator->()
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
    CreateRatingModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * レーティングの種類名を取得
     *
     * @return レーティングの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * レーティングの種類名を設定
     *
     * @param name レーティングの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * レーティングの種類名を設定
     *
     * @param name レーティングの種類名
     */
    CreateRatingModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * レーティングモデルマスターの説明を取得
     *
     * @return レーティングモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * レーティングモデルマスターの説明を設定
     *
     * @param description レーティングモデルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * レーティングモデルマスターの説明を設定
     *
     * @param description レーティングモデルマスターの説明
     */
    CreateRatingModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * レーティングの種類のメタデータを取得
     *
     * @return レーティングの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * レーティングの種類のメタデータを設定
     *
     * @param metadata レーティングの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * レーティングの種類のメタデータを設定
     *
     * @param metadata レーティングの種類のメタデータ
     */
    CreateRatingModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * レート値の変動の大きさを取得
     *
     * @return レート値の変動の大きさ
     */
    const optional<Int32>& getVolatility() const
    {
        return ensureData().volatility;
    }

    /**
     * レート値の変動の大きさを設定
     *
     * @param volatility レート値の変動の大きさ
     */
    void setVolatility(Int32 volatility)
    {
        ensureData().volatility.emplace(volatility);
    }

    /**
     * レート値の変動の大きさを設定
     *
     * @param volatility レート値の変動の大きさ
     */
    CreateRatingModelMasterRequest& withVolatility(Int32 volatility)
    {
        ensureData().volatility.emplace(volatility);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateRatingModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateRatingModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_CREATERATINGMODELMASTERREQUEST_HPP_