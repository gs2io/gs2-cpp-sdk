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

#ifndef GS2_EXPERIENCE_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ランクキャップ取得時 に実行されるスクリプト のGRN */
        optional<StringHolder> experienceCapScriptId;
        /** 経験値変化時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeExperienceTriggerScriptId;
        /** 経験値変化完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeExperienceDoneTriggerScriptId;
        /** 経験値変化完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> changeExperienceDoneTriggerNamespaceId;
        /** ランク変化時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeRankTriggerScriptId;
        /** ランク変化時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> changeRankTriggerNamespaceId;
        /** ランクキャップ変化時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeRankCapTriggerScriptId;
        /** ランクキャップ変化完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeRankCapDoneTriggerScriptId;
        /** ランクキャップ変化完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> changeRankCapDoneTriggerNamespaceId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            experienceCapScriptId(data.experienceCapScriptId),
            changeExperienceTriggerScriptId(data.changeExperienceTriggerScriptId),
            changeExperienceDoneTriggerScriptId(data.changeExperienceDoneTriggerScriptId),
            changeExperienceDoneTriggerNamespaceId(data.changeExperienceDoneTriggerNamespaceId),
            changeRankTriggerScriptId(data.changeRankTriggerScriptId),
            changeRankTriggerNamespaceId(data.changeRankTriggerNamespaceId),
            changeRankCapTriggerScriptId(data.changeRankCapTriggerScriptId),
            changeRankCapDoneTriggerScriptId(data.changeRankCapDoneTriggerScriptId),
            changeRankCapDoneTriggerNamespaceId(data.changeRankCapDoneTriggerNamespaceId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            experienceCapScriptId(std::move(data.experienceCapScriptId)),
            changeExperienceTriggerScriptId(std::move(data.changeExperienceTriggerScriptId)),
            changeExperienceDoneTriggerScriptId(std::move(data.changeExperienceDoneTriggerScriptId)),
            changeExperienceDoneTriggerNamespaceId(std::move(data.changeExperienceDoneTriggerNamespaceId)),
            changeRankTriggerScriptId(std::move(data.changeRankTriggerScriptId)),
            changeRankTriggerNamespaceId(std::move(data.changeRankTriggerNamespaceId)),
            changeRankCapTriggerScriptId(std::move(data.changeRankCapTriggerScriptId)),
            changeRankCapDoneTriggerScriptId(std::move(data.changeRankCapDoneTriggerScriptId)),
            changeRankCapDoneTriggerNamespaceId(std::move(data.changeRankCapDoneTriggerNamespaceId))
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
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
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
        Gs2Experience::operator=(updateNamespaceRequest);

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
        Gs2Experience::operator=(std::move(updateNamespaceRequest));

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
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
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
     * ランクキャップ取得時 に実行されるスクリプト のGRNを取得
     *
     * @return ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getExperienceCapScriptId() const
    {
        return ensureData().experienceCapScriptId;
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを設定
     *
     * @param experienceCapScriptId ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    void setExperienceCapScriptId(const Char* experienceCapScriptId)
    {
        ensureData().experienceCapScriptId.emplace(experienceCapScriptId);
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを設定
     *
     * @param experienceCapScriptId ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withExperienceCapScriptId(const Char* experienceCapScriptId)
    {
        ensureData().experienceCapScriptId.emplace(experienceCapScriptId);
        return *this;
    }

    /**
     * 経験値変化時 に実行されるスクリプト のGRNを取得
     *
     * @return 経験値変化時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getChangeExperienceTriggerScriptId() const
    {
        return ensureData().changeExperienceTriggerScriptId;
    }

    /**
     * 経験値変化時 に実行されるスクリプト のGRNを設定
     *
     * @param changeExperienceTriggerScriptId 経験値変化時 に実行されるスクリプト のGRN
     */
    void setChangeExperienceTriggerScriptId(const Char* changeExperienceTriggerScriptId)
    {
        ensureData().changeExperienceTriggerScriptId.emplace(changeExperienceTriggerScriptId);
    }

    /**
     * 経験値変化時 に実行されるスクリプト のGRNを設定
     *
     * @param changeExperienceTriggerScriptId 経験値変化時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withChangeExperienceTriggerScriptId(const Char* changeExperienceTriggerScriptId)
    {
        ensureData().changeExperienceTriggerScriptId.emplace(changeExperienceTriggerScriptId);
        return *this;
    }

    /**
     * 経験値変化完了時 に実行されるスクリプト のGRNを取得
     *
     * @return 経験値変化完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getChangeExperienceDoneTriggerScriptId() const
    {
        return ensureData().changeExperienceDoneTriggerScriptId;
    }

    /**
     * 経験値変化完了時 に実行されるスクリプト のGRNを設定
     *
     * @param changeExperienceDoneTriggerScriptId 経験値変化完了時 に実行されるスクリプト のGRN
     */
    void setChangeExperienceDoneTriggerScriptId(const Char* changeExperienceDoneTriggerScriptId)
    {
        ensureData().changeExperienceDoneTriggerScriptId.emplace(changeExperienceDoneTriggerScriptId);
    }

    /**
     * 経験値変化完了時 に実行されるスクリプト のGRNを設定
     *
     * @param changeExperienceDoneTriggerScriptId 経験値変化完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withChangeExperienceDoneTriggerScriptId(const Char* changeExperienceDoneTriggerScriptId)
    {
        ensureData().changeExperienceDoneTriggerScriptId.emplace(changeExperienceDoneTriggerScriptId);
        return *this;
    }

    /**
     * 経験値変化完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return 経験値変化完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getChangeExperienceDoneTriggerNamespaceId() const
    {
        return ensureData().changeExperienceDoneTriggerNamespaceId;
    }

    /**
     * 経験値変化完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param changeExperienceDoneTriggerNamespaceId 経験値変化完了時 にジョブが登録されるネームスペース のGRN
     */
    void setChangeExperienceDoneTriggerNamespaceId(const Char* changeExperienceDoneTriggerNamespaceId)
    {
        ensureData().changeExperienceDoneTriggerNamespaceId.emplace(changeExperienceDoneTriggerNamespaceId);
    }

    /**
     * 経験値変化完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param changeExperienceDoneTriggerNamespaceId 経験値変化完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withChangeExperienceDoneTriggerNamespaceId(const Char* changeExperienceDoneTriggerNamespaceId)
    {
        ensureData().changeExperienceDoneTriggerNamespaceId.emplace(changeExperienceDoneTriggerNamespaceId);
        return *this;
    }

    /**
     * ランク変化時 に実行されるスクリプト のGRNを取得
     *
     * @return ランク変化時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getChangeRankTriggerScriptId() const
    {
        return ensureData().changeRankTriggerScriptId;
    }

    /**
     * ランク変化時 に実行されるスクリプト のGRNを設定
     *
     * @param changeRankTriggerScriptId ランク変化時 に実行されるスクリプト のGRN
     */
    void setChangeRankTriggerScriptId(const Char* changeRankTriggerScriptId)
    {
        ensureData().changeRankTriggerScriptId.emplace(changeRankTriggerScriptId);
    }

    /**
     * ランク変化時 に実行されるスクリプト のGRNを設定
     *
     * @param changeRankTriggerScriptId ランク変化時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withChangeRankTriggerScriptId(const Char* changeRankTriggerScriptId)
    {
        ensureData().changeRankTriggerScriptId.emplace(changeRankTriggerScriptId);
        return *this;
    }

    /**
     * ランク変化時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return ランク変化時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getChangeRankTriggerNamespaceId() const
    {
        return ensureData().changeRankTriggerNamespaceId;
    }

    /**
     * ランク変化時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param changeRankTriggerNamespaceId ランク変化時 にジョブが登録されるネームスペース のGRN
     */
    void setChangeRankTriggerNamespaceId(const Char* changeRankTriggerNamespaceId)
    {
        ensureData().changeRankTriggerNamespaceId.emplace(changeRankTriggerNamespaceId);
    }

    /**
     * ランク変化時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param changeRankTriggerNamespaceId ランク変化時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withChangeRankTriggerNamespaceId(const Char* changeRankTriggerNamespaceId)
    {
        ensureData().changeRankTriggerNamespaceId.emplace(changeRankTriggerNamespaceId);
        return *this;
    }

    /**
     * ランクキャップ変化時 に実行されるスクリプト のGRNを取得
     *
     * @return ランクキャップ変化時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getChangeRankCapTriggerScriptId() const
    {
        return ensureData().changeRankCapTriggerScriptId;
    }

    /**
     * ランクキャップ変化時 に実行されるスクリプト のGRNを設定
     *
     * @param changeRankCapTriggerScriptId ランクキャップ変化時 に実行されるスクリプト のGRN
     */
    void setChangeRankCapTriggerScriptId(const Char* changeRankCapTriggerScriptId)
    {
        ensureData().changeRankCapTriggerScriptId.emplace(changeRankCapTriggerScriptId);
    }

    /**
     * ランクキャップ変化時 に実行されるスクリプト のGRNを設定
     *
     * @param changeRankCapTriggerScriptId ランクキャップ変化時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withChangeRankCapTriggerScriptId(const Char* changeRankCapTriggerScriptId)
    {
        ensureData().changeRankCapTriggerScriptId.emplace(changeRankCapTriggerScriptId);
        return *this;
    }

    /**
     * ランクキャップ変化完了時 に実行されるスクリプト のGRNを取得
     *
     * @return ランクキャップ変化完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getChangeRankCapDoneTriggerScriptId() const
    {
        return ensureData().changeRankCapDoneTriggerScriptId;
    }

    /**
     * ランクキャップ変化完了時 に実行されるスクリプト のGRNを設定
     *
     * @param changeRankCapDoneTriggerScriptId ランクキャップ変化完了時 に実行されるスクリプト のGRN
     */
    void setChangeRankCapDoneTriggerScriptId(const Char* changeRankCapDoneTriggerScriptId)
    {
        ensureData().changeRankCapDoneTriggerScriptId.emplace(changeRankCapDoneTriggerScriptId);
    }

    /**
     * ランクキャップ変化完了時 に実行されるスクリプト のGRNを設定
     *
     * @param changeRankCapDoneTriggerScriptId ランクキャップ変化完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withChangeRankCapDoneTriggerScriptId(const Char* changeRankCapDoneTriggerScriptId)
    {
        ensureData().changeRankCapDoneTriggerScriptId.emplace(changeRankCapDoneTriggerScriptId);
        return *this;
    }

    /**
     * ランクキャップ変化完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return ランクキャップ変化完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getChangeRankCapDoneTriggerNamespaceId() const
    {
        return ensureData().changeRankCapDoneTriggerNamespaceId;
    }

    /**
     * ランクキャップ変化完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param changeRankCapDoneTriggerNamespaceId ランクキャップ変化完了時 にジョブが登録されるネームスペース のGRN
     */
    void setChangeRankCapDoneTriggerNamespaceId(const Char* changeRankCapDoneTriggerNamespaceId)
    {
        ensureData().changeRankCapDoneTriggerNamespaceId.emplace(changeRankCapDoneTriggerNamespaceId);
    }

    /**
     * ランクキャップ変化完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param changeRankCapDoneTriggerNamespaceId ランクキャップ変化完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withChangeRankCapDoneTriggerNamespaceId(const Char* changeRankCapDoneTriggerNamespaceId)
    {
        ensureData().changeRankCapDoneTriggerNamespaceId.emplace(changeRankCapDoneTriggerNamespaceId);
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

#endif //GS2_EXPERIENCE_CONTROL_UPDATENAMESPACEREQUEST_HPP_