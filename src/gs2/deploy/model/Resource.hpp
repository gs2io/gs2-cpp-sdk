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

#ifndef GS2_DEPLOY_MODEL_RESOURCE_HPP_
#define GS2_DEPLOY_MODEL_RESOURCE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "OutputField.hpp"
#include <memory>

namespace gs2 { namespace deploy {

/**
 * 作成されたのリソース
 *
 * @author Game Server Services, Inc.
 *
 */
class Resource : public Gs2Object
{
    friend bool operator!=(const Resource& lhs, const Resource& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成されたのリソース */
        optional<StringHolder> resourceId;
        /** 操作対象のリソース */
        optional<StringHolder> type;
        /** 作成中のリソース名 */
        optional<StringHolder> name;
        /** リクエストパラメータ */
        optional<StringHolder> request;
        /** リソースの作成・更新のレスポンス */
        optional<StringHolder> response;
        /** ロールバック操作の種類 */
        optional<StringHolder> rollbackContext;
        /** ロールバック用のリクエストパラメータ */
        optional<StringHolder> rollbackRequest;
        /** ロールバック時に依存しているリソースの名前 */
        optional<List<StringHolder>> rollbackAfter;
        /** リソースを作成したときに Output に記録するフィールド */
        optional<List<OutputField>> outputFields;
        /** このリソースが作成された時の実行 ID */
        optional<StringHolder> workId;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Resource() = default;
    Resource(const Resource& resource) = default;
    Resource(Resource&& resource) = default;
    ~Resource() = default;

    Resource& operator=(const Resource& resource) = default;
    Resource& operator=(Resource&& resource) = default;

    Resource deepCopy() const;

    const Resource* operator->() const
    {
        return this;
    }

    Resource* operator->()
    {
        return this;
    }
    /**
     * 作成されたのリソースを取得
     *
     * @return 作成されたのリソース
     */
    const optional<StringHolder>& getResourceId() const
    {
        return ensureData().resourceId;
    }

    /**
     * 作成されたのリソースを設定
     *
     * @param resourceId 作成されたのリソース
     */
    void setResourceId(StringHolder resourceId)
    {
        ensureData().resourceId.emplace(std::move(resourceId));
    }

    /**
     * 作成されたのリソースを設定
     *
     * @param resourceId 作成されたのリソース
     */
    Resource& withResourceId(StringHolder resourceId)
    {
        setResourceId(std::move(resourceId));
        return *this;
    }

    /**
     * 操作対象のリソースを取得
     *
     * @return 操作対象のリソース
     */
    const optional<StringHolder>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 操作対象のリソースを設定
     *
     * @param type 操作対象のリソース
     */
    void setType(StringHolder type)
    {
        ensureData().type.emplace(std::move(type));
    }

    /**
     * 操作対象のリソースを設定
     *
     * @param type 操作対象のリソース
     */
    Resource& withType(StringHolder type)
    {
        setType(std::move(type));
        return *this;
    }

    /**
     * 作成中のリソース名を取得
     *
     * @return 作成中のリソース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 作成中のリソース名を設定
     *
     * @param name 作成中のリソース名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 作成中のリソース名を設定
     *
     * @param name 作成中のリソース名
     */
    Resource& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * リクエストパラメータを取得
     *
     * @return リクエストパラメータ
     */
    const optional<StringHolder>& getRequest() const
    {
        return ensureData().request;
    }

    /**
     * リクエストパラメータを設定
     *
     * @param request リクエストパラメータ
     */
    void setRequest(StringHolder request)
    {
        ensureData().request.emplace(std::move(request));
    }

    /**
     * リクエストパラメータを設定
     *
     * @param request リクエストパラメータ
     */
    Resource& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }

    /**
     * リソースの作成・更新のレスポンスを取得
     *
     * @return リソースの作成・更新のレスポンス
     */
    const optional<StringHolder>& getResponse() const
    {
        return ensureData().response;
    }

    /**
     * リソースの作成・更新のレスポンスを設定
     *
     * @param response リソースの作成・更新のレスポンス
     */
    void setResponse(StringHolder response)
    {
        ensureData().response.emplace(std::move(response));
    }

    /**
     * リソースの作成・更新のレスポンスを設定
     *
     * @param response リソースの作成・更新のレスポンス
     */
    Resource& withResponse(StringHolder response)
    {
        setResponse(std::move(response));
        return *this;
    }

