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

#ifndef GS2_QUEST_MODEL_CONTENTS_HPP_
#define GS2_QUEST_MODEL_CONTENTS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <memory>

namespace gs2 { namespace quest {

/**
 * コンテンツ
 *
 * @author Game Server Services, Inc.
 *
 */
class Contents : public Gs2Object
{
    friend bool operator!=(const Contents& lhs, const Contents& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストモデルのメタデータ */
        optional<StringHolder> metadata;
        /** クエストクリア時の報酬 */
        optional<List<AcquireAction>> completeAcquireActions;
        /** 抽選する重み */
        optional<Int32> weight;

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
    Contents() = default;
    Contents(const Contents& contents) = default;
    Contents(Contents&& contents) = default;
    ~Contents() = default;

    Contents& operator=(const Contents& contents) = default;
    Contents& operator=(Contents&& contents) = default;

    Contents deepCopy() const;

    const Contents* operator->() const
    {
        return this;
    }

    Contents* operator->()
    {
        return this;
    }
    /**
     * クエストモデルのメタデータを取得
     *
     * @return クエストモデルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * クエストモデルのメタデータを設定
     *
     * @param metadata クエストモデルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * クエストモデルのメタデータを設定
     *
     * @param metadata クエストモデルのメタデータ
     */
    Contents& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * クエストクリア時の報酬を取得
     *
     * @return クエストクリア時の報酬
     */
    const optional<List<AcquireAction>>& getCompleteAcquireActions() const
    {
        return ensureData().completeAcquireActions;
    }

    /**
     * クエストクリア時の報酬を設定
     *
     * @param completeAcquireActions クエストクリア時の報酬
     */
    void setCompleteAcquireActions(List<AcquireAction> completeAcquireActions)
    {
        ensureData().completeAcquireActions.emplace(std::move(completeAcquireActions));
    }

    /**
     * クエストクリア時の報酬を設定
     *
     * @param completeAcquireActions クエストクリア時の報酬
     */
    Contents& withCompleteAcquireActions(List<AcquireAction> completeAcquireActions)
    {
        setCompleteAcquireActions(std::move(completeAcquireActions));
        return *this;
    }

    /**
     * 抽選する重みを取得
     *
     * @return 抽選する重み
     */
    const optional<Int32>& getWeight() const
    {
        return ensureData().weight;
    }

    /**
     * 抽選する重みを設定
     *
     * @param weight 抽選する重み
     */
    void setWeight(Int32 weight)
    {
        ensureData().weight.emplace(weight);
    }

    /**
     * 抽選する重みを設定
     *
     * @param weight 抽選する重み
     */
    Contents& withWeight(Int32 weight)
    {
        setWeight(weight);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Contents& lhs, const Contents& lhr);

inline bool operator==(const Contents& lhs, const Contents& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_CONTENTS_HPP_