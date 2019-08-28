

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
    /** ランクアップ閾値のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** ランクアップ経験値閾値リスト */
    gs2::optional<List<Int64>> m_Values;

public:
    EzThreshold() = default;

    EzThreshold(gs2::experience::Threshold threshold) :
        m_Metadata(threshold.getMetadata()),
        m_Values(threshold.getValues())
    {
    }

    gs2::experience::Threshold ToModel() const
    {
        gs2::experience::Threshold threshold;
        threshold.setMetadata(*m_Metadata);
        threshold.setValues(*m_Values);
        return threshold;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const List<Int64>& getValues() const
    {
        return *m_Values;
    }

    List<Int64>& getValues()
    {
        return *m_Values;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setValues(const List<Int64>& values)
    {
        m_Values = values;
    }

    void setValues(List<Int64>&& values)
    {
        m_Values = std::move(values);
    }

    EzThreshold& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzThreshold& withValues(const List<Int64>& values)
    {
        setValues(values);
        return *this;
    }

    EzThreshold& withValues(List<Int64>&& values)
    {
        setValues(std::move(values));
        return *this;
    }
};

}}}

#endif //GS2_EZ_EXPERIENCE_EZTHRESHOLD_HPP_