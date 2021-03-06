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

#ifndef GS2_MISSION_CONTROL_COMPLETERESULT_HPP_
#define GS2_MISSION_CONTROL_COMPLETERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/mission/model/model.hpp>
#include <memory>

namespace gs2 { namespace mission
{

/**
 * ミッション達成報酬を受領するためのスタンプシートを発行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CompleteResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッションの達成報酬を受領するスタンプシート */
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
    CompleteResult() = default;
    CompleteResult(const CompleteResult& completeResult) = default;
    CompleteResult(CompleteResult&& completeResult) = default;
    ~CompleteResult() = default;

    CompleteResult& operator=(const CompleteResult& completeResult) = default;
    CompleteResult& operator=(CompleteResult&& completeResult) = default;

    CompleteResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CompleteResult);
    }

    const CompleteResult* operator->() const
    {
        return this;
    }

    CompleteResult* operator->()
    {
        return this;
    }
    /**
     * ミッションの達成報酬を受領するスタンプシートを取得
     *
     * @return ミッションの達成報酬を受領するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * ミッションの達成報酬を受領するスタンプシートを設定
     *
     * @param stampSheet ミッションの達成報酬を受領するスタンプシート
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

typedef AsyncResult<CompleteResult> AsyncCompleteResult;

} }

#endif //GS2_MISSION_CONTROL_COMPLETERESULT_HPP_