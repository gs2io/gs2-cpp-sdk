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

#ifndef GS2_MISSION_CONTROL_DESCRIBEMISSIONTASKMODELMASTERSRESULT_HPP_
#define GS2_MISSION_CONTROL_DESCRIBEMISSIONTASKMODELMASTERSRESULT_HPP_

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
 * ミッションタスクマスターの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeMissionTaskModelMastersResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ミッションタスクマスターのリスト */
        optional<List<MissionTaskModelMaster>> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

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
    DescribeMissionTaskModelMastersResult() = default;
    DescribeMissionTaskModelMastersResult(const DescribeMissionTaskModelMastersResult& describeMissionTaskModelMastersResult) = default;
    DescribeMissionTaskModelMastersResult(DescribeMissionTaskModelMastersResult&& describeMissionTaskModelMastersResult) = default;
    ~DescribeMissionTaskModelMastersResult() = default;

    DescribeMissionTaskModelMastersResult& operator=(const DescribeMissionTaskModelMastersResult& describeMissionTaskModelMastersResult) = default;
    DescribeMissionTaskModelMastersResult& operator=(DescribeMissionTaskModelMastersResult&& describeMissionTaskModelMastersResult) = default;

    DescribeMissionTaskModelMastersResult deepCopy() const;

    const DescribeMissionTaskModelMastersResult* operator->() const
    {
        return this;
    }

    DescribeMissionTaskModelMastersResult* operator->()
    {
        return this;
    }
    /**
     * ミッションタスクマスターのリストを取得
     *
     * @return ミッションタスクマスターのリスト
     */
    const optional<List<MissionTaskModelMaster>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ミッションタスクマスターのリストを設定
     *
     * @param items ミッションタスクマスターのリスト
     */
    void setItems(List<MissionTaskModelMaster> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * リストの続きを取得するためのページトークンを取得
     *
     * @return リストの続きを取得するためのページトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * リストの続きを取得するためのページトークンを設定
     *
     * @param nextPageToken リストの続きを取得するためのページトークン
     */
    void setNextPageToken(StringHolder nextPageToken)
    {
        ensureData().nextPageToken.emplace(std::move(nextPageToken));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeMissionTaskModelMastersResult> AsyncDescribeMissionTaskModelMastersResult;

} }

#endif //GS2_MISSION_CONTROL_DESCRIBEMISSIONTASKMODELMASTERSRESULT_HPP_