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

#ifndef GS2_RANKING_CONTROL_GETCATEGORYMODELMASTERREQUEST_HPP_
#define GS2_RANKING_CONTROL_GETCATEGORYMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/Gs2RankingConst.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * カテゴリマスターを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetCategoryModelMasterRequest : public Gs2BasicRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** カテゴリモデル名 */
        optional<StringHolder> categoryName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            categoryName(data.categoryName)
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
    GetCategoryModelMasterRequest() = default;
    GetCategoryModelMasterRequest(const GetCategoryModelMasterRequest& getCategoryModelMasterRequest) = default;
    GetCategoryModelMasterRequest(GetCategoryModelMasterRequest&& getCategoryModelMasterRequest) = default;
    ~GetCategoryModelMasterRequest() GS2_OVERRIDE = default;

    GetCategoryModelMasterRequest& operator=(const GetCategoryModelMasterRequest& getCategoryModelMasterRequest) = default;
    GetCategoryModelMasterRequest& operator=(GetCategoryModelMasterRequest&& getCategoryModelMasterRequest) = default;

    GetCategoryModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetCategoryModelMasterRequest);
    }

    const GetCategoryModelMasterRequest* operator->() const
    {
        return this;
    }

    GetCategoryModelMasterRequest* operator->()
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
    GetCategoryModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * カテゴリモデル名を取得
     *
     * @return カテゴリモデル名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param categoryName カテゴリモデル名
     */
    void setCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param categoryName カテゴリモデル名
     */
    GetCategoryModelMasterRequest& withCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetCategoryModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetCategoryModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_RANKING_CONTROL_GETCATEGORYMODELMASTERREQUEST_HPP_