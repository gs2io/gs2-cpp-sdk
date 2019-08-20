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

#ifndef GS2_DEPLOY_CONTROL_UPDATESTACKREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_UPDATESTACKREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DeployConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace deploy
{

/**
 * スタックを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateStackRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタック名 */
        optional<StringHolder> stackName;
        /** スタックの説明 */
        optional<StringHolder> description;
        /** テンプレートデータ */
        optional<StringHolder> template_;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            stackName(data.stackName),
            description(data.description),
            template_(data.template_)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            stackName(std::move(data.stackName)),
            description(std::move(data.description)),
            template_(std::move(data.template_))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    UpdateStackRequest() :
        m_pData(nullptr)
    {}

    UpdateStackRequest(const UpdateStackRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Deploy(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateStackRequest(UpdateStackRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Deploy(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateStackRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateStackRequest& operator=(const UpdateStackRequest& updateStackRequest)
    {
        Gs2BasicRequest::operator=(updateStackRequest);
        Gs2Deploy::operator=(updateStackRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateStackRequest.m_pData);

        return *this;
    }

    UpdateStackRequest& operator=(UpdateStackRequest&& updateStackRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateStackRequest));
        Gs2Deploy::operator=(std::move(updateStackRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateStackRequest.m_pData;
        updateStackRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateStackRequest* operator->() const
    {
        return this;
    }

    UpdateStackRequest* operator->()
    {
        return this;
    }

    /**
     * スタック名を取得
     *
     * @return スタック名
     */
    const optional<StringHolder>& getStackName() const
    {
        return ensureData().stackName;
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    void setStackName(const Char* stackName)
    {
        ensureData().stackName.emplace(stackName);
    }

    /**
     * スタック名を設定
     *
     * @param stackName スタック名
     */
    UpdateStackRequest& withStackName(const Char* stackName)
    {
        ensureData().stackName.emplace(stackName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    UpdateStackRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setTemplate(const Char* template_)
    {
        ensureData().template_.emplace(template_);
    }

    /**
     * テンプレートデータを設定
     *
     * @param template_ テンプレートデータ
     */
    UpdateStackRequest& withTemplate(const Char* template_)
    {
        ensureData().template_.emplace(template_);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateStackRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateStackRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateStackRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateStackRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_UPDATESTACKREQUEST_HPP_