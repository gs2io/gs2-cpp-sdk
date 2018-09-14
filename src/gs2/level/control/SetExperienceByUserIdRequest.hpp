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

#ifndef GS2_LEVEL_CONTROL_SETEXPERIENCEBYUSERIDREQUEST_HPP_
#define GS2_LEVEL_CONTROL_SETEXPERIENCEBYUSERIDREQUEST_HPP_

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
class SetExperienceByUserIdRequest : public Gs2BasicRequest, public Gs2Level
{
public:
    constexpr static const Char* const FUNCTION = "SetExperienceByUserId";

private:
    class Data : public Gs2Object
    {
    public:
        /** リソースプール */
        optional<StringHolder> resourcePoolName;
        /** ステータスID */
        optional<StringHolder> statusId;
        /** ステータス */
        optional<StringHolder> userId;
        /** 新しい累計獲得経験値 */
        optional<Int64> experience;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            resourcePoolName(data.resourcePoolName),
            statusId(data.statusId),
            userId(data.userId),
            experience(data.experience)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            resourcePoolName(std::move(data.resourcePoolName)),
            statusId(std::move(data.statusId)),
            userId(std::move(data.userId)),
            experience(std::move(data.experience))
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
    SetExperienceByUserIdRequest() :
        m_pData(nullptr)
    {}

    SetExperienceByUserIdRequest(const SetExperienceByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Level(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SetExperienceByUserIdRequest(SetExperienceByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Level(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SetExperienceByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SetExperienceByUserIdRequest& operator=(const SetExperienceByUserIdRequest& setExperienceByUserIdRequest)
    {
        Gs2BasicRequest::operator=(setExperienceByUserIdRequest);
        Gs2Level::operator=(setExperienceByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*setExperienceByUserIdRequest.m_pData);

        return *this;
    }

    SetExperienceByUserIdRequest& operator=(SetExperienceByUserIdRequest&& setExperienceByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(setExperienceByUserIdRequest));
        Gs2Level::operator=(std::move(setExperienceByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = setExperienceByUserIdRequest.m_pData;
        setExperienceByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const SetExperienceByUserIdRequest* operator->() const
    {
        return this;
    }

    SetExperienceByUserIdRequest* operator->()
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
    SetExperienceByUserIdRequest& withResourcePoolName(const Char* resourcePoolName)
    {
        ensureData().resourcePoolName.emplace(resourcePoolName);
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
    SetExperienceByUserIdRequest& withStatusId(const Char* statusId)
    {
        ensureData().statusId.emplace(statusId);
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
    SetExperienceByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 新しい累計獲得経験値を取得
     *
     * @return 新しい累計獲得経験値
     */
    const optional<Int64>& getExperience() const
    {
        return ensureData().experience;
    }

    /**
     * 新しい累計獲得経験値を設定
     *
     * @param experience 新しい累計獲得経験値
     */
    void setExperience(Int64 experience)
    {
        ensureData().experience.emplace(experience);
    }

    /**
     * 新しい累計獲得経験値を設定
     *
     * @param experience 新しい累計獲得経験値
     */
    SetExperienceByUserIdRequest& withExperience(Int64 experience)
    {
        ensureData().experience.emplace(experience);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SetExperienceByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SetExperienceByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SetExperienceByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetExperienceByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_LEVEL_CONTROL_SETEXPERIENCEBYUSERIDREQUEST_HPP_