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

#ifndef GS2_REALTIME_MODEL_GATHERING_HPP_
#define GS2_REALTIME_MODEL_GATHERING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace realtime {

/**
 * ギャザリング
 *
 * @author Game Server Services, Inc.
 *
 */
class Gathering : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ギャザリングID */
        optional<StringHolder> gatheringId;
        /** ギャザリングプールGRN */
        optional<StringHolder> gatheringPoolId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ギャザリング名 */
        optional<StringHolder> name;
        /** ホストIPアドレス */
        optional<StringHolder> ipAddress;
        /** ホストポート */
        optional<Int32> port;
        /** 暗号鍵 */
        optional<StringHolder> secret;
        /** 参加可能なユーザIDリスト */
        optional<List<StringHolder>> userIds;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gatheringId(data.gatheringId),
            gatheringPoolId(data.gatheringPoolId),
            ownerId(data.ownerId),
            name(data.name),
            ipAddress(data.ipAddress),
            port(data.port),
            secret(data.secret),
            userIds(data.userIds),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gatheringId(std::move(data.gatheringId)),
            gatheringPoolId(std::move(data.gatheringPoolId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            ipAddress(std::move(data.ipAddress)),
            port(std::move(data.port)),
            secret(std::move(data.secret)),
            userIds(std::move(data.userIds)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gatheringId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "gatheringPoolId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringPoolId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ipAddress") == 0) {
                if (jsonValue.IsString())
                {
                    this->ipAddress.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "port") == 0) {
                if (jsonValue.IsInt())
                {
                    this->port = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "secret") == 0) {
                if (jsonValue.IsString())
                {
                    this->secret.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userIds") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->userIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->userIds += std::move(stringHolder);
                    }
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
                }
            }
        }
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
    Gathering() :
        m_pData(nullptr)
    {}

    Gathering(const Gathering& gathering) :
        Gs2Object(gathering),
        m_pData(gathering.m_pData != nullptr ? new Data(*gathering.m_pData) : nullptr)
    {}

    Gathering(Gathering&& gathering) :
        Gs2Object(std::move(gathering)),
        m_pData(gathering.m_pData)
    {
        gathering.m_pData = nullptr;
    }

    ~Gathering()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Gathering& operator=(const Gathering& gathering)
    {
        Gs2Object::operator=(gathering);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gathering.m_pData);

        return *this;
    }

    Gathering& operator=(Gathering&& gathering)
    {
        Gs2Object::operator=(std::move(gathering));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gathering.m_pData;
        gathering.m_pData = nullptr;

        return *this;
    }

    const Gathering* operator->() const
    {
        return this;
    }

    Gathering* operator->()
    {
        return this;
    }


    /**
     * ギャザリングIDを取得
     *
     * @return ギャザリングID
     */
    const optional<StringHolder>& getGatheringId() const
    {
        return ensureData().gatheringId;
    }

    /**
     * ギャザリングIDを設定
     *
     * @param gatheringId ギャザリングID
     */
    void setGatheringId(const Char* gatheringId)
    {
        ensureData().gatheringId.emplace(gatheringId);
    }

    /**
     * ギャザリングプールGRNを取得
     *
     * @return ギャザリングプールGRN
     */
    const optional<StringHolder>& getGatheringPoolId() const
    {
        return ensureData().gatheringPoolId;
    }

    /**
     * ギャザリングプールGRNを設定
     *
     * @param gatheringPoolId ギャザリングプールGRN
     */
    void setGatheringPoolId(const Char* gatheringPoolId)
    {
        ensureData().gatheringPoolId.emplace(gatheringPoolId);
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
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
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
     * ホストIPアドレスを取得
     *
     * @return ホストIPアドレス
     */
    const optional<StringHolder>& getIpAddress() const
    {
        return ensureData().ipAddress;
    }

    /**
     * ホストIPアドレスを設定
     *
     * @param ipAddress ホストIPアドレス
     */
    void setIpAddress(const Char* ipAddress)
    {
        ensureData().ipAddress.emplace(ipAddress);
    }

    /**
     * ホストポートを取得
     *
     * @return ホストポート
     */
    const optional<Int32>& getPort() const
    {
        return ensureData().port;
    }

    /**
     * ホストポートを設定
     *
     * @param port ホストポート
     */
    void setPort(Int32 port)
    {
        ensureData().port.emplace(port);
    }

    /**
     * 暗号鍵を取得
     *
     * @return 暗号鍵
     */
    const optional<StringHolder>& getSecret() const
    {
        return ensureData().secret;
    }

    /**
     * 暗号鍵を設定
     *
     * @param secret 暗号鍵
     */
    void setSecret(const Char* secret)
    {
        ensureData().secret.emplace(secret);
    }

    /**
     * 参加可能なユーザIDリストを取得
     *
     * @return 参加可能なユーザIDリスト
     */
    const optional<List<StringHolder>>& getUserIds() const
    {
        return ensureData().userIds;
    }

    /**
     * 参加可能なユーザIDリストを設定
     *
     * @param userIds 参加可能なユーザIDリスト
     */
    void setUserIds(const List<StringHolder>& userIds)
    {
        ensureData().userIds.emplace(userIds);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_REALTIME_MODEL_GATHERING_HPP_