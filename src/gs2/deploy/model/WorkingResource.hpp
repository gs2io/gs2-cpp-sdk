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

#ifndef GS2_DEPLOY_MODEL_WORKINGRESOURCE_HPP_
#define GS2_DEPLOY_MODEL_WORKINGRESOURCE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "OutputField.hpp"
#include <cstring>

namespace gs2 { namespace deploy {

/**
 * 作成中のリソース
 *
 * @author Game Server Services, Inc.
 *
 */
class WorkingResource : public Gs2Object
{
    friend bool operator!=(const WorkingResource& lhs, const WorkingResource& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成中のリソース */
        optional<StringHolder> resourceId;
        /** 操作の種類 */
        optional<StringHolder> context;
        /** 操作対象のリソース */
        optional<StringHolder> type;
        /** 作成中のリソース名 */
        optional<StringHolder> name;
        /** リクエストパラメータ */
        optional<StringHolder> request;
        /** 依存しているリソースの名前 */
        optional<List<StringHolder>> after;
        /** ロールバック操作の種類 */
        optional<StringHolder> rollbackContext;
        /** ロールバック用のリクエストパラメータ */
        optional<StringHolder> rollbackRequest;
        /** ロールバック時に依存しているリソースの名前 */
        optional<List<StringHolder>> rollbackAfter;
        /** リソースを作成したときに Output に記録するフィールド */
        optional<List<OutputField>> outputFields;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            resourceId(data.resourceId),
            context(data.context),
            type(data.type),
            name(data.name),
            request(data.request),
            after(data.after),
            rollbackContext(data.rollbackContext),
            rollbackRequest(data.rollbackRequest),
            rollbackAfter(data.rollbackAfter),
            outputFields(data.outputFields),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            resourceId(std::move(data.resourceId)),
            context(std::move(data.context)),
            type(std::move(data.type)),
            name(std::move(data.name)),
            request(std::move(data.request)),
            after(std::move(data.after)),
            rollbackContext(std::move(data.rollbackContext)),
            rollbackRequest(std::move(data.rollbackRequest)),
            rollbackAfter(std::move(data.rollbackAfter)),
            outputFields(std::move(data.outputFields)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "resourceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->resourceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "context") == 0) {
                if (jsonValue.IsString())
                {
                    this->context.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsString())
                {
                    this->type.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "request") == 0) {
                if (jsonValue.IsString())
                {
                    this->request.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "after") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->after.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->after, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name, "rollbackContext") == 0) {
                if (jsonValue.IsString())
                {
                    this->rollbackContext.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "rollbackRequest") == 0) {
                if (jsonValue.IsString())
                {
                    this->rollbackRequest.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "rollbackAfter") == 0) {
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
            else if (std::strcmp(name, "outputFields") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->outputFields.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        OutputField item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->outputFields, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    WorkingResource() :
        m_pData(nullptr)
    {}

    WorkingResource(const WorkingResource& workingResource) :
        Gs2Object(workingResource),
        m_pData(workingResource.m_pData != nullptr ? new Data(*workingResource.m_pData) : nullptr)
    {}

    WorkingResource(WorkingResource&& workingResource) :
        Gs2Object(std::move(workingResource)),
        m_pData(workingResource.m_pData)
    {
        workingResource.m_pData = nullptr;
    }

    ~WorkingResource()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WorkingResource& operator=(const WorkingResource& workingResource)
    {
        Gs2Object::operator=(workingResource);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*workingResource.m_pData);

        return *this;
    }

    WorkingResource& operator=(WorkingResource&& workingResource)
    {
        Gs2Object::operator=(std::move(workingResource));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = workingResource.m_pData;
        workingResource.m_pData = nullptr;

        return *this;
    }

    const WorkingResource* operator->() const
    {
        return this;
    }

    WorkingResource* operator->()
    {
        return this;
    }
    /**
     * 作成中のリソースを取得
     *
     * @return 作成中のリソース
     */
    const optional<StringHolder>& getResourceId() const
    {
        return ensureData().resourceId;
    }

    /**
     * 作成中のリソースを設定
     *
     * @param resourceId 作成中のリソース
     */
    void setResourceId(const Char* resourceId)
    {
        ensureData().resourceId.emplace(resourceId);
    }

    /**
     * 作成中のリソースを設定
     *
     * @param resourceId 作成中のリソース
     */
    WorkingResource& withResourceId(const Char* resourceId)
    {
        setResourceId(resourceId);
        return *this;
    }

    /**
     * 操作の種類を取得
     *
     * @return 操作の種類
     */
    const optional<StringHolder>& getContext() const
    {
        return ensureData().context;
    }

    /**
     * 操作の種類を設定
     *
     * @param context 操作の種類
     */
    void setContext(const Char* context)
    {
        ensureData().context.emplace(context);
    }

    /**
     * 操作の種類を設定
     *
     * @param context 操作の種類
     */
    WorkingResource& withContext(const Char* context)
    {
        setContext(context);
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
    WorkingResource& withType(const Char* type)
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
    WorkingResource& withName(const Char* name)
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
    WorkingResource& withRequest(const Char* request)
    {
        setRequest(request);
        return *this;
    }

    /**
     * 依存しているリソースの名前を取得
     *
     * @return 依存しているリソースの名前
     */
    const optional<List<StringHolder>>& getAfter() const
    {
        return ensureData().after;
    }

    /**
     * 依存しているリソースの名前を設定
     *
     * @param after 依存しているリソースの名前
     */
    void setAfter(const List<StringHolder>& after)
    {
        ensureData().after.emplace(after);
    }

    /**
     * 依存しているリソースの名前を設定
     *
     * @param after 依存しているリソースの名前
     */
    WorkingResource& withAfter(const List<StringHolder>& after)
    {
        setAfter(after);
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
    WorkingResource& withRollbackContext(const Char* rollbackContext)
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
    WorkingResource& withRollbackRequest(const Char* rollbackRequest)
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
    WorkingResource& withRollbackAfter(const List<StringHolder>& rollbackAfter)
    {
        setRollbackAfter(rollbackAfter);
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
    void setOutputFields(const List<OutputField>& outputFields)
    {
        ensureData().outputFields.emplace(outputFields);
    }

    /**
     * リソースを作成したときに Output に記録するフィールドを設定
     *
     * @param outputFields リソースを作成したときに Output に記録するフィールド
     */
    WorkingResource& withOutputFields(const List<OutputField>& outputFields)
    {
        setOutputFields(outputFields);
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
    WorkingResource& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    WorkingResource& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const WorkingResource& lhs, const WorkingResource& lhr)
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
        if (lhs.m_pData->context != lhr.m_pData->context)
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
        if (lhs.m_pData->after != lhr.m_pData->after)
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
        if (lhs.m_pData->outputFields != lhr.m_pData->outputFields)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const WorkingResource& lhs, const WorkingResource& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_DEPLOY_MODEL_WORKINGRESOURCE_HPP_