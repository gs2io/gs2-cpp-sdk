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

#ifndef GS2_VERSION_CONTROL_CHECKVERSIONBYUSERIDRESULT_HPP_
#define GS2_VERSION_CONTROL_CHECKVERSIONBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/version/model/model.hpp>
#include <memory>

namespace gs2 { namespace version
{

/**
 * バージョンチェック のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CheckVersionByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** プロジェクトトークン */
        optional<StringHolder> projectToken;
        /** バージョンの検証結果のリスト */
        optional<List<Status>> warnings;
        /** バージョンの検証結果のリスト */
        optional<List<Status>> errors;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            projectToken(data.projectToken)
        {
            if (data.warnings)
            {
                warnings = data.warnings->deepCopy();
            }
            if (data.errors)
            {
                errors = data.errors->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "projectToken") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->projectToken.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "warnings") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->warnings.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Status item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->warnings, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "errors") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->errors.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Status item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->errors, std::move(item));
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CheckVersionByUserIdResult() = default;
    CheckVersionByUserIdResult(const CheckVersionByUserIdResult& checkVersionByUserIdResult) = default;
    CheckVersionByUserIdResult(CheckVersionByUserIdResult&& checkVersionByUserIdResult) = default;
    ~CheckVersionByUserIdResult() = default;

    CheckVersionByUserIdResult& operator=(const CheckVersionByUserIdResult& checkVersionByUserIdResult) = default;
    CheckVersionByUserIdResult& operator=(CheckVersionByUserIdResult&& checkVersionByUserIdResult) = default;

    CheckVersionByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CheckVersionByUserIdResult);
    }

    const CheckVersionByUserIdResult* operator->() const
    {
        return this;
    }

    CheckVersionByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * プロジェクトトークンを取得
     *
     * @return プロジェクトトークン
     */
    const optional<StringHolder>& getProjectToken() const
    {
        return ensureData().projectToken;
    }

    /**
     * プロジェクトトークンを設定
     *
     * @param projectToken プロジェクトトークン
     */
    void setProjectToken(StringHolder projectToken)
    {
        ensureData().projectToken.emplace(std::move(projectToken));
    }

    /**
     * バージョンの検証結果のリストを取得
     *
     * @return バージョンの検証結果のリスト
     */
    const optional<List<Status>>& getWarnings() const
    {
        return ensureData().warnings;
    }

    /**
     * バージョンの検証結果のリストを設定
     *
     * @param warnings バージョンの検証結果のリスト
     */
    void setWarnings(List<Status> warnings)
    {
        ensureData().warnings.emplace(std::move(warnings));
    }

    /**
     * バージョンの検証結果のリストを取得
     *
     * @return バージョンの検証結果のリスト
     */
    const optional<List<Status>>& getErrors() const
    {
        return ensureData().errors;
    }

    /**
     * バージョンの検証結果のリストを設定
     *
     * @param errors バージョンの検証結果のリスト
     */
    void setErrors(List<Status> errors)
    {
        ensureData().errors.emplace(std::move(errors));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<CheckVersionByUserIdResult> AsyncCheckVersionByUserIdResult;

} }

#endif //GS2_VERSION_CONTROL_CHECKVERSIONBYUSERIDRESULT_HPP_