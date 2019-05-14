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

#ifndef GS2_EXPERIENCE_CONTROL_CREATEEXPERIENCEREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_CREATEEXPERIENCEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * 経験値を新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateExperienceRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 経験値名 */
        optional<StringHolder> name;
        /** 経験値の説明 */
        optional<StringHolder> description;
        /** ランクキャップ取得時 に実行されるスクリプト のGRN */
        optional<StringHolder> experienceCapScriptId;
        /** 経験値変化時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeExperienceTriggerScriptId;
        /** 経験値変化完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeExperienceDoneTriggerScriptId;
        /** 経験値変化完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> changeExperienceDoneTriggerQueueId;
        /** ランク変化時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeRankTriggerScriptId;
        /** ランク変化時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> changeRankTriggerQueueId;
        /** ランクキャップ変化時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeRankCapTriggerScriptId;
        /** ランクキャップ変化完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> changeRankCapDoneTriggerScriptId;
        /** ランクキャップ変化完了時 にジョブが登録されるキュー のGRN */
        optional<StringHolder> changeRankCapDoneTriggerQueueId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            experienceCapScriptId(data.experienceCapScriptId),
            changeExperienceTriggerScriptId(data.changeExperienceTriggerScriptId),
            changeExperienceDoneTriggerScriptId(data.changeExperienceDoneTriggerScriptId),
            changeExperienceDoneTriggerQueueId(data.changeExperienceDoneTriggerQueueId),
            changeRankTriggerScriptId(data.changeRankTriggerScriptId),
            changeRankTriggerQueueId(data.changeRankTriggerQueueId),
            changeRankCapTriggerScriptId(data.changeRankCapTriggerScriptId),
            changeRankCapDoneTriggerScriptId(data.changeRankCapDoneTriggerScriptId),
            changeRankCapDoneTriggerQueueId(data.changeRankCapDoneTriggerQueueId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            experienceCapScriptId(std::move(data.experienceCapScriptId)),
            changeExperienceTriggerScriptId(std::move(data.changeExperienceTriggerScriptId)),
            changeExperienceDoneTriggerScriptId(std::move(data.changeExperienceDoneTriggerScriptId)),
            changeExperienceDoneTriggerQueueId(std::move(data.changeExperienceDoneTriggerQueueId)),
            changeRankTriggerScriptId(std::move(data.changeRankTriggerScriptId)),
            changeRankTriggerQueueId(std::move(data.changeRankTriggerQueueId)),
            changeRankCapTriggerScriptId(std::move(data.changeRankCapTriggerScriptId)),
            changeRankCapDoneTriggerScriptId(std::move(data.changeRankCapDoneTriggerScriptId)),
            changeRankCapDoneTriggerQueueId(std::move(data.changeRankCapDoneTriggerQueueId))
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
    CreateExperienceRequest() :
        m_pData(nullptr)
    {}

    CreateExperienceRequest(const CreateExperienceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateExperienceRequest(CreateExperienceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateExperienceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateExperienceRequest& operator=(const CreateExperienceRequest& createExperienceRequest)
    {
        Gs2BasicRequest::operator=(createExperienceRequest);
        Gs2Experience::operator=(createExperienceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createExperienceRequest.m_pData);

        return *this;
    }

    CreateExperienceRequest& operator=(CreateExperienceRequest&& createExperienceRequest)
    {
        Gs2BasicRequest::operator=(std::move(createExperienceRequest));
        Gs2Experience::operator=(std::move(createExperienceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createExperienceRequest.m_pData;
        createExperienceRequest.m_pData = nullptr;

        return *this;
    }

    const CreateExperienceRequest* operator->() const
    {
        return this;
    }

    CreateExperienceRequest* operator->()
    {
        return this;
    }
    /**
     * 経験値名を取得
     *
     * @return 経験値名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 経験値名を設定
     *
     * @param name 経験値名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 経験値名を設定
     *
     * @param name 経験値名
     */
    CreateExperienceRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * 経験値の説明を取得
     *
     * @return 経験値の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 経験値の説明を設定
     *
     * @param description 経験値の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 経験値の説明を設定
     *
     * @param description 経験値の説明
     */
    CreateExperienceRequest& withDescription(const Char* description)
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
    CreateExperienceRequest& withExperienceCapScriptId(const Char* experienceCapScriptId)
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
    CreateExperienceRequest& withChangeExperienceTriggerScriptId(const Char* changeExperienceTriggerScriptId)
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
    CreateExperienceRequest& withChangeExperienceDoneTriggerScriptId(const Char* changeExperienceDoneTriggerScriptId)
    {
        ensureData().changeExperienceDoneTriggerScriptId.emplace(changeExperienceDoneTriggerScriptId);
        return *this;
    }

    /**
     * 経験値変化完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return 経験値変化完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getChangeExperienceDoneTriggerQueueId() const
    {
        return ensureData().changeExperienceDoneTriggerQueueId;
    }

    /**
     * 経験値変化完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param changeExperienceDoneTriggerQueueId 経験値変化完了時 にジョブが登録されるキュー のGRN
     */
    void setChangeExperienceDoneTriggerQueueId(const Char* changeExperienceDoneTriggerQueueId)
    {
        ensureData().changeExperienceDoneTriggerQueueId.emplace(changeExperienceDoneTriggerQueueId);
    }

    /**
     * 経験値変化完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param changeExperienceDoneTriggerQueueId 経験値変化完了時 にジョブが登録されるキュー のGRN
     */
    CreateExperienceRequest& withChangeExperienceDoneTriggerQueueId(const Char* changeExperienceDoneTriggerQueueId)
    {
        ensureData().changeExperienceDoneTriggerQueueId.emplace(changeExperienceDoneTriggerQueueId);
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
    CreateExperienceRequest& withChangeRankTriggerScriptId(const Char* changeRankTriggerScriptId)
    {
        ensureData().changeRankTriggerScriptId.emplace(changeRankTriggerScriptId);
        return *this;
    }

    /**
     * ランク変化時 にジョブが登録されるキュー のGRNを取得
     *
     * @return ランク変化時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getChangeRankTriggerQueueId() const
    {
        return ensureData().changeRankTriggerQueueId;
    }

    /**
     * ランク変化時 にジョブが登録されるキュー のGRNを設定
     *
     * @param changeRankTriggerQueueId ランク変化時 にジョブが登録されるキュー のGRN
     */
    void setChangeRankTriggerQueueId(const Char* changeRankTriggerQueueId)
    {
        ensureData().changeRankTriggerQueueId.emplace(changeRankTriggerQueueId);
    }

    /**
     * ランク変化時 にジョブが登録されるキュー のGRNを設定
     *
     * @param changeRankTriggerQueueId ランク変化時 にジョブが登録されるキュー のGRN
     */
    CreateExperienceRequest& withChangeRankTriggerQueueId(const Char* changeRankTriggerQueueId)
    {
        ensureData().changeRankTriggerQueueId.emplace(changeRankTriggerQueueId);
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
    CreateExperienceRequest& withChangeRankCapTriggerScriptId(const Char* changeRankCapTriggerScriptId)
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
    CreateExperienceRequest& withChangeRankCapDoneTriggerScriptId(const Char* changeRankCapDoneTriggerScriptId)
    {
        ensureData().changeRankCapDoneTriggerScriptId.emplace(changeRankCapDoneTriggerScriptId);
        return *this;
    }

    /**
     * ランクキャップ変化完了時 にジョブが登録されるキュー のGRNを取得
     *
     * @return ランクキャップ変化完了時 にジョブが登録されるキュー のGRN
     */
    const optional<StringHolder>& getChangeRankCapDoneTriggerQueueId() const
    {
        return ensureData().changeRankCapDoneTriggerQueueId;
    }

    /**
     * ランクキャップ変化完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param changeRankCapDoneTriggerQueueId ランクキャップ変化完了時 にジョブが登録されるキュー のGRN
     */
    void setChangeRankCapDoneTriggerQueueId(const Char* changeRankCapDoneTriggerQueueId)
    {
        ensureData().changeRankCapDoneTriggerQueueId.emplace(changeRankCapDoneTriggerQueueId);
    }

    /**
     * ランクキャップ変化完了時 にジョブが登録されるキュー のGRNを設定
     *
     * @param changeRankCapDoneTriggerQueueId ランクキャップ変化完了時 にジョブが登録されるキュー のGRN
     */
    CreateExperienceRequest& withChangeRankCapDoneTriggerQueueId(const Char* changeRankCapDoneTriggerQueueId)
    {
        ensureData().changeRankCapDoneTriggerQueueId.emplace(changeRankCapDoneTriggerQueueId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateExperienceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateExperienceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateExperienceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateExperienceRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_EXPERIENCE_CONTROL_CREATEEXPERIENCEREQUEST_HPP_