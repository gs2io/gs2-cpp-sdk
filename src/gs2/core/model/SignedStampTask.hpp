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

#ifndef GS2_CORE_MODEL_SIGNEDSTAMPTASK_HPP_
#define GS2_CORE_MODEL_SIGNEDSTAMPTASK_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 {

/**
 * 署名付きスタンプタスク
 *
 * @author Game Server Services, Inc.
 *
 */
class SignedStampTask : public Gs2Object
{
    friend bool operator!=(const SignedStampTask& lhs, const SignedStampTask& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタンプタスクの本体 */
        optional<StringHolder> body;
        /** 署名 */
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
    SignedStampTask() = default;
    SignedStampTask(const SignedStampTask& signedStampTask) = default;
    SignedStampTask(SignedStampTask&& signedStampTask) = default;
    ~SignedStampTask() = default;

    SignedStampTask& operator=(const SignedStampTask& signedStampTask) = default;
    SignedStampTask& operator=(SignedStampTask&& signedStampTask) = default;

    SignedStampTask deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SignedStampTask);
    }

    const SignedStampTask* operator->() const
    {
        return this;
    }

    SignedStampTask* operator->()
    {
        return this;
    }
    /**
     * スタンプタスクの本体を取得
     *
     * @return スタンプタスクの本体
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * スタンプタスクの本体を設定
     *
     * @param body スタンプタスクの本体
     */
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
    }

    /**
     * スタンプタスクの本体を設定
     *
     * @param body スタンプタスクの本体
     */
    SignedStampTask& withBody(StringHolder body)
    {
        setBody(std::move(body));
        return *this;
    }

    /**
     * 署名を取得
     *
     * @return 署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    SignedStampTask& withSignature(StringHolder signature)
    {
        setSignature(std::move(signature));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SignedStampTask& lhs, const SignedStampTask& lhr)
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

inline bool operator==(const SignedStampTask& lhs, const SignedStampTask& lhr)
{
    return !(lhs != lhr);
}

}

#endif //GS2_CORE_MODEL_SIGNEDSTAMPTASK_HPP_