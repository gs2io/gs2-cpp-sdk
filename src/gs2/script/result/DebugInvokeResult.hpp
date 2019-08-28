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

#ifndef GS2_SCRIPT_CONTROL_DEBUGINVOKERESULT_HPP_
#define GS2_SCRIPT_CONTROL_DEBUGINVOKERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace script
{

/**
 * スクリプトを実行します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DebugInvokeResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ステータスコード */
        optional<Int32> code;
        /** 戻り値 */
        optional<StringHolder> result;
        /** スクリプトの実行時間(ミリ秒) */
        optional<Int32> executeTime;
        /** 費用の計算対象となった時間(秒) */
        optional<Int32> charged;
        /** 標準出力の内容のリスト */
        optional<List<StringHolder>> output;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            code(data.code),
            result(data.result),
            executeTime(data.executeTime),
            charged(data.charged),
            output(data.output)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            code(std::move(data.code)),
            result(std::move(data.result)),
            executeTime(std::move(data.executeTime)),
            charged(std::move(data.charged)),
            output(std::move(data.output))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "code") == 0) {
                if (jsonValue.IsInt())
                {
                    this->code = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "result") == 0) {
                if (jsonValue.IsString())
                {
                    this->result.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "executeTime") == 0) {
                if (jsonValue.IsInt())
                {
                    this->executeTime = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "charged") == 0) {
                if (jsonValue.IsInt())
                {
                    this->charged = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "output") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->output.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        detail::addToList(*this->output, std::move(stringHolder));
                    }
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
    DebugInvokeResult() :
        m_pData(nullptr)
    {}

    DebugInvokeResult(const DebugInvokeResult& debugInvokeResult) :
        Gs2Object(debugInvokeResult),
        m_pData(debugInvokeResult.m_pData != nullptr ? new Data(*debugInvokeResult.m_pData) : nullptr)
    {}

    DebugInvokeResult(DebugInvokeResult&& debugInvokeResult) :
        Gs2Object(std::move(debugInvokeResult)),
        m_pData(debugInvokeResult.m_pData)
    {
        debugInvokeResult.m_pData = nullptr;
    }

    ~DebugInvokeResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DebugInvokeResult& operator=(const DebugInvokeResult& debugInvokeResult)
    {
        Gs2Object::operator=(debugInvokeResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*debugInvokeResult.m_pData);

        return *this;
    }

    DebugInvokeResult& operator=(DebugInvokeResult&& debugInvokeResult)
    {
        Gs2Object::operator=(std::move(debugInvokeResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = debugInvokeResult.m_pData;
        debugInvokeResult.m_pData = nullptr;

        return *this;
    }

    const DebugInvokeResult* operator->() const
    {
        return this;
    }

    DebugInvokeResult* operator->()
    {
        return this;
    }
    /**
     * ステータスコードを取得
     *
     * @return ステータスコード
     */
    const optional<Int32>& getCode() const
    {
        return ensureData().code;
    }

    /**
     * ステータスコードを設定
     *
     * @param code ステータスコード
     */
    void setCode(Int32 code)
    {
        ensureData().code.emplace(code);
    }

    /**
     * 戻り値を取得
     *
     * @return 戻り値
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * 戻り値を設定
     *
     * @param result 戻り値
     */
    void setResult(const Char* result)
    {
        ensureData().result.emplace(result);
    }

    /**
     * スクリプトの実行時間(ミリ秒)を取得
     *
     * @return スクリプトの実行時間(ミリ秒)
     */
    const optional<Int32>& getExecuteTime() const
    {
        return ensureData().executeTime;
    }

    /**
     * スクリプトの実行時間(ミリ秒)を設定
     *
     * @param executeTime スクリプトの実行時間(ミリ秒)
     */
    void setExecuteTime(Int32 executeTime)
    {
        ensureData().executeTime.emplace(executeTime);
    }

    /**
     * 費用の計算対象となった時間(秒)を取得
     *
     * @return 費用の計算対象となった時間(秒)
     */
    const optional<Int32>& getCharged() const
    {
        return ensureData().charged;
    }

    /**
     * 費用の計算対象となった時間(秒)を設定
     *
     * @param charged 費用の計算対象となった時間(秒)
     */
    void setCharged(Int32 charged)
    {
        ensureData().charged.emplace(charged);
    }

    /**
     * 標準出力の内容のリストを取得
     *
     * @return 標準出力の内容のリスト
     */
    const optional<List<StringHolder>>& getOutput() const
    {
        return ensureData().output;
    }

    /**
     * 標準出力の内容のリストを設定
     *
     * @param output 標準出力の内容のリスト
     */
    void setOutput(const List<StringHolder>& output)
    {
        ensureData().output.emplace(output);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DebugInvokeResult> AsyncDebugInvokeResult;

} }

#endif //GS2_SCRIPT_CONTROL_DEBUGINVOKERESULT_HPP_