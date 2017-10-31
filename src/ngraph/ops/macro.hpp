// ----------------------------------------------------------------------------
// Copyright 2017 Nervana Systems Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// ----------------------------------------------------------------------------

#pragma once

#include "ngraph/ops/op.hpp"

namespace ngraph
{
    namespace op
    {
        class MacroNode : public ::ngraph::Node
        {
        public:
            using Node::Node;
            virtual void propagate_types() override;
            virtual std::shared_ptr<Node> lower() = 0;
            std::shared_ptr<Node> get_lowered_node();

        protected:
            std::shared_ptr<Node> m_lowered_node; //nullptr
        };
    }
}