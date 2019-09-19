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

#ifndef GS2_KEY_CONTROL_DECRYPTREQUEST_HPP_
#define GS2_KEY_CONTROL_DECRYPTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2KeyConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace key
{

/**
 * データを復号します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DecryptRequest : public Gs2BasicRequest, public Gs2Key
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 暗号鍵名 */
        optional<StringHolder> keyName;
        /** None */
        optional<StringHolder> data;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            keyName(data.keyName),
            data(data.data)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    DecryptRequest() = default;
    DecryptRequest(const DecryptRequest& decryptRequest) = default;
    DecryptRequest(DecryptRequest&& decryptRequest) = default;
    ~DecryptRequest() GS2_OVERRIDE = default;

    DecryptRequest& operator=(const DecryptRequest& decryptRequest) = default;
    DecryptRequest& operator=(DecryptRequest&& decryptRequest) = default;

    DecryptRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DecryptRequest);
    }

    const DecryptRequest* operator->() const
    {
        return this;
    }

    DecryptRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    DecryptRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 暗号鍵名を取得
     *
     * @return 暗号鍵名
     */
    const optional<StringHolder>& getKeyName() const
    {
        return ensureData().keyName;
    }

    /**
     * 暗号鍵名を設定
     *
     * @param keyName 暗号鍵名
     */
    void setKeyName(StringHolder keyName)
    {
        ensureData().keyName.emplace(std::move(keyName));
    }

    /**
     * 暗号鍵名を設定
     *
     * @param keyName 暗号鍵名
     */
    DecryptRequest& withKeyName(StringHolder keyName)
    {
        ensureData().keyName.emplace(std::move(keyName));
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getData() const
    {
        return ensureData().data;
    }

    /**
     * Noneを設定
     *
     * @param data None
     */
    void setData(StringHolder data)
    {
        ensureData().data.emplace(std::move(data));
    }

    /**
     * Noneを設定
     *
     * @param data None
     */
    DecryptRequest& withData(StringHolder data)
    {
        ensureData().data.emplace(std::move(data));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DecryptRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DecryptRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_KEY_CONTROL_DECRYPTREQUEST_HPP_