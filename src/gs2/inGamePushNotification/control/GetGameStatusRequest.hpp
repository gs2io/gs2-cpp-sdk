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

#ifndef GS2_INGAMEPUSHNOTIFICATION_CONTROL_GETGAMESTATUSREQUEST_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_CONTROL_GETGAMESTATUSREQUEST_HPP_

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
class GetGameStatusRequest : public Gs2BasicRequest, public Gs2InGamePushNotification
{
public:
    constexpr static const Char* const FUNCTION = "GetGameStatus";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲームの名前 */
        optional<StringHolder> gameName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName))
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
    GetGameStatusRequest() :
        m_pData(nullptr)
    {}

    GetGameStatusRequest(const GetGameStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2InGamePushNotification(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetGameStatusRequest(GetGameStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2InGamePushNotification(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetGameStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetGameStatusRequest& operator=(const GetGameStatusRequest& getGameStatusRequest)
    {
        Gs2BasicRequest::operator=(getGameStatusRequest);
        Gs2InGamePushNotification::operator=(getGameStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getGameStatusRequest.m_pData);

        return *this;
    }

    GetGameStatusRequest& operator=(GetGameStatusRequest&& getGameStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(getGameStatusRequest));
        Gs2InGamePushNotification::operator=(std::move(getGameStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getGameStatusRequest.m_pData;
        getGameStatusRequest.m_pData = nullptr;

        return *this;
    }

    const GetGameStatusRequest* operator->() const
    {
        return this;
    }

    GetGameStatusRequest* operator->()
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
    GetGameStatusRequest& withGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetGameStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetGameStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetGameStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetGameStatusRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INGAMEPUSHNOTIFICATION_CONTROL_GETGAMESTATUSREQUEST_HPP_