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

#include "DebugInvokeResult.hpp"
#include <gs2/core/json/JsonParser.hpp>

namespace gs2 { namespace script
{

DebugInvokeResult::Data::Data(const Data& data) :
    detail::json::IModel(data),
    code(data.code),
    result(data.result),
    executeTime(data.executeTime),
    charged(data.charged)
{
    if (data.output)
    {
        output = data.output->deepCopy();
    }
}

void DebugInvokeResult::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "code") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->code = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "result") == 0)
    {
        if (jsonValue.IsString())
        {
            this->result.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "executeTime") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->executeTime = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "charged") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->charged = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "output") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->output.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                auto valueStr = json->GetString();
                StringHolder stringHolder(valueStr);
                *this->output += std::move(stringHolder);
            }
        }
    }
}

DebugInvokeResult DebugInvokeResult::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DebugInvokeResult);
}

} }