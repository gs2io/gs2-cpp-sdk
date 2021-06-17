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

#ifndef GS2_QUEST_CONTROL_ENDRESULT_HPP_
#define GS2_QUEST_CONTROL_ENDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/quest/model/model.hpp>
#include <memory>

namespace gs2 { namespace quest
{

/**
 * クエストを完了 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class EndResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエスト挑戦 */
        optional<Progress> item;
        /** 報酬付与処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;
        /** スタンプシートの署名計算に使用した暗号鍵GRN */
        optional<StringHolder> stampSheetEncryptionKeyId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet),
            stampSheetEncryptionKeyId(data.stampSheetEncryptionKeyId)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EndResult() = default;
    EndResult(const EndResult& endResult) = default;
    EndResult(EndResult&& endResult) = default;
    ~EndResult() = default;

    EndResult& operator=(const EndResult& endResult) = default;
    EndResult& operator=(EndResult&& endResult) = default;

    EndResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EndResult);
    }

    const EndResult* operator->() const
    {
        return this;
    }

    EndResult* operator->()
    {
        return this;
    }
    /**
     * クエスト挑戦を取得
     *
     * @return クエスト挑戦
     */
    const optional<Progress>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * クエスト挑戦を設定
     *
     * @param item クエスト挑戦
     */
    void setItem(Progress item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 報酬付与処理の実行に使用するスタンプシートを取得
     *
     * @return 報酬付与処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 報酬付与処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet 報酬付与処理の実行に使用するスタンプシート
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<EndResult> AsyncEndResult;

} }

#endif //GS2_QUEST_CONTROL_ENDRESULT_HPP_