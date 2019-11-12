

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

#ifndef GS2_EZ_VERSION_MODEL_EZSTATUS_HPP_
#define GS2_EZ_VERSION_MODEL_EZSTATUS_HPP_

#include <gs2/version/model/Status.hpp>
#include "EzVersionModel.hpp"
#include "EzVersion.hpp"


namespace gs2 { namespace ez { namespace version {

class EzStatus : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** バージョン設定 */
        gs2::optional<EzVersionModel> versionModel;
        /** 現在のバージョン */
        gs2::optional<EzVersion> currentVersion;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            if (data.versionModel)
            {
                versionModel = data.versionModel->deepCopy();
            }
            if (data.currentVersion)
            {
                currentVersion = data.currentVersion->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::version::Status& status) :
            versionModel(*status.getVersionModel()),
            currentVersion(*status.getCurrentVersion())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzStatus() = default;
    EzStatus(const EzStatus& ezStatus) = default;
    EzStatus(EzStatus&& ezStatus) = default;
    ~EzStatus() = default;

    EzStatus(gs2::version::Status status) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(status)
    {}

    EzStatus& operator=(const EzStatus& ezStatus) = default;
    EzStatus& operator=(EzStatus&& ezStatus) = default;

    EzStatus deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStatus);
    }

    gs2::version::Status ToModel() const
    {
        gs2::version::Status status;
        status.setVersionModel(getVersionModel().ToModel());
        status.setCurrentVersion(getCurrentVersion().ToModel());
        return status;
    }

    // ========================================
    //   Getters
    // ========================================

    const EzVersionModel& getVersionModel() const
    {
        return *ensureData().versionModel;
    }

    const EzVersion& getCurrentVersion() const
    {
        return *ensureData().currentVersion;
    }

    // ========================================
    //   Setters
    // ========================================

    void setVersionModel(EzVersionModel versionModel)
    {
        ensureData().versionModel = std::move(versionModel);
    }

    void setCurrentVersion(EzVersion currentVersion)
    {
        ensureData().currentVersion = std::move(currentVersion);
    }

    EzStatus& withVersionModel(EzVersionModel versionModel)
    {
        setVersionModel(std::move(versionModel));
        return *this;
    }

    EzStatus& withCurrentVersion(EzVersion currentVersion)
    {
        setCurrentVersion(std::move(currentVersion));
        return *this;
    }
};

}}}

#endif //GS2_EZ_VERSION_EZSTATUS_HPP_