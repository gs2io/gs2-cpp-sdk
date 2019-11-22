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

#ifndef GS2_MONEY_CONTROL_RECORDRECEIPTBYSTAMPTASKRESULT_HPP_
#define GS2_MONEY_CONTROL_RECORDRECEIPTBYSTAMPTASKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/money/model/model.hpp>
#include <memory>

namespace gs2 { namespace money
{

/**
 * スタンプシートを使用してレシートを記録 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class RecordReceiptByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レシート */
        optional<Receipt> item;
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
    RecordReceiptByStampTaskResult() = default;
    RecordReceiptByStampTaskResult(const RecordReceiptByStampTaskResult& recordReceiptByStampTaskResult) = default;
    RecordReceiptByStampTaskResult(RecordReceiptByStampTaskResult&& recordReceiptByStampTaskResult) = default;
    ~RecordReceiptByStampTaskResult() = default;

    RecordReceiptByStampTaskResult& operator=(const RecordReceiptByStampTaskResult& recordReceiptByStampTaskResult) = default;
    RecordReceiptByStampTaskResult& operator=(RecordReceiptByStampTaskResult&& recordReceiptByStampTaskResult) = default;

    RecordReceiptByStampTaskResult deepCopy() const;

    const RecordReceiptByStampTaskResult* operator->() const
    {
        return this;
    }

    RecordReceiptByStampTaskResult* operator->()
    {
        return this;
    }
    /**
     * レシートを取得
     *
     * @return レシート
     */
    const optional<Receipt>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * レシートを設定
     *
     * @param item レシート
     */
    void setItem(Receipt item)
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

typedef AsyncResult<RecordReceiptByStampTaskResult> AsyncRecordReceiptByStampTaskResult;

} }

#endif //GS2_MONEY_CONTROL_RECORDRECEIPTBYSTAMPTASKRESULT_HPP_