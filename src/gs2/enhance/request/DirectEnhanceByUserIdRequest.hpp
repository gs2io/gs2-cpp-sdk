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

#ifndef GS2_ENHANCE_CONTROL_DIRECTENHANCEBYUSERIDREQUEST_HPP_
#define GS2_ENHANCE_CONTROL_DIRECTENHANCEBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/enhance/Gs2EnhanceConst.hpp>
#include <gs2/enhance/model/model.hpp>
#include <memory>

namespace gs2 { namespace enhance
{

/**
 * ユーザIDを指定して強化を実行 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DirectEnhanceByUserIdRequest : public Gs2BasicRequest, public Gs2Enhance
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 強化レート名 */
        optional<StringHolder> rateName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 強化対象の GS2-Inventory アイテムセットGRN */
        optional<StringHolder> targetItemSetId;
        /** 強化素材リスト */
        optional<List<Material>> materials;
        /** 設定値 */
        optional<List<Config>> config;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            rateName(data.rateName),
            userId(data.userId),
            targetItemSetId(data.targetItemSetId),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.materials)
            {
                materials = data.materials->deepCopy();
            }
            if (data.config)
            {
                config = data.config->deepCopy();
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
    DirectEnhanceByUserIdRequest() = default;
    DirectEnhanceByUserIdRequest(const DirectEnhanceByUserIdRequest& directEnhanceByUserIdRequest) = default;
    DirectEnhanceByUserIdRequest(DirectEnhanceByUserIdRequest&& directEnhanceByUserIdRequest) = default;
    ~DirectEnhanceByUserIdRequest() GS2_OVERRIDE = default;

    DirectEnhanceByUserIdRequest& operator=(const DirectEnhanceByUserIdRequest& directEnhanceByUserIdRequest) = default;
    DirectEnhanceByUserIdRequest& operator=(DirectEnhanceByUserIdRequest&& directEnhanceByUserIdRequest) = default;

    DirectEnhanceByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DirectEnhanceByUserIdRequest);
    }

    const DirectEnhanceByUserIdRequest* operator->() const
    {
        return this;
    }

    DirectEnhanceByUserIdRequest* operator->()
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
    DirectEnhanceByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 強化レート名を取得
     *
     * @return 強化レート名
     */
    const optional<StringHolder>& getRateName() const
    {
        return ensureData().rateName;
    }

    /**
     * 強化レート名を設定
     *
     * @param rateName 強化レート名
     */
    void setRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
    }

    /**
     * 強化レート名を設定
     *
     * @param rateName 強化レート名
     */
    DirectEnhanceByUserIdRequest& withRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    DirectEnhanceByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * 強化対象の GS2-Inventory アイテムセットGRNを取得
     *
     * @return 強化対象の GS2-Inventory アイテムセットGRN
     */
    const optional<StringHolder>& getTargetItemSetId() const
    {
        return ensureData().targetItemSetId;
    }

    /**
     * 強化対象の GS2-Inventory アイテムセットGRNを設定
     *
     * @param targetItemSetId 強化対象の GS2-Inventory アイテムセットGRN
     */
    void setTargetItemSetId(StringHolder targetItemSetId)
    {
        ensureData().targetItemSetId.emplace(std::move(targetItemSetId));
    }

    /**
     * 強化対象の GS2-Inventory アイテムセットGRNを設定
     *
     * @param targetItemSetId 強化対象の GS2-Inventory アイテムセットGRN
     */
    DirectEnhanceByUserIdRequest& withTargetItemSetId(StringHolder targetItemSetId)
    {
        ensureData().targetItemSetId.emplace(std::move(targetItemSetId));
        return *this;
    }

    /**
     * 強化素材リストを取得
     *
     * @return 強化素材リスト
     */
    const optional<List<Material>>& getMaterials() const
    {
        return ensureData().materials;
    }

    /**
     * 強化素材リストを設定
     *
     * @param materials 強化素材リスト
     */
    void setMaterials(List<Material> materials)
    {
        ensureData().materials.emplace(std::move(materials));
    }

    /**
     * 強化素材リストを設定
     *
     * @param materials 強化素材リスト
     */
    DirectEnhanceByUserIdRequest& withMaterials(List<Material> materials)
    {
        ensureData().materials.emplace(std::move(materials));
        return *this;
    }

    /**
     * 設定値を取得
     *
     * @return 設定値
     */
    const optional<List<Config>>& getConfig() const
    {
        return ensureData().config;
    }

    /**
     * 設定値を設定
     *
     * @param config 設定値
     */
    void setConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
    }

    /**
     * 設定値を設定
     *
     * @param config 設定値
     */
    DirectEnhanceByUserIdRequest& withConfig(List<Config> config)
    {
        ensureData().config.emplace(std::move(config));
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    DirectEnhanceByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DirectEnhanceByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DirectEnhanceByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_ENHANCE_CONTROL_DIRECTENHANCEBYUSERIDREQUEST_HPP_