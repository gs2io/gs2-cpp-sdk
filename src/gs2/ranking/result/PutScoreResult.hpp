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

#ifndef GS2_RANKING_CONTROL_PUTSCORERESULT_HPP_
#define GS2_RANKING_CONTROL_PUTSCORERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * スコアを登録 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class PutScoreResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 登録したスコア */
        optional<Score> item;

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
    PutScoreResult() = default;
    PutScoreResult(const PutScoreResult& putScoreResult) = default;
    PutScoreResult(PutScoreResult&& putScoreResult) = default;
    ~PutScoreResult() = default;

    PutScoreResult& operator=(const PutScoreResult& putScoreResult) = default;
    PutScoreResult& operator=(PutScoreResult&& putScoreResult) = default;

    PutScoreResult deepCopy() const;

    const PutScoreResult* operator->() const
    {
        return this;
    }

    PutScoreResult* operator->()
    {
        return this;
    }
    /**
     * 登録したスコアを取得
     *
     * @return 登録したスコア
     */
    const optional<Score>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 登録したスコアを設定
     *
     * @param item 登録したスコア
     */
    void setItem(Score item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<PutScoreResult> AsyncPutScoreResult;

} }

#endif //GS2_RANKING_CONTROL_PUTSCORERESULT_HPP_