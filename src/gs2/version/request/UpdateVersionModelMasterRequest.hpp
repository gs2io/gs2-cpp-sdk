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

#ifndef GS2_VERSION_CONTROL_UPDATEVERSIONMODELMASTERREQUEST_HPP_
#define GS2_VERSION_CONTROL_UPDATEVERSIONMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/version/Gs2VersionConst.hpp>
#include <gs2/version/model/model.hpp>
#include <memory>

namespace gs2 { namespace version
{

/**
 * バージョンマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateVersionModelMasterRequest : public Gs2BasicRequest, public Gs2Version
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** バージョン名 */
        optional<StringHolder> versionName;
        /** バージョンマスターの説明 */
        optional<StringHolder> description;
        /** バージョンのメタデータ */
        optional<StringHolder> metadata;
        /** バージョンアップを促すバージョン */
        optional<Version> warningVersion;
        /** バージョンチェックを蹴るバージョン */
        optional<Version> errorVersion;
        /** 判定に使用するバージョン値の種類 */
        optional<StringHolder> scope;
        /** 現在のバージョン */
        optional<Version> currentVersion;
        /** 判定するバージョン値に署名検証を必要とするか */
        optional<Bool> needSignature;
        /** 署名検証に使用する暗号鍵 のGRN */
        optional<StringHolder> signatureKeyId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            versionName(data.versionName),
            description(data.description),
            metadata(data.metadata),
            scope(data.scope),
            needSignature(data.needSignature),
            signatureKeyId(data.signatureKeyId)
        {
            if (data.warningVersion)
            {
                warningVersion = data.warningVersion->deepCopy();
            }
            if (data.errorVersion)
            {
                errorVersion = data.errorVersion->deepCopy();
            }
            if (data.currentVersion)
            {
                currentVersion = data.currentVersion->deepCopy();
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
    UpdateVersionModelMasterRequest() = default;
    UpdateVersionModelMasterRequest(const UpdateVersionModelMasterRequest& updateVersionModelMasterRequest) = default;
    UpdateVersionModelMasterRequest(UpdateVersionModelMasterRequest&& updateVersionModelMasterRequest) = default;
    ~UpdateVersionModelMasterRequest() GS2_OVERRIDE = default;

    UpdateVersionModelMasterRequest& operator=(const UpdateVersionModelMasterRequest& updateVersionModelMasterRequest) = default;
    UpdateVersionModelMasterRequest& operator=(UpdateVersionModelMasterRequest&& updateVersionModelMasterRequest) = default;

    UpdateVersionModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateVersionModelMasterRequest);
    }

    const UpdateVersionModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateVersionModelMasterRequest* operator->()
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
    UpdateVersionModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * バージョン名を取得
     *
     * @return バージョン名
     */
    const optional<StringHolder>& getVersionName() const
    {
        return ensureData().versionName;
    }

    /**
     * バージョン名を設定
     *
     * @param versionName バージョン名
     */
    void setVersionName(StringHolder versionName)
    {
        ensureData().versionName.emplace(std::move(versionName));
    }

    /**
     * バージョン名を設定
     *
     * @param versionName バージョン名
     */
    UpdateVersionModelMasterRequest& withVersionName(StringHolder versionName)
    {
        ensureData().versionName.emplace(std::move(versionName));
        return *this;
    }

    /**
     * バージョンマスターの説明を取得
     *
     * @return バージョンマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * バージョンマスターの説明を設定
     *
     * @param description バージョンマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * バージョンマスターの説明を設定
     *
     * @param description バージョンマスターの説明
     */
    UpdateVersionModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * バージョンのメタデータを取得
     *
     * @return バージョンのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * バージョンのメタデータを設定
     *
     * @param metadata バージョンのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * バージョンのメタデータを設定
     *
     * @param metadata バージョンのメタデータ
     */
    UpdateVersionModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * バージョンアップを促すバージョンを取得
     *
     * @return バージョンアップを促すバージョン
     */
    const optional<Version>& getWarningVersion() const
    {
        return ensureData().warningVersion;
    }

    /**
     * バージョンアップを促すバージョンを設定
     *
     * @param warningVersion バージョンアップを促すバージョン
     */
    void setWarningVersion(Version warningVersion)
    {
        ensureData().warningVersion.emplace(std::move(warningVersion));
    }

