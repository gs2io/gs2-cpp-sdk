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

#ifndef GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORMODELMASTERREQUEST_HPP_
#define GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DistributorConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * 配信設定マスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateDistributorModelMasterRequest : public Gs2BasicRequest, public Gs2Distributor
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 配信設定名 */
        optional<StringHolder> distributorName;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            distributorName(data.distributorName),
            description(data.description),
            metadata(data.metadata),
            assumeUserId(data.assumeUserId),
            inboxNamespaceId(data.inboxNamespaceId),
            whiteListTargetIds(data.whiteListTargetIds)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            distributorName(std::move(data.distributorName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            assumeUserId(std::move(data.assumeUserId)),
            inboxNamespaceId(std::move(data.inboxNamespaceId)),
            whiteListTargetIds(std::move(data.whiteListTargetIds))
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
    UpdateDistributorModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateDistributorModelMasterRequest(const UpdateDistributorModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Distributor(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateDistributorModelMasterRequest(UpdateDistributorModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Distributor(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateDistributorModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateDistributorModelMasterRequest& operator=(const UpdateDistributorModelMasterRequest& updateDistributorModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateDistributorModelMasterRequest);
        Gs2Distributor::operator=(updateDistributorModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateDistributorModelMasterRequest.m_pData);

        return *this;
    }

    UpdateDistributorModelMasterRequest& operator=(UpdateDistributorModelMasterRequest&& updateDistributorModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateDistributorModelMasterRequest));
        Gs2Distributor::operator=(std::move(updateDistributorModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateDistributorModelMasterRequest.m_pData;
        updateDistributorModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateDistributorModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateDistributorModelMasterRequest* operator->()
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
    UpdateDistributorModelMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * 配信設定名を取得
     *
     * @return 配信設定名
     */
    const optional<StringHolder>& getDistributorName() const
    {
        return ensureData().distributorName;
    }

    /**
     * 配信設定名を設定
     *
     * @param distributorName 配信設定名
     */
    void setDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
    }

    /**
     * 配信設定名を設定
     *
     * @param distributorName 配信設定名
     */
    UpdateDistributorModelMasterRequest& withDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 配信設定マスターの説明を設定
     *
     * @param description 配信設定マスターの説明
     */
    UpdateDistributorModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 配信設定のメタデータを設定
     *
     * @param metadata 配信設定のメタデータ
     */
    UpdateDistributorModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    void setAssumeUserId(const Char* assumeUserId)
    {
        ensureData().assumeUserId.emplace(assumeUserId);
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザ のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザ のGRN
     */
    UpdateDistributorModelMasterRequest& withAssumeUserId(const Char* assumeUserId)
    {
        ensureData().assumeUserId.emplace(assumeUserId);
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
    void setInboxNamespaceId(const Char* inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(inboxNamespaceId);
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    UpdateDistributorModelMasterRequest& withInboxNamespaceId(const Char* inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(inboxNamespaceId);
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
    void setWhiteListTargetIds(const List<StringHolder>& whiteListTargetIds)
    {
        ensureData().whiteListTargetIds.emplace(whiteListTargetIds);
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを設定
     *
     * @param whiteListTargetIds ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    UpdateDistributorModelMasterRequest& withWhiteListTargetIds(const List<StringHolder>& whiteListTargetIds)
    {
        ensureData().whiteListTargetIds.emplace(whiteListTargetIds);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateDistributorModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateDistributorModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateDistributorModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateDistributorModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORMODELMASTERREQUEST_HPP_