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

#ifndef GS2_MATCHMAKING_CONTROL_UPDATERATINGMODELMASTERREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_UPDATERATINGMODELMASTERREQUEST_HPP_

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
 * レーティングモデルマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateRatingModelMasterRequest : public Gs2BasicRequest, public Gs2Matchmaking
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
        optional<StringHolder> ratingName;
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
            ratingName(data.ratingName),
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
    UpdateRatingModelMasterRequest() = default;
    UpdateRatingModelMasterRequest(const UpdateRatingModelMasterRequest& updateRatingModelMasterRequest) = default;
    UpdateRatingModelMasterRequest(UpdateRatingModelMasterRequest&& updateRatingModelMasterRequest) = default;
    ~UpdateRatingModelMasterRequest() GS2_OVERRIDE = default;

    UpdateRatingModelMasterRequest& operator=(const UpdateRatingModelMasterRequest& updateRatingModelMasterRequest) = default;
    UpdateRatingModelMasterRequest& operator=(UpdateRatingModelMasterRequest&& updateRatingModelMasterRequest) = default;

    UpdateRatingModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateRatingModelMasterRequest);
    }

    const UpdateRatingModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateRatingModelMasterRequest* operator->()
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
    UpdateRatingModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * レーティングの種類名を取得
     *
     * @return レーティングの種類名
     */
    const optional<StringHolder>& getRatingName() const
    {
        return ensureData().ratingName;
    }

    /**
     * レーティングの種類名を設定
     *
     * @param ratingName レーティングの種類名
     */
    void setRatingName(StringHolder ratingName)
    {
        ensureData().ratingName.emplace(std::move(ratingName));
    }

    /**
     * レーティングの種類名を設定
     *
     * @param ratingName レーティングの種類名
     */
    UpdateRatingModelMasterRequest& withRatingName(StringHolder ratingName)
    {
        ensureData().ratingName.emplace(std::move(ratingName));
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
    UpdateRatingModelMasterRequest& withDescription(StringHolder description)
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
    UpdateRatingModelMasterRequest& withMetadata(StringHolder metadata)
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
    UpdateRatingModelMasterRequest& withVolatility(Int32 volatility)
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
    UpdateRatingModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateRatingModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_UPDATERATINGMODELMASTERREQUEST_HPP_