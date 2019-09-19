

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

#ifndef GS2_EZ_DISTRIBUTOR_MODEL_EZDISTRIBUTORMODEL_HPP_
#define GS2_EZ_DISTRIBUTOR_MODEL_EZDISTRIBUTORMODEL_HPP_

#include <gs2/distributor/model/DistributorModel.hpp>


namespace gs2 { namespace ez { namespace distributor {

class EzDistributorModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ディストリビューターの種類名 */
        gs2::optional<StringHolder> name;
        /** ディストリビューターの種類のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 所持品の配布処理の権限判定に使用する ユーザ のGRN */
        gs2::optional<StringHolder> assumeUserId;
        /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
        gs2::optional<StringHolder> inboxNamespaceId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        gs2::optional<List<StringHolder>> whiteListTargetIds;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            assumeUserId(data.assumeUserId),
            inboxNamespaceId(data.inboxNamespaceId)
        {
            if (data.whiteListTargetIds)
            {
                whiteListTargetIds = data.whiteListTargetIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::distributor::DistributorModel& distributorModel) :
            name(distributorModel.getName()),
            metadata(distributorModel.getMetadata()),
            assumeUserId(distributorModel.getAssumeUserId()),
            inboxNamespaceId(distributorModel.getInboxNamespaceId()),
            whiteListTargetIds(distributorModel.getWhiteListTargetIds())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDistributorModel() = default;
    EzDistributorModel(const EzDistributorModel& ezDistributorModel) = default;
    EzDistributorModel(EzDistributorModel&& ezDistributorModel) = default;
    ~EzDistributorModel() = default;

    EzDistributorModel(gs2::distributor::DistributorModel distributorModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(distributorModel)
    {}

    EzDistributorModel& operator=(const EzDistributorModel& ezDistributorModel) = default;
    EzDistributorModel& operator=(EzDistributorModel&& ezDistributorModel) = default;

    EzDistributorModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDistributorModel);
    }

    gs2::distributor::DistributorModel ToModel() const
    {
        gs2::distributor::DistributorModel distributorModel;
        distributorModel.setName(getName());
        distributorModel.setMetadata(getMetadata());
        distributorModel.setAssumeUserId(getAssumeUserId());
        distributorModel.setInboxNamespaceId(getInboxNamespaceId());
        distributorModel.setWhiteListTargetIds(getWhiteListTargetIds());
        return distributorModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const StringHolder& getAssumeUserId() const
    {
        return *ensureData().assumeUserId;
    }

    const StringHolder& getInboxNamespaceId() const
    {
        return *ensureData().inboxNamespaceId;
    }

    const List<StringHolder>& getWhiteListTargetIds() const
    {
        return *ensureData().whiteListTargetIds;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setAssumeUserId(StringHolder assumeUserId)
    {
        ensureData().assumeUserId = std::move(assumeUserId);
    }

    void setInboxNamespaceId(StringHolder inboxNamespaceId)
    {
        ensureData().inboxNamespaceId = std::move(inboxNamespaceId);
    }

    void setWhiteListTargetIds(List<StringHolder> whiteListTargetIds)
    {
        ensureData().whiteListTargetIds = std::move(whiteListTargetIds);
    }

    EzDistributorModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzDistributorModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzDistributorModel& withAssumeUserId(StringHolder assumeUserId)
    {
        setAssumeUserId(std::move(assumeUserId));
        return *this;
    }

    EzDistributorModel& withInboxNamespaceId(StringHolder inboxNamespaceId)
    {
        setInboxNamespaceId(std::move(inboxNamespaceId));
        return *this;
    }

    EzDistributorModel& withWhiteListTargetIds(List<StringHolder> whiteListTargetIds)
    {
        setWhiteListTargetIds(std::move(whiteListTargetIds));
        return *this;
    }
};

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZDISTRIBUTORMODEL_HPP_