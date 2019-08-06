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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

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
        /** このリソースに関連するアウトプットに記録したキー名 */
        optional<List<StringHolder>> outputKeys;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            resourceId(data.resourceId),
            type(data.type),
            name(data.name),
            request(data.request),
            response(data.response),
            rollbackContext(data.rollbackContext),
            rollbackRequest(data.rollbackRequest),
            rollbackAfter(data.rollbackAfter),
            outputKeys(data.outputKeys),
            createdAt(data.createdAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            resourceId(std::move(data.resourceId)),
            type(std::move(data.type)),
            name(std::move(data.name)),
            request(std::move(data.request)),
            response(std::move(data.response)),
            rollbackContext(std::move(data.rollbackContext)),
            rollbackRequest(std::move(data.rollbackRequest)),
            rollbackAfter(std::move(data.rollbackAfter)),
            outputKeys(std::move(data.outputKeys)),
            createdAt(std::move(data.createdAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "resourceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "request") == 0) {
                if (jsonValue.IsString())
                {
                    this->request.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "response") == 0) {
                if (jsonValue.IsString())
                {
                    this->response.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "rollbackContext") == 0) {
                if (jsonValue.IsString())
                {
                    this->rollbackContext.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "rollbackRequest") == 0) {
                if (jsonValue.IsString())
                {
                    this->rollbackRequest.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "rollbackAfter") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->rollbackAfter.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->rollbackAfter, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "outputKeys") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->outputKeys.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->outputKeys, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    Resource() :
        m_pData(nullptr)
    {}

    Resource(const Resource& resource) :
        Gs2Object(resource),
        m_pData(resource.m_pData != nullptr ? new Data(*resource.m_pData) : nullptr)
    {}

    Resource(Resource&& resource) :
        Gs2Object(std::move(resource)),
        m_pData(resource.m_pData)
    {
        resource.m_pData = nullptr;
    }

    ~Resource()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Resource& operator=(const Resource& resource)
    {
        Gs2Object::operator=(resource);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*resource.m_pData);

        return *this;
    }

    Resource& operator=(Resource&& resource)
    {
        Gs2Object::operator=(std::move(resource));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = resource.m_pData;
        resource.m_pData = nullptr;

        return *this;
    }

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
    void setResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
    }

    /**
     * 作成されたのリソースを設定
     *
     * @param resourceId 作成されたのリソース
     */
    Resource& withResourceId(const Char* resourceId)
    {
        setResourceId(resourceId);
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
    void setType(const Char* type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * 操作対象のリソースを設定
     *
     * @param type 操作対象のリソース
     */
    Resource& withType(const Char* type)
    {
        setType(type);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 作成中のリソース名を設定
     *
     * @param name 作成中のリソース名
     */
    Resource& withName(const Char* name)
    {
        setName(name);
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
    void setRequest(const Char* request)
    {
        ensureData().request.emplace(request);
    }

    /**
     * リクエストパラメータを設定
     *
     * @param request リクエストパラメータ
     */
    Resource& withRequest(const Char* request)
    {
        setRequest(request);
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
    void setResponse(const Char* response)
    {
        ensureData().response.emplace(response);
    }

    /**
     * リソースの作成・更新のレスポンスを設定
     *
     * @param response リソースの作成・更新のレスポンス
     */
    Resource& withResponse(const Char* response)
    {
        setResponse(response);
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
    void setRollbackContext(const Char* rollbackContext)
    {
        ensureData().rollbackContext.emplace(rollbackContext);
    }

    /**
     * ロールバック操作の種類を設定
     *
     * @param rollbackContext ロールバック操作の種類
     */
    Resource& withRollbackContext(const Char* rollbackContext)
    {
        setRollbackContext(rollbackContext);
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
    void setRollbackRequest(const Char* rollbackRequest)
    {
        ensureData().rollbackRequest.emplace(rollbackRequest);
    }

    /**
     * ロールバック用のリクエストパラメータを設定
     *
     * @param rollbackRequest ロールバック用のリクエストパラメータ
     */
    Resource& withRollbackRequest(const Char* rollbackRequest)
    {
        setRollbackRequest(rollbackRequest);
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
    void setRollbackAfter(const List<StringHolder>& rollbackAfter)
    {
        ensureData().rollbackAfter.emplace(rollbackAfter);
    }

    /**
     * ロールバック時に依存しているリソースの名前を設定
     *
     * @param rollbackAfter ロールバック時に依存しているリソースの名前
     */
    Resource& withRollbackAfter(const List<StringHolder>& rollbackAfter)
    {
        setRollbackAfter(rollbackAfter);
        return *this;
    }

    /**
     * このリソースに関連するアウトプットに記録したキー名を取得
     *
     * @return このリソースに関連するアウトプットに記録したキー名
     */
    const optional<List<StringHolder>>& getOutputKeys() const
    {
        return ensureData().outputKeys;
    }

    /**
     * このリソースに関連するアウトプットに記録したキー名を設定
     *
     * @param outputKeys このリソースに関連するアウトプットに記録したキー名
     */
    void setOutputKeys(const List<StringHolder>& outputKeys)
    {
        ensureData().outputKeys.emplace(outputKeys);
    }

    /**
     * このリソースに関連するアウトプットに記録したキー名を設定
     *
     * @param outputKeys このリソースに関連するアウトプットに記録したキー名
     */
    Resource& withOutputKeys(const List<StringHolder>& outputKeys)
    {
        setOutputKeys(outputKeys);
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

inline bool operator!=(const Resource& lhs, const Resource& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->resourceId != lhr.m_pData->resourceId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->request != lhr.m_pData->request)
        {
            return true;
        }
        if (lhs.m_pData->response != lhr.m_pData->response)
        {
            return true;
        }
        if (lhs.m_pData->rollbackContext != lhr.m_pData->rollbackContext)
        {
            return true;
        }
        if (lhs.m_pData->rollbackRequest != lhr.m_pData->rollbackRequest)
        {
            return true;
        }
        if (lhs.m_pData->rollbackAfter != lhr.m_pData->rollbackAfter)
        {
            return true;
        }
        if (lhs.m_pData->outputKeys != lhr.m_pData->outputKeys)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Resource& lhs, const Resource& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_RESOURCE_HPP_