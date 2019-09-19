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

#ifndef GS2_MISSION_CONTROL_UPDATECOUNTERMODELMASTERREQUEST_HPP_
#define GS2_MISSION_CONTROL_UPDATECOUNTERMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MissionConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace mission
{

/**
 * カウンターの種類マスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCounterModelMasterRequest : public Gs2BasicRequest, public Gs2Mission
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** カウンター名 */
        optional<StringHolder> counterName;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** カウンターの種類マスターの説明 */
        optional<StringHolder> description;
        /** カウンターのリセットタイミング */
        optional<List<CounterScopeModel>> scopes;
        /** カウントアップ可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            counterName(data.counterName),
            metadata(data.metadata),
            description(data.description),
            challengePeriodEventId(data.challengePeriodEventId)
        {
            if (data.scopes)
            {
                scopes = data.scopes->deepCopy();
            }
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
    UpdateCounterModelMasterRequest() = default;
    UpdateCounterModelMasterRequest(const UpdateCounterModelMasterRequest& updateCounterModelMasterRequest) = default;
    UpdateCounterModelMasterRequest(UpdateCounterModelMasterRequest&& updateCounterModelMasterRequest) = default;
    ~UpdateCounterModelMasterRequest() GS2_OVERRIDE = default;

    UpdateCounterModelMasterRequest& operator=(const UpdateCounterModelMasterRequest& updateCounterModelMasterRequest) = default;
    UpdateCounterModelMasterRequest& operator=(UpdateCounterModelMasterRequest&& updateCounterModelMasterRequest) = default;

    UpdateCounterModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateCounterModelMasterRequest);
    }

    const UpdateCounterModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateCounterModelMasterRequest* operator->()
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
    UpdateCounterModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * カウンター名を取得
     *
     * @return カウンター名
     */
    const optional<StringHolder>& getCounterName() const
    {
        return ensureData().counterName;
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    void setCounterName(StringHolder counterName)
    {
        ensureData().counterName.emplace(std::move(counterName));
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    UpdateCounterModelMasterRequest& withCounterName(StringHolder counterName)
    {
        ensureData().counterName.emplace(std::move(counterName));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    UpdateCounterModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * カウンターの種類マスターの説明を取得
     *
     * @return カウンターの種類マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * カウンターの種類マスターの説明を設定
     *
     * @param description カウンターの種類マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * カウンターの種類マスターの説明を設定
     *
     * @param description カウンターの種類マスターの説明
     */
    UpdateCounterModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * カウンターのリセットタイミングを取得
     *
     * @return カウンターのリセットタイミング
     */
    const optional<List<CounterScopeModel>>& getScopes() const
    {
        return ensureData().scopes;
    }

    /**
     * カウンターのリセットタイミングを設定
     *
     * @param scopes カウンターのリセットタイミング
     */
    void setScopes(List<CounterScopeModel> scopes)
    {
        ensureData().scopes.emplace(std::move(scopes));
    }

    /**
     * カウンターのリセットタイミングを設定
     *
     * @param scopes カウンターのリセットタイミング
     */
    UpdateCounterModelMasterRequest& withScopes(List<CounterScopeModel> scopes)
    {
        ensureData().scopes.emplace(std::move(scopes));
        return *this;
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを取得
     *
     * @return カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    const optional<StringHolder>& getChallengePeriodEventId() const
    {
        return ensureData().challengePeriodEventId;
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    UpdateCounterModelMasterRequest& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateCounterModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCounterModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MISSION_CONTROL_UPDATECOUNTERMODELMASTERREQUEST_HPP_