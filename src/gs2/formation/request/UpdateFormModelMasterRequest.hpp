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

#ifndef GS2_FORMATION_CONTROL_UPDATEFORMMODELMASTERREQUEST_HPP_
#define GS2_FORMATION_CONTROL_UPDATEFORMMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/Gs2FormationConst.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * フォームマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateFormModelMasterRequest : public Gs2BasicRequest, public Gs2Formation
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** フォーム名 */
        optional<StringHolder> formModelName;
        /** フォームマスターの説明 */
        optional<StringHolder> description;
        /** フォームのメタデータ */
        optional<StringHolder> metadata;
        /** スロットリスト */
        optional<List<SlotModel>> slots;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            formModelName(data.formModelName),
            description(data.description),
            metadata(data.metadata)
        {
            if (data.slots)
            {
                slots = data.slots->deepCopy();
            }
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
    UpdateFormModelMasterRequest() = default;
    UpdateFormModelMasterRequest(const UpdateFormModelMasterRequest& updateFormModelMasterRequest) = default;
    UpdateFormModelMasterRequest(UpdateFormModelMasterRequest&& updateFormModelMasterRequest) = default;
    ~UpdateFormModelMasterRequest() GS2_OVERRIDE = default;

    UpdateFormModelMasterRequest& operator=(const UpdateFormModelMasterRequest& updateFormModelMasterRequest) = default;
    UpdateFormModelMasterRequest& operator=(UpdateFormModelMasterRequest&& updateFormModelMasterRequest) = default;

    UpdateFormModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateFormModelMasterRequest);
    }

    const UpdateFormModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateFormModelMasterRequest* operator->()
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
    UpdateFormModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * フォーム名を取得
     *
     * @return フォーム名
     */
    const optional<StringHolder>& getFormModelName() const
    {
        return ensureData().formModelName;
    }

    /**
     * フォーム名を設定
     *
     * @param formModelName フォーム名
     */
    void setFormModelName(StringHolder formModelName)
    {
        ensureData().formModelName.emplace(std::move(formModelName));
    }

    /**
     * フォーム名を設定
     *
     * @param formModelName フォーム名
     */
    UpdateFormModelMasterRequest& withFormModelName(StringHolder formModelName)
    {
        ensureData().formModelName.emplace(std::move(formModelName));
        return *this;
    }

    /**
     * フォームマスターの説明を取得
     *
     * @return フォームマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * フォームマスターの説明を設定
     *
     * @param description フォームマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * フォームマスターの説明を設定
     *
     * @param description フォームマスターの説明
     */
    UpdateFormModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * フォームのメタデータを取得
     *
     * @return フォームのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * フォームのメタデータを設定
     *
     * @param metadata フォームのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * フォームのメタデータを設定
     *
     * @param metadata フォームのメタデータ
     */
    UpdateFormModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * スロットリストを取得
     *
     * @return スロットリスト
     */
    const optional<List<SlotModel>>& getSlots() const
    {
        return ensureData().slots;
    }

    /**
     * スロットリストを設定
     *
     * @param slots スロットリスト
     */
    void setSlots(List<SlotModel> slots)
    {
        ensureData().slots.emplace(std::move(slots));
    }

    /**
     * スロットリストを設定
     *
     * @param slots スロットリスト
     */
    UpdateFormModelMasterRequest& withSlots(List<SlotModel> slots)
    {
        ensureData().slots.emplace(std::move(slots));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateFormModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateFormModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FORMATION_CONTROL_UPDATEFORMMODELMASTERREQUEST_HPP_