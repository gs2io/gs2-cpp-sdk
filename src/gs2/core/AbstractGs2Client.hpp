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

#ifndef GS2_CORE_ABSTRACTGS2CLIENT_HPP_
#define GS2_CORE_ABSTRACTGS2CLIENT_HPP_

#include "Gs2Object.hpp"
#include "model/Region.hpp"
#include <string>

namespace cocos2d { namespace network {
class HttpClient;
class HttpRequest;
class HttpResponse;
}}

GS2_START_OF_NAMESPACE

class IGs2Credential;
class Gs2BasicRequest;

namespace detail {
class HttpRequestBase;
}

class AbstractGs2ClientBase : public Gs2Object
{
private:
    /** 認証情報 */
    IGs2Credential& m_Credential;
    /** アクセス先リージョン */
    Region m_Region;

public:
    explicit AbstractGs2ClientBase(IGs2Credential& credential);

    AbstractGs2ClientBase(IGs2Credential& credential, const Region& region);

    AbstractGs2ClientBase(IGs2Credential& credential, const Char region[]);

    /**
     * アクセス先リージョンを取得
     *
     * @return アクセス先リージョン
     */
    const Region& getRegion() const
    {
        return m_Region;
    }

    /**
     * アクセス先リージョンを設定
     *
     * @param region アクセス先リージョン
     */
    void setRegion(Region region)
    {
        m_Region = region;
    }

    virtual const Char* getEndPoint() const = 0;

protected:
    /**
     * HTTPリクエストにURLを設定
     *
     * @param httpRequest HTTPリクエスト
     * @param url URLパターン
     */
    void setUrl(::cocos2d::network::HttpRequest& httpRequest, const Char url[]) const;

    IGs2Credential& getCredential()
    {
        return m_Credential;
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_ABSTRACTGS2CLIENT_HPP_
