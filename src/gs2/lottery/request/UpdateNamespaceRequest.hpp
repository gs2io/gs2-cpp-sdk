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

#ifndef GS2_LOTTERY_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_LOTTERY_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/lottery/Gs2LotteryConst.hpp>
#include <gs2/lottery/model/model.hpp>
#include <memory>

namespace gs2 { namespace lottery
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Lottery
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** 景品付与処理をジョブとして追加するキューのネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 景品付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
        /** 抽選処理時 に実行されるスクリプト のGRN */
        optional<StringHolder> lotteryTriggerScriptId;
        /** 排出テーブル選択時 に実行されるスクリプト のGRN */
        optional<StringHolder> choicePrizeTableScriptId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId),
            lotteryTriggerScriptId(data.lotteryTriggerScriptId),
            choicePrizeTableScriptId(data.choicePrizeTableScriptId)
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
    UpdateNamespaceRequest() = default;
    UpdateNamespaceRequest(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest(UpdateNamespaceRequest&& updateNamespaceRequest) = default;
    ~UpdateNamespaceRequest() GS2_OVERRIDE = default;

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest) = default;

    UpdateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateNamespaceRequest);
    }

    const UpdateNamespaceRequest* operator->() const
    {
        return this;
    }

    UpdateNamespaceRequest* operator->()
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
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 景品付与処理をジョブとして追加するキューのネームスペース のGRNを取得
     *
     * @return 景品付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getQueueNamespaceId() const
    {
        return ensureData().queueNamespaceId;
    }

    /**
     * 景品付与処理をジョブとして追加するキューのネームスペース のGRNを設定
     *
     * @param queueNamespaceId 景品付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    void setQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
    }

    /**
     * 景品付与処理をジョブとして追加するキューのネームスペース のGRNを設定
     *
     * @param queueNamespaceId 景品付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    UpdateNamespaceRequest& withQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
        return *this;
    }

    /**
     * 景品付与処理のスタンプシートで使用する暗号鍵GRNを取得
     *
     * @return 景品付与処理のスタンプシートで使用する暗号鍵GRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 景品付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 景品付与処理のスタンプシートで使用する暗号鍵GRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 景品付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 景品付与処理のスタンプシートで使用する暗号鍵GRN
     */
    UpdateNamespaceRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
        return *this;
    }

    /**
     * 抽選処理時 に実行されるスクリプト のGRNを取得
     *
     * @return 抽選処理時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getLotteryTriggerScriptId() const
    {
        return ensureData().lotteryTriggerScriptId;
    }

    /**
     * 抽選処理時 に実行されるスクリプト のGRNを設定
     *
     * @param lotteryTriggerScriptId 抽選処理時 に実行されるスクリプト のGRN
     */
    void setLotteryTriggerScriptId(StringHolder lotteryTriggerScriptId)
    {
        ensureData().lotteryTriggerScriptId.emplace(std::move(lotteryTriggerScriptId));
    }

    /**
     * 抽選処理時 に実行されるスクリプト のGRNを設定
     *
     * @param lotteryTriggerScriptId 抽選処理時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withLotteryTriggerScriptId(StringHolder lotteryTriggerScriptId)
    {
        ensureData().lotteryTriggerScriptId.emplace(std::move(lotteryTriggerScriptId));
        return *this;
    }

    /**
     * 排出テーブル選択時 に実行されるスクリプト のGRNを取得
     *
     * @return 排出テーブル選択時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getChoicePrizeTableScriptId() const
    {
        return ensureData().choicePrizeTableScriptId;
    }

    /**
     * 排出テーブル選択時 に実行されるスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 排出テーブル選択時 に実行されるスクリプト のGRN
     */
    void setChoicePrizeTableScriptId(StringHolder choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(std::move(choicePrizeTableScriptId));
    }

    /**
     * 排出テーブル選択時 に実行されるスクリプト のGRNを設定
     *
     * @param choicePrizeTableScriptId 排出テーブル選択時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withChoicePrizeTableScriptId(StringHolder choicePrizeTableScriptId)
    {
        ensureData().choicePrizeTableScriptId.emplace(std::move(choicePrizeTableScriptId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LOTTERY_CONTROL_UPDATENAMESPACEREQUEST_HPP_