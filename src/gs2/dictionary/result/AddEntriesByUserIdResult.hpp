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

#ifndef GS2_DICTIONARY_CONTROL_ADDENTRIESBYUSERIDRESULT_HPP_
#define GS2_DICTIONARY_CONTROL_ADDENTRIESBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/dictionary/model/model.hpp>
#include <memory>

namespace gs2 { namespace dictionary
{

/**
 * ユーザIDを指定してエントリーを入手済みとして登録 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class AddEntriesByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 登録した{model_name}のリスト */
        optional<List<Entry>> items;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Entry item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item_);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AddEntriesByUserIdResult() = default;
    AddEntriesByUserIdResult(const AddEntriesByUserIdResult& addEntriesByUserIdResult) = default;
    AddEntriesByUserIdResult(AddEntriesByUserIdResult&& addEntriesByUserIdResult) = default;
    ~AddEntriesByUserIdResult() = default;

    AddEntriesByUserIdResult& operator=(const AddEntriesByUserIdResult& addEntriesByUserIdResult) = default;
    AddEntriesByUserIdResult& operator=(AddEntriesByUserIdResult&& addEntriesByUserIdResult) = default;

    AddEntriesByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AddEntriesByUserIdResult);
    }

    const AddEntriesByUserIdResult* operator->() const
    {
        return this;
    }

    AddEntriesByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 登録した{model_name}のリストを取得
     *
     * @return 登録した{model_name}のリスト
     */
    const optional<List<Entry>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 登録した{model_name}のリストを設定
     *
     * @param items 登録した{model_name}のリスト
     */
    void setItems(List<Entry> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<AddEntriesByUserIdResult> AsyncAddEntriesByUserIdResult;

} }

#endif //GS2_DICTIONARY_CONTROL_ADDENTRIESBYUSERIDRESULT_HPP_