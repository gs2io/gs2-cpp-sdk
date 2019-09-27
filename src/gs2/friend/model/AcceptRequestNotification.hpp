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

#ifndef GS2_FRIEND_MODEL_ACCEPTREQUESTNOTIFICATION_HPP_
#define GS2_FRIEND_MODEL_ACCEPTREQUESTNOTIFICATION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace friend_ {

/**
 * 
 *
 * @author Game Server Services, Inc.
 *
 */
class AcceptRequestNotification : public Gs2Object
{
    friend bool operator!=(const AcceptRequestNotification& lhs, const AcceptRequestNotification& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> targetUserId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceName(data.namespaceName),
            targetUserId(data.targetUserId)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

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
            else if (std::strcmp(name_, "targetUserId") == 0) {
                if (jsonValue.IsString())
                {
                    this->targetUserId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AcceptRequestNotification() = default;
    AcceptRequestNotification(const AcceptRequestNotification& acceptRequestNotification) = default;
    AcceptRequestNotification(AcceptRequestNotification&& acceptRequestNotification) = default;
    ~AcceptRequestNotification() = default;

    AcceptRequestNotification& operator=(const AcceptRequestNotification& acceptRequestNotification) = default;
    AcceptRequestNotification& operator=(AcceptRequestNotification&& acceptRequestNotification) = default;

    AcceptRequestNotification deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcceptRequestNotification);
    }

    const AcceptRequestNotification* operator->() const
    {
        return this;
    }

    AcceptRequestNotification* operator->()
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(
            std::move(namespaceName)
        );
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    AcceptRequestNotification& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(
            std::move(namespaceName)
        );
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getTargetUserId() const
    {
        return ensureData().targetUserId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param targetUserId ユーザーID
     */
    void setTargetUserId(StringHolder targetUserId)
    {
        ensureData().targetUserId.emplace(
            std::move(targetUserId)
        );
    }

    /**
     * ユーザーIDを設定
     *
     * @param targetUserId ユーザーID
     */
    AcceptRequestNotification& withTargetUserId(StringHolder targetUserId)
    {
        setTargetUserId(
            std::move(targetUserId)
        );
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const AcceptRequestNotification& lhs, const AcceptRequestNotification& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData || lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
        {
            return true;
        }
        if (lhs.m_pData->targetUserId != lhr.m_pData->targetUserId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const AcceptRequestNotification& lhs, const AcceptRequestNotification& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_ACCEPTREQUESTNOTIFICATION_HPP_