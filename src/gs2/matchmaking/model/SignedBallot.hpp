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

#ifndef GS2_MATCHMAKING_MODEL_SIGNEDBALLOT_HPP_
#define GS2_MATCHMAKING_MODEL_SIGNEDBALLOT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * 署名済みの投票用紙
 *
 * @author Game Server Services, Inc.
 *
 */
class SignedBallot : public Gs2Object
{
    friend bool operator!=(const SignedBallot& lhs, const SignedBallot& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 投票用紙の署名対象のデータ */
        optional<StringHolder> body;
        /** 投票用紙の署名 */
        optional<StringHolder> signature;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            body(data.body),
            signature(data.signature)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "body") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    SignedBallot() = default;
    SignedBallot(const SignedBallot& signedBallot) = default;
    SignedBallot(SignedBallot&& signedBallot) = default;
    ~SignedBallot() = default;

    SignedBallot& operator=(const SignedBallot& signedBallot) = default;
    SignedBallot& operator=(SignedBallot&& signedBallot) = default;

    SignedBallot deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SignedBallot);
    }

    const SignedBallot* operator->() const
    {
        return this;
    }

    SignedBallot* operator->()
    {
        return this;
    }
    /**
     * 投票用紙の署名対象のデータを取得
     *
     * @return 投票用紙の署名対象のデータ
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 投票用紙の署名対象のデータを設定
     *
     * @param body 投票用紙の署名対象のデータ
     */
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
    }

    /**
     * 投票用紙の署名対象のデータを設定
     *
     * @param body 投票用紙の署名対象のデータ
     */
    SignedBallot& withBody(StringHolder body)
    {
        setBody(std::move(body));
        return *this;
    }

    /**
     * 投票用紙の署名を取得
     *
     * @return 投票用紙の署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 投票用紙の署名を設定
     *
     * @param signature 投票用紙の署名
     */
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }

    /**
     * 投票用紙の署名を設定
     *
     * @param signature 投票用紙の署名
     */
    SignedBallot& withSignature(StringHolder signature)
    {
        setSignature(std::move(signature));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SignedBallot& lhs, const SignedBallot& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->body != lhr.m_pData->body)
        {
            return true;
        }
        if (lhs.m_pData->signature != lhr.m_pData->signature)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const SignedBallot& lhs, const SignedBallot& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MATCHMAKING_MODEL_SIGNEDBALLOT_HPP_