/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_INGAMEPUSHNOTIFICATION_CONTROL_DESCRIBESTATUSREQUEST_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_CONTROL_DESCRIBESTATUSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InGamePushNotificationConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inGamePushNotification
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeStatusRequest : public Gs2BasicRequest, public Gs2InGamePushNotification
{
public:
    constexpr static const Char* const FUNCTION = "DescribeStatus";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲームの名前 */
        optional<StringHolder> gameName;
        /** データの取得を開始する位置を指定するトークン */
        optional<StringHolder> pageToken;
        /** データの取得件数 */
        optional<Int32> limit;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName),
            pageToken(data.pageToken),
            limit(data.limit)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName)),
            pageToken(std::move(data.pageToken)),
            limit(std::move(data.limit))
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
    DescribeStatusRequest() :
        m_pData(nullptr)
    {}

    DescribeStatusRequest(const DescribeStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2InGamePushNotification(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeStatusRequest(DescribeStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2InGamePushNotification(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeStatusRequest& operator=(const DescribeStatusRequest& describeStatusRequest)
    {
        Gs2BasicRequest::operator=(describeStatusRequest);
        Gs2InGamePushNotification::operator=(describeStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeStatusRequest.m_pData);

        return *this;
    }

    DescribeStatusRequest& operator=(DescribeStatusRequest&& describeStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeStatusRequest));
        Gs2InGamePushNotification::operator=(std::move(describeStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeStatusRequest.m_pData;
        describeStatusRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeStatusRequest* operator->() const
    {
        return this;
    }

    DescribeStatusRequest* operator->()
    {
        return this;
    }

    /**
     * ゲームの名前を取得
     *
     * @return ゲームの名前
     */
    const optional<StringHolder>& getGameName() const
    {
        return ensureData().gameName;
    }

    /**
     * ゲームの名前を設定
     *
     * @param gameName ゲームの名前
     */
    void setGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
    }

    /**
     * ゲームの名前を設定
     *
     * @param gameName ゲームの名前
     */
    DescribeStatusRequest& withGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
        return *this;
    }

    /**
     * データの取得を開始する位置を指定するトークンを取得
     *
     * @return データの取得を開始する位置を指定するトークン
     */
    const optional<StringHolder>& getPageToken() const
    {
        return ensureData().pageToken;
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    void setPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    DescribeStatusRequest& withPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
        return *this;
    }

    /**
     * データの取得件数を取得
     *
     * @return データの取得件数
     */
    const optional<Int32>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    void setLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    DescribeStatusRequest& withLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeStatusRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INGAMEPUSHNOTIFICATION_CONTROL_DESCRIBESTATUSREQUEST_HPP_