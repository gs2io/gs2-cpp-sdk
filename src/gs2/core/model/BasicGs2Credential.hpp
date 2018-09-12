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

GS2_START_OF_NAMESPACE

namespace detail {
class HttpRequestBase;
}
class Gs2BasicRequest;

class BasicGs2Credential : public IGs2Credential
{
private:
    /** クライアントID */
    StringHolder m_ClientId;
    /** クライアントシークレット */
    StringHolder m_ClientSecret;

    void authorize(detail::HttpRequestBase& request, const Gs2BasicRequest& basicRequest) const GS2_OVERRIDE;

public:
    BasicGs2Credential() = default;
    virtual ~BasicGs2Credential() = default;

    /**
     * コンストラクタ。
     *
     * @param clientId クライアントID
     * @param clientSecret クライアントシークレット
     */
    BasicGs2Credential(const Char clientId[], const Char clientSecret[]);

    /**
     * クライアントIDを取得。
     *
     * @return クライアントID
     */
    const StringHolder& getClientId() const;

    /**
     * クライアントシークレットを取得。
     *
     * @return クライアントシークレット
     */
    const StringHolder& getClientSecret() const;
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_MODEL_BASICGS2CREDENTIAL_HPP_
