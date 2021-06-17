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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZSIGNEDBALLOT_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZSIGNEDBALLOT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace matchmaking {

class SignedBallot;

}

namespace ez { namespace matchmaking {

class EzSignedBallot : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 投票用紙の署名対象のデータ */
        gs2::optional<StringHolder> body;
        /** 投票用紙の署名 */
        gs2::optional<StringHolder> signature;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::SignedBallot& signedBallot);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzSignedBallot() = default;
    EzSignedBallot(const EzSignedBallot& ezSignedBallot) = default;
    EzSignedBallot(EzSignedBallot&& ezSignedBallot) = default;
    ~EzSignedBallot() = default;

    EzSignedBallot(gs2::matchmaking::SignedBallot signedBallot);

    EzSignedBallot& operator=(const EzSignedBallot& ezSignedBallot) = default;
    EzSignedBallot& operator=(EzSignedBallot&& ezSignedBallot) = default;

    EzSignedBallot deepCopy() const;

    gs2::matchmaking::SignedBallot ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getBody() const
    {
        return *ensureData().body;
    }

    const StringHolder& getSignature() const
    {
        return *ensureData().signature;
    }

    // ========================================
    //   Setters
    // ========================================

    void setBody(StringHolder body)
    {
        ensureData().body = std::move(body);
    }

    void setSignature(StringHolder signature)
    {
        ensureData().signature = std::move(signature);
    }

    EzSignedBallot& withBody(StringHolder body)
    {
        setBody(std::move(body));
        return *this;
    }

    EzSignedBallot& withSignature(StringHolder signature)
    {
        setSignature(std::move(signature));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZSIGNEDBALLOT_HPP_