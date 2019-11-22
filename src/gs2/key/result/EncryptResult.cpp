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

#include "EncryptResult.hpp"
#include <gs2/core/json/JsonParser.hpp>

namespace gs2 { namespace key
{

EncryptResult::Data::Data(const Data& data) :
    detail::json::IModel(data),
    data(data.data)
{
}

void EncryptResult::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "data") == 0)
    {
        if (jsonValue.IsString())
        {
            this->data.emplace(jsonValue.GetString());
        }
    }
}

EncryptResult EncryptResult::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EncryptResult);
}

} }