

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

#ifndef GS2_EZ_VERSION_MODEL_EZVERSION_HPP_
#define GS2_EZ_VERSION_MODEL_EZVERSION_HPP_

#include <gs2/version/model/Version.hpp>


namespace gs2 { namespace ez { namespace version {

class EzVersion : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** メジャーバージョン */
        gs2::optional<Int32> major_;
        /** マイナーバージョン */
        gs2::optional<Int32> minor_;
        /** マイクロバージョン */
        gs2::optional<Int32> micro;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            major_(data.major_),
            minor_(data.minor_),
            micro(data.micro)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::version::Version& version) :
            major_(version.getMajor() ? *version.getMajor() : 0),
            minor_(version.getMinor() ? *version.getMinor() : 0),
            micro(version.getMicro() ? *version.getMicro() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzVersion() = default;
    EzVersion(const EzVersion& ezVersion) = default;
    EzVersion(EzVersion&& ezVersion) = default;
    ~EzVersion() = default;

    EzVersion(gs2::version::Version version) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(version)
    {}

    EzVersion& operator=(const EzVersion& ezVersion) = default;
    EzVersion& operator=(EzVersion&& ezVersion) = default;

    EzVersion deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzVersion);
    }

    gs2::version::Version ToModel() const
    {
        gs2::version::Version version;
        version.setMajor(getMajor());
        version.setMinor(getMinor());
        version.setMicro(getMicro());
        return version;
    }

    // ========================================
    //   Getters
    // ========================================

    Int32 getMajor() const
    {
        return *ensureData().major_;
    }

    Int32 getMinor() const
    {
        return *ensureData().minor_;
    }

    Int32 getMicro() const
    {
        return *ensureData().micro;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMajor(Int32 major_)
    {
        ensureData().major_ = major_;
    }

    void setMinor(Int32 minor_)
    {
        ensureData().minor_ = minor_;
    }

    void setMicro(Int32 micro)
    {
        ensureData().micro = micro;
    }

    EzVersion& withMajor(Int32 major_)
    {
        setMajor(major_);
        return *this;
    }

    EzVersion& withMinor(Int32 minor_)
    {
        setMinor(minor_);
        return *this;
    }

    EzVersion& withMicro(Int32 micro)
    {
        setMicro(micro);
        return *this;
    }
};

}}}

#endif //GS2_EZ_VERSION_EZVERSION_HPP_