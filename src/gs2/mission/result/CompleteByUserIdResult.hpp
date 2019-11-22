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

#ifndef GS2_MISSION_CONTROL_COMPLETEBYUSERIDRESULT_HPP_
#define GS2_MISSION_CONTROL_COMPLETEBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/mission/model/model.hpp>
#include <memory>

namespace gs2 { namespace mission
{

/**
 * 達成状況を新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CompleteByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッションの達成報酬を受領するスタンプシート */
        optional<StringHolder> stampSheet;

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
    CompleteByUserIdResult() = default;
    CompleteByUserIdResult(const CompleteByUserIdResult& completeByUserIdResult) = default;
    CompleteByUserIdResult(CompleteByUserIdResult&& completeByUserIdResult) = default;
    ~CompleteByUserIdResult() = default;

    CompleteByUserIdResult& operator=(const CompleteByUserIdResult& completeByUserIdResult) = default;
    CompleteByUserIdResult& operator=(CompleteByUserIdResult&& completeByUserIdResult) = default;

    CompleteByUserIdResult deepCopy() const;

    const CompleteByUserIdResult* operator->() const
    {
        return this;
    }

    CompleteByUserIdResult* operator->()
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

typedef AsyncResult<CompleteByUserIdResult> AsyncCompleteByUserIdResult;

} }

#endif //GS2_MISSION_CONTROL_COMPLETEBYUSERIDRESULT_HPP_