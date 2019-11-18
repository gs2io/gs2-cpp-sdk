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
            metadata(data.metadata)
        {
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