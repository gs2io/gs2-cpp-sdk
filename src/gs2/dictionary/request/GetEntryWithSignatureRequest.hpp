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

#ifndef GS2_DICTIONARY_CONTROL_GETENTRYWITHSIGNATUREREQUEST_HPP_
#define GS2_DICTIONARY_CONTROL_GETENTRYWITHSIGNATUREREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/dictionary/Gs2DictionaryConst.hpp>
#include <gs2/dictionary/model/model.hpp>
#include <memory>

namespace gs2 { namespace dictionary
{

/**
 * エントリーを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetEntryWithSignatureRequest : public Gs2BasicRequest, public Gs2Dictionary
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** エントリー名 */
        optional<StringHolder> entryModelName;
        /** 署名の発行に使用する暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            entryModelName(data.entryModelName),
            keyId(data.keyId),
            duplicationAvoider(data.duplicationAvoider)
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
    GetEntryWithSignatureRequest() = default;
    GetEntryWithSignatureRequest(const GetEntryWithSignatureRequest& getEntryWithSignatureRequest) = default;
    GetEntryWithSignatureRequest(GetEntryWithSignatureRequest&& getEntryWithSignatureRequest) = default;
    ~GetEntryWithSignatureRequest() GS2_OVERRIDE = default;

    GetEntryWithSignatureRequest& operator=(const GetEntryWithSignatureRequest& getEntryWithSignatureRequest) = default;
    GetEntryWithSignatureRequest& operator=(GetEntryWithSignatureRequest&& getEntryWithSignatureRequest) = default;

    GetEntryWithSignatureRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetEntryWithSignatureRequest);
    }

    const GetEntryWithSignatureRequest* operator->() const
    {
        return this;
    }

    GetEntryWithSignatureRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    GetEntryWithSignatureRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    GetEntryWithSignatureRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * エントリー名を取得
     *
     * @return エントリー名
     */
    const optional<StringHolder>& getEntryModelName() const
    {
        return ensureData().entryModelName;
    }

    /**
     * エントリー名を設定
     *
     * @param entryModelName エントリー名
     */
    void setEntryModelName(StringHolder entryModelName)
    {
        ensureData().entryModelName.emplace(std::move(entryModelName));
    }

    /**
     * エントリー名を設定
     *
     * @param entryModelName エントリー名
     */
    GetEntryWithSignatureRequest& withEntryModelName(StringHolder entryModelName)
    {
        ensureData().entryModelName.emplace(std::move(entryModelName));
        return *this;
    }

    /**
     * 署名の発行に使用する暗号鍵 のGRNを取得
     *
     * @return 署名の発行に使用する暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 署名の発行に使用する暗号鍵 のGRNを設定
     *
     * @param keyId 署名の発行に使用する暗号鍵 のGRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 署名の発行に使用する暗号鍵 のGRNを設定
     *
     * @param keyId 署名の発行に使用する暗号鍵 のGRN
     */
    GetEntryWithSignatureRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    GetEntryWithSignatureRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetEntryWithSignatureRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetEntryWithSignatureRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DICTIONARY_CONTROL_GETENTRYWITHSIGNATUREREQUEST_HPP_