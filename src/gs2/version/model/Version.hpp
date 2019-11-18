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

#ifndef GS2_VERSION_MODEL_VERSION_HPP_
#define GS2_VERSION_MODEL_VERSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace version {

/**
 * バージョン
 *
 * @author Game Server Services, Inc.
 *
 */
class Version : public Gs2Object
{
    friend bool operator!=(const Version& lhs, const Version& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** メジャーバージョン */
        optional<Int32> major;
        /** マイナーバージョン */
        optional<Int32> minor;
        /** マイクロバージョン */
        optional<Int32> micro;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            major(data.major),
            minor(data.minor),
            micro(data.micro)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "major") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->major = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "minor") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->minor = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "micro") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->micro = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Version() = default;
    Version(const Version& version) = default;
    Version(Version&& version) = default;
    ~Version() = default;

    Version& operator=(const Version& version) = default;
    Version& operator=(Version&& version) = default;

    Version deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Version);
    }

    const Version* operator->() const
    {
        return this;
    }

    Version* operator->()
    {
        return this;
    }
    /**
     * メジャーバージョンを取得
     *
     * @return メジャーバージョン
     */
    const optional<Int32>& getMajor() const
    {
        return ensureData().major;
    }

    /**
     * メジャーバージョンを設定
     *
     * @param major メジャーバージョン
     */
    void setMajor(Int32 major)
    {
        ensureData().major.emplace(major);
    }

    /**
     * メジャーバージョンを設定
     *
     * @param major メジャーバージョン
     */
    Version& withMajor(Int32 major)
    {
        setMajor(major);
        return *this;
    }

    /**
     * マイナーバージョンを取得
     *
     * @return マイナーバージョン
     */
    const optional<Int32>& getMinor() const
    {
        return ensureData().minor;
    }

    /**
     * マイナーバージョンを設定
     *
     * @param minor マイナーバージョン
     */
    void setMinor(Int32 minor)
    {
        ensureData().minor.emplace(minor);
    }

    /**
     * マイナーバージョンを設定
     *
     * @param minor マイナーバージョン
     */
    Version& withMinor(Int32 minor)
    {
        setMinor(minor);
        return *this;
    }

    /**
     * マイクロバージョンを取得
     *
     * @return マイクロバージョン
     */
    const optional<Int32>& getMicro() const
    {
        return ensureData().micro;
    }

    /**
     * マイクロバージョンを設定
     *
     * @param micro マイクロバージョン
     */
    void setMicro(Int32 micro)
    {
        ensureData().micro.emplace(micro);
    }

    /**
     * マイクロバージョンを設定
     *
     * @param micro マイクロバージョン
     */
    Version& withMicro(Int32 micro)
    {
        setMicro(micro);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Version& lhs, const Version& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->major != lhr.m_pData->major)
        {
            return true;
        }
        if (lhs.m_pData->minor != lhr.m_pData->minor)
        {
            return true;
        }
        if (lhs.m_pData->micro != lhr.m_pData->micro)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Version& lhs, const Version& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_VERSION_MODEL_VERSION_HPP_