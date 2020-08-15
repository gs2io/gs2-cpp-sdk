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

#ifndef GS2_LOTTERY_CONTROL_DRAWBYUSERIDRESULT_HPP_
#define GS2_LOTTERY_CONTROL_DRAWBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/lottery/model/model.hpp>
#include <memory>

namespace gs2 { namespace lottery
{

/**
 * ユーザIDを指定して抽選を実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DrawByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 抽選結果の景品リスト */
        optional<List<DrawnPrize>> items;
        /** 排出された景品を入手するスタンプシート */
        optional<StringHolder> stampSheet;
        /** スタンプシートの署名計算に使用した暗号鍵GRN */
        optional<StringHolder> stampSheetEncryptionKeyId;
        /** ボックスから取り出したアイテムのリスト */
        optional<BoxItems> boxItems;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet),
            stampSheetEncryptionKeyId(data.stampSheetEncryptionKeyId)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
            if (data.boxItems)
            {
                boxItems = data.boxItems->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        DrawnPrize item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "stampSheet") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stampSheet.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "stampSheetEncryptionKeyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->stampSheetEncryptionKeyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "boxItems") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->boxItems.emplace();
                    detail::json::JsonParser::parse(&this->boxItems->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DrawByUserIdResult() = default;
    DrawByUserIdResult(const DrawByUserIdResult& drawByUserIdResult) = default;
    DrawByUserIdResult(DrawByUserIdResult&& drawByUserIdResult) = default;
    ~DrawByUserIdResult() = default;

    DrawByUserIdResult& operator=(const DrawByUserIdResult& drawByUserIdResult) = default;
    DrawByUserIdResult& operator=(DrawByUserIdResult&& drawByUserIdResult) = default;

    DrawByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DrawByUserIdResult);
    }

    const DrawByUserIdResult* operator->() const
    {
        return this;
    }

    DrawByUserIdResult* operator->()
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
     * スタンプシートの署名計算に使用した暗号鍵GRNを取得
     *
     * @return スタンプシートの署名計算に使用した暗号鍵GRN
     */
    const optional<StringHolder>& getStampSheetEncryptionKeyId() const
    {
        return ensureData().stampSheetEncryptionKeyId;
    }

    /**
     * スタンプシートの署名計算に使用した暗号鍵GRNを設定
     *
     * @param stampSheetEncryptionKeyId スタンプシートの署名計算に使用した暗号鍵GRN
     */
    void setStampSheetEncryptionKeyId(StringHolder stampSheetEncryptionKeyId)
    {
        ensureData().stampSheetEncryptionKeyId.emplace(std::move(stampSheetEncryptionKeyId));
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

typedef AsyncResult<DrawByUserIdResult> AsyncDrawByUserIdResult;

} }

#endif //GS2_LOTTERY_CONTROL_DRAWBYUSERIDRESULT_HPP_