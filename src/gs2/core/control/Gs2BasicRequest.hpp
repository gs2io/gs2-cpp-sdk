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

#ifndef GS2_CORE_CONTROL_GS2BASICREQUEST_HPP_
#define GS2_CORE_CONTROL_GS2BASICREQUEST_HPP_

#include "../Gs2Object.hpp"
#include "../util/StringHolder.hpp"
#include "../external/optional/optional.hpp"

GS2_START_OF_NAMESPACE

class Gs2BasicRequest : public Gs2Object
{
protected:
    class Data : public Gs2Object
    {
    public:
        /** GS2認証クライアントID */
        gs2::optional<StringHolder> gs2ClientId;
        /** GS2リクエストID */
        gs2::optional<StringHolder> gs2RequestId;
        /** コンテクストスタック */
        gs2::optional<StringHolder> contextStack;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gs2ClientId(data.gs2ClientId),
            gs2RequestId(data.gs2RequestId),
            contextStack(data.contextStack)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gs2ClientId(std::move(data.gs2ClientId)),
            gs2RequestId(std::move(data.gs2RequestId)),
            contextStack(std::move(data.contextStack))
        {}

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

private:
    virtual Data& getData_() = 0;
    virtual const Data& getData_() const = 0;

protected:
    Gs2BasicRequest() = default;

    Gs2BasicRequest(const Gs2BasicRequest& gs2BasicRequest) :
        Gs2Object(gs2BasicRequest)
    {}

    Gs2BasicRequest(Gs2BasicRequest&& gs2BasicRequest) :
        Gs2Object(std::move(gs2BasicRequest))
    {}

    virtual ~Gs2BasicRequest() = default;

    Gs2BasicRequest& operator=(const Gs2BasicRequest& gs2BasicRequest)
    {
        Gs2Object::operator=(gs2BasicRequest);
        return *this;
    }

    Gs2BasicRequest& operator=(Gs2BasicRequest&& gs2BasicRequest)
    {
        Gs2Object::operator=(std::move(gs2BasicRequest));
        return *this;
    }

public:
    /**
     * GS2認証クライアントIDを取得。
     *
     * @return GS2認証クライアントID
     */
    const gs2::optional<StringHolder>& getGs2ClientId() const
    {
        return getData_().gs2ClientId;
    }

    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    void setGs2ClientId(const Char* gs2ClientId)
    {
        getData_().gs2ClientId.emplace(gs2ClientId);
    }

    /**
     * GS2リクエストIDを取得。
     *
     * @return GS2リクエストID
     */
    const gs2::optional<StringHolder>& getRequestId() const
    {
        return getData_().gs2RequestId;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    void setRequestId(const Char* gs2RequestId)
    {
        getData_().gs2RequestId.emplace(gs2RequestId);
    }

    /**
     * コンテクストスタックを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param contextStack コンテクストスタック
     */
    void setContextStack(const Char* contextStack)
    {
        getData_().contextStack.emplace(contextStack);
    }

    /**
     * コンテクストスタックを取得。
     *
     * @return コンテクストスタック
     */
    const gs2::optional<StringHolder>& getContextStack() const
    {
        return getData_().contextStack;
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_CONTROL_GS2BASICREQUEST_HPP_
