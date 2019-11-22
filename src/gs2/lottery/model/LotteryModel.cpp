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

#include "LotteryModel.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

LotteryModel::Data::Data(const Data& data) :
    detail::json::IModel(data),
    lotteryModelId(data.lotteryModelId),
    name(data.name),
    metadata(data.metadata),
    mode(data.mode),
    method(data.method),
    prizeTableName(data.prizeTableName),
    choicePrizeTableScriptId(data.choicePrizeTableScriptId)
{
}

void LotteryModel::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "lotteryModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->lotteryModelId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "metadata") == 0)
    {
        if (jsonValue.IsString())
        {
            this->metadata.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "mode") == 0)
    {
        if (jsonValue.IsString())
        {
            this->mode.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "method") == 0)
    {
        if (jsonValue.IsString())
        {
            this->method.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "prizeTableName") == 0)
    {
        if (jsonValue.IsString())
        {
            this->prizeTableName.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "choicePrizeTableScriptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->choicePrizeTableScriptId.emplace(jsonValue.GetString());
        }
    }
}

LotteryModel LotteryModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LotteryModel);
}

bool operator!=(const LotteryModel& lhs, const LotteryModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->lotteryModelId != lhr.m_pData->lotteryModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->mode != lhr.m_pData->mode)
        {
            return true;
        }
        if (lhs.m_pData->method != lhr.m_pData->method)
        {
            return true;
        }
        if (lhs.m_pData->prizeTableName != lhr.m_pData->prizeTableName)
        {
            return true;
        }
        if (lhs.m_pData->choicePrizeTableScriptId != lhr.m_pData->choicePrizeTableScriptId)
        {
            return true;
        }
    }
    return false;
}

} }