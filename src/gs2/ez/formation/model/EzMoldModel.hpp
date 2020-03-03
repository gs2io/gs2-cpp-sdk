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

#ifndef GS2_EZ_FORMATION_MODEL_EZMOLDMODEL_HPP_
#define GS2_EZ_FORMATION_MODEL_EZMOLDMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzFormModel.hpp"
#include <memory>


namespace gs2 {

namespace formation {

class MoldModel;

}

namespace ez { namespace formation {

class EzMoldModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォームの保存領域名 */
        gs2::optional<StringHolder> name;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;
        /** None */
        gs2::optional<EzFormModel> formModel;
        /** フォームを保存できる初期キャパシティ */
        gs2::optional<Int32> initialMaxCapacity;
        /** フォームを保存できるキャパシティ */
        gs2::optional<Int32> maxCapacity;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::MoldModel& moldModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMoldModel() = default;
    EzMoldModel(const EzMoldModel& ezMoldModel) = default;
    EzMoldModel(EzMoldModel&& ezMoldModel) = default;
    ~EzMoldModel() = default;

    EzMoldModel(gs2::formation::MoldModel moldModel);

    EzMoldModel& operator=(const EzMoldModel& ezMoldModel) = default;
    EzMoldModel& operator=(EzMoldModel&& ezMoldModel) = default;

    EzMoldModel deepCopy() const;

    gs2::formation::MoldModel ToModel() const;

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

    const EzFormModel& getFormModel() const
    {
        return *ensureData().formModel;
    }

    Int32 getInitialMaxCapacity() const
    {
        return *ensureData().initialMaxCapacity;
    }

    Int32 getMaxCapacity() const
    {
        return *ensureData().maxCapacity;
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

    void setFormModel(EzFormModel formModel)
    {
        ensureData().formModel = std::move(formModel);
    }

    void setInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        ensureData().initialMaxCapacity = initialMaxCapacity;
    }

    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity = maxCapacity;
    }

    EzMoldModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzMoldModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzMoldModel& withFormModel(EzFormModel formModel)
    {
        setFormModel(std::move(formModel));
        return *this;
    }

    EzMoldModel& withInitialMaxCapacity(Int32 initialMaxCapacity)
    {
        setInitialMaxCapacity(initialMaxCapacity);
        return *this;
    }

    EzMoldModel& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZMOLDMODEL_HPP_