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

#ifndef GS2_LOTTERY_CONTROL_DRAWBYSTAMPSHEETRESULT_HPP_
#define GS2_LOTTERY_CONTROL_DRAWBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/lottery/model/model.hpp>
#include <memory>

namespace gs2 { namespace lottery
{

/**
 * スタンプシートを使用して抽選処理を実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DrawByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 抽選結果の景品リスト */
        optional<List<DrawnPrize>> items;
        /** 排出された景品を入手するスタンプシート */
        optional<StringHolder> stampSheet;
        /** ボックスから取り出したアイテムのリスト */
        optional<BoxItems> boxItems;

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
    DrawByStampSheetResult() = default;
    DrawByStampSheetResult(const DrawByStampSheetResult& drawByStampSheetResult) = default;
    DrawByStampSheetResult(DrawByStampSheetResult&& drawByStampSheetResult) = default;
    ~DrawByStampSheetResult() = default;

    DrawByStampSheetResult& operator=(const DrawByStampSheetResult& drawByStampSheetResult) = default;
    DrawByStampSheetResult& operator=(DrawByStampSheetResult&& drawByStampSheetResult) = default;

    DrawByStampSheetResult deepCopy() const;

    const DrawByStampSheetResult* operator->() const
    {
        return this;
    }

    DrawByStampSheetResult* operator->()
    {
        return this;
    }
    /**
     * 抽選結果の景品リストを取得
     *
     * @return 抽選結果の景品リスト
     */
    const optional<List<DrawnPrize>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 抽選結果の景品リストを設定
     *
     * @param items 抽選結果の景品リスト
     */
    void setItems(List<DrawnPrize> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * 排出された景品を入手するスタンプシートを取得
     *
     * @return 排出された景品を入手するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 排出された景品を入手するスタンプシートを設定
     *
     * @param stampSheet 排出された景品を入手するスタンプシート
     */
    void setStampSheet(StringHolder stampSheet)
    {
        ensureData().stampSheet.emplace(std::move(stampSheet));
    }

    /**
     * ボックスから取り出したアイテムのリストを取得
     *
     * @return ボックスから取り出したアイテムのリスト
     */
    const optional<BoxItems>& getBoxItems() const
    {
        return ensureData().boxItems;
    }

    /**
     * ボックスから取り出したアイテムのリストを設定
     *
     * @param boxItems ボックスから取り出したアイテムのリスト
     */
    void setBoxItems(BoxItems boxItems)
    {
        ensureData().boxItems.emplace(std::move(boxItems));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DrawByStampSheetResult> AsyncDrawByStampSheetResult;

} }

#endif //GS2_LOTTERY_CONTROL_DRAWBYSTAMPSHEETRESULT_HPP_