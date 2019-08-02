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
#include <gs2/core/external/optional/optional.hpp>
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            token(data.token)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            token(std::move(data.token))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "token") == 0) {
                if (jsonValue.IsString())
                {
                    this->token.emplace(jsonValue.GetString());
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
    ProjectToken() :
        m_pData(nullptr)
    {}

    ProjectToken(const ProjectToken& projectToken) :
        Gs2Object(projectToken),
        m_pData(projectToken.m_pData != nullptr ? new Data(*projectToken.m_pData) : nullptr)
    {}

    ProjectToken(ProjectToken&& projectToken) :
        Gs2Object(std::move(projectToken)),
        m_pData(projectToken.m_pData)
    {
        projectToken.m_pData = nullptr;
    }

    ~ProjectToken()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ProjectToken& operator=(const ProjectToken& projectToken)
    {
        Gs2Object::operator=(projectToken);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*projectToken.m_pData);

        return *this;
    }

    ProjectToken& operator=(ProjectToken&& projectToken)
    {
        Gs2Object::operator=(std::move(projectToken));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = projectToken.m_pData;
        projectToken.m_pData = nullptr;

        return *this;
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
    void setToken(const Char* token)
    {
        ensureData().token.emplace(token);
    }

    /**
     * プロジェクトトークンを設定
     *
     * @param token プロジェクトトークン
     */
    ProjectToken& withToken(const Char* token)
    {
        setToken(token);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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