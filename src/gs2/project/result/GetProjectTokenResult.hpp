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

#ifndef GS2_PROJECT_CONTROL_GETPROJECTTOKENRESULT_HPP_
#define GS2_PROJECT_CONTROL_GETPROJECTTOKENRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/project/model/model.hpp>
#include <memory>

namespace gs2 { namespace project
{

/**
 * プロジェクトトークンを発行します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetProjectTokenResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** サインインしたプロジェクト */
        optional<Project> item;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** プロジェクトトークン */
        optional<StringHolder> projectToken;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            ownerId(data.ownerId),
            projectToken(data.projectToken)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "projectToken") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->projectToken.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetProjectTokenResult() = default;
    GetProjectTokenResult(const GetProjectTokenResult& getProjectTokenResult) = default;
    GetProjectTokenResult(GetProjectTokenResult&& getProjectTokenResult) = default;
    ~GetProjectTokenResult() = default;

    GetProjectTokenResult& operator=(const GetProjectTokenResult& getProjectTokenResult) = default;
    GetProjectTokenResult& operator=(GetProjectTokenResult&& getProjectTokenResult) = default;

    GetProjectTokenResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetProjectTokenResult);
    }

    const GetProjectTokenResult* operator->() const
    {
        return this;
    }

    GetProjectTokenResult* operator->()
    {
        return this;
    }
    /**
     * サインインしたプロジェクトを取得
     *
     * @return サインインしたプロジェクト
     */
    const optional<Project>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * サインインしたプロジェクトを設定
     *
     * @param item サインインしたプロジェクト
     */
    void setItem(Project item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * プロジェクトトークンを取得
     *
     * @return プロジェクトトークン
     */
    const optional<StringHolder>& getProjectToken() const
    {
        return ensureData().projectToken;
    }

    /**
     * プロジェクトトークンを設定
     *
     * @param projectToken プロジェクトトークン
     */
    void setProjectToken(StringHolder projectToken)
    {
        ensureData().projectToken.emplace(std::move(projectToken));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetProjectTokenResult> AsyncGetProjectTokenResult;

} }

#endif //GS2_PROJECT_CONTROL_GETPROJECTTOKENRESULT_HPP_