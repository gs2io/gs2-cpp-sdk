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

#ifndef GS2_DEPLOY_CONTROL_FORCEDELETESTACKRESULT_HPP_
#define GS2_DEPLOY_CONTROL_FORCEDELETESTACKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/deploy/model/model.hpp>
#include <memory>

namespace gs2 { namespace deploy
{

/**
 * スタックを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ForceDeleteStackResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除したスタック */
        optional<Stack> item;

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
    ForceDeleteStackResult() = default;
    ForceDeleteStackResult(const ForceDeleteStackResult& forceDeleteStackResult) = default;
    ForceDeleteStackResult(ForceDeleteStackResult&& forceDeleteStackResult) = default;
    ~ForceDeleteStackResult() = default;

    ForceDeleteStackResult& operator=(const ForceDeleteStackResult& forceDeleteStackResult) = default;
    ForceDeleteStackResult& operator=(ForceDeleteStackResult&& forceDeleteStackResult) = default;

    ForceDeleteStackResult deepCopy() const;

    const ForceDeleteStackResult* operator->() const
    {
        return this;
    }

    ForceDeleteStackResult* operator->()
    {
        return this;
    }
    /**
     * 削除したスタックを取得
     *
     * @return 削除したスタック
     */
    const optional<Stack>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除したスタックを設定
     *
     * @param item 削除したスタック
     */
    void setItem(Stack item)
    {
        ensureData().item.emplace(std::move(item));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ForceDeleteStackResult> AsyncForceDeleteStackResult;

} }

#endif //GS2_DEPLOY_CONTROL_FORCEDELETESTACKRESULT_HPP_