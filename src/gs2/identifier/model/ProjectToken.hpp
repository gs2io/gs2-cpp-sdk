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

#ifndef GS2_IDENTIFIER_MODEL_PROJECTTOKEN_HPP_
#define GS2_IDENTIFIER_MODEL_PROJECTTOKEN_HPP_

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
 * プロジェクトトークン
 *
 * @author Game Server Services, Inc.
 *
 */
class ProjectToken : public Gs2Object
{
    friend bool operator!=(const ProjectToken& lhs, const ProjectToken& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** プロジェクトトークン */
        optional<StringHolder> token;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            token(data.token)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "token") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->token.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ProjectToken() = default;
    ProjectToken(const ProjectToken& projectToken) = default;
    ProjectToken(ProjectToken&& projectToken) = default;
    ~ProjectToken() = default;

    ProjectToken& operator=(const ProjectToken& projectToken) = default;
    ProjectToken& operator=(ProjectToken&& projectToken) = default;

    ProjectToken deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ProjectToken);
    }

    const ProjectToken* operator->() const
    {
        return this;
    }

    ProjectToken* operator->()
    {
        return this;
    }
    /**
     * プロジェクトトークンを取得
     *
     * @return プロジェクトトークン
     */
    const optional<StringHolder>& getToken() const
    {
        return ensureData().token;
    }

    /**
     * プロジェクトトークンを設定
     *
     * @param token プロジェクトトークン
     */
    void setToken(StringHolder token)
    {
        ensureData().token.emplace(std::move(token));
    }

    /**
     * プロジェクトトークンを設定
     *
     * @param token プロジェクトトークン
     */
    ProjectToken& withToken(StringHolder token)
    {
        setToken(std::move(token));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ProjectToken& lhs, const ProjectToken& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->token != lhr.m_pData->token)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const ProjectToken& lhs, const ProjectToken& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_IDENTIFIER_MODEL_PROJECTTOKEN_HPP_