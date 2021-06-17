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

#ifndef GS2_GATEWAY_MODEL_SESSION_HPP_
#define GS2_GATEWAY_MODEL_SESSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace gateway {

/**
 * WebSocketセッション
 *
 * @author Game Server Services, Inc.
 *
 */
class Session : public Gs2Object
{
    friend bool operator!=(const Session& lhs, const Session& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** WebSocketセッション のGRN */
        optional<StringHolder> sessionId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** WebSocketセッション名 */
        optional<StringHolder> sessionName;
        /** API Gateway の APIID */
        optional<StringHolder> apiId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            sessionId(data.sessionId),
            ownerId(data.ownerId),
            userId(data.userId),
            sessionName(data.sessionName),
            apiId(data.apiId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "sessionId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->sessionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "sessionName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->sessionName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "apiId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->apiId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Session() = default;
    Session(const Session& session) = default;
    Session(Session&& session) = default;
    ~Session() = default;

    Session& operator=(const Session& session) = default;
    Session& operator=(Session&& session) = default;

    Session deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Session);
    }

    const Session* operator->() const
    {
        return this;
    }

    Session* operator->()
    {
        return this;
    }
    /**
     * WebSocketセッション のGRNを取得
     *
     * @return WebSocketセッション のGRN
     */
    const optional<StringHolder>& getSessionId() const
    {
        return ensureData().sessionId;
    }

    /**
     * WebSocketセッション のGRNを設定
     *
     * @param sessionId WebSocketセッション のGRN
     */
    void setSessionId(StringHolder sessionId)
    {
        ensureData().sessionId.emplace(std::move(sessionId));
    }

    /**
     * WebSocketセッション のGRNを設定
     *
     * @param sessionId WebSocketセッション のGRN
     */
    Session& withSessionId(StringHolder sessionId)
    {
        setSessionId(std::move(sessionId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Session& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
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
    Session& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * WebSocketセッション名を取得
     *
     * @return WebSocketセッション名
     */
    const optional<StringHolder>& getSessionName() const
    {
        return ensureData().sessionName;
    }

    /**
     * WebSocketセッション名を設定
     *
     * @param sessionName WebSocketセッション名
     */
    void setSessionName(StringHolder sessionName)
    {
        ensureData().sessionName.emplace(std::move(sessionName));
    }

    /**
     * WebSocketセッション名を設定
     *
     * @param sessionName WebSocketセッション名
     */
    Session& withSessionName(StringHolder sessionName)
    {
        setSessionName(std::move(sessionName));
        return *this;
    }

    /**
     * API Gateway の APIIDを取得
     *
     * @return API Gateway の APIID
     */
    const optional<StringHolder>& getApiId() const
    {
        return ensureData().apiId;
    }

    /**
     * API Gateway の APIIDを設定
     *
     * @param apiId API Gateway の APIID
     */
    void setApiId(StringHolder apiId)
    {
        ensureData().apiId.emplace(std::move(apiId));
    }

    /**
     * API Gateway の APIIDを設定
     *
     * @param apiId API Gateway の APIID
     */
    Session& withApiId(StringHolder apiId)
    {
        setApiId(std::move(apiId));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Session& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Session& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Session& lhs, const Session& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->sessionId != lhr.m_pData->sessionId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->sessionName != lhr.m_pData->sessionName)
        {
            return true;
        }
        if (lhs.m_pData->apiId != lhr.m_pData->apiId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Session& lhs, const Session& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_GATEWAY_MODEL_SESSION_HPP_