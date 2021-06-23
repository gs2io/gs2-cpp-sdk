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

#include "EzAcquireActionConfig.hpp"
#include <gs2/formation/model/AcquireActionConfig.hpp>


namespace gs2 { namespace ez { namespace formation {

EzAcquireActionConfig::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name)
{
    if (data.config)
    {
        config = data.config->deepCopy();
    }
}

EzAcquireActionConfig::Data::Data(const gs2::formation::AcquireActionConfig& acquireActionConfig) :
    name(acquireActionConfig.getName())
{
    config.emplace();
    if (acquireActionConfig.getConfig())
    {
        for (int i = 0; i < acquireActionConfig.getConfig()->getCount(); ++i)
        {
            *config += EzConfig((*acquireActionConfig.getConfig())[i]);
        }
    }
}

EzAcquireActionConfig::EzAcquireActionConfig(gs2::formation::AcquireActionConfig acquireActionConfig) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(acquireActionConfig)
{
}

EzAcquireActionConfig EzAcquireActionConfig::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAcquireActionConfig);
}

gs2::formation::AcquireActionConfig EzAcquireActionConfig::ToModel() const
{
    gs2::formation::AcquireActionConfig acquireActionConfig;
    acquireActionConfig.setName(getName());
    {
        gs2::List<gs2::formation::Config> list;
        auto& config = getConfig();
        for (int i = 0; i < config.getCount(); ++i)
        {
            list += config[i].ToModel();
        }
        acquireActionConfig.setConfig(list);
    }
    return acquireActionConfig;
}

}}}