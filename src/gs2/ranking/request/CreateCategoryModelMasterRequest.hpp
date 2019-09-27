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

#ifndef GS2_RANKING_CONTROL_CREATECATEGORYMODELMASTERREQUEST_HPP_
#define GS2_RANKING_CONTROL_CREATECATEGORYMODELMASTERREQUEST_HPP_

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
 * カテゴリマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateCategoryModelMasterRequest : public Gs2BasicRequest, public Gs2Ranking
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
        optional<StringHolder> name;
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
        /** スコアの集計間隔(分) */
        optional<Int32> calculateIntervalMinutes;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            minimumValue(data.minimumValue),
            maximumValue(data.maximumValue),
            orderDirection(data.orderDirection),
            scope(data.scope),
            uniqueByUserId(data.uniqueByUserId),
            calculateIntervalMinutes(data.calculateIntervalMinutes)
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
    CreateCategoryModelMasterRequest() = default;
    CreateCategoryModelMasterRequest(const CreateCategoryModelMasterRequest& createCategoryModelMasterRequest) = default;
    CreateCategoryModelMasterRequest(CreateCategoryModelMasterRequest&& createCategoryModelMasterRequest) = default;
    ~CreateCategoryModelMasterRequest() GS2_OVERRIDE = default;

    CreateCategoryModelMasterRequest& operator=(const CreateCategoryModelMasterRequest& createCategoryModelMasterRequest) = default;
    CreateCategoryModelMasterRequest& operator=(CreateCategoryModelMasterRequest&& createCategoryModelMasterRequest) = default;

    CreateCategoryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateCategoryModelMasterRequest);
    }

    const CreateCategoryModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateCategoryModelMasterRequest* operator->()
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
    CreateCategoryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * カテゴリモデル名を取得
     *
     * @return カテゴリモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param name カテゴリモデル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param name カテゴリモデル名
     */
    CreateCategoryModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateCategoryModelMasterRequest& withDescription(StringHolder description)
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
    CreateCategoryModelMasterRequest& withMetadata(StringHolder metadata)
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
    CreateCategoryModelMasterRequest& withMinimumValue(Int64 minimumValue)
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
    CreateCategoryModelMasterRequest& withMaximumValue(Int64 maximumValue)
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
    CreateCategoryModelMasterRequest& withOrderDirection(StringHolder orderDirection)
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
    CreateCategoryModelMasterRequest& withScope(StringHolder scope)
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
    CreateCategoryModelMasterRequest& withUniqueByUserId(Bool uniqueByUserId)
    {
        ensureData().uniqueByUserId.emplace(uniqueByUserId);
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
    CreateCategoryModelMasterRequest& withCalculateIntervalMinutes(Int32 calculateIntervalMinutes)
    {
        ensureData().calculateIntervalMinutes.emplace(calculateIntervalMinutes);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateCategoryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateCategoryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_RANKING_CONTROL_CREATECATEGORYMODELMASTERREQUEST_HPP_