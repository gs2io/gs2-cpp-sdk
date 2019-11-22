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

#include "EzConfig.hpp"
#include <gs2/quest/model/Config.hpp>


namespace gs2 { namespace ez { namespace quest {

EzConfig::Data::Data(const Data& data) :
    Gs2Object(data),
    key(data.key),
    value(data.value)
{
}

EzConfig::Data::Data(const gs2::quest::Config& config) :
    key(config.getKey()),
    value(config.getValue())
{
}

EzConfig::EzConfig(gs2::quest::Config config) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(config)
{
}

EzConfig EzConfig::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzConfig);
}

gs2::quest::Config EzConfig::ToModel() const
{
    gs2::quest::Config config;
    config.setKey(getKey());
    config.setValue(getValue());
    return config;
}

}}}