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

#ifndef GS2_RANKING_CONTROL_UPDATECATEGORYMODELMASTERREQUEST_HPP_
#define GS2_RANKING_CONTROL_UPDATECATEGORYMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/Gs2RankingConst.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * カテゴリマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCategoryModelMasterRequest : public Gs2BasicRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** カテゴリモデル名 */
        optional<StringHolder> categoryName;
        /** カテゴリマスターの説明 */
        optional<StringHolder> description;
        /** カテゴリマスターのメタデータ */
        optional<StringHolder> metadata;
        /** スコアの最小値 */
        optional<Int64> minimumValue;
        /** スコアの最大値 */
        optional<Int64> maximumValue;
        /** スコアのソート方向 */
        optional<StringHolder> orderDirection;
        /** ランキングの種類 */
        optional<StringHolder> scope;
        /** ユーザID毎にスコアを1つしか登録されないようにする */
        optional<Bool> uniqueByUserId;
        /** スコアの固定集計開始時刻(時) */
        optional<Int32> calculateFixedTimingHour;
        /** スコアの固定集計開始時刻(分) */
        optional<Int32> calculateFixedTimingMinute;
        /** スコアの集計間隔(分) */
        optional<Int32> calculateIntervalMinutes;
        /** スコアの登録可能期間とするイベントマスター のGRN */
        optional<StringHolder> entryPeriodEventId;
        /** アクセス可能期間とするイベントマスター のGRN */
        optional<StringHolder> accessPeriodEventId;
        /** ランキングの世代 */
        optional<StringHolder> generation;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            categoryName(data.categoryName),
            description(data.description),
            metadata(data.metadata),
            minimumValue(data.minimumValue),
            maximumValue(data.maximumValue),
            orderDirection(data.orderDirection),
            scope(data.scope),
            uniqueByUserId(data.uniqueByUserId),
            calculateFixedTimingHour(data.calculateFixedTimingHour),
            calculateFixedTimingMinute(data.calculateFixedTimingMinute),
            calculateIntervalMinutes(data.calculateIntervalMinutes),
            entryPeriodEventId(data.entryPeriodEventId),
            accessPeriodEventId(data.accessPeriodEventId),
            generation(data.generation)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    UpdateCategoryModelMasterRequest() = default;
    UpdateCategoryModelMasterRequest(const UpdateCategoryModelMasterRequest& updateCategoryModelMasterRequest) = default;
    UpdateCategoryModelMasterRequest(UpdateCategoryModelMasterRequest&& updateCategoryModelMasterRequest) = default;
    ~UpdateCategoryModelMasterRequest() GS2_OVERRIDE = default;

    UpdateCategoryModelMasterRequest& operator=(const UpdateCategoryModelMasterRequest& updateCategoryModelMasterRequest) = default;
    UpdateCategoryModelMasterRequest& operator=(UpdateCategoryModelMasterRequest&& updateCategoryModelMasterRequest) = default;

    UpdateCategoryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateCategoryModelMasterRequest);
    }

    const UpdateCategoryModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateCategoryModelMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateCategoryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * カテゴリモデル名を取得
     *
     * @return カテゴリモデル名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param categoryName カテゴリモデル名
     */
    void setCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param categoryName カテゴリモデル名
     */
    UpdateCategoryModelMasterRequest& withCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
        return *this;
    }

    /**
     * カテゴリマスターの説明を取得
     *
     * @return カテゴリマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * カテゴリマスターの説明を設定
     *
     * @param description カテゴリマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * カテゴリマスターの説明を設定
     *
     * @param description カテゴリマスターの説明
     */
    UpdateCategoryModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * カテゴリマスターのメタデータを取得
     *
     * @return カテゴリマスターのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * カテゴリマスターのメタデータを設定
     *
     * @param metadata カテゴリマスターのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * カテゴリマスターのメタデータを設定
     *
     * @param metadata カテゴリマスターのメタデータ
     */
    UpdateCategoryModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * スコアの最小値を取得
     *
     * @return スコアの最小値
     */
    const optional<Int64>& getMinimumValue() const
    {
        return ensureData().minimumValue;
    }

    /**
     * スコアの最小値を設定
     *
     * @param minimumValue スコアの最小値
     */
    void setMinimumValue(Int64 minimumValue)
    {
        ensureData().minimumValue.emplace(minimumValue);
    }

    /**
     * スコアの最小値を設定
     *
     * @param minimumValue スコアの最小値
     */
    UpdateCategoryModelMasterRequest& withMinimumValue(Int64 minimumValue)
    {
        ensureData().minimumValue.emplace(minimumValue);
        return *this;
    }

    /**
     * スコアの最大値を取得
     *
     * @return スコアの最大値
     */
    const optional<Int64>& getMaximumValue() const
    {
        return ensureData().maximumValue;
    }

    /**
     * スコアの最大値を設定
     *
     * @param maximumValue スコアの最大値
     */
    void setMaximumValue(Int64 maximumValue)
    {
        ensureData().maximumValue.emplace(maximumValue);
    }

    /**
     * スコアの最大値を設定
     *
     * @param maximumValue スコアの最大値
     */
    UpdateCategoryModelMasterRequest& withMaximumValue(Int64 maximumValue)
    {
        ensureData().maximumValue.emplace(maximumValue);
        return *this;
    }

    /**
     * スコアのソート方向を取得
     *
     * @return スコアのソート方向
     */
    const optional<StringHolder>& getOrderDirection() const
    {
        return ensureData().orderDirection;
    }

    /**
     * スコアのソート方向を設定
     *
     * @param orderDirection スコアのソート方向
     */
    void setOrderDirection(StringHolder orderDirection)
    {
        ensureData().orderDirection.emplace(std::move(orderDirection));
    }

    /**
     * スコアのソート方向を設定
     *
     * @param orderDirection スコアのソート方向
     */
    UpdateCategoryModelMasterRequest& withOrderDirection(StringHolder orderDirection)
    {
        ensureData().orderDirection.emplace(std::move(orderDirection));
        return *this;
    }

    /**
     * ランキングの種類を取得
     *
     * @return ランキングの種類
     */
    const optional<StringHolder>& getScope() const
    {
        return ensureData().scope;
    }

    /**
     * ランキングの種類を設定
     *
     * @param scope ランキングの種類
     */
    void setScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
    }

    /**
     * ランキングの種類を設定
     *
     * @param scope ランキングの種類
     */
    UpdateCategoryModelMasterRequest& withScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
        return *this;
    }

    /**
     * ユーザID毎にスコアを1つしか登録されないようにするを取得
     *
     * @return ユーザID毎にスコアを1つしか登録されないようにする
     */
    const optional<Bool>& getUniqueByUserId() const
    {
        return ensureData().uniqueByUserId;
    }

    /**
     * ユーザID毎にスコアを1つしか登録されないようにするを設定
     *
     * @param uniqueByUserId ユーザID毎にスコアを1つしか登録されないようにする
     */
    void setUniqueByUserId(Bool uniqueByUserId)
    {
        ensureData().uniqueByUserId.emplace(uniqueByUserId);
    }

    /**
     * ユーザID毎にスコアを1つしか登録されないようにするを設定
     *
     * @param uniqueByUserId ユーザID毎にスコアを1つしか登録されないようにする
     */
    UpdateCategoryModelMasterRequest& withUniqueByUserId(Bool uniqueByUserId)
    {
        ensureData().uniqueByUserId.emplace(uniqueByUserId);
        return *this;
    }

    /**
     * スコアの固定集計開始時刻(時)を取得
     *
     * @return スコアの固定集計開始時刻(時)
     */
    const optional<Int32>& getCalculateFixedTimingHour() const
    {
        return ensureData().calculateFixedTimingHour;
    }

    /**
     * スコアの固定集計開始時刻(時)を設定
     *
     * @param calculateFixedTimingHour スコアの固定集計開始時刻(時)
     */
    void setCalculateFixedTimingHour(Int32 calculateFixedTimingHour)
    {
        ensureData().calculateFixedTimingHour.emplace(calculateFixedTimingHour);
    }

    /**
     * スコアの固定集計開始時刻(時)を設定
     *
     * @param calculateFixedTimingHour スコアの固定集計開始時刻(時)
     */
    UpdateCategoryModelMasterRequest& withCalculateFixedTimingHour(Int32 calculateFixedTimingHour)
    {
        ensureData().calculateFixedTimingHour.emplace(calculateFixedTimingHour);
        return *this;
    }

    /**
     * スコアの固定集計開始時刻(分)を取得
     *
     * @return スコアの固定集計開始時刻(分)
     */
    const optional<Int32>& getCalculateFixedTimingMinute() const
    {
        return ensureData().calculateFixedTimingMinute;
    }

    /**
     * スコアの固定集計開始時刻(分)を設定
     *
     * @param calculateFixedTimingMinute スコアの固定集計開始時刻(分)
     */
    void setCalculateFixedTimingMinute(Int32 calculateFixedTimingMinute)
    {
        ensureData().calculateFixedTimingMinute.emplace(calculateFixedTimingMinute);
    }

    /**
     * スコアの固定集計開始時刻(分)を設定
     *
     * @param calculateFixedTimingMinute スコアの固定集計開始時刻(分)
     */
    UpdateCategoryModelMasterRequest& withCalculateFixedTimingMinute(Int32 calculateFixedTimingMinute)
    {
        ensureData().calculateFixedTimingMinute.emplace(calculateFixedTimingMinute);
        return *this;
    }

    /**
     * スコアの集計間隔(分)を取得
     *
     * @return スコアの集計間隔(分)
     */
    const optional<Int32>& getCalculateIntervalMinutes() const
    {
        return ensureData().calculateIntervalMinutes;
    }

    /**
     * スコアの集計間隔(分)を設定
     *
     * @param calculateIntervalMinutes スコアの集計間隔(分)
     */
    void setCalculateIntervalMinutes(Int32 calculateIntervalMinutes)
    {
        ensureData().calculateIntervalMinutes.emplace(calculateIntervalMinutes);
    }

    /**
     * スコアの集計間隔(分)を設定
     *
     * @param calculateIntervalMinutes スコアの集計間隔(分)
     */
    UpdateCategoryModelMasterRequest& withCalculateIntervalMinutes(Int32 calculateIntervalMinutes)
    {
        ensureData().calculateIntervalMinutes.emplace(calculateIntervalMinutes);
        return *this;
    }

    /**
     * スコアの登録可能期間とするイベントマスター のGRNを取得
     *
     * @return スコアの登録可能期間とするイベントマスター のGRN
     */
    const optional<StringHolder>& getEntryPeriodEventId() const
    {
        return ensureData().entryPeriodEventId;
    }

    /**
     * スコアの登録可能期間とするイベントマスター のGRNを設定
     *
     * @param entryPeriodEventId スコアの登録可能期間とするイベントマスター のGRN
     */
    void setEntryPeriodEventId(StringHolder entryPeriodEventId)
    {
        ensureData().entryPeriodEventId.emplace(std::move(entryPeriodEventId));
    }

    /**
     * スコアの登録可能期間とするイベントマスター のGRNを設定
     *
     * @param entryPeriodEventId スコアの登録可能期間とするイベントマスター のGRN
     */
    UpdateCategoryModelMasterRequest& withEntryPeriodEventId(StringHolder entryPeriodEventId)
    {
        ensureData().entryPeriodEventId.emplace(std::move(entryPeriodEventId));
        return *this;
    }

    /**
     * アクセス可能期間とするイベントマスター のGRNを取得
     *
     * @return アクセス可能期間とするイベントマスター のGRN
     */
    const optional<StringHolder>& getAccessPeriodEventId() const
    {
        return ensureData().accessPeriodEventId;
    }

    /**
     * アクセス可能期間とするイベントマスター のGRNを設定
     *
     * @param accessPeriodEventId アクセス可能期間とするイベントマスター のGRN
     */
    void setAccessPeriodEventId(StringHolder accessPeriodEventId)
    {
        ensureData().accessPeriodEventId.emplace(std::move(accessPeriodEventId));
    }

    /**
     * アクセス可能期間とするイベントマスター のGRNを設定
     *
     * @param accessPeriodEventId アクセス可能期間とするイベントマスター のGRN
     */
    UpdateCategoryModelMasterRequest& withAccessPeriodEventId(StringHolder accessPeriodEventId)
    {
        ensureData().accessPeriodEventId.emplace(std::move(accessPeriodEventId));
        return *this;
    }

    /**
     * ランキングの世代を取得
     *
     * @return ランキングの世代
     */
    const optional<StringHolder>& getGeneration() const
    {
        return ensureData().generation;
    }

    /**
     * ランキングの世代を設定
     *
     * @param generation ランキングの世代
     */
    void setGeneration(StringHolder generation)
    {
        ensureData().generation.emplace(std::move(generation));
    }

    /**
     * ランキングの世代を設定
     *
     * @param generation ランキングの世代
     */
    UpdateCategoryModelMasterRequest& withGeneration(StringHolder generation)
    {
        ensureData().generation.emplace(std::move(generation));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateCategoryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCategoryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_RANKING_CONTROL_UPDATECATEGORYMODELMASTERREQUEST_HPP_