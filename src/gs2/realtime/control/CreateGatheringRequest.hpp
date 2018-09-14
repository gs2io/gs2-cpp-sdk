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

#ifndef GS2_REALTIME_CONTROL_CREATEGATHERINGREQUEST_HPP_
#define GS2_REALTIME_CONTROL_CREATEGATHERINGREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2RealtimeConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace realtime
{

/**
 * @author Game Server Services, Inc.
 */
class CreateGatheringRequest : public Gs2BasicRequest, public Gs2Realtime
{
public:
    constexpr static const Char* const FUNCTION = "CreateGathering";

private:
    class Data : public Gs2Object
    {
    public:
        /** ギャザリングプールの名前を指定します。 */
        optional<StringHolder> gatheringPoolName;
        /** ギャザリング名 */
        optional<StringHolder> name;
        /** カンマ区切りのギャザリングへの参加を許可するユーザIDリスト */
        optional<StringHolder> userIds;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gatheringPoolName(data.gatheringPoolName),
            name(data.name),
            userIds(data.userIds)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gatheringPoolName(std::move(data.gatheringPoolName)),
            name(std::move(data.name)),
            userIds(std::move(data.userIds))
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
    CreateGatheringRequest() :
        m_pData(nullptr)
    {}

    CreateGatheringRequest(const CreateGatheringRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Realtime(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGatheringRequest(CreateGatheringRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Realtime(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGatheringRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGatheringRequest& operator=(const CreateGatheringRequest& createGatheringRequest)
    {
        Gs2BasicRequest::operator=(createGatheringRequest);
        Gs2Realtime::operator=(createGatheringRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGatheringRequest.m_pData);

        return *this;
    }

    CreateGatheringRequest& operator=(CreateGatheringRequest&& createGatheringRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGatheringRequest));
        Gs2Realtime::operator=(std::move(createGatheringRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGatheringRequest.m_pData;
        createGatheringRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGatheringRequest* operator->() const
    {
        return this;
    }

    CreateGatheringRequest* operator->()
    {
        return this;
    }

    /**
     * ギャザリングプールの名前を指定します。を取得
     *
     * @return ギャザリングプールの名前を指定します。
     */
    const optional<StringHolder>& getGatheringPoolName() const
    {
        return ensureData().gatheringPoolName;
    }

    /**
     * ギャザリングプールの名前を指定します。を設定
     *
     * @param gatheringPoolName ギャザリングプールの名前を指定します。
     */
    void setGatheringPoolName(const Char* gatheringPoolName)
    {
        ensureData().gatheringPoolName.emplace(gatheringPoolName);
    }

    /**
     * ギャザリングプールの名前を指定します。を設定
     *
     * @param gatheringPoolName ギャザリングプールの名前を指定します。
     */
    CreateGatheringRequest& withGatheringPoolName(const Char* gatheringPoolName)
    {
        ensureData().gatheringPoolName.emplace(gatheringPoolName);
        return *this;
    }

    /**
     * ギャザリング名を取得
     *
     * @return ギャザリング名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ギャザリング名を設定
     *
     * @param name ギャザリング名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ギャザリング名を設定
     *
     * @param name ギャザリング名
     */
    CreateGatheringRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * カンマ区切りのギャザリングへの参加を許可するユーザIDリストを取得
     *
     * @return カンマ区切りのギャザリングへの参加を許可するユーザIDリスト
     */
    const optional<StringHolder>& getUserIds() const
    {
        return ensureData().userIds;
    }

    /**
     * カンマ区切りのギャザリングへの参加を許可するユーザIDリストを設定
     *
     * @param userIds カンマ区切りのギャザリングへの参加を許可するユーザIDリスト
     */
    void setUserIds(const Char* userIds)
    {
        ensureData().userIds.emplace(userIds);
    }

    /**
     * カンマ区切りのギャザリングへの参加を許可するユーザIDリストを設定
     *
     * @param userIds カンマ区切りのギャザリングへの参加を許可するユーザIDリスト
     */
    CreateGatheringRequest& withUserIds(const Char* userIds)
    {
        ensureData().userIds.emplace(userIds);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateGatheringRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGatheringRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGatheringRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGatheringRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_REALTIME_CONTROL_CREATEGATHERINGREQUEST_HPP_