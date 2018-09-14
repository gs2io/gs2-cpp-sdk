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

#ifndef GS2_ACCOUNT_MODEL_TAKEOVER_HPP_
#define GS2_ACCOUNT_MODEL_TAKEOVER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace account {

/**
 * 引き継ぎ情報
 *
 * @author Game Server Services, Inc.
 *
 */
class TakeOver : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザID */
        optional<StringHolder> userId;
        /** アカウント種別 */
        optional<Int32> type;
        /** ユーザ識別子 */
        optional<StringHolder> userIdentifier;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            type(data.type),
            userIdentifier(data.userIdentifier),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            type(std::move(data.type)),
            userIdentifier(std::move(data.userIdentifier)),
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
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsInt())
                {
                    this->type = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "userIdentifier") == 0) {
                if (jsonValue.IsString())
                {
                    this->userIdentifier.emplace(jsonValue.GetString());
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
    TakeOver() :
        m_pData(nullptr)
    {}

    TakeOver(const TakeOver& takeOver) :
        Gs2Object(takeOver),
        m_pData(takeOver.m_pData != nullptr ? new Data(*takeOver.m_pData) : nullptr)
    {}

    TakeOver(TakeOver&& takeOver) :
        Gs2Object(std::move(takeOver)),
        m_pData(takeOver.m_pData)
    {
        takeOver.m_pData = nullptr;
    }

    ~TakeOver()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    TakeOver& operator=(const TakeOver& takeOver)
    {
        Gs2Object::operator=(takeOver);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*takeOver.m_pData);

        return *this;
    }

    TakeOver& operator=(TakeOver&& takeOver)
    {
        Gs2Object::operator=(std::move(takeOver));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = takeOver.m_pData;
        takeOver.m_pData = nullptr;

        return *this;
    }

    const TakeOver* operator->() const
    {
        return this;
    }

    TakeOver* operator->()
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
     * アカウント種別を取得
     *
     * @return アカウント種別
     */
    const optional<Int32>& getType() const
    {
        return ensureData().type;
    }

    /**
     * アカウント種別を設定
     *
     * @param type アカウント種別
     */
    void setType(Int32 type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * ユーザ識別子を取得
     *
     * @return ユーザ識別子
     */
    const optional<StringHolder>& getUserIdentifier() const
    {
        return ensureData().userIdentifier;
    }

    /**
     * ユーザ識別子を設定
     *
     * @param userIdentifier ユーザ識別子
     */
    void setUserIdentifier(const Char* userIdentifier)
    {
        ensureData().userIdentifier.emplace(userIdentifier);
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_ACCOUNT_MODEL_TAKEOVER_HPP_