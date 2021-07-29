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

#include "EzJobResultBody.hpp"
#include <gs2/jobQueue/model/JobResultBody.hpp>


namespace gs2 { namespace ez { namespace jobQueue {

EzJobResultBody::Data::Data(const Data& data) :
    Gs2Object(data),
    tryNumber(data.tryNumber),
    statusCode(data.statusCode),
    result(data.result),
    tryAt(data.tryAt)
{
}

EzJobResultBody::Data::Data(const gs2::jobQueue::JobResultBody& jobResultBody) :
    tryNumber(jobResultBody.getTryNumber() ? *jobResultBody.getTryNumber() : 0),
    statusCode(jobResultBody.getStatusCode() ? *jobResultBody.getStatusCode() : 0),
    result(jobResultBody.getResult() ? *jobResultBody.getResult() : StringHolder()),
    tryAt(jobResultBody.getTryAt() ? *jobResultBody.getTryAt() : 0)
{
}

EzJobResultBody::Data::Data(const gs2::optional<gs2::jobQueue::JobResultBody>& jobResultBody) :
    tryNumber(jobResultBody && jobResultBody->getTryNumber() ? *jobResultBody->getTryNumber() : 0),
    statusCode(jobResultBody && jobResultBody->getStatusCode() ? *jobResultBody->getStatusCode() : 0),
    result(jobResultBody && jobResultBody->getResult() ? *jobResultBody->getResult() : StringHolder()),
    tryAt(jobResultBody && jobResultBody->getTryAt() ? *jobResultBody->getTryAt() : 0)
{
}

EzJobResultBody::EzJobResultBody(gs2::jobQueue::JobResultBody jobResultBody) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(jobResultBody)
{
}

EzJobResultBody::EzJobResultBody(gs2::optional<gs2::jobQueue::JobResultBody> jobResultBody) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(jobResultBody)
{
}

EzJobResultBody EzJobResultBody::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzJobResultBody);
}

gs2::jobQueue::JobResultBody EzJobResultBody::ToModel() const
{
    gs2::jobQueue::JobResultBody jobResultBody;
    jobResultBody.setTryNumber(getTryNumber());
    jobResultBody.setStatusCode(getStatusCode());
    jobResultBody.setResult(getResult());
    jobResultBody.setTryAt(getTryAt());
    return jobResultBody;
}

}}}