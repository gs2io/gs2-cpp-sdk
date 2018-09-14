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

#ifndef GS2_LEVEL_CONTROL_INCREASEEXPERIENCEBYUSERIDREQUEST_HPP_
#define GS2_LEVEL_CONTROL_INCREASEEXPERIENCEBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2LevelConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace level
{

/**
 * @author Game Server Services, Inc.
 */
class IncreaseExperienceByUserIdRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "IncreaseExperienceByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** ステータス */
        optional<StringHolder> userId;
        /** ステータスID */
        optional<StringHolder> statusId;
        /** 経験値の加算量 */
        optional<Int64> value;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            userId(data.userId),
            statusId(data.statusId),
            value(data.value)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            userId(std::move(data.userId)),
            statusId(std::move(data.statusId)),
            value(std::move(data.value))
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
    IncreaseExperienceByUserIdRequest() :
        m_pData(nullptr)
    {}

    IncreaseExperienceByUserIdRequest(const IncreaseExperienceByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    IncreaseExperienceByUserIdRequest(IncreaseExperienceByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~IncreaseExperienceByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    IncreaseExperienceByUserIdRequest& operator=(const IncreaseExperienceByUserIdRequest& increaseExperienceByUserIdRequest)
    {
        Gs2BasicRequest::operator=(increaseExperienceByUserIdRequest);
        Gs2Level::operator=(increaseExperienceByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*increaseExperienceByUserIdRequest.m_pData);

        return *this;
    }

    IncreaseExperienceByUserIdRequest& operator=(IncreaseExperienceByUserIdRequest&& increaseExperienceByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(increaseExperienceByUserIdRequest));
        Gs2Level::operator=(std::move(increaseExperienceByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = increaseExperienceByUserIdRequest.m_pData;
        increaseExperienceByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const IncreaseExperienceByUserIdRequest* operator->() const
    {
        return this;
    }

    IncreaseExperienceByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * リソースプールを取得
     *
     * @return リソースプール
     */
    const optional<StringHolder>& getResourcePoolName() const
    {
        return ensureData().resourcePoolName;
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    void setResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
    }

    /**
     * リソースプールを設定
     *
     * @param resourcePoolName リソースプール
     */
    IncreaseExperienceByUserIdRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
        return *this;
    }

    /**
     * ステータスを取得
     *
     * @return ステータス
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ステータスを設定
     *
     * @param userId ステータス
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ステータスを設定
     *
     * @param userId ステータス
     */
    IncreaseExperienceByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * ステータスIDを取得
     *
     * @return ステータスID
     */
    const optional<StringHolder>& getStatusId() const
    {
        return ensureData().statusId;
    }

    /**
     * ステータスIDを設定
     *
     * @param statusId ステータスID
     */
    void setStatusId(const Char* statusId)
    {
        ensureData().statusId.emplace(statusId);
    }

    /**
     * ステータスIDを設定
     *
     * @param statusId ステータスID
     */
    IncreaseExperienceByUserIdRequest& withStatusId(const Char* statusId)
    {
        ensureData().statusId.emplace(statusId);
        return *this;
    }

    /**
     * 経験値の加算量を取得
     *
     * @return 経験値の加算量
     */
    const optional<Int64>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 経験値の加算量を設定
     *
     * @param value 経験値の加算量
     */
    void setValue(Int64 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 経験値の加算量を設定
     *
     * @param value 経験値の加算量
     */
    IncreaseExperienceByUserIdRequest& withValue(Int64 value)
    {
        ensureData().value.emplace(value);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    IncreaseExperienceByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    IncreaseExperienceByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    IncreaseExperienceByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    IncreaseExperienceByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_INCREASEEXPERIENCEBYUSERIDREQUEST_HPP_