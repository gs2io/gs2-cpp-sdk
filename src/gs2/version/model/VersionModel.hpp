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

#ifndef GS2_VERSION_MODEL_VERSIONMODEL_HPP_
#define GS2_VERSION_MODEL_VERSIONMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Version.hpp"
#include "Version.hpp"
#include "Version.hpp"
#include <memory>

namespace gs2 { namespace version {

/**
 * バージョン設定
 *
 * @author Game Server Services, Inc.
 *
 */
class VersionModel : public Gs2Object
{
    friend bool operator!=(const VersionModel& lhs, const VersionModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** バージョン設定 */
        optional<StringHolder> versionModelId;
        /** バージョンの種類名 */
        optional<StringHolder> name;
        /** バージョンの種類のメタデータ */
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
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    VersionModel() = default;
    VersionModel(const VersionModel& versionModel) = default;
    VersionModel(VersionModel&& versionModel) = default;
    ~VersionModel() = default;

    VersionModel& operator=(const VersionModel& versionModel) = default;
    VersionModel& operator=(VersionModel&& versionModel) = default;

    VersionModel deepCopy() const;

    const VersionModel* operator->() const
    {
        return this;
    }

    VersionModel* operator->()
    {
        return this;
    }
    /**
     * バージョン設定を取得
     *
     * @return バージョン設定
     */
    const optional<StringHolder>& getVersionModelId() const
    {
        return ensureData().versionModelId;
    }

    /**
     * バージョン設定を設定
     *
     * @param versionModelId バージョン設定
     */
    void setVersionModelId(StringHolder versionModelId)
    {
        ensureData().versionModelId.emplace(std::move(versionModelId));
    }

    /**
     * バージョン設定を設定
     *
     * @param versionModelId バージョン設定
     */
    VersionModel& withVersionModelId(StringHolder versionModelId)
    {
        setVersionModelId(std::move(versionModelId));
        return *this;
    }

    /**
     * バージョンの種類名を取得
     *
     * @return バージョンの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * バージョンの種類名を設定
     *
     * @param name バージョンの種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * バージョンの種類名を設定
     *
     * @param name バージョンの種類名
     */
    VersionModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * バージョンの種類のメタデータを取得
     *
     * @return バージョンの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * バージョンの種類のメタデータを設定
     *
     * @param metadata バージョンの種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * バージョンの種類のメタデータを設定
     *
     * @param metadata バージョンの種類のメタデータ
     */
    VersionModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    VersionModel& withWarningVersion(Version warningVersion)
    {
        setWarningVersion(std::move(warningVersion));
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
    VersionModel& withErrorVersion(Version errorVersion)
    {
        setErrorVersion(std::move(errorVersion));
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
    VersionModel& withScope(StringHolder scope)
    {
        setScope(std::move(scope));
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
    VersionModel& withCurrentVersion(Version currentVersion)
    {
        setCurrentVersion(std::move(currentVersion));
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
    VersionModel& withNeedSignature(Bool needSignature)
    {
        setNeedSignature(needSignature);
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
    VersionModel& withSignatureKeyId(StringHolder signatureKeyId)
    {
        setSignatureKeyId(std::move(signatureKeyId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const VersionModel& lhs, const VersionModel& lhr);

inline bool operator==(const VersionModel& lhs, const VersionModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_VERSION_MODEL_VERSIONMODEL_HPP_