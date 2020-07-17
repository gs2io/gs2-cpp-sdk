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

#ifndef GS2_EXCHANGE_CONTROL_CREATERATEMODELMASTERREQUEST_HPP_
#define GS2_EXCHANGE_CONTROL_CREATERATEMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/exchange/Gs2ExchangeConst.hpp>
#include <gs2/exchange/model/model.hpp>
#include <memory>

namespace gs2 { namespace exchange
{

/**
 * 交換レートマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateRateModelMasterRequest : public Gs2BasicRequest, public Gs2Exchange
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 交換レート名 */
        optional<StringHolder> name;
        /** 交換レートマスターの説明 */
        optional<StringHolder> description;
        /** 交換レートのメタデータ */
        optional<StringHolder> metadata;
        /** 交換の種類 */
        optional<StringHolder> timingType;
        /** 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分） */
        optional<Int32> lockTime;
        /** スキップをすることができるか */
        optional<Bool> enableSkip;
        /** 時短消費アクションリスト */
        optional<List<ConsumeAction>> skipConsumeActions;
        /** 入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;
        /** 消費アクションリスト */
        optional<List<ConsumeAction>> consumeActions;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            timingType(data.timingType),
            lockTime(data.lockTime),
            enableSkip(data.enableSkip)
        {
            if (data.skipConsumeActions)
            {
                skipConsumeActions = data.skipConsumeActions->deepCopy();
            }
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
            }
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
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
    CreateRateModelMasterRequest() = default;
    CreateRateModelMasterRequest(const CreateRateModelMasterRequest& createRateModelMasterRequest) = default;
    CreateRateModelMasterRequest(CreateRateModelMasterRequest&& createRateModelMasterRequest) = default;
    ~CreateRateModelMasterRequest() GS2_OVERRIDE = default;

    CreateRateModelMasterRequest& operator=(const CreateRateModelMasterRequest& createRateModelMasterRequest) = default;
    CreateRateModelMasterRequest& operator=(CreateRateModelMasterRequest&& createRateModelMasterRequest) = default;

    CreateRateModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateRateModelMasterRequest);
    }

    const CreateRateModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateRateModelMasterRequest* operator->()
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
    CreateRateModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 交換レート名を取得
     *
     * @return 交換レート名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 交換レート名を設定
     *
     * @param name 交換レート名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 交換レート名を設定
     *
     * @param name 交換レート名
     */
    CreateRateModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * 交換レートマスターの説明を取得
     *
     * @return 交換レートマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 交換レートマスターの説明を設定
     *
     * @param description 交換レートマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 交換レートマスターの説明を設定
     *
     * @param description 交換レートマスターの説明
     */
    CreateRateModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 交換レートのメタデータを取得
     *
     * @return 交換レートのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 交換レートのメタデータを設定
     *
     * @param metadata 交換レートのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 交換レートのメタデータを設定
     *
     * @param metadata 交換レートのメタデータ
     */
    CreateRateModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 交換の種類を取得
     *
     * @return 交換の種類
     */
    const optional<StringHolder>& getTimingType() const
    {
        return ensureData().timingType;
    }

    /**
     * 交換の種類を設定
     *
     * @param timingType 交換の種類
     */
    void setTimingType(StringHolder timingType)
    {
        ensureData().timingType.emplace(std::move(timingType));
    }

    /**
     * 交換の種類を設定
     *
     * @param timingType 交換の種類
     */
    CreateRateModelMasterRequest& withTimingType(StringHolder timingType)
    {
        ensureData().timingType.emplace(std::move(timingType));
        return *this;
    }

    /**
     * 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）を取得
     *
     * @return 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）
     */
    const optional<Int32>& getLockTime() const
    {
        return ensureData().lockTime;
    }

    /**
     * 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）を設定
     *
     * @param lockTime 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）
     */
    void setLockTime(Int32 lockTime)
    {
        ensureData().lockTime.emplace(lockTime);
    }

    /**
     * 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）を設定
     *
     * @param lockTime 交換実行から実際に報酬を受け取れるようになるまでの待ち時間（分）
     */
    CreateRateModelMasterRequest& withLockTime(Int32 lockTime)
    {
        ensureData().lockTime.emplace(lockTime);
        return *this;
    }

    /**
     * スキップをすることができるかを取得
     *
     * @return スキップをすることができるか
     */
    const optional<Bool>& getEnableSkip() const
    {
        return ensureData().enableSkip;
    }

    /**
     * スキップをすることができるかを設定
     *
     * @param enableSkip スキップをすることができるか
     */
    void setEnableSkip(Bool enableSkip)
    {
        ensureData().enableSkip.emplace(enableSkip);
    }

    /**
     * スキップをすることができるかを設定
     *
     * @param enableSkip スキップをすることができるか
     */
    CreateRateModelMasterRequest& withEnableSkip(Bool enableSkip)
    {
        ensureData().enableSkip.emplace(enableSkip);
        return *this;
    }

    /**
     * 時短消費アクションリストを取得
     *
     * @return 時短消費アクションリスト
     */
    const optional<List<ConsumeAction>>& getSkipConsumeActions() const
    {
        return ensureData().skipConsumeActions;
    }

    /**
     * 時短消費アクションリストを設定
     *
     * @param skipConsumeActions 時短消費アクションリスト
     */
    void setSkipConsumeActions(List<ConsumeAction> skipConsumeActions)
    {
        ensureData().skipConsumeActions.emplace(std::move(skipConsumeActions));
    }

    /**
     * 時短消費アクションリストを設定
     *
     * @param skipConsumeActions 時短消費アクションリスト
     */
    CreateRateModelMasterRequest& withSkipConsumeActions(List<ConsumeAction> skipConsumeActions)
    {
        ensureData().skipConsumeActions.emplace(std::move(skipConsumeActions));
        return *this;
    }

    /**
     * 入手アクションリストを取得
     *
     * @return 入手アクションリスト
     */
    const optional<List<AcquireAction>>& getAcquireActions() const
    {
        return ensureData().acquireActions;
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    void setAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    CreateRateModelMasterRequest& withAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
        return *this;
    }

    /**
     * 消費アクションリストを取得
     *
     * @return 消費アクションリスト
     */
    const optional<List<ConsumeAction>>& getConsumeActions() const
    {
        return ensureData().consumeActions;
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    void setConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    CreateRateModelMasterRequest& withConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateRateModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateRateModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXCHANGE_CONTROL_CREATERATEMODELMASTERREQUEST_HPP_