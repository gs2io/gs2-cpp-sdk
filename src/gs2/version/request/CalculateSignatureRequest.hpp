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

#ifndef GS2_VERSION_CONTROL_CALCULATESIGNATUREREQUEST_HPP_
#define GS2_VERSION_CONTROL_CALCULATESIGNATUREREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/version/Gs2VersionConst.hpp>
#include <gs2/version/model/model.hpp>
#include <memory>

namespace gs2 { namespace version
{

/**
 * スタンプシートのタスクを実行する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CalculateSignatureRequest : public Gs2BasicRequest, public Gs2Version
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** バージョンの種類名 */
        optional<StringHolder> versionName;
        /** バージョン */
        optional<Version> version;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            versionName(data.versionName)
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
    CalculateSignatureRequest() = default;
    CalculateSignatureRequest(const CalculateSignatureRequest& calculateSignatureRequest) = default;
    CalculateSignatureRequest(CalculateSignatureRequest&& calculateSignatureRequest) = default;
    ~CalculateSignatureRequest() GS2_OVERRIDE = default;

    CalculateSignatureRequest& operator=(const CalculateSignatureRequest& calculateSignatureRequest) = default;
    CalculateSignatureRequest& operator=(CalculateSignatureRequest&& calculateSignatureRequest) = default;

    CalculateSignatureRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CalculateSignatureRequest);
    }

    const CalculateSignatureRequest* operator->() const
    {
        return this;
    }

    CalculateSignatureRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    CalculateSignatureRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * バージョンの種類名を取得
     *
     * @return バージョンの種類名
     */
    const optional<StringHolder>& getVersionName() const
    {
        return ensureData().versionName;
    }

    /**
     * バージョンの種類名を設定
     *
     * @param versionName バージョンの種類名
     */
    void setVersionName(StringHolder versionName)
    {
        ensureData().versionName.emplace(std::move(versionName));
    }

    /**
     * バージョンの種類名を設定
     *
     * @param versionName バージョンの種類名
     */
    CalculateSignatureRequest& withVersionName(StringHolder versionName)
    {
        ensureData().versionName.emplace(std::move(versionName));
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
    CalculateSignatureRequest& withVersion(Version version)
    {
        ensureData().version.emplace(std::move(version));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CalculateSignatureRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CalculateSignatureRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_VERSION_CONTROL_CALCULATESIGNATUREREQUEST_HPP_