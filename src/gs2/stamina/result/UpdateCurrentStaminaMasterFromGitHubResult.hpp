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

#ifndef GS2_STAMINA_CONTROL_UPDATECURRENTSTAMINAMASTERFROMGITHUBRESULT_HPP_
#define GS2_STAMINA_CONTROL_UPDATECURRENTSTAMINAMASTERFROMGITHUBRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * 現在有効な現在有効なスタミナマスターを更新します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentStaminaMasterFromGitHubResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した現在有効な現在有効なスタミナマスター */
        optional<CurrentStaminaMaster> item;

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
    UpdateCurrentStaminaMasterFromGitHubResult() :
        m_pData(nullptr)
    {}

    UpdateCurrentStaminaMasterFromGitHubResult(const UpdateCurrentStaminaMasterFromGitHubResult& updateCurrentStaminaMasterFromGitHubResult) :
        Gs2Object(updateCurrentStaminaMasterFromGitHubResult),
        m_pData(updateCurrentStaminaMasterFromGitHubResult.m_pData != nullptr ? new Data(*updateCurrentStaminaMasterFromGitHubResult.m_pData) : nullptr)
    {}

    UpdateCurrentStaminaMasterFromGitHubResult(UpdateCurrentStaminaMasterFromGitHubResult&& updateCurrentStaminaMasterFromGitHubResult) :
        Gs2Object(std::move(updateCurrentStaminaMasterFromGitHubResult)),
        m_pData(updateCurrentStaminaMasterFromGitHubResult.m_pData)
    {
        updateCurrentStaminaMasterFromGitHubResult.m_pData = nullptr;
    }

    ~UpdateCurrentStaminaMasterFromGitHubResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateCurrentStaminaMasterFromGitHubResult& operator=(const UpdateCurrentStaminaMasterFromGitHubResult& updateCurrentStaminaMasterFromGitHubResult)
    {
        Gs2Object::operator=(updateCurrentStaminaMasterFromGitHubResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateCurrentStaminaMasterFromGitHubResult.m_pData);

        return *this;
    }

    UpdateCurrentStaminaMasterFromGitHubResult& operator=(UpdateCurrentStaminaMasterFromGitHubResult&& updateCurrentStaminaMasterFromGitHubResult)
    {
        Gs2Object::operator=(std::move(updateCurrentStaminaMasterFromGitHubResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateCurrentStaminaMasterFromGitHubResult.m_pData;
        updateCurrentStaminaMasterFromGitHubResult.m_pData = nullptr;

        return *this;
    }

    const UpdateCurrentStaminaMasterFromGitHubResult* operator->() const
    {
        return this;
    }

    UpdateCurrentStaminaMasterFromGitHubResult* operator->()
    {
        return this;
    }
    /**
     * 更新した現在有効な現在有効なスタミナマスターを取得
     *
     * @return 更新した現在有効な現在有効なスタミナマスター
     */
    const optional<CurrentStaminaMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した現在有効な現在有効なスタミナマスターを設定
     *
     * @param item 更新した現在有効な現在有効なスタミナマスター
     */
    void setItem(const CurrentStaminaMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<UpdateCurrentStaminaMasterFromGitHubResult> AsyncUpdateCurrentStaminaMasterFromGitHubResult;

} }

#endif //GS2_STAMINA_CONTROL_UPDATECURRENTSTAMINAMASTERFROMGITHUBRESULT_HPP_