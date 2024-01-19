/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#pragma once

#include <gmock/gmock.h>

#include "platform/networkstrate/replica_communicator.h"

namespace resdb {

class MockReplicaCommunicator : public ReplicaCommunicator {
 public:
  MockReplicaCommunicator() : ReplicaCommunicator({}) {}
  MockReplicaCommunicator(const std::vector<ReplicaInfo>& replicas)
      : ReplicaCommunicator(replicas) {}

  MOCK_METHOD(int, SendHeartBeat, (const Request&), (override));
  MOCK_METHOD(int, SendMessage, (const google::protobuf::Message&), (override));

  MOCK_METHOD(void, BroadCast, (const google::protobuf::Message&), (override));
  MOCK_METHOD(void, SendMessage, (const google::protobuf::Message&, int64_t),
              (override));
  MOCK_METHOD(int, SendMessage,
              (const google::protobuf::Message&, const ReplicaInfo&),
              (override));
  MOCK_METHOD(int, SendBatchMessage,
              (const std::vector<std::unique_ptr<Request>>&,
               const ReplicaInfo&),
              (override));
};

}  // namespace resdb
