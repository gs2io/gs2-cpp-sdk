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

#ifndef GS2_REALTIME_CONTROL_DELETEGATHERINGPOOLREQUEST_HPP_
#define GS2_REALTIME_CONTROL_DELETEGATHERINGPOOLREQUEST_HPP_

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
class DeleteGatheringPoolRequest : public Gs2BasicRequest, public Gs2Realtime
{
public:
    constexpr static const Char* const FUNCTION = "DeleteGatheringPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** ギャザリングプールの名前を指定します。 */
        optional<StringHolder> gatheringPoolName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gatheringPoolName(data.gatheringPoolName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gatheringPoolName(std::move(data.gatheringPoolName))
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
    DeleteGatheringPoolRequest() :
        m_pData(nullptr)
    {}

    DeleteGatheringPoolRequest(const DeleteGatheringPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Realtime(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteGatheringPoolRequest(DeleteGatheringPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Realtime(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteGatheringPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteGatheringPoolRequest& operator=(const DeleteGatheringPoolRequest& deleteGatheringPoolRequest)
    {
        Gs2BasicRequest::operator=(deleteGatheringPoolRequest);
        Gs2Realtime::operator=(deleteGatheringPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteGatheringPoolRequest.m_pData);

        return *this;
    }

    DeleteGatheringPoolRequest& operator=(DeleteGatheringPoolRequest&& deleteGatheringPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteGatheringPoolRequest));
        Gs2Realtime::operator=(std::move(deleteGatheringPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteGatheringPoolRequest.m_pData;
        deleteGatheringPoolRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteGatheringPoolRequest* operator->() const
    {
        return this;
    }

    DeleteGatheringPoolRequest* operator->()
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
    DeleteGatheringPoolRequest& withGatheringPoolName(const Char* gatheringPoolName)
    {
        ensureData().gatheringPoolName.emplace(gatheringPoolName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteGatheringPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteGatheringPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteGatheringPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteGatheringPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_REALTIME_CONTROL_DELETEGATHERINGPOOLREQUEST_HPP_