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
        optional<Int32> major_;
        /** マイナーバージョン */
        optional<Int32> minor_;
        /** マイクロバージョン */
        optional<Int32> micro;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            major_(data.major_),
            minor_(data.minor_),
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
                    this->major_ = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "minor") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->minor_ = jsonValue.GetInt();
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
        return ensureData().major_;
    }

    /**
     * メジャーバージョンを設定
     *
     * @param major_ メジャーバージョン
     */
    void setMajor(Int32 major_)
    {
        ensureData().major_.emplace(major_);
    }

    /**
     * メジャーバージョンを設定
     *
     * @param major_ メジャーバージョン
     */
    Version& withMajor(Int32 major_)
    {
        setMajor(major_);
        return *this;
    }

    /**
     * マイナーバージョンを取得
     *
     * @return マイナーバージョン
     */
    const optional<Int32>& getMinor() const
    {
        return ensureData().minor_;
    }

    /**
     * マイナーバージョンを設定
     *
     * @param minor_ マイナーバージョン
     */
    void setMinor(Int32 minor_)
    {
        ensureData().minor_.emplace(minor_);
    }

    /**
     * マイナーバージョンを設定
     *
     * @param minor_ マイナーバージョン
     */
    Version& withMinor(Int32 minor_)
    {
        setMinor(minor_);
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
        if (lhs.m_pData->major_ != lhr.m_pData->major_)
        {
            return true;
        }
        if (lhs.m_pData->minor_ != lhr.m_pData->minor_)
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