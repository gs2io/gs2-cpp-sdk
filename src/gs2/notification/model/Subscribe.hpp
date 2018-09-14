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

#ifndef GS2_NOTIFICATION_MODEL_SUBSCRIBE_HPP_
#define GS2_NOTIFICATION_MODEL_SUBSCRIBE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace notification {

/**
 * 購読
 *
 * @author Game Server Services, Inc.
 *
 */
class Subscribe : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 購読GRN */
        optional<StringHolder> subscribeId;
        /** 通知GRN */
        optional<StringHolder> notificationId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 通知方法 */
        optional<StringHolder> type;
        /** type = email: メールアドレス */
        optional<StringHolder> endpoint;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            subscribeId(data.subscribeId),
            notificationId(data.notificationId),
            ownerId(data.ownerId),
            type(data.type),
            endpoint(data.endpoint),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            subscribeId(std::move(data.subscribeId)),
            notificationId(std::move(data.notificationId)),
            ownerId(std::move(data.ownerId)),
            type(std::move(data.type)),
            endpoint(std::move(data.endpoint)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "subscribeId") == 0) {
                if (jsonValue.IsString())
                {
                    this->subscribeId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationId") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "endpoint") == 0) {
                if (jsonValue.IsString())
                {
                    this->endpoint.emplace(jsonValue.GetString());
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
    Subscribe() :
        m_pData(nullptr)
    {}

    Subscribe(const Subscribe& subscribe) :
        Gs2Object(subscribe),
        m_pData(subscribe.m_pData != nullptr ? new Data(*subscribe.m_pData) : nullptr)
    {}

    Subscribe(Subscribe&& subscribe) :
        Gs2Object(std::move(subscribe)),
        m_pData(subscribe.m_pData)
    {
        subscribe.m_pData = nullptr;
    }

    ~Subscribe()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Subscribe& operator=(const Subscribe& subscribe)
    {
        Gs2Object::operator=(subscribe);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*subscribe.m_pData);

        return *this;
    }

    Subscribe& operator=(Subscribe&& subscribe)
    {
        Gs2Object::operator=(std::move(subscribe));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = subscribe.m_pData;
        subscribe.m_pData = nullptr;

        return *this;
    }

    const Subscribe* operator->() const
    {
        return this;
    }

    Subscribe* operator->()
    {
        return this;
    }


    /**
     * 購読GRNを取得
     *
     * @return 購読GRN
     */
    const optional<StringHolder>& getSubscribeId() const
    {
        return ensureData().subscribeId;
    }

    /**
     * 購読GRNを設定
     *
     * @param subscribeId 購読GRN
     */
    void setSubscribeId(const Char* subscribeId)
    {
        ensureData().subscribeId.emplace(subscribeId);
    }

    /**
     * 通知GRNを取得
     *
     * @return 通知GRN
     */
    const optional<StringHolder>& getNotificationId() const
    {
        return ensureData().notificationId;
    }

    /**
     * 通知GRNを設定
     *
     * @param notificationId 通知GRN
     */
    void setNotificationId(const Char* notificationId)
    {
        ensureData().notificationId.emplace(notificationId);
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
     * 通知方法を取得
     *
     * @return 通知方法
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 通知方法を設定
     *
     * @param type 通知方法
     */
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * type = email: メールアドレスを取得
     *
     * @return type = email: メールアドレス
     */
    const optional<StringHolder>& getEndpoint() const
    {
        return ensureData().endpoint;
    }

    /**
     * type = email: メールアドレスを設定
     *
     * @param endpoint type = email: メールアドレス
     */
    void setEndpoint(const Char* endpoint)
    {
        ensureData().endpoint.emplace(endpoint);
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

#endif //GS2_NOTIFICATION_MODEL_SUBSCRIBE_HPP_