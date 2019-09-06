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

#ifndef GS2_EXPERIENCE_CONTROL_CREATENAMESPACEREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_CREATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * ネームスペースを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateNamespaceRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ランクキャップ取得時 に実行されるスクリプト のGRN */
        optional<StringHolder> experienceCapScriptId;
        /** 経験値変化したときに実行するスクリプト */
        optional<ScriptSetting> changeExperienceScript;
        /** ランク変化したときに実行するスクリプト */
        optional<ScriptSetting> changeRankScript;
        /** ランクキャップ変化したときに実行するスクリプト */
        optional<ScriptSetting> changeRankCapScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            experienceCapScriptId(data.experienceCapScriptId),
            changeExperienceScript(data.changeExperienceScript),
            changeRankScript(data.changeRankScript),
            changeRankCapScript(data.changeRankCapScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            experienceCapScriptId(std::move(data.experienceCapScriptId)),
            changeExperienceScript(std::move(data.changeExperienceScript)),
            changeRankScript(std::move(data.changeRankScript)),
            changeRankCapScript(std::move(data.changeRankCapScript))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    CreateNamespaceRequest() :
        m_pData(nullptr)
    {}

    CreateNamespaceRequest(const CreateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateNamespaceRequest(CreateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateNamespaceRequest& operator=(const CreateNamespaceRequest& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(createNamespaceRequest);
        Gs2Experience::operator=(createNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createNamespaceRequest.m_pData);

        return *this;
    }

    CreateNamespaceRequest& operator=(CreateNamespaceRequest&& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(createNamespaceRequest));
        Gs2Experience::operator=(std::move(createNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createNamespaceRequest.m_pData;
        createNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const CreateNamespaceRequest* operator->() const
    {
        return this;
    }

    CreateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    CreateNamespaceRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    CreateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを取得
     *
     * @return ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getExperienceCapScriptId() const
    {
        return ensureData().experienceCapScriptId;
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを設定
     *
     * @param experienceCapScriptId ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    void setExperienceCapScriptId(const Char* experienceCapScriptId)
    {
        ensureData().experienceCapScriptId.emplace(experienceCapScriptId);
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを設定
     *
     * @param experienceCapScriptId ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    CreateNamespaceRequest& withExperienceCapScriptId(const Char* experienceCapScriptId)
    {
        ensureData().experienceCapScriptId.emplace(experienceCapScriptId);
        return *this;
    }

    /**
     * 経験値変化したときに実行するスクリプトを取得
     *
     * @return 経験値変化したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getChangeExperienceScript() const
    {
        return ensureData().changeExperienceScript;
    }

    /**
     * 経験値変化したときに実行するスクリプトを設定
     *
     * @param changeExperienceScript 経験値変化したときに実行するスクリプト
     */
    void setChangeExperienceScript(const ScriptSetting& changeExperienceScript)
    {
        ensureData().changeExperienceScript.emplace(changeExperienceScript);
    }

    /**
     * 経験値変化したときに実行するスクリプトを設定
     *
     * @param changeExperienceScript 経験値変化したときに実行するスクリプト
     */
    CreateNamespaceRequest& withChangeExperienceScript(const ScriptSetting& changeExperienceScript)
    {
        ensureData().changeExperienceScript.emplace(changeExperienceScript);
        return *this;
    }

    /**
     * ランク変化したときに実行するスクリプトを取得
     *
     * @return ランク変化したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getChangeRankScript() const
    {
        return ensureData().changeRankScript;
    }

    /**
     * ランク変化したときに実行するスクリプトを設定
     *
     * @param changeRankScript ランク変化したときに実行するスクリプト
     */
    void setChangeRankScript(const ScriptSetting& changeRankScript)
    {
        ensureData().changeRankScript.emplace(changeRankScript);
    }

    /**
     * ランク変化したときに実行するスクリプトを設定
     *
     * @param changeRankScript ランク変化したときに実行するスクリプト
     */
    CreateNamespaceRequest& withChangeRankScript(const ScriptSetting& changeRankScript)
    {
        ensureData().changeRankScript.emplace(changeRankScript);
        return *this;
    }

    /**
     * ランクキャップ変化したときに実行するスクリプトを取得
     *
     * @return ランクキャップ変化したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getChangeRankCapScript() const
    {
        return ensureData().changeRankCapScript;
    }

    /**
     * ランクキャップ変化したときに実行するスクリプトを設定
     *
     * @param changeRankCapScript ランクキャップ変化したときに実行するスクリプト
     */
    void setChangeRankCapScript(const ScriptSetting& changeRankCapScript)
    {
        ensureData().changeRankCapScript.emplace(changeRankCapScript);
    }

    /**
     * ランクキャップ変化したときに実行するスクリプトを設定
     *
     * @param changeRankCapScript ランクキャップ変化したときに実行するスクリプト
     */
    CreateNamespaceRequest& withChangeRankCapScript(const ScriptSetting& changeRankCapScript)
    {
        ensureData().changeRankCapScript.emplace(changeRankCapScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CreateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CreateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_CREATENAMESPACEREQUEST_HPP_