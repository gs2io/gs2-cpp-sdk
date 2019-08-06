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

#ifndef GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODELMASTER_HPP_
#define GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace distributor {

/**
 * 配信設定マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class DistributorModelMaster : public Gs2Object
{
    friend bool operator!=(const DistributorModelMaster& lhs, const DistributorModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 配信設定マスター */
        optional<StringHolder> distributorModelId;
        /** 配信設定名 */
        optional<StringHolder> name;
        /** 配信設定マスターの説明 */
        optional<StringHolder> description;
        /** 配信設定のメタデータ */
        optional<StringHolder> metadata;
        /** 所持品の配布処理の権限判定に使用する ユーザ のGRN */
        optional<StringHolder> assumeUserId;
        /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
        optional<StringHolder> inboxNamespaceId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        optional<List<StringHolder>> whiteListTargetIds;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            distributorModelId(data.distributorModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            assumeUserId(data.assumeUserId),
            inboxNamespaceId(data.inboxNamespaceId),
            whiteListTargetIds(data.whiteListTargetIds),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            distributorModelId(std::move(data.distributorModelId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            assumeUserId(std::move(data.assumeUserId)),
            inboxNamespaceId(std::move(data.inboxNamespaceId)),
            whiteListTargetIds(std::move(data.whiteListTargetIds)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "distributorModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->distributorModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "assumeUserId") == 0) {
                if (jsonValue.IsString())
                {
                    this->assumeUserId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "inboxNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inboxNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "whiteListTargetIds") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->whiteListTargetIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->whiteListTargetIds, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
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
    DistributorModelMaster() :
        m_pData(nullptr)
    {}

    DistributorModelMaster(const DistributorModelMaster& distributorModelMaster) :
        Gs2Object(distributorModelMaster),
        m_pData(distributorModelMaster.m_pData != nullptr ? new Data(*distributorModelMaster.m_pData) : nullptr)
    {}

    DistributorModelMaster(DistributorModelMaster&& distributorModelMaster) :
        Gs2Object(std::move(distributorModelMaster)),
        m_pData(distributorModelMaster.m_pData)
    {
        distributorModelMaster.m_pData = nullptr;
    }

    ~DistributorModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DistributorModelMaster& operator=(const DistributorModelMaster& distributorModelMaster)
    {
        Gs2Object::operator=(distributorModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*distributorModelMaster.m_pData);

        return *this;
    }

    DistributorModelMaster& operator=(DistributorModelMaster&& distributorModelMaster)
    {
        Gs2Object::operator=(std::move(distributorModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = distributorModelMaster.m_pData;
        distributorModelMaster.m_pData = nullptr;

        return *this;
    }

    const DistributorModelMaster* operator->() const
    {
        return this;
    }

    DistributorModelMaster* operator->()
    {
        return this;
    }
    /**
     * 配信設定マスターを取得
     *
     * @return 配信設定マスター
     */
    const optional<StringHolder>& getDistributorModelId() const
    {
        return ensureData().distributorModelId;
    }

    /**
     * 配信設定マスターを設定
     *
     * @param distributorModelId 配信設定マスター
     */
    void setDistributorModelId(const Char* distributorModelId)
    {
        ensureData().distributorModelId.emplace(distributorModelId);
    }

    /**
     * 配信設定マスターを設定
     *
     * @param distributorModelId 配信設定マスター
     */
    DistributorModelMaster& withDistributorModelId(const Char* distributorModelId)
    {
        setDistributorModelId(distributorModelId);
        return *this;
    }

    /**
     * 配信設定名を取得
     *
     * @return 配信設定名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 配信設定名を設定
     *
     * @param name 配信設定名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 配信設定名を設定
     *
     * @param name 配信設定名
     */
    DistributorModelMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 配信設定マスターの説明を取得
     *
     * @return 配信設定マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 配信設定マスターの説明を設定
     *
     * @param description 配信設定マスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 配信設定マスターの説明を設定
     *
     * @param description 配信設定マスターの説明
     */
    DistributorModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * 配信設定のメタデータを取得
     *
     * @return 配信設定のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 配信設定のメタデータを設定
     *
     * @param metadata 配信設定のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 配信設定のメタデータを設定
     *
     * @param metadata 配信設定のメタデータ
     */
    DistributorModelMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザ のGRNを取得
     *
     * @return 所持品の配布処理の権限判定に使用する ユーザ のGRN
     */
    const optional<StringHolder>& getAssumeUserId() const
    {
        return ensureData().assumeUserId;
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザ のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザ のGRN
     */
    void setAssumeUserId(const Char* assumeUserId)
    {
        ensureData().assumeUserId.emplace(assumeUserId);
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザ のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザ のGRN
     */
    DistributorModelMaster& withAssumeUserId(const Char* assumeUserId)
    {
        setAssumeUserId(assumeUserId);
        return *this;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを取得
     *
     * @return 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    const optional<StringHolder>& getInboxNamespaceId() const
    {
        return ensureData().inboxNamespaceId;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    void setInboxNamespaceId(const Char* inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(inboxNamespaceId);
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    DistributorModelMaster& withInboxNamespaceId(const Char* inboxNamespaceId)
    {
        setInboxNamespaceId(inboxNamespaceId);
        return *this;
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを取得
     *
     * @return ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    const optional<List<StringHolder>>& getWhiteListTargetIds() const
    {
        return ensureData().whiteListTargetIds;
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを設定
     *
     * @param whiteListTargetIds ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    void setWhiteListTargetIds(const List<StringHolder>& whiteListTargetIds)
    {
        ensureData().whiteListTargetIds.emplace(whiteListTargetIds);
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを設定
     *
     * @param whiteListTargetIds ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    DistributorModelMaster& withWhiteListTargetIds(const List<StringHolder>& whiteListTargetIds)
    {
        setWhiteListTargetIds(whiteListTargetIds);
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
    DistributorModelMaster& withCreatedAt(Int64 createdAt)
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
    DistributorModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DistributorModelMaster& lhs, const DistributorModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->distributorModelId != lhr.m_pData->distributorModelId)
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
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->assumeUserId != lhr.m_pData->assumeUserId)
        {
            return true;
        }
        if (lhs.m_pData->inboxNamespaceId != lhr.m_pData->inboxNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->whiteListTargetIds != lhr.m_pData->whiteListTargetIds)
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

inline bool operator==(const DistributorModelMaster& lhs, const DistributorModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODELMASTER_HPP_