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

#ifndef GS2_EXPERIENCE_MODEL_STATUS_HPP_
#define GS2_EXPERIENCE_MODEL_STATUS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace experience {

/**
 * ステータス
 *
 * @author Game Server Services, Inc.
 *
 */
class Status : public Gs2Object
{
    friend bool operator!=(const Status& lhs, const Status& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ステータス のGRN */
        optional<StringHolder> statusId;
        /** 経験値の種類名 */
        optional<StringHolder> experienceModelName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** プロパティID */
        optional<StringHolder> propertyId;
        /** 累計獲得経験値 */
        optional<Int64> experienceValue;
        /** 累計獲得経験値 */
        optional<Int64> rankValue;
        /** 現在のランクキャップ */
        optional<Int64> rankCapValue;
        /** 作成日時 */
        optional<Int64> createAt;
        /** 最終更新日時 */
        optional<Int64> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            statusId(data.statusId),
            experienceModelName(data.experienceModelName),
            userId(data.userId),
            propertyId(data.propertyId),
            experienceValue(data.experienceValue),
            rankValue(data.rankValue),
            rankCapValue(data.rankCapValue),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            statusId(std::move(data.statusId)),
            experienceModelName(std::move(data.experienceModelName)),
            userId(std::move(data.userId)),
            propertyId(std::move(data.propertyId)),
            experienceValue(std::move(data.experienceValue)),
            rankValue(std::move(data.rankValue)),
            rankCapValue(std::move(data.rankCapValue)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "statusId") == 0) {
                if (jsonValue.IsString())
                {
                    this->statusId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "experienceModelName") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceModelName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "propertyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->propertyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "experienceValue") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->experienceValue = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "rankValue") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->rankValue = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "rankCapValue") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->rankCapValue = jsonValue.GetInt64();
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
    Status() :
        m_pData(nullptr)
    {}

    Status(const Status& status) :
        Gs2Object(status),
        m_pData(status.m_pData != nullptr ? new Data(*status.m_pData) : nullptr)
    {}

    Status(Status&& status) :
        Gs2Object(std::move(status)),
        m_pData(status.m_pData)
    {
        status.m_pData = nullptr;
    }

    ~Status()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Status& operator=(const Status& status)
    {
        Gs2Object::operator=(status);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*status.m_pData);

        return *this;
    }

    Status& operator=(Status&& status)
    {
        Gs2Object::operator=(std::move(status));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = status.m_pData;
        status.m_pData = nullptr;

        return *this;
    }

    const Status* operator->() const
    {
        return this;
    }

    Status* operator->()
    {
        return this;
    }
    /**
     * ステータス のGRNを取得
     *
     * @return ステータス のGRN
     */
    const optional<StringHolder>& getStatusId() const
    {
        return ensureData().statusId;
    }

    /**
     * ステータス のGRNを設定
     *
     * @param statusId ステータス のGRN
     */
    void setStatusId(const Char* statusId)
    {
        ensureData().statusId.emplace(statusId);
    }

    /**
     * ステータス のGRNを設定
     *
     * @param statusId ステータス のGRN
     */
    Status& withStatusId(const Char* statusId)
    {
        setStatusId(statusId);
        return *this;
    }

    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getExperienceModelName() const
    {
        return ensureData().experienceModelName;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    void setExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    Status& withExperienceModelName(const Char* experienceModelName)
    {
        setExperienceModelName(experienceModelName);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Status& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * プロパティIDを取得
     *
     * @return プロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    void setPropertyId(const Char* propertyId)
    {
        ensureData().propertyId.emplace(propertyId);
    }

    /**
     * プロパティIDを設定
     *
     * @param propertyId プロパティID
     */
    Status& withPropertyId(const Char* propertyId)
    {
        setPropertyId(propertyId);
        return *this;
    }

    /**
     * 累計獲得経験値を取得
     *
     * @return 累計獲得経験値
     */
    const optional<Int64>& getExperienceValue() const
    {
        return ensureData().experienceValue;
    }

    /**
     * 累計獲得経験値を設定
     *
     * @param experienceValue 累計獲得経験値
     */
    void setExperienceValue(Int64 experienceValue)
    {
        ensureData().experienceValue.emplace(experienceValue);
    }

    /**
     * 累計獲得経験値を設定
     *
     * @param experienceValue 累計獲得経験値
     */
    Status& withExperienceValue(Int64 experienceValue)
    {
        setExperienceValue(experienceValue);
        return *this;
    }

    /**
     * 累計獲得経験値を取得
     *
     * @return 累計獲得経験値
     */
    const optional<Int64>& getRankValue() const
    {
        return ensureData().rankValue;
    }

    /**
     * 累計獲得経験値を設定
     *
     * @param rankValue 累計獲得経験値
     */
    void setRankValue(Int64 rankValue)
    {
        ensureData().rankValue.emplace(rankValue);
    }

    /**
     * 累計獲得経験値を設定
     *
     * @param rankValue 累計獲得経験値
     */
    Status& withRankValue(Int64 rankValue)
    {
        setRankValue(rankValue);
        return *this;
    }

    /**
     * 現在のランクキャップを取得
     *
     * @return 現在のランクキャップ
     */
    const optional<Int64>& getRankCapValue() const
    {
        return ensureData().rankCapValue;
    }

    /**
     * 現在のランクキャップを設定
     *
     * @param rankCapValue 現在のランクキャップ
     */
    void setRankCapValue(Int64 rankCapValue)
    {
        ensureData().rankCapValue.emplace(rankCapValue);
    }

    /**
     * 現在のランクキャップを設定
     *
     * @param rankCapValue 現在のランクキャップ
     */
    Status& withRankCapValue(Int64 rankCapValue)
    {
        setRankCapValue(rankCapValue);
        return *this;
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
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    Status& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
        return *this;
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

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    Status& withUpdateAt(Int64 updateAt)
    {
        setUpdateAt(updateAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Status& lhs, const Status& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->statusId != lhr.m_pData->statusId)
        {
            return true;
        }
        if (lhs.m_pData->experienceModelName != lhr.m_pData->experienceModelName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->propertyId != lhr.m_pData->propertyId)
        {
            return true;
        }
        if (lhs.m_pData->experienceValue != lhr.m_pData->experienceValue)
        {
            return true;
        }
        if (lhs.m_pData->rankValue != lhr.m_pData->rankValue)
        {
            return true;
        }
        if (lhs.m_pData->rankCapValue != lhr.m_pData->rankCapValue)
        {
            return true;
        }
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
        {
            return true;
        }
        if (lhs.m_pData->updateAt != lhr.m_pData->updateAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Status& lhs, const Status& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_STATUS_HPP_