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

#ifndef GS2_EZ_FORMATION_MODEL_EZCONFIG_HPP_
#define GS2_EZ_FORMATION_MODEL_EZCONFIG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace formation {

class Config;

}

namespace ez { namespace formation {

class EzConfig : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 名前 */
        StringHolder key;
        /** 値 */
        StringHolder value;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::Config& config);
        Data(const gs2::optional<gs2::formation::Config>& config);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzConfig() = default;
    EzConfig(const EzConfig& ezConfig) = default;
    EzConfig(EzConfig&& ezConfig) = default;
    ~EzConfig() = default;

    EzConfig(gs2::formation::Config config);
    EzConfig(gs2::optional<gs2::formation::Config> config);

    EzConfig& operator=(const EzConfig& ezConfig) = default;
    EzConfig& operator=(EzConfig&& ezConfig) = default;

    EzConfig deepCopy() const;

    gs2::formation::Config ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getKey() const
    {
        return ensureData().key;
    }

    const StringHolder& getValue() const
    {
        return ensureData().value;
    }

    // ========================================
    //   Setters
    // ========================================

    void setKey(StringHolder key)
    {
        ensureData().key = std::move(key);
    }

    void setValue(StringHolder value)
    {
        ensureData().value = std::move(value);
    }

    EzConfig& withKey(StringHolder key)
    {
        setKey(std::move(key));
        return *this;
    }

    EzConfig& withValue(StringHolder value)
    {
        setValue(std::move(value));
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZCONFIG_HPP_