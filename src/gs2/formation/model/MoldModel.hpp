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

#ifndef GS2_FORMATION_MODEL_MOLDMODEL_HPP_
#define GS2_FORMATION_MODEL_MOLDMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "FormModel.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace formation {

/**
 * フォームの保存領域
 *
 * @author Game Server Services, Inc.
 *
 */
class MoldModel : public Gs2Object
{
    friend bool operator!=(const MoldModel& lhs, const MoldModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** フォームの保存領域マスター */
        optional<StringHolder> moldModelId;
        /** フォームの保存領域名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** None */
        optional<FormModel> formModel;
        /** フォームを保存できる初期キャパシティ */
        optional<Int32> initialMaxCapacity;
        /** フォームを保存できるキャパシティ */
        optional<Int32> maxCapacity;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            moldModelId(data.moldModelId),
            name(data.name),
            metadata(data.metadata),
            initialMaxCapacity(data.initialMaxCapacity),
            maxCapacity(data.maxCapacity)
        {
            if (data.formModel)
            {
                formModel = data.formModel->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "moldModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->moldModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "formModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->formModel.emplace();
                    detail::json::JsonParser::parse(&this->formModel->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "initialMaxCapacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->initialMaxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "maxCapacity") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->maxCapacity = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    MoldModel() = default;
    MoldModel(const MoldModel& moldModel) = default;
    MoldModel(MoldModel&& moldModel) = default;
    ~MoldModel() = default;

    MoldModel& operator=(const MoldModel& moldModel) = default;
    MoldModel& operator=(MoldModel&& moldModel) = default;

    MoldModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(MoldModel);
    }

    const MoldModel* operator->() const
    {
        return this;
    }

    MoldModel* operator->()
    {
        return this;
    }
    /**
     * フォームの保存領域マスターを取得
     *
     * @return フォームの保存領域マスター
     */
    const optional<StringHolder>& getMoldModelId() const
    {
        return ensureData().moldModelId;
    }

    /**
     * フォームの保存領域マスターを設定
     *
     * @param moldModelId フォームの保存領域マスター
     */
    void setMoldModelId(StringHolder moldModelId)
    {
        ensureData().moldModelId.emplace(std::move(moldModelId));
    }

    /**
     * フォームの保存領域マスターを設定
     *
     * @param moldModelId フォームの保存領域マスター
     */
    MoldModel& withMoldModelId(StringHolder moldModelId)
    {
        setMoldModelId(std::move(moldModelId));
        return *this;
    }

    /**
     * フォームの保存領域名を取得
     *
     * @return フォームの保存領域名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * フォームの保存領域名を設定
     *
     * @param name フォームの保存領域名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * フォームの保存領域名を設定
     *
     * @param name フォームの保存領域名
     */
    MoldModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    MoldModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<FormModel>& getFormModel() const
    {
        return ensureData().formModel;
    }

    /**
     * Noneを設定
     *
     * @param formModel None
     */
    void setFormModel(FormModel formModel)
    {
        ensureData().formModel.emplace(std::move(formModel));
    }

    /**
     * Noneを設定
     *
     * @param formModel None
     */
    MoldModel& withFormModel(FormModel formModel)
    {
        setFormModel(std::move(formModel));
        return *this;
    }

    /**
     * フォームを保存できる初期キャパシティを取得
     *
     * @return フォームを保存できる初期キャパシティ
     */
    const optional<Int32>& getInitialMaxCapacity() const
    {
        return ensureData().initialMaxCapacity;
    }

    /**
     * フォームを保存できる初期キャパシティを設定
     *
     * @param initialMaxCapacity フォームを保存できる初期キャパシティ
     */
    void setInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        ensureData().initialMaxCapacity.emplace(initialMaxCapacity);
    }

    /**
     * フォームを保存できる初期キャパシティを設定
     *
     * @param initialMaxCapacity フォームを保存できる初期キャパシティ
     */
    MoldModel& withInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        setInitialMaxCapacity(initialMaxCapacity);
        return *this;
    }

    /**
     * フォームを保存できるキャパシティを取得
     *
     * @return フォームを保存できるキャパシティ
     */
    const optional<Int32>& getMaxCapacity() const
    {
        return ensureData().maxCapacity;
    }

    /**
     * フォームを保存できるキャパシティを設定
     *
     * @param maxCapacity フォームを保存できるキャパシティ
     */
    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
    }

    /**
     * フォームを保存できるキャパシティを設定
     *
     * @param maxCapacity フォームを保存できるキャパシティ
     */
    MoldModel& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const MoldModel& lhs, const MoldModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->moldModelId != lhr.m_pData->moldModelId)
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
        if (lhs.m_pData->formModel != lhr.m_pData->formModel)
        {
            return true;
        }
        if (lhs.m_pData->initialMaxCapacity != lhr.m_pData->initialMaxCapacity)
        {
            return true;
        }
        if (lhs.m_pData->maxCapacity != lhr.m_pData->maxCapacity)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const MoldModel& lhs, const MoldModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FORMATION_MODEL_MOLDMODEL_HPP_