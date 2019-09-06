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

#ifndef GS2_JOBQUEUE_MODEL_PUSHNOTIFICATION_HPP_
#define GS2_JOBQUEUE_MODEL_PUSHNOTIFICATION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

/**
 * 
 *
 * @author Game Server Services, Inc.
 *
 */
class PushNotification : public Gs2Object
{
    friend bool operator!=(const PushNotification& lhs, const PushNotification& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceName(data.namespaceName)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceName(std::move(data.namespaceName))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceName.emplace(jsonValue.GetString());
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
    PushNotification() :
        m_pData(nullptr)
    {}

    PushNotification(const PushNotification& pushNotification) :
        Gs2Object(pushNotification),
        m_pData(pushNotification.m_pData != nullptr ? new Data(*pushNotification.m_pData) : nullptr)
    {}

    PushNotification(PushNotification&& pushNotification) :
        Gs2Object(std::move(pushNotification)),
        m_pData(pushNotification.m_pData)
    {
        pushNotification.m_pData = nullptr;
    }

    ~PushNotification()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PushNotification& operator=(const PushNotification& pushNotification)
    {
        Gs2Object::operator=(pushNotification);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*pushNotification.m_pData);

        return *this;
    }

    PushNotification& operator=(PushNotification&& pushNotification)
    {
        Gs2Object::operator=(std::move(pushNotification));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = pushNotification.m_pData;
        pushNotification.m_pData = nullptr;

        return *this;
    }

    const PushNotification* operator->() const
    {
        return this;
    }

    PushNotification* operator->()
    {
        return this;
    }
    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    PushNotification& withNamespaceName(const Char* namespaceName)
    {
        setNamespaceName(namespaceName);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const PushNotification& lhs, const PushNotification& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const PushNotification& lhs, const PushNotification& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_PUSHNOTIFICATION_HPP_