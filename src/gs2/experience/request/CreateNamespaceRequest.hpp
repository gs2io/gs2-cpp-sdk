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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/experience/Gs2ExperienceConst.hpp>
#include <gs2/experience/model/model.hpp>
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            name(data.name),
            description(data.description),
            experienceCapScriptId(data.experienceCapScriptId)
        {
            if (data.changeExperienceScript)
            {
                changeExperienceScript = data.changeExperienceScript->deepCopy();
            }
            if (data.changeRankScript)
            {
                changeRankScript = data.changeRankScript->deepCopy();
            }
            if (data.changeRankCapScript)
            {
                changeRankCapScript = data.changeRankCapScript->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    CreateNamespaceRequest() = default;
    CreateNamespaceRequest(const CreateNamespaceRequest& createNamespaceRequest) = default;
    CreateNamespaceRequest(CreateNamespaceRequest&& createNamespaceRequest) = default;
    ~CreateNamespaceRequest() GS2_OVERRIDE = default;

    CreateNamespaceRequest& operator=(const CreateNamespaceRequest& createNamespaceRequest) = default;
    CreateNamespaceRequest& operator=(CreateNamespaceRequest&& createNamespaceRequest) = default;

    CreateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateNamespaceRequest);
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    CreateNamespaceRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    CreateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setExperienceCapScriptId(StringHolder experienceCapScriptId)
    {
        ensureData().experienceCapScriptId.emplace(std::move(experienceCapScriptId));
    }

    /**
     * ランクキャップ取得時 に実行されるスクリプト のGRNを設定
     *
     * @param experienceCapScriptId ランクキャップ取得時 に実行されるスクリプト のGRN
     */
    CreateNamespaceRequest& withExperienceCapScriptId(StringHolder experienceCapScriptId)
    {
        ensureData().experienceCapScriptId.emplace(std::move(experienceCapScriptId));
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
    void setChangeExperienceScript(ScriptSetting changeExperienceScript)
    {
        ensureData().changeExperienceScript.emplace(std::move(changeExperienceScript));
    }

    /**
     * 経験値変化したときに実行するスクリプトを設定
     *
     * @param changeExperienceScript 経験値変化したときに実行するスクリプト
     */
    CreateNamespaceRequest& withChangeExperienceScript(ScriptSetting changeExperienceScript)
    {
        ensureData().changeExperienceScript.emplace(std::move(changeExperienceScript));
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
    void setChangeRankScript(ScriptSetting changeRankScript)
    {
        ensureData().changeRankScript.emplace(std::move(changeRankScript));
    }

    /**
     * ランク変化したときに実行するスクリプトを設定
     *
     * @param changeRankScript ランク変化したときに実行するスクリプト
     */
    CreateNamespaceRequest& withChangeRankScript(ScriptSetting changeRankScript)
    {
        ensureData().changeRankScript.emplace(std::move(changeRankScript));
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
    void setChangeRankCapScript(ScriptSetting changeRankCapScript)
    {
        ensureData().changeRankCapScript.emplace(std::move(changeRankCapScript));
    }

    /**
     * ランクキャップ変化したときに実行するスクリプトを設定
     *
     * @param changeRankCapScript ランクキャップ変化したときに実行するスクリプト
     */
    CreateNamespaceRequest& withChangeRankCapScript(ScriptSetting changeRankCapScript)
    {
        ensureData().changeRankCapScript.emplace(std::move(changeRankCapScript));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_CREATENAMESPACEREQUEST_HPP_