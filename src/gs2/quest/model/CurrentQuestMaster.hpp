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

#ifndef GS2_QUEST_MODEL_CURRENTQUESTMASTER_HPP_
#define GS2_QUEST_MODEL_CURRENTQUESTMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace quest {

/**
 * 現在有効なクエストマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentQuestMaster : public Gs2Object
{
    friend bool operator!=(const CurrentQuestMaster& lhs, const CurrentQuestMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
        /** マスターデータ */
        optional<StringHolder> settings;

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
    CurrentQuestMaster() = default;
    CurrentQuestMaster(const CurrentQuestMaster& currentQuestMaster) = default;
    CurrentQuestMaster(CurrentQuestMaster&& currentQuestMaster) = default;
    ~CurrentQuestMaster() = default;

    CurrentQuestMaster& operator=(const CurrentQuestMaster& currentQuestMaster) = default;
    CurrentQuestMaster& operator=(CurrentQuestMaster&& currentQuestMaster) = default;

    CurrentQuestMaster deepCopy() const;

    const CurrentQuestMaster* operator->() const
    {
        return this;
    }

    CurrentQuestMaster* operator->()
    {
        return this;
    }
    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    CurrentQuestMaster& withNamespaceName(StringHolder namespaceName)
    {
        setNamespaceName(std::move(namespaceName));
        return *this;
    }

    /**
     * マスターデータを取得
     *
     * @return マスターデータ
     */
    const optional<StringHolder>& getSettings() const
    {
        return ensureData().settings;
    }

    /**
     * マスターデータを設定
     *
     * @param settings マスターデータ
     */
    void setSettings(StringHolder settings)
    {
        ensureData().settings.emplace(std::move(settings));
    }

    /**
     * マスターデータを設定
     *
     * @param settings マスターデータ
     */
    CurrentQuestMaster& withSettings(StringHolder settings)
    {
        setSettings(std::move(settings));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CurrentQuestMaster& lhs, const CurrentQuestMaster& lhr);

inline bool operator==(const CurrentQuestMaster& lhs, const CurrentQuestMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_CURRENTQUESTMASTER_HPP_