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

#ifndef GS2_DATASTORE_CONTROL_PREPAREDOWNLOADOWNDATARESULT_HPP_
#define GS2_DATASTORE_CONTROL_PREPAREDOWNLOADOWNDATARESULT_HPP_

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
 * データオブジェクトをダウンロード準備する のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class PrepareDownloadOwnDataResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** データオブジェクト */
        optional<DataObject> item;
        /** ファイルをダウンロードするためのURL */
        optional<StringHolder> fileUrl;
        /** ファイルの容量 */
        optional<Int64> contentLength;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            fileUrl(data.fileUrl),
            contentLength(data.contentLength)
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
            else if (std::strcmp(name_, "fileUrl") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->fileUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "contentLength") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->contentLength = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    PrepareDownloadOwnDataResult() = default;
    PrepareDownloadOwnDataResult(const PrepareDownloadOwnDataResult& prepareDownloadOwnDataResult) = default;
    PrepareDownloadOwnDataResult(PrepareDownloadOwnDataResult&& prepareDownloadOwnDataResult) = default;
    ~PrepareDownloadOwnDataResult() = default;

    PrepareDownloadOwnDataResult& operator=(const PrepareDownloadOwnDataResult& prepareDownloadOwnDataResult) = default;
    PrepareDownloadOwnDataResult& operator=(PrepareDownloadOwnDataResult&& prepareDownloadOwnDataResult) = default;

    PrepareDownloadOwnDataResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PrepareDownloadOwnDataResult);
    }

    const PrepareDownloadOwnDataResult* operator->() const
    {
        return this;
    }

    PrepareDownloadOwnDataResult* operator->()
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
     * ファイルをダウンロードするためのURLを取得
     *
     * @return ファイルをダウンロードするためのURL
     */
    const optional<StringHolder>& getFileUrl() const
    {
        return ensureData().fileUrl;
    }

    /**
     * ファイルをダウンロードするためのURLを設定
     *
     * @param fileUrl ファイルをダウンロードするためのURL
     */
    void setFileUrl(StringHolder fileUrl)
    {
        ensureData().fileUrl.emplace(std::move(fileUrl));
    }

    /**
     * ファイルの容量を取得
     *
     * @return ファイルの容量
     */
    const optional<Int64>& getContentLength() const
    {
        return ensureData().contentLength;
    }

    /**
     * ファイルの容量を設定
     *
     * @param contentLength ファイルの容量
     */
    void setContentLength(Int64 contentLength)
    {
        ensureData().contentLength.emplace(contentLength);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<PrepareDownloadOwnDataResult> AsyncPrepareDownloadOwnDataResult;

} }

#endif //GS2_DATASTORE_CONTROL_PREPAREDOWNLOADOWNDATARESULT_HPP_