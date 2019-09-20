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

#ifndef GS2_QUEST_CONTROL_STARTBYUSERIDRESULT_HPP_
#define GS2_QUEST_CONTROL_STARTBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/quest/model/model.hpp>
#include <memory>

namespace gs2 { namespace quest
{

/**
 * ユーザIDを指定してクエストを開始 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class StartByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストの開始処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "stampSheet") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    StartByUserIdResult() = default;
    StartByUserIdResult(const StartByUserIdResult& startByUserIdResult) = default;
    StartByUserIdResult(StartByUserIdResult&& startByUserIdResult) = default;
    ~StartByUserIdResult() = default;

    StartByUserIdResult& operator=(const StartByUserIdResult& startByUserIdResult) = default;
    StartByUserIdResult& operator=(StartByUserIdResult&& startByUserIdResult) = default;

    StartByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(StartByUserIdResult);
    }

    const StartByUserIdResult* operator->() const
    {
        return this;
    }

    StartByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * クエストの開始処理の実行に使用するスタンプシートを取得
     *
     * @return クエストの開始処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * クエストの開始処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet クエストの開始処理の実行に使用するスタンプシート
     */
    void setStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<StartByUserIdResult> AsyncStartByUserIdResult;

} }

#endif //GS2_QUEST_CONTROL_STARTBYUSERIDRESULT_HPP_