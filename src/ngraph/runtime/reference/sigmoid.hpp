/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include <cmath>
#include <cstddef>

namespace ngraph
{
    namespace runtime
    {
        namespace reference
        {
            template <typename T>
            void sigmoid(const T* arg, T* out, size_t count)
            {
                T exp_value;
                for (size_t i = 0; i < count; i++)
                {
                    exp_value = std::exp(-arg[i]);
                    out[i] = 1 / (1 + exp_value);
                }
            }

            template <typename T>
            void sigmoid_backprop(const T* arg, T* delta_arg, T* out, size_t count)
            {
                T exp_value;
                T func_x;
                for (size_t i = 0; i < count; i++)
                {
                    exp_value = std::exp(-arg[i]);
                    func_x = 1 / (1 + exp_value);
                    out[i] = delta_arg[i] * func_x * (1 - func_x);
                }
            }
        }
    }
}
