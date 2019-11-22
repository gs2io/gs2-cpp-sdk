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

#ifndef GS2_DEPLOY_MODEL_OUTPUTFIELD_HPP_
#define GS2_DEPLOY_MODEL_OUTPUTFIELD_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace deploy {

/**
 * Output に記録するフィールド
 *
 * @author Game Server Services, Inc.
 *
 */
class OutputField : public Gs2Object
{
    friend bool operator!=(const OutputField& lhs, const OutputField& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 名前 */
        optional<StringHolder> name;
        /** フィールド名 */
        optional<StringHolder> fieldName;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    OutputField() = default;
    OutputField(const OutputField& outputField) = default;
    OutputField(OutputField&& outputField) = default;
    ~OutputField() = default;

    OutputField& operator=(const OutputField& outputField) = default;
    OutputField& operator=(OutputField&& outputField) = default;

    OutputField deepCopy() const;

    const OutputField* operator->() const
    {
        return this;
    }

    OutputField* operator->()
    {
        return this;
    }
    /**
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 名前を設定
     *
     * @param name 名前
     */
    OutputField& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * フィールド名を取得
     *
     * @return フィールド名
     */
    const optional<StringHolder>& getFieldName() const
    {
        return ensureData().fieldName;
    }

    /**
     * フィールド名を設定
     *
     * @param fieldName フィールド名
     */
    void setFieldName(StringHolder fieldName)
    {
        ensureData().fieldName.emplace(std::move(fieldName));
    }

    /**
     * フィールド名を設定
     *
     * @param fieldName フィールド名
     */
    OutputField& withFieldName(StringHolder fieldName)
    {
        setFieldName(std::move(fieldName));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const OutputField& lhs, const OutputField& lhr);

inline bool operator==(const OutputField& lhs, const OutputField& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_OUTPUTFIELD_HPP_