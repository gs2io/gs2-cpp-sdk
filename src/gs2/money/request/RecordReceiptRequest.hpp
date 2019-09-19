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

#ifndef GS2_MONEY_CONTROL_RECORDRECEIPTREQUEST_HPP_
#define GS2_MONEY_CONTROL_RECORDRECEIPTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace money
{

/**
 * レシートを記録 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class RecordReceiptRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペースの名前 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** プラットフォームストアのコンテンツID */
        optional<StringHolder> contentsId;
        /** レシート */
        optional<StringHolder> receipt;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            contentsId(data.contentsId),
            receipt(data.receipt),
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
    RecordReceiptRequest() = default;
    RecordReceiptRequest(const RecordReceiptRequest& recordReceiptRequest) = default;
    RecordReceiptRequest(RecordReceiptRequest&& recordReceiptRequest) = default;
    ~RecordReceiptRequest() GS2_OVERRIDE = default;

    RecordReceiptRequest& operator=(const RecordReceiptRequest& recordReceiptRequest) = default;
    RecordReceiptRequest& operator=(RecordReceiptRequest&& recordReceiptRequest) = default;

    RecordReceiptRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RecordReceiptRequest);
    }

    const RecordReceiptRequest* operator->() const
    {
        return this;
    }

    RecordReceiptRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペースの名前を取得
     *
     * @return ネームスペースの名前
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param namespaceName ネームスペースの名前
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param namespaceName ネームスペースの名前
     */
    RecordReceiptRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    RecordReceiptRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * プラットフォームストアのコンテンツIDを取得
     *
     * @return プラットフォームストアのコンテンツID
     */
    const optional<StringHolder>& getContentsId() const
    {
        return ensureData().contentsId;
    }

    /**
     * プラットフォームストアのコンテンツIDを設定
     *
     * @param contentsId プラットフォームストアのコンテンツID
     */
    void setContentsId(StringHolder contentsId)
    {
        ensureData().contentsId.emplace(std::move(contentsId));
    }

    /**
     * プラットフォームストアのコンテンツIDを設定
     *
     * @param contentsId プラットフォームストアのコンテンツID
     */
    RecordReceiptRequest& withContentsId(StringHolder contentsId)
    {
        ensureData().contentsId.emplace(std::move(contentsId));
        return *this;
    }

    /**
     * レシートを取得
     *
     * @return レシート
     */
    const optional<StringHolder>& getReceipt() const
    {
        return ensureData().receipt;
    }

    /**
     * レシートを設定
     *
     * @param receipt レシート
     */
    void setReceipt(StringHolder receipt)
    {
        ensureData().receipt.emplace(std::move(receipt));
    }

    /**
     * レシートを設定
     *
     * @param receipt レシート
     */
    RecordReceiptRequest& withReceipt(StringHolder receipt)
    {
        ensureData().receipt.emplace(std::move(receipt));
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
    RecordReceiptRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    RecordReceiptRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    RecordReceiptRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MONEY_CONTROL_RECORDRECEIPTREQUEST_HPP_