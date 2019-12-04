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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace distributor {

class DistributorModel;

}

namespace ez { namespace distributor {

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
        /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
        gs2::optional<StringHolder> inboxNamespaceId;
        /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
        gs2::optional<List<StringHolder>> whiteListTargetIds;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::distributor::DistributorModel& distributorModel);
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

    EzDistributorModel(gs2::distributor::DistributorModel distributorModel);

    EzDistributorModel& operator=(const EzDistributorModel& ezDistributorModel) = default;
    EzDistributorModel& operator=(EzDistributorModel&& ezDistributorModel) = default;

    EzDistributorModel deepCopy() const;

    gs2::distributor::DistributorModel ToModel() const;

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