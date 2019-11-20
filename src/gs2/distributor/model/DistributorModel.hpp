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

#ifndef GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODEL_HPP_
#define GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace distributor {

/**
 * 配信設定
 *
 * @author Game Server Services, Inc.
 *
 */
class DistributorModel : public Gs2Object
{
    friend bool operator!=(const DistributorModel& lhs, const DistributorModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 配信設定 */
        optional<StringHolder> distributorModelId;
        /** ディストリビューターの種類名 */
        optional<StringHolder> name;
        /** ディストリビューターの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
        optional<StringHolder> inboxNamespaceId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        optional<List<StringHolder>> whiteListTargetIds;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            distributorModelId(data.distributorModelId),
            name(data.name),
            metadata(data.metadata),
            inboxNamespaceId(data.inboxNamespaceId)
        {
            if (data.whiteListTargetIds)
            {
                whiteListTargetIds = data.whiteListTargetIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "distributorModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->distributorModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "inboxNamespaceId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->inboxNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "whiteListTargetIds") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->whiteListTargetIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->whiteListTargetIds += std::move(stringHolder);
                        }
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    DistributorModel() = default;
    DistributorModel(const DistributorModel& distributorModel) = default;
    DistributorModel(DistributorModel&& distributorModel) = default;
    ~DistributorModel() = default;

    DistributorModel& operator=(const DistributorModel& distributorModel) = default;
    DistributorModel& operator=(DistributorModel&& distributorModel) = default;

    DistributorModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DistributorModel);
    }

    const DistributorModel* operator->() const
    {
        return this;
    }

    DistributorModel* operator->()
    {
        return this;
    }
    /**
     * 配信設定を取得
     *
     * @return 配信設定
     */
    const optional<StringHolder>& getDistributorModelId() const
    {
        return ensureData().distributorModelId;
    }

    /**
     * 配信設定を設定
     *
     * @param distributorModelId 配信設定
     */
    void setDistributorModelId(StringHolder distributorModelId)
    {
        ensureData().distributorModelId.emplace(std::move(distributorModelId));
    }

    /**
     * 配信設定を設定
     *
     * @param distributorModelId 配信設定
     */
    DistributorModel& withDistributorModelId(StringHolder distributorModelId)
    {
        setDistributorModelId(std::move(distributorModelId));
        return *this;
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param name ディストリビューターの種類名
     */
    DistributorModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * ディストリビューターの種類のメタデータを設定
     *
     * @param metadata ディストリビューターの種類のメタデータ
     */
    DistributorModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    void setInboxNamespaceId(StringHolder inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(std::move(inboxNamespaceId));
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    DistributorModel& withInboxNamespaceId(StringHolder inboxNamespaceId)
    {
        setInboxNamespaceId(std::move(inboxNamespaceId));
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
    void setWhiteListTargetIds(List<StringHolder> whiteListTargetIds)
    {
        ensureData().whiteListTargetIds.emplace(std::move(whiteListTargetIds));
    }

    /**
     * ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリストを設定
     *
     * @param whiteListTargetIds ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト
     */
    DistributorModel& withWhiteListTargetIds(List<StringHolder> whiteListTargetIds)
    {
        setWhiteListTargetIds(std::move(whiteListTargetIds));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const DistributorModel& lhs, const DistributorModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
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
    }
    return false;
}

inline bool operator==(const DistributorModel& lhs, const DistributorModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODEL_HPP_