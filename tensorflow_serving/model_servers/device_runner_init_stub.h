/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_SERVING_MODEL_SERVERS_DEVICE_RUNNER_INIT_STUB_H_
#define TENSORFLOW_SERVING_MODEL_SERVERS_DEVICE_RUNNER_INIT_STUB_H_

#include "tensorflow/core/lib/core/status.h"
#include "tensorflow/core/tfrt/runtime/runtime.h"

namespace tensorflow::serving {

using InitializeDeviceRunnerAndTopologyFuncType =
    Status (*)(tfrt_stub::Runtime&, int*, int*);

// Initializes a `TpuSystem` instance, and provide `num_local_devices` and
// `cores_per_chip` topology info. This is a function pointer because some
// binary contains code paths to call this function even though it doesn't use
// TPU, the function pointer allows us to provide a dummy implementation so it
// doesn't have to link TPU dependencies that increases binary size.
extern InitializeDeviceRunnerAndTopologyFuncType
    InitializeDeviceRunnerAndTopology;

}  // namespace tensorflow::serving

#endif  // TENSORFLOW_SERVING_MODEL_SERVERS_DEVICE_RUNNER_INIT_STUB_H_
