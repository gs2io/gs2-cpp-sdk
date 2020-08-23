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

#ifndef GS2_ENHANCE_CONTROL_DIRECTENHANCEBYSTAMPSHEETRESULT_HPP_
#define GS2_ENHANCE_CONTROL_DIRECTENHANCEBYSTAMPSHEETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/enhance/model/model.hpp>
#include <memory>

namespace gs2 { namespace enhance
{

/**
 * スタンプシートで強化を実行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DirectEnhanceByStampSheetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 強化レートモデル */
        optional<RateModel> item;
        /** 強化処理の実行に使用するスタンプシート */
        optional<StringHolder> stampSheet;
        /** スタンプシートの署名計算に使用した暗号鍵GRN */
        optional<StringHolder> stampSheetEncryptionKeyId;
        /** 獲得経験値量 */
        optional<Int64> acquireExperience;
        /** 経験値ボーナスの倍率(1.0=ボーナスなし) */
        optional<Float> bonusRate;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            stampSheet(data.stampSheet),
            stampSheetEncryptionKeyId(data.stampSheetEncryptionKeyId),
            acquireExperience(data.acquireExperience),
            bonusRate(data.bonusRate)
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
            else if (std::strcmp(name_, "acquireExperience") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->acquireExperience = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "bonusRate") == 0)
            {
                if (jsonValue.IsFloat())
                {
                    this->bonusRate = jsonValue.GetFloat();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DirectEnhanceByStampSheetResult() = default;
    DirectEnhanceByStampSheetResult(const DirectEnhanceByStampSheetResult& directEnhanceByStampSheetResult) = default;
    DirectEnhanceByStampSheetResult(DirectEnhanceByStampSheetResult&& directEnhanceByStampSheetResult) = default;
    ~DirectEnhanceByStampSheetResult() = default;

    DirectEnhanceByStampSheetResult& operator=(const DirectEnhanceByStampSheetResult& directEnhanceByStampSheetResult) = default;
    DirectEnhanceByStampSheetResult& operator=(DirectEnhanceByStampSheetResult&& directEnhanceByStampSheetResult) = default;

    DirectEnhanceByStampSheetResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DirectEnhanceByStampSheetResult);
    }

    const DirectEnhanceByStampSheetResult* operator->() const
    {
        return this;
    }

    DirectEnhanceByStampSheetResult* operator->()
    {
        return this;
    }
    /**
     * 強化レートモデルを取得
     *
     * @return 強化レートモデル
     */
    const optional<RateModel>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 強化レートモデルを設定
     *
     * @param item 強化レートモデル
     */
    void setItem(RateModel item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 強化処理の実行に使用するスタンプシートを取得
     *
     * @return 強化処理の実行に使用するスタンプシート
     */
    const optional<StringHolder>& getStampSheet() const
    {
        return ensureData().stampSheet;
    }

    /**
     * 強化処理の実行に使用するスタンプシートを設定
     *
     * @param stampSheet 強化処理の実行に使用するスタンプシート
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
     * 獲得経験値量を取得
     *
     * @return 獲得経験値量
     */
    const optional<Int64>& getAcquireExperience() const
    {
        return ensureData().acquireExperience;
    }

    /**
     * 獲得経験値量を設定
     *
     * @param acquireExperience 獲得経験値量
     */
    void setAcquireExperience(Int64 acquireExperience)
    {
        ensureData().acquireExperience.emplace(acquireExperience);
    }

    /**
     * 経験値ボーナスの倍率(1.0=ボーナスなし)を取得
     *
     * @return 経験値ボーナスの倍率(1.0=ボーナスなし)
     */
    const optional<Float>& getBonusRate() const
    {
        return ensureData().bonusRate;
    }

    /**
     * 経験値ボーナスの倍率(1.0=ボーナスなし)を設定
     *
     * @param bonusRate 経験値ボーナスの倍率(1.0=ボーナスなし)
     */
    void setBonusRate(Float bonusRate)
    {
        ensureData().bonusRate.emplace(bonusRate);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DirectEnhanceByStampSheetResult> AsyncDirectEnhanceByStampSheetResult;

} }

#endif //GS2_ENHANCE_CONTROL_DIRECTENHANCEBYSTAMPSHEETRESULT_HPP_