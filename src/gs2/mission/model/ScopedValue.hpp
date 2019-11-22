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

#ifndef GS2_MISSION_MODEL_SCOPEDVALUE_HPP_
#define GS2_MISSION_MODEL_SCOPEDVALUE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace mission {

/**
 * リセットタイミングまでの期間のカウンター値
 *
 * @author Game Server Services, Inc.
 *
 */
class ScopedValue : public Gs2Object
{
    friend bool operator!=(const ScopedValue& lhs, const ScopedValue& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** リセットタイミング */
        optional<StringHolder> resetType;
        /** カウント */
        optional<Int64> value;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

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
    ScopedValue() = default;
    ScopedValue(const ScopedValue& scopedValue) = default;
    ScopedValue(ScopedValue&& scopedValue) = default;
    ~ScopedValue() = default;

    ScopedValue& operator=(const ScopedValue& scopedValue) = default;
    ScopedValue& operator=(ScopedValue&& scopedValue) = default;

    ScopedValue deepCopy() const;

    const ScopedValue* operator->() const
    {
        return this;
    }

    ScopedValue* operator->()
    {
        return this;
    }
    /**
     * リセットタイミングを取得
     *
     * @return リセットタイミング
     */
    const optional<StringHolder>& getResetType() const
    {
        return ensureData().resetType;
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    void setResetType(StringHolder resetType)
    {
        ensureData().resetType.emplace(std::move(resetType));
    }

    /**
     * リセットタイミングを設定
     *
     * @param resetType リセットタイミング
     */
    ScopedValue& withResetType(StringHolder resetType)
    {
        setResetType(std::move(resetType));
        return *this;
    }

    /**
     * カウントを取得
     *
     * @return カウント
     */
    const optional<Int64>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * カウントを設定
     *
     * @param value カウント
     */
    void setValue(Int64 value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * カウントを設定
     *
     * @param value カウント
     */
    ScopedValue& withValue(Int64 value)
    {
        setValue(value);
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
    ScopedValue& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const ScopedValue& lhs, const ScopedValue& lhr);

inline bool operator==(const ScopedValue& lhs, const ScopedValue& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_SCOPEDVALUE_HPP_