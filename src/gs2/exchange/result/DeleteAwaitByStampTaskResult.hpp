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

#ifndef GS2_EXCHANGE_CONTROL_DELETEAWAITBYSTAMPTASKRESULT_HPP_
#define GS2_EXCHANGE_CONTROL_DELETEAWAITBYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/exchange/model/model.hpp>
#include <memory>

namespace gs2 { namespace exchange
{

/**
 * スタンプタスクで 交換待機 を削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteAwaitByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 交換待機 */
        optional<Await> item;
        /** スタンプタスクの実行結果を記録したコンテキスト */
        optional<StringHolder> newContextStack;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            newContextStack(data.newContextStack)
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
            else if (std::strcmp(name_, "newContextStack") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->newContextStack.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DeleteAwaitByStampTaskResult() = default;
    DeleteAwaitByStampTaskResult(const DeleteAwaitByStampTaskResult& deleteAwaitByStampTaskResult) = default;
    DeleteAwaitByStampTaskResult(DeleteAwaitByStampTaskResult&& deleteAwaitByStampTaskResult) = default;
    ~DeleteAwaitByStampTaskResult() = default;

    DeleteAwaitByStampTaskResult& operator=(const DeleteAwaitByStampTaskResult& deleteAwaitByStampTaskResult) = default;
    DeleteAwaitByStampTaskResult& operator=(DeleteAwaitByStampTaskResult&& deleteAwaitByStampTaskResult) = default;

    DeleteAwaitByStampTaskResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteAwaitByStampTaskResult);
    }

    const DeleteAwaitByStampTaskResult* operator->() const
    {
        return this;
    }

    DeleteAwaitByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * 交換待機を取得
     *
     * @return 交換待機
     */
    const optional<Await>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 交換待機を設定
     *
     * @param item 交換待機
     */
    void setItem(Await item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを取得
     *
     * @return スタンプタスクの実行結果を記録したコンテキスト
     */
    const optional<StringHolder>& getNewContextStack() const
    {
        return ensureData().newContextStack;
    }

    /**
     * スタンプタスクの実行結果を記録したコンテキストを設定
     *
     * @param newContextStack スタンプタスクの実行結果を記録したコンテキスト
     */
    void setNewContextStack(StringHolder newContextStack)
    {
        ensureData().newContextStack.emplace(std::move(newContextStack));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DeleteAwaitByStampTaskResult> AsyncDeleteAwaitByStampTaskResult;

} }

#endif //GS2_EXCHANGE_CONTROL_DELETEAWAITBYSTAMPTASKRESULT_HPP_