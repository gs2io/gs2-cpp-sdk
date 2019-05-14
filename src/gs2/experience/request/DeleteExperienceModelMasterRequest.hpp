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

#ifndef GS2_EXPERIENCE_CONTROL_DELETEEXPERIENCEMODELMASTERREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_DELETEEXPERIENCEMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * 経験値の種類を削除 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteExperienceModelMasterRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 経験値名 */
        optional<StringHolder> experienceName;
        /** 経験値の種類名 */
        optional<StringHolder> experienceModelName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            experienceName(data.experienceName),
            experienceModelName(data.experienceModelName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            experienceName(std::move(data.experienceName)),
            experienceModelName(std::move(data.experienceModelName))
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
    DeleteExperienceModelMasterRequest() :
        m_pData(nullptr)
    {}

    DeleteExperienceModelMasterRequest(const DeleteExperienceModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteExperienceModelMasterRequest(DeleteExperienceModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteExperienceModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteExperienceModelMasterRequest& operator=(const DeleteExperienceModelMasterRequest& deleteExperienceModelMasterRequest)
    {
        Gs2BasicRequest::operator=(deleteExperienceModelMasterRequest);
        Gs2Experience::operator=(deleteExperienceModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteExperienceModelMasterRequest.m_pData);

        return *this;
    }

    DeleteExperienceModelMasterRequest& operator=(DeleteExperienceModelMasterRequest&& deleteExperienceModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteExperienceModelMasterRequest));
        Gs2Experience::operator=(std::move(deleteExperienceModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteExperienceModelMasterRequest.m_pData;
        deleteExperienceModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteExperienceModelMasterRequest* operator->() const
    {
        return this;
    }

    DeleteExperienceModelMasterRequest* operator->()
    {
        return this;
    }
    /**
     * 経験値名を取得
     *
     * @return 経験値名
     */
    const optional<StringHolder>& getExperienceName() const
    {
        return ensureData().experienceName;
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    void setExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    DeleteExperienceModelMasterRequest& withExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
        return *this;
    }

    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getExperienceModelName() const
    {
        return ensureData().experienceModelName;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    void setExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    DeleteExperienceModelMasterRequest& withExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteExperienceModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteExperienceModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteExperienceModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteExperienceModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_DELETEEXPERIENCEMODELMASTERREQUEST_HPP_