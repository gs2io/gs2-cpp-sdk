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

#ifndef GS2_JOBQUEUE_CONTROL_PUSHBYSTAMPSHEETRESULT_HPP_
#define GS2_JOBQUEUE_CONTROL_PUSHBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/jobQueue/model/model.hpp>
#include <memory>

namespace gs2 { namespace jobQueue
{

/**
 * スタンプシートでジョブを登録 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class PushByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 追加した{model_name}の一覧 */
        optional<List<Job>> items;

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
    PushByStampSheetResult() = default;
    PushByStampSheetResult(const PushByStampSheetResult& pushByStampSheetResult) = default;
    PushByStampSheetResult(PushByStampSheetResult&& pushByStampSheetResult) = default;
    ~PushByStampSheetResult() = default;

    PushByStampSheetResult& operator=(const PushByStampSheetResult& pushByStampSheetResult) = default;
    PushByStampSheetResult& operator=(PushByStampSheetResult&& pushByStampSheetResult) = default;

    PushByStampSheetResult deepCopy() const;

    const PushByStampSheetResult* operator->() const
    {
        return this;
    }

    PushByStampSheetResult* operator->()
    {
        return this;
    }
    /**
     * 追加した{model_name}の一覧を取得
     *
     * @return 追加した{model_name}の一覧
     */
    const optional<List<Job>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 追加した{model_name}の一覧を設定
     *
     * @param items 追加した{model_name}の一覧
     */
    void setItems(List<Job> items)
    {
        ensureData().items.emplace(std::move(items));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<PushByStampSheetResult> AsyncPushByStampSheetResult;

} }

#endif //GS2_JOBQUEUE_CONTROL_PUSHBYSTAMPSHEETRESULT_HPP_