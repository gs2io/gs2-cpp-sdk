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

#ifndef GS2_DATASTORE_CONTROL_PREPAREUPLOADBYUSERIDRESULT_HPP_
#define GS2_DATASTORE_CONTROL_PREPAREUPLOADBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/datastore/model/model.hpp>
#include <memory>

namespace gs2 { namespace datastore
{

/**
 * ユーザIDを指定してデータオブジェクトをアップロード準備する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class PrepareUploadByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** データオブジェクト */
        optional<DataObject> item;
        /** アップロード処理の実行に使用するURL */
        optional<StringHolder> uploadUrl;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            uploadUrl(data.uploadUrl)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "uploadUrl") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->uploadUrl.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    PrepareUploadByUserIdResult() = default;
    PrepareUploadByUserIdResult(const PrepareUploadByUserIdResult& prepareUploadByUserIdResult) = default;
    PrepareUploadByUserIdResult(PrepareUploadByUserIdResult&& prepareUploadByUserIdResult) = default;
    ~PrepareUploadByUserIdResult() = default;

    PrepareUploadByUserIdResult& operator=(const PrepareUploadByUserIdResult& prepareUploadByUserIdResult) = default;
    PrepareUploadByUserIdResult& operator=(PrepareUploadByUserIdResult&& prepareUploadByUserIdResult) = default;

    PrepareUploadByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PrepareUploadByUserIdResult);
    }

    const PrepareUploadByUserIdResult* operator->() const
    {
        return this;
    }

    PrepareUploadByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * データオブジェクトを取得
     *
     * @return データオブジェクト
     */
    const optional<DataObject>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * データオブジェクトを設定
     *
     * @param item データオブジェクト
     */
    void setItem(DataObject item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * アップロード処理の実行に使用するURLを取得
     *
     * @return アップロード処理の実行に使用するURL
     */
    const optional<StringHolder>& getUploadUrl() const
    {
        return ensureData().uploadUrl;
    }

    /**
     * アップロード処理の実行に使用するURLを設定
     *
     * @param uploadUrl アップロード処理の実行に使用するURL
     */
    void setUploadUrl(StringHolder uploadUrl)
    {
        ensureData().uploadUrl.emplace(std::move(uploadUrl));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<PrepareUploadByUserIdResult> AsyncPrepareUploadByUserIdResult;

} }

#endif //GS2_DATASTORE_CONTROL_PREPAREUPLOADBYUSERIDRESULT_HPP_