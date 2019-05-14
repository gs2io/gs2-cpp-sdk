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

#ifndef GS2_EXPERIENCE_MODEL_EXPERIENCE_HPP_
#define GS2_EXPERIENCE_MODEL_EXPERIENCE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * 経験値
 *
 * @author Game Server Services, Inc.
 *
 */
class Experience : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値 のGRN */
        optional<StringHolder> experienceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
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
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            experienceId(data.experienceId),
            ownerId(data.ownerId),
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
            changeRankCapDoneTriggerQueueId(data.changeRankCapDoneTriggerQueueId),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            experienceId(std::move(data.experienceId)),
            ownerId(std::move(data.ownerId)),
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
            changeRankCapDoneTriggerQueueId(std::move(data.changeRankCapDoneTriggerQueueId)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "experienceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "experienceCapScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceCapScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeExperienceTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeExperienceDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeExperienceDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceDoneTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeRankTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeRankTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankTriggerQueueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeRankCapTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankCapTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeRankCapDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankCapDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "changeRankCapDoneTriggerQueueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankCapDoneTriggerQueueId.emplace(jsonValue.GetString());
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
    Experience() :
        m_pData(nullptr)
    {}

    Experience(const Experience& experience) :
        Gs2Object(experience),
        m_pData(experience.m_pData != nullptr ? new Data(*experience.m_pData) : nullptr)
    {}

    Experience(Experience&& experience) :
        Gs2Object(std::move(experience)),
        m_pData(experience.m_pData)
    {
        experience.m_pData = nullptr;
    }

    ~Experience()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Experience& operator=(const Experience& experience)
    {
        Gs2Object::operator=(experience);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*experience.m_pData);

        return *this;
    }

    Experience& operator=(Experience&& experience)
    {
        Gs2Object::operator=(std::move(experience));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = experience.m_pData;
        experience.m_pData = nullptr;

        return *this;
    }

    const Experience* operator->() const
    {
        return this;
    }

    Experience* operator->()
    {
        return this;
    }
    /**
     * 経験値 のGRNを取得
     *
     * @return 経験値 のGRN
     */
    const optional<StringHolder>& getExperienceId() const
    {
        return ensureData().experienceId;
    }

    /**
     * 経験値 のGRNを設定
     *
     * @param experienceId 経験値 のGRN
     */
    void setExperienceId(const Char* experienceId)
    {
        ensureData().experienceId.emplace(experienceId);
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

#endif //GS2_EXPERIENCE_MODEL_EXPERIENCE_HPP_