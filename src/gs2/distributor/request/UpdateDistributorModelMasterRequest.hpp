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
 * ディストリビュータの種類を更新 のリクエストモデル
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
        /** ディストリビュータ名 */
        optional<StringHolder> distributorName;
        /** ディストリビューターの種類名 */
        optional<StringHolder> distributorModelName;
        /** ディストリビュータの種類の説明 */
        optional<StringHolder> description;
        /** ディストリビューターの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所持品の配布処理の権限判定に使用する ユーザー のGRN */
        optional<StringHolder> assumeUserId;
        /** 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN */
        optional<StringHolder> inboxId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        optional<List<StringHolder>> whiteListTargetIds;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            distributorName(data.distributorName),
            distributorModelName(data.distributorModelName),
            description(data.description),
            metadata(data.metadata),
            assumeUserId(data.assumeUserId),
            inboxId(data.inboxId),
            whiteListTargetIds(data.whiteListTargetIds)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            distributorName(std::move(data.distributorName)),
            distributorModelName(std::move(data.distributorModelName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            assumeUserId(std::move(data.assumeUserId)),
            inboxId(std::move(data.inboxId)),
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
     * ディストリビュータ名を取得
     *
     * @return ディストリビュータ名
     */
    const optional<StringHolder>& getDistributorName() const
    {
        return ensureData().distributorName;
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    void setDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
    }

    /**
     * ディストリビュータ名を設定
     *
     * @param distributorName ディストリビュータ名
     */
    UpdateDistributorModelMasterRequest& withDistributorName(const Char* distributorName)
    {
        ensureData().distributorName.emplace(distributorName);
        return *this;
    }

    /**
     * ディストリビューターの種類名を取得
     *
     * @return ディストリビューターの種類名
     */
    const optional<StringHolder>& getDistributorModelName() const
    {
        return ensureData().distributorModelName;
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param distributorModelName ディストリビューターの種類名
     */
    void setDistributorModelName(const Char* distributorModelName)
    {
        ensureData().distributorModelName.emplace(distributorModelName);
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param distributorModelName ディストリビューターの種類名
     */
    UpdateDistributorModelMasterRequest& withDistributorModelName(const Char* distributorModelName)
    {
        ensureData().distributorModelName.emplace(distributorModelName);
        return *this;
    }

    /**
     * ディストリビュータの種類の説明を取得
     *
     * @return ディストリビュータの種類の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ディストリビュータの種類の説明を設定
     *
     * @param description ディストリビュータの種類の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ディストリビュータの種類の説明を設定
     *
     * @param description ディストリビュータの種類の説明
     */
    UpdateDistributorModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * ディストリビューターの種類のメタデータを取得
     *
     * @return ディストリビューターの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * ディストリビューターの種類のメタデータを設定
     *
     * @param metadata ディストリビューターの種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * ディストリビューターの種類のメタデータを設定
     *
     * @param metadata ディストリビューターの種類のメタデータ
     */
    UpdateDistributorModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザー のGRNを取得
     *
     * @return 所持品の配布処理の権限判定に使用する ユーザー のGRN
     */
    const optional<StringHolder>& getAssumeUserId() const
    {
        return ensureData().assumeUserId;
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザー のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザー のGRN
     */
    void setAssumeUserId(const Char* assumeUserId)
    {
        ensureData().assumeUserId.emplace(assumeUserId);
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザー のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザー のGRN
     */
    UpdateDistributorModelMasterRequest& withAssumeUserId(const Char* assumeUserId)
    {
        ensureData().assumeUserId.emplace(assumeUserId);
        return *this;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRNを取得
     *
     * @return 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN
     */
    const optional<StringHolder>& getInboxId() const
    {
        return ensureData().inboxId;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRNを設定
     *
     * @param inboxId 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN
     */
    void setInboxId(const Char* inboxId)
    {
        ensureData().inboxId.emplace(inboxId);
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRNを設定
     *
     * @param inboxId 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN
     */
    UpdateDistributorModelMasterRequest& withInboxId(const Char* inboxId)
    {
        ensureData().inboxId.emplace(inboxId);
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

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_UPDATEDISTRIBUTORMODELMASTERREQUEST_HPP_