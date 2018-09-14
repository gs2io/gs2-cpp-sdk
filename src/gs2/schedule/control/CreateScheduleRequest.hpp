/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_SCHEDULE_CONTROL_CREATESCHEDULEREQUEST_HPP_
#define GS2_SCHEDULE_CONTROL_CREATESCHEDULEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScheduleConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * @author Game Server Services, Inc.
 */
class CreateScheduleRequest : public Gs2BasicRequest, public Gs2Schedule
{
public:
    constexpr static const Char* const FUNCTION = "CreateSchedule";

private:
    class Data : public Gs2Object
    {
    public:
        /** スケジュール名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description))
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
    CreateScheduleRequest() :
        m_pData(nullptr)
    {}

    CreateScheduleRequest(const CreateScheduleRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Schedule(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateScheduleRequest(CreateScheduleRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Schedule(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateScheduleRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateScheduleRequest& operator=(const CreateScheduleRequest& createScheduleRequest)
    {
        Gs2BasicRequest::operator=(createScheduleRequest);
        Gs2Schedule::operator=(createScheduleRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createScheduleRequest.m_pData);

        return *this;
    }

    CreateScheduleRequest& operator=(CreateScheduleRequest&& createScheduleRequest)
    {
        Gs2BasicRequest::operator=(std::move(createScheduleRequest));
        Gs2Schedule::operator=(std::move(createScheduleRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createScheduleRequest.m_pData;
        createScheduleRequest.m_pData = nullptr;

        return *this;
    }

    const CreateScheduleRequest* operator->() const
    {
        return this;
    }

    CreateScheduleRequest* operator->()
    {
        return this;
    }

    /**
     * スケジュール名を取得
     *
     * @return スケジュール名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スケジュール名を設定
     *
     * @param name スケジュール名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * スケジュール名を設定
     *
     * @param name スケジュール名
     */
    CreateScheduleRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    CreateScheduleRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateScheduleRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateScheduleRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateScheduleRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateScheduleRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCHEDULE_CONTROL_CREATESCHEDULEREQUEST_HPP_