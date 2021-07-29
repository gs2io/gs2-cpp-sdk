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

#ifndef GS2_EZ_FORMATION_MODEL_EZACQUIREACTIONCONFIG_HPP_
#define GS2_EZ_FORMATION_MODEL_EZACQUIREACTIONCONFIG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzConfig.hpp"
#include <memory>


namespace gs2 {

namespace formation {

class AcquireActionConfig;

}

namespace ez { namespace formation {

class EzAcquireActionConfig : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スロット名 */
        StringHolder name;
        /** スタンプシートに使用するコンフィグ */
        List<EzConfig> config;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::AcquireActionConfig& acquireActionConfig);
        Data(const gs2::optional<gs2::formation::AcquireActionConfig>& acquireActionConfig);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAcquireActionConfig() = default;
    EzAcquireActionConfig(const EzAcquireActionConfig& ezAcquireActionConfig) = default;
    EzAcquireActionConfig(EzAcquireActionConfig&& ezAcquireActionConfig) = default;
    ~EzAcquireActionConfig() = default;

    EzAcquireActionConfig(gs2::formation::AcquireActionConfig acquireActionConfig);
    EzAcquireActionConfig(gs2::optional<gs2::formation::AcquireActionConfig> acquireActionConfig);

    EzAcquireActionConfig& operator=(const EzAcquireActionConfig& ezAcquireActionConfig) = default;
    EzAcquireActionConfig& operator=(EzAcquireActionConfig&& ezAcquireActionConfig) = default;

    EzAcquireActionConfig deepCopy() const;

    gs2::formation::AcquireActionConfig ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const List<EzConfig>& getConfig() const
    {
        return ensureData().config;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setConfig(List<EzConfig> config)
    {
        ensureData().config = std::move(config);
    }

    EzAcquireActionConfig& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzAcquireActionConfig& withConfig(List<EzConfig> config)
    {
        setConfig(std::move(config));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZACQUIREACTIONCONFIG_HPP_