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

#ifndef GS2_MONEY_CONTROL_RECORDRECEIPTBYSTAMPTASKREQUEST_HPP_
#define GS2_MONEY_CONTROL_RECORDRECEIPTBYSTAMPTASKREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MoneyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * スタンプシートを使用してレシートを記録 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class RecordReceiptByStampTaskRequest : public Gs2BasicRequest, public Gs2Money
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタンプタスク */
        optional<StringHolder> stampTask;
        /** スタンプタスクの署名検証に使用する 暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            stampTask(data.stampTask),
            keyId(data.keyId),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            stampTask(std::move(data.stampTask)),
            keyId(std::move(data.keyId)),
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
    RecordReceiptByStampTaskRequest() :
        m_pData(nullptr)
    {}

    RecordReceiptByStampTaskRequest(const RecordReceiptByStampTaskRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Money(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    RecordReceiptByStampTaskRequest(RecordReceiptByStampTaskRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Money(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~RecordReceiptByStampTaskRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RecordReceiptByStampTaskRequest& operator=(const RecordReceiptByStampTaskRequest& recordReceiptByStampTaskRequest)
    {
        Gs2BasicRequest::operator=(recordReceiptByStampTaskRequest);
        Gs2Money::operator=(recordReceiptByStampTaskRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*recordReceiptByStampTaskRequest.m_pData);

        return *this;
    }

    RecordReceiptByStampTaskRequest& operator=(RecordReceiptByStampTaskRequest&& recordReceiptByStampTaskRequest)
    {
        Gs2BasicRequest::operator=(std::move(recordReceiptByStampTaskRequest));
        Gs2Money::operator=(std::move(recordReceiptByStampTaskRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = recordReceiptByStampTaskRequest.m_pData;
        recordReceiptByStampTaskRequest.m_pData = nullptr;

        return *this;
    }

    const RecordReceiptByStampTaskRequest* operator->() const
    {
        return this;
    }

    RecordReceiptByStampTaskRequest* operator->()
    {
        return this;
    }

    /**
     * スタンプタスクを取得
     *
     * @return スタンプタスク
     */
    const optional<StringHolder>& getStampTask() const
    {
        return ensureData().stampTask;
    }

    /**
     * スタンプタスクを設定
     *
     * @param stampTask スタンプタスク
     */
    void setStampTask(const Char* stampTask)
    {
        ensureData().stampTask.emplace(stampTask);
    }

    /**
     * スタンプタスクを設定
     *
     * @param stampTask スタンプタスク
     */
    RecordReceiptByStampTaskRequest& withStampTask(const Char* stampTask)
    {
        ensureData().stampTask.emplace(stampTask);
        return *this;
    }

    /**
     * スタンプタスクの署名検証に使用する 暗号鍵 のGRNを取得
     *
     * @return スタンプタスクの署名検証に使用する 暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * スタンプタスクの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプタスクの署名検証に使用する 暗号鍵 のGRN
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * スタンプタスクの署名検証に使用する 暗号鍵 のGRNを設定
     *
     * @param keyId スタンプタスクの署名検証に使用する 暗号鍵 のGRN
     */
    RecordReceiptByStampTaskRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
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
    RecordReceiptByStampTaskRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    RecordReceiptByStampTaskRequest& withGs2ClientId(const Char* gs2ClientId)
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
    RecordReceiptByStampTaskRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    RecordReceiptByStampTaskRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    RecordReceiptByStampTaskRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_MONEY_CONTROL_RECORDRECEIPTBYSTAMPTASKREQUEST_HPP_