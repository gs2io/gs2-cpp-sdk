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

#ifndef GS2_CORE_MODEL_BASICGS2CREDENTIAL_HPP_
#define GS2_CORE_MODEL_BASICGS2CREDENTIAL_HPP_

#include "IGs2Credential.hpp"
#include "../util/StringHolder.hpp"
#include <mutex>

GS2_START_OF_NAMESPACE

class BasicGs2Credential : public IGs2Credential
{
private:
    /** クライアントID */
    StringHolder m_ClientId;
    /** クライアントシークレット */
    StringHolder m_ClientSecret;

public:
    /**
     * コンストラクタ。
     *
     * @param clientId クライアントID
     * @param clientSecret クライアントシークレット
     */
    BasicGs2Credential(StringHolder clientId, StringHolder clientSecret);

    BasicGs2Credential(const BasicGs2Credential& basicGs2Credential) = default;
    BasicGs2Credential(BasicGs2Credential&& basicGs2Credential) = default;
    ~BasicGs2Credential() GS2_OVERRIDE = default;

    /**
     * クライアントIDを取得。
     *
     * @return クライアントID
     */
    const StringHolder& getClientId() const
    {
        return m_ClientId;
    }

    /**
     * クライアントシークレットを取得。
     *
     * @return クライアントシークレット
     */
    const StringHolder& getClientSecret() const
    {
        return m_ClientSecret;
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_MODEL_BASICGS2CREDENTIAL_HPP_
