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

#ifndef GS2_IDENTIFIER_MODEL_SECURITYPOLICY_HPP_
#define GS2_IDENTIFIER_MODEL_SECURITYPOLICY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace identifier {

/**
 * セキュリティポリシー
 *
 * @author Game Server Services, Inc.
 *
 */
class SecurityPolicy : public Gs2Object
{
    friend bool operator!=(const SecurityPolicy& lhs, const SecurityPolicy& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** セキュリティポリシー */
        optional<StringHolder> securityPolicyId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** セキュリティポリシー名 */
        optional<StringHolder> name;
        /** セキュリティポリシーの説明 */
        optional<StringHolder> description;
        /** ポリシードキュメント */
        optional<StringHolder> policy;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SecurityPolicy() = default;
    SecurityPolicy(const SecurityPolicy& securityPolicy) = default;
    SecurityPolicy(SecurityPolicy&& securityPolicy) = default;
    ~SecurityPolicy() = default;

    SecurityPolicy& operator=(const SecurityPolicy& securityPolicy) = default;
    SecurityPolicy& operator=(SecurityPolicy&& securityPolicy) = default;

    SecurityPolicy deepCopy() const;

    const SecurityPolicy* operator->() const
    {
        return this;
    }

    SecurityPolicy* operator->()
    {
        return this;
    }
    /**
     * セキュリティポリシーを取得
     *
     * @return セキュリティポリシー
     */
    const optional<StringHolder>& getSecurityPolicyId() const
    {
        return ensureData().securityPolicyId;
    }

    /**
     * セキュリティポリシーを設定
     *
     * @param securityPolicyId セキュリティポリシー
     */
    void setSecurityPolicyId(StringHolder securityPolicyId)
    {
        ensureData().securityPolicyId.emplace(std::move(securityPolicyId));
    }

    /**
     * セキュリティポリシーを設定
     *
     * @param securityPolicyId セキュリティポリシー
     */
    SecurityPolicy& withSecurityPolicyId(StringHolder securityPolicyId)
    {
        setSecurityPolicyId(std::move(securityPolicyId));
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
    SecurityPolicy& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * セキュリティポリシー名を設定
     *
     * @param name セキュリティポリシー名
     */
    SecurityPolicy& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * セキュリティポリシーの説明を取得
     *
     * @return セキュリティポリシーの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * セキュリティポリシーの説明を設定
     *
     * @param description セキュリティポリシーの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * セキュリティポリシーの説明を設定
     *
     * @param description セキュリティポリシーの説明
     */
    SecurityPolicy& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
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
    void setPolicy(StringHolder policy)
    {
        ensureData().policy.emplace(std::move(policy));
    }

    /**
     * ポリシードキュメントを設定
     *
     * @param policy ポリシードキュメント
     */
    SecurityPolicy& withPolicy(StringHolder policy)
    {
        setPolicy(std::move(policy));
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
    SecurityPolicy& withCreatedAt(Int64 createdAt)
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
    SecurityPolicy& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const SecurityPolicy& lhs, const SecurityPolicy& lhr);

inline bool operator==(const SecurityPolicy& lhs, const SecurityPolicy& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_IDENTIFIER_MODEL_SECURITYPOLICY_HPP_