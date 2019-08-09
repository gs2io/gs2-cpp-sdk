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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MissionConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            counterName(data.counterName),
            metadata(data.metadata),
            description(data.description),
            scopes(data.scopes),
            challengePeriodEventId(data.challengePeriodEventId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            counterName(std::move(data.counterName)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            scopes(std::move(data.scopes)),
            challengePeriodEventId(std::move(data.challengePeriodEventId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    UpdateCounterModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateCounterModelMasterRequest(const UpdateCounterModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Mission(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateCounterModelMasterRequest(UpdateCounterModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Mission(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateCounterModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCounterModelMasterRequest& operator=(const UpdateCounterModelMasterRequest& updateCounterModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateCounterModelMasterRequest);
        Gs2Mission::operator=(updateCounterModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCounterModelMasterRequest.m_pData);

        return *this;
    }

    UpdateCounterModelMasterRequest& operator=(UpdateCounterModelMasterRequest&& updateCounterModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateCounterModelMasterRequest));
        Gs2Mission::operator=(std::move(updateCounterModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCounterModelMasterRequest.m_pData;
        updateCounterModelMasterRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateCounterModelMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    UpdateCounterModelMasterRequest& withCounterName(const Char* counterName)
    {
        ensureData().counterName.emplace(counterName);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    UpdateCounterModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * カウンターの種類マスターの説明を設定
     *
     * @param description カウンターの種類マスターの説明
     */
    UpdateCounterModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setScopes(const List<CounterScopeModel>& scopes)
    {
        ensureData().scopes.emplace(scopes);
    }

    /**
     * カウンターのリセットタイミングを設定
     *
     * @param scopes カウンターのリセットタイミング
     */
    UpdateCounterModelMasterRequest& withScopes(const List<CounterScopeModel>& scopes)
    {
        ensureData().scopes.emplace(scopes);
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
    void setChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(challengePeriodEventId);
    }

    /**
     * カウントアップ可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId カウントアップ可能な期間を指定するイベントマスター のGRN
     */
    UpdateCounterModelMasterRequest& withChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(challengePeriodEventId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateCounterModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateCounterModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateCounterModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCounterModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_MISSION_CONTROL_UPDATECOUNTERMODELMASTERREQUEST_HPP_