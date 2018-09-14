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

#ifndef GS2_IDENTIFIER_MODEL_SECURITYPOLICY_HPP_
#define GS2_IDENTIFIER_MODEL_SECURITYPOLICY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace identifier {

/**
 * セキュリティポリシー
 *
 * @author Game Server Services, Inc.
 *
 */
class SecurityPolicy : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** セキュリティポリシーID */
        optional<StringHolder> securityPolicyId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** セキュリティポリシー名 */
        optional<StringHolder> name;
        /** ポリシードキュメント */
        optional<StringHolder> policy;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            securityPolicyId(data.securityPolicyId),
            ownerId(data.ownerId),
            name(data.name),
            policy(data.policy),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            securityPolicyId(std::move(data.securityPolicyId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            policy(std::move(data.policy)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "securityPolicyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->securityPolicyId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "policy") == 0) {
                if (jsonValue.IsString())
                {
                    this->policy.emplace(jsonValue.GetString());
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
    SecurityPolicy() :
        m_pData(nullptr)
    {}

    SecurityPolicy(const SecurityPolicy& securityPolicy) :
        Gs2Object(securityPolicy),
        m_pData(securityPolicy.m_pData != nullptr ? new Data(*securityPolicy.m_pData) : nullptr)
    {}

    SecurityPolicy(SecurityPolicy&& securityPolicy) :
        Gs2Object(std::move(securityPolicy)),
        m_pData(securityPolicy.m_pData)
    {
        securityPolicy.m_pData = nullptr;
    }

    ~SecurityPolicy()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SecurityPolicy& operator=(const SecurityPolicy& securityPolicy)
    {
        Gs2Object::operator=(securityPolicy);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*securityPolicy.m_pData);

        return *this;
    }

    SecurityPolicy& operator=(SecurityPolicy&& securityPolicy)
    {
        Gs2Object::operator=(std::move(securityPolicy));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = securityPolicy.m_pData;
        securityPolicy.m_pData = nullptr;

        return *this;
    }

    const SecurityPolicy* operator->() const
    {
        return this;
    }

    SecurityPolicy* operator->()
    {
        return this;
    }


    /**
     * セキュリティポリシーIDを取得
     *
     * @return セキュリティポリシーID
     */
    const optional<StringHolder>& getSecurityPolicyId() const
    {
        return ensureData().securityPolicyId;
    }

    /**
     * セキュリティポリシーIDを設定
     *
     * @param securityPolicyId セキュリティポリシーID
     */
    void setSecurityPolicyId(const Char* securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(securityPolicyId);
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
     * セキュリティポリシー名を取得
     *
     * @return セキュリティポリシー名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * セキュリティポリシー名を設定
     *
     * @param name セキュリティポリシー名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ポリシードキュメントを取得
     *
     * @return ポリシードキュメント
     */
    const optional<StringHolder>& getPolicy() const
    {
        return ensureData().policy;
    }

    /**
     * ポリシードキュメントを設定
     *
     * @param policy ポリシードキュメント
     */
    void setPolicy(const Char* policy)
    {
        ensureData().policy.emplace(policy);
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

#endif //GS2_IDENTIFIER_MODEL_SECURITYPOLICY_HPP_