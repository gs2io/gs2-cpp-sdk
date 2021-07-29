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

#ifndef GS2_EZ_ACCOUNT_MODEL_EZTAKEOVER_HPP_
#define GS2_EZ_ACCOUNT_MODEL_EZTAKEOVER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace account {

class TakeOver;

}

namespace ez { namespace account {

class EzTakeOver : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        StringHolder userId;
        /** スロット番号 */
        Int32 type;
        /** 引き継ぎ用ユーザーID */
        StringHolder userIdentifier;
        /** 作成日時 */
        Int64 createdAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::account::TakeOver& takeOver);
        Data(const gs2::optional<gs2::account::TakeOver>& takeOver);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzTakeOver() = default;
    EzTakeOver(const EzTakeOver& ezTakeOver) = default;
    EzTakeOver(EzTakeOver&& ezTakeOver) = default;
    ~EzTakeOver() = default;

    EzTakeOver(gs2::account::TakeOver takeOver);
    EzTakeOver(gs2::optional<gs2::account::TakeOver> takeOver);

    EzTakeOver& operator=(const EzTakeOver& ezTakeOver) = default;
    EzTakeOver& operator=(EzTakeOver&& ezTakeOver) = default;

    EzTakeOver deepCopy() const;

    gs2::account::TakeOver ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return ensureData().userId;
    }

    Int32 getType() const
    {
        return ensureData().type;
    }

    const StringHolder& getUserIdentifier() const
    {
        return ensureData().userIdentifier;
    }

    Int64 getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setType(Int32 type)
    {
        ensureData().type = type;
    }

    void setUserIdentifier(StringHolder userIdentifier)
    {
        ensureData().userIdentifier = std::move(userIdentifier);
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    EzTakeOver& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzTakeOver& withType(Int32 type)
    {
        setType(type);
        return *this;
    }

    EzTakeOver& withUserIdentifier(StringHolder userIdentifier)
    {
        setUserIdentifier(std::move(userIdentifier));
        return *this;
    }

    EzTakeOver& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_ACCOUNT_EZTAKEOVER_HPP_