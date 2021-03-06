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

#ifndef GS2_IDENTIFIER_MODEL_ATTACHSECURITYPOLICY_HPP_
#define GS2_IDENTIFIER_MODEL_ATTACHSECURITYPOLICY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace identifier {

/**
 * 割り当てられたセキュリティポリシー
 *
 * @author Game Server Services, Inc.
 *
 */
class AttachSecurityPolicy : public Gs2Object
{
    friend bool operator!=(const AttachSecurityPolicy& lhs, const AttachSecurityPolicy& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザ のGRN */
        optional<StringHolder> userId;
        /** セキュリティポリシー のGRNのリスト */
        optional<List<StringHolder>> securityPolicyIds;
        /** 作成日時 */
        optional<Int64> attachedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            attachedAt(data.attachedAt)
        {
            if (data.securityPolicyIds)
            {
                securityPolicyIds = data.securityPolicyIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "securityPolicyIds") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->securityPolicyIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->securityPolicyIds += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "attachedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->attachedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AttachSecurityPolicy() = default;
    AttachSecurityPolicy(const AttachSecurityPolicy& attachSecurityPolicy) = default;
    AttachSecurityPolicy(AttachSecurityPolicy&& attachSecurityPolicy) = default;
    ~AttachSecurityPolicy() = default;

    AttachSecurityPolicy& operator=(const AttachSecurityPolicy& attachSecurityPolicy) = default;
    AttachSecurityPolicy& operator=(AttachSecurityPolicy&& attachSecurityPolicy) = default;

    AttachSecurityPolicy deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AttachSecurityPolicy);
    }

    const AttachSecurityPolicy* operator->() const
    {
        return this;
    }

    AttachSecurityPolicy* operator->()
    {
        return this;
    }
    /**
     * ユーザ のGRNを取得
     *
     * @return ユーザ のGRN
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザ のGRNを設定
     *
     * @param userId ユーザ のGRN
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザ のGRNを設定
     *
     * @param userId ユーザ のGRN
     */
    AttachSecurityPolicy& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * セキュリティポリシー のGRNのリストを取得
     *
     * @return セキュリティポリシー のGRNのリスト
     */
    const optional<List<StringHolder>>& getSecurityPolicyIds() const
    {
        return ensureData().securityPolicyIds;
    }

    /**
     * セキュリティポリシー のGRNのリストを設定
     *
     * @param securityPolicyIds セキュリティポリシー のGRNのリスト
     */
    void setSecurityPolicyIds(List<StringHolder> securityPolicyIds)
    {
        ensureData().securityPolicyIds.emplace(std::move(securityPolicyIds));
    }

    /**
     * セキュリティポリシー のGRNのリストを設定
     *
     * @param securityPolicyIds セキュリティポリシー のGRNのリスト
     */
    AttachSecurityPolicy& withSecurityPolicyIds(List<StringHolder> securityPolicyIds)
    {
        setSecurityPolicyIds(std::move(securityPolicyIds));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getAttachedAt() const
    {
        return ensureData().attachedAt;
    }

    /**
     * 作成日時を設定
     *
     * @param attachedAt 作成日時
     */
    void setAttachedAt(Int64 attachedAt)
    {
        ensureData().attachedAt.emplace(attachedAt);
    }

    /**
     * 作成日時を設定
     *
     * @param attachedAt 作成日時
     */
    AttachSecurityPolicy& withAttachedAt(Int64 attachedAt)
    {
        setAttachedAt(attachedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const AttachSecurityPolicy& lhs, const AttachSecurityPolicy& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->securityPolicyIds != lhr.m_pData->securityPolicyIds)
        {
            return true;
        }
        if (lhs.m_pData->attachedAt != lhr.m_pData->attachedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const AttachSecurityPolicy& lhs, const AttachSecurityPolicy& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_IDENTIFIER_MODEL_ATTACHSECURITYPOLICY_HPP_