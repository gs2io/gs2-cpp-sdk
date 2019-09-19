

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

#ifndef GS2_EZ_EXPERIENCE_MODEL_EZTHRESHOLD_HPP_
#define GS2_EZ_EXPERIENCE_MODEL_EZTHRESHOLD_HPP_

#include <gs2/experience/model/Threshold.hpp>


namespace gs2 { namespace ez { namespace experience {

class EzThreshold : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ランクアップ閾値のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** ランクアップ経験値閾値リスト */
        gs2::optional<List<Int64>> values;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            metadata(data.metadata)
        {
            if (data.values)
            {
                values = data.values->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::experience::Threshold& threshold) :
            metadata(threshold.getMetadata()),
            values(threshold.getValues())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzThreshold() = default;
    EzThreshold(const EzThreshold& ezThreshold) = default;
    EzThreshold(EzThreshold&& ezThreshold) = default;
    ~EzThreshold() = default;

    EzThreshold(gs2::experience::Threshold threshold) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(threshold)
    {}

    EzThreshold& operator=(const EzThreshold& ezThreshold) = default;
    EzThreshold& operator=(EzThreshold&& ezThreshold) = default;

    EzThreshold deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzThreshold);
    }

    gs2::experience::Threshold ToModel() const
    {
        gs2::experience::Threshold threshold;
        threshold.setMetadata(getMetadata());
        threshold.setValues(getValues());
        return threshold;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<Int64>& getValues() const
    {
        return *ensureData().values;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setValues(List<Int64> values)
    {
        ensureData().values = std::move(values);
    }

    EzThreshold& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzThreshold& withValues(List<Int64> values)
    {
        setValues(std::move(values));
        return *this;
    }
};

}}}

#endif //GS2_EZ_EXPERIENCE_EZTHRESHOLD_HPP_