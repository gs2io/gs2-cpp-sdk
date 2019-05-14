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

namespace gs2 { namespace  {

/**
 * ディストリビュータの種類
 *
 * @author Game Server Services, Inc.
 *
 */
class DistributorModelMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ディストリビュータの種類 のGRN */
        optional<StringHolder> distributorModelId;
        /** ディストリビューターの種類名 */
        optional<StringHolder> name;
        /** ディストリビュータの種類の説明 */
        optional<StringHolder> description;
        /** ディストリビューターの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所持品の配布処理の権限判定に使用する ユーザー のGRN */
        optional<StringHolder> assumeUserId;
        /** 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN */
        optional<StringHolder> inboxId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        
        optional<List<StringHolder>> whiteListTargetIds;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            distributorModelId(data.distributorModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            assumeUserId(data.assumeUserId),
            inboxId(data.inboxId),
            whiteListTargetIds(data.whiteListTargetIds),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            distributorModelId(std::move(data.distributorModelId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            assumeUserId(std::move(data.assumeUserId)),
            inboxId(std::move(data.inboxId)),
            whiteListTargetIds(std::move(data.whiteListTargetIds)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "distributorModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->distributorModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "assumeUserId") == 0) {
                if (jsonValue.IsString())
                {
                    this->assumeUserId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "inboxId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inboxId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "whiteListTargetIds") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->whiteListTargetIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->whiteListTargetIds += std::move(stringHolder);
                    }
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * ディストリビュータの種類 のGRNを取得
     *
     * @return ディストリビュータの種類 のGRN
     */
    const optional<StringHolder>& getDistributorModelId() const
    {
        return ensureData().distributorModelId;
    }

    /**
     * ディストリビュータの種類 のGRNを設定
     *
     * @param distributorModelId ディストリビュータの種類 のGRN
     */
    void setDistributorModelId(const Char* distributorModelId)
    {
        ensureData().distributorModelId.emplace(distributorModelId);
    }

    /**
     * ディストリビューターの種類名を取得
     *
     * @return ディストリビューターの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param name ディストリビューターの種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ディストリビュータの種類の説明を取得
     *
     * @return ディストリビュータの種類の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ディストリビュータの種類の説明を設定
     *
     * @param description ディストリビュータの種類の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ディストリビューターの種類のメタデータを取得
     *
     * @return ディストリビューターの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * ディストリビューターの種類のメタデータを設定
     *
     * @param metadata ディストリビューターの種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザー のGRNを取得
     *
     * @return 所持品の配布処理の権限判定に使用する ユーザー のGRN
     */
    const optional<StringHolder>& getAssumeUserId() const
    {
        return ensureData().assumeUserId;
    }

    /**
     * 所持品の配布処理の権限判定に使用する ユーザー のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザー のGRN
     */
    void setAssumeUserId(const Char* assumeUserId)
    {
        ensureData().assumeUserId.emplace(assumeUserId);
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRNを取得
     *
     * @return 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN
     */
    const optional<StringHolder>& getInboxId() const
    {
        return ensureData().inboxId;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRNを設定
     *
     * @param inboxId 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN
     */
    void setInboxId(const Char* inboxId)
    {
        ensureData().inboxId.emplace(inboxId);
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
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODELMASTER_HPP_