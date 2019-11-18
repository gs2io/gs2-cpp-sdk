

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

#ifndef GS2_EZ_VERSION_MODEL_EZVERSIONMODEL_HPP_
#define GS2_EZ_VERSION_MODEL_EZVERSIONMODEL_HPP_

#include <gs2/version/model/VersionModel.hpp>
#include "EzVersion.hpp"
#include "EzVersion.hpp"
#include "EzVersion.hpp"


namespace gs2 { namespace ez { namespace version {

class EzVersionModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** バージョンの種類名 */
        gs2::optional<StringHolder> name;
        /** バージョンの種類のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** バージョンアップを促すバージョン */
        gs2::optional<EzVersion> warningVersion;
        /** バージョンチェックを蹴るバージョン */
        gs2::optional<EzVersion> errorVersion;
        /** 判定に使用するバージョン値の種類 */
        gs2::optional<StringHolder> scope;
        /** 現在のバージョン */
        gs2::optional<EzVersion> currentVersion;
        /** 判定するバージョン値に署名検証を必要とするか */
        gs2::optional<Bool> needSignature;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            scope(data.scope),
            needSignature(data.needSignature)
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

        Data(const gs2::version::VersionModel& versionModel) :
            name(versionModel.getName()),
            metadata(versionModel.getMetadata()),
            warningVersion(*versionModel.getWarningVersion()),
            errorVersion(*versionModel.getErrorVersion()),
            scope(versionModel.getScope()),
            currentVersion(*versionModel.getCurrentVersion()),
            needSignature(versionModel.getNeedSignature() ? *versionModel.getNeedSignature() : false)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzVersionModel() = default;
    EzVersionModel(const EzVersionModel& ezVersionModel) = default;
    EzVersionModel(EzVersionModel&& ezVersionModel) = default;
    ~EzVersionModel() = default;

    EzVersionModel(gs2::version::VersionModel versionModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(versionModel)
    {}

    EzVersionModel& operator=(const EzVersionModel& ezVersionModel) = default;
    EzVersionModel& operator=(EzVersionModel&& ezVersionModel) = default;

    EzVersionModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzVersionModel);
    }

    gs2::version::VersionModel ToModel() const
    {
        gs2::version::VersionModel versionModel;
        versionModel.setName(getName());
        versionModel.setMetadata(getMetadata());
        versionModel.setWarningVersion(getWarningVersion().ToModel());
        versionModel.setErrorVersion(getErrorVersion().ToModel());
        versionModel.setScope(getScope());
        versionModel.setCurrentVersion(getCurrentVersion().ToModel());
        versionModel.setNeedSignature(getNeedSignature());
        return versionModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const EzVersion& getWarningVersion() const
    {
        return *ensureData().warningVersion;
    }

    const EzVersion& getErrorVersion() const
    {
        return *ensureData().errorVersion;
    }

    const StringHolder& getScope() const
    {
        return *ensureData().scope;
    }

    const EzVersion& getCurrentVersion() const
    {
        return *ensureData().currentVersion;
    }

    Bool getNeedSignature() const
    {
        return *ensureData().needSignature;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setWarningVersion(EzVersion warningVersion)
    {
        ensureData().warningVersion = std::move(warningVersion);
    }

    void setErrorVersion(EzVersion errorVersion)
    {
        ensureData().errorVersion = std::move(errorVersion);
    }

    void setScope(StringHolder scope)
    {
        ensureData().scope = std::move(scope);
    }

    void setCurrentVersion(EzVersion currentVersion)
    {
        ensureData().currentVersion = std::move(currentVersion);
    }

    void setNeedSignature(Bool needSignature)
    {
        ensureData().needSignature = needSignature;
    }

    EzVersionModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzVersionModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzVersionModel& withWarningVersion(EzVersion warningVersion)
    {
        setWarningVersion(std::move(warningVersion));
        return *this;
    }

    EzVersionModel& withErrorVersion(EzVersion errorVersion)
    {
        setErrorVersion(std::move(errorVersion));
        return *this;
    }

    EzVersionModel& withScope(StringHolder scope)
    {
        setScope(std::move(scope));
        return *this;
    }

    EzVersionModel& withCurrentVersion(EzVersion currentVersion)
    {
        setCurrentVersion(std::move(currentVersion));
        return *this;
    }

    EzVersionModel& withNeedSignature(Bool needSignature)
    {
        setNeedSignature(needSignature);
        return *this;
    }
};

}}}

#endif //GS2_EZ_VERSION_EZVERSIONMODEL_HPP_