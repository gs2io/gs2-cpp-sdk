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

#ifndef GS2_FORMATION_CONTROL_GETFORMWITHSIGNATUREBYUSERIDRESULT_HPP_
#define GS2_FORMATION_CONTROL_GETFORMWITHSIGNATUREBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/formation/model/model.hpp>
#include <memory>

namespace gs2 { namespace formation
{

/**
 * ユーザIDを指定して署名付きフォームを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetFormWithSignatureByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** フォーム */
        optional<Form> item;
        /** 署名対象の値 */
        optional<StringHolder> body;
        /** 署名 */
        optional<StringHolder> signature;
        /** 保存したフォーム */
        optional<Mold> mold;
        /** フォームの保存領域 */
        optional<MoldModel> moldModel;
        /** フォームモデル */
        optional<FormModel> formModel;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            body(data.body),
            signature(data.signature)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
            if (data.mold)
            {
                mold = data.mold->deepCopy();
            }
            if (data.moldModel)
            {
                moldModel = data.moldModel->deepCopy();
            }
            if (data.formModel)
            {
                formModel = data.formModel->deepCopy();
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
            else if (std::strcmp(name_, "body") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "mold") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->mold.emplace();
                    detail::json::JsonParser::parse(&this->mold->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "moldModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->moldModel.emplace();
                    detail::json::JsonParser::parse(&this->moldModel->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "formModel") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->formModel.emplace();
                    detail::json::JsonParser::parse(&this->formModel->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GetFormWithSignatureByUserIdResult() = default;
    GetFormWithSignatureByUserIdResult(const GetFormWithSignatureByUserIdResult& getFormWithSignatureByUserIdResult) = default;
    GetFormWithSignatureByUserIdResult(GetFormWithSignatureByUserIdResult&& getFormWithSignatureByUserIdResult) = default;
    ~GetFormWithSignatureByUserIdResult() = default;

    GetFormWithSignatureByUserIdResult& operator=(const GetFormWithSignatureByUserIdResult& getFormWithSignatureByUserIdResult) = default;
    GetFormWithSignatureByUserIdResult& operator=(GetFormWithSignatureByUserIdResult&& getFormWithSignatureByUserIdResult) = default;

    GetFormWithSignatureByUserIdResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetFormWithSignatureByUserIdResult);
    }

    const GetFormWithSignatureByUserIdResult* operator->() const
    {
        return this;
    }

    GetFormWithSignatureByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * フォームを取得
     *
     * @return フォーム
     */
    const optional<Form>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * フォームを設定
     *
     * @param item フォーム
     */
    void setItem(Form item)
    {
        ensureData().item.emplace(std::move(item));
    }

    /**
     * 署名対象の値を取得
     *
     * @return 署名対象の値
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 署名対象の値を設定
     *
     * @param body 署名対象の値
     */
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
    }

    /**
     * 署名を取得
     *
     * @return 署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }

    /**
     * 保存したフォームを取得
     *
     * @return 保存したフォーム
     */
    const optional<Mold>& getMold() const
    {
        return ensureData().mold;
    }

    /**
     * 保存したフォームを設定
     *
     * @param mold 保存したフォーム
     */
    void setMold(Mold mold)
    {
        ensureData().mold.emplace(std::move(mold));
    }

    /**
     * フォームの保存領域を取得
     *
     * @return フォームの保存領域
     */
    const optional<MoldModel>& getMoldModel() const
    {
        return ensureData().moldModel;
    }

    /**
     * フォームの保存領域を設定
     *
     * @param moldModel フォームの保存領域
     */
    void setMoldModel(MoldModel moldModel)
    {
        ensureData().moldModel.emplace(std::move(moldModel));
    }

    /**
     * フォームモデルを取得
     *
     * @return フォームモデル
     */
    const optional<FormModel>& getFormModel() const
    {
        return ensureData().formModel;
    }

    /**
     * フォームモデルを設定
     *
     * @param formModel フォームモデル
     */
    void setFormModel(FormModel formModel)
    {
        ensureData().formModel.emplace(std::move(formModel));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetFormWithSignatureByUserIdResult> AsyncGetFormWithSignatureByUserIdResult;

} }

#endif //GS2_FORMATION_CONTROL_GETFORMWITHSIGNATUREBYUSERIDRESULT_HPP_