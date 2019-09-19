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

#ifndef GS2_MISSION_CONTROL_CREATEMISSIONGROUPMODELMASTERREQUEST_HPP_
#define GS2_MISSION_CONTROL_CREATEMISSIONGROUPMODELMASTERREQUEST_HPP_

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
 * ミッショングループマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateMissionGroupModelMasterRequest : public Gs2BasicRequest, public Gs2Mission
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ミッショングループ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** ミッショングループの説明 */
        optional<StringHolder> description;
        /** ミッションを達成したときの通知先ネームスペース のGRN */
        optional<StringHolder> completeNotificationNamespaceId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            completeNotificationNamespaceId(data.completeNotificationNamespaceId)
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
    CreateMissionGroupModelMasterRequest() = default;
    CreateMissionGroupModelMasterRequest(const CreateMissionGroupModelMasterRequest& createMissionGroupModelMasterRequest) = default;
    CreateMissionGroupModelMasterRequest(CreateMissionGroupModelMasterRequest&& createMissionGroupModelMasterRequest) = default;
    ~CreateMissionGroupModelMasterRequest() GS2_OVERRIDE = default;

    CreateMissionGroupModelMasterRequest& operator=(const CreateMissionGroupModelMasterRequest& createMissionGroupModelMasterRequest) = default;
    CreateMissionGroupModelMasterRequest& operator=(CreateMissionGroupModelMasterRequest&& createMissionGroupModelMasterRequest) = default;

    CreateMissionGroupModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateMissionGroupModelMasterRequest);
    }

    const CreateMissionGroupModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateMissionGroupModelMasterRequest* operator->()
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
    CreateMissionGroupModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ミッショングループ名を取得
     *
     * @return ミッショングループ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ミッショングループ名を設定
     *
     * @param name ミッショングループ名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ミッショングループ名を設定
     *
     * @param name ミッショングループ名
     */
    CreateMissionGroupModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateMissionGroupModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * ミッショングループの説明を取得
     *
     * @return ミッショングループの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ミッショングループの説明を設定
     *
     * @param description ミッショングループの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ミッショングループの説明を設定
     *
     * @param description ミッショングループの説明
     */
    CreateMissionGroupModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * ミッションを達成したときの通知先ネームスペース のGRNを取得
     *
     * @return ミッションを達成したときの通知先ネームスペース のGRN
     */
    const optional<StringHolder>& getCompleteNotificationNamespaceId() const
    {
        return ensureData().completeNotificationNamespaceId;
    }

    /**
     * ミッションを達成したときの通知先ネームスペース のGRNを設定
     *
     * @param completeNotificationNamespaceId ミッションを達成したときの通知先ネームスペース のGRN
     */
    void setCompleteNotificationNamespaceId(StringHolder completeNotificationNamespaceId)
    {
        ensureData().completeNotificationNamespaceId.emplace(std::move(completeNotificationNamespaceId));
    }

    /**
     * ミッションを達成したときの通知先ネームスペース のGRNを設定
     *
     * @param completeNotificationNamespaceId ミッションを達成したときの通知先ネームスペース のGRN
     */
    CreateMissionGroupModelMasterRequest& withCompleteNotificationNamespaceId(StringHolder completeNotificationNamespaceId)
    {
        ensureData().completeNotificationNamespaceId.emplace(std::move(completeNotificationNamespaceId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateMissionGroupModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateMissionGroupModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MISSION_CONTROL_CREATEMISSIONGROUPMODELMASTERREQUEST_HPP_