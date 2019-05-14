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

#ifndef GS2_INBOX_MODEL_BODY_HPP_
#define GS2_INBOX_MODEL_BODY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * None
 *
 * @author Game Server Services, Inc.
 *
 */
class Body : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザーID */
        optional<StringHolder> userId;
        /** メッセージの内容に相当するメタデータ */
        optional<StringHolder> metadata;
        /** メッセージ開封時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageTriggerScriptId;
        /** メッセージ開封時 に実行されるスクリプト に指定する引数 */
        optional<StringHolder> readMessageTriggerScriptArgs;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            metadata(data.metadata),
            readMessageTriggerScriptId(data.readMessageTriggerScriptId),
            readMessageTriggerScriptArgs(data.readMessageTriggerScriptArgs)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            metadata(std::move(data.metadata)),
            readMessageTriggerScriptId(std::move(data.readMessageTriggerScriptId)),
            readMessageTriggerScriptArgs(std::move(data.readMessageTriggerScriptArgs))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageTriggerScriptArgs") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageTriggerScriptArgs.emplace(jsonValue.GetString());
                }
            }
        }
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
    Body() :
        m_pData(nullptr)
    {}

    Body(const Body& body) :
        Gs2Object(body),
        m_pData(body.m_pData != nullptr ? new Data(*body.m_pData) : nullptr)
    {}

    Body(Body&& body) :
        Gs2Object(std::move(body)),
        m_pData(body.m_pData)
    {
        body.m_pData = nullptr;
    }

    ~Body()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Body& operator=(const Body& body)
    {
        Gs2Object::operator=(body);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*body.m_pData);

        return *this;
    }

    Body& operator=(Body&& body)
    {
        Gs2Object::operator=(std::move(body));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = body.m_pData;
        body.m_pData = nullptr;

        return *this;
    }

    const Body* operator->() const
    {
        return this;
    }

    Body* operator->()
    {
        return this;
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * メッセージの内容に相当するメタデータを取得
     *
     * @return メッセージの内容に相当するメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ開封時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReadMessageTriggerScriptId() const
    {
        return ensureData().readMessageTriggerScriptId;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageTriggerScriptId メッセージ開封時 に実行されるスクリプト のGRN
     */
    void setReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        ensureData().readMessageTriggerScriptId.emplace(readMessageTriggerScriptId);
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を取得
     *
     * @return メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    const optional<StringHolder>& getReadMessageTriggerScriptArgs() const
    {
        return ensureData().readMessageTriggerScriptArgs;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を設定
     *
     * @param readMessageTriggerScriptArgs メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    void setReadMessageTriggerScriptArgs(const Char* readMessageTriggerScriptArgs)
    {
        ensureData().readMessageTriggerScriptArgs.emplace(readMessageTriggerScriptArgs);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_MODEL_BODY_HPP_