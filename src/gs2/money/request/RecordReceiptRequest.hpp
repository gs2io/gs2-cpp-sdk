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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            contentsId(data.contentsId),
            receipt(data.receipt),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            userId(std::move(data.userId)),
            contentsId(std::move(data.contentsId)),
            receipt(std::move(data.receipt)),
            duplicationAvoider(std::move(data.duplicationAvoider))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    RecordReceiptRequest() :
        m_pData(nullptr)
    {}

    RecordReceiptRequest(const RecordReceiptRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    RecordReceiptRequest(RecordReceiptRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~RecordReceiptRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RecordReceiptRequest& operator=(const RecordReceiptRequest& recordReceiptRequest)
    {
        Gs2BasicRequest::operator=(recordReceiptRequest);
        Gs2Money::operator=(recordReceiptRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*recordReceiptRequest.m_pData);

        return *this;
    }

    RecordReceiptRequest& operator=(RecordReceiptRequest&& recordReceiptRequest)
    {
        Gs2BasicRequest::operator=(std::move(recordReceiptRequest));
        Gs2Money::operator=(std::move(recordReceiptRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = recordReceiptRequest.m_pData;
        recordReceiptRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペースの名前を設定
     *
     * @param namespaceName ネームスペースの名前
     */
    RecordReceiptRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    RecordReceiptRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    void setContentsId(const Char* contentsId)
    {
        ensureData().contentsId.emplace(contentsId);
    }

    /**
     * プラットフォームストアのコンテンツIDを設定
     *
     * @param contentsId プラットフォームストアのコンテンツID
     */
    RecordReceiptRequest& withContentsId(const Char* contentsId)
    {
        ensureData().contentsId.emplace(contentsId);
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
    void setReceipt(const Char* receipt)
    {
        ensureData().receipt.emplace(receipt);
    }

    /**
     * レシートを設定
     *
     * @param receipt レシート
     */
    RecordReceiptRequest& withReceipt(const Char* receipt)
    {
        ensureData().receipt.emplace(receipt);
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
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    RecordReceiptRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    RecordReceiptRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    RecordReceiptRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    RecordReceiptRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    RecordReceiptRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_MONEY_CONTROL_RECORDRECEIPTREQUEST_HPP_