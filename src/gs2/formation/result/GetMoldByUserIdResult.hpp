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

#ifndef GS2_FORMATION_CONTROL_GETMOLDBYUSERIDRESULT_HPP_
#define GS2_FORMATION_CONTROL_GETMOLDBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * ユーザIDを指定して保存したフォームを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMoldByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 保存したフォーム */
        optional<Mold> item;
        /** フォームの保存領域 */
        optional<MoldModel> moldModel;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
            if (data.moldModel)
            {
                moldModel = data.moldModel->deepCopy();
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
            else if (std::strcmp(name_, "moldModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->moldModel.emplace();
                    detail::json::JsonParser::parse(&this->moldModel->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetMoldByUserIdResult() = default;
    GetMoldByUserIdResult(const GetMoldByUserIdResult& getMoldByUserIdResult) = default;
    GetMoldByUserIdResult(GetMoldByUserIdResult&& getMoldByUserIdResult) = default;
    ~GetMoldByUserIdResult() = default;

    GetMoldByUserIdResult& operator=(const GetMoldByUserIdResult& getMoldByUserIdResult) = default;
    GetMoldByUserIdResult& operator=(GetMoldByUserIdResult&& getMoldByUserIdResult) = default;

    GetMoldByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetMoldByUserIdResult);
    }

    const GetMoldByUserIdResult* operator->() const
    {
        return this;
    }

    GetMoldByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 保存したフォームを取得
     *
     * @return 保存したフォーム
     */
    const optional<Mold>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 保存したフォームを設定
     *
     * @param item 保存したフォーム
     */
    void setItem(Mold item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * フォームの保存領域を取得
     *
     * @return フォームの保存領域
     */
    const optional<MoldModel>& getMoldModel() const
    {
        return ensureData().moldModel;
    }

    /**
     * フォームの保存領域を設定
     *
     * @param moldModel フォームの保存領域
     */
    void setMoldModel(MoldModel moldModel)
    {
        ensureData().moldModel.emplace(std::move(moldModel));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetMoldByUserIdResult> AsyncGetMoldByUserIdResult;

} }

#endif //GS2_FORMATION_CONTROL_GETMOLDBYUSERIDRESULT_HPP_