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

#ifndef GS2_RANKING_MODEL_CURRENTRANKINGMASTER_HPP_
#define GS2_RANKING_MODEL_CURRENTRANKINGMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace ranking {

/**
 * 現在有効なランキング設定
 *
 * @author Game Server Services, Inc.
 *
 */
class CurrentRankingMaster : public Gs2Object
{
    friend bool operator!=(const CurrentRankingMaster& lhs, const CurrentRankingMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース名 */
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
    CurrentRankingMaster() = default;
    CurrentRankingMaster(const CurrentRankingMaster& currentRankingMaster) = default;
    CurrentRankingMaster(CurrentRankingMaster&& currentRankingMaster) = default;
    ~CurrentRankingMaster() = default;

    CurrentRankingMaster& operator=(const CurrentRankingMaster& currentRankingMaster) = default;
    CurrentRankingMaster& operator=(CurrentRankingMaster&& currentRankingMaster) = default;

    CurrentRankingMaster deepCopy() const;

    const CurrentRankingMaster* operator->() const
    {
        return this;
    }

    CurrentRankingMaster* operator->()
    {
        return this;
    }
    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    CurrentRankingMaster& withNamespaceName(StringHolder namespaceName)
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
    CurrentRankingMaster& withSettings(StringHolder settings)
    {
        setSettings(std::move(settings));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CurrentRankingMaster& lhs, const CurrentRankingMaster& lhr);

inline bool operator==(const CurrentRankingMaster& lhs, const CurrentRankingMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_RANKING_MODEL_CURRENTRANKINGMASTER_HPP_