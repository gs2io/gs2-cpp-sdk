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

#ifndef GS2_VERSION_MODEL_TARGETVERSION_HPP_
#define GS2_VERSION_MODEL_TARGETVERSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Version.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace version {

/**
 * 検証するバージョン
 *
 * @author Game Server Services, Inc.
 *
 */
class TargetVersion : public Gs2Object
{
    friend bool operator!=(const TargetVersion& lhs, const TargetVersion& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** バージョンの名前 */
        optional<StringHolder> versionName;
        /** バージョン */
        optional<Version> version;
        /** ボディ */
        optional<StringHolder> body;
        /** 署名 */
        optional<StringHolder> signature;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            versionName(data.versionName),
            body(data.body),
            signature(data.signature)
        {
            if (data.version)
            {
                version = data.version->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "versionName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->versionName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "version") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->version.emplace();
                    detail::json::JsonParser::parse(&this->version->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "body") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    TargetVersion() = default;
    TargetVersion(const TargetVersion& targetVersion) = default;
    TargetVersion(TargetVersion&& targetVersion) = default;
    ~TargetVersion() = default;

    TargetVersion& operator=(const TargetVersion& targetVersion) = default;
    TargetVersion& operator=(TargetVersion&& targetVersion) = default;

    TargetVersion deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(TargetVersion);
    }

    const TargetVersion* operator->() const
    {
        return this;
    }

    TargetVersion* operator->()
    {
        return this;
    }
    /**
     * バージョンの名前を取得
     *
     * @return バージョンの名前
     */
    const optional<StringHolder>& getVersionName() const
    {
        return ensureData().versionName;
    }

    /**
     * バージョンの名前を設定
     *
     * @param versionName バージョンの名前
     */
    void setVersionName(StringHolder versionName)
    {
        ensureData().versionName.emplace(std::move(versionName));
    }

    /**
     * バージョンの名前を設定
     *
     * @param versionName バージョンの名前
     */
    TargetVersion& withVersionName(StringHolder versionName)
    {
        setVersionName(std::move(versionName));
        return *this;
    }

    /**
     * バージョンを取得
     *
     * @return バージョン
     */
    const optional<Version>& getVersion() const
    {
        return ensureData().version;
    }

    /**
     * バージョンを設定
     *
     * @param version バージョン
     */
    void setVersion(Version version)
    {
        ensureData().version.emplace(std::move(version));
    }

    /**
     * バージョンを設定
     *
     * @param version バージョン
     */
    TargetVersion& withVersion(Version version)
    {
        setVersion(std::move(version));
        return *this;
    }

    /**
     * ボディを取得
     *
     * @return ボディ
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * ボディを設定
     *
     * @param body ボディ
     */
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
    }

    /**
     * ボディを設定
     *
     * @param body ボディ
     */
    TargetVersion& withBody(StringHolder body)
    {
        setBody(std::move(body));
        return *this;
    }

    /**
     * 署名を取得
     *
     * @return 署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    TargetVersion& withSignature(StringHolder signature)
    {
        setSignature(std::move(signature));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const TargetVersion& lhs, const TargetVersion& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->versionName != lhr.m_pData->versionName)
        {
            return true;
        }
        if (lhs.m_pData->version != lhr.m_pData->version)
        {
            return true;
        }
        if (lhs.m_pData->body != lhr.m_pData->body)
        {
            return true;
        }
        if (lhs.m_pData->signature != lhr.m_pData->signature)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const TargetVersion& lhs, const TargetVersion& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_VERSION_MODEL_TARGETVERSION_HPP_