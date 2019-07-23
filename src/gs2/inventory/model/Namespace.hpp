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

#ifndef GS2_INVENTORY_MODEL_NAMESPACE_HPP_
#define GS2_INVENTORY_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** カテゴリー名 */
        optional<StringHolder> name;
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            acquireTriggerScriptId(data.acquireTriggerScriptId),
            acquireDoneTriggerScriptId(data.acquireDoneTriggerScriptId),
            acquireDoneTriggerQueueNamespaceId(data.acquireDoneTriggerQueueNamespaceId),
            overflowTriggerScriptId(data.overflowTriggerScriptId),
            overflowTriggerQueueNamespaceId(data.overflowTriggerQueueNamespaceId),
            consumeTriggerScriptId(data.consumeTriggerScriptId),
            consumeDoneTriggerScriptId(data.consumeDoneTriggerScriptId),
            consumeDoneTriggerQueueNamespaceId(data.consumeDoneTriggerQueueNamespaceId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            acquireTriggerScriptId(std::move(data.acquireTriggerScriptId)),
            acquireDoneTriggerScriptId(std::move(data.acquireDoneTriggerScriptId)),
            acquireDoneTriggerQueueNamespaceId(std::move(data.acquireDoneTriggerQueueNamespaceId)),
            overflowTriggerScriptId(std::move(data.overflowTriggerScriptId)),
            overflowTriggerQueueNamespaceId(std::move(data.overflowTriggerQueueNamespaceId)),
            consumeTriggerScriptId(std::move(data.consumeTriggerScriptId)),
            consumeDoneTriggerScriptId(std::move(data.consumeDoneTriggerScriptId)),
            consumeDoneTriggerQueueNamespaceId(std::move(data.consumeDoneTriggerQueueNamespaceId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "namespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "acquireTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->acquireTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "acquireDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->acquireDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "acquireDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->acquireDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "overflowTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->overflowTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "overflowTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->overflowTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->consumeDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
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
    Namespace() :
        m_pData(nullptr)
    {}

    Namespace(const Namespace& namespace_) :
        Gs2Object(namespace_),
        m_pData(namespace_.m_pData != nullptr ? new Data(*namespace_.m_pData) : nullptr)
    {}

    Namespace(Namespace&& namespace_) :
        Gs2Object(std::move(namespace_)),
        m_pData(namespace_.m_pData)
    {
        namespace_.m_pData = nullptr;
    }

    ~Namespace()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Namespace& operator=(const Namespace& namespace_)
    {
        Gs2Object::operator=(namespace_);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*namespace_.m_pData);

        return *this;
    }

    Namespace& operator=(Namespace&& namespace_)
    {
        Gs2Object::operator=(std::move(namespace_));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = namespace_.m_pData;
        namespace_.m_pData = nullptr;

        return *this;
    }

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(const Char* namespaceId)
    {
        setNamespaceId(namespaceId);
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    Namespace& withName(const Char* name)
    {
        setName(name);
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
    Namespace& withDescription(const Char* description)
    {
        setDescription(description);
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
    Namespace& withAcquireTriggerScriptId(const Char* acquireTriggerScriptId)
    {
        setAcquireTriggerScriptId(acquireTriggerScriptId);
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
    Namespace& withAcquireDoneTriggerScriptId(const Char* acquireDoneTriggerScriptId)
    {
        setAcquireDoneTriggerScriptId(acquireDoneTriggerScriptId);
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
    Namespace& withAcquireDoneTriggerQueueNamespaceId(const Char* acquireDoneTriggerQueueNamespaceId)
    {
        setAcquireDoneTriggerQueueNamespaceId(acquireDoneTriggerQueueNamespaceId);
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
    Namespace& withOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        setOverflowTriggerScriptId(overflowTriggerScriptId);
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
    Namespace& withOverflowTriggerQueueNamespaceId(const Char* overflowTriggerQueueNamespaceId)
    {
        setOverflowTriggerQueueNamespaceId(overflowTriggerQueueNamespaceId);
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
    Namespace& withConsumeTriggerScriptId(const Char* consumeTriggerScriptId)
    {
        setConsumeTriggerScriptId(consumeTriggerScriptId);
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
    Namespace& withConsumeDoneTriggerScriptId(const Char* consumeDoneTriggerScriptId)
    {
        setConsumeDoneTriggerScriptId(consumeDoneTriggerScriptId);
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
    Namespace& withConsumeDoneTriggerQueueNamespaceId(const Char* consumeDoneTriggerQueueNamespaceId)
    {
        setConsumeDoneTriggerQueueNamespaceId(consumeDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Namespace& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->acquireTriggerScriptId != lhr.m_pData->acquireTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->acquireDoneTriggerScriptId != lhr.m_pData->acquireDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->acquireDoneTriggerQueueNamespaceId != lhr.m_pData->acquireDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->overflowTriggerScriptId != lhr.m_pData->overflowTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->overflowTriggerQueueNamespaceId != lhr.m_pData->overflowTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->consumeTriggerScriptId != lhr.m_pData->consumeTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->consumeDoneTriggerScriptId != lhr.m_pData->consumeDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->consumeDoneTriggerQueueNamespaceId != lhr.m_pData->consumeDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_NAMESPACE_HPP_