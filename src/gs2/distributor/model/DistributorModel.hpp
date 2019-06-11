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
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace distributor {

/**
 * ディストリビュータの種類
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
        /** ディストリビュータの種類 のGRN */
        optional<StringHolder> distributorModelId;
        /** ディストリビューターの種類名 */
        optional<StringHolder> name;
        /** ディストリビューターの種類のメタデータ */
        optional<StringHolder> metadata;
        /** 所持品の配布処理の権限判定に使用する ユーザー のGRN */
        optional<StringHolder> assumeUserId;
        /** 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN */
        optional<StringHolder> inboxId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        optional<List<StringHolder>> whiteListTargetIds;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            distributorModelId(data.distributorModelId),
            name(data.name),
            metadata(data.metadata),
            assumeUserId(data.assumeUserId),
            inboxId(data.inboxId),
            whiteListTargetIds(data.whiteListTargetIds)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            distributorModelId(std::move(data.distributorModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            assumeUserId(std::move(data.assumeUserId)),
            inboxId(std::move(data.inboxId)),
            whiteListTargetIds(std::move(data.whiteListTargetIds))
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
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->whiteListTargetIds, std::move(stringHolder));
                        }
                    }
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
    DistributorModel() :
        m_pData(nullptr)
    {}

    DistributorModel(const DistributorModel& distributorModel) :
        Gs2Object(distributorModel),
        m_pData(distributorModel.m_pData != nullptr ? new Data(*distributorModel.m_pData) : nullptr)
    {}

    DistributorModel(DistributorModel&& distributorModel) :
        Gs2Object(std::move(distributorModel)),
        m_pData(distributorModel.m_pData)
    {
        distributorModel.m_pData = nullptr;
    }

    ~DistributorModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DistributorModel& operator=(const DistributorModel& distributorModel)
    {
        Gs2Object::operator=(distributorModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*distributorModel.m_pData);

        return *this;
    }

    DistributorModel& operator=(DistributorModel&& distributorModel)
    {
        Gs2Object::operator=(std::move(distributorModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = distributorModel.m_pData;
        distributorModel.m_pData = nullptr;

        return *this;
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
     * ディストリビュータの種類 のGRNを設定
     *
     * @param distributorModelId ディストリビュータの種類 のGRN
     */
    DistributorModel& withDistributorModelId(const Char* distributorModelId)
    {
        setDistributorModelId(distributorModelId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ディストリビューターの種類名を設定
     *
     * @param name ディストリビューターの種類名
     */
    DistributorModel& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * ディストリビューターの種類のメタデータを設定
     *
     * @param metadata ディストリビューターの種類のメタデータ
     */
    DistributorModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
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
     * 所持品の配布処理の権限判定に使用する ユーザー のGRNを設定
     *
     * @param assumeUserId 所持品の配布処理の権限判定に使用する ユーザー のGRN
     */
    DistributorModel& withAssumeUserId(const Char* assumeUserId)
    {
        setAssumeUserId(assumeUserId);
        return *this;
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
     * 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRNを設定
     *
     * @param inboxId 所持品がキャパシティをオーバーしたときに転送する プレゼントボックス のGRN
     */
    DistributorModel& withInboxId(const Char* inboxId)
    {
        setInboxId(inboxId);
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
    DistributorModel& withWhiteListTargetIds(const List<StringHolder>& whiteListTargetIds)
    {
        setWhiteListTargetIds(whiteListTargetIds);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const DistributorModel& lhs, const DistributorModel& lhr)
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
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->assumeUserId != lhr.m_pData->assumeUserId)
        {
            return true;
        }
        if (lhs.m_pData->inboxId != lhr.m_pData->inboxId)
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

bool operator==(const DistributorModel& lhs, const DistributorModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DISTRIBUTOR_MODEL_DISTRIBUTORMODEL_HPP_