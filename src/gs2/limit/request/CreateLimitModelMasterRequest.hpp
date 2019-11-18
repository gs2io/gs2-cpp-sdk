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

#ifndef GS2_LIMIT_CONTROL_CREATELIMITMODELMASTERREQUEST_HPP_
#define GS2_LIMIT_CONTROL_CREATELIMITMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/limit/Gs2LimitConst.hpp>
#include <gs2/limit/model/model.hpp>
#include <memory>

namespace gs2 { namespace limit
{

/**
 * 回数制限の種類マスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateLimitModelMasterRequest : public Gs2BasicRequest, public Gs2Limit
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 回数制限の種類名 */
        optional<StringHolder> name;
        /** 回数制限の種類マスターの説明 */
        optional<StringHolder> description;
        /** 回数制限の種類のメタデータ */
        optional<StringHolder> metadata;
        /** リセットタイミング */
        optional<StringHolder> resetType;
        /** リセットをする日にち */
        optional<Int32> resetDayOfMonth;
        /** リセットする曜日 */
        optional<StringHolder> resetDayOfWeek;
        /** リセット時刻 */
        optional<Int32> resetHour;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            resetType(data.resetType),
            resetDayOfMonth(data.resetDayOfMonth),
            resetDayOfWeek(data.resetDayOfWeek),
            resetHour(data.resetHour)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    CreateLimitModelMasterRequest() = default;
    CreateLimitModelMasterRequest(const CreateLimitModelMasterRequest& createLimitModelMasterRequest) = default;
    CreateLimitModelMasterRequest(CreateLimitModelMasterRequest&& createLimitModelMasterRequest) = default;
    ~CreateLimitModelMasterRequest() GS2_OVERRIDE = default;

    CreateLimitModelMasterRequest& operator=(const CreateLimitModelMasterRequest& createLimitModelMasterRequest) = default;
    CreateLimitModelMasterRequest& operator=(CreateLimitModelMasterRequest&& createLimitModelMasterRequest) = default;

    CreateLimitModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateLimitModelMasterRequest);
    }

    const CreateLimitModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateLimitModelMasterRequest* operator->()
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
    CreateLimitModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 回数制限の種類名を取得
     *
     * @return 回数制限の種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 回数制限の種類名を設定
     *
     * @param name 回数制限の種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 回数制限の種類名を設定
     *
     * @param name 回数制限の種類名
     */
    CreateLimitModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * 回数制限の種類マスターの説明を取得
     *
     * @return 回数制限の種類マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 回数制限の種類マスターの説明を設定
     *
     * @param description 回数制限の種類マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 回数制限の種類マスターの説明を設定
     *
     * @param description 回数制限の種類マスターの説明
     */
    CreateLimitModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 回数制限の種類のメタデータを取得
     *
     * @return 回数制限の種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 回数制限の種類のメタデータを設定
     *
     * @param metadata 回数制限の種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 回数制限の種類のメタデータを設定
     *
     * @param metadata 回数制限の種類のメタデータ
     */
    CreateLimitModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
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
    CreateLimitModelMasterRequest& withResetType(StringHolder resetType)
    {
        ensureData().resetType.emplace(std::move(resetType));
        return *this;
    }

    /**
     * リセットをする日にちを取得
     *
     * @return リセットをする日にち
     */
    const optional<Int32>& getResetDayOfMonth() const
    {
        return ensureData().resetDayOfMonth;
    }

    /**
     * リセットをする日にちを設定
     *
     * @param resetDayOfMonth リセットをする日にち
     */
    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
    }

    /**
     * リセットをする日にちを設定
     *
     * @param resetDayOfMonth リセットをする日にち
     */
    CreateLimitModelMasterRequest& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth.emplace(resetDayOfMonth);
        return *this;
    }

    /**
     * リセットする曜日を取得
     *
     * @return リセットする曜日
     */
    const optional<StringHolder>& getResetDayOfWeek() const
    {
        return ensureData().resetDayOfWeek;
    }

    /**
     * リセットする曜日を設定
     *
     * @param resetDayOfWeek リセットする曜日
     */
    void setResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(std::move(resetDayOfWeek));
    }

    /**
     * リセットする曜日を設定
     *
     * @param resetDayOfWeek リセットする曜日
     */
    CreateLimitModelMasterRequest& withResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        ensureData().resetDayOfWeek.emplace(std::move(resetDayOfWeek));
        return *this;
    }

    /**
     * リセット時刻を取得
     *
     * @return リセット時刻
     */
    const optional<Int32>& getResetHour() const
    {
        return ensureData().resetHour;
    }

    /**
     * リセット時刻を設定
     *
     * @param resetHour リセット時刻
     */
    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
    }

    /**
     * リセット時刻を設定
     *
     * @param resetHour リセット時刻
     */
    CreateLimitModelMasterRequest& withResetHour(Int32 resetHour)
    {
        ensureData().resetHour.emplace(resetHour);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateLimitModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateLimitModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_LIMIT_CONTROL_CREATELIMITMODELMASTERREQUEST_HPP_