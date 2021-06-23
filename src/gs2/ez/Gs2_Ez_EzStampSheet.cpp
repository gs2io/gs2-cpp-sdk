/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#include "EzStampSheet.hpp"
#include "../core/model/SignedStampSheet.hpp"
#include "../core/json/JsonParser.hpp"
#include "Client.hpp"

namespace gs2 { namespace ez {

EzStampSheet::EzStampSheet(StringHolder signedStampSheetString) :
    m_SignedStampSheetString(std::move(signedStampSheetString))
{
    SignedStampSheet signedStampSheet;
    detail::json::JsonParser::parse(&signedStampSheet.getModel(), m_SignedStampSheetString);

    const auto& body = signedStampSheet.getBody();
    if (body)
    {
        StampSheet stampSheet;
        detail::json::JsonParser::parse(&stampSheet.getModel(), *body);

        const auto& stampTaskStrings = stampSheet.getTasks();
        if (stampTaskStrings)
        {
            for (auto i = 0; i < stampTaskStrings->getCount(); ++i)
            {
                m_StampTasks += EzStampTask((*stampTaskStrings)[i]);
            }
        }
    }
}

void EzStampSheet::execute(
    EzRunStampSheetCallback callback,
    StringHolder stackContext,
    Client& client,
    StringHolder distributorNamespaceName,
    StringHolder stampSheetEncryptKeyId
)
{
    client.distributor.runStampSheet(
        std::move(callback),
        std::move(distributorNamespaceName),
        m_SignedStampSheetString,
        std::move(stampSheetEncryptKeyId),
        std::move(stackContext)
    );
}

}}
