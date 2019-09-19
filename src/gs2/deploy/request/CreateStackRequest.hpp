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

#ifndef GS2_DEPLOY_CONTROL_CREATESTACKREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_CREATESTACKREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DeployConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace deploy
{

/**
 * スタックを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateStackRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** スタック名 */
        optional<StringHolder> name;
        /** スタックの説明 */
        optional<StringHolder> description;
        /** テンプレートデータ */
        optional<StringHolder> template_;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            name(data.name),
            description(data.description),
            template_(data.template_)
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
    CreateStackRequest() = default;
    CreateStackRequest(const CreateStackRequest& createStackRequest) = default;
    CreateStackRequest(CreateStackRequest&& createStackRequest) = default;
    ~CreateStackRequest() GS2_OVERRIDE = default;

    CreateStackRequest& operator=(const CreateStackRequest& createStackRequest) = default;
    CreateStackRequest& operator=(CreateStackRequest&& createStackRequest) = default;

    CreateStackRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateStackRequest);
    }

    const CreateStackRequest* operator->() const
    {
        return this;
    }

    CreateStackRequest* operator->()
    {
        return this;
    }

    /**
     * スタック名を取得
     *
     * @return スタック名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタック名を設定
     *
     * @param name スタック名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スタック名を設定
     *
     * @param name スタック名
     */
    CreateStackRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * スタックの説明を取得
     *
     * @return スタックの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    CreateStackRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * テンプレートデータを取得
     *
     * @return テンプレートデータ
     */
    const optional<StringHolder>& getTemplate() const
    {
        return ensureData().template_;
    }

    /**
     * テンプレートデータを設定
     *
     * @param template_ テンプレートデータ
     */
    void setTemplate(StringHolder template_)
    {
        ensureData().template_.emplace(std::move(template_));
    }

    /**
     * テンプレートデータを設定
     *
     * @param template_ テンプレートデータ
     */
    CreateStackRequest& withTemplate(StringHolder template_)
    {
        ensureData().template_.emplace(std::move(template_));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateStackRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateStackRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_CREATESTACKREQUEST_HPP_