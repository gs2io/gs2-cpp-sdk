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

#ifndef GS2_REALTIME_CONTROL_CREATEGATHERINGPOOLREQUEST_HPP_
#define GS2_REALTIME_CONTROL_CREATEGATHERINGPOOLREQUEST_HPP_

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
class CreateGatheringPoolRequest : public Gs2BasicRequest, public Gs2Realtime
{
public:
    constexpr static const Char* const FUNCTION = "CreateGatheringPool";

private:
    class Data : public Gs2Object
    {
    public:
        /** ギャザリングプールの名前 */
        optional<StringHolder> name;
        /** ギャザリングプールの説明 */
        optional<StringHolder> description;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description))
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
    CreateGatheringPoolRequest() :
        m_pData(nullptr)
    {}

    CreateGatheringPoolRequest(const CreateGatheringPoolRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Realtime(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGatheringPoolRequest(CreateGatheringPoolRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Realtime(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGatheringPoolRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGatheringPoolRequest& operator=(const CreateGatheringPoolRequest& createGatheringPoolRequest)
    {
        Gs2BasicRequest::operator=(createGatheringPoolRequest);
        Gs2Realtime::operator=(createGatheringPoolRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGatheringPoolRequest.m_pData);

        return *this;
    }

    CreateGatheringPoolRequest& operator=(CreateGatheringPoolRequest&& createGatheringPoolRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGatheringPoolRequest));
        Gs2Realtime::operator=(std::move(createGatheringPoolRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGatheringPoolRequest.m_pData;
        createGatheringPoolRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGatheringPoolRequest* operator->() const
    {
        return this;
    }

    CreateGatheringPoolRequest* operator->()
    {
        return this;
    }

    /**
     * ギャザリングプールの名前を取得
     *
     * @return ギャザリングプールの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ギャザリングプールの名前を設定
     *
     * @param name ギャザリングプールの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ギャザリングプールの名前を設定
     *
     * @param name ギャザリングプールの名前
     */
    CreateGatheringPoolRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * ギャザリングプールの説明を取得
     *
     * @return ギャザリングプールの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ギャザリングプールの説明を設定
     *
     * @param description ギャザリングプールの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ギャザリングプールの説明を設定
     *
     * @param description ギャザリングプールの説明
     */
    CreateGatheringPoolRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateGatheringPoolRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGatheringPoolRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGatheringPoolRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGatheringPoolRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_REALTIME_CONTROL_CREATEGATHERINGPOOLREQUEST_HPP_