

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
    /** ディストリビューターの種類名 */
    gs2::optional<StringHolder> m_Name;
    /** ディストリビューターの種類のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** 所持品の配布処理の権限判定に使用する ユーザ のGRN */
    gs2::optional<StringHolder> m_AssumeUserId;
    /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
    gs2::optional<StringHolder> m_InboxNamespaceId;
    /** ディストリビューターを通して処理出来る対象のリソースGRNのホワイトリスト */
    gs2::optional<List<StringHolder>> m_WhiteListTargetIds;

public:
    EzDistributorModel() = default;

    EzDistributorModel(gs2::distributor::DistributorModel distributorModel) :
        m_Name(distributorModel.getName()),
        m_Metadata(distributorModel.getMetadata()),
        m_AssumeUserId(distributorModel.getAssumeUserId()),
        m_InboxNamespaceId(distributorModel.getInboxNamespaceId()),
        m_WhiteListTargetIds(distributorModel.getWhiteListTargetIds())
    {
    }

    gs2::distributor::DistributorModel ToModel() const
    {
        gs2::distributor::DistributorModel distributorModel;
        distributorModel.setName(*m_Name);
        distributorModel.setMetadata(*m_Metadata);
        distributorModel.setAssumeUserId(*m_AssumeUserId);
        distributorModel.setInboxNamespaceId(*m_InboxNamespaceId);
        distributorModel.setWhiteListTargetIds(*m_WhiteListTargetIds);
        return distributorModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const gs2::StringHolder& getAssumeUserId() const
    {
        return *m_AssumeUserId;
    }

    gs2::StringHolder& getAssumeUserId()
    {
        return *m_AssumeUserId;
    }

    const gs2::StringHolder& getInboxNamespaceId() const
    {
        return *m_InboxNamespaceId;
    }

    gs2::StringHolder& getInboxNamespaceId()
    {
        return *m_InboxNamespaceId;
    }

    const List<StringHolder>& getWhiteListTargetIds() const
    {
        return *m_WhiteListTargetIds;
    }

    List<StringHolder>& getWhiteListTargetIds()
    {
        return *m_WhiteListTargetIds;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setAssumeUserId(Char* assumeUserId)
    {
        m_AssumeUserId.emplace(assumeUserId);
    }

    void setInboxNamespaceId(Char* inboxNamespaceId)
    {
        m_InboxNamespaceId.emplace(inboxNamespaceId);
    }

    void setWhiteListTargetIds(const List<StringHolder>& whiteListTargetIds)
    {
        m_WhiteListTargetIds = whiteListTargetIds;
    }

    void setWhiteListTargetIds(List<StringHolder>&& whiteListTargetIds)
    {
        m_WhiteListTargetIds = std::move(whiteListTargetIds);
    }

    EzDistributorModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzDistributorModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzDistributorModel& withAssumeUserId(Char* assumeUserId)
    {
        setAssumeUserId(assumeUserId);
        return *this;
    }

    EzDistributorModel& withInboxNamespaceId(Char* inboxNamespaceId)
    {
        setInboxNamespaceId(inboxNamespaceId);
        return *this;
    }

    EzDistributorModel& withWhiteListTargetIds(const List<StringHolder>& whiteListTargetIds)
    {
        setWhiteListTargetIds(whiteListTargetIds);
        return *this;
    }

    EzDistributorModel& withWhiteListTargetIds(List<StringHolder>&& whiteListTargetIds)
    {
        setWhiteListTargetIds(std::move(whiteListTargetIds));
        return *this;
    }
};

}}}

#endif //GS2_EZ_DISTRIBUTOR_EZDISTRIBUTORMODEL_HPP_