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

#ifndef GS2_PROJECT_CONTROL_DESCRIBEBILLINGSREQUEST_HPP_
#define GS2_PROJECT_CONTROL_DESCRIBEBILLINGSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/project/Gs2ProjectConst.hpp>
#include <gs2/project/model/model.hpp>
#include <memory>

namespace gs2 { namespace project
{

/**
 * 利用状況の一覧を取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeBillingsRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** GS2アカウントトークン */
        optional<StringHolder> accountToken;
        /** プロジェクト名 */
        optional<StringHolder> projectName;
        /** イベントの発生年 */
        optional<Int32> year;
        /** イベントの発生月 */
        optional<Int32> month;
        /** サービスの種類 */
        optional<StringHolder> region;
        /** サービスの種類 */
        optional<StringHolder> service;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accountToken(data.accountToken),
            projectName(data.projectName),
            year(data.year),
            month(data.month),
            region(data.region),
            service(data.service)
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
    DescribeBillingsRequest() = default;
    DescribeBillingsRequest(const DescribeBillingsRequest& describeBillingsRequest) = default;
    DescribeBillingsRequest(DescribeBillingsRequest&& describeBillingsRequest) = default;
    ~DescribeBillingsRequest() GS2_OVERRIDE = default;

    DescribeBillingsRequest& operator=(const DescribeBillingsRequest& describeBillingsRequest) = default;
    DescribeBillingsRequest& operator=(DescribeBillingsRequest&& describeBillingsRequest) = default;

    DescribeBillingsRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeBillingsRequest);
    }

    const DescribeBillingsRequest* operator->() const
    {
        return this;
    }

    DescribeBillingsRequest* operator->()
    {
        return this;
    }

    /**
     * GS2アカウントトークンを取得
     *
     * @return GS2アカウントトークン
     */
    const optional<StringHolder>& getAccountToken() const
    {
        return ensureData().accountToken;
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    void setAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
    }

    /**
     * GS2アカウントトークンを設定
     *
     * @param accountToken GS2アカウントトークン
     */
    DescribeBillingsRequest& withAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
        return *this;
    }

    /**
     * プロジェクト名を取得
     *
     * @return プロジェクト名
     */
    const optional<StringHolder>& getProjectName() const
    {
        return ensureData().projectName;
    }

    /**
     * プロジェクト名を設定
     *
     * @param projectName プロジェクト名
     */
    void setProjectName(StringHolder projectName)
    {
        ensureData().projectName.emplace(std::move(projectName));
    }

    /**
     * プロジェクト名を設定
     *
     * @param projectName プロジェクト名
     */
    DescribeBillingsRequest& withProjectName(StringHolder projectName)
    {
        ensureData().projectName.emplace(std::move(projectName));
        return *this;
    }

    /**
     * イベントの発生年を取得
     *
     * @return イベントの発生年
     */
    const optional<Int32>& getYear() const
    {
        return ensureData().year;
    }

    /**
     * イベントの発生年を設定
     *
     * @param year イベントの発生年
     */
    void setYear(Int32 year)
    {
        ensureData().year.emplace(year);
    }

    /**
     * イベントの発生年を設定
     *
     * @param year イベントの発生年
     */
    DescribeBillingsRequest& withYear(Int32 year)
    {
        ensureData().year.emplace(year);
        return *this;
    }

    /**
     * イベントの発生月を取得
     *
     * @return イベントの発生月
     */
    const optional<Int32>& getMonth() const
    {
        return ensureData().month;
    }

    /**
     * イベントの発生月を設定
     *
     * @param month イベントの発生月
     */
    void setMonth(Int32 month)
    {
        ensureData().month.emplace(month);
    }

    /**
     * イベントの発生月を設定
     *
     * @param month イベントの発生月
     */
    DescribeBillingsRequest& withMonth(Int32 month)
    {
        ensureData().month.emplace(month);
        return *this;
    }

    /**
     * サービスの種類を取得
     *
     * @return サービスの種類
     */
    const optional<StringHolder>& getRegion() const
    {
        return ensureData().region;
    }

    /**
     * サービスの種類を設定
     *
     * @param region サービスの種類
     */
    void setRegion(StringHolder region)
    {
        ensureData().region.emplace(std::move(region));
    }

    /**
     * サービスの種類を設定
     *
     * @param region サービスの種類
     */
    DescribeBillingsRequest& withRegion(StringHolder region)
    {
        ensureData().region.emplace(std::move(region));
        return *this;
    }

    /**
     * サービスの種類を取得
     *
     * @return サービスの種類
     */
    const optional<StringHolder>& getService() const
    {
        return ensureData().service;
    }

    /**
     * サービスの種類を設定
     *
     * @param service サービスの種類
     */
    void setService(StringHolder service)
    {
        ensureData().service.emplace(std::move(service));
    }

    /**
     * サービスの種類を設定
     *
     * @param service サービスの種類
     */
    DescribeBillingsRequest& withService(StringHolder service)
    {
        ensureData().service.emplace(std::move(service));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeBillingsRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeBillingsRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_DESCRIBEBILLINGSREQUEST_HPP_