    /**
     * バージョンアップを促すバージョンを設定
     *
     * @param warningVersion バージョンアップを促すバージョン
     */
    UpdateVersionModelMasterRequest& withWarningVersion(Version warningVersion)
    {
        ensureData().warningVersion.emplace(std::move(warningVersion));
        return *this;
    }

    /**
     * バージョンチェックを蹴るバージョンを取得
     *
     * @return バージョンチェックを蹴るバージョン
     */
    const optional<Version>& getErrorVersion() const
    {
        return ensureData().errorVersion;
    }

    /**
     * バージョンチェックを蹴るバージョンを設定
     *
     * @param errorVersion バージョンチェックを蹴るバージョン
     */
    void setErrorVersion(Version errorVersion)
    {
        ensureData().errorVersion.emplace(std::move(errorVersion));
    }

    /**
     * バージョンチェックを蹴るバージョンを設定
     *
     * @param errorVersion バージョンチェックを蹴るバージョン
     */
    UpdateVersionModelMasterRequest& withErrorVersion(Version errorVersion)
    {
        ensureData().errorVersion.emplace(std::move(errorVersion));
        return *this;
    }

    /**
     * 判定に使用するバージョン値の種類を取得
     *
     * @return 判定に使用するバージョン値の種類
     */
    const optional<StringHolder>& getScope() const
    {
        return ensureData().scope;
    }

    /**
     * 判定に使用するバージョン値の種類を設定
     *
     * @param scope 判定に使用するバージョン値の種類
     */
    void setScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
    }

    /**
     * 判定に使用するバージョン値の種類を設定
     *
     * @param scope 判定に使用するバージョン値の種類
     */
    UpdateVersionModelMasterRequest& withScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
        return *this;
    }

    /**
     * 現在のバージョンを取得
     *
     * @return 現在のバージョン
     */
    const optional<Version>& getCurrentVersion() const
    {
        return ensureData().currentVersion;
    }

    /**
     * 現在のバージョンを設定
     *
     * @param currentVersion 現在のバージョン
     */
    void setCurrentVersion(Version currentVersion)
    {
        ensureData().currentVersion.emplace(std::move(currentVersion));
    }

    /**
     * 現在のバージョンを設定
     *
     * @param currentVersion 現在のバージョン
     */
    UpdateVersionModelMasterRequest& withCurrentVersion(Version currentVersion)
    {
        ensureData().currentVersion.emplace(std::move(currentVersion));
        return *this;
    }

    /**
     * 判定するバージョン値に署名検証を必要とするかを取得
     *
     * @return 判定するバージョン値に署名検証を必要とするか
     */
    const optional<Bool>& getNeedSignature() const
    {
        return ensureData().needSignature;
    }

    /**
     * 判定するバージョン値に署名検証を必要とするかを設定
     *
     * @param needSignature 判定するバージョン値に署名検証を必要とするか
     */
    void setNeedSignature(Bool needSignature)
    {
        ensureData().needSignature.emplace(needSignature);
    }

    /**
     * 判定するバージョン値に署名検証を必要とするかを設定
     *
     * @param needSignature 判定するバージョン値に署名検証を必要とするか
     */
    UpdateVersionModelMasterRequest& withNeedSignature(Bool needSignature)
    {
        ensureData().needSignature.emplace(needSignature);
        return *this;
    }

    /**
     * 署名検証に使用する暗号鍵 のGRNを取得
     *
     * @return 署名検証に使用する暗号鍵 のGRN
     */
    const optional<StringHolder>& getSignatureKeyId() const
    {
        return ensureData().signatureKeyId;
    }

    /**
     * 署名検証に使用する暗号鍵 のGRNを設定
     *
     * @param signatureKeyId 署名検証に使用する暗号鍵 のGRN
     */
    void setSignatureKeyId(StringHolder signatureKeyId)
    {
        ensureData().signatureKeyId.emplace(std::move(signatureKeyId));
    }

    /**
     * 署名検証に使用する暗号鍵 のGRNを設定
     *
     * @param signatureKeyId 署名検証に使用する暗号鍵 のGRN
     */
    UpdateVersionModelMasterRequest& withSignatureKeyId(StringHolder signatureKeyId)
    {
        ensureData().signatureKeyId.emplace(std::move(signatureKeyId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateVersionModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateVersionModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_VERSION_CONTROL_UPDATEVERSIONMODELMASTERREQUEST_HPP_