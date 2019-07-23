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

#ifndef GS2_MISSION_MODEL_NAMESPACE_HPP_
#define GS2_MISSION_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace mission {

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
        /** ネームスペース名 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ミッション達成時 に実行されるスクリプト のGRN */
        optional<StringHolder> missionCompleteTriggerScriptId;
        /** ミッション達成完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> missionCompleteDoneTriggerScriptId;
        /** ミッション達成完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> missionCompleteDoneTriggerQueueNamespaceId;
        /** カウンター上昇時 に実行されるスクリプト のGRN */
        optional<StringHolder> counterIncrementTriggerScriptId;
        /** カウンター上昇完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> counterIncrementDoneTriggerScriptId;
        /** カウンター上昇完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> counterIncrementDoneTriggerQueueNamespaceId;
        /** 報酬受け取り時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveRewardsTriggerScriptId;
        /** 報酬受け取り完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveRewardsDoneTriggerScriptId;
        /** 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> receiveRewardsDoneTriggerQueueNamespaceId;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
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
            missionCompleteTriggerScriptId(data.missionCompleteTriggerScriptId),
            missionCompleteDoneTriggerScriptId(data.missionCompleteDoneTriggerScriptId),
            missionCompleteDoneTriggerQueueNamespaceId(data.missionCompleteDoneTriggerQueueNamespaceId),
            counterIncrementTriggerScriptId(data.counterIncrementTriggerScriptId),
            counterIncrementDoneTriggerScriptId(data.counterIncrementDoneTriggerScriptId),
            counterIncrementDoneTriggerQueueNamespaceId(data.counterIncrementDoneTriggerQueueNamespaceId),
            receiveRewardsTriggerScriptId(data.receiveRewardsTriggerScriptId),
            receiveRewardsDoneTriggerScriptId(data.receiveRewardsDoneTriggerScriptId),
            receiveRewardsDoneTriggerQueueNamespaceId(data.receiveRewardsDoneTriggerQueueNamespaceId),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            missionCompleteTriggerScriptId(std::move(data.missionCompleteTriggerScriptId)),
            missionCompleteDoneTriggerScriptId(std::move(data.missionCompleteDoneTriggerScriptId)),
            missionCompleteDoneTriggerQueueNamespaceId(std::move(data.missionCompleteDoneTriggerQueueNamespaceId)),
            counterIncrementTriggerScriptId(std::move(data.counterIncrementTriggerScriptId)),
            counterIncrementDoneTriggerScriptId(std::move(data.counterIncrementDoneTriggerScriptId)),
            counterIncrementDoneTriggerQueueNamespaceId(std::move(data.counterIncrementDoneTriggerQueueNamespaceId)),
            receiveRewardsTriggerScriptId(std::move(data.receiveRewardsTriggerScriptId)),
            receiveRewardsDoneTriggerScriptId(std::move(data.receiveRewardsDoneTriggerScriptId)),
            receiveRewardsDoneTriggerQueueNamespaceId(std::move(data.receiveRewardsDoneTriggerQueueNamespaceId)),
            queueNamespaceId(std::move(data.queueNamespaceId)),
            keyId(std::move(data.keyId)),
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
            else if (std::strcmp(name, "missionCompleteTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->missionCompleteTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "missionCompleteDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->missionCompleteDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "missionCompleteDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->missionCompleteDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "counterIncrementTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterIncrementTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "counterIncrementDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterIncrementDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "counterIncrementDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->counterIncrementDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receiveRewardsTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveRewardsTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receiveRewardsDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveRewardsDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receiveRewardsDoneTriggerQueueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->receiveRewardsDoneTriggerQueueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "queueNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->queueNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "keyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->keyId.emplace(jsonValue.GetString());
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
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
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
     * ミッション達成時 に実行されるスクリプト のGRNを取得
     *
     * @return ミッション達成時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getMissionCompleteTriggerScriptId() const
    {
        return ensureData().missionCompleteTriggerScriptId;
    }

    /**
     * ミッション達成時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteTriggerScriptId ミッション達成時 に実行されるスクリプト のGRN
     */
    void setMissionCompleteTriggerScriptId(const Char* missionCompleteTriggerScriptId)
    {
        ensureData().missionCompleteTriggerScriptId.emplace(missionCompleteTriggerScriptId);
    }

    /**
     * ミッション達成時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteTriggerScriptId ミッション達成時 に実行されるスクリプト のGRN
     */
    Namespace& withMissionCompleteTriggerScriptId(const Char* missionCompleteTriggerScriptId)
    {
        setMissionCompleteTriggerScriptId(missionCompleteTriggerScriptId);
        return *this;
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを取得
     *
     * @return ミッション達成完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getMissionCompleteDoneTriggerScriptId() const
    {
        return ensureData().missionCompleteDoneTriggerScriptId;
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteDoneTriggerScriptId ミッション達成完了時 に実行されるスクリプト のGRN
     */
    void setMissionCompleteDoneTriggerScriptId(const Char* missionCompleteDoneTriggerScriptId)
    {
        ensureData().missionCompleteDoneTriggerScriptId.emplace(missionCompleteDoneTriggerScriptId);
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteDoneTriggerScriptId ミッション達成完了時 に実行されるスクリプト のGRN
     */
    Namespace& withMissionCompleteDoneTriggerScriptId(const Char* missionCompleteDoneTriggerScriptId)
    {
        setMissionCompleteDoneTriggerScriptId(missionCompleteDoneTriggerScriptId);
        return *this;
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getMissionCompleteDoneTriggerQueueNamespaceId() const
    {
        return ensureData().missionCompleteDoneTriggerQueueNamespaceId;
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param missionCompleteDoneTriggerQueueNamespaceId ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    void setMissionCompleteDoneTriggerQueueNamespaceId(const Char* missionCompleteDoneTriggerQueueNamespaceId)
    {
        ensureData().missionCompleteDoneTriggerQueueNamespaceId.emplace(missionCompleteDoneTriggerQueueNamespaceId);
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param missionCompleteDoneTriggerQueueNamespaceId ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    Namespace& withMissionCompleteDoneTriggerQueueNamespaceId(const Char* missionCompleteDoneTriggerQueueNamespaceId)
    {
        setMissionCompleteDoneTriggerQueueNamespaceId(missionCompleteDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを取得
     *
     * @return カウンター上昇時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCounterIncrementTriggerScriptId() const
    {
        return ensureData().counterIncrementTriggerScriptId;
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementTriggerScriptId カウンター上昇時 に実行されるスクリプト のGRN
     */
    void setCounterIncrementTriggerScriptId(const Char* counterIncrementTriggerScriptId)
    {
        ensureData().counterIncrementTriggerScriptId.emplace(counterIncrementTriggerScriptId);
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementTriggerScriptId カウンター上昇時 に実行されるスクリプト のGRN
     */
    Namespace& withCounterIncrementTriggerScriptId(const Char* counterIncrementTriggerScriptId)
    {
        setCounterIncrementTriggerScriptId(counterIncrementTriggerScriptId);
        return *this;
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを取得
     *
     * @return カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCounterIncrementDoneTriggerScriptId() const
    {
        return ensureData().counterIncrementDoneTriggerScriptId;
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementDoneTriggerScriptId カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    void setCounterIncrementDoneTriggerScriptId(const Char* counterIncrementDoneTriggerScriptId)
    {
        ensureData().counterIncrementDoneTriggerScriptId.emplace(counterIncrementDoneTriggerScriptId);
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementDoneTriggerScriptId カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    Namespace& withCounterIncrementDoneTriggerScriptId(const Char* counterIncrementDoneTriggerScriptId)
    {
        setCounterIncrementDoneTriggerScriptId(counterIncrementDoneTriggerScriptId);
        return *this;
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getCounterIncrementDoneTriggerQueueNamespaceId() const
    {
        return ensureData().counterIncrementDoneTriggerQueueNamespaceId;
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param counterIncrementDoneTriggerQueueNamespaceId カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    void setCounterIncrementDoneTriggerQueueNamespaceId(const Char* counterIncrementDoneTriggerQueueNamespaceId)
    {
        ensureData().counterIncrementDoneTriggerQueueNamespaceId.emplace(counterIncrementDoneTriggerQueueNamespaceId);
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param counterIncrementDoneTriggerQueueNamespaceId カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    Namespace& withCounterIncrementDoneTriggerQueueNamespaceId(const Char* counterIncrementDoneTriggerQueueNamespaceId)
    {
        setCounterIncrementDoneTriggerQueueNamespaceId(counterIncrementDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを取得
     *
     * @return 報酬受け取り時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveRewardsTriggerScriptId() const
    {
        return ensureData().receiveRewardsTriggerScriptId;
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsTriggerScriptId 報酬受け取り時 に実行されるスクリプト のGRN
     */
    void setReceiveRewardsTriggerScriptId(const Char* receiveRewardsTriggerScriptId)
    {
        ensureData().receiveRewardsTriggerScriptId.emplace(receiveRewardsTriggerScriptId);
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsTriggerScriptId 報酬受け取り時 に実行されるスクリプト のGRN
     */
    Namespace& withReceiveRewardsTriggerScriptId(const Char* receiveRewardsTriggerScriptId)
    {
        setReceiveRewardsTriggerScriptId(receiveRewardsTriggerScriptId);
        return *this;
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを取得
     *
     * @return 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveRewardsDoneTriggerScriptId() const
    {
        return ensureData().receiveRewardsDoneTriggerScriptId;
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsDoneTriggerScriptId 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    void setReceiveRewardsDoneTriggerScriptId(const Char* receiveRewardsDoneTriggerScriptId)
    {
        ensureData().receiveRewardsDoneTriggerScriptId.emplace(receiveRewardsDoneTriggerScriptId);
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsDoneTriggerScriptId 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    Namespace& withReceiveRewardsDoneTriggerScriptId(const Char* receiveRewardsDoneTriggerScriptId)
    {
        setReceiveRewardsDoneTriggerScriptId(receiveRewardsDoneTriggerScriptId);
        return *this;
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getReceiveRewardsDoneTriggerQueueNamespaceId() const
    {
        return ensureData().receiveRewardsDoneTriggerQueueNamespaceId;
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveRewardsDoneTriggerQueueNamespaceId 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    void setReceiveRewardsDoneTriggerQueueNamespaceId(const Char* receiveRewardsDoneTriggerQueueNamespaceId)
    {
        ensureData().receiveRewardsDoneTriggerQueueNamespaceId.emplace(receiveRewardsDoneTriggerQueueNamespaceId);
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveRewardsDoneTriggerQueueNamespaceId 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    Namespace& withReceiveRewardsDoneTriggerQueueNamespaceId(const Char* receiveRewardsDoneTriggerQueueNamespaceId)
    {
        setReceiveRewardsDoneTriggerQueueNamespaceId(receiveRewardsDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを取得
     *
     * @return 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    const optional<StringHolder>& getQueueNamespaceId() const
    {
        return ensureData().queueNamespaceId;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    void setQueueNamespaceId(const Char* queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(queueNamespaceId);
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    Namespace& withQueueNamespaceId(const Char* queueNamespaceId)
    {
        setQueueNamespaceId(queueNamespaceId);
        return *this;
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを取得
     *
     * @return 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    Namespace& withKeyId(const Char* keyId)
    {
        setKeyId(keyId);
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
        if (lhs.m_pData->missionCompleteTriggerScriptId != lhr.m_pData->missionCompleteTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->missionCompleteDoneTriggerScriptId != lhr.m_pData->missionCompleteDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->missionCompleteDoneTriggerQueueNamespaceId != lhr.m_pData->missionCompleteDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->counterIncrementTriggerScriptId != lhr.m_pData->counterIncrementTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->counterIncrementDoneTriggerScriptId != lhr.m_pData->counterIncrementDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->counterIncrementDoneTriggerQueueNamespaceId != lhr.m_pData->counterIncrementDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->receiveRewardsTriggerScriptId != lhr.m_pData->receiveRewardsTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->receiveRewardsDoneTriggerScriptId != lhr.m_pData->receiveRewardsDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->receiveRewardsDoneTriggerQueueNamespaceId != lhr.m_pData->receiveRewardsDoneTriggerQueueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->queueNamespaceId != lhr.m_pData->queueNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->keyId != lhr.m_pData->keyId)
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

#endif //GS2_MISSION_MODEL_NAMESPACE_HPP_