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

#ifndef GS2_NEWS_CONTROL_PREPAREUPDATECURRENTNEWSMASTERRESULT_HPP_
#define GS2_NEWS_CONTROL_PREPAREUPDATECURRENTNEWSMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/news/model/model.hpp>
#include <memory>

namespace gs2 { namespace news
{

/**
 * 現在有効なお知らせを更新準備する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class PrepareUpdateCurrentNewsMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アップロード後に結果を反映する際に使用するトークン */
        optional<StringHolder> uploadToken;
        /** テンプレートアップロード処理の実行に使用するURL */
        optional<StringHolder> templateUploadUrl;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            uploadToken(data.uploadToken),
            templateUploadUrl(data.templateUploadUrl)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "uploadToken") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->uploadToken.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "templateUploadUrl") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->templateUploadUrl.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    PrepareUpdateCurrentNewsMasterResult() = default;
    PrepareUpdateCurrentNewsMasterResult(const PrepareUpdateCurrentNewsMasterResult& prepareUpdateCurrentNewsMasterResult) = default;
    PrepareUpdateCurrentNewsMasterResult(PrepareUpdateCurrentNewsMasterResult&& prepareUpdateCurrentNewsMasterResult) = default;
    ~PrepareUpdateCurrentNewsMasterResult() = default;

    PrepareUpdateCurrentNewsMasterResult& operator=(const PrepareUpdateCurrentNewsMasterResult& prepareUpdateCurrentNewsMasterResult) = default;
    PrepareUpdateCurrentNewsMasterResult& operator=(PrepareUpdateCurrentNewsMasterResult&& prepareUpdateCurrentNewsMasterResult) = default;

    PrepareUpdateCurrentNewsMasterResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PrepareUpdateCurrentNewsMasterResult);
    }

    const PrepareUpdateCurrentNewsMasterResult* operator->() const
    {
        return this;
    }

    PrepareUpdateCurrentNewsMasterResult* operator->()
    {
        return this;
    }
    /**
     * アップロード後に結果を反映する際に使用するトークンを取得
     *
     * @return アップロード後に結果を反映する際に使用するトークン
     */
    const optional<StringHolder>& getUploadToken() const
    {
        return ensureData().uploadToken;
    }

    /**
     * アップロード後に結果を反映する際に使用するトークンを設定
     *
     * @param uploadToken アップロード後に結果を反映する際に使用するトークン
     */
    void setUploadToken(StringHolder uploadToken)
    {
        ensureData().uploadToken.emplace(std::move(uploadToken));
    }

    /**
     * テンプレートアップロード処理の実行に使用するURLを取得
     *
     * @return テンプレートアップロード処理の実行に使用するURL
     */
    const optional<StringHolder>& getTemplateUploadUrl() const
    {
        return ensureData().templateUploadUrl;
    }

    /**
     * テンプレートアップロード処理の実行に使用するURLを設定
     *
     * @param templateUploadUrl テンプレートアップロード処理の実行に使用するURL
     */
    void setTemplateUploadUrl(StringHolder templateUploadUrl)
    {
        ensureData().templateUploadUrl.emplace(std::move(templateUploadUrl));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<PrepareUpdateCurrentNewsMasterResult> AsyncPrepareUpdateCurrentNewsMasterResult;

} }

#endif //GS2_NEWS_CONTROL_PREPAREUPDATECURRENTNEWSMASTERRESULT_HPP_