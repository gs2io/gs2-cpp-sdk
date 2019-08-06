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

#ifndef GS2_PROJECT_CONTROL_DELETEPROJECTRESULT_HPP_
#define GS2_PROJECT_CONTROL_DELETEPROJECTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace project
{

/**
 * プロジェクトを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteProjectResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除したプロジェクト */
        optional<Project> item;

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
    DeleteProjectResult() :
        m_pData(nullptr)
    {}

    DeleteProjectResult(const DeleteProjectResult& deleteProjectResult) :
        Gs2Object(deleteProjectResult),
        m_pData(deleteProjectResult.m_pData != nullptr ? new Data(*deleteProjectResult.m_pData) : nullptr)
    {}

    DeleteProjectResult(DeleteProjectResult&& deleteProjectResult) :
        Gs2Object(std::move(deleteProjectResult)),
        m_pData(deleteProjectResult.m_pData)
    {
        deleteProjectResult.m_pData = nullptr;
    }

    ~DeleteProjectResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteProjectResult& operator=(const DeleteProjectResult& deleteProjectResult)
    {
        Gs2Object::operator=(deleteProjectResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteProjectResult.m_pData);

        return *this;
    }

    DeleteProjectResult& operator=(DeleteProjectResult&& deleteProjectResult)
    {
        Gs2Object::operator=(std::move(deleteProjectResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteProjectResult.m_pData;
        deleteProjectResult.m_pData = nullptr;

        return *this;
    }

    const DeleteProjectResult* operator->() const
    {
        return this;
    }

    DeleteProjectResult* operator->()
    {
        return this;
    }
    /**
     * 削除したプロジェクトを取得
     *
     * @return 削除したプロジェクト
     */
    const optional<Project>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除したプロジェクトを設定
     *
     * @param item 削除したプロジェクト
     */
    void setItem(const Project& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_PROJECT_CONTROL_DELETEPROJECTRESULT_HPP_