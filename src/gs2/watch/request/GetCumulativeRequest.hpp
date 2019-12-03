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

#ifndef GS2_WATCH_CONTROL_GETCUMULATIVEREQUEST_HPP_
#define GS2_WATCH_CONTROL_GETCUMULATIVEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/watch/Gs2WatchConst.hpp>
#include <gs2/watch/model/model.hpp>
#include <memory>

namespace gs2 { namespace watch
{

/**
 * 累積値を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCumulativeRequest : public Gs2BasicRequest, public Gs2Watch
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** 名前 */
        optional<StringHolder> name;
        /** リソースのGRN */
        optional<StringHolder> resourceGrn;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            name(data.name),
            resourceGrn(data.resourceGrn)
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
    GetCumulativeRequest() = default;
    GetCumulativeRequest(const GetCumulativeRequest& getCumulativeRequest) = default;
    GetCumulativeRequest(GetCumulativeRequest&& getCumulativeRequest) = default;
    ~GetCumulativeRequest() GS2_OVERRIDE = default;

    GetCumulativeRequest& operator=(const GetCumulativeRequest& getCumulativeRequest) = default;
    GetCumulativeRequest& operator=(GetCumulativeRequest&& getCumulativeRequest) = default;

    GetCumulativeRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetCumulativeRequest);
    }

    const GetCumulativeRequest* operator->() const
    {
        return this;
    }

    GetCumulativeRequest* operator->()
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
    GetCumulativeRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * リソースのGRNを取得
     *
     * @return リソースのGRN
     */
    const optional<StringHolder>& getResourceGrn() const
    {
        return ensureData().resourceGrn;
    }

    /**
     * リソースのGRNを設定
     *
     * @param resourceGrn リソースのGRN
     */
    void setResourceGrn(StringHolder resourceGrn)
    {
        ensureData().resourceGrn.emplace(std::move(resourceGrn));
    }

    /**
     * リソースのGRNを設定
     *
     * @param resourceGrn リソースのGRN
     */
    GetCumulativeRequest& withResourceGrn(StringHolder resourceGrn)
    {
        ensureData().resourceGrn.emplace(std::move(resourceGrn));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetCumulativeRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetCumulativeRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_WATCH_CONTROL_GETCUMULATIVEREQUEST_HPP_