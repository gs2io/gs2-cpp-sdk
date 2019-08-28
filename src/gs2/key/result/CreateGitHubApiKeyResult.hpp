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

#ifndef GS2_KEY_CONTROL_CREATEGITHUBAPIKEYRESULT_HPP_
#define GS2_KEY_CONTROL_CREATEGITHUBAPIKEYRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace key
{

/**
 * GitHub のAPIキーを新規作成します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateGitHubApiKeyResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したGitHub のAPIキー */
        optional<GitHubApiKey> item;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
    CreateGitHubApiKeyResult() :
        m_pData(nullptr)
    {}

    CreateGitHubApiKeyResult(const CreateGitHubApiKeyResult& createGitHubApiKeyResult) :
        Gs2Object(createGitHubApiKeyResult),
        m_pData(createGitHubApiKeyResult.m_pData != nullptr ? new Data(*createGitHubApiKeyResult.m_pData) : nullptr)
    {}

    CreateGitHubApiKeyResult(CreateGitHubApiKeyResult&& createGitHubApiKeyResult) :
        Gs2Object(std::move(createGitHubApiKeyResult)),
        m_pData(createGitHubApiKeyResult.m_pData)
    {
        createGitHubApiKeyResult.m_pData = nullptr;
    }

    ~CreateGitHubApiKeyResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGitHubApiKeyResult& operator=(const CreateGitHubApiKeyResult& createGitHubApiKeyResult)
    {
        Gs2Object::operator=(createGitHubApiKeyResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGitHubApiKeyResult.m_pData);

        return *this;
    }

    CreateGitHubApiKeyResult& operator=(CreateGitHubApiKeyResult&& createGitHubApiKeyResult)
    {
        Gs2Object::operator=(std::move(createGitHubApiKeyResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGitHubApiKeyResult.m_pData;
        createGitHubApiKeyResult.m_pData = nullptr;

        return *this;
    }

    const CreateGitHubApiKeyResult* operator->() const
    {
        return this;
    }

    CreateGitHubApiKeyResult* operator->()
    {
        return this;
    }
    /**
     * 作成したGitHub のAPIキーを取得
     *
     * @return 作成したGitHub のAPIキー
     */
    const optional<GitHubApiKey>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したGitHub のAPIキーを設定
     *
     * @param item 作成したGitHub のAPIキー
     */
    void setItem(const GitHubApiKey& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CreateGitHubApiKeyResult> AsyncCreateGitHubApiKeyResult;

} }

#endif //GS2_KEY_CONTROL_CREATEGITHUBAPIKEYRESULT_HPP_