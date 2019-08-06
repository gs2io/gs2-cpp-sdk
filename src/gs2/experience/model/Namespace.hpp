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

#ifndef GS2_EXPERIENCE_MODEL_NAMESPACE_HPP_
#define GS2_EXPERIENCE_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace experience {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ネームスペース名 */
        optional<StringHolder> name;
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            namespaceId(data.namespaceId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            experienceCapScriptId(data.experienceCapScriptId),
            changeExperienceTriggerScriptId(data.changeExperienceTriggerScriptId),
            changeExperienceDoneTriggerScriptId(data.changeExperienceDoneTriggerScriptId),
            changeExperienceDoneTriggerNamespaceId(data.changeExperienceDoneTriggerNamespaceId),
            changeRankTriggerScriptId(data.changeRankTriggerScriptId),
            changeRankTriggerNamespaceId(data.changeRankTriggerNamespaceId),
            changeRankCapTriggerScriptId(data.changeRankCapTriggerScriptId),
            changeRankCapDoneTriggerScriptId(data.changeRankCapDoneTriggerScriptId),
            changeRankCapDoneTriggerNamespaceId(data.changeRankCapDoneTriggerNamespaceId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            namespaceId(std::move(data.namespaceId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            experienceCapScriptId(std::move(data.experienceCapScriptId)),
            changeExperienceTriggerScriptId(std::move(data.changeExperienceTriggerScriptId)),
            changeExperienceDoneTriggerScriptId(std::move(data.changeExperienceDoneTriggerScriptId)),
            changeExperienceDoneTriggerNamespaceId(std::move(data.changeExperienceDoneTriggerNamespaceId)),
            changeRankTriggerScriptId(std::move(data.changeRankTriggerScriptId)),
            changeRankTriggerNamespaceId(std::move(data.changeRankTriggerNamespaceId)),
            changeRankCapTriggerScriptId(std::move(data.changeRankCapTriggerScriptId)),
            changeRankCapDoneTriggerScriptId(std::move(data.changeRankCapDoneTriggerScriptId)),
            changeRankCapDoneTriggerNamespaceId(std::move(data.changeRankCapDoneTriggerNamespaceId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "namespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "experienceCapScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceCapScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeExperienceTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeExperienceDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeExperienceDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeExperienceDoneTriggerNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeRankTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeRankTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankTriggerNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeRankCapTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankCapTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeRankCapDoneTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankCapDoneTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "changeRankCapDoneTriggerNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->changeRankCapDoneTriggerNamespaceId.emplace(jsonValue.GetString());
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
    Namespace() :
        m_pData(nullptr)
    {}

    Namespace(const Namespace& namespace_) :
        Gs2Object(namespace_),
        m_pData(namespace_.m_pData != nullptr ? new Data(*namespace_.m_pData) : nullptr)
    {}

    Namespace(Namespace&& namespace_) :
        Gs2Object(std::move(namespace_)),
        m_pData(namespace_.m_pData)
    {
        namespace_.m_pData = nullptr;
    }

    ~Namespace()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Namespace& operator=(const Namespace& namespace_)
    {
        Gs2Object::operator=(namespace_);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*namespace_.m_pData);

        return *this;
    }

    Namespace& operator=(Namespace&& namespace_)
    {
        Gs2Object::operator=(std::move(namespace_));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = namespace_.m_pData;
        namespace_.m_pData = nullptr;

        return *this;
    }

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(const Char* namespaceId)
    {
        ensureData().namespaceId.emplace(namespaceId);
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(const Char* namespaceId)
    {
        setNamespaceId(namespaceId);
        return *this;
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
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    Namespace& withName(const Char* name)
    {
        setName(name);
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
    Namespace& withDescription(const Char* description)
    {
        setDescription(description);
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
    Namespace& withExperienceCapScriptId(const Char* experienceCapScriptId)
    {
        setExperienceCapScriptId(experienceCapScriptId);
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
    Namespace& withChangeExperienceTriggerScriptId(const Char* changeExperienceTriggerScriptId)
    {
        setChangeExperienceTriggerScriptId(changeExperienceTriggerScriptId);
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
    Namespace& withChangeExperienceDoneTriggerScriptId(const Char* changeExperienceDoneTriggerScriptId)
    {
        setChangeExperienceDoneTriggerScriptId(changeExperienceDoneTriggerScriptId);
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
    Namespace& withChangeExperienceDoneTriggerNamespaceId(const Char* changeExperienceDoneTriggerNamespaceId)
    {
        setChangeExperienceDoneTriggerNamespaceId(changeExperienceDoneTriggerNamespaceId);
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
    Namespace& withChangeRankTriggerScriptId(const Char* changeRankTriggerScriptId)
    {
        setChangeRankTriggerScriptId(changeRankTriggerScriptId);
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
    Namespace& withChangeRankTriggerNamespaceId(const Char* changeRankTriggerNamespaceId)
    {
        setChangeRankTriggerNamespaceId(changeRankTriggerNamespaceId);
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
    Namespace& withChangeRankCapTriggerScriptId(const Char* changeRankCapTriggerScriptId)
    {
        setChangeRankCapTriggerScriptId(changeRankCapTriggerScriptId);
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
    Namespace& withChangeRankCapDoneTriggerScriptId(const Char* changeRankCapDoneTriggerScriptId)
    {
        setChangeRankCapDoneTriggerScriptId(changeRankCapDoneTriggerScriptId);
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
    Namespace& withChangeRankCapDoneTriggerNamespaceId(const Char* changeRankCapDoneTriggerNamespaceId)
    {
        setChangeRankCapDoneTriggerNamespaceId(changeRankCapDoneTriggerNamespaceId);
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
    Namespace& withCreatedAt(Int64 createdAt)
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
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
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
        if (lhs.m_pData->experienceCapScriptId != lhr.m_pData->experienceCapScriptId)
        {
            return true;
        }
        if (lhs.m_pData->changeExperienceTriggerScriptId != lhr.m_pData->changeExperienceTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->changeExperienceDoneTriggerScriptId != lhr.m_pData->changeExperienceDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->changeExperienceDoneTriggerNamespaceId != lhr.m_pData->changeExperienceDoneTriggerNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->changeRankTriggerScriptId != lhr.m_pData->changeRankTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->changeRankTriggerNamespaceId != lhr.m_pData->changeRankTriggerNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->changeRankCapTriggerScriptId != lhr.m_pData->changeRankCapTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->changeRankCapDoneTriggerScriptId != lhr.m_pData->changeRankCapDoneTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->changeRankCapDoneTriggerNamespaceId != lhr.m_pData->changeRankCapDoneTriggerNamespaceId)
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

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_NAMESPACE_HPP_