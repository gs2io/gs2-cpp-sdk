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

#ifndef GS2_VERSION_MODEL_STATUS_HPP_
#define GS2_VERSION_MODEL_STATUS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "VersionModel.hpp"
#include "Version.hpp"
#include <memory>

namespace gs2 { namespace version {

/**
 * バージョンの検証結果
 *
 * @author Game Server Services, Inc.
 *
 */
class Status : public Gs2Object
{
    friend bool operator!=(const Status& lhs, const Status& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** バージョン設定 */
        optional<VersionModel> versionModel;
        /** 現在のバージョン */
        optional<Version> currentVersion;

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
    Status() = default;
    Status(const Status& status) = default;
    Status(Status&& status) = default;
    ~Status() = default;

    Status& operator=(const Status& status) = default;
    Status& operator=(Status&& status) = default;

    Status deepCopy() const;

    const Status* operator->() const
    {
        return this;
    }

    Status* operator->()
    {
        return this;
    }
    /**
     * バージョン設定を取得
     *
     * @return バージョン設定
     */
    const optional<VersionModel>& getVersionModel() const
    {
        return ensureData().versionModel;
    }

    /**
     * バージョン設定を設定
     *
     * @param versionModel バージョン設定
     */
    void setVersionModel(VersionModel versionModel)
    {
        ensureData().versionModel.emplace(std::move(versionModel));
    }

    /**
     * バージョン設定を設定
     *
     * @param versionModel バージョン設定
     */
    Status& withVersionModel(VersionModel versionModel)
    {
        setVersionModel(std::move(versionModel));
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
    Status& withCurrentVersion(Version currentVersion)
    {
        setCurrentVersion(std::move(currentVersion));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Status& lhs, const Status& lhr);

inline bool operator==(const Status& lhs, const Status& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_VERSION_MODEL_STATUS_HPP_