    /**
     * ロールバック操作の種類を取得
     *
     * @return ロールバック操作の種類
     */
    const optional<StringHolder>& getRollbackContext() const
    {
        return ensureData().rollbackContext;
    }

    /**
     * ロールバック操作の種類を設定
     *
     * @param rollbackContext ロールバック操作の種類
     */
    void setRollbackContext(StringHolder rollbackContext)
    {
        ensureData().rollbackContext.emplace(std::move(rollbackContext));
    }

    /**
     * ロールバック操作の種類を設定
     *
     * @param rollbackContext ロールバック操作の種類
     */
    Resource& withRollbackContext(StringHolder rollbackContext)
    {
        setRollbackContext(std::move(rollbackContext));
        return *this;
    }

    /**
     * ロールバック用のリクエストパラメータを取得
     *
     * @return ロールバック用のリクエストパラメータ
     */
    const optional<StringHolder>& getRollbackRequest() const
    {
        return ensureData().rollbackRequest;
    }

    /**
     * ロールバック用のリクエストパラメータを設定
     *
     * @param rollbackRequest ロールバック用のリクエストパラメータ
     */
    void setRollbackRequest(StringHolder rollbackRequest)
    {
        ensureData().rollbackRequest.emplace(std::move(rollbackRequest));
    }

    /**
     * ロールバック用のリクエストパラメータを設定
     *
     * @param rollbackRequest ロールバック用のリクエストパラメータ
     */
    Resource& withRollbackRequest(StringHolder rollbackRequest)
    {
        setRollbackRequest(std::move(rollbackRequest));
        return *this;
    }

    /**
     * ロールバック時に依存しているリソースの名前を取得
     *
     * @return ロールバック時に依存しているリソースの名前
     */
    const optional<List<StringHolder>>& getRollbackAfter() const
    {
        return ensureData().rollbackAfter;
    }

    /**
     * ロールバック時に依存しているリソースの名前を設定
     *
     * @param rollbackAfter ロールバック時に依存しているリソースの名前
     */
    void setRollbackAfter(List<StringHolder> rollbackAfter)
    {
        ensureData().rollbackAfter.emplace(std::move(rollbackAfter));
    }

    /**
     * ロールバック時に依存しているリソースの名前を設定
     *
     * @param rollbackAfter ロールバック時に依存しているリソースの名前
     */
    Resource& withRollbackAfter(List<StringHolder> rollbackAfter)
    {
        setRollbackAfter(std::move(rollbackAfter));
        return *this;
    }

    /**
     * リソースを作成したときに Output に記録するフィールドを取得
     *
     * @return リソースを作成したときに Output に記録するフィールド
     */
    const optional<List<OutputField>>& getOutputFields() const
    {
        return ensureData().outputFields;
    }

    /**
     * リソースを作成したときに Output に記録するフィールドを設定
     *
     * @param outputFields リソースを作成したときに Output に記録するフィールド
     */
    void setOutputFields(List<OutputField> outputFields)
    {
        ensureData().outputFields.emplace(std::move(outputFields));
    }

    /**
     * リソースを作成したときに Output に記録するフィールドを設定
     *
     * @param outputFields リソースを作成したときに Output に記録するフィールド
     */
    Resource& withOutputFields(List<OutputField> outputFields)
    {
        setOutputFields(std::move(outputFields));
        return *this;
    }

    /**
     * このリソースが作成された時の実行 IDを取得
     *
     * @return このリソースが作成された時の実行 ID
     */
    const optional<StringHolder>& getWorkId() const
    {
        return ensureData().workId;
    }

    /**
     * このリソースが作成された時の実行 IDを設定
     *
     * @param workId このリソースが作成された時の実行 ID
     */
    void setWorkId(StringHolder workId)
    {
        ensureData().workId.emplace(std::move(workId));
    }

    /**
     * このリソースが作成された時の実行 IDを設定
     *
     * @param workId このリソースが作成された時の実行 ID
     */
    Resource& withWorkId(StringHolder workId)
    {
        setWorkId(std::move(workId));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Resource& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Resource& lhs, const Resource& lhr);

inline bool operator==(const Resource& lhs, const Resource& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_RESOURCE_HPP_