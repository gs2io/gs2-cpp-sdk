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

#ifndef GS2_DISTRIBUTOR_CONTROL_DISTRIBUTERESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_DISTRIBUTERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/distributor/model/model.hpp>
#include <memory>

namespace gs2 { namespace distributor
{

/**
 * 所持品を配布する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DistributeResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 処理した DistributeResource */
        optional<DistributeResource> distributeResource;
        /** 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN */
        optional<StringHolder> inboxNamespaceId;
        /** レスポンス内容 */
        optional<StringHolder> result;

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
    DistributeResult() = default;
    DistributeResult(const DistributeResult& distributeResult) = default;
    DistributeResult(DistributeResult&& distributeResult) = default;
    ~DistributeResult() = default;

    DistributeResult& operator=(const DistributeResult& distributeResult) = default;
    DistributeResult& operator=(DistributeResult&& distributeResult) = default;

    DistributeResult deepCopy() const;

    const DistributeResult* operator->() const
    {
        return this;
    }

    DistributeResult* operator->()
    {
        return this;
    }
    /**
     * 処理した DistributeResourceを取得
     *
     * @return 処理した DistributeResource
     */
    const optional<DistributeResource>& getDistributeResource() const
    {
        return ensureData().distributeResource;
    }

    /**
     * 処理した DistributeResourceを設定
     *
     * @param distributeResource 処理した DistributeResource
     */
    void setDistributeResource(DistributeResource distributeResource)
    {
        ensureData().distributeResource.emplace(std::move(distributeResource));
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを取得
     *
     * @return 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    const optional<StringHolder>& getInboxNamespaceId() const
    {
        return ensureData().inboxNamespaceId;
    }

    /**
     * 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRNを設定
     *
     * @param inboxNamespaceId 所持品がキャパシティをオーバーしたときに転送するプレゼントボックスのネームスペース のGRN
     */
    void setInboxNamespaceId(StringHolder inboxNamespaceId)
    {
        ensureData().inboxNamespaceId.emplace(std::move(inboxNamespaceId));
    }

    /**
     * レスポンス内容を取得
     *
     * @return レスポンス内容
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * レスポンス内容を設定
     *
     * @param result レスポンス内容
     */
    void setResult(StringHolder result)
    {
        ensureData().result.emplace(std::move(result));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DistributeResult> AsyncDistributeResult;

} }

#endif //GS2_DISTRIBUTOR_CONTROL_DISTRIBUTERESULT_HPP_