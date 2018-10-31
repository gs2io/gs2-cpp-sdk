# Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
# Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License").
# You may not use this file except in compliance with the License.
# A copy of the License is located at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# or in the "license" file accompanying this file. This file is distributed
# on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied. See the License for the specific language governing
# permissions and limitations under the License.

GS2_PATH := $(call my-dir)

GS2_SRC_FILES := $(GS2_PATH)/core/AbstractGs2Client.cpp \
                   $(GS2_PATH)/core/Gs2Constant.cpp \
                   $(GS2_PATH)/core/Gs2Object.cpp \
                   $(GS2_PATH)/core/control/Gs2BasicRequest.cpp \
                   $(GS2_PATH)/core/json/Allocator.cpp \
                   $(GS2_PATH)/core/json/JsonParser.cpp \
                   $(GS2_PATH)/core/json/JsonWriter.cpp \
                   $(GS2_PATH)/core/model/BasicGs2Credential.cpp \
                   $(GS2_PATH)/core/model/OnetimeTokenGs2Credential.cpp \
                   $(GS2_PATH)/core/model/Region.cpp \
                   $(GS2_PATH)/core/util/Base64.cpp \
                   $(GS2_PATH)/core/util/DefaultAllocator.cpp \
                   $(GS2_PATH)/core/util/SignUtil.cpp \
                   $(GS2_PATH)/core/util/StringHolder.cpp \
                   $(GS2_PATH)/core/util/StringUtil.cpp \
                   $(GS2_PATH)/core/util/StringVariable.cpp \
                   $(GS2_PATH)/core/util/UrlEncoder.cpp \
                   $(GS2_PATH)/core/external/cryptopp/algparam.cpp \
                   $(GS2_PATH)/core/external/cryptopp/asn.cpp \
                   $(GS2_PATH)/core/external/cryptopp/cpu.cpp \
                   $(GS2_PATH)/core/external/cryptopp/crc-simd.cpp \
                   $(GS2_PATH)/core/external/cryptopp/cryptlib.cpp \
                   $(GS2_PATH)/core/external/cryptopp/filters.cpp \
                   $(GS2_PATH)/core/external/cryptopp/fips140.cpp \
                   $(GS2_PATH)/core/external/cryptopp/gcm-simd.cpp \
                   $(GS2_PATH)/core/external/cryptopp/hmac.cpp \
                   $(GS2_PATH)/core/external/cryptopp/integer.cpp \
                   $(GS2_PATH)/core/external/cryptopp/iterhash.cpp \
                   $(GS2_PATH)/core/external/cryptopp/misc.cpp \
                   $(GS2_PATH)/core/external/cryptopp/mqueue.cpp \
                   $(GS2_PATH)/core/external/cryptopp/nbtheory.cpp \
                   $(GS2_PATH)/core/external/cryptopp/neon-simd.cpp \
                   $(GS2_PATH)/core/external/cryptopp/osrng.cpp \
                   $(GS2_PATH)/core/external/cryptopp/pubkey.cpp \
                   $(GS2_PATH)/core/external/cryptopp/queue.cpp \
                   $(GS2_PATH)/core/external/cryptopp/rdtables.cpp \
                   $(GS2_PATH)/core/external/cryptopp/rijndael-simd.cpp \
                   $(GS2_PATH)/core/external/cryptopp/rijndael.cpp \
                   $(GS2_PATH)/core/external/cryptopp/rng.cpp \
                   $(GS2_PATH)/core/external/cryptopp/sha.cpp \
                   $(GS2_PATH)/core/external/cryptopp/sha-simd.cpp \
                   $(GS2_PATH)/core/external/cryptopp/sse-simd.cpp \
                   $(GS2_PATH)/inGamePushNotification/mqtt/ConnectRequest.cpp \
                   $(GS2_PATH)/inGamePushNotification/mqtt/ConnectResponse.cpp \
                   $(GS2_PATH)/inGamePushNotification/mqtt/MqttClient.cpp \
                   $(GS2_PATH)/inGamePushNotification/mqtt/PingRequest.cpp \
                   $(GS2_PATH)/inGamePushNotification/mqtt/PublishResponse.cpp \
                   $(GS2_PATH)/inGamePushNotification/mqtt/SubscribeRequest.cpp

GS2_C_INCLUDES := $(GS2_PATH)/..
