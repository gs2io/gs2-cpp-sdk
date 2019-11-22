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

#ifndef GS2_LIMIT_CONTROL_COUNTUPBYSTAMPTASKRESULT_HPP_
#define GS2_LIMIT_CONTROL_COUNTUPBYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/limit/model/model.hpp>
#include <memory>

namespace gs2 { namespace limit
{

/**
 * スタンプシートでカウントアップ のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CountUpByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** カウントを増やしたカウンター */
        optional<Counter> item;
        /** スタンプタスクの実行結果を記録したコンテキスト */
        optional<StringHolder> newContextStack;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CountUpByStampTaskResult() = default;
    CountUpByStampTaskResult(const CountUpByStampTaskResult& countUpByStampTaskResult) = default;
    CountUpByStampTaskResult(CountUpByStampTaskResult&& countUpByStampTaskResult) = default;
    ~CountUpByStampTaskResult() = default;

    CountUpByStampTaskResult& operator=(const CountUpByStampTaskResult& countUpByStampTaskResult) = default;
    CountUpByStampTaskResult& operator=(CountUpByStampTaskResult&& countUpByStampTaskResult) = default;

    CountUpByStampTaskResult deepCopy() const;

    const CountUpByStampTaskResult* operator->() const
    {
        return this;
    }

    CountUpByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * カウントを増やしたカウンターを取得
     *
     * @return カウントを増やしたカウンター
     */
    const optional<Counter>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * カウントを増やしたカウンターを設定
     *
     * @param item カウントを増やしたカウンター
     */
    void setItem(Counter item)
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

typedef AsyncResult<CountUpByStampTaskResult> AsyncCountUpByStampTaskResult;

} }

#endif //GS2_LIMIT_CONTROL_COUNTUPBYSTAMPTASKRESULT_HPP_