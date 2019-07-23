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

#ifndef GS2_INVENTORY_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** アイテム入手時 に実行されるスクリプト のGRN */
        optional<StringHolder> acquireTriggerScriptId;
        /** アイテム入手完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> acquireDoneTriggerScriptId;
        /** アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN */
        optional<StringHolder> acquireDoneTriggerQueueNamespaceId;
        /** 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN */
        optional<StringHolder> overflowTriggerScriptId;
        /** 入手上限に当たって入手できなかった数量を通知するジョブを追加する ネームスペース のGRN */
        optional<StringHolder> overflowTriggerQueueNamespaceId;
        /** アイテム消費時 に実行されるスクリプト のGRN */
        optional<StringHolder> consumeTriggerScriptId;
        /** アイテム入手完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> consumeDoneTriggerScriptId;
        /** アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN */
        optional<StringHolder> consumeDoneTriggerQueueNamespaceId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            acquireTriggerScriptId(data.acquireTriggerScriptId),
            acquireDoneTriggerScriptId(data.acquireDoneTriggerScriptId),
            acquireDoneTriggerQueueNamespaceId(data.acquireDoneTriggerQueueNamespaceId),
            overflowTriggerScriptId(data.overflowTriggerScriptId),
            overflowTriggerQueueNamespaceId(data.overflowTriggerQueueNamespaceId),
            consumeTriggerScriptId(data.consumeTriggerScriptId),
            consumeDoneTriggerScriptId(data.consumeDoneTriggerScriptId),
            consumeDoneTriggerQueueNamespaceId(data.consumeDoneTriggerQueueNamespaceId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            acquireTriggerScriptId(std::move(data.acquireTriggerScriptId)),
            acquireDoneTriggerScriptId(std::move(data.acquireDoneTriggerScriptId)),
            acquireDoneTriggerQueueNamespaceId(std::move(data.acquireDoneTriggerQueueNamespaceId)),
            overflowTriggerScriptId(std::move(data.overflowTriggerScriptId)),
            overflowTriggerQueueNamespaceId(std::move(data.overflowTriggerQueueNamespaceId)),
            consumeTriggerScriptId(std::move(data.consumeTriggerScriptId)),
            consumeDoneTriggerScriptId(std::move(data.consumeDoneTriggerScriptId)),
            consumeDoneTriggerQueueNamespaceId(std::move(data.consumeDoneTriggerQueueNamespaceId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    UpdateNamespaceRequest() :
        m_pData(nullptr)
    {}

    UpdateNamespaceRequest(const UpdateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(updateNamespaceRequest);
        Gs2Inventory::operator=(updateNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateNamespaceRequest.m_pData);

        return *this;
    }

    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateNamespaceRequest));
        Gs2Inventory::operator=(std::move(updateNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateNamespaceRequest.m_pData;
        updateNamespaceRequest.m_pData = nullptr;

        return *this;
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
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    UpdateNamespaceRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    UpdateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * アイテム入手時 に実行されるスクリプト のGRNを取得
     *
     * @return アイテム入手時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getAcquireTriggerScriptId() const
    {
        return ensureData().acquireTriggerScriptId;
    }

    /**
     * アイテム入手時 に実行されるスクリプト のGRNを設定
     *
     * @param acquireTriggerScriptId アイテム入手時 に実行されるスクリプト のGRN
     */
    void setAcquireTriggerScriptId(const Char* acquireTriggerScriptId)
    {
        ensureData().acquireTriggerScriptId.emplace(acquireTriggerScriptId);
    }

    /**
     * アイテム入手時 に実行されるスクリプト のGRNを設定
     *
     * @param acquireTriggerScriptId アイテム入手時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withAcquireTriggerScriptId(const Char* acquireTriggerScriptId)
    {
        ensureData().acquireTriggerScriptId.emplace(acquireTriggerScriptId);
        return *this;
    }

    /**
     * アイテム入手完了時 に実行されるスクリプト のGRNを取得
     *
     * @return アイテム入手完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getAcquireDoneTriggerScriptId() const
    {
        return ensureData().acquireDoneTriggerScriptId;
    }

    /**
     * アイテム入手完了時 に実行されるスクリプト のGRNを設定
     *
     * @param acquireDoneTriggerScriptId アイテム入手完了時 に実行されるスクリプト のGRN
     */
    void setAcquireDoneTriggerScriptId(const Char* acquireDoneTriggerScriptId)
    {
        ensureData().acquireDoneTriggerScriptId.emplace(acquireDoneTriggerScriptId);
    }

    /**
     * アイテム入手完了時 に実行されるスクリプト のGRNを設定
     *
     * @param acquireDoneTriggerScriptId アイテム入手完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withAcquireDoneTriggerScriptId(const Char* acquireDoneTriggerScriptId)
    {
        ensureData().acquireDoneTriggerScriptId.emplace(acquireDoneTriggerScriptId);
        return *this;
    }

    /**
     * アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRNを取得
     *
     * @return アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN
     */
    const optional<StringHolder>& getAcquireDoneTriggerQueueNamespaceId() const
    {
        return ensureData().acquireDoneTriggerQueueNamespaceId;
    }

    /**
     * アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRNを設定
     *
     * @param acquireDoneTriggerQueueNamespaceId アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN
     */
    void setAcquireDoneTriggerQueueNamespaceId(const Char* acquireDoneTriggerQueueNamespaceId)
    {
        ensureData().acquireDoneTriggerQueueNamespaceId.emplace(acquireDoneTriggerQueueNamespaceId);
    }

    /**
     * アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRNを設定
     *
     * @param acquireDoneTriggerQueueNamespaceId アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN
     */
    UpdateNamespaceRequest& withAcquireDoneTriggerQueueNamespaceId(const Char* acquireDoneTriggerQueueNamespaceId)
    {
        ensureData().acquireDoneTriggerQueueNamespaceId.emplace(acquireDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知する スクリプト のGRNを取得
     *
     * @return 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN
     */
    const optional<StringHolder>& getOverflowTriggerScriptId() const
    {
        return ensureData().overflowTriggerScriptId;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN
     */
    void setOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId 入手上限に当たって入手できなかった数量を通知する スクリプト のGRN
     */
    UpdateNamespaceRequest& withOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
        return *this;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知するジョブを追加する ネームスペース のGRNを取得
     *
     * @return 入手上限に当たって入手できなかった数量を通知するジョブを追加する ネームスペース のGRN
     */
    const optional<StringHolder>& getOverflowTriggerQueueNamespaceId() const
    {
        return ensureData().overflowTriggerQueueNamespaceId;
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知するジョブを追加する ネームスペース のGRNを設定
     *
     * @param overflowTriggerQueueNamespaceId 入手上限に当たって入手できなかった数量を通知するジョブを追加する ネームスペース のGRN
     */
    void setOverflowTriggerQueueNamespaceId(const Char* overflowTriggerQueueNamespaceId)
    {
        ensureData().overflowTriggerQueueNamespaceId.emplace(overflowTriggerQueueNamespaceId);
    }

    /**
     * 入手上限に当たって入手できなかった数量を通知するジョブを追加する ネームスペース のGRNを設定
     *
     * @param overflowTriggerQueueNamespaceId 入手上限に当たって入手できなかった数量を通知するジョブを追加する ネームスペース のGRN
     */
    UpdateNamespaceRequest& withOverflowTriggerQueueNamespaceId(const Char* overflowTriggerQueueNamespaceId)
    {
        ensureData().overflowTriggerQueueNamespaceId.emplace(overflowTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * アイテム消費時 に実行されるスクリプト のGRNを取得
     *
     * @return アイテム消費時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getConsumeTriggerScriptId() const
    {
        return ensureData().consumeTriggerScriptId;
    }

    /**
     * アイテム消費時 に実行されるスクリプト のGRNを設定
     *
     * @param consumeTriggerScriptId アイテム消費時 に実行されるスクリプト のGRN
     */
    void setConsumeTriggerScriptId(const Char* consumeTriggerScriptId)
    {
        ensureData().consumeTriggerScriptId.emplace(consumeTriggerScriptId);
    }

    /**
     * アイテム消費時 に実行されるスクリプト のGRNを設定
     *
     * @param consumeTriggerScriptId アイテム消費時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withConsumeTriggerScriptId(const Char* consumeTriggerScriptId)
    {
        ensureData().consumeTriggerScriptId.emplace(consumeTriggerScriptId);
        return *this;
    }

    /**
     * アイテム入手完了時 に実行されるスクリプト のGRNを取得
     *
     * @return アイテム入手完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getConsumeDoneTriggerScriptId() const
    {
        return ensureData().consumeDoneTriggerScriptId;
    }

    /**
     * アイテム入手完了時 に実行されるスクリプト のGRNを設定
     *
     * @param consumeDoneTriggerScriptId アイテム入手完了時 に実行されるスクリプト のGRN
     */
    void setConsumeDoneTriggerScriptId(const Char* consumeDoneTriggerScriptId)
    {
        ensureData().consumeDoneTriggerScriptId.emplace(consumeDoneTriggerScriptId);
    }

    /**
     * アイテム入手完了時 に実行されるスクリプト のGRNを設定
     *
     * @param consumeDoneTriggerScriptId アイテム入手完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withConsumeDoneTriggerScriptId(const Char* consumeDoneTriggerScriptId)
    {
        ensureData().consumeDoneTriggerScriptId.emplace(consumeDoneTriggerScriptId);
        return *this;
    }

    /**
     * アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRNを取得
     *
     * @return アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN
     */
    const optional<StringHolder>& getConsumeDoneTriggerQueueNamespaceId() const
    {
        return ensureData().consumeDoneTriggerQueueNamespaceId;
    }

    /**
     * アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRNを設定
     *
     * @param consumeDoneTriggerQueueNamespaceId アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN
     */
    void setConsumeDoneTriggerQueueNamespaceId(const Char* consumeDoneTriggerQueueNamespaceId)
    {
        ensureData().consumeDoneTriggerQueueNamespaceId.emplace(consumeDoneTriggerQueueNamespaceId);
    }

    /**
     * アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRNを設定
     *
     * @param consumeDoneTriggerQueueNamespaceId アイテム入手完了時 に通知するジョブを追加する ネームスペース のGRN
     */
    UpdateNamespaceRequest& withConsumeDoneTriggerQueueNamespaceId(const Char* consumeDoneTriggerQueueNamespaceId)
    {
        ensureData().consumeDoneTriggerQueueNamespaceId.emplace(consumeDoneTriggerQueueNamespaceId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_UPDATENAMESPACEREQUEST_HPP_