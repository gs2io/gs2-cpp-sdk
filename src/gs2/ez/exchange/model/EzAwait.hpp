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

#ifndef GS2_EZ_EXCHANGE_MODEL_EZAWAIT_HPP_
#define GS2_EZ_EXCHANGE_MODEL_EZAWAIT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace exchange {

class Await;

}

namespace ez { namespace exchange {

class EzAwait : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 交換レート名 */
        gs2::optional<StringHolder> rateName;
        /** 交換待機の名前 */
        gs2::optional<StringHolder> name;
        /** 作成日時 */
        gs2::optional<Int64> exchangedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::exchange::Await& await_);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAwait() = default;
    EzAwait(const EzAwait& ezAwait) = default;
    EzAwait(EzAwait&& ezAwait) = default;
    ~EzAwait() = default;

    EzAwait(gs2::exchange::Await await_);

    EzAwait& operator=(const EzAwait& ezAwait) = default;
    EzAwait& operator=(EzAwait&& ezAwait) = default;

    EzAwait deepCopy() const;

    gs2::exchange::Await ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const StringHolder& getRateName() const
    {
        return *ensureData().rateName;
    }

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    Int64 getExchangedAt() const
    {
        return *ensureData().exchangedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setRateName(StringHolder rateName)
    {
        ensureData().rateName = std::move(rateName);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setExchangedAt(Int64 exchangedAt)
    {
        ensureData().exchangedAt = exchangedAt;
    }

    EzAwait& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzAwait& withRateName(StringHolder rateName)
    {
        setRateName(std::move(rateName));
        return *this;
    }

    EzAwait& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzAwait& withExchangedAt(Int64 exchangedAt)
    {
        setExchangedAt(exchangedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_EXCHANGE_EZAWAIT_HPP_