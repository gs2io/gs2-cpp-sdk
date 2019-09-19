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

#ifndef GS2_SHOWCASE_CONTROL_DELETESHOWCASEMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_DELETESHOWCASEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace showcase
{

/**
 * 陳列棚マスターを削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteShowcaseMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 陳列棚名 */
        optional<StringHolder> showcaseName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            showcaseName(data.showcaseName)
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
    DeleteShowcaseMasterRequest() = default;
    DeleteShowcaseMasterRequest(const DeleteShowcaseMasterRequest& deleteShowcaseMasterRequest) = default;
    DeleteShowcaseMasterRequest(DeleteShowcaseMasterRequest&& deleteShowcaseMasterRequest) = default;
    ~DeleteShowcaseMasterRequest() GS2_OVERRIDE = default;

    DeleteShowcaseMasterRequest& operator=(const DeleteShowcaseMasterRequest& deleteShowcaseMasterRequest) = default;
    DeleteShowcaseMasterRequest& operator=(DeleteShowcaseMasterRequest&& deleteShowcaseMasterRequest) = default;

    DeleteShowcaseMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteShowcaseMasterRequest);
    }

    const DeleteShowcaseMasterRequest* operator->() const
    {
        return this;
    }

    DeleteShowcaseMasterRequest* operator->()
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
    DeleteShowcaseMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 陳列棚名を取得
     *
     * @return 陳列棚名
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * 陳列棚名を設定
     *
     * @param showcaseName 陳列棚名
     */
    void setShowcaseName(StringHolder showcaseName)
    {
        ensureData().showcaseName.emplace(std::move(showcaseName));
    }

    /**
     * 陳列棚名を設定
     *
     * @param showcaseName 陳列棚名
     */
    DeleteShowcaseMasterRequest& withShowcaseName(StringHolder showcaseName)
    {
        ensureData().showcaseName.emplace(std::move(showcaseName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteShowcaseMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteShowcaseMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_DELETESHOWCASEMASTERREQUEST_HPP_