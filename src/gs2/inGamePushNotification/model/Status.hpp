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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MODEL_STATUS_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MODEL_STATUS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

/**
 * オンラインステータス
 *
 * @author Game Server Services, Inc.
 *
 */
class Status : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザID */
        optional<StringHolder> userId;
        /** ステータス */
        optional<StringHolder> status;
        /** Firebaseトークン */
        optional<StringHolder> fcmToken;
        /** 登録日時 */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            status(data.status),
            fcmToken(data.fcmToken),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            status(std::move(data.status)),
            fcmToken(std::move(data.fcmToken)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "status") == 0) {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "fcmToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->fcmToken.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
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
    Status() :
        m_pData(nullptr)
    {}

    Status(const Status& status) :
        Gs2Object(status),
        m_pData(status.m_pData != nullptr ? new Data(*status.m_pData) : nullptr)
    {}

    Status(Status&& status) :
        Gs2Object(std::move(status)),
        m_pData(status.m_pData)
    {
        status.m_pData = nullptr;
    }

    ~Status()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Status& operator=(const Status& status)
    {
        Gs2Object::operator=(status);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*status.m_pData);

        return *this;
    }

    Status& operator=(Status&& status)
    {
        Gs2Object::operator=(std::move(status));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = status.m_pData;
        status.m_pData = nullptr;

        return *this;
    }

    const Status* operator->() const
    {
        return this;
    }

    Status* operator->()
    {
        return this;
    }


    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ステータスを取得
     *
     * @return ステータス
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * ステータスを設定
     *
     * @param status ステータス
     */
    void setStatus(const Char* status)
    {
        ensureData().status.emplace(status);
    }

    /**
     * Firebaseトークンを取得
     *
     * @return Firebaseトークン
     */
    const optional<StringHolder>& getFcmToken() const
    {
        return ensureData().fcmToken;
    }

    /**
     * Firebaseトークンを設定
     *
     * @param fcmToken Firebaseトークン
     */
    void setFcmToken(const Char* fcmToken)
    {
        ensureData().fcmToken.emplace(fcmToken);
    }

    /**
     * 登録日時を取得
     *
     * @return 登録日時
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 登録日時を設定
     *
     * @param createAt 登録日時
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INGAMEPUSHNOTIFICATION_MODEL_STATUS_HPP_