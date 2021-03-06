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

#ifndef GS2_VERSION_MODEL_VERSIONMODELMASTER_HPP_
#define GS2_VERSION_MODEL_VERSIONMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Version.hpp"
#include "Version.hpp"
#include "Version.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace version {

/**
 * バージョンマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class VersionModelMaster : public Gs2Object
{
    friend bool operator!=(const VersionModelMaster& lhs, const VersionModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** バージョンマスター */
        optional<StringHolder> versionModelId;
        /** バージョン名 */
        optional<StringHolder> name;
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            versionModelId(data.versionModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            scope(data.scope),
            needSignature(data.needSignature),
            signatureKeyId(data.signatureKeyId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
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

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "versionModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->versionModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "warningVersion") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->warningVersion.emplace();
                    detail::json::JsonParser::parse(&this->warningVersion->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "errorVersion") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->errorVersion.emplace();
                    detail::json::JsonParser::parse(&this->errorVersion->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "scope") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->scope.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "currentVersion") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->currentVersion.emplace();
                    detail::json::JsonParser::parse(&this->currentVersion->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "needSignature") == 0)
            {
                if (jsonValue.IsBool())
                {
                    this->needSignature = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "signatureKeyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signatureKeyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    VersionModelMaster() = default;
    VersionModelMaster(const VersionModelMaster& versionModelMaster) = default;
    VersionModelMaster(VersionModelMaster&& versionModelMaster) = default;
    ~VersionModelMaster() = default;

    VersionModelMaster& operator=(const VersionModelMaster& versionModelMaster) = default;
    VersionModelMaster& operator=(VersionModelMaster&& versionModelMaster) = default;

    VersionModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(VersionModelMaster);
    }

    const VersionModelMaster* operator->() const
    {
        return this;
    }

    VersionModelMaster* operator->()
    {
        return this;
    }
    /**
     * バージョンマスターを取得
     *
     * @return バージョンマスター
     */
    const optional<StringHolder>& getVersionModelId() const
    {
        return ensureData().versionModelId;
    }

    /**
     * バージョンマスターを設定
     *
     * @param versionModelId バージョンマスター
     */
    void setVersionModelId(StringHolder versionModelId)
    {
        ensureData().versionModelId.emplace(std::move(versionModelId));
    }

    /**
     * バージョンマスターを設定
     *
     * @param versionModelId バージョンマスター
     */
    VersionModelMaster& withVersionModelId(StringHolder versionModelId)
    {
        setVersionModelId(std::move(versionModelId));
        return *this;
    }

    /**
     * バージョン名を取得
     *
     * @return バージョン名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * バージョン名を設定
     *
     * @param name バージョン名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * バージョン名を設定
     *
     * @param name バージョン名
     */
    VersionModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
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
    VersionModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    VersionModelMaster& withMetadata(StringHolder metadata)
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
    VersionModelMaster& withWarningVersion(Version warningVersion)
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
    VersionModelMaster& withErrorVersion(Version errorVersion)
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
    VersionModelMaster& withScope(StringHolder scope)
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
    VersionModelMaster& withCurrentVersion(Version currentVersion)
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
    VersionModelMaster& withNeedSignature(Bool needSignature)
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
    VersionModelMaster& withSignatureKeyId(StringHolder signatureKeyId)
    {
        setSignatureKeyId(std::move(signatureKeyId));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    VersionModelMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    VersionModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const VersionModelMaster& lhs, const VersionModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->versionModelId != lhr.m_pData->versionModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->warningVersion != lhr.m_pData->warningVersion)
        {
            return true;
        }
        if (lhs.m_pData->errorVersion != lhr.m_pData->errorVersion)
        {
            return true;
        }
        if (lhs.m_pData->scope != lhr.m_pData->scope)
        {
            return true;
        }
        if (lhs.m_pData->currentVersion != lhr.m_pData->currentVersion)
        {
            return true;
        }
        if (lhs.m_pData->needSignature != lhr.m_pData->needSignature)
        {
            return true;
        }
        if (lhs.m_pData->signatureKeyId != lhr.m_pData->signatureKeyId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const VersionModelMaster& lhs, const VersionModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_VERSION_MODEL_VERSIONMODELMASTER_HPP_