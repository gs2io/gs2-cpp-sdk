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

#ifndef GS2_DISTRIBUTOR_CONTROL_CREATEDISTRIBUTORMODELMASTERREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_CREATEDISTRIBUTORMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace distributor
{

/**
 * 配信設定マスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateDistributorModelMasterRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 配信設定名 */
        optional<StringHolder> name;
        /** 配信設定マスターの説明 */
        optional<StringHolder> description;
        /** 配信設定のメタデータ */
        optional<StringHolder> metadata;
        /** 所持品の配布処理の権限判定に使用する ユーザ のGRN */
        optional<StringHolder> assumeUserId;
        /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
        optional<StringHolder> inboxNamespaceId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        optional<List<StringHolder>> whiteListTargetIds;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            assumeUserId(data.assumeUserId),
            inboxNamespaceId(data.inboxNamespaceId)
        {
            if (data.whiteListTargetIds)
            {
                whiteListTargetIds = data.whiteListTargetIds->deepCopy();
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
    CreateDistributorModelMasterRequest() = default;
    CreateDistributorModelMasterRequest(const CreateDistributorModelMasterRequest& createDistributorModelMasterRequest) = default;
    CreateDistributorModelMasterRequest(CreateDistributorModelMasterRequest&& createDistributorModelMasterRequest) = default;
    ~CreateDistributorModelMasterRequest() GS2_OVERRIDE = default;

    CreateDistributorModelMasterRequest& operator=(const CreateDistributorModelMasterRequest& createDistributorModelMasterRequest) = default;
    CreateDistributorModelMasterRequest& operator=(CreateDistributorModelMasterRequest&& createDistributorModelMasterRequest) = default;

    CreateDistributorModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateDistributorModelMasterRequest);
    }

    const CreateDistributorModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateDistributorModelMasterRequest* operator->()
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
    CreateDistributorModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 配信設定名を取得
     *
     * @return 配信設定名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 配信設定名を設定
     *
     * @param name 配信設定名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 配信設定名を設定
     *
     * @param name 配信設定名
     */
    CreateDistributorModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * 配信設定マスターの説明を取得
     *
     * @return 配信設定マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 配信設定マスターの説明を設定
     *
     * @param description 配信設定マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 配信設定マスターの説明を設定
     *
     * @param description 配信設定マスターの説明
     */
    CreateDistributorModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 配信設定のメタデータを取得
     *
     * @return 配信設定のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 配信設定のメタデータを設定
     *
     * @param metadata 配信設定のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 配信設定のメタデータを設定
     *
     * @param metadata 配信設定のメタデータ
     */
    CreateDistributorModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザ のGRNを取得
     *
     * @return 所持品の配布処理の権限判定に使用する ユーザ のGRN
     */
    const optional<StringHolder>& getAssumeUserId() const
    {
        return ensureData().assumeUserId;
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザ のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザ のGRN
     */
    void setAssumeUserId(StringHolder assumeUserId)
    {
        ensureData().assumeUserId.emplace(std::move(assumeUserId));
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザ のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザ のGRN
     */
    CreateDistributorModelMasterRequest& withAssumeUserId(StringHolder assumeUserId)
    {
        ensureData().assumeUserId.emplace(std::move(assumeUserId));
        return *this;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを取得
     *
     * @return 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    const optional<StringHolder>& getInboxNamespaceId() const
    {
        return ensureData().inboxNamespaceId;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    void setInboxNamespaceId(StringHolder inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(std::move(inboxNamespaceId));
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    CreateDistributorModelMasterRequest& withInboxNamespaceId(StringHolder inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(std::move(inboxNamespaceId));
        return *this;
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを取得
     *
     * @return ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    const optional<List<StringHolder>>& getWhiteListTargetIds() const
    {
        return ensureData().whiteListTargetIds;
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを設定
     *
     * @param whiteListTargetIds ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    void setWhiteListTargetIds(List<StringHolder> whiteListTargetIds)
    {
        ensureData().whiteListTargetIds.emplace(std::move(whiteListTargetIds));
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを設定
     *
     * @param whiteListTargetIds ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    CreateDistributorModelMasterRequest& withWhiteListTargetIds(List<StringHolder> whiteListTargetIds)
    {
        ensureData().whiteListTargetIds.emplace(std::move(whiteListTargetIds));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateDistributorModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateDistributorModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_CREATEDISTRIBUTORMODELMASTERREQUEST_HPP_