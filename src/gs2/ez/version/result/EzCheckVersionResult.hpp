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

#ifndef GS2_EZ_VERSION_EZCHECKVERSIONRESULT_HPP_
#define GS2_EZ_VERSION_EZCHECKVERSIONRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/version/result/CheckVersionResult.hpp>


namespace gs2 { namespace ez { namespace version {

class EzCheckVersionResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** プロジェクトトークン */
        StringHolder projectToken;
        /** バージョンの検証結果のリスト */
        List<EzStatus> warnings;
        /** バージョンの検証結果のリスト */
        List<EzStatus> errors;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            projectToken(data.projectToken)
        {
            warnings = data.warnings.deepCopy();
            errors = data.errors.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::version::CheckVersionResult& checkVersionResult) :
            projectToken(*checkVersionResult.getProjectToken())
        {
            {
                auto& list = *checkVersionResult.getWarnings();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    warnings += EzStatus(list[i]);
                }
            }
            {
                auto& list = *checkVersionResult.getErrors();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    errors += EzStatus(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCheckVersionResult() = default;
    EzCheckVersionResult(const EzCheckVersionResult& result) = default;
    EzCheckVersionResult(EzCheckVersionResult&& result) = default;
    ~EzCheckVersionResult() = default;

    EzCheckVersionResult(gs2::version::CheckVersionResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzCheckVersionResult& operator=(const EzCheckVersionResult& result) = default;
    EzCheckVersionResult& operator=(EzCheckVersionResult&& result) = default;

    EzCheckVersionResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCheckVersionResult);
    }

    static bool isConvertible(const gs2::version::CheckVersionResult& result)
    {
        return
            result.getProjectToken().has_value() &&
            result.getWarnings().has_value() &&
            result.getErrors().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getProjectToken() const
    {
        return ensureData().projectToken;
    }

    const List<EzStatus>& getWarnings() const
    {
        return ensureData().warnings;
    }

    const List<EzStatus>& getErrors() const
    {
        return ensureData().errors;
    }
};

typedef gs2::AsyncResult<EzCheckVersionResult> AsyncEzCheckVersionResult;

}}}

#endif //GS2_EZ_VERSION_EZCHECKVERSIONRESULT_HPP_